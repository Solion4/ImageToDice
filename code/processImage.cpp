#include "processImage.h"
#include "diceFaces.h"

// ------------------------------------------ calculateDieSubsections() ---------------------------------------------- //

void calculateDieSubsections(int dieWidth, int& left, int& center, int& right)
{
    int totalPixels = dieWidth;
    int centerPixels = dieWidth / 3;
    int extraPixels = dieWidth % 3;

    if(extraPixels == 0)
    {
        left = centerPixels;
        center = centerPixels;
        right = centerPixels;
    }
    else if(extraPixels == 1)
    {
        left = centerPixels;
        center = centerPixels + extraPixels;
        right = centerPixels;
    }
    else // must have 2 extra pixels
    {
        left = centerPixels + 1;
        center = centerPixels;
        right = centerPixels + 1;
    }
}
/*
// Lookup table for face assignment based on combination
const int faceLookupTable[512] = {
    // Map each combination to the corresponding face value
    // Example: faceLookupTable[0] = face for combination 0
    //          faceLookupTable[1] = face for combination 1
    //          ...
    //          faceLookupTable[511] = face for combination 511
    6, 6, 6, 9, 6, 9, 9, 9, 6, 6, 6, 6, 6, 6, 6, 9, 6, 6, 6, 6, 6, 6, 6, 6, 9, 9, 9, 7, 9, 
};
*/

/*
int determineDiceFace(int avgInt1, int avgInt2, int avgInt3, int avgInt4, int avgInt5, int avgInt6, int avgInt7, int avgInt8, int avgInt9)
{
    // determine what dice Face fits best:
    // Implement in most efficient method, CHANGE ME

    // use threshold, to change avg. intensities to either 1 or 0:
    int top_left = 0;
    int top_middle = 0;
    int top_right = 0;
    int middle_left = 0;
    int middle_middle = 0;
    int middle_right = 0;
    int bottom_left = 0;
    int bottom_middle = 0;
    int bottom_right = 0;

    int light = 0;
    
    double threshold = 128.0;
    
    if(avgInt1 > threshold)
    {
        top_left = 1; // 1 means white
        light++;
    }
    if(avgInt2 > threshold)
    {
        top_middle = 1;
        light++;
    }
    if(avgInt3 > threshold)
    {
        top_right = 1;
        light++;
    }
    if(avgInt4 > threshold)
    {
        middle_left = 1;
        light++;
    }
    if(avgInt5 > threshold)
    {
        middle_middle = 1;
        light++;
    }
    if(avgInt6 > threshold)
    {
        middle_right = 1;
        light++;
    }
    if(avgInt7 > threshold)
    {
        bottom_left = 1;
        light++;
    }
    if(avgInt8 > threshold)
    {
        bottom_middle = 1;
        light++;
    }
    if(avgInt9 > threshold)
    {
        bottom_right = 1;
        light++;
    }

    int face = 1; // 6 by default
    
    if(middle_middle == 0)
    {
        face = 1;
    }
    if(light >= 8)
    {
        face = 1; // just 1 dot
    }
    if(top_left == 0 && bottom_right == 0)
    {
        face = 2;
    }
    if((light >= 7) && (top_left == 1 || bottom_right == 1))
    {
        face = 1;
    }
    // just 2 dots
    if((light >= 7) && (top_left == 0 || middle_left == 0 || top_middle == 0) && (bottom_right == 0 || bottom_middle == 0 || middle_right == 0))
    {
        face = 2;
    }
    if((light >= 7) && (top_right == 0 || middle_right == 0 || top_middle == 0) && (bottom_left == 0 || bottom_middle == 0 || middle_left == 0))
    {
        face = 7;
    }
    if(top_left == 0 && middle_middle == 0 && bottom_right == 0)
    {
        face = 3;
    }
    if(top_right == 0 && middle_middle == 0 && bottom_left == 0)
    {
        face = 8;
    }
    if(top_left == 0 && top_right == 0 && bottom_right == 0 && bottom_left == 0)
    {
        face = 4;
    }
    if(top_left == 0 && top_right == 0 && middle_middle == 0 && bottom_left == 0 && bottom_right == 0)
    {
        face = 5;
    }
    if(top_left == 0 && middle_left == 0 && bottom_left == 0 && top_right == 0 && middle_right == 0 && bottom_right == 0)
    {
        face = 6;
    }
    if(top_left == 0 && top_middle == 0 && top_right == 0 && bottom_left == 0 && bottom_middle == 0 && bottom_right == 0)
    {
        face = 9;
    }

    return face;

    
    // Convert the binary representation to a decimal number
    int combination = (top_left << 8) | (top_middle << 7) | (top_right << 6) |
                      (middle_left << 5) | (middle_middle << 4) | (middle_right << 3) |
                      (bottom_left << 2) | (bottom_middle << 1) | bottom_right;

    // Choose the corresponding face based on the decimal number
    if(combination == 0)
    {
        return 6;
    }

    int face = faceLookupTable[combination];

    return face;
    

}
*/

