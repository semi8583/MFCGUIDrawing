#pragma once
#include <iostream>
#include "afxtempl.h"
#include "Tur.h"


using namespace std;

class CLibTurret
{
public:
	CTurArray m_aTur;
public:
	CLibTurret();
	CLibTurret(const CLibTurret& src);
	virtual ~CLibTurret();
	void vSetCLibTurret(CTurArray aTur);
	virtual CLibTurret & operator =(const CLibTurret & rhs);
	virtual BOOL operator==(const CLibTurret & rhs);
	BOOL operator!=(const CLibTurret & rhs);
	virtual CLibTurret* clone();
//	virtual CLibTurret* clone() const { return new CLibTurret(*this); }
//	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

