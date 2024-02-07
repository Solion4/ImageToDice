#include "DiceFaces.h"

// ------------------------------------------ createDiceFace1() ---------------------------------------------- //

// Face 1, just middle
cv::Mat createDiceFace1(int size) {
    // Create a white image
    cv::Mat diceFace1(size, size, CV_8UC3, cv::Scalar(255, 255, 255));

    // Make outline of white image with red line
    cv::rectangle(diceFace1, cv::Point(0, 0), cv::Point(size - 1, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Draw a black rectangle in the middle of the die (for die with 1 face, just 1 dot)
    int one_third = size / 3;
    int two_third = size / 3 * 2;
    
    // Middle Dot
    cv::rectangle(diceFace1, cv::Point(one_third, one_third), cv::Point(two_third, two_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);

    // Make dice face outlines on 1/3, 2/3 sections, both vertically and hortizontally (create into a 3 by 3)
    // Vertical lines
    cv::line(diceFace1, cv::Point(one_third, 0), cv::Point(one_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(two_third, 0), cv::Point(two_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Horizontal lines
    cv::line(diceFace1, cv::Point(0, one_third), cv::Point(size - 1, one_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(0, two_third), cv::Point(size - 1, two_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    
    return diceFace1;
}

// ------------------------------------------ createDiceFace2() ---------------------------------------------- //

// Face 2
// 2 dots, top left, bottom right
cv::Mat createDiceFace2(int size) {
    // Create a white image
    cv::Mat diceFace1(size, size, CV_8UC3, cv::Scalar(255, 255, 255));

    // Make outline of white image with red line
    cv::rectangle(diceFace1, cv::Point(0, 0), cv::Point(size - 1, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Draw a black rectangle in the middle of the die (for die with 1 face, just 2 dots top right, bottom left)
    int one_third = size / 3;
    int two_third = size / 3 * 2;
    
    // Create dots
    cv::rectangle(diceFace1, cv::Point(1, 1), cv::Point(one_third, one_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    cv::rectangle(diceFace1, cv::Point(two_third, two_third), cv::Point(size - 2, size - 2), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);

    // Make dice face outlines on 1/3, 2/3 sections, both vertically and hortizontally (create into a 3 by 3)
    // Vertical lines
    cv::line(diceFace1, cv::Point(one_third, 0), cv::Point(one_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(two_third, 0), cv::Point(two_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Horizontal lines
    cv::line(diceFace1, cv::Point(0, one_third), cv::Point(size - 1, one_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(0, two_third), cv::Point(size - 1, two_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    
    return diceFace1;
}

// ------------------------------------------ createDiceFace3() ---------------------------------------------- //

// Face 3
// 3 dots, top left, middle, bottom right
cv::Mat createDiceFace3(int size) {
    // Create a white image
    cv::Mat diceFace1(size, size, CV_8UC3, cv::Scalar(255, 255, 255));

    // Make outline of white image with red line
    cv::rectangle(diceFace1, cv::Point(0, 0), cv::Point(size - 1, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Draw a black rectangle in the middle of the die (for die with 1 face, just 2 dots top right, bottom left)
    int one_third = size / 3;
    int two_third = size / 3 * 2;
    
    // Top left dot:
    cv::rectangle(diceFace1, cv::Point(1, 1), cv::Point(one_third, one_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Bottom right dot:
    cv::rectangle(diceFace1, cv::Point(two_third, two_third), cv::Point(size - 2, size - 2), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Middle dot:
    cv::rectangle(diceFace1, cv::Point(one_third, one_third), cv::Point(two_third, two_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    
    // Make dice face outlines on 1/3, 2/3 sections, both vertically and hortizontally (create into a 3 by 3)
    // Vertical lines
    cv::line(diceFace1, cv::Point(one_third, 0), cv::Point(one_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(two_third, 0), cv::Point(two_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Horizontal lines
    cv::line(diceFace1, cv::Point(0, one_third), cv::Point(size - 1, one_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(0, two_third), cv::Point(size - 1, two_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    
    return diceFace1;
}

// ------------------------------------------ createDiceFace4() ---------------------------------------------- //

// Face 4
// 4 dots, on every corner
cv::Mat createDiceFace4(int size) {
    // Create a white image
    cv::Mat diceFace1(size, size, CV_8UC3, cv::Scalar(255, 255, 255));

    // Make outline of white image with red line
    cv::rectangle(diceFace1, cv::Point(0, 0), cv::Point(size - 1, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Draw a black rectangle in the middle of the die (for die with 1 face, just 2 dots top right, bottom left)
    int one_third = size / 3;
    int two_third = size / 3 * 2;
    
    // Top left dot:
    cv::rectangle(diceFace1, cv::Point(1, 1), cv::Point(one_third, one_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Bottom right dot:
    cv::rectangle(diceFace1, cv::Point(two_third, two_third), cv::Point(size - 2, size - 2), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Top Right dot:
    cv::rectangle(diceFace1, cv::Point(two_third, 1), cv::Point(size - 2, one_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Bottom Left dot:
    cv::rectangle(diceFace1, cv::Point(1, size - 2), cv::Point(one_third, two_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);

    // Make dice face outlines on 1/3, 2/3 sections, both vertically and hortizontally (create into a 3 by 3)
    // Vertical lines
    cv::line(diceFace1, cv::Point(one_third, 0), cv::Point(one_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(two_third, 0), cv::Point(two_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Horizontal lines
    cv::line(diceFace1, cv::Point(0, one_third), cv::Point(size - 1, one_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(0, two_third), cv::Point(size - 1, two_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    
    return diceFace1;
}

// ------------------------------------------ createDiceFace5() ---------------------------------------------- //

// Face 5
// 5 dots, on every corner, and in middle
cv::Mat createDiceFace5(int size) {
    // Create a white image
    cv::Mat diceFace1(size, size, CV_8UC3, cv::Scalar(255, 255, 255));

    // Make outline of white image with red line
    cv::rectangle(diceFace1, cv::Point(0, 0), cv::Point(size - 1, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Draw a black rectangle in the middle of the die (for die with 1 face, just 2 dots top right, bottom left)
    int one_third = size / 3;
    int two_third = size / 3 * 2;
    
    // Top left dot:
    cv::rectangle(diceFace1, cv::Point(1, 1), cv::Point(one_third, one_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Bottom right dot:
    cv::rectangle(diceFace1, cv::Point(two_third, two_third), cv::Point(size - 2, size - 2), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Top Right dot:
    cv::rectangle(diceFace1, cv::Point(two_third, 1), cv::Point(size - 2, one_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Bottom Left dot:
    cv::rectangle(diceFace1, cv::Point(1, size - 2), cv::Point(one_third, two_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Middle dot:
    cv::rectangle(diceFace1, cv::Point(one_third, one_third), cv::Point(two_third, two_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);

    // Make dice face outlines on 1/3, 2/3 sections, both vertically and hortizontally (create into a 3 by 3)
    // Vertical lines
    cv::line(diceFace1, cv::Point(one_third, 0), cv::Point(one_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(two_third, 0), cv::Point(two_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Horizontal lines
    cv::line(diceFace1, cv::Point(0, one_third), cv::Point(size - 1, one_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(0, two_third), cv::Point(size - 1, two_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    
    return diceFace1;
}

// ------------------------------------------ createDiceFace6() ---------------------------------------------- //

// Face 6
// 6 dots, vertically standing
cv::Mat createDiceFace6(int size) {
    // Create a white image
    cv::Mat diceFace1(size, size, CV_8UC3, cv::Scalar(255, 255, 255));

    // Make outline of white image with red line
    cv::rectangle(diceFace1, cv::Point(0, 0), cv::Point(size - 1, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Draw a black rectangle in the middle of the die (for die with 1 face, just 2 dots top right, bottom left)
    int one_third = size / 3;
    int two_third = size / 3 * 2;
    
    // Top left dot:
    cv::rectangle(diceFace1, cv::Point(1, 1), cv::Point(one_third, one_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Middle left dot:
    cv::rectangle(diceFace1, cv::Point(1, one_third), cv::Point(one_third, two_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Bottom Left dot:
    cv::rectangle(diceFace1, cv::Point(1, size - 2), cv::Point(one_third, two_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Top Right dot:
    cv::rectangle(diceFace1, cv::Point(two_third, 1), cv::Point(size - 2, one_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // middle right dot:
    cv::rectangle(diceFace1, cv::Point(two_third, one_third), cv::Point(size - 2, two_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Bottom right dot:
    cv::rectangle(diceFace1, cv::Point(two_third, two_third), cv::Point(size - 2, size - 2), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    
    // Make dice face outlines on 1/3, 2/3 sections, both vertically and hortizontally (create into a 3 by 3)
    // Vertical lines
    cv::line(diceFace1, cv::Point(one_third, 0), cv::Point(one_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(two_third, 0), cv::Point(two_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Horizontal lines
    cv::line(diceFace1, cv::Point(0, one_third), cv::Point(size - 1, one_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(0, two_third), cv::Point(size - 1, two_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    
    return diceFace1;
}

// ------------------------------------------ createDiceFace7() ---------------------------------------------- //

// Face 7
// 2 dots, top right and bottom left
cv::Mat createDiceFace7(int size) {
    // Create a white image
    cv::Mat diceFace1(size, size, CV_8UC3, cv::Scalar(255, 255, 255));

    // Make outline of white image with red line
    cv::rectangle(diceFace1, cv::Point(0, 0), cv::Point(size - 1, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Draw a black rectangle in the middle of the die (for die with 1 face, just 2 dots top right, bottom left)
    int one_third = size / 3;
    int two_third = size / 3 * 2;
   
    // Bottom Left dot:
    cv::rectangle(diceFace1, cv::Point(1, size - 2), cv::Point(one_third, two_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Top Right dot:
    cv::rectangle(diceFace1, cv::Point(two_third, 1), cv::Point(size - 2, one_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);

    // Make dice face outlines on 1/3, 2/3 sections, both vertically and hortizontally (create into a 3 by 3)
    // Vertical lines
    cv::line(diceFace1, cv::Point(one_third, 0), cv::Point(one_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(two_third, 0), cv::Point(two_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Horizontal lines
    cv::line(diceFace1, cv::Point(0, one_third), cv::Point(size - 1, one_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(0, two_third), cv::Point(size - 1, two_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    
    return diceFace1;
}

// ------------------------------------------ createDiceFace8() ---------------------------------------------- //

// 3 dots, middle, top left, bottom right
cv::Mat createDiceFace8(int size) {
    // Create a white image
    cv::Mat diceFace1(size, size, CV_8UC3, cv::Scalar(255, 255, 255));

    // Make outline of white image with red line
    cv::rectangle(diceFace1, cv::Point(0, 0), cv::Point(size - 1, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Draw a black rectangle in the middle of the die (for die with 1 face, just 2 dots top right, bottom left)
    int one_third = size / 3;
    int two_third = size / 3 * 2;
   
    // Bottom Left dot:
    cv::rectangle(diceFace1, cv::Point(1, size - 2), cv::Point(one_third, two_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Top Right dot:
    cv::rectangle(diceFace1, cv::Point(two_third, 1), cv::Point(size - 2, one_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Middle dot:
    cv::rectangle(diceFace1, cv::Point(one_third, one_third), cv::Point(two_third, two_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);


    // Make dice face outlines on 1/3, 2/3 sections, both vertically and hortizontally (create into a 3 by 3)
    // Vertical lines
    cv::line(diceFace1, cv::Point(one_third, 0), cv::Point(one_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(two_third, 0), cv::Point(two_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Horizontal lines
    cv::line(diceFace1, cv::Point(0, one_third), cv::Point(size - 1, one_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(0, two_third), cv::Point(size - 1, two_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    
    return diceFace1;
}

// ------------------------------------------ createDiceFace9() ---------------------------------------------- //

// 6 dots, horizontal
cv::Mat createDiceFace9(int size) {
    // Create a white image
    cv::Mat diceFace1(size, size, CV_8UC3, cv::Scalar(255, 255, 255));

    // Make outline of white image with red line
    cv::rectangle(diceFace1, cv::Point(0, 0), cv::Point(size - 1, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Draw a black rectangle in the middle of the die (for die with 1 face, just 2 dots top right, bottom left)
    int one_third = size / 3;
    int two_third = size / 3 * 2;
    
    // Top left dot:
    cv::rectangle(diceFace1, cv::Point(1, 1), cv::Point(one_third, one_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Top middle
    cv::rectangle(diceFace1, cv::Point(one_third, 1), cv::Point(two_third, one_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Bottom right dot:
    cv::rectangle(diceFace1, cv::Point(two_third, two_third), cv::Point(size - 2, size - 2), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Top Right dot:
    cv::rectangle(diceFace1, cv::Point(two_third, 1), cv::Point(size - 2, one_third), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Bottom Left dot:
    cv::rectangle(diceFace1, cv::Point(1, two_third), cv::Point(one_third, size - 2), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);
    // Bottom Middle dot:
    cv::rectangle(diceFace1, cv::Point(one_third, two_third), cv::Point(two_third, size - 2), cv::Scalar(0, 0, 0), -1, cv::LINE_AA, 0);

    // Make dice face outlines on 1/3, 2/3 sections, both vertically and hortizontally (create into a 3 by 3)
    // Vertical lines
    cv::line(diceFace1, cv::Point(one_third, 0), cv::Point(one_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(two_third, 0), cv::Point(two_third, size - 1), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);

    // Horizontal lines
    cv::line(diceFace1, cv::Point(0, one_third), cv::Point(size - 1, one_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    cv::line(diceFace1, cv::Point(0, two_third), cv::Point(size - 1, two_third), cv::Scalar(0, 0, 0), 1, cv::LINE_AA, 0);
    
    return diceFace1;
}
