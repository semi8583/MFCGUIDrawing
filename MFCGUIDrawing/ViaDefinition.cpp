#include "stdafx.h"
#include "ViaDefinition.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CViaDefinition::CViaDefinition()
{
	cout << "생성자 CViaDefinition() 호출" << endl;
}
CViaDefinition::CViaDefinition(const CViaDefinition& src)
{
	*this = src;
}

CViaDefinition::~CViaDefinition()
{
	for (int i = 0; i < m_aLayerTypeName.GetSize(); i++)
	{
		CLayerTypeName * pItem = m_aLayerTypeName.GetAt(i);
		delete pItem;
	}
	m_aLayerTypeName.RemoveAll();
	cout << "소멸자 ~CViaDefinition() 호출" << endl;
}
void CViaDefinition::vSetViaDefinition(int nLibViaNo, string sViaName, string sViaType, int nLibTurretForHoleNo,
	string sPlatedType, int nViaStartingArtworkLayNo, int nViaEndingArtworkLayNo, CLayerTypeNameArray aLayerTypeName)
{
	for (int i = 0; i < m_aLayerTypeName.GetSize(); i++)
	{
		CLayerTypeName * pItem = m_aLayerTypeName.GetAt(i);
		delete pItem;
	}
	m_aLayerTypeName.RemoveAll();

	this->m_nLibViaNo = nLibViaNo;
	this->m_sViaName = sViaName;
	this->m_sViaType = sViaType;
	this->m_nLibTurretForHoleNo = nLibTurretForHoleNo;
	this->m_sPlatedType = sPlatedType;
	this->m_nViaStartingArtworkLayNo = nViaStartingArtworkLayNo;
	this->m_nViaEndingArtworkLayNo = nViaEndingArtworkLayNo;
	for (int i = 0; i < aLayerTypeName.GetSize(); i++)
	{
		CLayerTypeName* pItem = new CLayerTypeName();
		pItem = aLayerTypeName.GetAt(i);
		this->m_aLayerTypeName.Add(pItem->clone());
	}
}
CViaDefinition& CViaDefinition::operator =(const CViaDefinition& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < m_aLayerTypeName.GetSize(); i++)
	{
		CLayerTypeName * pItem = m_aLayerTypeName.GetAt(i);
		delete pItem;
	}
	m_aLayerTypeName.RemoveAll();

	this->m_nLibViaNo = rhs.m_nLibViaNo;
	this->m_sViaName = rhs.m_sViaName;
	this->m_sViaType = rhs.m_sViaType;
	this->m_nLibTurretForHoleNo = rhs.m_nLibTurretForHoleNo;
	this->m_sPlatedType = rhs.m_sPlatedType;
	this->m_nViaStartingArtworkLayNo = rhs.m_nViaStartingArtworkLayNo;
	this->m_nViaEndingArtworkLayNo = rhs.m_nViaEndingArtworkLayNo;
	for (int i = 0; i < rhs.m_aLayerTypeName.GetSize(); i++)
	{
		CLayerTypeName* pItem = rhs.m_aLayerTypeName.GetAt(i);
		this->m_aLayerTypeName.Add(pItem->clone());
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CViaDefinition::operator==(const CViaDefinition & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CViaDefinition::operator!=(const CViaDefinition& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CViaDefinition* CViaDefinition::clone()
{
	return new CViaDefinition(*this);

}
// const int CViaDefinition::m_nVersion = 1;


CViaDefinitionArray::CViaDefinitionArray()
{
}
CViaDefinitionArray::CViaDefinitionArray(const CViaDefinitionArray& src)
{
	*this = src;
}
CViaDefinitionArray::~CViaDefinitionArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CViaDefinition * pItem = GetAt(i);
		delete pItem;
	}
    RemoveAll();
}

CViaDefinitionArray& CViaDefinitionArray::operator =(const CViaDefinitionArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CViaDefinition * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CViaDefinition* pItem = new CViaDefinition();

		for (int j = 0; j < rhs[i]->m_aLayerTypeName.GetSize(); j++)
		{
			pItem->m_aLayerTypeName.Add(rhs.GetAt(i)->m_aLayerTypeName.GetAt(j)->clone());
		}
		pItem->m_nLibTurretForHoleNo = rhs[i]->m_nLibTurretForHoleNo;
		pItem->m_nLibViaNo = rhs[i]->m_nLibViaNo;
		pItem->m_nViaEndingArtworkLayNo = rhs[i]->m_nViaEndingArtworkLayNo;
		pItem->m_nViaStartingArtworkLayNo = rhs[i]->m_nViaStartingArtworkLayNo;
		pItem->m_sPlatedType = rhs[i]->m_sPlatedType;
		pItem->m_sViaName = rhs[i]->m_sViaName;
		pItem->m_sViaType = rhs[i]->m_sViaType;
		this->Add(pItem->clone());
	}

	return *this;
}

bool CViaDefinitionArray::operator==(const CViaDefinitionArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CViaDefinition* pItem1;
	CViaDefinition* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CViaDefinitionArray::operator!=(const CViaDefinitionArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CViaDefinitionArray* CViaDefinitionArray::clone()
{
	return new CViaDefinitionArray(*this);

}