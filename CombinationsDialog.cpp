// CombinationsDialog.cpp: Implementierungsdatei
//

#include "pch.h"
#include "MFCKakuro21.h"
#include "CombinationsDialog.h"
#include "afxdialogex.h"


// CCombinationsDialog-Dialog

IMPLEMENT_DYNAMIC(CCombinationsDialog, CDialogEx)

CCombinationsDialog::CCombinationsDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent),
	m_pParent(pParent)
{

}

CCombinationsDialog::~CCombinationsDialog()
{
}

void CCombinationsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCombinationsDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCombinationsDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CCombinationsDialog-Meldungshandler


void CCombinationsDialog::OnBnClickedOk()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
	
	CDialogEx::OnOK();
}

