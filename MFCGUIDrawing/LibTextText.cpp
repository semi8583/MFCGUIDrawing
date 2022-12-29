#include "stdafx.h"
#include "LibTextText.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CLibTextText::CLibTextText()
{
	cout << "생성자 CLibTextText() 호출" << endl;
}
CLibTextText::CLibTextText(const CLibTextText& src)
{
	*this = src;
}
CLibTextText::~CLibTextText()
{
	cout << "소멸자 ~CLibTextText() 호출" << endl;
}
void CLibTextText::vSetCLibTextText(int nLibTextNo, string sFontName, string sFontType, double dTextHeight, double dTextWidth, double dTextSpace
	, double dTextLineSpace, double dTextThickness, int nECADFontID)
{
	m_nLibTextNo = nLibTextNo;
	m_sFontName = sFontName;
	m_sFontType = sFontType;
	m_dTextHeight = dTextHeight;
	m_dTextWidth = dTextWidth;
	m_dTextSpace = dTextSpace;
	m_dTextLineSpace = dTextLineSpace;
	m_dTextThickness = dTextThickness;
	m_nEcadFontID = nECADFontID;
}
CLibTextText& CLibTextText::operator =(const CLibTextText& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_nLibTextNo = rhs.m_nLibTextNo;
	this->m_sFontName = rhs.m_sFontName;
	this->m_sFontType = rhs.m_sFontType;
	this->m_dTextHeight = rhs.m_dTextHeight;
	this->m_dTextWidth = rhs.m_dTextWidth;
	this->m_dTextSpace = rhs.m_dTextSpace;
	this->m_dTextLineSpace = rhs.m_dTextLineSpace;
	this->m_dTextThickness = rhs.m_dTextThickness;
	this->m_nEcadFontID = rhs.m_nEcadFontID;
	// Add code to serialize member variable
	return *this;
}


BOOL CLibTextText::operator==(const CLibTextText & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CLibTextText::operator!=(const CLibTextText& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLibTextText* CLibTextText::clone()
{
	return new CLibTextText(*this);

}
//const int CLibTextText::m_nVersion = 1;

CLibTextTextArray::CLibTextTextArray()
{
}
CLibTextTextArray::CLibTextTextArray(const CLibTextTextArray& src)
{
	*this = src;
}
CLibTextTextArray::~CLibTextTextArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CLibTextText * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CLibTextTextArray& CLibTextTextArray::operator =(const CLibTextTextArray& rhs)
{
	if (this == &rhs)
		return *this;
	for (int i = 0; i < GetSize(); i++)
	{
		CLibTextText * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CLibTextText* pItem = new CLibTextText();
		pItem->m_dTextHeight = rhs.GetAt(i)->m_dTextHeight;
		pItem->m_dTextLineSpace = rhs.GetAt(i)->m_dTextLineSpace;
		pItem->m_dTextSpace = rhs.GetAt(i)->m_dTextSpace;
		pItem->m_dTextThickness = rhs.GetAt(i)->m_dTextThickness;
		pItem->m_dTextWidth = rhs.GetAt(i)->m_dTextWidth;
		pItem->m_nEcadFontID = rhs.GetAt(i)->m_nEcadFontID;
		pItem->m_nLibTextNo = rhs.GetAt(i)->m_nLibTextNo;
		pItem->m_sFontName = rhs.GetAt(i)->m_sFontName;
		pItem->m_sFontType = rhs.GetAt(i)->m_sFontType;
		this->Add(pItem->clone());
	}

	return *this;
}

bool CLibTextTextArray::operator==(const CLibTextTextArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CLibTextText* pItem1;
	CLibTextText* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CLibTextTextArray::operator!=(const CLibTextTextArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLibTextTextArray* CLibTextTextArray::clone()
{
	return new CLibTextTextArray(*this);

}