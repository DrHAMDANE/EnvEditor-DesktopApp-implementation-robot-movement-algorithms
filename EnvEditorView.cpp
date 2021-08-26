// EnvEditorView.cpp : implementation of the CEnvEditorView class
//

#include "stdafx.h"
#include "EnvEditor.h"

#include "EnvEditorDoc.h"
#include "EnvEditorView.h"
#include "Afxdb.h"
#include "rdcmax.h"
#include "rdcpointselect.h"
#include "EquDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnvEditorView

IMPLEMENT_DYNCREATE(CEnvEditorView, CView)

BEGIN_MESSAGE_MAP(CEnvEditorView, CView)
	//{{AFX_MSG_MAP(CEnvEditorView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_BUTTON_EO, OnButtonEo)
	ON_COMMAND(ID_BUTTON_FH, OnButtonFh)
	ON_COMMAND(ID_BUTTON_HB, OnButtonHb)
	ON_COMMAND(ID_BUTTON_RO, OnButtonRo)
	ON_COMMAND(ID_BUTTON_SEL, OnButtonSel)
	ON_COMMAND(ID_BUTTON_VB, OnButtonVb)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnvEditorView construction/destruction

CEnvEditorView::CEnvEditorView()
{
	// TODO: add construction code here
	env=new CRect();
	mType=SEL;
	
	IsAnItemSelected=false;
	IsDrawing=false;
	LBIsDown=false;

}

CEnvEditorView::~CEnvEditorView()
{
	delete env;	
	
	POSITION pos=itemList.GetHeadPosition();
	CItem* item;
	while(pos!=NULL)
	{
		item=itemList.GetNext(pos);
		delete item;
	}
}

BOOL CEnvEditorView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CEnvEditorView drawing

void CEnvEditorView::OnDraw(CDC* pDC)
{
	CEnvEditorDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	LPRECT rect=new RECT;
	static int i=0;
	CDC* dcEnv=new CDC();
	dcEnv->CreateCompatibleDC(pDC);
	CBitmap bmp;
	pDC->GetWindow()->GetClientRect(rect);	
	env->top=((rect->bottom-rect->top-pDoc->hi)/2)-1;
	env->bottom=env->top+pDoc->hi+1;
	env->left=((rect->right-rect->left-pDoc->wi)/2)-1;
	env->right=env->left+pDoc->wi+1;
	bmp.CreateCompatibleBitmap(pDC,rect->right ,rect->bottom );
	CBitmap* tempBmp=dcEnv->SelectObject(&bmp);
	dcEnv->FillSolidRect(rect,RGB(244,244,255));
	dcEnv->FillSolidRect(env,RGB(255,255,255));
	dcEnv->Rectangle(env);
	POSITION pos=itemList.GetTailPosition();
	CItem* item;
	while(pos!=NULL)
	{
		item=itemList.GetPrev(pos);
		if(item->isMoving)
		{
			if(item->iType==ROM)
				dcEnv->FillSolidRect(item->rect->left,item->rect->top,item->rect->Width(),item->rect->Height(),RGB(200,50,50));
			else
			{
				CRgn rg;
				rg.CreateEllipticRgn(item->rect->left,item->rect->top,item->rect->right,item->rect->bottom);
				CBrush br;
				br.CreateSolidBrush(RGB(255,0,0));
				dcEnv->FillRgn(&rg,&br);
				rg.DeleteObject();
				br.DeleteObject();
			}
		}
		else
		{
			if(item->iType==RO || item->iType==HB || item->iType==VB)
				dcEnv->FillSolidRect(item->rect->left,item->rect->top,item->rect->Width(),item->rect->Height(),RGB(0,0,0));
			else
			{
				if(item->iType==EO)
				{
					CRgn rg;
					rg.CreateEllipticRgn(item->rect->left,item->rect->top,item->rect->right,item->rect->bottom);
					CBrush br;
					br.CreateSolidBrush(RGB(0,0,0));
					dcEnv->FillRgn(&rg,&br);
					br.DeleteObject();
					rg.DeleteObject();
				}
				else
				{
					CPoint pt;
					POSITION _pos=item->pointList.GetHeadPosition();
					while(_pos)
					{
						pt=item->pointList.GetNext(_pos);
						dcEnv->SetPixelV(pt,RGB(0,0,0));
					}
				}
			}
		}
	}
	if(IsDrawing)
	{
		CBrush br;
		br.CreateStockObject(NULL_BRUSH);
		CBrush* tempbr=dcEnv->SelectObject(&br);
		CPen pen;
		pen.CreatePen(PS_DOT,1,RGB(0,0,0));
		CPen* pp=dcEnv->SelectObject(&pen);
		dcEnv->Rectangle(begin.x,begin.y,end.x,end.y);
		dcEnv->SelectObject(tempbr);
		dcEnv->SelectObject(pp);
		pen.DeleteObject();
		br.DeleteObject();
	}
	else
	{
		if(IsAnItemSelected)
		{
			pos=itemList.GetHeadPosition();
			while(pos!=NULL)
			{
				item=itemList.GetNext(pos);
				if(item->IsSelected)
				{
					if(item->isMoving)
					{
						CBrush br;
						br.CreateStockObject(NULL_BRUSH);
						CBrush* tbr=dcEnv->SelectObject(&br);
						CPen pen;
						pen.CreatePen(PS_SOLID,3,RGB(255,0,0));
						CPen* pp=dcEnv->SelectObject(&pen);
						dcEnv->Rectangle(item->rect->left-1,item->rect->top-1,item->rect->right+1,item->rect->bottom+1);
						dcEnv->SelectObject(pp);
						dcEnv->SelectObject(tbr);
					}
					else
					{
						CBrush br;
						br.CreateStockObject(NULL_BRUSH);
						CBrush* tbr=dcEnv->SelectObject(&br);
						CPen pen;
						pen.CreatePen(PS_SOLID,3,RGB(150,150,150));
						CPen* pp=dcEnv->SelectObject(&pen);
						dcEnv->Rectangle(item->rect->left-1,item->rect->top-1,item->rect->right+1,item->rect->bottom+1);
						dcEnv->SelectObject(pp);
						dcEnv->SelectObject(tbr);
					}
					break;
				}
			}
		}
	}
	
	
	
	pDC->BitBlt(0,0,rect->right ,rect->bottom ,dcEnv,0,0,SRCCOPY);
	delete rect;
	dcEnv->SelectObject(tempBmp);
	dcEnv->DeleteDC();
	delete dcEnv;
	bmp.DeleteObject();
}

