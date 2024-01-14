#pragma once
#include "CFigure.h"
class CTriangle :
	public CFigure
{
private:
	Point P1;
	Point P2;
	Point P3;
public:
	CTriangle(Point , Point , Point , GfxInfo FigureGfxInfo);
	virtual void Draw(Output* pOut) const;
	bool SelectFigure(Point);
	GfxInfo GetGfxInfo();
	void PrintInfo(Output* pOut);
	virtual Point Shift(Point&p, Point &p8);
	virtual int figuretype();
};



