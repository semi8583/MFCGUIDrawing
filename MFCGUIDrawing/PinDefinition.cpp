#include "stdafx.h"
#include "PinDefinition.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPinDefinition::CPinDefinition()
{
	cout << "생성자 CPinDefinition() 호출" << endl;
}
CPinDefinition::CPinDefinition(const CPinDefinition& src)
{
	*this = src;
}
CPinDefinition::~CPinDefinition()
{
	cout << "소멸자 ~CPinDefinition() 호출" << endl;
}
void CPinDefinition::vSetPinDefinition(int nPinNo, string sPinName, string sGatePinName, string sPinType, int nLibPadstackNo, double dAngle, int nSymbolNo, double dPtX, double dPtY)
{
	this->m_nPinNo = nPinNo;
	this->m_sPinName = sPinName;
	this->m_sGatePinName = sGatePinName;
	this->m_sPinType = sPinType;
	this->m_nLibPadStackNo = nLibPadstackNo;
	this->m_dAngle = dAngle;
	this->m_nSymbolNo = nSymbolNo;
	this->m_dPtX = dPtX;
	this->m_dPtY = dPtY;
}
CPinDefinition& CPinDefinition::operator =(const CPinDefinition& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_nPinNo = rhs.m_nPinNo;
	this->m_sPinName = rhs.m_sPinName;
	this->m_sGatePinName = rhs.m_sGatePinName;
	this->m_sPinType = rhs.m_sPinType;
	this->m_nLibPadStackNo = rhs.m_nLibPadStackNo;
	this->m_dAngle = rhs.m_dAngle;
	this->m_nSymbolNo = rhs.m_nSymbolNo;
	this->m_dPtX = rhs.m_dPtX;
	this->m_dPtY = rhs.m_dPtY;
	// Add code to serialize member variable
	return *this;
}


BOOL CPinDefinition::operator==(const CPinDefinition & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPinDefinition::operator!=(const CPinDefinition& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPinDefinition* CPinDefinition::clone()
{
	return new CPinDefinition(*this);

}
// const int CPinDefinition::m_nVersion = 1;

CPinDefinitionArray::CPinDefinitionArray()
{
}
CPinDefinitionArray::CPinDefinitionArray(const CPinDefinitionArray& src)
{
	*this = src;
}
CPinDefinitionArray::~CPinDefinitionArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CPinDefinition * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CPinDefinitionArray& CPinDefinitionArray::operator =(const CPinDefinitionArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CPinDefinition * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CPinDefinition* pItem = new CPinDefinition();
		pItem->m_dAngle = rhs.GetAt(i)->m_dAngle;
		pItem->m_dPtX = rhs.GetAt(i)->m_dPtX;
		pItem->m_dPtY = rhs.GetAt(i)->m_dPtY;
		pItem->m_nLibPadStackNo = rhs.GetAt(i)->m_nLibPadStackNo;
		pItem->m_nPinNo = rhs.GetAt(i)->m_nPinNo;
		pItem->m_nSymbolNo = rhs.GetAt(i)->m_nSymbolNo;
		pItem->m_sGatePinName = rhs.GetAt(i)->m_sGatePinName;
		pItem->m_sPinName = rhs.GetAt(i)->m_sPinName;
		pItem->m_sPinType = rhs.GetAt(i)->m_sPinType;
		this->Add(pItem->clone());
	}

	return *this;
}

bool CPinDefinitionArray::operator==(const CPinDefinitionArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CPinDefinition* pItem1;
	CPinDefinition* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CPinDefinitionArray::operator!=(const CPinDefinitionArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPinDefinitionArray* CPinDefinitionArray::clone()
{
	return new CPinDefinitionArray(*this);

}