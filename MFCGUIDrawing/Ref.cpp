#include "stdafx.h"
#include "Ref.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CRef::CRef()
{
	cout << "생성자 CRef() 호출" << endl;
}
CRef::CRef(const CRef& src)
{
	*this = src;
}
CRef::~CRef()
{
	for (int i = 0; i < m_aPinConnectionStatus.GetSize(); i++)
	{
		CPinConnectionStatus * pItem = m_aPinConnectionStatus.GetAt(i);
		delete pItem;
	}
	m_aPinConnectionStatus.RemoveAll();
	for (int i = 0; i < m_aProperty.GetSize(); i++)
	{
		CPropertys * pItem = m_aProperty.GetAt(i);
		delete pItem;
	}
	m_aProperty.RemoveAll();
	for (int i = 0; i < m_RefText2.m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_RefText2.m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_RefText2.m_aDrawObj.RemoveAll();
	cout << "소멸자 ~CRef() 호출" << endl;
}
void CRef::vSetRef(int nLibPartNo, string sReferenceName, string sPlacedLayer, double dPtX, double dPtY, double dAngle, double dECADAngle, char cPassiveType, double dPassiveValue
	, bool bReferenceTextReversePlaced, bool bExistInBom, CRefText RefText, CPinConnectionStatusArray aPinConnectionStatus, CRefText2 RefText2, string sreferenceThermalCondition, CPropertysArray aProperty)
{
	for (int i = 0; i < m_aPinConnectionStatus.GetSize(); i++)
	{
		CPinConnectionStatus * pItem = m_aPinConnectionStatus.GetAt(i);
		delete pItem;
	}
	m_aPinConnectionStatus.RemoveAll();
	for (int i = 0; i < m_aProperty.GetSize(); i++)
	{
		CPropertys * pItem = m_aProperty.GetAt(i);
		delete pItem;
	}
	m_aProperty.RemoveAll();
	for (int i = 0; i < m_RefText2.m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_RefText2.m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_RefText2.m_aDrawObj.RemoveAll();

	m_nLibPartNo = nLibPartNo;
	m_sReferenceName = sReferenceName;
	m_sPlacedLayer = sPlacedLayer;
	m_dPtX = dPtX;
	m_dPtY = dPtY;
	m_dAngle = dAngle;
	m_dECADAngle = dECADAngle;
	m_dPassiveValue = dPassiveValue;
	m_cPassiveType = cPassiveType;
	m_bReferenceTextReversePlaced = bReferenceTextReversePlaced;
	m_bExistInBom = bExistInBom;
	for (int i = 0; i < RefText2.m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = RefText2.m_aDrawObj.GetAt(i);
		m_RefText2.m_aDrawObj.Add(pItem->clone());
		delete pItem;
	}
	for (int i = 0; i < aPinConnectionStatus.GetSize(); i++)
	{
		CPinConnectionStatus * pItem = aPinConnectionStatus.GetAt(i);
		m_aPinConnectionStatus.Add(pItem->clone());
		delete pItem;
	}	
	for (int i = 0; i < aProperty.GetSize(); i++)
	{
		CPropertys * pItem = aProperty.GetAt(i);
		m_aProperty.Add(pItem->clone());
		delete pItem;
	}
	m_sReferenceThermalCondition = sreferenceThermalCondition;
}
CRef& CRef::operator =(const CRef& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < m_aPinConnectionStatus.GetSize(); i++)
	{
		CPinConnectionStatus * pItem = m_aPinConnectionStatus.GetAt(i);
		delete pItem;
	}
	m_aPinConnectionStatus.RemoveAll();
	for (int i = 0; i < m_aProperty.GetSize(); i++)
	{
		CPropertys * pItem = m_aProperty.GetAt(i);
		delete pItem;
	}
	m_aProperty.RemoveAll();
	for (int i = 0; i < m_RefText2.m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_RefText2.m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_RefText2.m_aDrawObj.RemoveAll();

	m_nLibPartNo = rhs.m_nLibPartNo;
	m_sReferenceName = rhs.m_sReferenceName;
	m_sPlacedLayer = rhs.m_sPlacedLayer;
	m_dPtX = rhs.m_dPtX;
	m_dPtY = rhs.m_dPtY;
	m_dAngle = rhs.m_dAngle;
	m_dECADAngle = rhs.m_dECADAngle;
	m_dPassiveValue = rhs.m_dPassiveValue;
	m_cPassiveType = rhs.m_cPassiveType;
	m_bReferenceTextReversePlaced = rhs.m_bReferenceTextReversePlaced;
	m_bExistInBom = rhs.m_bExistInBom;
	for (int i = 0; i < rhs.m_RefText2.m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = rhs.m_RefText2.m_aDrawObj.GetAt(i);
		m_RefText2.m_aDrawObj.Add(pItem->clone());
	}
	for (int i = 0; i < rhs.m_aPinConnectionStatus.GetSize(); i++)
	{
		CPinConnectionStatus * pItem = rhs.m_aPinConnectionStatus.GetAt(i);
		m_aPinConnectionStatus.Add(pItem->clone());
	}
	for (int i = 0; i < rhs.m_aProperty.GetSize(); i++)
	{
		CPropertys * pItem = rhs.m_aProperty.GetAt(i);
		m_aProperty.Add(pItem->clone());
	}
	m_sReferenceThermalCondition = rhs.m_sReferenceThermalCondition;
	return *this;
}


BOOL CRef::operator==(const CRef & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CRef::operator!=(const CRef& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CRef* CRef::clone()
{
	return new CRef(*this);

}

// const int CRef::m_nVersion = 1;


CRefArray::CRefArray()
{
}
CRefArray::CRefArray(const CRefArray& src)
{
	*this = src;
}
CRefArray::~CRefArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CRef * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CRefArray& CRefArray::operator =(const CRefArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CRef * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();


	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CRef* pItem = new CRef();
		pItem->m_sReferenceThermalCondition = rhs[i]->m_sReferenceThermalCondition;
		pItem->m_sReferenceName = rhs[i]->m_sReferenceName;
		pItem->m_sPlacedLayer = rhs[i]->m_sPlacedLayer;
		pItem->m_RefText2 = rhs[i]->m_RefText2;
		pItem->m_RefText = rhs[i]->m_RefText;
		pItem->m_nLibPartNo = rhs[i]->m_nLibPartNo;
		pItem->m_dPtY = rhs[i]->m_dPtY;
		pItem->m_dPtX = rhs[i]->m_dPtX;
		pItem->m_dPassiveValue = rhs[i]->m_dPassiveValue;
		pItem->m_dECADAngle = rhs[i]->m_dECADAngle;
		pItem->m_dAngle = rhs[i]->m_dAngle;
		pItem->m_cPassiveType = rhs[i]->m_cPassiveType;
		pItem->m_bReferenceTextReversePlaced = rhs[i]->m_bReferenceTextReversePlaced;
		pItem->m_bExistInBom = rhs[i]->m_bExistInBom;
		for (int j = 0; j < rhs[i]->m_aPinConnectionStatus.GetSize(); j++)
		{
			CPinConnectionStatus* pItem2 = new CPinConnectionStatus();
			pItem2->m_nPinNo = rhs[i]->m_aPinConnectionStatus.GetAt(j)->m_nPinNo;
			for (int k = 0; k < rhs[i]->m_aPinConnectionStatus[j]->m_asConnectionStatus.GetSize(); k++)
			{
				pItem2->m_asConnectionStatus.Add(rhs[i]->m_aPinConnectionStatus.GetAt(j)->m_asConnectionStatus.GetAt(k));
			}
			pItem->m_aPinConnectionStatus.Add(pItem2->clone());
		}
		for (int j = 0; j < rhs[i]->m_aProperty.GetSize(); j++)
		{
			CPropertys* pItem2 = new CPropertys();
			pItem2->m_sPropertyContents = rhs[i]->m_aProperty.GetAt(j)->m_sPropertyContents;
			pItem2->m_sPropertyItem = rhs[i]->m_aProperty.GetAt(j)->m_sPropertyItem;

			pItem->m_aProperty.Add(pItem2->clone());
		}
		this->Add(pItem->clone());
	}

	return *this;
}

bool CRefArray::operator==(const CRefArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CRef* pItem1;
	CRef* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CRefArray::operator!=(const CRefArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CRefArray* CRefArray::clone()
{
	return new CRefArray(*this);

}