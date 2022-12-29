#pragma once
#include <iostream>
#include "DrawObj.h"
using namespace std;

class CGLayer
{
public:
	int m_nArtworkLayerNo;
	CDrawObjArray m_aDrawObj;
public:
	CGLayer();
	CGLayer(const CGLayer& src);
	~CGLayer();
	void vSetGLayer(int nArtworkLayerNo, CDrawObjArray aDrawObj);
	virtual CGLayer & operator =(const CGLayer & rhs);
	virtual BOOL operator==(const CGLayer & rhs);
	BOOL operator!=(const CGLayer & rhs);
	virtual CGLayer* clone();
//	virtual CGLayer* clone() const { return new CGLayer(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

class  CGLayerArray : public CArray< CGLayer *, CGLayer * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CGLayerArray();
	CGLayerArray(const CGLayerArray& src);
	virtual ~CGLayerArray();

	virtual CGLayerArray& operator =(const CGLayerArray& rhs);
	virtual bool operator==(const CGLayerArray& rhs) const;
	bool operator!=(const CGLayerArray& rhs) const;
	virtual CGLayerArray* clone();
	virtual CGLayerArray * clone() const { return new CGLayerArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};

