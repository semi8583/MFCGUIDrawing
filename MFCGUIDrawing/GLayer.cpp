#include "stdafx.h"
#include "GLayer.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CGLayer::CGLayer()
{
	cout << "생성자 CGLayer() 호출" << endl;
}
CGLayer::CGLayer(const CGLayer& src)
{
	*this = src;
}
CGLayer::~CGLayer()
{
	for (int i = 0; m_aDrawObj.GetSize(); i++)
	{
		CDrawObj* pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();
	
	cout << "소멸자 ~CGLayer() 호출" << endl;
}
void CGLayer::vSetGLayer(int nArtworkLayerNo, CDrawObjArray aDrawObj)
{
	m_nArtworkLayerNo = nArtworkLayerNo;
	for (int i = 0; m_aDrawObj.GetSize(); i++)
	{
		CDrawObj* pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	for (int i = 0; i < aDrawObj.GetSize(); i++)
	{
		CDrawObj* pItem = aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());
		delete pItem;
	}

}
CGLayer& CGLayer::operator =(const CGLayer& rhs)
{
	if (this == &rhs)
		return *this;


	for (int i = 0; m_aDrawObj.GetSize(); i++)
	{
		CDrawObj* pItem = m_aDrawObj.GetAt(i);
		delete pItem;
	}
	m_aDrawObj.RemoveAll();

	for (int i = 0; i < rhs.m_aDrawObj.GetSize(); i++)
	{
		CDrawObj * pItem = rhs.m_aDrawObj.GetAt(i);
		this->m_aDrawObj.Add(pItem->clone());
	}
	this->m_nArtworkLayerNo = rhs.m_nArtworkLayerNo;

	// Add code to serialize member variable
	return *this;
}


BOOL CGLayer::operator==(const CGLayer & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CGLayer::operator!=(const CGLayer& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CGLayer* CGLayer::clone()
{
	return new CGLayer(*this);

}
//const int CGLayer::m_nVersion = 1;


CGLayerArray::CGLayerArray()
{
}
CGLayerArray::CGLayerArray(const CGLayerArray& src)
{
	*this = src;
}
CGLayerArray::~CGLayerArray()
{
	for (int i = 0; GetSize(); i++)
	{
		CGLayer* pItem =GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CGLayerArray& CGLayerArray::operator =(const CGLayerArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; GetSize(); i++)
	{
		CGLayer* pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CGLayer* pItem = new CGLayer();
		pItem->m_nArtworkLayerNo = rhs.GetAt(i)->m_nArtworkLayerNo;
		for (int j = 0; j < rhs.GetAt(i)->m_aDrawObj.GetSize(); j++)
		{
			CDrawObj * pItem2 = new CDrawObj();
			pItem2 = rhs.GetAt(i)->m_aDrawObj.GetAt(j);
			pItem->m_aDrawObj.Add(pItem2->clone());
			delete pItem2;
		}
		this->Add(pItem->clone());
		delete pItem;
	}

	return *this;
}

bool CGLayerArray::operator==(const CGLayerArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CGLayer* pItem1;
	CGLayer* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CGLayerArray::operator!=(const CGLayerArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CGLayerArray* CGLayerArray::clone()
{
	return new CGLayerArray(*this);

}