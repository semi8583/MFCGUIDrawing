#pragma once
#include <iostream>
using namespace std;

class CNetStatus
{
public:
	int m_nST1, m_nST2, m_nST3, m_nST4;
	CNetStatus();
	CNetStatus(const CNetStatus& src);
	virtual ~CNetStatus();
	void vSetNetStatus(int nST1, int nST2, int nST3, int nST4);
	virtual CNetStatus & operator =(const CNetStatus & rhs);
	virtual BOOL operator==(const CNetStatus & rhs);
	BOOL operator!=(const CNetStatus & rhs);
	virtual CNetStatus* clone();
//	virtual CNetStatus* clone() const { return new CNetStatus(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};