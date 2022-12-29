#pragma once
#include <iostream>
using namespace std;

class CConnectInfo
{
public:
	int m_nRefIndex, m_nLibNetNoFirst, m_nPinNumberFirst, m_nLibNetNoSecond, m_nPinNumberSecond;
	CConnectInfo();
	CConnectInfo(const CConnectInfo& src);
	virtual ~CConnectInfo();
	void vSetConnectInfo(int nRefIndex, int nLibNetNoFirst, int nPinNumberFirst, int nLibNetNoSecond, int nPinNumberSecond);
	virtual CConnectInfo & operator =(const CConnectInfo & rhs);
	virtual BOOL operator==(const CConnectInfo & rhs);
	BOOL operator!=(const CConnectInfo & rhs);
	virtual CConnectInfo* clone();
	//virtual CConnectInfo* clone() const { return new CConnectInfo(*this); }

	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};

class  CConnectInfoArray : public CArray< CConnectInfo *, CConnectInfo * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CConnectInfoArray();
	CConnectInfoArray(const CConnectInfoArray& src);
	virtual ~CConnectInfoArray();

	virtual CConnectInfoArray& operator =(const CConnectInfoArray& rhs);
	virtual bool operator==(const CConnectInfoArray& rhs) const;
	bool operator!=(const CConnectInfoArray& rhs) const;
	virtual CConnectInfoArray* clone();
	virtual CConnectInfoArray * clone() const { return new CConnectInfoArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};