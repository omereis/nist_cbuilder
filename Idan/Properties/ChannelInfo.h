//------------------------------------------------------------------------------
#ifndef	ChannelInfoH
#define	ChannelInfoH
//------------------------------------------------------------------------------
#include <ADODB.hpp>
#include "DBMisc.h"
#include <vector>
using namespace std;
//------------------------------------------------------------------------------
class TChannelInfo;
typedef vector<TChannelInfo> TChannelInfoBase;
//------------------------------------------------------------------------------
class TChannelInfo {
public:
	__fastcall TChannelInfo ();
	__fastcall TChannelInfo (const TChannelInfo &other);
	TChannelInfo __fastcall operator= (const TChannelInfo &other);
	bool __fastcall operator!= (const TChannelInfo &other) const;
	bool __fastcall operator== (const TChannelInfo &other) const;
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
	__property String ChannelName = {read=GetChannelName, write=SetChannelName};
	__property TSampleInfoVec Samples = {read=GetSamples, write=SetSamples};
	__property TSampleInfoVec  = {read=Get, write=Set};
// ---------- S t a t i c ----------
	static String Table;
	static String ;
	static String ;
	static String ;
protected:
	void __fastcall AssignAll (const TChannelInfo &other);
private:
	String m_strChannelName;
	TSampleInfoVec m_vSamples;
	TSampleInfoVec ;
//------------------------------------------------------------------------------
	String __fastcall GetChannelName () const;
	TSampleInfoVec __fastcall GetSamples () const;
	TSampleInfoVec __fastcall Get () const;
//------------------------------------------------------------------------------
	void __fastcall SetChannelName (const String &value);
	void __fastcall SetSamples (const TSampleInfoVec &value);
	void __fastcall Set (const TSampleInfoVec value);
};
//------------------------------------------------------------------------------
class TChannelInfoVec : public TChannelInfoBase {
public:
	__fastcall TChannelInfoVec ();
// Vector Database Support
	bool __fastcall LoadFromDB (TADOQuery *query, String &strErr);
	bool __fastcall LoadFromDB (TADOConnection *db, String &strErr);
};
//------------------------------------------------------------------------------
#endif
