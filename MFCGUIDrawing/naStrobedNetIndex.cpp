#include "stdafx.h"
#include "naStrobedNetIndex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CStrobedNetIndex::CStrobedNetIndex()
{
	cout << "생성자 CStrobedNetIndex() 호출" << endl;
}
CStrobedNetIndex::CStrobedNetIndex(const CStrobedNetIndex& src)
{
	*this = src;
}
CStrobedNetIndex::~CStrobedNetIndex()
{
	cout << "소멸자 ~CStrobedNetIndex() 호출" << endl;
}
void CStrobedNetIndex::vSetNetIndex(CArray<int> naStrobedNetIndex)
{
	this->m_naStrobedNetIndex.RemoveAll();
	
	int pItem;

	for (int i = 0; i < naStrobedNetIndex.GetSize(); i++)
	{
		pItem = naStrobedNetIndex.GetAt(i);
		this->m_naStrobedNetIndex.Add(pItem);
	}
}
CStrobedNetIndex& CStrobedNetIndex::operator =(const CStrobedNetIndex& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_naStrobedNetIndex.RemoveAll();

	int pItem;

	for (int i = 0; i < rhs.m_naStrobedNetIndex.GetSize(); i++)
	{
		pItem = rhs.m_naStrobedNetIndex.GetAt(i);
		this->m_naStrobedNetIndex.Add(pItem);
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CStrobedNetIndex::operator==(const CStrobedNetIndex & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CStrobedNetIndex::operator!=(const CStrobedNetIndex& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CStrobedNetIndex* CStrobedNetIndex::clone()
{
	return new CStrobedNetIndex(*this);

}
// const int CStrobedNetIndex::m_nVersion = 1;


CStrobedNetIndexArray::CStrobedNetIndexArray()
{
}
CStrobedNetIndexArray::CStrobedNetIndexArray(const CStrobedNetIndexArray& src)
{
	*this = src;
}
CStrobedNetIndexArray::~CStrobedNetIndexArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CStrobedNetIndex * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CStrobedNetIndexArray& CStrobedNetIndexArray::operator =(const CStrobedNetIndexArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CStrobedNetIndex * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CStrobedNetIndex* pItem = new CStrobedNetIndex();
		for (int j = 0; j < rhs.GetAt(i)->m_naStrobedNetIndex.GetSize(); j++)
		{ 
			int nItem = rhs.GetAt(i)->m_naStrobedNetIndex.GetAt(j);
			pItem->m_naStrobedNetIndex.Add(nItem);
		}
		this->Add(pItem->clone());
	}

	return *this;
}

bool CStrobedNetIndexArray::operator==(const CStrobedNetIndexArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CStrobedNetIndex* pItem1;
	CStrobedNetIndex* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CStrobedNetIndexArray::operator!=(const CStrobedNetIndexArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CStrobedNetIndexArray* CStrobedNetIndexArray::clone()
{
	return new CStrobedNetIndexArray(*this);

}