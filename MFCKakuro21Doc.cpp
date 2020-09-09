
// MFCKakuro21Doc.cpp: Implementierung der CMFCKakuro21Doc-Klasse
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS können in einem ATL-Projekt definiert werden, in dem Vorschau-, Miniaturansichts- 
// und Suchfilterhandler implementiert werden, und die Freigabe von Dokumentcode für das Projekt wird ermöglicht.
#ifndef SHARED_HANDLERS
#include "MFCKakuro21.h"
#endif

#include "MFCKakuro21Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCKakuro21Doc

IMPLEMENT_DYNCREATE(CMFCKakuro21Doc, CDocument)

BEGIN_MESSAGE_MAP(CMFCKakuro21Doc, CDocument)
END_MESSAGE_MAP()


// CMFCKakuro21Doc-Erstellung/Zerstörung

CMFCKakuro21Doc::CMFCKakuro21Doc() noexcept
{
	// TODO: Hier Code für One-Time-Konstruktion einfügen

}

CMFCKakuro21Doc::~CMFCKakuro21Doc()
{
}

BOOL CMFCKakuro21Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: Hier Code zur Reinitialisierung einfügen
	// (SDI-Dokumente verwenden dieses Dokument)

	return TRUE;
}




// CMFCKakuro21Doc-Serialisierung

void CMFCKakuro21Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: Hier Code zum Speichern einfügen
	}
	else
	{
		// TODO: Hier Code zum Laden einfügen
	}
}

#ifdef SHARED_HANDLERS

// Unterstützung für Miniaturansichten
void CMFCKakuro21Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Ändern Sie diesen Code, um die Dokumentdaten zu zeichnen.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Unterstützung für Suchhandler
void CMFCKakuro21Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// Suchinhalte aus Dokumentdaten festlegen. 
	// Die Inhaltsteile sollten durch ";" getrennt werden.

	// Beispiel:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCKakuro21Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCKakuro21Doc-Diagnose

#ifdef _DEBUG
void CMFCKakuro21Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCKakuro21Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCKakuro21Doc-Befehle
