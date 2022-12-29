#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CAlu
{
public:
	string m_sUnionName = "";
	int m_nArtworkLayNo = 0;
	CAlu();
	CAlu(const CAlu& src);
	virtual ~CAlu();
	void vSetCAlu(string sUnionName, int nArtworkLayNo);

	virtual CAlu & operator =(const CAlu & rhs);
	virtual BOOL operator==(const CAlu & rhs);
	BOOL operator!=(const CAlu & rhs);
	virtual CAlu* clone();
	//virtual CAlu* clone() const { return new CAlu(*this); }
	// //virtual void Serialize(CArchive& ar);  

protected:
private:
	//static const int m_nVersion ;
};
