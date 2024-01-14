#pragma once
#include "CFigure.h"
class CRhombus :
	public CFigure
{
private:
	Point P;
public:
	CRhombus(Point, GfxInfo);
	virtual void Draw(Output*)const;
	bool SelectFigure(Point);
	GfxInfo GetGfxInfo();
	void PrintInfo(Output* pOut);
	virtual Point Shift(Point &p, Point &p8);
	virtual int figuretype();
};

