#include "CutAction.h"
#include"ApplicationManager.h"
CutAction::CutAction(ApplicationManager *pApp):Action(pApp)
{}
void CutAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("The selected figure is cut, Please paste anywhere");
	pManager->Cut();
}
void CutAction::Execute()
{
	ReadActionParameters();
}
