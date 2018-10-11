#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
protected:
	int size;
	int offsetX, offsetY;
private:
	bool isDragging;
	int previousX, previousY;
public:
	Figure(int size, int offsetX, int offsetY) : size(size), offsetX(offsetX), offsetY(offsetY), isDragging(false), previousX(0), previousY(0)
	{
	}
	void Clear(HDC dc)
	{
		RECT r;
		GetClientRect(WindowFromDC(dc),&r);
		Rectangle(dc,0,0,r.right,r.bottom);
	}
	virtual void Draw(HDC dc) = 0;
	virtual bool InnerPoint(int X, int Y) = 0;
	void MoveTo(int X, int Y)
	{
		/* ... */
		offsetX = X;
		offsetY = Y;
	}
	void Move(int X, int Y)
	{
		/* ... */
		
		offsetX += X;
		offsetY += Y;
	}
	void StartDragging(int X, int Y)
	{
		/* ... */
		isDragging = true;
	}

	void Drag(int X, int Y) 
	{
		/* ... */
		offsetX = X;
		offsetY = Y;
	}
	void StopDragging()
	{
		isDragging = false;
		
	}
	bool IsDragging()
	{
		return isDragging;
	}
};

#endif FIGURE_H
