#if !defined(AFX_RDCMAX_H__BBA9BF41_D73A_489A_BBAD_7A24F83DDAC9__INCLUDED_)
#define AFX_RDCMAX_H__BBA9BF41_D73A_489A_BBAD_7A24F83DDAC9__INCLUDED_
#include "afxdb.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RdcMax.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRdcMax recordset

class CRdcMax : public CRecordset
{
public:
	CRdcMax(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRdcMax)

// Field/Param Data
	//{{AFX_FIELD(CRdcMax, CRecordset)
	long	max;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRdcMax)
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

#endif // !defined(AFX_RDCMAX_H__BBA9BF41_D73A_489A_BBAD_7A24F83DDAC9__INCLUDED_)
