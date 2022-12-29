#pragma once
#include "stdafx.h"
#include "LayerTypeName.h"

class CViaDefinition
{
public:
	int m_nLibViaNo=0, m_nLibTurretForHoleNo=0, m_nViaStartingArtworkLayNo=0, m_nViaEndingArtworkLayNo=0;
	string m_sViaName, m_sViaType, m_sPlatedType;
	CLayerTypeNameArray m_aLayerTypeName;
public:
	CViaDefinition();
	CViaDefinition(const CViaDefinition& src);
	virtual ~CViaDefinition();
	void vSetViaDefinition(int nLibViaNo, string sViaName, string sViaType, int nLibTurretForHoleNo,
		string sPlatedType, int nViaStartingArtworkLayNo, int nViaEndingArtworkLayNo, CLayerTypeNameArray aLayerTypeName);
	virtual CViaDefinition & operator =(const CViaDefinition & rhs);
	virtual BOOL operator==(const CViaDefinition & rhs);
	BOOL operator!=(const CViaDefinition & rhs);
	virtual CViaDefinition* clone();
//	virtual CViaDefinition* clone() const { return new CViaDefinition(*this); };
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

class  CViaDefinitionArray : public CArray< CViaDefinition *, CViaDefinition * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CViaDefinitionArray();
	CViaDefinitionArray(const CViaDefinitionArray& src);
	virtual ~CViaDefinitionArray();

	virtual CViaDefinitionArray& operator =(const CViaDefinitionArray& rhs);
	virtual bool operator==(const CViaDefinitionArray& rhs) const;
	bool operator!=(const CViaDefinitionArray& rhs) const;
	virtual CViaDefinitionArray* clone();
	virtual CViaDefinitionArray * clone() const { return new CViaDefinitionArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};
