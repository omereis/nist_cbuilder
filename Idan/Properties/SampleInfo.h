//------------------------------------------------------------------------------
#ifndef	SampleInfoH
#define	SampleInfoH
//------------------------------------------------------------------------------
#include <ADODB.hpp>
#include "DBMisc.h"
#include <vector>
using namespace std;
//------------------------------------------------------------------------------
class TSampleInfo;
typedef vector<TSampleInfo> TSampleInfoBase;
//------------------------------------------------------------------------------
class TSampleInfo {
public:
	__fastcall TSampleInfo ();
	__fastcall TSampleInfo (const TSampleInfo &other);
	TSampleInfo __fastcall operator= (const TSampleInfo &other);
	bool __fastcall operator!= (const TSampleInfo &other) const;
	bool __fastcall operator== (const TSampleInfo &other) const;
	void __fastcall Clear ();
// ---------- Database Support ----------
	bool __fastcall LoadFromDB (TADOQuery *query);
	bool __fastcall InsertAsNew (TADOConnection *db, String &strErr);
	bool __fastcall InsertAsNew (TADOQuery *query, String &strErr);
	bool __fastcall UpdateInDB (TADOConnection *db, String &strErr);
	bool __fastcall UpdateInDB (TADOQuery *query, String &strErr);
	bool __fastcall DeleteInDB (TADOConnection *db, String &strErr);
	bool __fastcall DeleteInDB (TADOQuery *query, String &strErr);
//----- P r o p e r t i e s -----------------------------------------------
	__property int SampleID = {read=GetSampleID, write=SetSampleID};
	__property TDateTime SampleDateTime = {read=GetSampleDateTime, write=SetSampleDateTime};
	__property double ValueMin = {read=GetValueMin, write=SetValueMin};
	__property double ValueMax = {read=GetValueMax, write=SetValueMax};
	__property bool Valid = {read=GetValid, write=SetValid};
// ---------- S t a t i c ----------
	static String Table;
	static String ;
	static String ;
	static String ;
	static String ;
	static String ;
protected:
	void __fastcall AssignAll (const TSampleInfo &other);
private:
	int m_n;
	TDateTime m_dt;
	double m_dValueMin;
	double m_dValueMax;
	bool m_fValid;
//------------------------------------------------------------------------------
	int __fastcall GetSampleID () const;
	TDateTime __fastcall GetSampleDateTime () const;
	double __fastcall GetValueMin () const;
	double __fastcall GetValueMax () const;
	bool __fastcall GetValid () const;
//------------------------------------------------------------------------------
	void __fastcall SetSampleID (const int value);
	void __fastcall SetSampleDateTime (const TDateTime &value);
	void __fastcall SetValueMin (const double value);
	void __fastcall SetValueMax (const double value);
	void __fastcall SetValid (const bool value);
};
//------------------------------------------------------------------------------
class TSampleInfoVec : public TSampleInfoBase {
public:
	__fastcall TSampleInfoVec ();
// Vector Database Support
	bool __fastcall LoadFromDB (TADOQuery *query, String &strErr);
	bool __fastcall LoadFromDB (TADOConnection *db, String &strErr);
};
//------------------------------------------------------------------------------
#endif
