#include "stdafx.h"
#include "LayerTypeName.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CLayerTypeName::CLayerTypeName()
{
	cout << "생성자 CsLayerTypeName() 호출" << endl;
}
CLayerTypeName::CLayerTypeName(const CLayerTypeName& src)
{
	*this = src;
}
CLayerTypeName::~CLayerTypeName()
{
	for (int i = 0; i < m_aConnectionType.GetSize(); i++)
	{
		CConnectionType* pItem = m_aConnectionType.GetAt(i);
		delete pItem;
	}
	m_aConnectionType.RemoveAll();
	cout << "소멸자 ~CsLayerTypeName() 호출" << endl;
}
void CLayerTypeName::vSetCsLayerTypeName(string sLayerTypeName, CConnectionTypeArray aConnectionType)
{
	m_sLayerTypeName = sLayerTypeName;
	for (int i = 0; m_aConnectionType.GetSize(); i++)
	{
		CConnectionType* pItem = m_aConnectionType.GetAt(i);
		delete pItem;
	}
	m_aConnectionType.RemoveAll();

	for (int i = 0; aConnectionType.GetSize(); i++)
	{
		CConnectionType* pItem = aConnectionType.GetAt(i);
		m_aConnectionType.Add(pItem->clone());
		delete pItem;
	}
}
CLayerTypeName& CLayerTypeName::operator =(const CLayerTypeName& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; m_aConnectionType.GetSize(); i++)
	{
		CConnectionType* pItem = m_aConnectionType.GetAt(i);
		delete pItem;
	}
	m_aConnectionType.RemoveAll();

	for (int i = 0; i < rhs.m_aConnectionType.GetSize(); i++)
	{
		CConnectionType * pItem = rhs.m_aConnectionType.GetAt(i);
		this->m_aConnectionType.Add(pItem->clone());
	}
	this->m_sLayerTypeName = rhs.m_sLayerTypeName;
	// Add code to serialize member variable
	return *this;
}


BOOL CLayerTypeName::operator==(const CLayerTypeName & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CLayerTypeName::operator!=(const CLayerTypeName& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLayerTypeName* CLayerTypeName::clone()
{
	return new CLayerTypeName(*this);

}
//const int CLayerTypeName::m_nVersion = 1;

CLayerTypeNameArray::CLayerTypeNameArray()
{
}
CLayerTypeNameArray::CLayerTypeNameArray(const CLayerTypeNameArray& src)
{
	*this = src;
}
CLayerTypeNameArray::~CLayerTypeNameArray()
{
	for (int i = 0; GetSize(); i++)
	{
		CLayerTypeName * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CLayerTypeNameArray& CLayerTypeNameArray::operator =(const CLayerTypeNameArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; GetSize(); i++)
	{
		CLayerTypeName * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CLayerTypeName* pItem = new CLayerTypeName();
		pItem->m_sLayerTypeName = rhs.GetAt(i)->m_sLayerTypeName;
		for (int j = 0; j < rhs.GetAt(i)->m_aConnectionType.GetSize(); j++)
		{
			CConnectionType* pItem2 = new CConnectionType();
			pItem2->m_sConnectionType = rhs.GetAt(i)->m_aConnectionType.GetAt(j)->m_sConnectionType;
			for (int k = 0; k < rhs.GetAt(i)->m_aConnectionType.GetAt(j)->m_aDrawObj.GetSize(); k++)
			{
				CDrawObj* pItem3 = rhs.GetAt(i)->m_aConnectionType.GetAt(j)->m_aDrawObj.GetAt(k);
				pItem2->m_aDrawObj.Add(pItem3->clone());
				delete pItem3;
			}
			pItem->m_aConnectionType.Add(pItem2->clone());
			delete pItem2;
		}
		this->Add(pItem->clone());
		delete pItem;
	}

	return *this;
}

bool CLayerTypeNameArray::operator==(const CLayerTypeNameArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CLayerTypeName* pItem1;
	CLayerTypeName* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CLayerTypeNameArray::operator!=(const CLayerTypeNameArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLayerTypeNameArray* CLayerTypeNameArray::clone()
{
	return new CLayerTypeNameArray(*this);

}