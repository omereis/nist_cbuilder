//------------------------------------------------------------------------------
#include<vcl.h>
#pragma hdrstop
#include "ChannelInfo.h"
//------------------------------------------------------------------------------
#include <System.StrUtils.hpp>
#include "Misc.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------
__fastcall TChannelInfo::TChannelInfo ()
{
	Clear();
}
//------------------------------------------------------------------------------
__fastcall TChannelInfo::TChannelInfo (const TChannelInfo &other)
{
	AssignAll (other);
}
//------------------------------------------------------------------------------
TChannelInfo __fastcall TChannelInfo::operator= (const TChannelInfo &other)
{
	AssignAll (other);
	return (*this);
}
//------------------------------------------------------------------------------
void __fastcall TChannelInfo::AssignAll (const TChannelInfo &other)
{
	ChannelName = other.ChannelName;
	Samples     = other.Samples;
}
//------------------------------------------------------------------------------
void __fastcall TChannelInfo::Clear ()
{
	ChannelName = "";
	Samples     = TSampleInfoVec();
}
//------------------------------------------------------------------------------
bool __fastcall TChannelInfo::operator== (const TChannelInfo &other) const
{
	if (ChannelName != other.ChannelName)
		return (false);
	if (Samples     != other.Samples)
		return (false);
	return (true);
}
//------------------------------------------------------------------------------
void __fastcall TChannelInfo::SetChannelName (const String &value)
{
	m_strChannelName = value;
}
//------------------------------------------------------------------------------
String __fastcall TChannelInfo::GetChannelName () const
{
	return (m_strChannelName);
}
//------------------------------------------------------------------------------
void __fastcall TChannelInfo::SetSamples (const TSampleInfoVec &value)
{
	m_vSamples = value;
}
//------------------------------------------------------------------------------
TSampleInfoVec __fastcall TChannelInfo::GetSamples () const
{
	return (m_vSamples);
}
//------------------------------------------------------------------------------
//  TChannelInfoVec
//------------------------------------------------------------------------------
__fastcall TChannelInfoVec::TChannelInfoVec ()
	: TChannelInfoBase ()
{

}
//------------------------------------------------------------------------------
void TChannelInfoVec::ParseChannels (const String &strLineSource)
{
	String strLine;
	TStringList *lstr = NULL;
	TChannelInfo ci;
	int nCount;

	strLine = ReplaceStr (strLineSource, "\"", "");
	try {
		lstr = new TStringList;
		nCount = Tokenize (strLine, lstr, ",");
		for (int n=1 ; n < nCount ; n++) {
			ci.ChannelName = lstr->Strings[n];
			push_back (ci);
            ci.Clear();
        }
	}
	__finally {
		if (lstr)
			delete lstr;
	}
}
//------------------------------------------------------------------------------

