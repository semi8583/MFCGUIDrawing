#include "stdafx.h"
#include "LibRaryPartPath.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CLibRaryPartPath::CLibRaryPartPath()
{
	cout << "������ CLibRaryPartPath() ȣ��" << endl;
}
CLibRaryPartPath::CLibRaryPartPath(const CLibRaryPartPath& src)
{
	*this = src;
}
CLibRaryPartPath::~CLibRaryPartPath()
{
	cout << "�Ҹ��� ~CLibRaryPartPath() ȣ��" << endl;
}
void CLibRaryPartPath::vSetCLibRaryPartPath(string sLibRaryPartPath)
{
	m_sLibRaryPartPath = sLibRaryPartPath;
}
CLibRaryPartPath& CLibRaryPartPath::operator =(const CLibRaryPartPath& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_sLibRaryPartPath = rhs.m_sLibRaryPartPath;
	// Add code to serialize member variable
	return *this;
}


BOOL CLibRaryPartPath::operator==(const CLibRaryPartPath & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CLibRaryPartPath::operator!=(const CLibRaryPartPath& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLibRaryPartPath* CLibRaryPartPath::clone()
{
	return new CLibRaryPartPath(*this);

}
//const int CLibRaryPartPath::m_nVersion = 1;