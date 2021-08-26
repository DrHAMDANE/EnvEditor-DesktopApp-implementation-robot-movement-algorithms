// RdcMax.cpp : implementation file
//

#include "stdafx.h"
#include "EnvEditor.h"
#include "RdcMax.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRdcMax

IMPLEMENT_DYNAMIC(CRdcMax, CRecordset)

CRdcMax::CRdcMax(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRdcMax)
	max = 0;
	m_nFields = 1;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}


CString CRdcMax::GetDefaultConnect()
{
	return _T("ODBC;DSN=DB_STAT_PROJECT");
}

CString CRdcMax::GetDefaultSQL()
{
	return _T("[TEnv]");
}

void CRdcMax::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRdcMax)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[nEnv]"), max);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRdcMax diagnostics

#ifdef _DEBUG
void CRdcMax::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRdcMax::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
