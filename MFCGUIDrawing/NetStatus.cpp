#include "stdafx.h"
#include "NetStatus.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CNetStatus::CNetStatus()
{
	cout << "생성자 CNetStatus() 호출" << endl;
}
CNetStatus::CNetStatus(const CNetStatus& src)
{
	*this = src;
}
CNetStatus::~CNetStatus()
{
	cout << "소멸자 ~CNetStatus() 호출" << endl;
}
void CNetStatus::vSetNetStatus(int nST1, int nST2, int nST3, int nST4)
{
	this->m_nST1 = nST1;
	this->m_nST2 = nST2;
	this->m_nST3 = nST3;
	this->m_nST4 = nST4;
}
CNetStatus& CNetStatus::operator =(const CNetStatus& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_nST1 = rhs.m_nST1;
	this->m_nST2 = rhs.m_nST2;
	this->m_nST3 = rhs.m_nST3;
	this->m_nST4 = rhs.m_nST4;
	// Add code to serialize member variable
	return *this;
}


BOOL CNetStatus::operator==(const CNetStatus & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CNetStatus::operator!=(const CNetStatus& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNetStatus* CNetStatus::clone()
{
	return new CNetStatus(*this);

}
// const int CNetStatus::m_nVersion = 1;