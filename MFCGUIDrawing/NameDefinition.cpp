#include "stdafx.h"
#include "NameDefinition.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CNameDefinition::CNameDefinition()
{
	cout << "생성자 CNameDefinition() 호출" << endl;
}
CNameDefinition::CNameDefinition(const CNameDefinition& src)
{
	*this = src;
}
CNameDefinition::~CNameDefinition()
{
	cout << "소멸자 ~CNameDefinition() 호출" << endl;
}
void CNameDefinition::vSetNamedefinition(string sPartName, string sEcadPartName, string sPackageName, string sDeviceName, string sFunctionName, string sPackageType, string sReferencePrefix,
	string sPlaceableLayer, string sFootPrintName)
{
	this->m_sPartName = sPartName;
	this->m_sEcadPartName = sEcadPartName;
	this->m_sPackageName = sPackageName;
	this->m_sDeviceName = sDeviceName;
	this->m_sFunctionName = sFunctionName;
	this->m_sPackageType = sPackageType;
	this->m_sReferencePrefix = sReferencePrefix;
	this->m_sPlaceableLayer = sPlaceableLayer;
	this->m_sFootPrintName = sFootPrintName;
}
CNameDefinition& CNameDefinition::operator =(const CNameDefinition& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_sPartName = rhs.m_sPartName;
	this->m_sEcadPartName = rhs.m_sEcadPartName;
	this->m_sPackageName = rhs.m_sPackageName;
	this->m_sDeviceName = rhs.m_sDeviceName;
	this->m_sFunctionName = rhs.m_sFunctionName;
	this->m_sPackageType = rhs.m_sPackageType;
	this->m_sReferencePrefix = rhs.m_sReferencePrefix;
	this->m_sPlaceableLayer = rhs.m_sPlaceableLayer;
	this->m_sFootPrintName = rhs.m_sFootPrintName;
	// Add code to serialize member variable
	return *this;
}


BOOL CNameDefinition::operator==(const CNameDefinition & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CNameDefinition::operator!=(const CNameDefinition& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CNameDefinition* CNameDefinition::clone()
{
	return new CNameDefinition(*this);

}
// const int CNameDefinition::m_nVersion = 1;