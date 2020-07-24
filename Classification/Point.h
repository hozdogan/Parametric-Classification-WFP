#pragma once
#ifndef __POINT_H__
#define __POINT_H__
#include<vector>

class Point2D
{
public:
	Point2D(int x,int y)
	{
		this->x = x;
		this->y = y;
	}
	Point2D() {};
	void setX(int);
	int getX();
	void setY(int);
	int getY();
	void setPoints(int, int);
	void setClassID(int cid);
	int getClassID();
	
private:
	int x, y,cid;

};


class ClassifiersProcess
{
public:
	double BTPLen(Point2D* p1, Point2D* p2);
	Point2D* CGCenter(std::vector<Point2D*> vec,int);
		
private:


};

class Renk
{
public:
	Renk(int r, int g, int b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}
	int getRed();
	int getBlue();
	int getGreen();
	void setRed(int);
	void setGreen(int);
	void setBlue(int);
	
private:
	int r, g, b;
};





#endif // ! __POINT_H__