/////////////////////////////////////////////////////////////////////////////
// CEnvEditorView printing

BOOL CEnvEditorView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEnvEditorView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEnvEditorView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CEnvEditorView diagnostics

#ifdef _DEBUG
void CEnvEditorView::AssertValid() const
{
	CView::AssertValid();
}

void CEnvEditorView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEnvEditorDoc* CEnvEditorView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEnvEditorDoc)));
	return (CEnvEditorDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CEnvEditorView message handlers

void CEnvEditorView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(env->PtInRect(point))
	{
		end=point;
		switch (mType)
		{
		case EO:
			{
				
			}break;
		case EOM:
			{
			}break;
		case FH:
			{
				if(IsDrawing)
				{
				CPoint pt=FHItem->pointList.GetTail();
				
				if(pt.x<point.x && point.x>FHItem->rect->right)
					FHItem->rect->right=point.x;
				if(pt.y<point.y && point.y>FHItem->rect->bottom)
					FHItem->rect->bottom=point.y;
				if(pt.x>point.x && point.x<FHItem->rect->left)
					FHItem->rect->left=point.x;
				if(pt.y>point.y)
					FHItem->rect->top=point.y;
							
				FHItem->pointList.AddTail(point);
				}
			}break;
		case HB:
			{
			}break;
		case RO:
			{
				
				
			}break;
		case ROM:
			{
				
				InvalidateRect(CRect(begin,end),false);
			}break;
		case VB:
			{
			}break;
		case SEL:
			{
			/*	if(IsAnItemSelected)
				{
					POSITION pos=itemList.GetHeadPosition();
						while (pos!=NULL)
						{
							item=itemList.GetNext(pos);
							if(item->IsSelected)
								break;
						}
					if(!LBIsDown)
					{
						
						if(point.x<item->rect->right-1)
						{
							if(point.x>item->rect->left+1)
							{
								if(point.y<item->rect->top+1 && point.y>item->rect->top-3)
								{
									::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_SIZENS));
									chTop=true;									
								}
								else
								{
									if(point.y>item->rect->bottom-1 && point.y<item->rect->bottom+3)
									{
										::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_SIZENS));
										chBottom=true;
									}
								}
							}
							else
							{
								if(point.x>item->rect->left-3 && point.y<item->rect->bottom-1 && point.y>item->rect->top+1)
								{
									::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_SIZEWE));
									chLeft=true;
								}
							}
						}
						else
						{
							if(point.x<item->rect->right+3 && point.y<item->rect->bottom-1 && point.y>item->rect->top+1)
							{
								::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_SIZEWE));
								chRight=true;
							}
						}
					}
					else
					{
						if(chTop)
						{
							item->rect->top=point;
						}
						if(chBottom)
						{
							item->rect->bottom=point;
						}
						if(chLeft)
						{
							item->rect->left=point;
						}
						if(chRight)
						{
							item->rect->right=point;
						}
					}
				}*/
			}break;
			InvalidateRect(env,false);
		}
		
	}
	CView::OnMouseMove(nFlags, point);
}

