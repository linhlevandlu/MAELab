/*
 * Drawing.h
 *
 *  Created on: Dec 18, 2016
 *      Author: linh
 */

#ifndef DRAWING_H_
#define DRAWING_H_

void drawingCircle(Matrix<RGB> &mat, Point center, int radius, RGB color);
void fillCircle(Matrix<RGB> &mat, Point center, int radius, RGB color);
void drawingLine(Matrix<RGB> &mat, Line line, RGB color);
#endif /* DRAWING_H_ */
