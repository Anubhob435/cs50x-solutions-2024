#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// To avoid repetition we'll declare a const int
// That is equal to a JPG block (512 Bytes)
const int BLOCK_SIZE = 512;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Use ./recover 000.jpg");
        return 1;
    }
    // Init FILE var jpg that holds the input file
    FILE *jpg = fopen(argv[1], "r");
    if (jpg == NULL)
    {
        printf("Cant open image");
        return 1;
    }

    // Buffer for fread & fwrite
    // Could also use malloc
    BYTE buffer[BLOCK_SIZE];
    // Filename needs 8 bytes because of 7 chars + 1 null char
    // Could have used malloc
    char filename[8];
    // Count for sprintf to count the number of jpgs
    int count = 0;
    // Init as NULL to avoid any unwanted erros
    FILE *img = NULL;

    while (fread(buffer, sizeof(BYTE), BLOCK_SIZE, jpg) == BLOCK_SIZE)
    {
        // By checking the first 4 bytes of the file we can tell if its a jpeg or not
        if (buffer[0] == 0xff & buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // First image that we write
            if (count == 0)
            {
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
                count++;
            }
            // Write to other images
            else if (count > 0)
            {
                // We need to close the first image we opened
                // In order to open and write to a new one.
                fclose(img);
                sprintf(filename, "%03i.jpg", count);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
                // Incrementing count for the nth image
                count++;
            }
        }
        else if (count != 0)
        {
            fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
        }
    }

    // Closing all the files
    // No need to free any memory
    // Since we didnt use malloc
    fclose(img);
    fclose(jpg);

    return 0;
}
