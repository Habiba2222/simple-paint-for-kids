#include "CRhombus.h"



CRhombus::CRhombus(Point Pp,GfxInfo Fig):CFigure(Fig)
{
	P = Pp;
}

void CRhombus::Draw(Output* pOut)const{
	pOut->DrawRhombus(P, FigGfxInfo, Selected);
}
bool CRhombus::SelectFigure(Point A){
	Point P1; P1.x = P.x + 100; P1.y = P.y;
	Point P2; P2.x = P.x - 100; P2.y = P.y;
	Point P3; P3.x = P.x; P3.y = P.y + 200;
	Point P4; P4.x = P.x; P4.y = P.y - 200;
double Area = abs((((P1.x)*(P2.y - P3.y) + (P2.x)*(P3.y - P1.y) + (P3.x)*(P1.y - P2.y)) / 2) + 
				(((P1.x)*(P4.y - P3.y) + (P4.x)*(P3.y - P1.y) + (P4.x)*(P1.y - P4.y)) / 2));
double Area1 = abs((A.x)*(P2.y - P3.y) + (P2.x)*(P3.y - A.y) + (P3.x)*(A.y - P2.y)) / 2;
double Area2 = abs((A.x)*(P4.y - P3.y) + (P4.x)*(P3.y - A.y) + (P3.x)*(A.y - P4.y)) / 2;
double Area3 = abs((A.x)*(P1.y - P2.y) + (P1.x)*(P2.y - A.y) + (P2.x)*(A.y - P1.y)) / 2;
double Area4 = abs((A.x)*(P4.y - P1.y) + (P4.x)*(P1.y - A.y) + (P1.x)*(A.y - P4.y)) / 2;
return(Area >= Area1 + Area2 + Area3 + Area4);
	///*float Area = (abs((A.x) / 100)) + (abs((A.y) / 200));
	//if (Area <= 1.0) {
	//	SetSelected(true);
	//	return true;
	//}
	//return false;*/
}
GfxInfo CRhombus::GetGfxInfo() {
	return FigGfxInfo;
}
void CRhombus::PrintInfo(Output* pOut) {
	string id = to_string(ID);
	pOut->PrintMessage("Rhombus of ID " + id + " ,Center is (" + to_string(P.x) +","+ to_string(P.y)+") Two diagonals are 200,400");
}
Point CRhombus::Shift(Point&p, Point &p8) {
	Point Shiftedpoint;
	Shiftedpoint.x = 0;
	Shiftedpoint.y = 0;
	return Shiftedpoint;
}
int CRhombus::figuretype() {
	return 4;
}