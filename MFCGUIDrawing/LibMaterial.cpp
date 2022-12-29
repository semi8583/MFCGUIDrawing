#include "stdafx.h"
#include "LibMaterial.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CLibMaterial::CLibMaterial()
{
	cout << "생성자 CLibMaterial() 호출" << endl;
}
CLibMaterial::CLibMaterial(const CLibMaterial& src)
{
	*this = src;
}
CLibMaterial:: ~CLibMaterial()
{
	for (int i = 0; i < this->m_aMaterial.GetSize(); i++)
	{
		CMaterial * pItem = m_aMaterial.GetAt(i);
		delete pItem;
	}
	m_aMaterial.RemoveAll();
	cout << "소멸자 ~CLibMaterial() 호출" << endl;
}
void CLibMaterial::vSetCLibMaterial(CMaterialArray aMaterial)
{
	for (int i = 0; i < this->m_aMaterial.GetSize(); i++)
	{
		CMaterial * pItem = m_aMaterial.GetAt(i);
		delete pItem;
	}
	m_aMaterial.RemoveAll();

	for (int i = 0; i < aMaterial.GetSize(); i++)
	{
		CMaterial * pItem = aMaterial.GetAt(i);
		this->m_aMaterial.Add(pItem->clone());
		delete pItem;
	}

}
CLibMaterial& CLibMaterial::operator =(const CLibMaterial& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < this->m_aMaterial.GetSize(); i++)
	{
		CMaterial * pItem = m_aMaterial.GetAt(i);
		delete pItem;
	}
	m_aMaterial.RemoveAll();


	for (int i = 0; i < rhs.m_aMaterial.GetSize(); i++)
	{
		CMaterial * pItem = rhs.m_aMaterial.GetAt(i);
		this->m_aMaterial.Add(pItem->clone());
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CLibMaterial::operator==(const CLibMaterial & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CLibMaterial::operator!=(const CLibMaterial& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLibMaterial* CLibMaterial::clone()
{
	return new CLibMaterial(*this);

}
//const int CLibMaterial::m_nVersion = 1;



CMaterialArray::CMaterialArray()
{
}
CMaterialArray::CMaterialArray(const CMaterialArray& src)
{
	*this = src;
}
CMaterialArray::~CMaterialArray()
{
	for (int i = 0; i < GetSize(); i++)
	{
		CMaterial * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();
}

CMaterialArray& CMaterialArray::operator =(const CMaterialArray& rhs)
{
	if (this == &rhs)
		return *this;

	for (int i = 0; i < GetSize(); i++)
	{
		CMaterial * pItem = GetAt(i);
		delete pItem;
	}
	RemoveAll();

	for (int i = 0; i < rhs.GetSize(); i++)
	{
		CMaterial* pItem = new CMaterial();
		pItem->m_dThermalConductivityX = rhs.GetAt(i)->m_dThermalConductivityX;
		pItem->m_dThermalConductivityY = rhs.GetAt(i)->m_dThermalConductivityY;
		pItem->m_dThermalConductivityZ = rhs.GetAt(i)->m_dThermalConductivityZ;
		pItem->m_Frequency = rhs.GetAt(i)->m_Frequency;
		pItem->m_sMaterialName = rhs.GetAt(i)->m_sMaterialName;
		pItem->m_sMaterialType = rhs.GetAt(i)->m_sMaterialType;
		this->Add(pItem->clone());
	}

	return *this;
}

bool CMaterialArray::operator==(const CMaterialArray& rhs) const
{
	if (this == &rhs)
		return TRUE;

	if (GetSize() != rhs.GetSize())
		return FALSE;

	CMaterial* pItem1;
	CMaterial* pItem2;
	for (int i = 0; i < GetSize(); i++)
	{
		pItem1 = GetAt(i);
		pItem2 = rhs.GetAt(i);
		if (*pItem1 != *pItem2)
			return FALSE;
	}

	return TRUE;
}

bool CMaterialArray::operator!=(const CMaterialArray& rhs) const
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CMaterialArray* CMaterialArray::clone()
{
	return new CMaterialArray(*this);

}