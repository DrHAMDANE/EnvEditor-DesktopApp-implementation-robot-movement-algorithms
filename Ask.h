#if !defined(AFX_ASK_H__4350A062_5AC5_4110_9AB1_B001C8297D81__INCLUDED_)
#define AFX_ASK_H__4350A062_5AC5_4110_9AB1_B001C8297D81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Ask.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAsk dialog

class CAsk : public CDialog
{
// Construction
public:
	CAsk(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAsk)
	enum { IDD = IDD_DIALOG1 };
	BOOL	m_OM;
	UINT	m_HI;
	UINT	m_WI;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAsk)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAsk)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASK_H__4350A062_5AC5_4110_9AB1_B001C8297D81__INCLUDED_)
