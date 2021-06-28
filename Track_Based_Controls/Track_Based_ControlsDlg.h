
// Track_Based_ControlsDlg.h : header file
//

#pragma once


// CTrackBasedControlsDlg dialog
class CTrackBasedControlsDlg : public CDialogEx
{
// Construction
public:
	CTrackBasedControlsDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TRACK_BASED_CONTROLS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_Preview;

private:
	COLORREF PreviewColor= RGB(192, 192, 192);;
	void UpdatePreview();
public:
	CSpinButtonCtrl m_SpinRed;
	CSpinButtonCtrl m_SpinGreen;
	CSpinButtonCtrl m_SpinBlue;
	afx_msg void OnDeltaposSpinRed(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpinGreen(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpinBlue(NMHDR* pNMHDR, LRESULT* pResult);
	
	CSliderCtrl m_SliderRating;
	CString m_Rating;
	//afx_msg void OnNMCustomdrawSliderRating(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnTRBNThumbPosChangingSliderRating(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnNMReleasedcaptureSliderRating(NMHDR* pNMHDR, LRESULT* pResult);
};
