#pragma once
#include <iostream>
#include "stdafx.h"
#include "FlexibleAreas.h"
using namespace std;
class CRigidFlexiblePcb {
public:
	CFlexibleAreas m_FlexibleAreas;
public:
	CRigidFlexiblePcb();
	CRigidFlexiblePcb(const CRigidFlexiblePcb& src);
	virtual ~CRigidFlexiblePcb();
	void vSetCRigidFlexiblePcb(CFlexibleAreas FlexibleAreas);
	virtual CRigidFlexiblePcb & operator =(const CRigidFlexiblePcb & rhs);
	virtual BOOL operator==(const CRigidFlexiblePcb & rhs);
	BOOL operator!=(const CRigidFlexiblePcb & rhs);
	virtual CRigidFlexiblePcb* clone();
//	virtual CRigidFlexiblePcb* clone() const { return new CRigidFlexiblePcb(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

