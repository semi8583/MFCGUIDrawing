#pragma once
#include <iostream>
using namespace std;
class CPropertys
{
public:
	string m_sPropertyItem, m_sPropertyContents;
	CPropertys();
	CPropertys(const CPropertys& src);
	virtual ~CPropertys();
	void vSetCPropertys(string m_sPropertyItem,string m_sPropertyContents);
	virtual CPropertys & operator =(const CPropertys & rhs);
	virtual BOOL operator==(const CPropertys & rhs);
	BOOL operator!=(const CPropertys & rhs);
	virtual CPropertys* clone();
};

class  CPropertysArray : public CArray< CPropertys *, CPropertys * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CPropertysArray();
	CPropertysArray(const CPropertysArray& src);
	virtual ~CPropertysArray();

	virtual CPropertysArray& operator =(const CPropertysArray& rhs);
	virtual bool operator==(const CPropertysArray& rhs) const;
	bool operator!=(const CPropertysArray& rhs) const;
	virtual CPropertysArray* clone();
	virtual CPropertysArray * clone() const { return new CPropertysArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};