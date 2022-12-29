#include "stdafx.h"
#include "ReferenceList.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CReferenceList::CReferenceList()
{
	cout << "생성자 CReferenceList() 호출" << endl;
}
CReferenceList::CReferenceList(const CReferenceList& src)
{
	*this = src;
}
CReferenceList::~CReferenceList()
{
	for (int i = 0; i < m_aRef.GetSize(); i++)
	{
		CRef * pItem = m_aRef.GetAt(i);
		delete pItem;
	}
	m_aRef.RemoveAll();
	cout << "소멸자 ~CReferenceList() 호출" << endl;
}
void CReferenceList::vSetReferenceList(string sPointingType, CRefArray aRef)
{
	this->m_sPointingType = sPointingType;
	for (int i = 0; i < m_aRef.GetSize(); i++)
	{
		CRef * pItem = m_aRef.GetAt(i);
		delete pItem;
	}
	m_aRef.RemoveAll();

	for (int i = 0; i < aRef.GetSize(); i++)
	{
		CRef * pItem = aRef.GetAt(i);
		this->m_aRef.Add(pItem->clone());
		delete pItem;
	}
}

CReferenceList& CReferenceList::operator =(const CReferenceList& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_sPointingType = rhs.m_sPointingType;

	for (int i = 0; i < m_aRef.GetSize(); i++)
	{
		CRef * pItem = m_aRef.GetAt(i);
		delete pItem;
	}
	m_aRef.RemoveAll();
	
	for (int i = 0; i < rhs.m_aRef.GetSize(); i++)
	{
		CRef * pItem = new CRef();
		for (int j = 0; j < rhs.m_aRef[i]->m_aPinConnectionStatus.GetSize(); j++)
		{
			CPinConnectionStatus* pItem2 = new CPinConnectionStatus();
			pItem2->m_nPinNo = rhs.m_aRef[i]->m_aPinConnectionStatus[j]->m_nPinNo;
			for (int k = 0; k < rhs.m_aRef[i]->m_aPinConnectionStatus[j]->m_asConnectionStatus.GetSize(); k++)
			{
				pItem2->m_asConnectionStatus.Add(rhs.m_aRef[i]->m_aPinConnectionStatus[j]->m_asConnectionStatus[k]);
			}
			pItem->m_aPinConnectionStatus.Add(pItem2->clone());
			delete pItem2;
		}
		for (int j = 0; j < rhs.m_aRef[i]->m_aProperty.GetSize(); j++)
		{
			CPropertys* pItem2 = new CPropertys();
			pItem2->m_sPropertyContents = rhs.m_aRef[i]->m_aProperty[j]->m_sPropertyContents;
			pItem2->m_sPropertyItem = rhs.m_aRef[i]->m_aProperty[j]->m_sPropertyItem;
			pItem->m_aProperty.Add(pItem2->clone());
			delete pItem2;
		}

		pItem->m_bExistInBom = rhs.m_aRef[i]->m_bExistInBom;
		pItem->m_bReferenceTextReversePlaced = rhs.m_aRef[i]->m_bReferenceTextReversePlaced;
		pItem->m_cPassiveType = rhs.m_aRef[i]->m_cPassiveType;
		pItem->m_dAngle = rhs.m_aRef[i]->m_dAngle;
		pItem->m_dECADAngle = rhs.m_aRef[i]->m_dECADAngle;
		pItem->m_dPassiveValue = rhs.m_aRef[i]->m_dPassiveValue;
		pItem->m_dPtX = rhs.m_aRef[i]->m_dPtX;
		pItem->m_dPtY = rhs.m_aRef[i]->m_dPtY;
		pItem->m_nLibPartNo = rhs.m_aRef[i]->m_nLibPartNo;
		pItem->m_RefText = rhs.m_aRef[i]->m_RefText;
		pItem->m_RefText2 = rhs.m_aRef[i]->m_RefText2;
		pItem->m_sPlacedLayer = rhs.m_aRef[i]->m_sPlacedLayer;
		pItem->m_sReferenceName = rhs.m_aRef[i]->m_sReferenceName;
		pItem->m_sReferenceThermalCondition = rhs.m_aRef[i]->m_sReferenceThermalCondition;

		this->m_aRef.Add(pItem->clone());
		delete pItem;
	}

	// Add code to serialize member variable
	return *this;
}


BOOL CReferenceList::operator==(const CReferenceList & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CReferenceList::operator!=(const CReferenceList& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CReferenceList* CReferenceList::clone()
{
	return new CReferenceList(*this);

}
//  const int CReferenceList::m_nVersion = 1;