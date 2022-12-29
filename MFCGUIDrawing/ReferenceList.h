#pragma once
#include <iostream>


#include "Ref.h"
using namespace std;

class CReferenceList
{
public:
	string m_sPointingType;
	CRefArray m_aRef;
public:
	CReferenceList();
	CReferenceList(const CReferenceList& src);
	virtual ~CReferenceList();
	void vSetReferenceList(string PointingType, CRefArray aRef);
	CReferenceList ReturnReferenceList(CReferenceList ReferenceList);
	virtual CReferenceList & operator =(const CReferenceList & rhs);
	virtual BOOL operator==(const CReferenceList & rhs);
	BOOL operator!=(const CReferenceList & rhs);
	virtual CReferenceList* clone();
//	virtual CReferenceList* clone() const { return new CReferenceList(*this); };
//
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};