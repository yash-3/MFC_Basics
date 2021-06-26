
// Strings_Fundamentals.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CStringsFundamentalsApp:
// See Strings_Fundamentals.cpp for the implementation of this class
//

class CStringsFundamentalsApp : public CWinApp
{
public:
	CStringsFundamentalsApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CStringsFundamentalsApp theApp;
