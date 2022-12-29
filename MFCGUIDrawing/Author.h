#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CAuthor
{
public:
	string m_sMakerName;
public:
	CAuthor();
	CAuthor(const CAuthor& src);
	virtual ~CAuthor();
	void vSetCAuthor(string sMakerName);
	virtual CAuthor & operator =(const CAuthor & rhs);
	virtual BOOL operator==(const CAuthor & rhs);
	BOOL operator!=(const CAuthor & rhs);
	virtual CAuthor* clone();
	//virtual CAuthor* clone() const { return new CAuthor(*this); }

	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};