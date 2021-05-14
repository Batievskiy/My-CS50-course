#include "helpers.h"
#include <math.h> // round - round a number to the nearest integer
#include <stdbool.h>

// This is my explanation of each line of code here for Dummies in programming like Me.)

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row++) // here we iterate with each row of array of image pixels[row][]
    {
        for (int col = 0; col < width; col++) // here we iterate with each column value in array of image pixels[row][col]
        {
            int originRed = image[row][col].rgbtRed; // copy Red value from image to temporary variable for Red
            int originGreen = image[row][col].rgbtGreen; // copy Green value from image to temp variable for Green
            int originBlue = image[row][col].rgbtBlue; // same here for Blue
            int averageGrey; // here we store calculated average value for Gray scale

            // after we have all temp values to work with
            // first of all we have to round all three values for Red Green and Blue
            // lets count average of three values and use round() function from <math.h> to round it to nearest integer
            averageGrey = round((originRed + originGreen + originBlue) / 3.0);

            // as we converted each pixel of this loop cycle for [row][col]
            // then we have to store this average to original pixels array
            image[row][col].rgbtRed = averageGrey;
            image[row][col].rgbtGreen = averageGrey;
            image[row][col].rgbtBlue = averageGrey;
        }
    }
    return;
}

// here pixels is gonna swap using pointers on it (from lecture)
void swap(RGBTRIPLE *originPixel, RGBTRIPLE *swapPixel)
{
    RGBTRIPLE tempPixel = *originPixel; // temporary pixel storage
    *originPixel = *swapPixel;
    *swapPixel = tempPixel;
}

// Reflect image horizontally using swap function from lecture with two glasses
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // for every row we gonna swap pixels on horizontally opposite sides
    // but how to do that?
    // let's count a formula:
    // width = 5; indexes is [0][1][2][3][4]
    // col[0] must swap with [4]; col[1] with [3]; col[2] with [2]; col[3] with [1] and col[4] with [0]
    // so this what we have: width 5 - 1 = 4; 4 - col = swapped index
    // swap [index] = [width - 1 - col]
    // using swap function
    for (int row = 0; row < height; row++) // here we iterate with each row of array of image pixels[row][]
    {
        for (int col = 0; col < width / 2; col++) // here we iterate with each column value in array of image pixels[row][col]
        {
            swap(&image[row][col], &image[row][width - 1 - col]);
        }
    }
    return;
}

/*
// and this is another way how to reflect pixels
// using more deep ungerstanding of arrays in structure RGBTRIPLE
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // here we have to temporary copy the array of image pixels
    // that takes only one row at the time size of width from image array
    // but how to do that?
    // we gonna use structure RGBTRIPLE from bmp.h
    // that describes a color consisting of relative intensities of red, green, and blue

    RGBTRIPLE tempRow[width];
    for (int row = 0; row < height; row++) // here we iterate with each row of array of image pixels[row][]
    {
        for (int col = 0; col < width; col++)
        {
            tempRow[col] = image[row][col]; // here we copy each [col] value to temporary array
        }

        // for every row we gonna swap pixels on horizontally opposite sides
        // same formula here as described in first solution:
        // swap [index] = [width - 1 - col]
        for (int col = 0; col < width; col++) // here we iterate with each column value in array of image pixels[row][col]
        {
            // here we exactly swap pixels variables in each column for current row
            image[row][col].rgbtRed = tempRow[width - 1 - col].rgbtRed;
            image[row][col].rgbtGreen = tempRow[width - 1 - col].rgbtGreen;
            image[row][col].rgbtBlue = tempRow[width - 1 - col].rgbtBlue;
        }
    }
    return;
}
*/

// here we check for pixel exist
// is it in bounds of our matrix down below?
bool isPixelExist(int tmpRow, int tmpCol, int height, int width)
{
    return tmpRow >= 0 && tmpRow < height && tmpCol >= 0 && tmpCol < width;
}

// this is our own blurr function
RGBTRIPLE getPixelBlurred(int originRow, int originCol, int height, int width, RGBTRIPLE image[height][width])
{
    int sumRed, sumGreen, sumBlue;
    sumRed = sumGreen = sumBlue = 0;
    int pixelCounter = 0;
    /* here we have to grab all nine values (in matrix 3 by 3)
     * around our center pixel at the particular [row][col] position
     * let's visualize this 2d array (matrix):
        [row - 1][col - 1]    [row - 1][  col  ]    [row - 1][col + 1]

        [  row  ][col - 1]    [  row  ][  col  ]    [  row  ][col + 1]

        [row + 1][col - 1]    [row + 1][  col  ]    [row + 1][col + 1]
    */
    // so at the particular row of center pixel
    for (int row = -1; row <= 1; row++) // we can move 1 step back (-1) and 1 step forward (+1)
    {
        // so at the particular column of center pixel
        for (int col = -1; col <= 1; col++) // we can move 1 step back (-1) and 1 step forward (+1)
        {
            int tempRow = originRow + row; // here we adding offset to row index
            int tempCol = originCol + col; // and adding offset to column index

            // checking is pixel in range of our pixel martix 3 by 3 from above
            if (isPixelExist(tempRow, tempCol, height, width))
            {
                // and calculating sum for each 9 pixels in pixel matrix
                sumRed += image[tempRow][tempCol].rgbtRed; // for red
                sumGreen += image[tempRow][tempCol].rgbtGreen; // green
                sumBlue += image[tempRow][tempCol].rgbtBlue; // and blue pixel
                pixelCounter++;
            }
        }
    }
    RGBTRIPLE pixelBlurred; // creating blurred pixel structure

    // and counting an average for each pixel struct (sum of values of 9 pixels divided my number of pixels)
    pixelBlurred.rgbtRed = round((float) sumRed / pixelCounter); // rounding Red values
    pixelBlurred.rgbtGreen = round((float) sumGreen / pixelCounter); // rounding Green values
    pixelBlurred.rgbtBlue = round((float) sumBlue / pixelCounter); // rounding Blue values

    return pixelBlurred;
}

