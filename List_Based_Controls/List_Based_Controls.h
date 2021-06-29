
// List_Based_Controls.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CListBasedControlsApp:
// See List_Based_Controls.cpp for the implementation of this class
//

class CListBasedControlsApp : public CWinApp
{
public:
	CListBasedControlsApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CListBasedControlsApp theApp;
