#include<iostream>
#include"PasteAction.h"
#include"ApplicationManager.h"
#include"Figures/CEllipse.h"
#include"Figures/CLine.h"
#include"Figures/CRhombus.h"
#include"Figures/CRectangle.h"
#include"Figures/CTriangle.h"
PasteAction::PasteAction(ApplicationManager*pManager) :Action(pManager) {

}
void PasteAction::Execute() {
	//for copy
	Input*pln = pManager->GetInput();
	Output*pOut = pManager->GetOutput();
	pOut->PrintMessage("Paste Action is pressed");
	pln->GetPointClicked(P.x, P.y);
	CFigure* figure= pManager->getClipboard();
	Point P1, p6;
	p6.x = 0;
	p6.y = 0;
	int r = figure->figuretype();
	if (r==3)
	{
		P1 = figure->Shift(P, p6);
		//pManager->AddFigure(figure);
		CRectangle *R = new CRectangle(P, P1, figure->GetGfxInfo());
		//pOut->DrawRect(P, P1, figure->GetGfxInfo(), false);
		pManager->AddFigure(R);
	}
	else if (r==1) {
		P1 = figure->Shift(P, p6);
		CEllipse*E = new CEllipse(P, figure->GetGfxInfo());
		//pOut->DrawEllipse(P, figure->GetGfxInfo(), false);
		pManager->AddFigure(E);
	}
	else if (r==4) {
		P1 = figure->Shift(P, p6);
		CRhombus*R = new CRhombus(P, figure->GetGfxInfo());
		pManager->AddFigure(R);
		//pOut->DrawRhombus(P, figure->GetGfxInfo(), false);
	}
	else if (r==2) 
	{	
		P1 = figure->Shift(P, p6);
		CLine*l = new CLine(P, P1, figure->GetGfxInfo());
		pManager->AddFigure(l);
		//pOut->DrawLine(P, P1, figure->GetGfxInfo(), false);
	}
	else if (r==5) {
		P1 = figure->Shift(P, p6);
		CTriangle*T = new CTriangle(P, P1, p6, figure->GetGfxInfo());
		pManager->AddFigure(T);
	}
	//pOut->ClearDrawArea();
	pManager->UpdateInterface();
	//figure->Draw(pOut);
	//pOut->PrintMessage("Successful");
}
void PasteAction::ReadActionParameters() {

}