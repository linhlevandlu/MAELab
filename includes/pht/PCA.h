/*
 * PCA.h
 *
 *  Created on: Feb 7, 2017
 *      Author: linh
 */

#ifndef PCA_H_
#define PCA_H_
Line principalAxis(ptr_IntMatrix gradMatrix, Point &cPoint);
Line principalAxis(vector<Point> listOfPoints, Point &cPoint);
double rotateDirection(Line refLine, Line objLine, double angle);
vector<Point> PCAIPoints(vector<Point> modelPoints, Point mPoint,
		vector<Point> scenePoints, double angle);
vector<Point> PCAI(Image modelGray, Image &sceneGray, vector<Point> mnLandmarks);
/*void pcaiFolder(string folderScene, vector<string> sceneImages, Image model,
	vector<Point> mnLandmarks,string savePath);*/
#endif /* PCA_H_ */