// Blurring the image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // first of all we have to make a copy of the original image
    // and only then process with its values and store new values to new file

    RGBTRIPLE copyImage[height][width]; // this is a copy of original image
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            // here we store all new values from temporary array in blurr function
            copyImage[row][col] = getPixelBlurred(row, col, height, width, image);
        }
    }

    // and finally we have to copy our copied and blurred image back to original
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col] = copyImage[row][col];
        }
    }
    return;
}

// since color channel values can only take on integer values from 0 to 255
// we have to cap values of colors that is greater than 255
int cap(int colorValue)
{
    return colorValue < 255 ? colorValue : 255; // simply if weight is greater than 255 - convert it to 255;
}

RGBTRIPLE getEdgePixel(int originRow, int originCol, int height, int width, RGBTRIPLE image[height][width])
{
    // this is Gx Sobel operator matrix:
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};

    // and this is Gy Sobel operator matrix:
    int Gy[3][3] = {{-1, -2, -1}, { 0,  0,  0}, { 1,  2,  1}};

    /*
    we actually don't have to make matrix for Gy and just
    use Gx's matrix values because Gx[row][col] = Gy[col][row]
    */

    int sumRedX, sumGreenX, sumBlueX; // for future weight sum calculation of Gx
    sumRedX = sumGreenX = sumBlueX = 0;

    int sumRedY, sumGreenY, sumBlueY; // for future weight sum calculation of Gy
    sumRedY = sumGreenY = sumBlueY = 0;

    /* here is the same as for blur logic
     * we have to grab all nine values
     * around our center pixel at the particular [row][col] position
     * let's visualize this 2d array (matrix):
        [row - 1][col - 1]    [row - 1][  col  ]    [row - 1][col + 1]

        [  row  ][col - 1]    [  row  ][  col  ]    [  row  ][col + 1]

        [row + 1][col - 1]    [row + 1][  col  ]    [row + 1][col + 1]
    */
    // so at the particular row of center pixel
    for (int row = -1; row <= 1; row++)
    {
        for (int col = -1; col <= 1; col++)
        {
            int tempRow = originRow + row; // creating an offset for rows
            int tempCol = originCol + col; // and for colums

            // here we check is pixel in bounds of 3 by 3 matrix
            if (isPixelExist(tempRow, tempCol, height, width))
            {
                // for each of the three color values for each pixel
                // we’ll compute two values Gx and Gy
                // for that we need to take all nine pixel values in pixel matrix 3 by 3
                // multiply them each by the corresponding value from Gx matrix
                // and take the sum of the resulting values

                int weightXsum = Gx[row + 1][col + 1];
                sumRedX += weightXsum * image[tempRow][tempCol].rgbtRed;
                sumGreenX += weightXsum * image[tempRow][tempCol].rgbtGreen;
                sumBlueX += weightXsum * image[tempRow][tempCol].rgbtBlue;

                int weightYsum = Gy[row + 1][col + 1];
                sumRedY += weightYsum * image[tempRow][tempCol].rgbtRed;
                sumGreenY += weightYsum * image[tempRow][tempCol].rgbtGreen;
                sumBlueY += weightYsum * image[tempRow][tempCol].rgbtBlue;
            }
        }
    }
    RGBTRIPLE edgePixel; // creating edged pixel structure

    // The Sobel filter algorithm combines Gx and Gy
    // into a final value by calculating the square root of Gx^2 + Gy^2
    // And since channel values can only take on integer values from 0 to 255
    // we have to round resulting value to the nearest integer and cap it at 255
    edgePixel.rgbtRed = cap(round(sqrt(sumRedX * sumRedX + sumRedY * sumRedY)));
    edgePixel.rgbtGreen = cap(round(sqrt(sumGreenX * sumGreenX + sumGreenY * sumGreenY)));
    edgePixel.rgbtBlue = cap(round(sqrt(sumBlueX * sumBlueX + sumBlueY * sumBlueY)));

    return edgePixel;
}

// Detecting edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // same as for blurred pixels
    // we have to make a copy of the original image
    RGBTRIPLE copyImage[height][width];

    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            copyImage[row][col] = getEdgePixel(row, col, height, width, image);
        }
    }

    // and finally we have to copy our copied and edged image back to original
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            image[row][col] = copyImage[row][col];
        }
    }
    return;
}
