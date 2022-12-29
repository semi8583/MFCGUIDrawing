#include "stdafx.h"
#include "DiffPair.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CDiffPair::CDiffPair()
{
	cout << "생성자 CDiffPair() 호출" << endl;
}
CDiffPair::CDiffPair(const CDiffPair& src)
{
	*this = src;
}
CDiffPair::~CDiffPair()
{
	cout << "소멸자 ~CDiffPair() 호출" << endl;
}
void CDiffPair::vSetDiffPair(int nDifferentialPairNetIndex)
{
	m_nDifferentialPairNetIndex = nDifferentialPairNetIndex;
}
CDiffPair& CDiffPair::operator =(const CDiffPair& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_nDifferentialPairNetIndex = rhs.m_nDifferentialPairNetIndex;
	// Add code to serialize member variable
	return *this;
}


BOOL CDiffPair::operator==(const CDiffPair & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CDiffPair::operator!=(const CDiffPair& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CDiffPair* CDiffPair::clone()
{
	return new CDiffPair(*this);

}
//const int CDiffPair::m_nVersion = 1;