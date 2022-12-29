#include "stdafx.h"
#include "FlexibleArea.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC

#endif
CFlexibleArea::CFlexibleArea()
{
	m_dMinX = NULL, m_dMinY = NULL, m_dMaxX = NULL, m_dMaxY = NULL, m_dTopCoverlayThickness = NULL, m_dBottomCoverlayThickness = NULL;
	cout << "생성자 CFlexibleArea() 호출" << endl;
}
CFlexibleArea::CFlexibleArea(const CFlexibleArea& src)
{
	*this = src;
}
CFlexibleArea::~CFlexibleArea()
{
	cout << "소멸자 ~CFlexibleArea() 호출" << endl;
}
void CFlexibleArea::vSetCFlexibleArea(double dMinX, double dMinY, double dMaxX, double dMaxY, double  dTopLayerName, double dBottomLayerName,
	string sCoverlayMaterialName, double dTopCoverlayThickness, double dBottomCoverlayThickness)
{
	m_dMinX = dMinX;
	m_dMinY = dMinY;
	m_dMaxX = dMaxX;
	m_dMaxY = dMaxY;
	m_sTopLayerName = dTopLayerName;
	m_sBottomLayerName = dBottomLayerName;
	m_sCoverlayMaterialName = sCoverlayMaterialName;
	m_dTopCoverlayThickness = dTopCoverlayThickness;
	m_dBottomCoverlayThickness = dBottomCoverlayThickness;
}
CFlexibleArea& CFlexibleArea::operator =(const CFlexibleArea& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_dBottomCoverlayThickness = rhs.m_dBottomCoverlayThickness;
	this->m_dMaxX = rhs.m_dMaxX;
	this->m_dMaxY = rhs.m_dMaxY;
	this->m_dMinX = rhs.m_dMinX;
	this->m_dMinY = rhs.m_dMinY;
	this->m_dTopCoverlayThickness = rhs.m_dTopCoverlayThickness;
	this->m_sBottomLayerName = rhs.m_sBottomLayerName;
	this->m_sCoverlayMaterialName = rhs.m_sCoverlayMaterialName;
	this->m_sTopLayerName = rhs.m_sTopLayerName;
	// Add code to serialize member variable
	return *this;
}


BOOL CFlexibleArea::operator==(const CFlexibleArea & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CFlexibleArea::operator!=(const CFlexibleArea& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CFlexibleArea* CFlexibleArea::clone()
{
	return new CFlexibleArea(*this);

}
//const int CFlexibleArea::m_nVersion = 1;