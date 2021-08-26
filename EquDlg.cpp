// EquDlg.cpp : implementation file
//

#include "stdafx.h"
#include "EnvEditor.h"
#include "EquDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEquDlg dialog


CEquDlg::CEquDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CEquDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CEquDlg)
	AX = 0;
	AY = 0;
	BX = 0;
	BY = 0;
	Period = 0;
	//}}AFX_DATA_INIT
}


void CEquDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CEquDlg)
	DDX_Control(pDX, IDC_RADIO3, mRadio2);
	DDX_Control(pDX, IDC_RADIO1, mRadio1);
	DDX_Text(pDX, IDC_EDIT_AX, AX);
	DDX_Text(pDX, IDC_EDIT_AY, AY);
	DDX_Text(pDX, IDC_EDIT_BX, BX);
	DDX_Text(pDX, IDC_EDIT_BY, BY);
	DDX_Text(pDX, IDC_EDIT_PERIOD, Period);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CEquDlg, CDialog)
	//{{AFX_MSG_MAP(CEquDlg)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEquDlg message handlers

BOOL CEquDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	this->CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO1);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CEquDlg::OnRadio3() 
{
	// TODO: Add your control notification handler code here
	this->CheckRadioButton(IDC_RADIO1,IDC_RADIO2,IDC_RADIO2);
	type=0;
}

void CEquDlg::OnRadio1() 
{
	// TODO: Add your control notification handler code here
	type=1;
}
