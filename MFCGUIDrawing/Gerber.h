#pragma once
#include <iostream>
#include "GLayer.h"


using namespace std;

class CGerber
{
public:
	CGLayerArray m_aGLayer;
	CGerber();
	CGerber(const CGerber& src);
	virtual ~CGerber();
	void vSetGetber(CGLayerArray aGLayer);
	virtual CGerber & operator =(const CGerber & rhs);
	virtual BOOL operator==(const CGerber & rhs);
	BOOL operator!=(const CGerber & rhs);
	virtual CGerber* clone();
//	virtual CGerber* clone() const { return new CGerber(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};