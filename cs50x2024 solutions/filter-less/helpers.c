#include "helpers.h"
#include <math.h>


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    double average;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            average = (int)round(((float)image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     int tempRed, tempGreen, tempBlue;
     int sepiaRed, sepiaGreen, sepiaBlue;
     for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            tempRed = image[i][j].rgbtRed;
            tempGreen = image[i][j].rgbtGreen;
            tempBlue = image[i][j].rgbtBlue;

            sepiaRed = round(.393 * tempRed + .769 * tempGreen + .189 * tempBlue);
           // sepiaRed = image[i][j].rgbtRed;
            if(sepiaRed > 255){
                sepiaRed = 255;
            }
            else if(sepiaRed < 0){
                sepiaRed = 0;
            }


            sepiaGreen = round(.349 * tempRed + .686 * tempGreen + .168 * tempBlue);
            //sepiaGreen = image[i][j].rgbtGreen;
             if(sepiaGreen > 255){
                sepiaGreen = 255;
            }
            else if(sepiaGreen < 0){
                sepiaGreen = 0;
            }

            sepiaBlue = round(.272 * tempRed + .534 * tempGreen + .131 * tempBlue);
            //sepiaBlue = image[i][j].rgbtBlue;
            if(sepiaBlue > 255){
                sepiaBlue = 255;
            }
            else if(sepiaBlue < 0){
                sepiaBlue = 0;
            }
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
     }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[width];
    RGBTRIPLE temp1[width];
    int count = 0;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width / 2; j++){
            temp[j] = image[i][width - j - 1];
            temp1[width - j - 1] = image[i][j];
            image[i][j] = temp[j];
            image[i][width - j - 1] = temp1[width - j - 1];

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

    //I still need to work on this, since i havent found a proper solution. :)

    /**int blur = 0;
    int red, green, blue;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width / 2; j++){
            red = image[i][j].rgbtRed;
            green = image[i][j].rgbtGreen;
            blue = image[i][j].rgbtBlue;
            if(i == 0 && j == 0){
                red = (float)image[i][j].rgbtRed + image[i][j+1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 2].rgbtRed;
                green =(float)image[i][j].rgbtGreen + image[i][j+1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 2].rgbtGreen;
                blue =(float)image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 2].rgbtBlue;
                image[i][j].rgbtRed = round(red / 4);
                image[i][j].rgbtGreen = round(green/4);
                image[i][j].rgbtBlue = round(blue/4);
            }
            else if(i == 0 && (j >= 0 || j <= width)){

            }
        **/






    return;
}