// NEW VERSION - STILL IN REVISION
/*
void processDie(const cv::Mat& inputImage, cv::Mat& outputImage, int row, int startX, int endX,
                 int startY, int endY, int leftSection, int centerSection, int rightSection)
{
    // startX is the coordinate of the start of the die being processed
    // endX is the end of the coordinate of the die being processed, horizontally
    // startY, endY, are coordinates, but vertically
    // leftSection, centerSection, rightSection, are width's of the die subsections, in pixels. 
    // we also pass the inputImage and outputImage as parameters

    // Rough Draft - Crude Processing:
    // Process Dice as a whole, without going into individual sections
    // Take average gradient of dice. 
    // Assign Gradient to one of 6 faces, based on gradient degree:
    // 0-60 = Face 1, 61-120 = face 2, etc. 
    // Put Determined die onto proper spot in output image. 

    // Extract the region of interest (ROI) for the current die, in 9 sections:
    cv::Mat dieROI1 = inputImage(cv::Rect(startX, startY, leftSection, leftSection)); // top left
    cv::Mat dieROI2 = inputImage(cv::Rect(startX + leftSection, startY, centerSection, leftSection)); // top middle
    cv::Mat dieROI3 = inputImage(cv::Rect(startX + leftSection + centerSection, startY, rightSection, leftSection)); // top right
    cv::Mat dieROI4 = inputImage(cv::Rect(startX, startY + leftSection, leftSection, centerSection)); // middle left
    cv::Mat dieROI5 = inputImage(cv::Rect(startX + leftSection, startY + leftSection, centerSection, centerSection)); // middle middle
    cv::Mat dieROI6 = inputImage(cv::Rect(startX + leftSection + centerSection, startY + leftSection, rightSection, centerSection)); // middle right
    cv::Mat dieROI7 = inputImage(cv::Rect(startX, startY + leftSection + centerSection, leftSection, rightSection)); // bottom left
    cv::Mat dieROI8 = inputImage(cv::Rect(startX + leftSection, startY + leftSection + centerSection, centerSection, rightSection)); // bottom middle
    cv::Mat dieROI9 = inputImage(cv::Rect(startX + leftSection + centerSection, startY + leftSection + centerSection, rightSection, rightSection)); // bottom right 

    // Calculate avg. intensities
    // Note - intensity of 0 is black, intensity of 255 is white. 
    double avgInt1 = cv::mean(dieROI1)[0];
    double avgInt2 = cv::mean(dieROI2)[0];
    double avgInt3 = cv::mean(dieROI3)[0];
    double avgInt4 = cv::mean(dieROI4)[0];
    double avgInt5 = cv::mean(dieROI5)[0];
    double avgInt6 = cv::mean(dieROI6)[0];
    double avgInt7 = cv::mean(dieROI7)[0];
    double avgInt8 = cv::mean(dieROI8)[0];
    double avgInt9 = cv::mean(dieROI9)[0];

    // Accurately determine one of 9 possible faces based on the 9 intensities of the 9 subsections of a 3 by 3 die:
    // CHANGE ME

    int face = determineDiceFace(avgInt1, avgInt2, avgInt3,
                                       avgInt4, avgInt5, avgInt6,
                                       avgInt7, avgInt8, avgInt9);

    // Choose the corresponding dice face based on the determined face index
    cv::Mat determinedDie;
    switch (face) {
        case 1:
            determinedDie = createDiceFace1(endX - startX);
            break;
        case 2:
            determinedDie = createDiceFace2(endX - startX);
            break;
        case 3:
            determinedDie = createDiceFace3(endX - startX);
            break;
        case 4:
            determinedDie = createDiceFace4(endX - startX);
            break;
        case 5:
            determinedDie = createDiceFace5(endX - startX);
            break;
        case 6: 
            determinedDie = createDiceFace6(endX - startX);
            break;
        default:
            determinedDie = createDiceFace6(endX - startX);  // Default to face 1
            break;
    }

    // Copy determined die face to the output image
    determinedDie.copyTo(outputImage(cv::Rect(startX, startY, endX - startX, endY - startY)));
}
*/

