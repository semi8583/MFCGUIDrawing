#pragma once
#include <iostream>


using namespace std;

class CNetClassList
{
public:
	string m_sClassName;
	CArray<string> m_saStringFilter;//메타 캐릭터
public:
	CNetClassList();
	CNetClassList(const CNetClassList& src);
	virtual ~CNetClassList();
	void vSetNetClassList(string ClassName, CArray<string>  saStringFilter);
	virtual CNetClassList & operator =(const CNetClassList & rhs);
	virtual BOOL operator==(const CNetClassList & rhs);
	BOOL operator!=(const CNetClassList & rhs);
	virtual CNetClassList* clone();
	//virtual CNetClassList* clone() const { return new CNetClassList(*this); }
	//virtual void Serialize(CArchive& ar);
//
//protected:
//private:
	//static const int m_nVersion ;
};

class  CNetClassListArray : public CArray< CNetClassList *, CNetClassList * >
{
	//////////////////////////////////////////////////////////////////////////
	// Default Function & Variable 
public:
	CNetClassListArray();
	CNetClassListArray(const CNetClassListArray& src);
	virtual ~CNetClassListArray();

	virtual CNetClassListArray& operator =(const CNetClassListArray& rhs);
	virtual bool operator==(const CNetClassListArray& rhs) const;
	bool operator!=(const CNetClassListArray& rhs) const;
	virtual CNetClassListArray* clone();
	virtual CNetClassListArray * clone() const { return new CNetClassListArray(*this); }
	//virtual void Serialize(CArchive& ar);
	//protected:
	//private:
	//	static const int m_nVersion ;

};