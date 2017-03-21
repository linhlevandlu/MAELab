/*
 * Edge.h
 *
 *  Created on: Sep 15, 2016
 *      Author: linh
 */

#ifndef EDGE_H_
#define EDGE_H_
bool checkPointInList(std::vector<Point>, Point);
class Edge
{

private:
	std::vector<Point> listOfPoints; // list of points in the edge
	std::vector<Point> listOfBreakPoints; // list of break points in edge. Break point is connection point between two lines on edge.
	void breakEdge(double);

public:
	struct comparex
	{
		bool operator()(Point p1, Point p2)
		{
			return p1.getX() < p2.getX();
		}
	} xComparation;
	struct comparey
	{
		bool operator()(Point p1, Point p2)
		{
			return p1.getY() < p2.getY();
		}
	} yComparation;
	Edge();
	Edge(const Edge &cpedge);
	virtual ~Edge();
	Edge(std::vector<Point>);

	std::vector<Point> getPoints();
	void setPoints(std::vector<Point>);
	std::vector<Point> segment(double);

	std::vector<Line> getLines(std::vector<Point>);

	void sortByX();
	void sortByY();

};
typedef Edge* ptr_Edge;
#endif /* EDGE_H_ */
