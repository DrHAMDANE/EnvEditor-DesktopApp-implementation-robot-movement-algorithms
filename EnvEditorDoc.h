// EnvEditorDoc.h : interface of the CEnvEditorDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENVEDITORDOC_H__F088AE84_E254_498B_B512_BD5CABE10682__INCLUDED_)
#define AFX_ENVEDITORDOC_H__F088AE84_E254_498B_B512_BD5CABE10682__INCLUDED_
#include "item.h"
#include "afxtempl.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CEnvEditorDoc : public CDocument
{
protected: // create from serialization only
	CEnvEditorDoc();
	DECLARE_DYNCREATE(CEnvEditorDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnvEditorDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL ObsMoving;
	
	int wi;
	int hi;
	virtual ~CEnvEditorDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEnvEditorDoc)
	afx_msg void OnFileNew();
	afx_msg void OnButtonEo();
	afx_msg void OnButtonFh();
	afx_msg void OnButtonHb();
	afx_msg void OnButtonRo();
	afx_msg void OnButtonSel();
	afx_msg void OnButtonVb();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENVEDITORDOC_H__F088AE84_E254_498B_B512_BD5CABE10682__INCLUDED_)
