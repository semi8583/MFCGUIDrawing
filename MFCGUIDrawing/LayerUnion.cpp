#include "stdafx.h"
#include "LayerUnion.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CLayerUnion::CLayerUnion()
{
	cout << "������ CLayerUnion() ȣ��" << endl;
}
CLayerUnion::CLayerUnion(const CLayerUnion& src)
{
	*this = src;
}
CLayerUnion::~CLayerUnion()
{
	cout << "�Ҹ��� ~CLayerUnion() ȣ��" << endl;
}
void CLayerUnion::vSetCLayerUnion(CAlu Alu)
{
	m_Alu = Alu;
}
CLayerUnion& CLayerUnion::operator =(const CLayerUnion& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_Alu = rhs.m_Alu;
	// Add code to serialize member variable
	return *this;
}


BOOL CLayerUnion::operator==(const CLayerUnion & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CLayerUnion::operator!=(const CLayerUnion& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLayerUnion* CLayerUnion::clone()
{
	return new CLayerUnion(*this);

}
//const int CLayerUnion::m_nVersion = 1;