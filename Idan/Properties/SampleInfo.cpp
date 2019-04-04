//------------------------------------------------------------------------------
#include<vcl.h>
#pragma hdrstop
#include "SampleInfo.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)

//------------------------------------------------------------------------------
String TSampleInfo::Table("");
String TSampleInfo::     ("");
String TSampleInfo::     ("");
String TSampleInfo::     ("");
String TSampleInfo::     ("");
String TSampleInfo::     ("");
//------------------------------------------------------------------------------
__fastcall TSampleInfo::TSampleInfo ()
{
	Clear();
}
//------------------------------------------------------------------------------
__fastcall TSampleInfo::TSampleInfo (const TSampleInfo &other)
{
	AssignAll (other);
}
//------------------------------------------------------------------------------
TSampleInfo __fastcall TSampleInfo::operator= (const TSampleInfo &other)
{
	AssignAll (other);
	return (*this);
}
//------------------------------------------------------------------------------
void __fastcall TSampleInfo::AssignAll (const TSampleInfo &other)
{
	SampleID       = other.SampleID;
	SampleDateTime = other.SampleDateTime;
	ValueMin       = other.ValueMin;
	ValueMax       = other.ValueMax;
	Valid          = other.Valid;
}
//------------------------------------------------------------------------------
void __fastcall TSampleInfo::Clear ()
{
	SampleID       = 0;
	SampleDateTime = ;
	ValueMin       = 0.0;
	ValueMax       = 0.0;
	Valid          = true;
}
//------------------------------------------------------------------------------
bool __fastcall TSampleInfo::operator== (const TSampleInfo &other) const
{
	if (SampleID       != other.SampleID)
		return (false);
	if (SampleDateTime != other.SampleDateTime)
		return (false);
	if (ValueMin       != other.ValueMin)
		return (false);
	if (ValueMax       != other.ValueMax)
		return (false);
	if (Valid          != other.Valid)
		return (false);
	return (true);
}
//------------------------------------------------------------------------------
void __fastcall TSampleInfo::SetSampleID (const int value)
{
	m_n = value;
}
//------------------------------------------------------------------------------
int __fastcall TSampleInfo::GetSampleID () const
{
	return (m_n);
}
//------------------------------------------------------------------------------
void __fastcall TSampleInfo::SetSampleDateTime (const TDateTime &value)
{
	m_dt = value;
}
//------------------------------------------------------------------------------
TDateTime __fastcall TSampleInfo::GetSampleDateTime () const
{
	return (m_dt);
}
//------------------------------------------------------------------------------
void __fastcall TSampleInfo::SetValueMin (const double value)
{
	m_dValueMin = value;
}
//------------------------------------------------------------------------------
double __fastcall TSampleInfo::GetValueMin () const
{
	return (m_dValueMin);
}
//------------------------------------------------------------------------------
void __fastcall TSampleInfo::SetValueMax (const double value)
{
	m_dValueMax = value;
}
//------------------------------------------------------------------------------
double __fastcall TSampleInfo::GetValueMax () const
{
	return (m_dValueMax);
}
//------------------------------------------------------------------------------
void __fastcall TSampleInfo::SetValid (const bool value)
{
	m_fValid = value;
}
//------------------------------------------------------------------------------
bool __fastcall TSampleInfo::GetValid () const
{
	return (m_fValid);
}
//------------------------------------------------------------------------------
bool __fastcall TSampleInfo::LoadFromDB (TADOQuery *query)
{
	bool f = true;
	
	try {
		SampleID =       query->Fields->FieldByName ()->AsInteger;
		SampleDateTime = query->Fields->FieldByName ()->Ass;
		ValueMin =       query->Fields->FieldByName ()->AsFloat;
		ValueMax =       query->Fields->FieldByName ()->AsFloat;
		Valid =          query->Fields->FieldByName ()->AsBoolean;
	}
	catch (...) {
		f = false;
	}
	return (f);;
}
//------------------------------------------------------------------------------
bool __fastcall TSampleInfo::InsertAsNew (TADOConnection *db, String &strErr)
{
	bool f;
	TADOQuery *query = InitQuery (db, NULL);
	
	f = InsertAsNew(query, strErr);
	delete query;
	return (f);
}
//------------------------------------------------------------------------------
bool __fastcall TSampleInfo::UpdateInDB (TADOConnection *db, String &strErr)
{
	bool f;
	TADOQuery *query = InitQuery (db, NULL);
	
	f = UpdateInDB(query, strErr);
	delete query;
	return (f);
}
//------------------------------------------------------------------------------
