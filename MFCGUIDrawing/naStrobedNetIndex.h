#pragma once
#include <iostream>


using namespace std;

class CStrobedNetIndex
{
public:
	CArray<int> m_naStrobedNetIndex;
public:
	CStrobedNetIndex();
	CStrobedNetIndex(const CStrobedNetIndex& src);
	virtual ~CStrobedNetIndex();
	void vSetNetIndex(CArray<int> naStrobedNetIndex);
	virtual CStrobedNetIndex & operator =(const CStrobedNetIndex & rhs);
	virtual BOOL operator==(const CStrobedNetIndex & rhs);
	BOOL operator!=(const CStrobedNetIndex & rhs);
	virtual CStrobedNetIndex* clone();
//	//virtual CStrobedNetIndex* clone() const { return new CStrobedNetIndex(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};
class  CStrobedNetIndexArray : public CArray< CStrobedNetIndex *, CStrobedNetIndex * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CStrobedNetIndexArray();
	CStrobedNetIndexArray(const CStrobedNetIndexArray& src);
	virtual ~CStrobedNetIndexArray();

	virtual CStrobedNetIndexArray& operator =(const CStrobedNetIndexArray& rhs);
	virtual bool operator==(const CStrobedNetIndexArray& rhs) const;
	bool operator!=(const CStrobedNetIndexArray& rhs) const;
	virtual CStrobedNetIndexArray* clone();
	virtual CStrobedNetIndexArray * clone() const { return new CStrobedNetIndexArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};
