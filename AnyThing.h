#if !defined(AFX_ANYTHING_H__4C0E4B22_A51D_40EE_BFE3_CE3CA8A581AE__INCLUDED_)
#define AFX_ANYTHING_H__4C0E4B22_A51D_40EE_BFE3_CE3CA8A581AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AnyThing.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAnyThing recordset

class CAnyThing : public CRecordset
{
public:
	CAnyThing(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAnyThing)

// Field/Param Data
	//{{AFX_FIELD(CAnyThing, CRecordset)
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnyThing)
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

#endif // !defined(AFX_ANYTHING_H__4C0E4B22_A51D_40EE_BFE3_CE3CA8A581AE__INCLUDED_)
