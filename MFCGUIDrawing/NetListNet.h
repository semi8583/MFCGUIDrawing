#pragma once
#include <iostream>

#include "NetStatus.h"
#include "NetRef.h"
#include "NetListElectricConstraints.h"
using namespace std;

class CNetListNet
{
public:
	string m_sNetName, m_sNetType, m_sNetClassName;
	int m_nNetType;
	CNetStatus m_NetStatus;
	CNetRefArray m_aNetRef;
	CNetListElectricConstraints m_ElectricConstraints;

	CNetListNet();
	CNetListNet(const CNetListNet& src);
	virtual ~CNetListNet();
	void vSetCNetListNet(string sNetName, string sNetType, string sNetClassName, int nNetType, CNetStatus NetStatus, CNetRefArray aNetRef, CNetListElectricConstraints ElectricConstraints);
	virtual CNetListNet & operator =(const CNetListNet & rhs);
	virtual BOOL operator==(const CNetListNet & rhs);
	BOOL operator!=(const CNetListNet & rhs);
	virtual CNetListNet* clone();
	//virtual CNetListNet* clone() const { return new CNetListNet(*this); }
	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

class  CNetListNetArray : public CArray< CNetListNet *, CNetListNet * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CNetListNetArray();
	CNetListNetArray(const CNetListNetArray& src);
	virtual ~CNetListNetArray();

	virtual CNetListNetArray& operator =(const CNetListNetArray& rhs);
	virtual bool operator==(const CNetListNetArray& rhs) const;
	bool operator!=(const CNetListNetArray& rhs) const;
	virtual CNetListNetArray* clone();
	virtual CNetListNetArray * clone() const { return new CNetListNetArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};
