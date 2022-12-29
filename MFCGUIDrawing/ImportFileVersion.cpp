#include "stdafx.h"
#include "ImportFileVersion.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CImportFileVersion::CImportFileVersion()
{
	cout << "생성자 CImportFileVersion() 호출" << endl;
}
CImportFileVersion::CImportFileVersion(const CImportFileVersion& src)
{
	*this = src;
}
CImportFileVersion::~CImportFileVersion()
{
	cout << "소멸자 ~CImportFileVersion() 호출" << endl;
}
void CImportFileVersion::vSetCImportFileVersion(string sECADTypeName, int nMajorVerNum, int nMinorVerNum)
{
	m_sECADTypeName = sECADTypeName;
	m_nMajorVerNum = nMajorVerNum;
	m_nMinorVerNum = nMinorVerNum;
}
CImportFileVersion& CImportFileVersion::operator =(const CImportFileVersion& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_nMajorVerNum = rhs.m_nMajorVerNum;
	this->m_nMinorVerNum = rhs.m_nMinorVerNum;
	this->m_sECADTypeName = rhs.m_sECADTypeName;
	// Add code to serialize member variable
	return *this;
}


BOOL CImportFileVersion::operator==(const CImportFileVersion & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CImportFileVersion::operator!=(const CImportFileVersion& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CImportFileVersion* CImportFileVersion::clone()
{
	return new CImportFileVersion(*this);

}
//const int CImportFileVersion::m_nVersion = 1;