#pragma once

#include "opencv2/opencv.hpp"

//int determineDiceFace(int avgInt1, int avgInt2, int avgInt3, int avgInt4, int avgInt5, int avgInt6, int avgInt7, int avgInt8, int avgInt9);

void calculateDieSubsections(int dieWidth, int& left, int& center, int& right);

void processDie(const cv::Mat& inputImage, cv::Mat& outputImage, int row, int startX, int endX,
                 int startY, int endY, int leftSection, int centerSection, int rightSection);
