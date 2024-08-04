#include "helpers.h"
#include <stdio.h>
#include "bmp.h"


void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Define the color you want to use for replacement (e.g., red)
    RGBTRIPLE color;
    color.rgbtRed = 255;
    color.rgbtGreen = 0;
    color.rgbtBlue = 0;

    // Iterate through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Check if the pixel is black (all channels set to 0)
            if (image[i][j].rgbtRed == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtBlue == 0)
            {
                // If it's black, replace it with the specified color
                image[i][j] = color;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    // Check for correct number of command-line arguments
    if (argc != 3)
    {
        printf("Usage: ./colorize infile outfile\n");
        return 1;
    }

    // Open input file
    char *infile = argv[1];
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // Open output file
    char *outfile = argv[2];
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // Read input BMP file
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // Check if the input file is 24-bit uncompressed BMP
    if (bf.bfType != 0x4d42 || bi.biSize != 40 || bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // Write output BMP file
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // Determine padding for scanlines
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // Allocate memory for image storage
    RGBTRIPLE (*image)[bi.biWidth] = calloc(abs(bi.biHeight), sizeof(RGBTRIPLE[bi.biWidth]));

    if (image == NULL)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Not enough memory for image storage.\n");
        return 5;
    }

    // Read image data from input file
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        fread(image[i], sizeof(RGBTRIPLE), bi.biWidth, inptr);

        // Skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);
    }

    // Call the colorize function to change black pixels to a specified color
    colorize(abs(bi.biHeight), bi.biWidth, image);

    // Write image data to output file
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        fwrite(image[i], sizeof(RGBTRIPLE), bi.biWidth, outptr);

        // Add padding back to output file
        for (int k = 0; k < padding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // Close input and output files
    fclose(inptr);
    fclose(outptr);

    // Free dynamically allocated memory
    free(image);

    return 0;
}
