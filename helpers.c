#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = (int) round(
                (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sred, sgreen, sblue;
            sred = round(0.393 * image[i][j].rgbtRed + 0.769 * image[i][j].rgbtGreen +
                         0.189 * image[i][j].rgbtBlue);
            sgreen = round(0.349 * image[i][j].rgbtRed + 0.686 * image[i][j].rgbtGreen +
                           0.168 * image[i][j].rgbtBlue);
            sblue = round(0.272 * image[i][j].rgbtRed + 0.534 * image[i][j].rgbtGreen +
                          0.131 * image[i][j].rgbtBlue);
            if (sred > 255)
            {
                sred = 255;
            }
            if (sgreen > 255)
            {
                sgreen = 255;
            }
            if (sblue > 255)
            {
                sblue = 255;
            }
            image[i][j].rgbtRed = sred;
            image[i][j].rgbtGreen = sgreen;
            image[i][j].rgbtBlue = sblue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image1[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            image1[i][j] = image[i][(width - 1) - j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            image[i][j] = image1[i][j];
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image1[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = 0, green = 0, blue = 0, px = 0;
            for (int k = i - 1; k <= i + 1; k++)
            {
                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (k >= 0 && k < height && l >= 0 && l < width)
                    {
                        red += image[k][l].rgbtRed;
                        green += image[k][l].rgbtGreen;
                        blue += image[k][l].rgbtBlue;
                        px++;
                    }
                }
            }
            image1[i][j].rgbtRed = round(red / px);
            image1[i][j].rgbtGreen = round(green / px);
            image1[i][j].rgbtBlue = round(blue / px);
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            image[i][j] = image1[i][j];
        }
    }

    return;
}
