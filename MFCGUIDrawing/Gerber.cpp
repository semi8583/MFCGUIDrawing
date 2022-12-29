#include "stdafx.h"
#include "Gerber.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CGerber::CGerber()
{
	cout << "생성자 CGerber() 호출" << endl;
}
CGerber::CGerber(const CGerber& src)
{
	*this = src;
}
CGerber::~CGerber()
{
	for (int i = 0; m_aGLayer.GetSize(); i++)
	{
		CGLayer* pItem = m_aGLayer.GetAt(i);
		delete pItem;
	}
	m_aGLayer.RemoveAll();

	cout << "소멸자 ~CGerber() 호출" << endl;
}
void CGerber::vSetGetber(CGLayerArray aGLayer)
{
	for (int i = 0; m_aGLayer.GetSize(); i++)
	{
		CGLayer* pItem = m_aGLayer.GetAt(i);
		delete pItem;
	}
	m_aGLayer.RemoveAll();


	for (int i = 0; i < aGLayer.GetSize(); i++)
	{
		CGLayer * pItem = aGLayer.GetAt(i);
		this->m_aGLayer.Add(pItem->clone());
		delete pItem;
	}

}
CGerber& CGerber::operator =(const CGerber& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; m_aGLayer.GetSize(); i++)
	{
		CGLayer* pItem = m_aGLayer.GetAt(i);
		delete pItem;
	}
	m_aGLayer.RemoveAll();


	for (int i = 0; i < rhs.m_aGLayer.GetSize(); i++)
	{
		CGLayer * pItem = rhs.m_aGLayer.GetAt(i);
		this->m_aGLayer.Add(pItem->clone());
	}

	// Add code to serialize member variable
	return *this;
}


BOOL CGerber::operator==(const CGerber & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CGerber::operator!=(const CGerber& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CGerber* CGerber::clone()
{
	return new CGerber(*this);

}
//const int CGerber::m_nVersion = 1;