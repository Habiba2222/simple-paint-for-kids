#include "CLine.h"



CLine::CLine(Point Pp1,Point Pp2, GfxInfo FigGfxInfo):CFigure(FigGfxInfo)
{
	P1 = Pp1;
	P2 = Pp2;
}


void CLine::Draw(Output* pOut)const {
	pOut->DrawLine(P1, P2, FigGfxInfo, Selected);
}

bool CLine::SelectFigure(Point A) {
	////y = a * x + b; //   where a is slope
	//const float Precision = 0.0000000000000000000000000000000000001f;  //as float precision roundings will screw up the calculations

	//float a = (P2.y - P1.y) / (P2.x - P1.x);
	//float b = P1.y - a * P1.x;

	//SetSelected(abs(A.y - (a*A.x + b)) <= Precision);
	//return(abs(A.y - (a*A.x + b)) <= Precision);
	//
	bool betweeny;
	if (P1.y > P2.y) 
		betweeny = (A.y<=P1.y&&A.y>=P2.y);
	else if(P1.y<P2.y)
		betweeny = (A.y>=P1.y&&A.y<=P2.y);

	bool betweenx;
	if (P1.x > P2.x)
		betweenx = (A.x<P1.x&&A.x>P2.x);
	else
		betweenx = (A.x<P2.x&&A.x>P1.x);
			
		return(((A.x - P1.x) / (P2.x - A.x) == (A.y - P1.y) / (P2.y - A.y)) && betweeny&&betweenx);
	
}
GfxInfo CLine::GetGfxInfo() {
	return FigGfxInfo;
}

void CLine::PrintInfo(Output* pOut) {
	string id = to_string(ID);
	double length = sqrt(((P2.x - P1.x)*(P2.x - P1.x)) + ((P2.y - P1.y)*(P2.y - P1.y)));
	string lnth = to_string(length / 1.00);
	pOut->PrintMessage("Line of ID " + id + " Starting Point is " + to_string(P1.x) + "," + to_string(P1.y) + "), Ending Point is (" + to_string(P2.x) + "," + to_string(P2.y) + ")," + " Length is" + lnth);
}
Point CLine::Shift(Point&p, Point &p8) {
	Output*pOut;
	Point Shiftedpoint;
	Point P4;
	P4.x = p.x - P1.x;
	P4.y = p.y - P1.y;
	Shiftedpoint.x = P2.x + P4.x;
	Shiftedpoint.y = P2.y + P4.y;
	return Shiftedpoint;
}
int CLine::figuretype() {
	return 2;
}