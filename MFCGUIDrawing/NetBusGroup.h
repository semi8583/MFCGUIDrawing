#pragma once
#include <iostream>
using namespace std;

class CNetBusGroup
{
public:
	string m_sBusGroupName, m_sControlDevice;
	double m_dMaxBusSkew, m_dMaxStrobedSkew;
public:
	CNetBusGroup();
	CNetBusGroup(const CNetBusGroup& src);
	virtual ~CNetBusGroup();
	void vSetNetBusGroup(string sBusGroupName, double dMaxBusSkew, double dMaxStrobedSkew, string sControlDevice);
	virtual CNetBusGroup & operator =(const CNetBusGroup & rhs);
	virtual BOOL operator==(const CNetBusGroup & rhs);
	BOOL operator!=(const CNetBusGroup & rhs);

	virtual CNetBusGroup* clone();
	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};

class  CNetBusGroupArray : public CArray< CNetBusGroup *, CNetBusGroup * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CNetBusGroupArray();
	CNetBusGroupArray(const CNetBusGroupArray& src);
	virtual ~CNetBusGroupArray();

	virtual CNetBusGroupArray& operator =(const CNetBusGroupArray& rhs);
	virtual bool operator==(const CNetBusGroupArray& rhs) const;
	bool operator!=(const CNetBusGroupArray& rhs) const;
	virtual CNetBusGroupArray* clone();
	virtual CNetBusGroupArray * clone() const { return new CNetBusGroupArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};
