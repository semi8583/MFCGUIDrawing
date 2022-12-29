#include "stdafx.h"
#include "PinConnection.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPinConnection::CPinConnection()
{
	cout << "생성자 CPinConnection() 호출" << endl;
}
CPinConnection::CPinConnection(const CPinConnection& src)
{
	*this = src;
}
CPinConnection::~CPinConnection()
{
	cout << "소멸자 ~CPinConnection() 호출" << endl;
}
void CPinConnection::vSetPinConnection(string sFirstPinName, string sSecondPinName, string sConnectType, double dValue)
{
	this->m_sFirstPinName = sFirstPinName;
	this->m_sSecondPinName = sSecondPinName;
	this->m_sConnectType = sConnectType;
	this->m_dValue = dValue;
}
CPinConnection& CPinConnection::operator =(const CPinConnection& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_sFirstPinName = rhs.m_sFirstPinName;
	this->m_sSecondPinName = rhs.m_sSecondPinName;
	this->m_sConnectType = rhs.m_sConnectType;
	this->m_dValue = rhs.m_dValue;
	// Add code to serialize member variable
	return *this;
}


BOOL CPinConnection::operator==(const CPinConnection & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPinConnection::operator!=(const CPinConnection& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPinConnection* CPinConnection::clone()
{
	return new CPinConnection(*this);

}
// const int CPinConnection::m_nVersion = 1;

CPinConnectionArray::CPinConnectionArray()
{
}
CPinConnectionArray::CPinConnectionArray(const CPinConnectionArray& src)
{
	*this = src;
}
CPinConnectionArray::~CPinConnectionArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CPinConnection * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CPinConnectionArray& CPinConnectionArray::operator =(const CPinConnectionArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CPinConnection * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CPinConnection* pItem = new CPinConnection();
		pItem->m_dValue = rhs.GetAt(i)->m_dValue;
		pItem->m_sConnectType = rhs.GetAt(i)->m_sConnectType;
		pItem->m_sFirstPinName = rhs.GetAt(i)->m_sFirstPinName;
		pItem->m_sSecondPinName = rhs.GetAt(i)->m_sSecondPinName;
		this->Add(pItem->clone());
	}

	return *this;
}

bool CPinConnectionArray::operator==(const CPinConnectionArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CPinConnection* pItem1;
	CPinConnection* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CPinConnectionArray::operator!=(const CPinConnectionArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPinConnectionArray* CPinConnectionArray::clone()
{
	return new CPinConnectionArray(*this);

}