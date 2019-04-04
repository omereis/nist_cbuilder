//------------------------------------------------------------------------------
#include<vcl.h>
#pragma hdrstop
#include "ChannelInfo.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)

//------------------------------------------------------------------------------
String TChannelInfo::Table("");
String TChannelInfo::     ("");
String TChannelInfo::     ("");
String TChannelInfo::     ("");
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
	            = other.;
}
//------------------------------------------------------------------------------
void __fastcall TChannelInfo::Clear ()
{
	ChannelName = "";
	Samples     = ;
	            = ;
}
//------------------------------------------------------------------------------
bool __fastcall TChannelInfo::operator== (const TChannelInfo &other) const
{
	if (ChannelName != other.ChannelName)
		return (false);
	if (Samples     != other.Samples)
		return (false);
	if (            != other.)
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
void __fastcall TChannelInfo::Set (const TSampleInfoVec value)
{
	 = value;
}
//------------------------------------------------------------------------------
TSampleInfoVec __fastcall TChannelInfo::Get () const
{
	return ();
}
//------------------------------------------------------------------------------
bool __fastcall TChannelInfo::LoadFromDB (TADOQuery *query)
{
	bool f = true;
	
	try {
		ChannelName = query->Fields->FieldByName ()->AsString;
		Samples =     query->Fields->FieldByName ()->Ass;
		 =            query->Fields->FieldByName ()->Ass;
	}
	catch (...) {
		f = false;
	}
	return (f);;
}
//------------------------------------------------------------------------------
bool __fastcall TChannelInfo::InsertAsNew (TADOConnection *db, String &strErr)
{
	bool f;
	TADOQuery *query = InitQuery (db, NULL);
	
	f = InsertAsNew(query, strErr);
	delete query;
	return (f);
}
//------------------------------------------------------------------------------
bool __fastcall TChannelInfo::UpdateInDB (TADOConnection *db, String &strErr)
{
	bool f;
	TADOQuery *query = InitQuery (db, NULL);
	
	f = UpdateInDB(query, strErr);
	delete query;
	return (f);
}
//------------------------------------------------------------------------------
