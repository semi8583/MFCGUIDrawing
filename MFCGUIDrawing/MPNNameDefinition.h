#pragma once
#include <iostream>
using namespace std;

class CMPNNameDefinition
{
public:
	string m_sMPNName;
public:
	CMPNNameDefinition();
	CMPNNameDefinition(const CMPNNameDefinition& src);
	virtual ~CMPNNameDefinition();
	void vSetMPNname(string sMPNName);
	virtual CMPNNameDefinition & operator =(const CMPNNameDefinition & rhs);
	virtual BOOL operator==(const CMPNNameDefinition & rhs);
	BOOL operator!=(const CMPNNameDefinition & rhs);

	virtual CMPNNameDefinition* clone();
	//virtual void Serialize(CArchive& ar);

protected:
private:
	//static const int m_nVersion ;
};