// Ask.cpp : implementation file
//

#include "stdafx.h"
#include "EnvEditor.h"
#include "Ask.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAsk dialog


CAsk::CAsk(CWnd* pParent /*=NULL*/)
	: CDialog(CAsk::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAsk)
	m_OM = FALSE;
	m_HI = 0;
	m_WI = 0;
	//}}AFX_DATA_INIT
}


void CAsk::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAsk)
	DDX_Check(pDX, IDC_CHECK_OM, m_OM);
	DDX_Text(pDX, IDC_EDIT_HI, m_HI);
	DDV_MinMaxUInt(pDX, m_HI, 100, 700);
	DDX_Text(pDX, IDC_EDIT_WI, m_WI);
	DDV_MinMaxUInt(pDX, m_WI, 100, 800);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAsk, CDialog)
	//{{AFX_MSG_MAP(CAsk)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAsk message handlers
