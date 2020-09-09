
// MFCKakuro21.cpp: Definiert das Klassenverhalten für die Anwendung.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MFCKakuro21.h"
#include "MainFrm.h"

#include "ChildFrm.h"
#include "MFCKakuro21Doc.h"
#include "MFCKakuro21View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCKakuro21App

BEGIN_MESSAGE_MAP(CMFCKakuro21App, CWinAppEx)
	ON_COMMAND(ID_APP_ABOUT, &CMFCKakuro21App::OnAppAbout)
	// Dateibasierte Standarddokumentbefehle
	ON_COMMAND(ID_FILE_NEW, &CWinAppEx::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinAppEx::OnFileOpen)
	// Standarddruckbefehl "Seite einrichten"
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinAppEx::OnFilePrintSetup)
END_MESSAGE_MAP()


// CMFCKakuro21App-Erstellung

CMFCKakuro21App::CMFCKakuro21App() noexcept
{
	m_bHiColorIcons = TRUE;

	// Neustart-Manager unterstützen
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// Wenn die Anwendung mit Common Language Runtime-Unterstützung (/clr) erstellt wurde:
	//     1) Diese zusätzliche Eigenschaft ist erforderlich, damit der Neustart-Manager ordnungsgemäß unterstützt wird.
	//     2) Für die Projekterstellung müssen Sie im Projekt einen Verweis auf System.Windows.Forms hinzufügen.
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: Ersetzen Sie die Anwendungs-ID-Zeichenfolge unten durch eine eindeutige ID-Zeichenfolge; empfohlen
	// Das Format für die Zeichenfolge ist: CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("MFCKakuro21.AppID.NoVersion"));

	// TODO: Hier Code zur Konstruktion einfügen
	// Alle wichtigen Initialisierungen in InitInstance positionieren
}

// Das einzige CMFCKakuro21App-Objekt

CMFCKakuro21App theApp;


// CMFCKakuro21App-Initialisierung

BOOL CMFCKakuro21App::InitInstance()
{
	// InitCommonControlsEx() ist für Windows XP erforderlich, wenn ein Anwendungsmanifest
	// die Verwendung von ComCtl32.dll Version 6 oder höher zum Aktivieren
	// von visuellen Stilen angibt.  Ansonsten treten beim Erstellen von Fenstern Fehler auf.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Legen Sie dies fest, um alle allgemeinen Steuerelementklassen einzubeziehen,
	// die Sie in Ihrer Anwendung verwenden möchten.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();


	// OLE-Bibliotheken initialisieren
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction();

	// AfxInitRichEdit2() ist für die Verwendung des RichEdit-Steuerelements erforderlich.
	// AfxInitRichEdit2();

	// Standardinitialisierung
	// Wenn Sie diese Funktionen nicht verwenden und die Größe
	// der ausführbaren Datei verringern möchten, entfernen Sie
	// die nicht erforderlichen Initialisierungsroutinen.
	// Ändern Sie den Registrierungsschlüssel, unter dem Ihre Einstellungen gespeichert sind.
	// TODO: Ändern Sie diese Zeichenfolge entsprechend,
	// z.B. zum Namen Ihrer Firma oder Organisation.
	SetRegistryKey(_T("Vom lokalen Anwendungs-Assistenten generierte Anwendungen"));
	LoadStdProfileSettings(4);  // Standard INI-Dateioptionen laden (einschließlich MRU)


	InitContextMenuManager();

	InitKeyboardManager();

	InitTooltipManager();
	CMFCToolTipInfo ttParams;
	ttParams.m_bVislManagerTheme = TRUE;
	theApp.GetTooltipManager()->SetTooltipParams(AFX_TOOLTIP_TYPE_ALL,
		RUNTIME_CLASS(CMFCToolTipCtrl), &ttParams);

	// Dokumentvorlagen der Anwendung registrieren.  Dokumentvorlagen
	//  dienen als Verbindung zwischen Dokumenten, Rahmenfenstern und Ansichten.
	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(IDR_MFCKakuro21TYPE,
		RUNTIME_CLASS(CMFCKakuro21Doc),
		RUNTIME_CLASS(CChildFrame), // Benutzerspezifischer MDI-Child-Rahmen
		RUNTIME_CLASS(CMFCKakuro21View));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);

	// Haupt-MDI-Rahmenfenster erstellen
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame || !pMainFrame->LoadFrame(IDR_MAINFRAME))
	{
		delete pMainFrame;
		return FALSE;
	}
	m_pMainWnd = pMainFrame;


	// Befehlszeile auf Standardumgebungsbefehle überprüfen, DDE, Datei öffnen
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Verteilung der in der Befehlszeile angegebenen Befehle.  Gibt FALSE zurück, wenn
	// die Anwendung mit /RegServer, /Register, /Unregserver oder /Unregister gestartet wurde.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// Das Hauptfenster ist initialisiert und kann jetzt angezeigt und aktualisiert werden.
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();

	return TRUE;
}

int CMFCKakuro21App::ExitInstance()
{
	//TODO: Zusätzliche Ressourcen behandeln, die Sie möglicherweise hinzugefügt haben
	AfxOleTerm(FALSE);

	return CWinAppEx::ExitInstance();
}

// CMFCKakuro21App-Meldungshandler


// CAboutDlg-Dialogfeld für Anwendungsbefehl "Info"

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

// Implementierung
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnExtrasKombinationenberechnen();
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
	ON_COMMAND(ID_EXTRAS_KOMBINATIONENBERECHNEN, &CAboutDlg::OnExtrasKombinationenberechnen)
END_MESSAGE_MAP()

// Anwendungsbefehl zum Ausführen des Dialogfelds
void CMFCKakuro21App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMFCKakuro21App-Anpassungen – Methoden zum Laden/Speichern

void CMFCKakuro21App::PreLoadState()
{
	BOOL bNameValid;
	CString strName;
	bNameValid = strName.LoadString(IDS_EDIT_MENU);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EDIT);
	bNameValid = strName.LoadString(IDS_EXPLORER);
	ASSERT(bNameValid);
	GetContextMenuManager()->AddMenu(strName, IDR_POPUP_EXPLORER);
}

void CMFCKakuro21App::LoadCustomState()
{
}

void CMFCKakuro21App::SaveCustomState()
{
}

// CMFCKakuro21App-Meldungshandler





void CAboutDlg::OnBnClickedOk()
{
	// TODO: Fügen Sie hier Ihren Handlercode für Benachrichtigungen des Steuerelements ein.
	CDialogEx::OnOK();
}


void CAboutDlg::OnExtrasKombinationenberechnen()
{
	// TODO: Fügen Sie hier Ihren Befehlshandlercode ein.
}
