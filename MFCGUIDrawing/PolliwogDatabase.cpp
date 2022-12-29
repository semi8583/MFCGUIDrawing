#include "stdafx.h"
#include "PolliwogDatabase.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPolliwogDatabase::CPolliwogDatabase()
{
	cout << "������ CPolliwogDatabase() ȣ��" << endl;
}
CPolliwogDatabase::CPolliwogDatabase(const CPolliwogDatabase& src)
{
	*this = src;
}
CPolliwogDatabase::~CPolliwogDatabase()
{
	cout << "�Ҹ��� ~CPolliwogDatabase() ȣ��" << endl;
}
void CPolliwogDatabase::vSetPolliwogDatabase(int nMinorVersionNum)
{
	this->m_nMinorVersionNum = nMinorVersionNum;
}
void CPolliwogDatabase::vSetVersion(string sVersion)
{
	this->m_sVersion = sVersion;
}
CPolliwogDatabase& CPolliwogDatabase::operator =(const CPolliwogDatabase& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_nMinorVersionNum = rhs.m_nMinorVersionNum;
	this->m_sVersion = rhs.m_sVersion;
	// Add code to serialize member variable
	return *this;
}


BOOL CPolliwogDatabase::operator==(const CPolliwogDatabase & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPolliwogDatabase::operator!=(const CPolliwogDatabase& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPolliwogDatabase* CPolliwogDatabase::clone()
{
	return new CPolliwogDatabase(*this);

}
// const int CPolliwogDatabase::m_nVersion = 1;