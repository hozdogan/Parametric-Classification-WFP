#include "Point.h"


void Point2D::setPoints(int x, int y)
{
	this->x = x;
	this->y = y;
}
int Point2D::getX()
{
	return this->x;
}
int Point2D::getY()
{
	return this->y;
}
void Point2D::setX(int x)
{
	this->x = x;
}
void Point2D::setY(int y)
{
	this->y = y;
}
int Point2D::getClassID()
{
	return cid;
}
void Point2D::setClassID(int cid)
{
	this->cid = cid;
}

//classification class
double ClassifiersProcess::BTPLen(Point2D* p1, Point2D* p2)
{
	double res = pow(p2->getX() - p1->getX(), 2) + pow(p2->getY() - p2->getX(), 2);
	return sqrt(res);
}
Point2D* ClassifiersProcess::CGCenter(std::vector<Point2D*> vec,int cid)
{
	int sumX = 0;
	int sumY = 0;
	int count = 0;
	
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i]->getClassID() == cid)
		{
			sumX += vec[i]->getX();
			sumY += vec[i]->getY();
			count++;
		}
	}
	Point2D* p = new Point2D();
	p->setClassID(cid);
	p->setPoints(sumX / count, sumY / count);//vec.size a bölünce olmaz nokta kadar bölmen lazým yoksa ortaya toplanýr
	return p;
}





//renk class

int Renk::getRed()
{
	return r;
}
int Renk::getGreen() {
	return g;
}
int Renk::getBlue() {
	return b;
}

void Renk::setBlue(int b)
{
	this->b = b;
}
void Renk::setGreen(int g)
{
	this->g = g;
}
void Renk::setRed(int r)
{
	this->r = r;
}
