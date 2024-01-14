#include "CTriangle.h"



CTriangle::CTriangle(Point Pp1,Point Pp2,Point Pp3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P1 = Pp1;
	P2 = Pp2;
	P3 = Pp3;
}

void CTriangle::Draw(Output* pOut)const {
	pOut->DrawTri(P1,P2,P3,FigGfxInfo,Selected);
}

bool CTriangle::SelectFigure(Point A) {
	double Area = abs((P1.x)*(P2.y - P3.y) +(P2.x)*(P3.y-P1.y)+(P3.x)*(P1.y-P2.y))/2;
	double Area1= abs((A.x)*(P2.y - P3.y) + (P2.x)*(P3.y - A.y) + (P3.x)*(A.y - P2.y)) / 2;
	double Area2= abs((A.x)*(P1.y - P3.y) + (P1.x)*(P3.y - A.y) + (P3.x)*(A.y - P1.y)) / 2;
	double Area3= abs((A.x)*(P1.y - P2.y) + (P1.x)*(P2.y - A.y) + (P2.x)*(A.y - P1.y)) / 2;
	return (Area >= Area1 + Area2 + Area3);
}
GfxInfo CTriangle::GetGfxInfo() {
	return FigGfxInfo;
}

void CTriangle::PrintInfo(Output* pOut) {
	string id = to_string(ID);
	double Area = abs((P1.x)*(P2.y - P3.y) + (P2.x)*(P3.y - P1.y) + (P3.x)*(P1.y - P2.y)) / 2;
	string area = to_string(Area/1.00);
	pOut->PrintMessage("Triangle of ID " + id + " Vertices are P1(" + to_string(P1.x) + "," + to_string(P1.y) + ") " + " P2(" + to_string(P2.x) + ", " + to_string(P2.y) + ") " + " P3(" + to_string(P3.x) + ", " + to_string(P3.y) + ") ");
}
Point CTriangle::Shift(Point&p, Point &p8) {
	Point P4; // delta
	P4.x = p.x - P1.x;
	P4.y = p.y - P1.y;
	Point Shiftedpoint;
		Shiftedpoint.x = P4.x + P2.x;
	Shiftedpoint.y = P4.y + P2.y;
	p8; 
	p8.x = P4.x + P3.x;
	p8.y = P4.y + P3.y;
		return Shiftedpoint;
}
int CTriangle::figuretype() {
	return 5;
}