#include "stdafx.h"
#include "Polyline.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CPolyline::CPolyline()
{
	cout << "������ CPolyline() ȣ��" << endl;
}
CPolyline::CPolyline(const CPolyline& src)
{
	*this = src;
}
CPolyline::~CPolyline()
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	cout << "�Ҹ��� ~CPolyline() ȣ��" << endl;
}
void CPolyline::vSetPolylineLibArtworkLayNo(int nLibArtworkLayNo)
{
	m_nLibArtworkLayNo = nLibArtworkLayNo;
}
void CPolyline::vSetPolylineDrawObj(CDrawObjArray aDrawObj)
{
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());// .Add(DrawObj[i]);
	}
}
int  CPolyline::nGetPolylineLibArtworkLayNo()
{
	return m_nLibArtworkLayNo;
}
CDrawObjArray CPolyline::vGetPolylineDrawObj()
{
	return m_aDrawObj;
}
void CPolyline::vAddDrawObj(CDrawObjArray aDrawObj)
{
	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = aDrawObj.GetAt(i);
		m_aDrawObj.Add(pItem->clone());
	}
}
//// ���� aDrawObj�� ���� ���� �𸣴µ� arc�� line�� �Ű������� �޾Ƽ� ���� m_aDrawObj�� �߰�
void CPolyline::vAddLineAndArc(CDrawObj* aDrawObj)
{
	CLine* pLine;
	CArc* pArc;
	if (pLine = dynamic_cast<CLine*>(aDrawObj)) //line�ϰ� arc���� virtual �Լ� ��� 
	{
		m_aDrawObj.Add(pLine->clone());
		delete pLine;
	}
	else if (pArc = dynamic_cast<CArc*>(aDrawObj)) //line�ϰ� arc���� virtual �Լ� ��� 
	{
		m_aDrawObj.Add(pArc->clone());
		delete pArc;
	}
}

CDrawObj& CPolyline::operator =(const CDrawObj& rhs)
{
	if (this == &rhs)
		return *this;
	CDrawObj::operator=(rhs);
	// Add code to serialize member variable
}
CPolyline& CPolyline::operator =(const CPolyline& rhs)
{
	if (this == &rhs)
		return *this;
	
	for (int i = 0; i < m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	CDrawObj::operator=(rhs);
	this->m_nLibArtworkLayNo = rhs.m_nLibArtworkLayNo;
	for (int i = 0; i < rhs.m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = rhs.m_aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());
	}
	return *this;
}

BOOL CPolyline::operator==(const CDrawObj & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CPolyline::operator!=(const CDrawObj& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}

CDrawObj* CPolyline::clone()
{
	return new CPolyline(*this);
}
// const int CPolyline::m_nVersion = 1;