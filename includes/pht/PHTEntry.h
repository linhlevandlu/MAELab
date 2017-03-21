/*
 * PHTEntry.h
 *
 *  Created on: Nov 30, 2016
 *      Author: linh
 */

#ifndef PHTENTRY_H_
#define PHTENTRY_H_
struct HoughSpace
{
	double distance;
	double angle;
};
class PHTEntry
{
private:
	Line rLine; // reference line
	Line oLine; // object line
	vector<HoughSpace> listHoughSpace;
public:
	PHTEntry();
	virtual ~PHTEntry();
	vector<HoughSpace> getListHoughSpace();
	void setListHoughSpace(vector<HoughSpace> listHoughSpace);
	Line getObjLine();
	void setObjLine(Line line);
	Line getRefLine();
	void setRefLine(Line line);
	void addHoughSpace(HoughSpace hSpace);
};
typedef PHTEntry* ptr_PHTEntry;
#endif /* PHTENTRY_H_ */
