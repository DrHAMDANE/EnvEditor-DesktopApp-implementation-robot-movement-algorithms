#if !defined(AFX_ADDPOINTS_H__77BC8C08_2F9E_4A34_A7E2_4CA9DBCB1467__INCLUDED_)
#define AFX_ADDPOINTS_H__77BC8C08_2F9E_4A34_A7E2_4CA9DBCB1467__INCLUDED_
#include "afxdb.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddPoints.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAddPoints recordset

class CAddPoints : public CRecordset
{
public:
	CAddPoints(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAddPoints)

// Field/Param Data
	//{{AFX_FIELD(CAddPoints, CRecordset)
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddPoints)
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

#endif // !defined(AFX_ADDPOINTS_H__77BC8C08_2F9E_4A34_A7E2_4CA9DBCB1467__INCLUDED_)
