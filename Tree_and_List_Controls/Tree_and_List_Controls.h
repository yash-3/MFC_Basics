
// Tree_and_List_Controls.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTreeandListControlsApp:
// See Tree_and_List_Controls.cpp for the implementation of this class
//

class CTreeandListControlsApp : public CWinApp
{
public:
	CTreeandListControlsApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTreeandListControlsApp theApp;
