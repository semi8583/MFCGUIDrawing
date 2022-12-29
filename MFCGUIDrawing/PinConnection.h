#pragma once
#include <iostream>
using namespace std;

class CPinConnection
{
public:
	string m_sFirstPinName, m_sSecondPinName, m_sConnectType;
	double m_dValue;
public:
	CPinConnection();
	CPinConnection(const CPinConnection& src);
	virtual ~CPinConnection();
	void vSetPinConnection(string sFirstPinName, string sSecondPinName, string sConnectType, double dValue);
	virtual CPinConnection & operator =(const CPinConnection & rhs);
	virtual BOOL operator==(const CPinConnection & rhs);
	BOOL operator!=(const CPinConnection & rhs);
	virtual CPinConnection* clone();
//	virtual CPinConnection* clone() const { return new CPinConnection(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

class  CPinConnectionArray : public CArray< CPinConnection *, CPinConnection * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CPinConnectionArray();
	CPinConnectionArray(const CPinConnectionArray& src);
	virtual ~CPinConnectionArray();

	virtual CPinConnectionArray& operator =(const CPinConnectionArray& rhs);
	virtual bool operator==(const CPinConnectionArray& rhs) const;
	bool operator!=(const CPinConnectionArray& rhs) const;
	virtual CPinConnectionArray* clone();
	virtual CPinConnectionArray * clone() const { return new CPinConnectionArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};
