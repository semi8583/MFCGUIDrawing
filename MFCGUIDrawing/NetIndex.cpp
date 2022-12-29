#include "stdafx.h"
#include "NetIndex.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CNetIndex::CNetIndex()
{
	cout << "생성자 CNetIndex() 호출" << endl;
}
CNetIndex::CNetIndex(const CNetIndex& src)
{
	*this = src;
}
CNetIndex::~CNetIndex()
{
	cout << "소멸자 ~CNetIndex() 호출" << endl;
}
void CNetIndex::vSetNetIndex(CArray<int> naNetIndex)
{
	this->m_naNetIndex.RemoveAll();
	int pItem;
	for (int i = 0; i < naNetIndex.GetSize(); i++)
	{
		pItem = naNetIndex.GetAt(i);
		m_naNetIndex.Add(pItem);
	}
}
CNetIndex& CNetIndex::operator =(const CNetIndex& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_naNetIndex.RemoveAll();
	int pItem;
	for (int i = 0; i < rhs.m_naNetIndex.GetSize(); i++)
	{
		pItem = rhs.m_naNetIndex.GetAt(i);
		m_naNetIndex.Add(pItem);
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CNetIndex::operator==(const CNetIndex & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CNetIndex::operator!=(const CNetIndex& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetIndex* CNetIndex::clone()
{
	return new CNetIndex(*this);

}
// const int CNetIndex::m_nVersion = 1;


CNetIndexArray::CNetIndexArray()
{
}
CNetIndexArray::CNetIndexArray(const CNetIndexArray& src)
{
	*this = src;
}
CNetIndexArray::~CNetIndexArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CNetIndex * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CNetIndexArray& CNetIndexArray::operator =(const CNetIndexArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CNetIndex * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CNetIndex* pItem = new CNetIndex();
		for (int j = 0; j < rhs.GetAt(i)->m_naNetIndex.GetSize(); j++)
		{
			int nItem = rhs.GetAt(i)->m_naNetIndex.GetAt(j);
			pItem->m_naNetIndex.Add(nItem);
		}
		this->Add(pItem->clone());

	}

	return *this;
}

bool CNetIndexArray::operator==(const CNetIndexArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CNetIndex* pItem1;
	CNetIndex* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CNetIndexArray::operator!=(const CNetIndexArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetIndexArray* CNetIndexArray::clone()
{
	return new CNetIndexArray(*this);

}