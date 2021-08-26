#if !defined(AFX_EQUDLG_H__14487E37_0BFC_487E_83A7_C3CF7DD02A65__INCLUDED_)
#define AFX_EQUDLG_H__14487E37_0BFC_487E_83A7_C3CF7DD02A65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EquDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEquDlg dialog

class CEquDlg : public CDialog
{
// Construction
public:
	int type;
	CEquDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEquDlg)
	enum { IDD = IDD_DIALOG_EQU };
	CButton	mRadio2;
	CButton	mRadio1;
	int		AX;
	int		AY;
	int		BX;
	int		BY;
	int		Period;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEquDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEquDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadio3();
	afx_msg void OnRadio1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EQUDLG_H__14487E37_0BFC_487E_83A7_C3CF7DD02A65__INCLUDED_)
