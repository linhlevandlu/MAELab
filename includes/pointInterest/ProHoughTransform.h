/*
 * ProHoughTransform.h
 *
 *  Created on: Dec 2, 2016
 *      Author: linh
 */

#ifndef PROHOUGHTRANSFORM_H_
#define PROHOUGHTRANSFORM_H_

PHTEntry matchingInScene(vector<PHTEntry> entryTable, vector<Line> sceneLines,
	int width, int height, vector<Line> &maxVector);
Point refPointInScene(PHTEntry entry, vector<Line> matchLines,
	double &angleDiff, vector<Point> refLandmarks, int width, int height);
vector<Point> phtLandmarks(vector<PHTEntry> entriesTable, Point refPoint,
	vector<Line> sceneLines, int width, int height, vector<Point> mLandmarks,
	double &angleDiff, Point &ePoint);

class ProHoughTransform: public Treatments
{
public:
	ProHoughTransform();
	virtual ~ProHoughTransform();
	PHoughTransform constructPHT();
	vector<Point> estimateLandmarks(Image sImage, double &angleDiff,
		Point &ePoint);

	vector<Point> generalTransform(Image &sImage, double &angle, Point &ePoint,
		Point &mPoint, ptr_IntMatrix &newScene, Point &translation,
		vector<Point> &modelSeg, vector<Point> &sceneSeg, vector<Point> &newScenePoints,double &scaleX, double &scaleY, Point &moveScale);
};

#endif /* PROHOUGHTRANSFORM_H_ */
