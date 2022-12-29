#pragma once
#include <iostream>


#include "ReferenceList.h"
#include "NetList.h"
#include "CompositeNet.h"
#include "NetBusGroupList.h"
#include "NetClassList.h"
using namespace std;

class CNetListRefdesList
{
public:
	CReferenceList m_ReferenceList;
	CNetList m_NetList;
	CCompositeNet m_CompositeNet;
	CNetBusGroupList m_NetBusGroupList;
	CNetClassListArray m_aNetClassList;
public:
	CNetListRefdesList();
	CNetListRefdesList(const CNetListRefdesList& src);
	virtual ~CNetListRefdesList();
	void vSetCNetListRefdesList(CReferenceList ReferenceList, CNetList NetList, CCompositeNet CompositeNet, CNetBusGroupList NetBusGroupList, CNetClassListArray aNetClassList);
	virtual CNetListRefdesList & operator =(const CNetListRefdesList & rhs);
	virtual BOOL operator==(const CNetListRefdesList & rhs);
	BOOL operator!=(const CNetListRefdesList & rhs);
	virtual CNetListRefdesList* clone();
//	virtual CNetListRefdesList* clone() const { return new CNetListRefdesList(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};