#pragma once
#include <iostream>
#include "stdafx.h"
#include "PolliwogDatabase.h"
#include "ImportFileVersion.h"
#include "Unit.h"
#include "Unitscale.h"
#include "Author.h"
#include "Date.h"
#include "FilePath.h"
#include "sInterfaceFilePath.h"
#include "Comment.h"
#include "LibRaryPartPath.h"
using namespace std;

class CPolliwogDatabase;
class CImportFileVersion;
class CUnit;
class CUnitscale;
class CAuthor;
class CDate;
class CFilePath;
class CInterfaceFilePath;
class CComment;
class CLibRaryPartPath;


class CInformation {
public:
	CPolliwogDatabase m_PolliwogDatabase;
	CImportFileVersion m_ImportFileVersion;
	CUnit m_Unit;
	CUnitscale m_Unitscale;
	CAuthor m_Author;
	CDate m_Date;
	CFilePath m_FilePath;
	CInterfaceFilePath m_InterfaceFilePath;
	CComment m_Comment;
	CLibRaryPartPath m_LibRaryPartPath;
public:
	CInformation();
	CInformation(const CInformation& src);
	virtual ~CInformation();
	void vSetCImportFileVersion(CImportFileVersion ImportFileVersion);
	void vSetCUnit(CUnit Unit);
	void vSetCUnitscale(CUnitscale Unitscale);
	void vSetCAuthor(CAuthor Author);
	void vSetCDate(CDate Date);
	void vSetCFilePath(CFilePath FilePath);
	void vSetCComment(CComment Comment);
	virtual CInformation & operator =(const CInformation & rhs);
	virtual BOOL operator==(const CInformation & rhs);
	BOOL operator!=(const CInformation & rhs);
	virtual CInformation* clone();
//	virtual CInformation* clone() const { return new CInformation(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};
