#include "stdafx.h"
#include "Lay.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CLay::CLay()
{
	cout << "생성자 CLay() 호출" << endl;
}
CLay::CLay(const CLay& src)
{
	*this = src;
}
CLay:: ~CLay()
{
	cout << "소멸자 ~CLay() 호출" << endl;
}
void CLay::vSetLibLayer(int nLibArtworkLayNo, int nEcadLayNum, int nPhysicalLayNo, string sLayerName,
	string sLayerType, string sNetName, string sPolarity, string sComment, int nRed,
	int nGreen, int nBlue)
{
	m_nLibArtworkLayNo = nLibArtworkLayNo;
	m_nEcadLayNum = nEcadLayNum;
	m_nPhysicalLayNo = nPhysicalLayNo;
	m_sLayerName = sLayerName;
	m_sLayerType = sLayerType;
	m_sNetName = sNetName;
	m_sPolarity = sPolarity;
	m_sComment = sComment;
	m_nRed = nRed;
	m_nGreen = nGreen;
	m_nBlue = nBlue;
}
CLay& CLay::operator =(const CLay& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_nBlue = rhs.m_nBlue;
	this->m_nEcadLayNum = rhs.m_nEcadLayNum;
	this->m_nGreen = rhs.m_nGreen;
	this->m_nLibArtworkLayNo = rhs.m_nLibArtworkLayNo;
	this->m_nPhysicalLayNo = rhs.m_nPhysicalLayNo;
	this->m_nRed = rhs.m_nRed;
	this->m_sComment = rhs.m_sComment;
	this->m_sLayerName = rhs.m_sLayerName;
	this->m_sLayerType = rhs.m_sLayerType;
	this->m_sNetName = rhs.m_sNetName;
	this->m_sPolarity = rhs.m_sPolarity;
	// Add code to serialize member variable
	return *this;
}


BOOL CLay::operator==(const CLay & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CLay::operator!=(const CLay& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLay* CLay::clone()
{
	return new CLay(*this);

}
//const int CLay::m_nVersion = 1;


CLayArray::CLayArray()
{
}
CLayArray::CLayArray(const CLayArray& src)
{
	*this = src;
}

CLayArray::~CLayArray()
{
	for (int i = 0; GetSize(); i++)
	{
		CLay* pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CLayArray& CLayArray::operator =(const CLayArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; GetSize(); i++)
	{
		CLay* pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CLay* pItem = new CLay();
		pItem->m_nBlue = rhs.GetAt(i)->m_nBlue;
		pItem->m_nEcadLayNum = rhs.GetAt(i)->m_nEcadLayNum;
		pItem->m_nGreen = rhs.GetAt(i)->m_nGreen;
		pItem->m_nLibArtworkLayNo = rhs.GetAt(i)->m_nLibArtworkLayNo;
		pItem->m_nPhysicalLayNo = rhs.GetAt(i)->m_nPhysicalLayNo;
		pItem->m_nRed = rhs.GetAt(i)->m_nRed;
		pItem->m_sComment = rhs.GetAt(i)->m_sComment;
		pItem->m_sLayerName = rhs.GetAt(i)->m_sLayerName;
		pItem->m_sLayerType = rhs.GetAt(i)->m_sLayerType;
		pItem->m_sNetName = rhs.GetAt(i)->m_sNetName;
		pItem->m_sPolarity = rhs.GetAt(i)->m_sPolarity;
		this->Add(pItem->clone());
	}

	return *this;
}

bool CLayArray::operator==(const CLayArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CLay* pItem1;
	CLay* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CLayArray::operator!=(const CLayArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLayArray* CLayArray::clone()
{
	return new CLayArray(*this);

}