#include "stdafx.h"
#include "PadDefinition.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPadDefinition::CPadDefinition()
{
	cout << "생성자 CPadDefinition() 호출" << endl;
}
CPadDefinition::CPadDefinition(const CPadDefinition& src)
{
	*this = src;
}
CPadDefinition::~CPadDefinition()
{
	for (int i = 0; i < m_aLayerTypeName.GetSize(); i++)
	{
		CLayerTypeName * pItem = m_aLayerTypeName.GetAt(i);
		delete pItem;
	}
	m_aLayerTypeName.RemoveAll();
	cout << "소멸자 ~CPadDefinition() 호출" << endl;
}
void CPadDefinition::vSetPadDefinition(int nLibPadStackNo, string sPadStackName, string sPadStackType, int nLibTurretForHoleNo, string sPlatedType,
int nPadStackStartingArtworkLayNo, int nPadStackEndingArtworkLayNo, CLayerTypeNameArray aLayerTypeName)
{
	for (int i = 0; i < m_aLayerTypeName.GetSize(); i++)
	{
		CLayerTypeName * pItem = m_aLayerTypeName.GetAt(i);
		delete pItem;
	}
	m_aLayerTypeName.RemoveAll();

	this->m_nLibPadStackNo = nLibPadStackNo;
	this->m_sPadStackName = sPadStackName;
	this->m_sPadstackType = sPadStackType;
	this->m_nLibTurretForHoleNo = nLibTurretForHoleNo;
	this->m_sPlatedType = sPlatedType;
	this->m_nPadStackStartingArtworkLayNo = nPadStackStartingArtworkLayNo;
	this->m_nPadstackEndingArtworkLayNo = nPadStackEndingArtworkLayNo;

	for (int i = 0; i < aLayerTypeName.GetSize(); i++)
	{
		CLayerTypeName* pItem = new CLayerTypeName();
		pItem = aLayerTypeName.GetAt(i);
		this->m_aLayerTypeName.Add(pItem->clone());
		delete pItem;
	}
}
CPadDefinition& CPadDefinition::operator =(const CPadDefinition& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_nLibPadStackNo = rhs.m_nLibPadStackNo;
	this->m_sPadStackName = rhs.m_sPadStackName;
	this->m_sPadstackType = rhs.m_sPadstackType;
	this->m_nLibTurretForHoleNo = rhs.m_nLibTurretForHoleNo;
	this->m_sPlatedType = rhs.m_sPlatedType;
	this->m_nPadStackStartingArtworkLayNo = rhs.m_nPadStackStartingArtworkLayNo;
	this->m_nPadstackEndingArtworkLayNo = rhs.m_nPadstackEndingArtworkLayNo;
	
	for (int i = 0; i < m_aLayerTypeName.GetSize(); i++)
	{
		CLayerTypeName * pItem = m_aLayerTypeName.GetAt(i);
		delete pItem;
	}
	m_aLayerTypeName.RemoveAll();

	for (int i = 0; i < rhs.m_aLayerTypeName.GetSize(); i++)
	{
		CLayerTypeName* pItem = rhs.m_aLayerTypeName.GetAt(i);
		this->m_aLayerTypeName.Add(pItem->clone());
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CPadDefinition::operator==(const CPadDefinition & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPadDefinition::operator!=(const CPadDefinition& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPadDefinition* CPadDefinition::clone()
{
	return new CPadDefinition(*this);

}
// const int CPadDefinition::m_nVersion = 1;


CPadDefinitionArray::CPadDefinitionArray()
{
}
CPadDefinitionArray::CPadDefinitionArray(const CPadDefinitionArray& src)
{
	*this = src;
}
CPadDefinitionArray::~CPadDefinitionArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CPadDefinition * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CPadDefinitionArray& CPadDefinitionArray::operator =(const CPadDefinitionArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CPadDefinition * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CPadDefinition* pItem = new CPadDefinition();

		pItem->m_sPlatedType = rhs.GetAt(i)->m_sPlatedType;
		pItem->m_sPadstackType = rhs.GetAt(i)->m_sPadstackType;
		pItem->m_sPadStackName = rhs.GetAt(i)->m_sPadStackName;
		pItem->m_nPadStackStartingArtworkLayNo = rhs.GetAt(i)->m_nPadStackStartingArtworkLayNo;
		pItem->m_nPadstackEndingArtworkLayNo = rhs.GetAt(i)->m_nPadstackEndingArtworkLayNo;
		pItem->m_nLibTurretForHoleNo = rhs.GetAt(i)->m_nLibTurretForHoleNo;
		pItem->m_nLibPadStackNo = rhs.GetAt(i)->m_nLibPadStackNo;
		for (int j = 0; j < rhs.GetAt(i)->m_aLayerTypeName.GetSize(); j++)
		{
			CLayerTypeName* pItem2 = new CLayerTypeName();
			pItem2->m_sLayerTypeName = rhs.GetAt(i)->m_aLayerTypeName.GetAt(j)->m_sLayerTypeName;
			for (int k = 0; k < rhs.GetAt(i)->m_aLayerTypeName.GetAt(j)->m_aConnectionType.GetSize(); k++)
			{
				CConnectionType* pItem3 = new CConnectionType();
				pItem3->m_sConnectionType = rhs.GetAt(i)->m_aLayerTypeName.GetAt(j)->m_aConnectionType.GetAt(k)->m_sConnectionType;
				for (int l = 0; l < rhs.GetAt(i)->m_aLayerTypeName.GetAt(j)->m_aConnectionType.GetAt(k)->m_aDrawObj.GetSize(); k++)
				{
					CDrawObj* pItem4 = new CDrawObj();
					pItem4 = rhs.GetAt(i)->m_aLayerTypeName.GetAt(j)->m_aConnectionType.GetAt(k)->m_aDrawObj.GetAt(l);
					pItem3->m_aDrawObj.Add(pItem4->clone());
				}
				pItem2->m_aConnectionType.Add(pItem3->clone());
			}
			pItem->m_aLayerTypeName.Add(pItem2->clone());
		}
		this->Add(pItem->clone());
	}

	return *this;
}

bool CPadDefinitionArray::operator==(const CPadDefinitionArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CPadDefinition* pItem1;
	CPadDefinition* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CPadDefinitionArray::operator!=(const CPadDefinitionArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPadDefinitionArray* CPadDefinitionArray::clone()
{
	return new CPadDefinitionArray(*this);

}