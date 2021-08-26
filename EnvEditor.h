// EnvEditor.h : main header file for the ENVEDITOR application
//

#if !defined(AFX_ENVEDITOR_H__91CFC715_E80F_4FA0_85F9_C1BFAFD93809__INCLUDED_)
#define AFX_ENVEDITOR_H__91CFC715_E80F_4FA0_85F9_C1BFAFD93809__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CEnvEditorApp:
// See EnvEditor.cpp for the implementation of this class
//

class CEnvEditorApp : public CWinApp
{
public:
	CEnvEditorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnvEditorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CEnvEditorApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENVEDITOR_H__91CFC715_E80F_4FA0_85F9_C1BFAFD93809__INCLUDED_)
