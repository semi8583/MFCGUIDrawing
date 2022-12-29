#include "stdafx.h"
#include "SymbolDefinition.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CSymbolDefinition::CSymbolDefinition()
{
	cout << "생성자 CSymbolDefinition() 호출" << endl;
}
CSymbolDefinition::CSymbolDefinition(const CSymbolDefinition& src)
{
	*this = src;
}
CSymbolDefinition::~CSymbolDefinition()
{
	cout << "소멸자 ~CSymbolDefinition() 호출" << endl;
}
void CSymbolDefinition::vSetSymbol(int nSymbolNo, string sSymbolName, int nPinNumber, CGateNo GateNo, CPinNumber PinNumber2)
{
	this->m_nSymbolNo = nSymbolNo;
	this->m_sSymbolName = sSymbolName;
	this->m_nPinNumber = nPinNumber;
	this->m_GateNo = GateNo;
	this->m_PinNumber = PinNumber2;
}
CSymbolDefinition& CSymbolDefinition::operator =(const CSymbolDefinition& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_nSymbolNo = rhs.m_nSymbolNo;
	this->m_sSymbolName = rhs.m_sSymbolName;
	this->m_nPinNumber = rhs.m_nPinNumber;
	this->m_GateNo = rhs.m_GateNo;
	this->m_PinNumber = rhs.m_PinNumber;
	// Add code to serialize member variable
	return *this;
}


BOOL CSymbolDefinition::operator==(const CSymbolDefinition & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CSymbolDefinition::operator!=(const CSymbolDefinition& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CSymbolDefinition* CSymbolDefinition::clone()
{
	return new CSymbolDefinition(*this);

}
// const int CSymbolDefinition::m_nVersion = 1;