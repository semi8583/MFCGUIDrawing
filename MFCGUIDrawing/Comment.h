#pragma once
#include <iostream>
#include "stdafx.h"
using namespace std;

class CComment
{
public:
	string m_sComment;
public:
	CComment();
	CComment(const CComment& src);
	virtual ~CComment();
	void vSetCComment(string sComment);
	virtual CComment & operator =(const CComment & rhs);
	virtual BOOL operator==(const CComment & rhs);
	BOOL operator!=(const CComment & rhs);
	virtual CComment* clone();
	//virtual CComment* clone() const { return new CComment(*this); }
	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};
