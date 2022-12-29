#include "stdafx.h"
#include "NetClassList.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CNetClassList::CNetClassList()
{
	cout << "생성자 CNetClassList() 호출" << endl;
}
CNetClassList::CNetClassList(const CNetClassList& src)
{
	*this = src;
}
CNetClassList::~CNetClassList()
{
	cout << "소멸자 ~CNetClassList() 호출" << endl;
}
void CNetClassList::vSetNetClassList(string sClassName, CArray<string>  saStringFilter)
{
	m_sClassName = sClassName;

	m_saStringFilter.RemoveAll();
	string pItem;
	for (int i = 0; i < saStringFilter.GetSize(); i++)
	{
		pItem = saStringFilter.GetAt(i);
		m_saStringFilter.Add(pItem);
	}
}
CNetClassList& CNetClassList::operator =(const CNetClassList& rhs)
{
	if (this == &rhs)
		return *this;

	m_sClassName = rhs.m_sClassName;

	m_saStringFilter.RemoveAll();
	string pItem;
	for (int i = 0; i < rhs.m_saStringFilter.GetSize(); i++)
	{
		pItem = rhs.m_saStringFilter.GetAt(i);
		m_saStringFilter.Add(pItem);
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CNetClassList::operator==(const CNetClassList & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CNetClassList::operator!=(const CNetClassList& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetClassList* CNetClassList::clone()
{
	return new CNetClassList(*this);

}
// const int CNetClassList::m_nVersion = 1;


CNetClassListArray::CNetClassListArray()
{
}
CNetClassListArray::CNetClassListArray(const CNetClassListArray& src)
{
	*this = src;
}
CNetClassListArray::~CNetClassListArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CNetClassList * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CNetClassListArray& CNetClassListArray::operator =(const CNetClassListArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CNetClassList * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CNetClassList* pItem = new CNetClassList();
		pItem->m_sClassName = rhs.GetAt(i)->m_sClassName;
		for (int j = 0; j < rhs.GetAt(i)->m_saStringFilter.GetSize(); j++)
		{
			string pItem2 = rhs.GetAt(i)->m_saStringFilter.GetAt(j);
			pItem->m_saStringFilter.Add(pItem2);
		}
		this->Add(pItem->clone());
	}

	return *this;
}

bool CNetClassListArray::operator==(const CNetClassListArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CNetClassList* pItem1;
	CNetClassList* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CNetClassListArray::operator!=(const CNetClassListArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetClassListArray* CNetClassListArray::clone()
{
	return new CNetClassListArray(*this);

}