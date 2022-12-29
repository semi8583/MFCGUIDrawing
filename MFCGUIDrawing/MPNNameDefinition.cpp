#include "stdafx.h"
#include "MPNNameDefinition.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CMPNNameDefinition::CMPNNameDefinition()
{
	cout << "생성자 CMPNNameDefinition() 호출" << endl;
}
CMPNNameDefinition::CMPNNameDefinition(const CMPNNameDefinition& src)
{
	*this = src;
}
CMPNNameDefinition::~CMPNNameDefinition()
{
	cout << "소멸자 ~CMPNNameDefinition() 호출" << endl;
}
void CMPNNameDefinition::vSetMPNname(string sMPNName)
{
	m_sMPNName = sMPNName;
}
CMPNNameDefinition& CMPNNameDefinition::operator =(const CMPNNameDefinition& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_sMPNName = rhs.m_sMPNName;
	// Add code to serialize member variable
	return *this;
}


BOOL CMPNNameDefinition::operator==(const CMPNNameDefinition & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CMPNNameDefinition::operator!=(const CMPNNameDefinition& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CMPNNameDefinition* CMPNNameDefinition::clone()
{
	return new CMPNNameDefinition(*this);

}
// const int CMPNNameDefinition::m_nVersion = 1;