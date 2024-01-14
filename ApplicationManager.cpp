#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddTriAction.h"
#include "AddSelectAction.h"
#include "AddLineAction.h"
#include "AddRhombusAction.h"
#include "AddEllipseAction.h"
#include "ChangeFillClrAction.h"
#include "ChangeDrawClrAction.h"
#include "DeleteAction.h"
#include"PasteAction.h"
#include "CopytoCB.h"
#include"CutAction.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}

////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	

	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);

			break;
		case DRAW_RHOMBUS:
			pAct = new AddRhombusAction(this);
			break;
		case DRAW_ELLIPSE:
			pAct = new AddEllipseAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;
		case SELECT_FIGURE:
			pAct = new AddSelectAction(this);
			break;
		case CHNG_DRAW_CLR:
			pAct = new ChangeDrawClrAction(this);
				break;
		case CHNG_FILL_CLR:	
			pAct = new ChangeFillClrAction(this);
			break;
		case COPY:
			pAct = new CopytoCB(this);
			break;

		case EXIT:
			pOut->PrintMessage("Program is exiting now");
			///create ExitAction here
			break;	
		case DEL:
			pAct = new DeleteAction(this);
			break;
		case PASTE:
			pAct = new PasteAction(this);
			break;
		case CUT:
			pAct = new CutAction(this);
			break;
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
int ApplicationManager::GetFigureCount()
{ 
	return FigCount; 
}
void ApplicationManager::ChangeFillColor(color c) {
	UI.FillColor = c;
	UI.IsFilled = true;
}
void ApplicationManager::ChangeDrawColor(color c) {
	UI.DrawColor = c;
}
////////////////////////////////////////////////////////////////////////////////////
void ApplicationManager::UnSelectFigures() {
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
			FigList[i]->SetSelected(false);
	}
}
CFigure *ApplicationManager::GetFigure(Point P) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	CFigure* TopFig =nullptr;
	for (int i = 0; i < FigCount; i++)
	{	
		if (FigList[i]->SelectFigure(P))
			TopFig = FigList[i];
	}

	if (TopFig == nullptr)
		return NULL;
	else
		return TopFig;
}
CFigure *ApplicationManager::GetSelectedFigure()const
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->IsSelected())
			return FigList[i];
	}
}
//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for (int i = 0; i < FigCount; i++)
		if (pOut == NULL)
			return;
		else
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}
void ApplicationManager::DeleteSelectedFigures() {
	int count = 0;
	bool found = false;
	for (int i = 0;i < FigCount;i++) {
		if (FigList[i]->IsSelected()) {
			FigList[i]->SetSelected(false);

			count = i;
			found = true;
		}
	}
	if (found) {
		for (int j = count;j < FigCount - 1;j++) {
			FigList[j] = FigList[j + 1];
		}

		FigList[FigCount] = NULL;
		FigCount--;
		pOut->ClearDrawArea();
		UpdateInterface();
		pOut->ClearStatusBar();
		pOut->CreateDrawToolBar();
	}
}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
void ApplicationManager::CopyToCB()
{
	Clipboard = NULL;
	Clipboard = GetSelectedFigure();
}
void ApplicationManager::Cut()
{
	Clipboard = NULL;
	Clipboard = GetSelectedFigure();
	CuttingColor = GetSelectedFigure()->GetGfxInfo().FillClr;
	GetSelectedFigure()->ChngFillClr(GREY);
}
CFigure* ApplicationManager::getClipboard()
{
	return Clipboard;
}
/*CFigure** ApplicationManager::Getfiglist() {
	return this->FigList;
}
int ApplicationManager::getfigcount() const {
	return FigCount;
}/**/
