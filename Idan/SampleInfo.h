//------------------------------------------------------------------------------
#ifndef	SampleInfoH
#define	SampleInfoH
//------------------------------------------------------------------------------
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
//----- P r o p e r t i e s -----------------------------------------------
	__property int SampleID = {read=GetSampleID, write=SetSampleID};
	__property TDateTime SampleDateTime = {read=GetSampleDateTime, write=SetSampleDateTime};
	__property double ValueMin = {read=GetValueMin, write=SetValueMin};
	__property double ValueMax = {read=GetValueMax, write=SetValueMax};
	__property bool Valid = {read=GetValid, write=SetValid};
protected:
	void __fastcall AssignAll (const TSampleInfo &other);
private:
	int m_nSampleID;
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

};
//------------------------------------------------------------------------------
#endif
