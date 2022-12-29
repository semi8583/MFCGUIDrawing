#pragma once
#include <iostream>


using namespace std;

class CNetIndex
{
public:
	CArray<int> m_naNetIndex;
public:
	CNetIndex();
	CNetIndex(const CNetIndex& src);
	virtual ~CNetIndex();
	void vSetNetIndex(CArray<int> naNetIndex);
	virtual CNetIndex & operator =(const CNetIndex & rhs);
	virtual BOOL operator==(const CNetIndex & rhs);
	BOOL operator!=(const CNetIndex & rhs);
	virtual CNetIndex* clone();
	//virtual CNetIndex* clone() const { return new CNetIndex(*this); }
	//virtual void Serialize(CArchive& ar);

//protected:
//private:
	//static const int m_nVersion ;
};

class  CNetIndexArray : public CArray< CNetIndex *, CNetIndex * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CNetIndexArray();
	CNetIndexArray(const CNetIndexArray& src);
	virtual ~CNetIndexArray();

	virtual CNetIndexArray& operator =(const CNetIndexArray& rhs);
	virtual bool operator==(const CNetIndexArray& rhs) const;
	bool operator!=(const CNetIndexArray& rhs) const;
	virtual CNetIndexArray* clone();
	virtual CNetIndexArray * clone() const { return new CNetIndexArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};
