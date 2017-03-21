/*
 * JPEGReader.h
 *
 *  Created on: Nov 8, 2016
 *      Author: linh
 */

#ifndef JPEGREADER_H_
#define JPEGREADER_H_
ptr_RGBMatrix decompressJPEG(const char* filename, int &rows, int &cols);
void RGB2JPEG(const char* filename, ptr_RGBMatrix rgbMatrix);
void Gray2JPEG(const char* filename, ptr_IntMatrix grayMatrix);

#endif /* JPEGREADER_H_ */
