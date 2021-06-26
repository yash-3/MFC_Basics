
// Array_Operations.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CArrayOperationsApp:
// See Array_Operations.cpp for the implementation of this class
//

class CArrayOperationsApp : public CWinApp
{
public:
	CArrayOperationsApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CArrayOperationsApp theApp;
