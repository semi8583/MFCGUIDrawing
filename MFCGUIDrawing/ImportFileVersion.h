#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CImportFileVersion
{
public:
	string m_sECADTypeName;
	int m_nMajorVerNum, m_nMinorVerNum;
public:
	CImportFileVersion();
	CImportFileVersion(const CImportFileVersion& src);
	virtual ~CImportFileVersion();
	void vSetCImportFileVersion(string sECADTypeName, int nMajorVerNum, int nMinorVerNum);
	virtual CImportFileVersion & operator =(const CImportFileVersion & rhs);
	virtual BOOL operator==(const CImportFileVersion & rhs);
	BOOL operator!=(const CImportFileVersion & rhs);
	virtual CImportFileVersion* clone();
//	virtual CImportFileVersion* clone() const { return new CImportFileVersion(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};
