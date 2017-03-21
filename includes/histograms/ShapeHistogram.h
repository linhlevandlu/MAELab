/*
 * LocalHistogram.h
 *
 *  Created on: Oct 18, 2016
 *      Author: linh
 */

#ifndef SHAPEHISTOGRAM_H_
#define SHAPEHISTOGRAM_H_

/*class LocalHistogram {
 private:
 vector<GFeature> listFeatures;
 public:
 LocalHistogram();
 virtual ~LocalHistogram();
 };*/
enum AngleAccuracy
{
	HaftDegree = 0,
	Degree = 1,
	TwoTimeDegree = 2,
	FourTimeDegree = 4,
	SixTimeDegree = 6,
	TwelveTimeDegree = 12,
	SixtyTimeDegree = 60
};
struct GFeature
{
	double angle; // angle in degree
	double dmin;
	double dmax;
};

struct LocalHistogram
{
	vector<GFeature> features;
	double maxDistance;
};

class ShapeHistogram
{
private:
	ptr_IntMatrix matrix;
	vector<LocalHistogram> listLocalHistogram;
	double totalEntries;
	double max_distance;
public:
	ShapeHistogram();
	virtual ~ShapeHistogram();

	double getEntries();
	void setEntries(double);
	ptr_IntMatrix getMatrix();
	void setMatrix(ptr_IntMatrix);
	void setMaxDistance(double);
	double getMaxDistance();
	void setLocalHistogram(vector<LocalHistogram>);
	vector<LocalHistogram> getLocalHistogram();

	vector<LocalHistogram> constructPGH(vector<Line> listOfLines);
	ptr_IntMatrix constructPGHMatrix(vector<LocalHistogram> localHists,
			AngleAccuracy angleAcc, int cols);
};

#endif /* LOCALHISTOGRAM_H_ */
