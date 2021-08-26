// Item.h: interface for the CItem class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ITEM_H__7D4A451D_2DE4_4E2C_8A98_53643BDA65B7__INCLUDED_)
#define AFX_ITEM_H__7D4A451D_2DE4_4E2C_8A98_53643BDA65B7__INCLUDED_
#include "afxtempl.h"
#include "Equation.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CItem  
{
public:
	CList<CPoint,CPoint> pointList;
	int iType;
	bool IsSelected;
	CEquation eq;
	bool isMoving;
	CRect *rect;
	CItem();
	virtual ~CItem();

};

#endif // !defined(AFX_ITEM_H__7D4A451D_2DE4_4E2C_8A98_53643BDA65B7__INCLUDED_)
