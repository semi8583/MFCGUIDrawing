#include "stdafx.h"
#include "Via.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CVia::CVia()
{
	cout << "생성자 CVia() 호출" << endl;
}
CVia::CVia(const CVia& src)
{
	*this = src;
}
CVia:: ~CVia()
{
	cout << "소멸자 ~CVia() 호출" << endl;
}
void CVia::vSetViaLibArtworkLayNo(int nLibArtworkLayNo)
{
	m_nLibArtworkLayNo = nLibArtworkLayNo;
}
void CVia::vSetViaLibViaNo(int nLibViaNo)
{
	m_nLibViaNo = nLibViaNo;
}
void CVia::vSetViaAngle(double dAngle)
{
	m_dAngle = dAngle;
}
void CVia::vSetViaTearDropExist(string sTearDropExist)
{
	m_sTearDropExist = sTearDropExist;
}
void CVia::vSetViaPtX(double dPtX)
{
	m_dPtX = dPtX;
}
void CVia::vSetViaPtY(double dPtY)
{
	m_dPtY = dPtY;
}
//
int CVia::nGetViaLibArtworkLayNo()
{
	return m_nLibArtworkLayNo;
}
int CVia::nGetViaLibViaNo()
{
	return m_nLibViaNo;
}
double CVia::dGetViaAngle()
{
	return m_dAngle;
}
string  CVia::sGetViaTearDropExist()
{
	return m_sTearDropExist;
}
double CVia::dGetViaPtX()
{
	return m_dPtX;
}
double CVia::dGetViaPtY()
{
	return m_dPtY;
}
CVia &  CVia::operator =(const CVia & rhs)
{
	CDrawObj::operator=(rhs);
	this->m_dAngle = rhs.m_dAngle;
	this->m_dPtX = rhs.m_dPtX;
	this->m_dPtY = rhs.m_dPtY;
	this->m_nLibArtworkLayNo = rhs.m_nLibArtworkLayNo;
	this->m_nLibViaNo = rhs.m_nLibViaNo;
	this->m_PinConnectionStatus.m_nPinNo = rhs.m_PinConnectionStatus.m_nPinNo;
	for (int i = 0; i < rhs.m_PinConnectionStatus.m_asConnectionStatus.GetSize(); i++)
		this->m_PinConnectionStatus.m_asConnectionStatus.Add(rhs.m_PinConnectionStatus.m_asConnectionStatus[i]);
	this->m_sTearDropExist = rhs.m_sTearDropExist;
	return *this;
}
CDrawObj & CVia::operator =(const CDrawObj & rhs)
{
	if (this == &rhs)
		return *this;
	CDrawObj::operator=(rhs);
	// Add code to serialize member variable
	return *this;
}


BOOL CVia::operator==(const CDrawObj & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CVia::operator!=(const CDrawObj& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CDrawObj* CVia::clone()
{
	return new CVia(*this);

}
// const int CVia::m_nVersion = 1;