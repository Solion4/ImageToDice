#include "opencv2/opencv.hpp"
#include "iostream"
#include "DiceFaces.h"  // Include the header file with dice face functions
#include "processImage.h"

// ------------------------------------------ main() ---------------------------------------------- //
int main( )
{
    // Get image from computer
    cv::Mat image;
    image = cv::imread("/Users/lev/Downloads/ImageToDice/image.jpg", 1);

    // Check if the image is loaded successfully
    if (image.empty()) {
        std::cerr << "Failed to open the image!" << std::endl;
        return -1;
    }
    
    // Convert Image to Grayscale (each individual pixel)
    cv::Mat grayImage;
    cv::cvtColor(image, grayImage, cv::COLOR_BGR2GRAY);

    // Create Output image
    cv::Mat outputImage = cv::Mat::zeros(image.size(), image.type());
    int numDiceWidth = 50; // Let's say x dice are represented horizontally in the image
    int numDiceHeight = static_cast<int>((static_cast<double>(image.rows) / image.cols) * numDiceWidth);
    int imageWidth = image.cols; // the width of the given image, in pixels

    // -- Convert the image to dice representation
    
    // Determine width of each die, in pixels. 
    // Example: For a 2000 pixel wide image, if we want 100 dice to fit, each die will be 20 pixels. 
    int dieWidthPixels = imageWidth / numDiceWidth; // how wide each die processed has to be
    int dieHeightPixels = dieWidthPixels;

    // Variables to store subsection widths
    int leftSection, centerSection, rightSection;

    // Calculate subsection widths
    calculateDieSubsections(dieWidthPixels, leftSection, centerSection, rightSection);

    // for loop to process each die
    for (int i = 0; i < numDiceHeight; i++) {
        for (int j = 0; j < numDiceWidth; j++) {
            int startX = (j * dieWidthPixels);
            int endX = startX + dieWidthPixels;
            
            int startY = (i * dieHeightPixels);
            int endY = startY + dieHeightPixels;

            // Process pixels for the current die
            processDie(grayImage, outputImage, i, startX, endX, startY, endY, leftSection, centerSection, rightSection);
        }
    }

    cv::imshow("gray representation", image);
    cv::imshow("Dice Representation", outputImage);
    cv::waitKey(0);
}