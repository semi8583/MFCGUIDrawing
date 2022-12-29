#include "stdafx.h"
#include "DrawingArea.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CDrawingArea::CDrawingArea()
{
	cout << "생성자 CDrawingArea() 호출" << endl;
}
CDrawingArea::CDrawingArea(const CDrawingArea& src)
{
	*this = src;
}
CDrawingArea:: ~CDrawingArea()
{
	cout << "소멸자 ~CDrawingArea() 호출" << endl;
}
void CDrawingArea::vSetCDrawingArea(double dLowLeftMinX, double dLowLeftMaxY,
	double dUpperRightX, double dUpperRightY)
{
	m_dLowLeftMinX = dLowLeftMinX;
	m_dLowLeftMaxY = dLowLeftMaxY;
	m_dUpperRightX = dUpperRightX;
	m_dUpperRightY = dUpperRightY;
}
CDrawingArea& CDrawingArea::operator =(const CDrawingArea& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_dLowLeftMaxY = rhs.m_dLowLeftMaxY;
	this->m_dLowLeftMinX = rhs.m_dLowLeftMinX;
	this->m_dUpperRightX = rhs.m_dUpperRightX;
	this->m_dUpperRightY = rhs.m_dUpperRightY;
	// Add code to serialize member variable
	return *this;
}


BOOL CDrawingArea::operator==(const CDrawingArea & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CDrawingArea::operator!=(const CDrawingArea& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CDrawingArea* CDrawingArea::clone()
{
	return new CDrawingArea(*this);

}
//const int CDrawingArea::m_nVersion = 1;