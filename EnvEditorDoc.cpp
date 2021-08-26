// EnvEditorDoc.cpp : implementation of the CEnvEditorDoc class
//

#include "stdafx.h"
#include "EnvEditor.h"

#include "EnvEditorDoc.h"
#include "ask.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnvEditorDoc

IMPLEMENT_DYNCREATE(CEnvEditorDoc, CDocument)

BEGIN_MESSAGE_MAP(CEnvEditorDoc, CDocument)
	//{{AFX_MSG_MAP(CEnvEditorDoc)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_BUTTON_EO, OnButtonEo)
	ON_COMMAND(ID_BUTTON_FH, OnButtonFh)
	ON_COMMAND(ID_BUTTON_HB, OnButtonHb)
	ON_COMMAND(ID_BUTTON_RO, OnButtonRo)
	ON_COMMAND(ID_BUTTON_SEL, OnButtonSel)
	ON_COMMAND(ID_BUTTON_VB, OnButtonVb)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnvEditorDoc construction/destruction

CEnvEditorDoc::CEnvEditorDoc()
{
	// TODO: add one-time construction code here

}

CEnvEditorDoc::~CEnvEditorDoc()
{
}

BOOL CEnvEditorDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	CAsk dlg;
	if(dlg.DoModal()==IDOK)
	{
		hi=dlg.m_HI;
		wi=dlg.m_WI;
		ObsMoving=dlg.m_OM;
	}
	else
	{
		hi=100;
		wi=100;
		ObsMoving=false;
	}
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CEnvEditorDoc serialization

void CEnvEditorDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CEnvEditorDoc diagnostics

#ifdef _DEBUG
void CEnvEditorDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEnvEditorDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEnvEditorDoc commands

void CEnvEditorDoc::OnFileNew() 
{
	// TODO: Add your command handler code here

}

void CEnvEditorDoc::OnButtonEo() 
{
	// TODO: Add your command handler code here
	
}

//DEL void CEnvEditorDoc::OnButtonEom() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

void CEnvEditorDoc::OnButtonFh() 
{
	// TODO: Add your command handler code here
	
}

void CEnvEditorDoc::OnButtonHb() 
{
	// TODO: Add your command handler code here
	
}

void CEnvEditorDoc::OnButtonRo() 
{
	// TODO: Add your command handler code here
	
}

//DEL void CEnvEditorDoc::OnButtonRom() 
//DEL {
//DEL 	// TODO: Add your command handler code here
//DEL 	
//DEL }

void CEnvEditorDoc::OnButtonSel() 
{
	// TODO: Add your command handler code here
	
}

void CEnvEditorDoc::OnButtonVb() 
{
	// TODO: Add your command handler code here
	
}
