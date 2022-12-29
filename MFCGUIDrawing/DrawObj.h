#pragma once
#include <iostream>
using namespace std;
class CDrawObj
{
public:
	CDrawObj();
	CDrawObj(const CDrawObj& src);
	virtual ~CDrawObj();
	virtual CDrawObj & operator =(const CDrawObj & rhs);
	virtual BOOL operator==(const CDrawObj & rhs);
	BOOL operator!=(const CDrawObj & rhs);
	virtual CDrawObj* clone();
	//virtual CDrawObj* clone() const { return new CDrawObj(*this); }

//protected:
//private:
//	static const int m_nVersion;
};

class  CDrawObjArray : public CArray< CDrawObj *, CDrawObj * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CDrawObjArray();
	CDrawObjArray(const CDrawObjArray& src);
	virtual ~CDrawObjArray();

	virtual CDrawObjArray& operator =(const CDrawObjArray& rhs);
	virtual bool operator==(const CDrawObjArray& rhs) const;
	bool operator!=(const CDrawObjArray& rhs) const;
	virtual CDrawObjArray* clone();
	virtual CDrawObjArray * clone() const { return new CDrawObjArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};