void CEnvEditorView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	LBIsDown=false;
	if(env->PtInRect(point))
	{
	
		
		switch (mType)
		{
		case EO:
			{
				if(IsDrawing)
				{
				CItem* item=new CItem();
				item->isMoving=false;
				item->iType=EO;
				item->rect->top=begin.y;
				item->rect->left=begin.x;
				item->rect->bottom=point.y;
				item->rect->right=point.x;
				item->IsSelected=true;
				item->rect->NormalizeRect();
				itemList.AddHead(item);
				IsAnItemSelected=false;
				::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_ARROW));
				}
			}break;
		case EOM:
			{
				if(IsDrawing)
				{
				CEquDlg dlg;
				if(dlg.DoModal()==IDOK)
				{
					CItem* item=new CItem();
					item->isMoving=true;
					item->rect->top=begin.y;				
					item->rect->left=begin.x;
					item->rect->bottom=point.y;
					item->rect->right=point.x;
					item->iType=EOM;
					if(dlg.type)
						item->eq.type=RANDOM;
					else
					{
						item->eq.type=LINEAR;
						item->eq.param1=dlg.AX;
						item->eq.param2=dlg.BX;
						item->eq.param3=dlg.AY;
						item->eq.param4=dlg.BY;
						item->eq.param5=dlg.Period;
					}
					item->IsSelected=true;
					item->rect->NormalizeRect();
					itemList.AddHead(item);
					IsAnItemSelected=false;
				}
				::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_ARROW));
				}
			}break;
		case FH:
			{
				if(IsDrawing)
				{
				CPoint pt=FHItem->pointList.GetTail();
				
				if(pt.x<point.x && point.x>FHItem->rect->right)
					FHItem->rect->right=point.x;
				if(pt.y<point.y && point.y>FHItem->rect->bottom)
					FHItem->rect->bottom=point.y;
				if(pt.x>point.x && point.x<FHItem->rect->left)
					FHItem->rect->left=point.x;
				if(pt.y>point.y)
					FHItem->rect->top=point.y;
							
				FHItem->pointList.AddTail(point);
				itemList.AddHead(FHItem);
				::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_ARROW));
				}
			}break;
		case HB:
			{
				if(IsDrawing)
				{
				CItem* item=new CItem();
				item->isMoving=false;
				item->iType=HB;
				item->rect->top=begin.y;
				item->rect->left=begin.x;
				item->rect->bottom=begin.y+3;
				item->rect->right=point.x;
				item->IsSelected=true;
				item->rect->NormalizeRect();
				itemList.AddHead(item);
				IsAnItemSelected=false;
				::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_ARROW));
				}
			}break;
		case RO:
			{
				if(IsDrawing)
				{
				CItem* item=new CItem();
				item->isMoving=false;
				item->rect->top=begin.y;
				item->rect->left=begin.x;
				item->rect->bottom=point.y;
				item->rect->right=point.x;
				item->iType=RO;
				item->IsSelected=true;
				item->rect->NormalizeRect();
				itemList.AddHead(item);
				IsAnItemSelected=false;
				::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_ARROW));
				}
			}break;
		case ROM:
			{
				if(IsDrawing)
				{
				CEquDlg dlg;
				if(dlg.DoModal()==IDOK)
				{
					CItem* item=new CItem();
					item->isMoving=true;
					item->rect->top=begin.y;				
					item->rect->left=begin.x;
					item->rect->bottom=point.y;
					item->rect->right=point.x;
					item->iType=ROM;
					if(dlg.type)
						item->eq.type=RANDOM;
					else
					{
						item->eq.type=LINEAR;
						item->eq.param1=dlg.AX;
						item->eq.param2=dlg.BX;
						item->eq.param3=dlg.AY;
						item->eq.param4=dlg.BY;
						item->eq.param5=dlg.Period;
					}
					item->IsSelected=true;
					item->rect->NormalizeRect();
					itemList.AddHead(item);
					IsAnItemSelected=false;
				}
				::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_ARROW));
				}
			}break;
		case VB:
			{
				if(IsDrawing)
				{
				CItem* item=new CItem();
				item->isMoving=false;
				item->iType=VB;
				item->rect->top=begin.y;
				item->rect->left=begin.x;
				item->rect->bottom=point.y;
				item->rect->right=begin.x+3;
				item->IsSelected=true;
				item->rect->NormalizeRect();
				itemList.AddHead(item);
				IsAnItemSelected=false;
				::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_ARROW));
				}
			}break;
		case SEL:
			{
				if(itemList.GetCount())
				{
				CItem* item;
				int xDiff,yDiff;
				POSITION pos=itemList.GetHeadPosition();
				while(pos!=NULL)
				{
					item=itemList.GetNext(pos);
					if(item->IsSelected)
						break;
				}
				xDiff=point.x-begin.x;
				yDiff=point.y-begin.y;

				item->rect->top+=yDiff;
				item->rect->left+=xDiff;
				item->rect->right+=xDiff;
				item->rect->bottom+=yDiff;

				::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_ARROW));
				}
			}break;
		}
	IsDrawing=false;
		InvalidateRect(env,false);
	}
	else
	{
		if(mType==FH)
		{
			if(IsDrawing)
				delete FHItem;
		}
	}
	CView::OnLButtonUp(nFlags, point);
}

