#include "stdafx.h"
#include "LibVia.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CLibVia::CLibVia()
{
	cout << "생성자 CLibVia() 호출" << endl;
}
CLibVia::CLibVia(const CLibVia& src)
{
	*this = src;
}
CLibVia::~CLibVia()
{
	for (int i = 0; i < m_aViaDefinition.GetSize(); i++)
	{
		CViaDefinition * pItem = m_aViaDefinition.GetAt(i);
		delete pItem;
	}
	m_aViaDefinition.RemoveAll();
	cout << "소멸자 ~CLibVia() 호출" << endl;
}
void CLibVia::vSetCLibVia(CViaDefinitionArray aViaDefinition)
{
	for (int i = 0; i < m_aViaDefinition.GetSize(); i++)
	{
		CViaDefinition * pItem = m_aViaDefinition.GetAt(i);
		delete pItem;
	}
	m_aViaDefinition.RemoveAll();

	for (int i = 0; i < aViaDefinition.GetSize(); i++)
	{
		CViaDefinition* pItem = new CViaDefinition();
		pItem->m_aLayerTypeName = aViaDefinition[i]->m_aLayerTypeName;
		pItem->m_nLibTurretForHoleNo = aViaDefinition[i]->m_nLibTurretForHoleNo;
		pItem->m_nLibViaNo = aViaDefinition[i]->m_nLibViaNo;
		pItem->m_nViaEndingArtworkLayNo = aViaDefinition[i]->m_nViaEndingArtworkLayNo;
		pItem->m_nViaStartingArtworkLayNo = aViaDefinition[i]->m_nViaStartingArtworkLayNo;
		pItem->m_sPlatedType = aViaDefinition[i]->m_sPlatedType;
		pItem->m_sViaName = aViaDefinition[i]->m_sViaName;
		pItem->m_sViaType = aViaDefinition[i]->m_sViaType;
		this->m_aViaDefinition.Add(pItem->clone());
		delete pItem;
	}
}
CLibVia& CLibVia::operator =(const CLibVia& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < m_aViaDefinition.GetSize(); i++)
	{
		CViaDefinition * pItem = m_aViaDefinition.GetAt(i);
		delete pItem;
	}
	m_aViaDefinition.RemoveAll();

	for (int i = 0; i < rhs.m_aViaDefinition.GetSize(); i++)
	{
		CViaDefinition* pItem = new CViaDefinition();
		for (int j = 0; j < rhs.m_aViaDefinition[i]->m_aLayerTypeName.GetSize(); j++)
		{
			pItem->m_aLayerTypeName.Add(rhs.m_aViaDefinition[i]->m_aLayerTypeName[j]->clone());
		}
		pItem->m_nLibTurretForHoleNo = rhs.m_aViaDefinition[i]->m_nLibTurretForHoleNo;
		pItem->m_nLibViaNo = rhs.m_aViaDefinition[i]->m_nLibViaNo;
		pItem->m_nViaEndingArtworkLayNo = rhs.m_aViaDefinition[i]->m_nViaEndingArtworkLayNo;
		pItem->m_nViaStartingArtworkLayNo = rhs.m_aViaDefinition[i]->m_nViaStartingArtworkLayNo;
		pItem->m_sPlatedType = rhs.m_aViaDefinition[i]->m_sPlatedType;
		pItem->m_sViaName = rhs.m_aViaDefinition[i]->m_sViaName;
		pItem->m_sViaType = rhs.m_aViaDefinition[i]->m_sViaType;
		this->m_aViaDefinition.Add(pItem->clone());
		delete pItem;
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CLibVia::operator==(const CLibVia & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CLibVia::operator!=(const CLibVia& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLibVia* CLibVia::clone()
{
	return new CLibVia(*this);

}
//const int CLibVia::m_nVersion = 1;