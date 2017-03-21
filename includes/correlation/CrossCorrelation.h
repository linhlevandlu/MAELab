/*
 * CrossCorrelation.h
 *
 *  Created on: Dec 2, 2016
 *      Author: linh
 */

#ifndef CROSSCORRELATION_H_
#define CROSSCORRELATION_H_
vector<Point> verifyLandmarks(Image mImage, Image sImage,
		vector<Point> manualLM, vector<Point> esLandmarks, int templSize,
		int sceneSize, double angleDiff, Point ePoint);
vector<Point> verifyLandmarks2(ptr_IntMatrix mImage, ptr_IntMatrix sImage,
	vector<Point> manualLM, vector<Point> esLandmarks, int templSize,
	int sceneSize);
ptr_IntMatrix createTemplate2(ptr_IntMatrix inputImage, Point centerPoint,
	int tsize, Point &tlCorn, Point &brCorner, Point &distance);
vector<Point> verifyLandmarks3(ptr_IntMatrix mImage, ptr_IntMatrix sImage,
	vector<Point> manualLM, vector<Point> esLandmarks, int templSize,
	int sceneSize,vector<Point> lsEdgePoints);
class CrossCorrelation
{
public:
	CrossCorrelation();
	virtual ~CrossCorrelation();
};

#endif /* CROSSCORRELATION_H_ */
