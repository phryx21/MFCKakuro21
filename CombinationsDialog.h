#pragma once


// CCombinationsDialog-Dialog

class CCombinationsDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CCombinationsDialog)

public:
	CCombinationsDialog(CWnd* pParent = nullptr);   // Standardkonstruktor
	virtual ~CCombinationsDialog();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
private:
	CWnd* m_pParent;
};
