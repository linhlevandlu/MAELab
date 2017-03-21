/*
 * TPSReader.h
 *
 *  Created on: Oct 6, 2016
 *      Author: linh
 */

#ifndef TPSREADER_H_
#define TPSREADER_H_

std::vector<Point> readTPS(const char* filename);
std::vector<Point> readTPSWithDifference(const char* filename, string &difference);
#endif /* TPSREADER_H_ */
