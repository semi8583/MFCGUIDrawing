#include "stdafx.h"
#include "Void.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CVoid::CVoid()
{
	cout << "생성자 CVoid() 호출" << endl;
}
CVoid::CVoid(const CVoid& src)
{
	*this = src;
}
CVoid:: ~CVoid()
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();
	cout << "소멸자 ~CVoid() 호출" << endl;
}
void CVoid::vSetVoidLibArtworkLayNo(int nLibArtworkLayNo)
{
	m_nLibArtworkLayNo = nLibArtworkLayNo;
}
void CVoid::vSetVoidDrawObj(CDrawObjArray aDrawObj)
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
		m_aDrawObj.Add(pItem->clone());
		delete pItem;
	}
}
int CVoid::nGetVoidLibArtworkLayNo()
{
	return m_nLibArtworkLayNo;
}
CDrawObjArray CVoid::vGetVoidDrawObj()
{
	return this->m_aDrawObj;
}
void CVoid::vAddDrawObj(CDrawObjArray aDrawObj)
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
		m_aDrawObj.Add(pItem->clone());
	}
}
void CVoid::vAddPolygon(CDrawObj* aDrawObj)
{
	CPolygon* pPolygon;
	if (pPolygon = dynamic_cast<CPolygon*>(aDrawObj))
	{
		m_aDrawObj.Add(pPolygon->clone());
	}
}
CDrawObj& CVoid::operator =(const CDrawObj& rhs)
{
	if (this == &rhs)
		return *this;
	CDrawObj::operator=(rhs);
	// Add code to serialize member variable
	return *this;
}
CVoid& CVoid::operator =(const CVoid& rhs)
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
	this->m_nLibArtworkLayNo = rhs.m_nLibArtworkLayNo;
	for (int i = 0; i < rhs.m_aDrawObj.GetSize(); i++)
	{
		CDrawObj* pItem = rhs.m_aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());
	}
	// Add code to serialize member variable
	return *this;
}
void CVoid::vAddPt(CDrawObjArray aDrawObj)
{
	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CPt* pPt;
		if (pPt = dynamic_cast<CPt*>(aDrawObj[i]))
		{
			m_aDrawObj.Add(pPt->clone());
		}
	}
}
void CVoid::vAddPt(CDrawObj* pDrawObj)
{
	CPt* pPt;//0x000001cd80d01720

	if (pPt = dynamic_cast<CPt*>(pDrawObj))
	{
		m_aDrawObj.Add(pPt->clone());
	}
}
BOOL CVoid::operator==(const CDrawObj & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CVoid::operator!=(const CDrawObj& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CDrawObj* CVoid::clone()
{
	return new CVoid(*this);
}
// const int CVoid::m_nVersion = 1;