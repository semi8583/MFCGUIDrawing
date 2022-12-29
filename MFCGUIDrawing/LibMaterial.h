#pragma once
#include <iostream>
#include "stdafx.h"
#include "Material.h"


using namespace std;

class CLibMaterial
{
public:
	CMaterialArray m_aMaterial;
public:
	CLibMaterial();
	CLibMaterial(const CLibMaterial& src);
	virtual ~CLibMaterial();
	void vSetCLibMaterial(CMaterialArray  aMaterial);
	virtual CLibMaterial & operator =(const CLibMaterial & rhs);
	virtual BOOL operator==(const CLibMaterial & rhs);
	BOOL operator!=(const CLibMaterial & rhs);
	virtual CLibMaterial* clone();
	//	virtual CLibMaterial* clone() const { return new CLibMaterial(*this); }
	//
	//protected:
	//private:
};
