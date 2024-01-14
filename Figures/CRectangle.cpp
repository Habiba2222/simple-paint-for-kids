#include "CRectangle.h"

CRectangle::CRectangle(Point Pp1, Point Pp2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P1 = Pp1;
	P3 = Pp2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(P1, P3, FigGfxInfo, Selected);
}
bool CRectangle::SelectFigure(Point A) 
{
	return ((A.x >= P1.x) && (A.x <= P3.x) && (A.y >= P1.y) && (A.y <= P3.y));
	/*Point P2;
	Point P4;
		P2.x = P3.x; P2.y = P1.y;
		P4.x = P1.x; P4.y = P3.y;
		double Area = abs((((P1.x)*(P2.y - P3.y) + (P2.x)*(P3.y - P1.y) + (P3.x)*(P1.y - P2.y)) / 2)) +
			abs((((P1.x)*(P4.y - P3.y) + (P4.x)*(P3.y - P1.y) + (P4.x)*(P1.y - P4.y)) / 2));
		double Area1 = abs((A.x)*(P2.y - P3.y) + (P2.x)*(P3.y - A.y) + (P3.x)*(A.y - P2.y)) / 2;
		double Area2 = abs((A.x)*(P4.y - P3.y) + (P4.x)*(P3.y - A.y) + (P3.x)*(A.y - P4.y)) / 2;
		double Area3 = abs((A.x)*(P1.y - P2.y) + (P1.x)*(P2.y - A.y) + (P2.x)*(A.y - P1.y)) / 2;
		double Area4 = abs((A.x)*(P4.y - P1.y) + (P4.x)*(P1.y - A.y) + (P1.x)*(A.y - P4.y)) / 2;
		SetSelected(Area >= Area1 + Area2 + Area3 + Area4);
		return(Area >= Area1 + Area2 + Area3 + Area4);*/		
}
GfxInfo CRectangle::GetGfxInfo() {
	return FigGfxInfo;
}

void CRectangle::PrintInfo(Output* pOut) {
	string id = to_string(ID);
	string length = to_string(abs(P1.y - P3.y));
	string width  = to_string(abs(P1.x - P3.x)); 
	string area = to_string(abs(P1.y - P3.y)*abs(P1.x - P3.x));
	pOut->PrintMessage("Rectange of ID " + id + " ,Length of " + length + " ,Width of " + width + " ,Area Of " + area);
}
Point CRectangle::Shift(Point&p, Point &p8) {
	//Output*pOut = NULL;
	Point Shiftedpoint;
	Point P4;
	P4.x =p.x - P1.x;
	P4.y =p.y - P1.y;
	Shiftedpoint.x = P3.x + P4.x;
	Shiftedpoint.y = P3.y + P4.y;
	return Shiftedpoint;
}
int CRectangle::figuretype() {
	return 3;
}