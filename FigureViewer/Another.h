#ifndef ANOTHER_H
#define ANOTHER_H

#include "Figure.h"

class Another : public Figure
{
public:
	Another(int size = 25, int offsetX = 50, int offsetY = 50) : Figure(size, offsetX, offsetY)
	{

	}
	void Draw(HDC dc)
	{
		Rectangle(dc, offsetX - size, offsetY - size, offsetX + size, offsetY + size);
		//Ellipse(dc, offsetX - size, offsetY - size, offsetX + size, offsetY + size);
		MoveToEx(dc, offsetX - size, offsetY - size, NULL);
		LineTo(dc, offsetX + size, offsetY + size);
		MoveToEx(dc, offsetX - size, offsetY + size, NULL);
		LineTo(dc, offsetX + size, offsetY - size);
	}
	bool InnerPoint(int X, int Y)
	{
		return (X - offsetX)*(X - offsetX) + (Y - offsetY)*(Y - offsetY) <= size * size;
	}
};

#endif ANOTHER_H
