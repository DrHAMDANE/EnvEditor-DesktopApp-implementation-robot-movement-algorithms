// RdcPointSelect.cpp : implementation file
//

#include "stdafx.h"
#include "EnvEditor.h"
#include "RdcPointSelect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRdcPointSelect

IMPLEMENT_DYNAMIC(CRdcPointSelect, CRecordset)

CRdcPointSelect::CRdcPointSelect(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRdcPointSelect)
	nEnv = 0;
	X = 0;
	Y = 0;
	m_nFields = 3;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CRdcPointSelect::GetDefaultConnect()
{
	return _T("ODBC;DSN=DB_STAT_PROJECT");
}

CString CRdcPointSelect::GetDefaultSQL()
{
	return _T("[TEnvPointList]");
}

void CRdcPointSelect::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRdcPointSelect)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[nEnv]"), nEnv);
	RFX_Int(pFX, _T("[x]"), X);
	RFX_Int(pFX, _T("[y]"), Y);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRdcPointSelect diagnostics

#ifdef _DEBUG
void CRdcPointSelect::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRdcPointSelect::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
