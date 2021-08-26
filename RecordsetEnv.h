#if !defined(AFX_RECORDSETENV_H__D08D8E10_3A42_4E61_8EA5_DE1F36197972__INCLUDED_)
#define AFX_RECORDSETENV_H__D08D8E10_3A42_4E61_8EA5_DE1F36197972__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RecordsetEnv.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRecordsetEnv recordset

class CRecordsetEnv : public CRecordset
{
public:
	CRecordsetEnv(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CRecordsetEnv)

// Field/Param Data
	//{{AFX_FIELD(CRecordsetEnv, CRecordset)
	long	m_nEnv;
	CString	m_Title;
	long	m_wi;
	long	m_hi;
	BOOL	m_obsMoving;
	long	m_x;
	long	m_y;
	BOOL	m_IsLocked;
	long	m_nEnvPointList;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecordsetEnv)
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

#endif // !defined(AFX_RECORDSETENV_H__D08D8E10_3A42_4E61_8EA5_DE1F36197972__INCLUDED_)
