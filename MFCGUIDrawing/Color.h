#pragma once
#include <iostream>
using namespace std;

class CColor
{
public:
	int m_nR, m_nG, m_nB;
public:
	CColor();
	CColor(const CColor& src);
	virtual ~CColor();
	void vSetColor(int nR, int nG, int nB);
	virtual CColor & operator =(const CColor & rhs);
	virtual BOOL operator==(const CColor & rhs);
	BOOL operator!=(const CColor & rhs);
	virtual CColor* clone();
	//virtual CColor* clone() const { return new CColor(*this); }

	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};
