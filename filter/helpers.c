#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //Loop over each pixel
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float average = (image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3.000;
            int final_avrg = round(average);

            //set each pixel to the average
            image[h][w].rgbtRed = final_avrg;
            image[h][w].rgbtGreen = final_avrg;
            image[h][w].rgbtBlue = final_avrg;
        }
    }


    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed;
    float sepiaGreen;
    float sepiaBlue;

    //Loop over each pixel
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            //Applying the sepia formula
            sepiaRed = .393 * image[h][w].rgbtRed + .769 * image[h][w].rgbtGreen + .189 * image[h][w].rgbtBlue;
            sepiaGreen = .349 * image[h][w].rgbtRed + .686 * image[h][w].rgbtGreen + .168 * image[h][w].rgbtBlue;
            sepiaBlue = .272 * image[h][w].rgbtRed + .534 * image[h][w].rgbtGreen + .131 * image[h][w].rgbtBlue;
            
            //Round them to the closest integer
            sepiaRed = round(sepiaRed);
            sepiaGreen = round(sepiaGreen);
            sepiaBlue = round(sepiaBlue);
            if (sepiaRed >= 255)
            {
                sepiaRed = 255;
                
            }
            if (sepiaGreen >= 255)
            {
                sepiaGreen = 255;
                
            }
            if (sepiaBlue >= 255)
            {
                sepiaBlue = 255;
                
            }
            //Set the final colour to the pixel
            image[h][w].rgbtRed = sepiaRed;
            image[h][w].rgbtGreen = sepiaGreen;
            image[h][w].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    for (int h = 0; h <= height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {
            temp[0] = image[h][w].rgbtBlue;
            temp[1] = image[h][w].rgbtGreen;
            temp[2] = image[h][w].rgbtRed;

            image[h][w].rgbtBlue = image[h][width - w - 1].rgbtBlue;
            image[h][w].rgbtGreen = image[h][width - w - 1].rgbtGreen;
            image[h][w].rgbtRed = image[h][width - w - 1].rgbtRed;

            image[h][width - w - 1].rgbtBlue = temp[0];
            image[h][width - w - 1].rgbtGreen = temp[1];
            image[h][width - w - 1].rgbtRed = temp[2];
        }
    }
    return;
}

// Blur image


void blur(int height, int width, RGBTRIPLE image[height][width])
{
????
    return;
}
