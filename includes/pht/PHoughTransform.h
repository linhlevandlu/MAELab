/*
 * PHoughTransform.h
 *
 *  Created on: Nov 30, 2016
 *      Author: linh
 */

#ifndef PHOUGHTRANSFORM_H_
#define PHOUGHTRANSFORM_H_

bool closetLine(Line line1, Line line2);
class PHoughTransform {
private:
	Point refPoint;
	vector<PHTEntry> phtEntries;
	//ptr_IntMatrix accumulator;
public:
	PHoughTransform();
	virtual ~PHoughTransform();

	void setRefPoint(Point rpoint);
	Point getRefPoint();
	vector<PHTEntry> getPHTEntries();
	vector<PHTEntry> constructPHTTable(vector<Line> lines);
};

#endif /* PHOUGHTRANSFORM_H_ */
