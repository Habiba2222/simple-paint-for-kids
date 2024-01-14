#include "CopytoCB.h"
#include"ApplicationManager.h"

CopytoCB::CopytoCB(ApplicationManager *pApp):Action(pApp)
{
}
void CopytoCB::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("The selected figure is copied, Please paste anywhere");
	pManager->CopyToCB();
}
void CopytoCB::Execute()
{
	ReadActionParameters();
}