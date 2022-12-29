#include "stdafx.h"
#include "Comment.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CComment::CComment()
{
	cout << "생성자 CComment() 호출" << endl;
}
CComment::CComment(const CComment& src)
{
	*this = src;
}
CComment::~CComment()
{
	cout << "소멸자 ~CComment() 호출" << endl;
}
void CComment::vSetCComment(string sComment)
{
	m_sComment = sComment;
}
CComment& CComment::operator =(const CComment& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_sComment = rhs.m_sComment;
	// Add code to serialize member variable
	return *this;
}


BOOL CComment::operator==(const CComment & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CComment::operator!=(const CComment& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CComment* CComment::clone()
{
	return new CComment(*this);

}
//const int CComment::m_nVersion = 1;