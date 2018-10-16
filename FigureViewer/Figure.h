#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
protected:
	int size;
	int offsetX, offsetY;
private:
	COLORREF color;
	HDC dc;
	bool isDragging;
	int previousX, previousY;
public:
	Figure(int size, int offsetX, int offsetY) : size(size), offsetX(offsetX), offsetY(offsetY), isDragging(false), previousX(0), previousY(0)
	{
		color = RGB(255, 0, 0);
	}
	void Clear(HDC dc)
	{
		RECT r;
		GetClientRect(WindowFromDC(dc),&r);
		HPEN pen = (HPEN)SelectObject(dc, CreatePen(PS_SOLID, 1, RGB(0,0,0)));
		Rectangle(dc,0,0,r.right,r.bottom);
		pen = (HPEN)SelectObject(dc, CreatePen(PS_SOLID, 1, color));
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
	void StartDragging(HDC dc, int X, int Y)
	{
		/* ... */
		this->dc = dc;
		isDragging = true;
	}

	void Drag(int X, int Y) 
	{
		/* ... */
		RECT r;
		GetClientRect(WindowFromDC(dc), &r);
		offsetX += X;
		offsetY += Y;
		if (offsetX + size > r.right)
		{
			offsetX -= X;
		}
		if (offsetX - size < 0) {
			offsetX += X;
		}
		if (offsetY + size > r.bottom)
		{
			offsetY -= Y;
		}
		if (offsetY - size < 0)
		{
			offsetY += Y;
		} 
		
	}
	void StopDragging()
	{
		isDragging = false;
		
	}
	bool IsDragging()
	{
		return isDragging;
	}
	void IncreaseSize()
	{
		size += 1;
	}
	void DecreaseSize()
	{
		if (size > 0) {
			size -= 1;

		}
	}

	void setColor(HDC dc, COLORREF color) {
		this->color = color;
		HPEN pen = (HPEN)SelectObject(dc, CreatePen(PS_SOLID, 1, color));
	}
};

#endif FIGURE_H
