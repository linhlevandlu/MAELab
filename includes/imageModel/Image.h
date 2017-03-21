/*
 * Image.h
 *
 *  Created on: Sep 16, 2016
 *      Author: linh
 */

#ifndef IMAGE_H_
#define IMAGE_H_
#include "Edge.h"
class Image
{
private:
	std::string fileName;
	vector<Line> listOfLines;
	vector<Point> manualLandmarks;
	vector<Point> autoLandmarks;
	ptr_IntMatrix grayMatrix;
	ptr_RGBMatrix imgMatrix;
	ptr_IntMatrix grayHistogram;
	float medianHistogram;
	float meanHistogram;
	float thresholdValue;

	void calcGrayHistogram();
	void calThresholdValue();

public:
	Image();
	Image(const Image &cpimage);
	~Image();
	Image(std::string);
	void setFileName(std::string);
	std::string getFileName();
	string getName();
	void setMLandmarks(string);
	void setRGBMatrix(ptr_RGBMatrix);
	void setGrayMatrix(Matrix<int>);
	void setAutoLandmarks(vector<Point>);
	ptr_IntMatrix getGrayMatrix();
	ptr_RGBMatrix getRGBMatrix();
	ptr_IntMatrix getHistogram();
	float getMedianHistogram();
	float getMeanHistogram();
	float getThresholdValue();
	vector<Line> getListOfLines();
	vector<Point> getListOfManualLandmarks();
	vector<Point> getListOfAutoLandmarks();

	vector<Edge> cannyAlgorithm();
	vector<Line> getApproximateLines(double minDistance);
	vector<Point> readManualLandmarks(string fileName);

	/*ptr_DoubleMatrix getRotationMatrix2D(Point center, double angle,
		double scale);*/
	void rotate(Point center, double angle, double scale);
};
typedef Image* ptr_Image;
#endif /* IMAGE_H_ */
