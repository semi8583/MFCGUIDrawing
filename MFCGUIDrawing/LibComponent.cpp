#include "stdafx.h"
#include "LibComponent.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CLibComponent::CLibComponent()
{
	cout << "생성자 CLibComponent() 호출" << endl;
}
CLibComponent::CLibComponent(const CLibComponent& src)
{
	*this = src;
}
CLibComponent::~CLibComponent()
{
	for (int i = 0; i < m_aPart.GetSize(); i++)
	{
		CPart * pItem = m_aPart.GetAt(i);
		delete pItem;
	}
	m_aPart.RemoveAll();

	cout << "소멸자 ~CLibComponent() 호출" << endl;
}
void CLibComponent::vSetCLibComponent(CPartArray aPart)
{
	for (int i = 0; m_aPart.GetSize(); i++)
	{
		CPart * pItem = m_aPart.GetAt(i);
		delete pItem;
	}
	m_aPart.RemoveAll();

	for (int i = 0; i < aPart.GetSize(); i++)
	{
		CPart * pItem = new CPart();
		for (int j = 0; j < aPart[i]->m_aPinConnection.GetSize(); j++)
		{
			CPinConnection* pItem2 = new CPinConnection();
			pItem2->m_dValue = aPart[i]->m_aPinConnection[j]->m_dValue;
			pItem2->m_sConnectType = aPart[i]->m_aPinConnection[j]->m_sConnectType;
			pItem2->m_sFirstPinName = aPart[i]->m_aPinConnection[j]->m_sFirstPinName;
			pItem2->m_sSecondPinName = aPart[i]->m_aPinConnection[j]->m_sSecondPinName;
			pItem->m_aPinConnection.Add(pItem2->clone());
			delete pItem2;
		}
		for (int j = 0; j < aPart[i]->m_aPinDefinition.GetSize(); j++)
		{
			CPinDefinition* pItem2 = new CPinDefinition();
			pItem2->m_dAngle = aPart[i]->m_aPinDefinition[j]->m_dAngle;
			pItem2->m_dPtX = aPart[i]->m_aPinDefinition[j]->m_dPtX;
			pItem2->m_dPtY = aPart[i]->m_aPinDefinition[j]->m_dPtY;
			pItem2->m_nLibPadStackNo = aPart[i]->m_aPinDefinition[j]->m_nLibPadStackNo;
			pItem2->m_nPinNo = aPart[i]->m_aPinDefinition[j]->m_nPinNo;
			pItem2->m_nSymbolNo = aPart[i]->m_aPinDefinition[j]->m_nSymbolNo;
			pItem2->m_sGatePinName = aPart[i]->m_aPinDefinition[j]->m_sGatePinName;
			pItem2->m_sPinName = aPart[i]->m_aPinDefinition[j]->m_sPinName;
			pItem2->m_sPinType = aPart[i]->m_aPinDefinition[j]->m_sPinType;

			pItem->m_aPinDefinition.Add(pItem2->clone());
			delete pItem2;
		}
		for (int j = 0; j < aPart[i]->m_aProperty.GetSize(); j++)
		{
			CPropertys* pItem2 = new CPropertys();
			pItem2->m_sPropertyContents = aPart[i]->m_aProperty[j]->m_sPropertyContents;
			pItem2->m_sPropertyItem = aPart[i]->m_aProperty[j]->m_sPropertyItem;

			pItem->m_aProperty.Add(pItem2->clone());
			delete pItem2;
		}

		pItem->m_bIsBroken = aPart[i]->m_bIsBroken;
		pItem->m_CMPNNameDefinition = aPart[i]->m_CMPNNameDefinition;
		pItem->m_dDrawingSizeX = aPart[i]->m_dDrawingSizeX;
		pItem->m_dDrawingSizeY = aPart[i]->m_dDrawingSizeY;
		pItem->m_dHeight = aPart[i]->m_dHeight;
		pItem->m_dHighHeight = aPart[i]->m_dHighHeight;
		pItem->m_dLowHeight = aPart[i]->m_dLowHeight;
		pItem->m_FigureDefinition = aPart[i]->m_FigureDefinition;
		pItem->m_NameDefinition = aPart[i]->m_NameDefinition;
		pItem->m_nLibPartNo = aPart[i]->m_nLibPartNo;
		pItem->m_SilkScreenDefinition = aPart[i]->m_SilkScreenDefinition;
		pItem->m_SymbolDefinition = aPart[i]->m_SymbolDefinition;

		this->m_aPart.Add(pItem->clone());
		delete pItem;
	}
}
CLibComponent& CLibComponent::operator =(const CLibComponent& rhs)
{
	if (this == &rhs)
		return *this;
	
	for (int i = 0; m_aPart.GetSize(); i++)
	{
		CPart * pItem = m_aPart.GetAt(i);
		delete pItem;
	}
	m_aPart.RemoveAll();

	for (int i = 0; i < rhs.m_aPart.GetSize(); i++)
	{
		CPart * pItem = new CPart();
		for (int j = 0; j < rhs.m_aPart[i]->m_aPinConnection.GetSize(); j++)
		{
			CPinConnection* pItem2 = new CPinConnection();
			pItem2->m_dValue = rhs.m_aPart[i]->m_aPinConnection[j]->m_dValue;
			pItem2->m_sConnectType = rhs.m_aPart[i]->m_aPinConnection[j]->m_sConnectType;
			pItem2->m_sFirstPinName = rhs.m_aPart[i]->m_aPinConnection[j]->m_sFirstPinName;
			pItem2->m_sSecondPinName = rhs.m_aPart[i]->m_aPinConnection[j]->m_sSecondPinName;
			pItem->m_aPinConnection.Add(pItem2->clone());
			delete pItem2;
		}
		for (int j = 0; j < rhs.m_aPart[i]->m_aPinDefinition.GetSize(); j++)
		{
			CPinDefinition* pItem2 = new CPinDefinition();
			pItem2->m_dAngle = rhs.m_aPart[i]->m_aPinDefinition[j]->m_dAngle;
			pItem2->m_dPtX = rhs.m_aPart[i]->m_aPinDefinition[j]->m_dPtX;
			pItem2->m_dPtY = rhs.m_aPart[i]->m_aPinDefinition[j]->m_dPtY;
			pItem2->m_nLibPadStackNo = rhs.m_aPart[i]->m_aPinDefinition[j]->m_nLibPadStackNo;
			pItem2->m_nPinNo = rhs.m_aPart[i]->m_aPinDefinition[j]->m_nPinNo;
			pItem2->m_nSymbolNo = rhs.m_aPart[i]->m_aPinDefinition[j]->m_nSymbolNo;
			pItem2->m_sGatePinName = rhs.m_aPart[i]->m_aPinDefinition[j]->m_sGatePinName;
			pItem2->m_sPinName = rhs.m_aPart[i]->m_aPinDefinition[j]->m_sPinName;
			pItem2->m_sPinType = rhs.m_aPart[i]->m_aPinDefinition[j]->m_sPinType;

			pItem->m_aPinDefinition.Add(pItem2->clone());
			delete pItem2;
		}
		for (int j = 0; j < rhs.m_aPart[i]->m_aProperty.GetSize(); j++)
		{
			CPropertys* pItem2 = new CPropertys();
			pItem2->m_sPropertyContents = rhs.m_aPart[i]->m_aProperty[j]->m_sPropertyContents;
			pItem2->m_sPropertyItem = rhs.m_aPart[i]->m_aProperty[j]->m_sPropertyItem;

			pItem->m_aProperty.Add(pItem2->clone());
			delete pItem2;
		}

		pItem->m_bIsBroken = rhs.m_aPart[i]->m_bIsBroken;
		pItem->m_CMPNNameDefinition = rhs.m_aPart[i]->m_CMPNNameDefinition;
		pItem->m_dDrawingSizeX = rhs.m_aPart[i]->m_dDrawingSizeX;
		pItem->m_dDrawingSizeY = rhs.m_aPart[i]->m_dDrawingSizeY;
		pItem->m_dHeight = rhs.m_aPart[i]->m_dHeight;
		pItem->m_dHighHeight = rhs.m_aPart[i]->m_dHighHeight;
		pItem->m_dLowHeight = rhs.m_aPart[i]->m_dLowHeight;
		pItem->m_FigureDefinition = rhs.m_aPart[i]->m_FigureDefinition;
		pItem->m_NameDefinition = rhs.m_aPart[i]->m_NameDefinition;
		pItem->m_nLibPartNo = rhs.m_aPart[i]->m_nLibPartNo;
		pItem->m_SilkScreenDefinition = rhs.m_aPart[i]->m_SilkScreenDefinition;
		pItem->m_SymbolDefinition = rhs.m_aPart[i]->m_SymbolDefinition;

		this->m_aPart.Add(pItem->clone());
		delete pItem;
	}
	// Add code to serialize member variable
	return *this;
}


BOOL CLibComponent::operator==(const CLibComponent & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CLibComponent::operator!=(const CLibComponent& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CLibComponent* CLibComponent::clone()
{
	return new CLibComponent(*this);

}
//const int CLibComponent::m_nVersion = 1;