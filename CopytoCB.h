#pragma once
#include "Actions/Action.h"

class CopytoCB : public Action
{
public:
	CopytoCB(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
};

