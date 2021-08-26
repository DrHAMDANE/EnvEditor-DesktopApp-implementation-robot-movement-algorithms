// Equation.h: interface for the CEquation class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EQUATION_H__42AAF0FB_716B_4920_95D4_EC32D31EFCB0__INCLUDED_)
#define AFX_EQUATION_H__42AAF0FB_716B_4920_95D4_EC32D31EFCB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
typedef enum{SINOISIDAL,LINEAR,CIRCLIC,RANDOM} EQ_TYPE;
class CEquation  
{
public:
	int param1;
	int param2;
	int param3;
	int param4;
	int param5;
	EQ_TYPE type;
	CEquation();
	virtual ~CEquation();

};

#endif // !defined(AFX_EQUATION_H__42AAF0FB_716B_4920_95D4_EC32D31EFCB0__INCLUDED_)
