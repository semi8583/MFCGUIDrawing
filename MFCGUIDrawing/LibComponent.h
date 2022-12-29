#pragma once
#include <iostream>
#include "Part.h"
using namespace std;

class CLibComponent
{
public:
	CPartArray m_aPart;
	CLibComponent();
	CLibComponent(const CLibComponent& src);
    virtual ~CLibComponent();
	void vSetCLibComponent(CPartArray aPart);
	virtual CLibComponent & operator =(const CLibComponent & rhs);
	virtual BOOL operator==(const CLibComponent & rhs);
	BOOL operator!=(const CLibComponent & rhs);
	virtual CLibComponent* clone();
//	virtual CLibComponent* clone() const { return new CLibComponent(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};