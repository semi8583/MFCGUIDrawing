#include "stdafx.h"
#include "Panel.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPanel::CPanel()
{
	cout << "생성자 CPanel() 호출" << endl;
}
CPanel::CPanel(const CPanel& src)
{
	*this = src;
}
CPanel::~CPanel()
{
	for (int i = 0; i < m_aPanel.GetSize(); i++)
	{
		CDrawObj * pItem = m_aPanel.GetAt(i);
		delete pItem;
	}
	m_aPanel.RemoveAll();
	cout << "소멸자 ~CBoard() 호출" << endl;
}
void CPanel::vSetCPanel(CDrawObjArray aPanel, CSubboard Subboard)
{
	m_Subboard = Subboard;
	for (int i = 0; i < m_aPanel.GetSize(); i++)
	{
		CDrawObj * pItem = m_aPanel.GetAt(i);
		delete pItem;
	}
	m_aPanel.RemoveAll();

	for (int i = 0; i < aPanel.GetSize(); i++)
	{
		CDrawObj * pItem = aPanel.GetAt(i);
		this->m_aPanel.Add(pItem->clone());
		delete pItem;
	}
};
CPanel& CPanel::operator =(const CPanel& rhs)
{
	if (this == &rhs)
		return *this;

	m_Subboard = rhs.m_Subboard;

	for (int i = 0; i < m_aPanel.GetSize(); i++)
	{
		CDrawObj * pItem = m_aPanel.GetAt(i);
		delete pItem;
	}
	m_aPanel.RemoveAll();;

	for (int i = 0; i < rhs.m_aPanel.GetSize(); i++)
	{
		CDrawObj * pItem = rhs.m_aPanel.GetAt(i);
		this->m_aPanel.Add(pItem->clone());
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CPanel::operator==(const CPanel & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPanel::operator!=(const CPanel& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CPanel* CPanel::clone()
{
	return new CPanel(*this);

}
// const int CPanel::m_nVersion = 1;