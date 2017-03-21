/*
 * Point.h
 *
 *  Created on: Sep 14, 2016
 *      Author: linh
 */

#ifndef POINT_H_
#define POINT_H_
struct RGB
{
	unsigned short int R;
	unsigned short int G;
	unsigned short int B;
	RGB operator+(const RGB& color) const
	{
		RGB result;
		result.R = color.R + R;
		result.G = color.G + G;
		result.B = color.B + B;
		return result;
	}
	RGB operator*(const RGB& color) const
	{
		RGB result;
		result.R = color.R * R;
		result.G = color.G * G;
		result.B = color.B * B;
		return result;
	}
	RGB operator/(const double c) const
	{
		RGB result;
		result.R = R / c;
		result.G = G / c;
		result.B = B / c;
		return result;
	}
	RGB operator+=(const RGB& color) const
	{
		RGB result;
		result.R = color.R + R;
		result.G = color.G + G;
		result.B = color.B + B;
		return result;
	}
	bool operator==(const int i) const
	{
		if (R == i && G == i && B == i)
			return true;
		return false;
	}
	bool operator>(const int i) const
	{
		if (R > i && G > i && B > i)
			return true;
		return false;
	}
	bool operator>=(const int i) const
	{
		if (R >= i && G >= i && B >= i)
			return true;
		return false;
	}
};

class Point
{
private:
	int x;
	int y;
	RGB color;
public:
	Point();
	Point(const Point &cpPoint);
	Point(int xCoor, int yCoor)
	{
		x = xCoor;
		y = yCoor;
		color.R = color.G = color.B = 0;
	}
	Point(int xCoor, int yCoor, RGB clor)
	{
		x = xCoor;
		y = yCoor;
		color.R = clor.R;
		color.G = clor.G;
		color.B = clor.B;
	}
	virtual ~Point();
	int getX()
	{
		return x;
	}
	void setX(int xCoor)
	{
		x = xCoor;
	}
	int getY()
	{
		return y;
	}
	void setY(int yCoor)
	{
		y = yCoor;
	}
	RGB getColor();
	void setColor(RGB rgb);
	void toString();
	bool operator<(const Point &cPoint);
	bool operator>(const Point &cPoint);
	bool operator==(const Point &cPoint);
	bool operator!=(int value);
	Point operator-(const Point cPoint);
	Point operator+(const Point cPoint);
};

typedef Point *ptr_Point;

#endif /* POINT_H_ */
