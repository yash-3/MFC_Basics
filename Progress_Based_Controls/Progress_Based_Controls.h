
// Progress_Based_Controls.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CProgressBasedControlsApp:
// See Progress_Based_Controls.cpp for the implementation of this class
//

class CProgressBasedControlsApp : public CWinApp
{
public:
	CProgressBasedControlsApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CProgressBasedControlsApp theApp;
