#pragma once
#include <iostream>
using namespace std;

class CDiffPair
{
public:
	int m_nDifferentialPairNetIndex;
	CDiffPair();
	CDiffPair(const CDiffPair& src);
	virtual ~CDiffPair();
	void vSetDiffPair(int nDifferentialPairNetIndex);
	virtual CDiffPair & operator =(const CDiffPair & rhs);
	virtual BOOL operator==(const CDiffPair & rhs);
	BOOL operator!=(const CDiffPair & rhs);
	virtual CDiffPair* clone();
	//virtual CDiffPair* clone() const { return new CDiffPair(*this); }

	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};