void CEnvEditorView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	if(env->PtInRect(point))
	{
		LBIsDown=true;
		begin=point;
		switch( mType)
		{
		case SEL:
			{
/*				if(chTop)
				{
					goto Section;
				}
				if(chBottom)
				{
					goto Section;
				}
				if(chLeft)
				{
					goto Section;
				}
				if(chRight)
				{
					goto Section;
				}*/
				CItem* item;
				IsAnItemSelected=false;
				POSITION pos=itemList.GetHeadPosition();
				while(pos!=NULL)
				{
					item=itemList.GetNext(pos);
					if(item->IsSelected)
						item->IsSelected=false;
					if(item->rect->PtInRect(point))
					{
						item->IsSelected=true;
						IsAnItemSelected=true;
						break;
					}
				}
				if(!IsAnItemSelected)
				{
					pos=itemList.GetHeadPosition();
					while(pos!=NULL)
					{
						item=itemList.GetNext(pos);
						item->IsSelected=false;
					}
				}
				::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_SIZEALL));
//Section:
			}break;
		case EO:
			{
				::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_CROSS));
				IsDrawing=true;
			}break;
		case EOM:
			{
				::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_CROSS));
				IsDrawing=true;
			}break;
		case FH:
			{
				FHItem=new CItem();
				FHItem->iType=FH;
				FHItem->pointList.AddHead(point);
				FHItem->isMoving=false;
				FHItem->IsSelected=false;
				FHItem->rect->left=point.x;
				FHItem->rect->top=point.y;
				FHItem->rect->right=point.x+1;
				FHItem->rect->bottom=point.y+1;				

				SetCursor(LoadCursor(AfxGetInstanceHandle(),IDC_CROSS));
				IsDrawing=true;
			}break;
		case HB:
			{
				::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_CROSS));
				IsDrawing=true;
			}break;
		case RO:
			{
				::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_CROSS));
				IsDrawing=true;
			}break;
		case ROM:
			{
				::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_CROSS));
				IsDrawing=true;
			}break;
		case VB:
			{
				::SetCursor(::LoadCursor(::AfxGetInstanceHandle(),IDC_CROSS));
				IsDrawing=true;
			}break;
		}
		
		InvalidateRect(env,false);
	}
	CView::OnLButtonDown(nFlags, point);
}

void CEnvEditorView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnRButtonDown(nFlags, point);
}

