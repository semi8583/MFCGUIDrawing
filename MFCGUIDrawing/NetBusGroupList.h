#pragma once
#include <iostream>
#include "afxtempl.h"
#include "NetBusGroup.h"
#include "naStrobedNetIndex.h"
#include "NetIndex.h"


using namespace std;

class CNetBusGroupList
{
public:
	CNetBusGroupArray m_aNetBusGroup;
	CStrobedNetIndexArray m_aStrobedNetIndex;
	CNetIndexArray m_aNetIndex;
public:
	CNetBusGroupList();
	CNetBusGroupList(const CNetBusGroupList& src);
	virtual ~CNetBusGroupList();
	void vSetNetIndex(CNetBusGroupArray aNetBusGroup, CStrobedNetIndexArray aStrobedNetIndex, CNetIndexArray aNetIndex);
	virtual CNetBusGroupList & operator =(const CNetBusGroupList & rhs);
	virtual BOOL operator==(const CNetBusGroupList & rhs);
	BOOL operator!=(const CNetBusGroupList & rhs);
	virtual CNetBusGroupList* clone();
	//virtual CNetBusGroupList* clone() const { return new CNetBusGroupList(*this); }
	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};