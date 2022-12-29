#include "stdafx.h"
#include "Dimension.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CDimension::CDimension()
{
	cout << "생성자 CDimension() 호출" << endl;
}
CDimension::CDimension(const CDimension& src)
{
	*this = src;
}
CDimension:: ~CDimension()
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();
	cout << "소멸자 ~CDimension() 호출" << endl;
}
void CDimension::vSetDimensionLibArtworkLayNo(int nLibArtworkLayNo)
{
	m_nLibArtworkLayNo = nLibArtworkLayNo;
}
void CDimension::vSetDimensionDrawObj(CDrawObjArray aDrawObj)
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();


	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());
		delete pItem;
	}

}
int CDimension::nGetDimensionLibArtworkLayNo()
{
	return m_nLibArtworkLayNo;
}
CDrawObjArray CDimension::vGetDimensionDrawObj()
{
	return m_aDrawObj;
}
void CDimension::vAddDrawObj(CDrawObjArray aDrawObj)
{
	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		m_aDrawObj.Add(pItem->clone());
		delete pItem;
	}
}
CDrawObj& CDimension::operator =(const CDrawObj& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	CDrawObj::operator=(rhs);
	// Add code to serialize member variable
	return *this;
}
CDimension& CDimension::operator =(const CDimension& rhs)
{
	if (this == &rhs)
		return *this;
	
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	CDrawObj::operator=(rhs);

	for (int i = 0; i < rhs.m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = rhs.m_aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());
	}

	this->m_nLibArtworkLayNo = rhs.m_nLibArtworkLayNo;

	// Add code to serialize member variable
	return *this;
}


BOOL CDimension::operator==(const CDrawObj & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CDimension::operator!=(const CDrawObj& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CDrawObj* CDimension::clone()
{
	return new CDimension(*this);
}
//const int CDimension::m_nVersion = 1;