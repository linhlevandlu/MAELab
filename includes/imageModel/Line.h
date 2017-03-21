/*
 * Line.h
 *
 *  Created on: Sep 14, 2016
 *      Author: linh
 */

#ifndef LINE_H_
#define LINE_H_

class Line
{

  private:
    Point begin;
    Point end;
    int dx; // slope of x
    int dy; // slope of y
    double length;
    std::vector<double> equation;

    bool isPoint();
    double lengthOfLine();
    std::vector<double> equationOfLine();

  public:
    Line();
    Line(const Line&);
    Line(Point, Point);
    virtual ~Line();
    Point getBegin();
    Point getEnd();
    double getLength();
    std::vector<double> getEquation();
    void setBegin(Point);
    void setEnd(Point);
    double perpendicularDistance(Point);
    double angleLines(Line);
    Point intersection(Line);
    bool checkBelongPoint(Point);
    vector<Point> interParallel(Line line1, Line line2, double distance1,
    	double distance2, int width, int height);
};
typedef Line* ptr_Line;

double distancePoints(Point p1, Point p2);
#endif /* LINE_H_ */
