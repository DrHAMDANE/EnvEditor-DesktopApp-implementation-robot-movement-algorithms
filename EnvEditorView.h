// EnvEditorView.h : interface of the CEnvEditorView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ENVEDITORVIEW_H__7C27A699_8449_4D50_9EEF_43D3B9DAF0AB__INCLUDED_)
#define AFX_ENVEDITORVIEW_H__7C27A699_8449_4D50_9EEF_43D3B9DAF0AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define EO 1
#define EOM 2
#define FH  3
#define HB 4
#define VB 5
#define RO 6
#define ROM 7
#define SEL 8
class CEnvEditorView : public CView
{
protected: // create from serialization only
	CEnvEditorView();
	DECLARE_DYNCREATE(CEnvEditorView)

// Attributes
public:
	CEnvEditorDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnvEditorView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	CItem* FHItem;
	bool IsAnItemSelected;
	CList<CItem*,CItem*> itemList;
	CPoint begin;
	bool IsDrawing;
	bool LBIsDown;
	CPoint end;
	

	
	CRect* env;
	virtual ~CEnvEditorView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CEnvEditorView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnFileSave();
	afx_msg void OnButtonEo();
	afx_msg void OnButtonFh();
	afx_msg void OnButtonHb();
	afx_msg void OnButtonRo();
	afx_msg void OnButtonSel();
	afx_msg void OnButtonVb();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int mType;
};

#ifndef _DEBUG  // debug version in EnvEditorView.cpp
inline CEnvEditorDoc* CEnvEditorView::GetDocument()
   { return (CEnvEditorDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENVEDITORVIEW_H__7C27A699_8449_4D50_9EEF_43D3B9DAF0AB__INCLUDED_)
