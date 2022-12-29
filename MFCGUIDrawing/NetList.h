#pragma once
#include <iostream>


#include "NetListNet.h"
using namespace std;

class CNetList
{
public:
	CNetListNetArray m_aNetListNet;
public:
	CNetList();
	CNetList(const CNetList& src);
	virtual ~CNetList();
	void vSetNetList(CNetListNetArray aNetListNet);
	virtual CNetList & operator =(const CNetList & rhs);
	virtual BOOL operator==(const CNetList & rhs);
	BOOL operator!=(const CNetList & rhs);
	virtual CNetList* clone();
//	virtual CNetList* clone() const { return new CNetList(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};