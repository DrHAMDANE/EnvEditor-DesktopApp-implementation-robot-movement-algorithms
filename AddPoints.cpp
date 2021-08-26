// AddPoints.cpp : implementation file
//

#include "stdafx.h"
#include "EnvEditor.h"
#include "AddPoints.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAddPoints

IMPLEMENT_DYNAMIC(CAddPoints, CRecordset)

CAddPoints::CAddPoints(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAddPoints)
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CAddPoints::GetDefaultConnect()
{
	return _T("ODBC;DSN=DB_STAT_PROJECT");
}

CString CAddPoints::GetDefaultSQL()
{
	return _T("");
}

void CAddPoints::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAddPoints)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAddPoints diagnostics

#ifdef _DEBUG
void CAddPoints::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAddPoints::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
