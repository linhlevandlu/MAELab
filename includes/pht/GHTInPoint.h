/*
 * GHTInPoint.h
 *
 *  Created on: Jan 17, 2017
 *      Author: linh
 */

#ifndef GHTINPOINT_H_
#define GHTINPOINT_H_
struct PolarValue
{
	Point p;
	double angle;
	double distance;
};

struct REntry
{
	double gradient;
	vector<PolarValue> polarValues;
};
struct RTable
{
	Point center;
	vector<REntry> entriesTable;
};
ptr_IntMatrix getGradientDMatrix(Image grayImage,vector<Point> &edgePoints);
double angleVector(Point p1, Point p2, Point q1, Point q2);
RTable rTableConstruct(ptr_IntMatrix gradMatrix, Point center);
Point houghSpace(ptr_IntMatrix gradMatrix, RTable rentries);
vector<Point> detectLandmarks(Point refPoint, Point ePoint,
		vector<Point> mlandmarks);
//Point centroidPoint(ptr_IntMatrix gradMatrix);
double avgDistance(vector<Point> listPoints, Line axis);
Line principalAxis(ptr_IntMatrix gradMatrix, Point &cPoint);
vector<Point> generalizingHoughTransform(ptr_IntMatrix mGradient,
		ptr_IntMatrix sGradient, vector<Point> mLandmarks, Point &ePoint,
		Point &mPoint, double &angle, Point &translation, Point &mtranslation);
vector<Point> ghtWithEntries(RTable rEntries, Line mLine,
	Point mcPoint, ptr_IntMatrix sGradient, vector<Point> mLandmarks,
	Point &ePoint, Point &mPoint, double &angle, Point &translation, Point &mtranslation);
#endif /* GHTINPOINT_H_ */
