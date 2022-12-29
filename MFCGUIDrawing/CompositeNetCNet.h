#pragma once
#include <iostream>
#include "ConnectInfo.h"
#include "NetType.h"
#include "DiffPair.h"
#include "NetClass.h"
#include "NetElectricConstraints.h"


using namespace std;

class CCompositeNetCNet
{
public:
	string m_sCompositeNetName;
	CArray<int> m_naLibNetNo;
	string m_sNetClassName;
	CConnectInfoArray m_aConnectInfo;
	CNetType m_NetType;
	CDiffPair m_DiffPair;
	CNetClass m_NetClass;
	CNetElectricConstraints m_ElectricConstraints;
	CCompositeNetCNet();
	CCompositeNetCNet(const CCompositeNetCNet& src);
	virtual ~CCompositeNetCNet();
	void vSetNet(string sCompositeNetName, CArray<int> naLibNetNo, string sNetClassName, CConnectInfoArray aConnectInfo, CNetType NetType, CDiffPair DiffPair, CNetClass NetClassName, CNetElectricConstraints ElectricConstraints);
	virtual CCompositeNetCNet & operator =(const CCompositeNetCNet & rhs);
	virtual BOOL operator==(const CCompositeNetCNet & rhs);
	BOOL operator!=(const CCompositeNetCNet & rhs);
	virtual CCompositeNetCNet* clone();
	//virtual CCompositeNetCNet* clone() const { return new CCompositeNetCNet(*this); }

	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};

class  CCompositeNetCNetArray : public CArray< CCompositeNetCNet *, CCompositeNetCNet * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CCompositeNetCNetArray();
	CCompositeNetCNetArray(const CCompositeNetCNetArray& src);
	virtual ~CCompositeNetCNetArray();

	virtual CCompositeNetCNetArray& operator =(const CCompositeNetCNetArray& rhs);
	virtual bool operator==(const CCompositeNetCNetArray& rhs) const;
	bool operator!=(const CCompositeNetCNetArray& rhs) const;
	virtual CCompositeNetCNetArray* clone();
	virtual CCompositeNetCNetArray * clone() const { return new CCompositeNetCNetArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};
