#pragma once
#include <iostream>
using namespace std;

class CPinConnectionStatus
{
public:
	int m_nPinNo;
	CArray<string> m_asConnectionStatus;
public:
	CPinConnectionStatus();
	CPinConnectionStatus(const CPinConnectionStatus& src);
	virtual ~CPinConnectionStatus();
	void vPinConnectionStatus(int nPinNo, CArray<string> asConnectionStatus);
	virtual CPinConnectionStatus & operator =(const CPinConnectionStatus & rhs);
	virtual BOOL operator==(const CPinConnectionStatus & rhs);
	BOOL operator!=(const CPinConnectionStatus & rhs);
	virtual CPinConnectionStatus* clone();
//	virtual CPinConnectionStatus* clone() const { return new CPinConnectionStatus(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};
class  CPinConnectionStatusArray : public CArray< CPinConnectionStatus *, CPinConnectionStatus * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CPinConnectionStatusArray();
	CPinConnectionStatusArray(const CPinConnectionStatusArray& src);
	virtual ~CPinConnectionStatusArray();

	virtual CPinConnectionStatusArray& operator =(const CPinConnectionStatusArray& rhs);
	virtual bool operator==(const CPinConnectionStatusArray& rhs) const;
	bool operator!=(const CPinConnectionStatusArray& rhs) const;
	virtual CPinConnectionStatusArray* clone();
	virtual CPinConnectionStatusArray * clone() const { return new CPinConnectionStatusArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};