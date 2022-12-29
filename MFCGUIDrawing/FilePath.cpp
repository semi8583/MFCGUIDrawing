#include "stdafx.h"
#include "FilePath.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CFilePath::CFilePath()
{
	cout << "생성자 CFilePath() 호출" << endl;
}
CFilePath::CFilePath(const CFilePath& src)
{
	*this = src;
}
CFilePath::~CFilePath()
{
	cout << "소멸자 ~CFilePath() 호출" << endl;
}
void CFilePath::vSetCFilePath(string sOrigianlEcadFilePath)
{
	m_sOrigianlEcadFilePath = sOrigianlEcadFilePath;
}
CFilePath& CFilePath::operator =(const CFilePath& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_sOrigianlEcadFilePath = rhs.m_sOrigianlEcadFilePath;
	// Add code to serialize member variable
	return *this;
}


BOOL CFilePath::operator==(const CFilePath & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CFilePath::operator!=(const CFilePath& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CFilePath* CFilePath::clone()
{
	return new CFilePath(*this);

}
//const int CFilePath::m_nVersion = 1;