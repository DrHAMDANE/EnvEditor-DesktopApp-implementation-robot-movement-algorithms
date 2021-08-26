// RecordsetEnv.cpp : implementation file
//

#include "stdafx.h"
#include "EnvEditor.h"
#include "RecordsetEnv.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecordsetEnv

IMPLEMENT_DYNAMIC(CRecordsetEnv, CRecordset)

CRecordsetEnv::CRecordsetEnv(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CRecordsetEnv)
	m_nEnv = 0;
	m_Title = _T("");
	m_wi = 0;
	m_hi = 0;
	m_obsMoving = FALSE;
	m_x = 0;
	m_y = 0;
	m_IsLocked = FALSE;
	m_nEnvPointList = 0;
	m_nFields = 9;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CRecordsetEnv::GetDefaultConnect()
{
	return _T("ODBC;DSN=DB_STAT_PROJECT");
}

CString CRecordsetEnv::GetDefaultSQL()
{
	return _T("[TEnv],[TEnvPointList]");
}

void CRecordsetEnv::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CRecordsetEnv)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[TEnv].[nEnv]"), m_nEnv);
	RFX_Text(pFX, _T("[Title]"), m_Title);
	RFX_Long(pFX, _T("[wi]"), m_wi);
	RFX_Long(pFX, _T("[hi]"), m_hi);
	RFX_Bool(pFX, _T("[obsMoving]"), m_obsMoving);
	RFX_Long(pFX, _T("[x]"), m_x);
	RFX_Long(pFX, _T("[y]"), m_y);
	RFX_Bool(pFX, _T("[IsLocked]"), m_IsLocked);
	RFX_Long(pFX, _T("[TEnvPointList].[nEnv]"), m_nEnvPointList);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRecordsetEnv diagnostics

#ifdef _DEBUG
void CRecordsetEnv::AssertValid() const
{
	CRecordset::AssertValid();
}

void CRecordsetEnv::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
