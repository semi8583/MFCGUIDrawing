#include "stdafx.h"
#include "FigureDefinition.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CFigureDefinition::CFigureDefinition()
{
	cout << "생성자 CFigureDefinition() 호출" << endl;
}
CFigureDefinition::CFigureDefinition(const CFigureDefinition& src)
{
	*this = src;
}
CFigureDefinition::~CFigureDefinition()
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();
	cout << "소멸자 ~CFigureDefinition() 호출" << endl;
}
void CFigureDefinition::vSetFigure(CDrawObjArray aDrawObj)
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CDrawObj* pItem = new CDrawObj();
		pItem = aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());
		delete pItem;
	}

}
CFigureDefinition& CFigureDefinition::operator =(const CFigureDefinition& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	for (int i = 0; i < rhs.m_aDrawObj.GetSize(); i++) 
	{
		CDrawObj* pItem = rhs.m_aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CFigureDefinition::operator==(const CFigureDefinition & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CFigureDefinition::operator!=(const CFigureDefinition& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CFigureDefinition* CFigureDefinition::clone()
{
	return new CFigureDefinition(*this);

}
//const int CFigureDefinition::m_nVersion = 1;