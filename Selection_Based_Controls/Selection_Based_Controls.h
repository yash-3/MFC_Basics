
// Selection_Based_Controls.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CSelectionBasedControlsApp:
// See Selection_Based_Controls.cpp for the implementation of this class
//

class CSelectionBasedControlsApp : public CWinApp
{
public:
	CSelectionBasedControlsApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CSelectionBasedControlsApp theApp;
