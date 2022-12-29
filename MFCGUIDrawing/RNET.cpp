#include "stdafx.h"
#include "RNET.h"
#include "DrawObj.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CRNET::CRNET()
{
	cout << "생성자 CRNET() 호출" << endl;
}
CRNET::CRNET(const CRNET& src)
{
	*this = src;
}
CRNET::~CRNET()
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();
	cout << "소멸자 ~CRNET() 호출" << endl;
}
void CRNET::vSetRNET(string sNetName, CDrawObjArray aDrawObj, CColor Color, CPadColor PadColor)
{
	this->m_sNetName = sNetName;
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
	this->m_Color = Color;
	this->m_PadColor = PadColor;
}

CRNET& CRNET::operator =(const CRNET& rhs)
{
	if (this == &rhs)
		return *this;
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	this->m_sNetName = rhs.m_sNetName;

	for (int i = 0; i < rhs.m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = rhs.m_aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());
	}
	this->m_Color = rhs.m_Color;
	this->m_PadColor = rhs.m_PadColor;
	// Add code to serialize member variable
	return *this;
}


BOOL CRNET::operator==(const CRNET & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CRNET::operator!=(const CRNET& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CRNET* CRNET::clone()
{
	return new CRNET(*this);

}
// const int CRNET::m_nVersion = 1;


CRNETArray::CRNETArray()
{
}
CRNETArray::CRNETArray(const CRNETArray& src)
{
	*this = src;
}
CRNETArray::~CRNETArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CRNET * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CRNETArray& CRNETArray::operator =(const CRNETArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CRNET * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CRNET* pItem = new CRNET();

		pItem->m_sNetName = rhs.GetAt(i)->m_sNetName;
		pItem->m_Color = rhs.GetAt(i)->m_Color;
		pItem->m_PadColor = rhs.GetAt(i)->m_PadColor;
		//this->GetAt(i)->m_aDrawObj = rhs.GetAt(i)->m_aDrawObj;
		for (int j = 0; j < rhs.GetAt(i)->m_aDrawObj.GetSize(); j++)
		{
			CDrawObj* pItem2;
			pItem2 = rhs.GetAt(i)->m_aDrawObj.GetAt(j);
			pItem->m_aDrawObj.Add(pItem2->clone());
		}
		this->Add(pItem->clone());
	}

	return *this;
}

bool CRNETArray::operator==(const CRNETArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CRNET* pItem1;
	CRNET* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CRNETArray::operator!=(const CRNETArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CRNETArray* CRNETArray::clone()
{
	return new CRNETArray(*this);

}