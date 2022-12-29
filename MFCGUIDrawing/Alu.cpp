
#include "stdafx.h"
#include "Alu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CAlu::CAlu()
{
	cout << "생성자 CAlu() 호출" << endl;
}
CAlu::CAlu(const CAlu& src)
{
	*this = src;
}

CAlu::~CAlu()
{
	cout << "소멸자 ~CAlu() 호출" << endl;
}
void CAlu::vSetCAlu(string sUnionName, int nArtworkLayNo)
{
	m_sUnionName = sUnionName;
	m_nArtworkLayNo = nArtworkLayNo;
}
CAlu& CAlu::operator =(const CAlu& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_nArtworkLayNo = rhs.m_nArtworkLayNo;
	this->m_sUnionName = rhs.m_sUnionName;
	// Add code to serialize member variable
	return *this;
}


BOOL CAlu::operator==(const CAlu & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CAlu::operator!=(const CAlu& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CAlu* CAlu::clone()
{
	return new CAlu(*this);

}
//const int CAlu::m_nVersion = 1;