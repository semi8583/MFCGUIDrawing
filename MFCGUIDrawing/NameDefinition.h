#pragma once
#include <iostream>
using namespace std;

class CNameDefinition
{
public:
	string m_sPartName, m_sEcadPartName, m_sPackageName, m_sDeviceName, m_sFunctionName, m_sPackageType, m_sReferencePrefix, m_sPlaceableLayer, m_sFootPrintName;
public:
	CNameDefinition();
	CNameDefinition(const CNameDefinition& src);
	virtual ~CNameDefinition();
	void vSetNamedefinition(string sPartName, string sEcadPartName, string sPackageName, string sDeviceName, string sFunctionName, string sPackageType, string sReferencePrefix,
		string sPlaceableLayer, string sFootPrintName);
	virtual CNameDefinition & operator =(const CNameDefinition & rhs);
	virtual BOOL operator==(const CNameDefinition & rhs);
	BOOL operator!=(const CNameDefinition & rhs);

	virtual CNameDefinition*clone();
	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};

