#include "CEllipse.h"
# define PI           3.14159265358979323846


CEllipse::CEllipse(Point Pp1,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	P = Pp1;
}

void CEllipse::Draw(Output* pOut)const {
	pOut->DrawEllipse(P,FigGfxInfo, Selected);
}

bool CEllipse::SelectFigure(Point A) {
	float Area = (((A.x - P.x)*(A.x - P.x)) / (150*150)) + (((A.y - P.y)*(A.y - P.y)) / (70*70));
		return(Area <= 1);
}
GfxInfo CEllipse::GetGfxInfo() { 
	return FigGfxInfo;
}
void CEllipse::PrintInfo(Output* pOut) {
	string id = to_string(ID);
	string Area =to_string((PI*100*50)/1.00);

	pOut->PrintMessage("Ellipse with id Of " + id + ", The two radii are 100,50 , Area is " + Area+" ,Center is ("+to_string(P.x)+","+to_string(P.y)+")" );
}
Point CEllipse::Shift(Point&p, Point &p8) {
	Point P;
	P.x = 0;
	P.y = 0;
	return P;
}
int CEllipse::figuretype() {
	return 1;
}