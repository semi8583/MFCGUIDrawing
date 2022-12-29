#pragma once
#include <iostream>
using namespace std;

class CNetType
{
public:
	int m_nNetType;
	CNetType();
	CNetType(const CNetType& src);
	virtual ~CNetType();
	void vSetNetType(int nNetType);
	virtual CNetType & operator =(const CNetType & rhs);
	virtual BOOL operator==(const CNetType & rhs);
	BOOL operator!=(const CNetType & rhs);
	virtual CNetType* clone();
//	virtual CNetType* clone() const { return new CNetType(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};