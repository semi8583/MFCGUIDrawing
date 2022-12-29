#include "stdafx.h"
#include "Wing.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CWing::CWing()
{
	cout << "������ CWing() ȣ��" << endl;
}
CWing::CWing(const CWing& src)
{
	*this = src;
}
CWing::~CWing()
{
	cout << "�Ҹ��� ~CWing() ȣ��" << endl;
}
void CWing::vSetCWing(double dWingAngle, double dWingDistance, int nWingCount, int nWingCount1, int nWingCount2, int nWingCount3, int nWingCount4)
{
	this->m_dWingAngle = dWingAngle;
	this->m_dWingDistance = dWingDistance;
	this->m_nWingCount1 = nWingCount1;
	this->m_nWingCount2 = nWingCount2;
	this->m_nWingCount3 = nWingCount3;
	this->m_nWingCount4 = nWingCount4;
}
CWing& CWing::operator =(const CWing& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_dWingAngle = rhs.m_dWingAngle;
	this->m_dWingDistance = rhs.m_dWingDistance;
	this->m_nWingCount1 = rhs.m_nWingCount1;
	this->m_nWingCount2 = rhs.m_nWingCount2;
	this->m_nWingCount3 = rhs.m_nWingCount3;
	this->m_nWingCount4 = rhs.m_nWingCount4;
	// Add code to serialize member variable
	return *this;
}


BOOL CWing::operator==(const CWing & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CWing::operator!=(const CWing& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CWing* CWing::clone() // ��������ڸ� Ȱ���� Clone()�Լ�
{
	return new CWing(*this); // ������ ������ ���ο� ��ü�� �����Ҵ��� �ּҸ� ��ȯ

}
//const int CWing::m_nVersion = 1;