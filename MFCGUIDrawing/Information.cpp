#include "stdafx.h"
#include "Information.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CInformation::CInformation()
{
	cout << "생성자 CInformation() 호출" << endl;
}
CInformation::CInformation(const CInformation& src)
{
	*this = src;
}
CInformation::~CInformation()
{
	cout << "소멸자 ~CInformation() 호출" << endl;
}
void CInformation::vSetCImportFileVersion(CImportFileVersion ImportFileVersion)
{
	m_ImportFileVersion = ImportFileVersion;
}
void CInformation::vSetCUnit(CUnit Unit)
{
	m_Unit = Unit;
}
void CInformation::vSetCUnitscale(CUnitscale Unitscale)
{
	m_Unitscale = Unitscale;
}
void CInformation::vSetCAuthor(CAuthor Author)
{
	m_Author = Author;
}
void CInformation::vSetCDate(CDate Date)
{
	m_Date = Date;
}
void CInformation::vSetCFilePath(CFilePath FilePath)
{
	m_FilePath = FilePath;
}
void CInformation::vSetCComment(CComment Comment)
{
	m_Comment = Comment;
}
CInformation& CInformation::operator =(const CInformation& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_Author = rhs.m_Author;
	this->m_Comment = rhs.m_Comment;
	this->m_Date = rhs.m_Date;
	this->m_FilePath = rhs.m_FilePath;
	this->m_ImportFileVersion = rhs.m_ImportFileVersion;
	this->m_InterfaceFilePath = rhs.m_InterfaceFilePath;
	this->m_LibRaryPartPath = rhs.m_LibRaryPartPath;
	this->m_PolliwogDatabase = rhs.m_PolliwogDatabase;
	this->m_Unit = rhs.m_Unit;
	this->m_Unitscale = rhs.m_Unitscale;
	// Add code to serialize member variable
	return *this;
}


BOOL CInformation::operator==(const CInformation & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CInformation::operator!=(const CInformation& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CInformation* CInformation::clone()
{
	return new CInformation(*this);

}
//const int CInformation::m_nVersion = 1;