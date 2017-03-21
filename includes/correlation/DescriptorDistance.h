/*
 * DescriptorDistance.h
 *
 *  Created on: Feb 28, 2017
 *      Author: linh
 */

#ifndef DESCRIPTORDISTANCE_H_
#define DESCRIPTORDISTANCE_H_
Point nearestPoint(vector<Point> lsPoints, Point p);
vector<Point> verifyDescriptors(ptr_IntMatrix model, ptr_IntMatrix scene,
	vector<Point> manualLM, vector<Point> esLandmarks, int templSize,
	int sceneSize);
vector<Point> verifyDescriptors2(ptr_IntMatrix model, ptr_IntMatrix scene,
	vector<Point> scenePoints, vector<Point> manualLM, vector<Point> esLandmarks,
	int templSize, int sceneSize);
#endif /* DESCRIPTORDISTANCE_H_ */
