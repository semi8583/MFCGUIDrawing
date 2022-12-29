#include "stdafx.h"
#include "Part.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPart::CPart()
{
	cout << "생성자 CPart() 호출" << endl;
}
CPart::CPart(const CPart& src)
{
	*this = src;
}
CPart::~CPart()
{
	cout << "소멸자 ~CPart() 호출" << endl;
}
void CPart::setComponent(int nLibPartNo, double dDrawingSizeX, double dDrawingSizeY, double dHeight, bool bIsBroken, double dHighHeight, double dLowHeight, CNameDefinition NameDefinition,
	CMPNNameDefinition MPNNameDefinition, CSymbolDefinition SymbolDefinition, CPinDefinitionArray aPinDefinition, CPinConnectionArray aPinConnection,
	CSilkScreenDefinition SilkScreenDefinition, CFigureDefinition FigureDefinition, CPropertysArray aProperty)
{
	this->m_nLibPartNo = nLibPartNo;
	this->m_dDrawingSizeX = dDrawingSizeX;
	this->m_dDrawingSizeY = dDrawingSizeY;
	this->m_dHeight = dHeight;
	this->m_dHighHeight = dHighHeight;
	this->m_dLowHeight = dLowHeight;
	this->m_bIsBroken = bIsBroken;
	this->m_NameDefinition = NameDefinition;
	this->m_CMPNNameDefinition = MPNNameDefinition;
	this->m_SymbolDefinition = SymbolDefinition;
	this->m_SilkScreenDefinition = SilkScreenDefinition;
	this->m_FigureDefinition = FigureDefinition;

	for (int i = 0; i < m_aPinDefinition.GetSize(); i++)
	{
		CPinDefinition * pItem = m_aPinDefinition.GetAt(i);
		delete pItem;
	}
	m_aPinDefinition.RemoveAll();


	for (int i = 0; i < aPinDefinition.GetSize(); i++)
	{
		CPinDefinition * pItem1 = aPinDefinition.GetAt(i);
		this->m_aPinDefinition.Add(pItem1->clone());
	}

	for (int i = 0; i < m_aPinConnection.GetSize(); i++)
	{
		CPinConnection * pItem = m_aPinConnection.GetAt(i);
		delete pItem;
	}
	m_aPinConnection.RemoveAll();


	for (int i = 0; i < aPinConnection.GetSize(); i++)
	{
		CPinConnection * pItem2 = aPinConnection.GetAt(i);
		this->m_aPinConnection.Add(pItem2->clone());
	}

	for (int i = 0; i < m_aProperty.GetSize(); i++)
	{
		CPropertys * pItem = m_aProperty.GetAt(i);
		delete pItem;
	}
	m_aProperty.RemoveAll();


	for (int i = 0; i < aProperty.GetSize(); i++)
	{
		CPropertys* pItem3 = aProperty.GetAt(i);
		this->m_aProperty.Add(pItem3->clone());
	}
}
CPart& CPart::operator =(const CPart& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_nLibPartNo = rhs.m_nLibPartNo;
	this->m_dDrawingSizeX = rhs.m_dDrawingSizeX;
	this->m_dDrawingSizeY = rhs.m_dDrawingSizeY;
	this->m_dHeight = rhs.m_dHeight;
	this->m_dHighHeight = rhs.m_dHighHeight;
	this->m_dLowHeight = rhs.m_dLowHeight;
	this->m_bIsBroken = rhs.m_bIsBroken;
	this->m_NameDefinition = rhs.m_NameDefinition;
	this->m_CMPNNameDefinition = rhs.m_CMPNNameDefinition;
	this->m_SymbolDefinition = rhs.m_SymbolDefinition;
	this->m_SilkScreenDefinition = rhs.m_SilkScreenDefinition;
	this->m_FigureDefinition = rhs.m_FigureDefinition;

	for (int i = 0; i < m_aPinDefinition.GetSize(); i++)
	{
		CPinDefinition * pItem = m_aPinDefinition.GetAt(i);
		delete pItem;
	}
	m_aPinDefinition.RemoveAll();


	for (int i = 0; i < rhs.m_aPinDefinition.GetSize(); i++)
	{
		CPinDefinition * pItem1 = rhs.m_aPinDefinition.GetAt(i);
		this->m_aPinDefinition.Add(pItem1->clone());
	}

	for (int i = 0; i < m_aPinConnection.GetSize(); i++)
	{
		CPinConnection * pItem = m_aPinConnection.GetAt(i);
		delete pItem;
	}
	m_aPinConnection.RemoveAll();


	for (int i = 0; i < rhs.m_aPinConnection.GetSize(); i++)
	{
		CPinConnection * pItem2 = rhs.m_aPinConnection.GetAt(i);
		this->m_aPinConnection.Add(pItem2->clone());
	}

	for (int i = 0; i < m_aProperty.GetSize(); i++)
	{
		CPropertys * pItem = m_aProperty.GetAt(i);
		delete pItem;
	}
	m_aProperty.RemoveAll();


	for (int i = 0; i < rhs.m_aProperty.GetSize(); i++)
	{
		CPropertys* pItem3 = rhs.m_aProperty.GetAt(i);
		this->m_aProperty.Add(pItem3->clone());
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CPart::operator==(const CPart & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPart::operator!=(const CPart& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPart* CPart::clone()
{
	return new CPart(*this);

}
// const int CPart::m_nVersion = 1;


CPartArray::CPartArray()
{
}
CPartArray::CPartArray(const CPartArray& src)
{
	*this = src;
}
CPartArray::~CPartArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CPart * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CPartArray& CPartArray::operator =(const CPartArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CPart * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CPart* pItem = new CPart();
		pItem = rhs.GetAt(i);
		this->Add(pItem->clone());
	}

	return *this;
}

bool CPartArray::operator==(const CPartArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CPart* pItem1;
	CPart* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CPartArray::operator!=(const CPartArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPartArray* CPartArray::clone()
{
	return new CPartArray(*this);

}