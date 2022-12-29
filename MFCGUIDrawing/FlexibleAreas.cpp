#include "stdafx.h"
#include "FlexibleAreas.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CFlexibleAreas::CFlexibleAreas()
{
	cout << "생성자 CFlexibleAreas() 호출" << endl;
}
CFlexibleAreas::CFlexibleAreas(const CFlexibleAreas& src)
{
	*this = src;
}
CFlexibleAreas::~CFlexibleAreas()
{
	cout << "소멸자 ~CFlexibleAreas() 호출" << endl;
}
void CFlexibleAreas::vSetCFlexibleAreas(CFlexibleArea FlexibleArea)
{
	m_FlexibleArea = FlexibleArea;
}
CFlexibleAreas& CFlexibleAreas::operator =(const CFlexibleAreas& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_FlexibleArea = rhs.m_FlexibleArea;
	// Add code to serialize member variable
	return *this;
}


BOOL CFlexibleAreas::operator==(const CFlexibleAreas & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CFlexibleAreas::operator!=(const CFlexibleAreas& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CFlexibleAreas* CFlexibleAreas::clone()
{
	return new CFlexibleAreas(*this);

}
//const int CFlexibleAreas::m_nVersion = 1;