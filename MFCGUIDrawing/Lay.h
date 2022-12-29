#pragma once
#include <iostream>
#include "stdafx.h"
#include "DrawObj.h"
using namespace std;

class CLay
{
public:
	int m_nLibArtworkLayNo, m_nEcadLayNum, m_nPhysicalLayNo, m_nRed, m_nGreen, m_nBlue;
	string m_sLayerName, m_sLayerType, m_sNetName, m_sPolarity, m_sComment;
public:
	CLay();
	CLay(const CLay& src);
	virtual ~CLay();
	void vSetLibLayer(int nLibArtworkLayNo, int nEcadLayNum, int nPhysicalLayNo, string sLayerName,
		string sLayerType, string sNetName, string sPolarity, string sComment, int nRed,
		int nGreen, int nBlue);
	virtual CLay & operator =(const CLay & rhs);
	virtual BOOL operator==(const CLay & rhs);
	BOOL operator!=(const CLay & rhs);
	virtual CLay* clone();
//	virtual CLay* clone() const { return new CLay(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};
class  CLayArray : public CArray< CLay *, CLay * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CLayArray();
	CLayArray(const CLayArray& src);
	virtual ~CLayArray();

	virtual CLayArray& operator =(const CLayArray& rhs);
	virtual bool operator==(const CLayArray& rhs) const;
	bool operator!=(const CLayArray& rhs) const;
	virtual CLayArray* clone();
	virtual CLayArray * clone() const { return new CLayArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};

