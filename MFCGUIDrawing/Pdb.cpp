#include "stdafx.h"
#include "Pdb.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPdb::CPdb()
{
	cout << "생성자 CPdb() 호출" << endl;
}
CPdb::CPdb(const CPdb& src)
{
	*this = src;
}
CPdb::~CPdb()
{
	cout << "소멸자 ~CPdb() 호출" << endl;
}

CPdb& CPdb::operator =(const CPdb& rhs)
{
	if (this == &rhs)
		return *this;

	this->m_Board = rhs.m_Board;
	this->m_BoardFigure = rhs.m_BoardFigure;
	this->m_CNetListRefdesList = rhs.m_CNetListRefdesList;
	this->m_Gerber = rhs.m_Gerber;
	this->m_Information = rhs.m_Information;
	this->m_LayerUnion = rhs.m_LayerUnion;
	this->m_LibComponent = rhs.m_LibComponent;
	this->m_LibLayer = rhs.m_LibLayer;
	this->m_LibPadStack = rhs.m_LibPadStack;
	this->m_LibPenType = rhs.m_LibPenType;
	this->m_LibText = rhs.m_LibText;
	this->m_LibTurret = rhs.m_LibTurret;
	this->m_LibVia = rhs.m_LibVia;
	this->m_Route = rhs.m_Route;
	// Add code to serialize member variable
	return *this;
}


BOOL CPdb::operator==(const CPdb & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPdb::operator!=(const CPdb& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CPdb* CPdb::clone()
{
	return new CPdb(*this);

}
// const int CPdb::m_nVersion = 1;