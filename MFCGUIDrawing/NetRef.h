#pragma once
#include <iostream>
using namespace std;

class CNetRef
{
public:
	string m_sReferenceName;
	int m_nPinNo;
	CNetRef();
	CNetRef(const CNetRef& src);
	virtual ~CNetRef();
	void vSetNetRef(string sReferenceName, int nPinNo);
	virtual CNetRef & operator =(const CNetRef & rhs);
	virtual BOOL operator==(const CNetRef & rhs);
	BOOL operator!=(const CNetRef & rhs);
	virtual CNetRef* clone();
//	virtual CNetRef* clone() const { return new CNetRef(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

class  CNetRefArray : public CArray< CNetRef *, CNetRef * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CNetRefArray();
	CNetRefArray(const CNetRefArray& src);
	virtual ~CNetRefArray();

	virtual CNetRefArray& operator =(const CNetRefArray& rhs);
	virtual bool operator==(const CNetRefArray& rhs) const;
	bool operator!=(const CNetRefArray& rhs) const;
	virtual CNetRefArray* clone();
	virtual CNetRefArray * clone() const { return new CNetRefArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};