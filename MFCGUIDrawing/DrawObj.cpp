#include "stdafx.h"
#include "DrawObj.h"
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif

CDrawObj::CDrawObj()
{
	cout << "생성자 CDrawObj() 호출" << endl;
}
CDrawObj::CDrawObj(const CDrawObj& src)
{
	*this = src;
}
CDrawObj::~CDrawObj()
{
	cout << "소멸자 ~CDrawObj() 호출" << endl;
}
CDrawObj& CDrawObj::operator =(const CDrawObj& rhs)
{
	if (this == &rhs)
		return *this;
	// Add code to serialize member variable
	return *this;
}


BOOL CDrawObj::operator==(const CDrawObj & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CDrawObj::operator!=(const CDrawObj& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CDrawObj* CDrawObj::clone()
{
	return new CDrawObj(*this);

}

CDrawObjArray::CDrawObjArray()
{
}
CDrawObjArray::CDrawObjArray(const CDrawObjArray& src)
{
	*this = src;
}
CDrawObjArray::~CDrawObjArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CDrawObj * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CDrawObjArray& CDrawObjArray::operator =(const CDrawObjArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CDrawObj * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CDrawObj* pItem = rhs.GetAt(i);
		this->Add(pItem->clone());
		//delete pItem;
	}

	return *this;
}

bool CDrawObjArray::operator==(const CDrawObjArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CDrawObj* pItem1;
	CDrawObj* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CDrawObjArray::operator!=(const CDrawObjArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CDrawObjArray* CDrawObjArray::clone()
{
	return new CDrawObjArray(*this);

}
//const int CDrawObjArray::m_nVersion = 1;
//
//void CDrawObjArray::Serialize(CArchive& ar)
//{
//#if defined(POLEX_WIN64)
//	unsigned long long i;
//	unsigned long long nArraySize;
//#else
//	int i;
//	int nArraySize;
//#endif
//	CDrawObj* pItem;
//
//	//int nVersion = CDrawObjArray::m_nVersion;
//
//	if (ar.IsStoring())
//	{
//		ar << (nVersion);
//		nArraySize = GetSize();
//		ar << nArraySize;
//		for (i = 0; i < nArraySize; i++)
//		{
//			pItem = GetAt(i);
//			//pItem->Serialize(ar);
//		}
//	}
//	else
//	{
//		this->RemoveAll();
//
//		int nVersion;
//		ar >> nVersion;
//
//		/*const bool bIs64 = (nVersion & FLAG64) != 0;*/
//		const bool bIs64 = (nVersion) != 0;
//		nVersion = nVersion & (~FLAG64);
//		if (nVersion > CDrawObjArray::m_nVersion)
//		{
//			TRACE("Incorrect class version(CItemArray)!!\n");
//			return;
//		}
//
//		if (nVersion >= 1)
//		{
//			if (bIs64)
//				ar >> nArraySize;
//			else
//			{
//				int nOldSize;
//				ar >> nOldSize;
//				nArraySize = nOldSize;
//			}
//			for (i = 0; i < nArraySize; i++)
//			{
//				pItem = new CDrawObj;
//				pItem->Serialize(ar);
//				Add(pItem);
//			}
//		}
//	}
//}
