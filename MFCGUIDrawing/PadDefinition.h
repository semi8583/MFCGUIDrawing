#pragma once
#include <iostream>
#include "LayerTypeName.h"
using namespace std;

class CPadDefinition
{
public:
	int m_nLibPadStackNo, m_nLibTurretForHoleNo, m_nPadStackStartingArtworkLayNo, m_nPadstackEndingArtworkLayNo;
	string m_sPadStackName, m_sPadstackType, m_sPlatedType;
	CLayerTypeNameArray m_aLayerTypeName;
public:
	CPadDefinition();
	CPadDefinition(const CPadDefinition& src);
	virtual ~CPadDefinition();
	void vSetPadDefinition(int nLibPadStackNo, string sPadStackName, string sPadStackType, int nLibTurretForHoleNo, string sPlatedType,
		int nPadStackStartingArtworkLayNo, int nPadStackEndingArtworkLayNo, CLayerTypeNameArray aLayerTypeName);
	virtual CPadDefinition & operator =(const CPadDefinition & rhs);
	virtual BOOL operator==(const CPadDefinition & rhs);
	BOOL operator!=(const CPadDefinition & rhs);
	virtual CPadDefinition* clone();
//	virtual CPadDefinition* clone() const { return new CPadDefinition(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

class  CPadDefinitionArray : public CArray< CPadDefinition *, CPadDefinition * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CPadDefinitionArray();
	CPadDefinitionArray(const CPadDefinitionArray& src);
	virtual ~CPadDefinitionArray();

	virtual CPadDefinitionArray& operator =(const CPadDefinitionArray& rhs);
	virtual bool operator==(const CPadDefinitionArray& rhs) const;
	bool operator!=(const CPadDefinitionArray& rhs) const;
	virtual CPadDefinitionArray* clone();
	virtual CPadDefinitionArray * clone() const { return new CPadDefinitionArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};
