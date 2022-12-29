#include "stdafx.h"
#include "LocalShape.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CLocalShape::CLocalShape()
{
	cout << "생성자 CLocalShape() 호출" << endl;
}
CLocalShape::CLocalShape(const CLocalShape& src)
{
	*this = src;
}
CLocalShape::~CLocalShape()
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	cout << "소멸자 ~CLocalShape() 호출" << endl;
}
void CLocalShape::vSetLocalshape(int dArtwork, int dLayerNumber, CDrawObjArray aDrawObj)
{
	m_nArtwork = dArtwork;
	m_nLayerNumber = dLayerNumber;

	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();
	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = aDrawObj.GetAt(i);
		m_aDrawObj.Add(pItem->clone());
		delete pItem;
	}
}
CLocalShape& CLocalShape::operator =(const CLocalShape& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_nArtwork = rhs.m_nArtwork;
	this->m_nLayerNumber = rhs.m_nLayerNumber;

	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	for (int i = 0; i < rhs.m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = rhs.m_aDrawObj.GetAt(i);
		m_aDrawObj.Add(pItem->clone());
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CLocalShape::operator==(const CLocalShape & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CLocalShape::operator!=(const CLocalShape& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLocalShape* CLocalShape::clone()
{
	return new CLocalShape(*this);

}
// const int CLocalShape::m_nVersion = 1;