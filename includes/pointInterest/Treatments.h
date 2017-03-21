/*
 * Treatments.h
 *
 *  Created on: Dec 2, 2016
 *      Author: linh
 */

#ifndef TREATMENTS_H_
#define TREATMENTS_H_

class Treatments
{
protected:
	Image refImage;
public:
	Treatments();
	Treatments(Image);
	virtual ~Treatments();
	void setRefImage(Image);
	Image getRefImage();

};
typedef Treatments* ptr_Treatments;
#endif /* TREATMENTS_H_ */
