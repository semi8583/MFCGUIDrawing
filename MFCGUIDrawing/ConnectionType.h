#pragma once
#include <iostream>
#include "DrawObj.h"
#include "Polygon.h"


using namespace std;

class CConnectionType
{
public:
	string m_sConnectionType ;
	CDrawObjArray m_aDrawObj;
public:
	CConnectionType();
	CConnectionType(const CConnectionType& src);
	virtual ~CConnectionType();
	void vSetCConnectionType(string sConnectionType, CDrawObjArray aDrawObj);
	void vAddPolygonToConnectionType(CDrawObj* pDrawObj);
	void vAddPolygonToConnectionType(CDrawObjArray aDrawObj);
	virtual  CConnectionType & operator =(const CConnectionType & rhs);
	virtual  BOOL operator==(const CConnectionType & rhs);
	BOOL operator!=(const CConnectionType & rhs);
	virtual CConnectionType* clone();
	//virtual CConnectionType* clone() const { return new CConnectionType(*this); }

	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};

class  CConnectionTypeArray : public CArray< CConnectionType *, CConnectionType * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CConnectionTypeArray();
	CConnectionTypeArray(const CConnectionTypeArray& src);
	virtual ~CConnectionTypeArray();

	virtual CConnectionTypeArray& operator =(const CConnectionTypeArray& rhs);
	virtual bool operator==(const CConnectionTypeArray& rhs) const;
	bool operator!=(const CConnectionTypeArray& rhs) const;
	virtual CConnectionTypeArray* clone();
	virtual CConnectionTypeArray * clone() const { return new CConnectionTypeArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};