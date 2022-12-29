#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CFilePath
{
public:
	string m_sOrigianlEcadFilePath;
public:
	CFilePath();
	CFilePath(const CFilePath& src);
	virtual ~CFilePath();
	void vSetCFilePath(string sOrigianlEcadFilePath);
	virtual CFilePath & operator =(const CFilePath & rhs);
	virtual BOOL operator==(const CFilePath & rhs);
	BOOL operator!=(const CFilePath & rhs);
	virtual CFilePath* clone();
//	virtual CFilePath* clone() const { return new CFilePath(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};
