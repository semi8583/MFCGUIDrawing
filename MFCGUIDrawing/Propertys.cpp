#include "stdafx.h"
#include "Propertys.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPropertys::CPropertys()
{
	cout << "생성자 CPropertys() 호출" << endl;
}
CPropertys::CPropertys(const CPropertys& src)
{
	*this = src;
}
CPropertys::~CPropertys()
{
	cout << "소멸자 ~CPropertys() 호출" << endl;
}
void CPropertys::vSetCPropertys(string sPropertyItem, string sPropertyContents)
{
	this->m_sPropertyContents = sPropertyContents;
	this->m_sPropertyItem = sPropertyItem;
}
CPropertys& CPropertys::operator =(const CPropertys& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_sPropertyContents = rhs.m_sPropertyContents;
	this->m_sPropertyItem = rhs.m_sPropertyItem;
	// Add code to serialize member variable
	return *this;
}


BOOL CPropertys::operator==(const CPropertys & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPropertys::operator!=(const CPropertys& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPropertys* CPropertys::clone()
{
	return new CPropertys(*this);

}




CPropertysArray::CPropertysArray()
{
}
CPropertysArray::CPropertysArray(const CPropertysArray& src)
{
	*this = src;
}
CPropertysArray::~CPropertysArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CPropertys * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CPropertysArray& CPropertysArray::operator =(const CPropertysArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CPropertys * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CPropertys* pItem = new CPropertys();
		pItem->m_sPropertyContents = rhs.GetAt(i)->m_sPropertyContents;
		pItem->m_sPropertyItem = rhs.GetAt(i)->m_sPropertyItem;
		this->Add(pItem->clone());
	}

	return *this;
}

bool CPropertysArray::operator==(const CPropertysArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CPropertys* pItem1;
	CPropertys* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CPropertysArray::operator!=(const CPropertysArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPropertysArray* CPropertysArray::clone()
{
	return new CPropertysArray(*this);

}