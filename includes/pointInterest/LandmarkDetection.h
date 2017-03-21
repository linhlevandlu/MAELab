/*
 * LandmarkDetection.h
 *
 *  Created on: Dec 7, 2016
 *      Author: linh
 */

#ifndef LANDMARKDETECTION_H_
#define LANDMARKDETECTION_H_

class LandmarkDetection: public Treatments
{
private:
	vector<Point> refineLandmarks(vector<Point> estLandmarks,vector<Point> segmentation);
public:
	LandmarkDetection();
	virtual ~LandmarkDetection();
	vector<Point> landmarksAutoDectect(Image sceneImage, AngleAccuracy acc,
		int cols, int templSize, int sceneSize, Point &ePoint,
		double &angleDiff);
	void landmarksOnDir(string modelName,string folderScene,
		vector<string> sceneImages, AngleAccuracy acc, int cols, int templSize,
		int sceneSize, Point &ePoint, double &angleDiff,string saveFolder);
	vector<Point> landmarksAutoDectect2(Image &sceneImage,
			int templSize, int sceneSize);
	vector<Point> landmarksWithSIFT(Image &sceneImage,
			int templSize, int sceneSize);
	void landmarksOnDir2(string modelName, string folderScene,
		vector<string> sceneImages, string saveFolder);
	void landmarksOnDir3(string modelName, string folderScene,
		vector<string> sceneImages, string saveFolder);
	void landmarksOnDir4(string modelName, string folderScene,
		vector<string> sceneImages, string saveFolder, string folderLandmarks,
		vector<string> landmarks);
};

#endif /* LANDMARKDETECTION_H_ */
