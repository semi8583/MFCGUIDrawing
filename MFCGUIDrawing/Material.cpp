#include "stdafx.h"
#include "Material.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define _CRTDBG_MAPALLOC
#endif
CMaterial::CMaterial()
{
	cout << "생성자 CMaterial() 호출" << endl;
}
CMaterial::CMaterial(const CMaterial& src)
{
	*this = src;
}
CMaterial:: ~CMaterial()
{
	cout << "소멸자 ~CMaterial() 호출" << endl;
}
void CMaterial::vSetCMaterial(string sMaterialName, string sMaterialType, double dThermalConductivityX, double dThermalConductivityY
	, double dThermalConductivityZ, CFrequency Frequency)
{
	m_sMaterialName = sMaterialName;
	m_sMaterialType = sMaterialType;
	m_dThermalConductivityX = dThermalConductivityX;
	m_dThermalConductivityY = dThermalConductivityY;
	m_dThermalConductivityZ = dThermalConductivityZ;
	m_Frequency = Frequency;
}
CMaterial& CMaterial::operator =(const CMaterial& rhs)
{
	if (this == &rhs)
		return *this;
	this->m_sMaterialName = rhs.m_sMaterialName;
	this->m_sMaterialType = rhs.m_sMaterialType;
	this->m_dThermalConductivityX = rhs.m_dThermalConductivityX;
	this->m_dThermalConductivityY = rhs.m_dThermalConductivityY;
	this->m_dThermalConductivityZ = rhs.m_dThermalConductivityZ;

	this->m_Frequency.m_dFrequency = rhs.m_Frequency.m_dFrequency;
	this->m_Frequency.m_dElectricProperty1 = rhs.m_Frequency.m_dElectricProperty1;
	this->m_Frequency.m_dElectricProperty2 = rhs.m_Frequency.m_dElectricProperty2;
	// Add code to serialize member variable
	return *this;
}


BOOL CMaterial::operator==(const CMaterial & rhs)
{
	if (this == &rhs)
		return TRUE;
	// Member 
	return FALSE;
}


BOOL CMaterial::operator!=(const CMaterial& rhs)
{
	if (*this == rhs)
		return FALSE;

	return TRUE;
}
CMaterial* CMaterial::clone()
{
	return new CMaterial(*this);

}
// const int CMaterial::m_nVersion = 1;