void CEnvEditorView::OnFileSave() 
{
	// TODO: Add your command handler code here
	CRdcMax *rdc=new CRdcMax();
	rdc->Open();
	CString strEnv;
	int i=1;
	while(!rdc->IsEOF())
	{
		rdc->MoveNext();
		i++;
	}
	strEnv.Format("%d",i);
	rdc->Close();
	delete rdc;
	CEnvEditorDoc* pDoc=GetDocument(); 
	CString strHi,strWi,strObsMoving;
	strHi.Format("%d",pDoc->hi);
	strWi.Format("%d",pDoc->wi);
	if(pDoc->ObsMoving==TRUE)
		strObsMoving="true";
	else
		strObsMoving="false";
	CDatabase *db=new CDatabase();
	db->OpenEx(_T("DSN=DB_STAT_PROJECT"),0);
	db->ExecuteSQL("insert into tenv(nenv,title,wi,hi,obsmoving) values ("+strEnv+",'Env Number "+strEnv+"',"+strWi+","+strHi+","+strObsMoving+")");

	CItem* item;
	CString x,y,eqtype,p1,p2,p3,p4,p5,strType;
	if(strObsMoving=="true")
	{
		POSITION pos=itemList.GetHeadPosition();
		while(pos!=NULL)
		{
			item=itemList.GetNext(pos);
			if(item->isMoving)
			{
				x.Format("%d",item->rect->left-env->left-1);
				y.Format("%d",item->rect->top-env->top-1);
				strWi.Format("%d",item->rect->Width());
				strHi.Format("%d",item->rect->Height());
				strType.Format("%d",item->iType);
				if(item->eq.type ==RANDOM)
				{
					eqtype="0";
					p1="0";
					p2="0";
					p3="0";
					p4="0";
					p5="0";
				}
				else
				{
					eqtype="1";
					p1.Format("%d",item->eq.param1);
					p2.Format("%d",item->eq.param2);
					p3.Format("%d",item->eq.param3);
					p4.Format("%d",item->eq.param4);
					p5.Format("%d",item->eq.param5);
				}
				db->ExecuteSQL("insert into tenvdynamicitem(x,y,wi,hi,nEnv,eqtype,p1,p2,p3,p4,p5,itype) values ("+x+","+y+","+strWi+","+strHi+","+strEnv+","+eqtype+","+p1+","+p2+","+p3+","+p4+","+p5+","+strType+")");
			}
			else
			{
				if(item->iType!=FH)
				{
				x.Format("%d",item->rect->left-env->left-1);
				y.Format("%d",item->rect->top-env->top-1);
				strWi.Format("%d",item->rect->Width());
				strHi.Format("%d",item->rect->Height());
				strType.Format("%d",item->iType);
				db->ExecuteSQL("insert into tenvstaticitem(x,y,wi,hi,nEnv,iType) values ("+x+","+y+","+strWi+","+strHi+","+strEnv+","+strType+")");
				}
			}
		}
	}
	else
	{
		POSITION pos=itemList.GetHeadPosition();
		while(pos!=NULL)
		{
			item=itemList.GetNext(pos);
			if(item->iType!=FH)
			{
				x.Format("%d",item->rect->left-env->left-1);
				y.Format("%d",item->rect->top-env->top-1);
				strWi.Format("%d",item->rect->Width());
				strHi.Format("%d",item->rect->Height());
				strType.Format("%d",item->iType);
				db->ExecuteSQL("insert into tenvstaticitem(x,y,wi,hi,nEnv,iType) values ("+x+","+y+","+strWi+","+strHi+","+strEnv+","+strType+")");
			}
		}
	}
	db->Close();
	delete db;
}

void CEnvEditorView::OnButtonEo() 
{
	// TODO: Add your command handler code here
//	Insert(CItem(EO));
	mType=EO;
}



void CEnvEditorView::OnButtonFh() 
{
	// TODO: Add your command handler code here
	mType=FH;
}

void CEnvEditorView::OnButtonHb() 
{
	// TODO: Add your command handler code here
//	Insert(CItem(HB));
	mType=HB;
}

void CEnvEditorView::OnButtonRo() 
{
	// TODO: Add your command handler code here
//	Insert(CItem(RO));
	mType=RO;
}



void CEnvEditorView::OnButtonSel() 
{
	// TODO: Add your command handler code here
	mType=SEL;
}

void CEnvEditorView::OnButtonVb() 
{
	// TODO: Add your command handler code here
//	Insert(CItem(VB));
	mType=VB;
}

