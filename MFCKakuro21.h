
// MFCKakuro21.h: Hauptheaderdatei für die MFCKakuro21-Anwendung
//
#pragma once

#ifndef __AFXWIN_H__
	#error "'pch.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"       // Hauptsymbole


// CMFCKakuro21App:
// Siehe MFCKakuro21.cpp für die Implementierung dieser Klasse
//

class CMFCKakuro21App : public CWinAppEx
{
public:
	CMFCKakuro21App() noexcept;


// Überschreibungen
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementierung
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCKakuro21App theApp;
