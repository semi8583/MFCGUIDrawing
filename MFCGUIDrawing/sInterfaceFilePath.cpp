#include "stdafx.h"
#include "sInterfaceFilePath.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CInterfaceFilePath::CInterfaceFilePath()
{
	cout << "������ CInterfaceFilePath() ȣ��" << endl;
}
CInterfaceFilePath::CInterfaceFilePath(const CInterfaceFilePath& src)
{
	*this = src;
}
CInterfaceFilePath::~CInterfaceFilePath()
{
	cout << "�Ҹ��� ~CInterfaceFilePath() ȣ��" << endl;
}
void CInterfaceFilePath::vSetCInterfaceFilePath(string sInterfaceFilePath)
{
	m_sInterfaceFilePath = sInterfaceFilePath;
}
CInterfaceFilePath& CInterfaceFilePath::operator =(const CInterfaceFilePath& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_sInterfaceFilePath = rhs.m_sInterfaceFilePath;
	// Add code to serialize member variable
	return *this;
}


BOOL CInterfaceFilePath::operator==(const CInterfaceFilePath & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CInterfaceFilePath::operator!=(const CInterfaceFilePath& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CInterfaceFilePath* CInterfaceFilePath::clone()
{
	return new CInterfaceFilePath(*this);

}
//const int CInterfaceFilePath::m_nVersion = 1;