#pragma once
#include <iostream>
using namespace std;

class CNetClass
{
public:
	string m_sNetClassName;
	CNetClass();
	CNetClass(const CNetClass& src);
	virtual ~CNetClass();
	void vSetNetClass(string NetClassName);
	virtual CNetClass  & operator =(const CNetClass  & rhs);
	virtual BOOL operator==(const CNetClass  & rhs);
	BOOL operator!=(const CNetClass  & rhs);
	virtual CNetClass* clone();
//	virtual CNetClass* clone() const { return new CNetClass(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};
