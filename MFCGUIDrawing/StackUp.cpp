#include "stdafx.h"
#include "StackUp.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CStackUp::CStackUp()
{
	cout << "생성자 CStackUp() 호출" << endl;
}
CStackUp::CStackUp(const CStackUp& src)
{
	*this = src;
}
CStackUp::~CStackUp()
{
	cout << "소멸자 ~CStackUp() 호출" << endl;
}
void CStackUp::vSetCStackUp(string sLayerType, int nArtworkLayNo, int nPhysicalLayerNo, string sConductingMaterial
	, string sDielectricMaterial, double dThickness, double dTraceWidthDifference, int nWiderTraceSide)
{
	this->m_sLayerType = sLayerType;
	this->m_nArtworkLayNo = nArtworkLayNo;
	this->m_nPhysicalLayerNo = nPhysicalLayerNo;
	this->m_sConductingMaterial = sConductingMaterial;
	this->m_sDielectricMaterial = sDielectricMaterial;
	this->m_dThickness = dThickness;
	this->m_dTraceWidthDifference = dTraceWidthDifference;
	this->m_nWiderTraceSide = nWiderTraceSide;
}
CStackUp& CStackUp::operator =(const CStackUp& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_sLayerType = rhs.m_sLayerType;
	this->m_nArtworkLayNo = rhs.m_nArtworkLayNo;
	this->m_nPhysicalLayerNo = rhs.m_nPhysicalLayerNo;
	this->m_sConductingMaterial = rhs.m_sConductingMaterial;
	this->m_sDielectricMaterial = rhs.m_sDielectricMaterial;
	this->m_dThickness = rhs.m_dThickness;
	this->m_dTraceWidthDifference = rhs.m_dTraceWidthDifference;
	this->m_nWiderTraceSide = rhs.m_nWiderTraceSide;
	// Add code to serialize member variable
	return *this;
}


BOOL CStackUp::operator==(const CStackUp & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CStackUp::operator!=(const CStackUp& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CStackUp* CStackUp::clone()
{
	return new CStackUp(*this);

}
// const int CStackUp::m_nVersion = 1;

CStackUpArray::CStackUpArray()
{
}
CStackUpArray::CStackUpArray(const CStackUpArray& src)
{
	*this = src;
}
CStackUpArray::~CStackUpArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CStackUp * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CStackUpArray& CStackUpArray::operator =(const CStackUpArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CStackUp * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CStackUp* pItem = new CStackUp();
		pItem->m_dThickness = rhs.GetAt(i)->m_dThickness;
		pItem->m_dTraceWidthDifference = rhs.GetAt(i)->m_dTraceWidthDifference;
		pItem->m_nArtworkLayNo = rhs.GetAt(i)->m_nArtworkLayNo;
		pItem->m_nPhysicalLayerNo = rhs.GetAt(i)->m_nPhysicalLayerNo;
		pItem->m_nWiderTraceSide = rhs.GetAt(i)->m_nWiderTraceSide;
		pItem->m_sConductingMaterial = rhs.GetAt(i)->m_sConductingMaterial;
		pItem->m_sDielectricMaterial = rhs.GetAt(i)->m_sDielectricMaterial;
		pItem->m_sLayerType = rhs.GetAt(i)->m_sLayerType;
		this->Add(pItem->clone());

	}
	return *this;
}

bool CStackUpArray::operator==(const CStackUpArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CStackUp* pItem1;
	CStackUp* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CStackUpArray::operator!=(const CStackUpArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CStackUpArray* CStackUpArray::clone()
{
	return new CStackUpArray(*this);

}