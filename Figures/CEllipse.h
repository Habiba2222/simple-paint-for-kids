#pragma once
#include "CFigure.h"
class CEllipse :
	public CFigure
{
private:
	Point P;
public:
	CEllipse(Point,GfxInfo);
	virtual void Draw(Output* pOut) const;
	bool SelectFigure(Point);
	GfxInfo GetGfxInfo();
	void PrintInfo(Output* pOut);
	virtual Point Shift(Point&p, Point &p2);
	//virtual void Paste(Point P1, Point P2, Point P3);
	virtual int figuretype();
};

