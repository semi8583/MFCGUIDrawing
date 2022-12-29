#include "stdafx.h"
#include "PinConnectionStatus.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPinConnectionStatus::CPinConnectionStatus()
{
	cout << "생성자 CPinConnectionStatus() 호출" << endl;
}
CPinConnectionStatus::CPinConnectionStatus(const CPinConnectionStatus& src)
{
	*this = src;
}
CPinConnectionStatus::~CPinConnectionStatus()
{
	m_asConnectionStatus.RemoveAll();
	cout << "소멸자 ~CPinConnectionStatus() 호출" << endl;
}
void CPinConnectionStatus::vPinConnectionStatus(int nPinNo, CArray<string> asConnectionStatus)
{
	this->m_nPinNo = nPinNo;
	m_asConnectionStatus.RemoveAll();
	for (int i = 0; i < asConnectionStatus.GetSize(); i++)
	{
		m_asConnectionStatus.Add(asConnectionStatus[i]);
	}
}
CPinConnectionStatus& CPinConnectionStatus::operator =(const CPinConnectionStatus& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_nPinNo = rhs.m_nPinNo;
	m_asConnectionStatus.RemoveAll();
	for (int i = 0; i < rhs.m_asConnectionStatus.GetSize(); i++)
	{
		m_asConnectionStatus.Add(rhs.m_asConnectionStatus.GetAt(i));
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CPinConnectionStatus::operator==(const CPinConnectionStatus & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPinConnectionStatus::operator!=(const CPinConnectionStatus& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPinConnectionStatus* CPinConnectionStatus::clone()
{
	return new CPinConnectionStatus(*this);

}
// const int CPinConnectionStatus::m_nVersion = 1;


CPinConnectionStatusArray::CPinConnectionStatusArray()
{
}
CPinConnectionStatusArray::CPinConnectionStatusArray(const CPinConnectionStatusArray& src)
{
	*this = src;
}
CPinConnectionStatusArray::~CPinConnectionStatusArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CPinConnectionStatus * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CPinConnectionStatusArray& CPinConnectionStatusArray::operator =(const CPinConnectionStatusArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CPinConnectionStatus * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CPinConnectionStatus* pItem = new CPinConnectionStatus();
		pItem->m_nPinNo = rhs.GetAt(i)->m_nPinNo;
		for (int j = 0; j < rhs.GetAt(i)->m_asConnectionStatus.GetSize(); j++)
			pItem->m_asConnectionStatus.Add(rhs.GetAt(i)->m_asConnectionStatus.GetAt(j));
		this->Add(pItem->clone());
	}

	return *this;
}

bool CPinConnectionStatusArray::operator==(const CPinConnectionStatusArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CPinConnectionStatus* pItem1;
	CPinConnectionStatus* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CPinConnectionStatusArray::operator!=(const CPinConnectionStatusArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPinConnectionStatusArray* CPinConnectionStatusArray::clone()
{
	return new CPinConnectionStatusArray(*this);

}