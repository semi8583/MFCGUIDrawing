#include "stdafx.h"
#include "RigidFlexiblePcb.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CRigidFlexiblePcb::CRigidFlexiblePcb()
{
	cout << "생성자 CRigidFlexiblePcb() 호출" << endl;
}
CRigidFlexiblePcb::CRigidFlexiblePcb(const CRigidFlexiblePcb& src)
{
	*this = src;
}
CRigidFlexiblePcb:: ~CRigidFlexiblePcb()
{
	cout << "소멸자 ~CRigidFlexiblePcb() 호출" << endl;
}
void CRigidFlexiblePcb::vSetCRigidFlexiblePcb(CFlexibleAreas FlexibleAreas)
{
	m_FlexibleAreas = FlexibleAreas;
}
CRigidFlexiblePcb& CRigidFlexiblePcb::operator =(const CRigidFlexiblePcb& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_FlexibleAreas = rhs.m_FlexibleAreas;
	// Add code to serialize member variable
	return *this;
}


BOOL CRigidFlexiblePcb::operator==(const CRigidFlexiblePcb & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CRigidFlexiblePcb::operator!=(const CRigidFlexiblePcb& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CRigidFlexiblePcb* CRigidFlexiblePcb::clone()
{
	return new CRigidFlexiblePcb(*this);

}
// const int CRigidFlexiblePcb::m_nVersion = 1;