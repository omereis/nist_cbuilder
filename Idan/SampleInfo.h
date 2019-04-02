//---------------------------------------------------------------------------

#ifndef SampleInfoH
#define SampleInfoH
//---------------------------------------------------------------------------
class TSampleInfo {
public:
	TSampleInfo ();
	TSampleInfo (const TSampleInfo &other);
	TSampleInfo operator= (const TSampleInfo &other);
	bool operator== (const TSampleInfo &other) const;
	bool operator!= (const TSampleInfo &other) const;
	void Clear ();
protected:
    void AssignAll (const TSampleInfo &other);
private:
	TDateTime m_dt;
	double m_rMin;
	double m_rMax;
	bool m_vValid;
};
#endif
