#if !defined(AFX_RDCPOINTSELECT_H__3C2C8EA9_0AB9_46F2_B732_981000E92773__INCLUDED_)
#define AFX_RDCPOINTSELECT_H__3C2C8EA9_0AB9_46F2_B732_981000E92773__INCLUDED_
#include "afxdb.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RdcPointSelect.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRdcPointSelect recordset

class CRdcPointSelect : public CRecordset
{
public:
	CRdcPointSelect(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRdcPointSelect)

// Field/Param Data
	//{{AFX_FIELD(CRdcPointSelect, CRecordset)
	long	nEnv;
	int		X;
	int		Y;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRdcPointSelect)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RDCPOINTSELECT_H__3C2C8EA9_0AB9_46F2_B732_981000E92773__INCLUDED_)
