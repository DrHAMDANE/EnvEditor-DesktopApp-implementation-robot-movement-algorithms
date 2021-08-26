// AnyThing.cpp : implementation file
//

#include "stdafx.h"
#include "EnvEditor.h"
#include "AnyThing.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAnyThing

IMPLEMENT_DYNAMIC(CAnyThing, CRecordset)

CAnyThing::CAnyThing(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAnyThing)
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CAnyThing::GetDefaultConnect()
{
	return _T("ODBC;DSN=C:\My Documents\Statistics.mdb");
}

CString CAnyThing::GetDefaultSQL()
{
	return _T("");
}

void CAnyThing::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAnyThing)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAnyThing diagnostics

#ifdef _DEBUG
void CAnyThing::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAnyThing::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
