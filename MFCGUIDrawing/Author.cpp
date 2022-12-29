
#include "stdafx.h"
#include "Author.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CAuthor::CAuthor()
{
	cout << "생성자 CAuthor() 호출" << endl;
}
CAuthor::CAuthor(const CAuthor& src)
{
	*this = src;
}

CAuthor::~CAuthor()
{
	cout << "소멸자 ~CAuthor() 호출" << endl;
}
void CAuthor::vSetCAuthor(string sMakerName)
{
	m_sMakerName = sMakerName;
}
CAuthor& CAuthor::operator =(const CAuthor& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_sMakerName = rhs.m_sMakerName;
	// Add code to serialize member variable
	return *this;
}


BOOL CAuthor::operator==(const CAuthor & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CAuthor::operator!=(const CAuthor& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CAuthor* CAuthor::clone()
{
	return new CAuthor(*this);

}
//const int CAuthor::m_nVersion = 1;