// ------------------------------------------ processDie() ---------------------------------------------- //

void processDie(const cv::Mat& inputImage, cv::Mat& outputImage, int row, int startX, int endX,
                 int startY, int endY, int leftSection, int centerSection, int rightSection)
{
    // startX is the coordinate of the start of the die being processed
    // endX is the end of the coordinate of the die being processed, horizontally
    // startY, endY, are coordinates, but vertically
    // leftSection, centerSection, rightSection, are width's of the die subsections, in pixels. 
    // we also pass the inputImage and outputImage as parameters

    // Rough Draft - Crude Processing:
    // Process Dice as a whole, without going into individual sections
    // Take average gradient of dice. 
    // Assign Gradient to one of 6 faces, based on gradient degree:
    // 0-60 = Face 1, 61-120 = face 2, etc. 
    // Put Determined die onto proper spot in output image. 

    // Extract the region of interest (ROI) for the current die
    cv::Mat dieROI = inputImage(cv::Rect(startX, startY, endX - startX, endY - startY));

    // Calculate the average grayscale intensity
    double averageIntensity = cv::mean(dieROI)[0];

    int face = 1;  // Default face
    
    // Determine which dice face works best for the current image section based on average intensity
    if (averageIntensity >= 0 && averageIntensity < 42.5) {
        face = 6;
    } else if (averageIntensity >= 42.5 && averageIntensity < 85) {
        face = 5;
    } else if (averageIntensity >= 85 && averageIntensity < 127.5) {
        face = 4;
    } else if (averageIntensity >= 127.5 && averageIntensity < 170) {
        face = 3;
    } else if (averageIntensity >= 170 && averageIntensity < 212.5) {
        face = 2;
    } else if (averageIntensity >= 212.5 && averageIntensity <= 255) {
        face = 1;
    }

    // Choose the corresponding dice face based on the determined face index
    cv::Mat determinedDie;
    switch (face) {
        case 1:
            determinedDie = createDiceFace1(endX - startX);
            break;
        case 2:
            determinedDie = createDiceFace2(endX - startX);
            break;
        case 3:
            determinedDie = createDiceFace3(endX - startX);
            break;
        case 4:
            determinedDie = createDiceFace4(endX - startX);
            break;
        case 5:
            determinedDie = createDiceFace5(endX - startX);
            break;
        case 6: 
            determinedDie = createDiceFace6(endX - startX);
            break;
        case 7:
            determinedDie = createDiceFace7(endX - startX);
            break;
        case 8:
            determinedDie = createDiceFace8(endX - startX);
            break;
        case 9: 
            determinedDie = createDiceFace9(endX - startX);
            break;
        default:
            determinedDie = createDiceFace6(endX - startX);  // Default to face 1
            break;
    }

    // Copy determined die face to the output image
    determinedDie.copyTo(outputImage(cv::Rect(startX, startY, endX - startX, endY - startY)));
}