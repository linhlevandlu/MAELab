/*
 * Segmentation.h
 *
 *  Created on: Dec 2, 2016
 *      Author: linh
 */

#ifndef SEGMENTATION_H_
#define SEGMENTATION_H_

class Segmentation: public Treatments
{
public:
	Segmentation();
	virtual ~Segmentation();
	vector<Line> segment();
	ptr_IntMatrix threshold(int tValue, int maxValue);
	vector<Edge> canny();
	int removePronotum();
	void gridRemoveFolder();
};

#endif /* SEGMENTATION_H_ */
