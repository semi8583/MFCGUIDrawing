#pragma once
#include <iostream>
#include "CompositeNetCNet.h"


using namespace std;

class CCompositeNet
{
public:
	CCompositeNetCNetArray m_aCompositeNet;
public:
	CCompositeNet();
	CCompositeNet(const CCompositeNet& src);
	virtual ~CCompositeNet();
	void vSetCompositeNet(CCompositeNetCNetArray aCompositeNet);
	virtual CCompositeNet & operator =(const CCompositeNet & rhs);
	virtual BOOL operator==(const CCompositeNet & rhs);
	BOOL operator!=(const CCompositeNet & rhs);
	virtual CCompositeNet* clone();
	//virtual CCompositeNet* clone() const { return new CCompositeNet(*this); }

	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};
