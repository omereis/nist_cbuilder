//------------------------------------------------------------------------------
#ifndef	ChannelInfoH
#define	ChannelInfoH
//------------------------------------------------------------------------------
#include "SampleInfo.h"
//------------------------------------------------------------------------------
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
//----- P r o p e r t i e s -----------------------------------------------
	__property String ChannelName = {read=GetChannelName, write=SetChannelName};
	__property TSampleInfoVec Samples = {read=GetSamples, write=SetSamples};
protected:
	void __fastcall AssignAll (const TChannelInfo &other);
private:
	String m_strChannelName;
	TSampleInfoVec m_vSamples;
//------------------------------------------------------------------------------
	String __fastcall GetChannelName () const;
	TSampleInfoVec __fastcall GetSamples () const;
//------------------------------------------------------------------------------
	void __fastcall SetChannelName (const String &value);
	void __fastcall SetSamples (const TSampleInfoVec &value);
};
//------------------------------------------------------------------------------
class TChannelInfoVec : public TChannelInfoBase {
public:
	__fastcall TChannelInfoVec ();
};
//------------------------------------------------------------------------------
#endif
