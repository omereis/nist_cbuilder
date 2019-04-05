//------------------------------------------------------------------------------
#include<vcl.h>
#pragma hdrstop
#include "SampleInfo.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)

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
	MinValid       = other.MinValid;
	MaxValid       = other.MaxValid;
}
//------------------------------------------------------------------------------
void __fastcall TSampleInfo::Clear ()
{
	SampleID       = 0;
	SampleDateTime = Now();
	ValueMin       = 0.0;
	ValueMax       = 0.0;
	MinValid       = true;
	MaxValid       = true;
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
	if (MinValid       != other.MinValid)
		return (false);
	if (MaxValid       != other.MaxValid)
		return (false);
	return (true);
}
//------------------------------------------------------------------------------
void __fastcall TSampleInfo::SetSampleID (const int value)
{
	m_nSampleID = value;
}
//------------------------------------------------------------------------------
int __fastcall TSampleInfo::GetSampleID () const
{
	return (m_nSampleID);
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
void __fastcall TSampleInfo::SetMinValid (const bool value)
{
	m_fMinValid = value;
}
//------------------------------------------------------------------------------
bool __fastcall TSampleInfo::GetMinValid () const
{
	return (m_fMinValid);
}
//------------------------------------------------------------------------------
void __fastcall TSampleInfo::SetMaxValid (const bool value)
{
	m_fMaxValid = value;
}
//------------------------------------------------------------------------------
bool __fastcall TSampleInfo::GetMaxValid () const
{
	return (m_fMaxValid);
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
__fastcall TSampleInfoVec::TSampleInfoVec ()
	: TSampleInfoBase ()
{

}
//------------------------------------------------------------------------------

