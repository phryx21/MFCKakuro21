
// MFCKakuro21View.cpp: Implementierung der CMFCKakuro21View-Klasse
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS können in einem ATL-Projekt definiert werden, in dem Vorschau-, Miniaturansichts- 
// und Suchfilterhandler implementiert werden, und die Freigabe von Dokumentcode für das Projekt wird ermöglicht.
#ifndef SHARED_HANDLERS
#include "MFCKakuro21.h"
#endif

#include "MFCKakuro21Doc.h"
#include "MFCKakuro21View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCKakuro21View

IMPLEMENT_DYNCREATE(CMFCKakuro21View, CView)

BEGIN_MESSAGE_MAP(CMFCKakuro21View, CView)
	// Standarddruckbefehle
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCKakuro21View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_EXTRAS_KOMBINATIONENBERECHNEN, &CMFCKakuro21View::OnExtrasKombinationenberechnen)
	ON_COMMAND(ID_EXTRAS_KOMBINATIONENBERECHNEN32773, &CMFCKakuro21View::OnExtrasKombinationenberechnen32773)
END_MESSAGE_MAP()

// CMFCKakuro21View-Erstellung/Zerstörung

CMFCKakuro21View::CMFCKakuro21View() noexcept
{
	// TODO: Hier Code zur Konstruktion einfügen

}

CMFCKakuro21View::~CMFCKakuro21View()
{
}

BOOL CMFCKakuro21View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Ändern Sie hier die Fensterklasse oder die Darstellung, indem Sie
	//  CREATESTRUCT cs modifizieren.

	return CView::PreCreateWindow(cs);
}

// CMFCKakuro21View-Zeichnung

void CMFCKakuro21View::OnDraw(CDC* /*pDC*/)
{
	CMFCKakuro21Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: Code zum Zeichnen der nativen Daten hinzufügen
}


// CMFCKakuro21View-Druck


void CMFCKakuro21View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCKakuro21View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Standardvorbereitung
	return DoPreparePrinting(pInfo);
}

void CMFCKakuro21View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: Zusätzliche Initialisierung vor dem Drucken hier einfügen
}

void CMFCKakuro21View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: Bereinigung nach dem Drucken einfügen
}

void CMFCKakuro21View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCKakuro21View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCKakuro21View-Diagnose

#ifdef _DEBUG
void CMFCKakuro21View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCKakuro21View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCKakuro21Doc* CMFCKakuro21View::GetDocument() const // Nichtdebugversion ist inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCKakuro21Doc)));
	return (CMFCKakuro21Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCKakuro21View-Meldungshandler


void CMFCKakuro21View::OnExtrasKombinationenberechnen()
{
	if (!m_pCombinationsDialog)
	{
		this->m_pCombinationsDialog = std::make_unique<CCombinationsDialog>(this);
		m_pCombinationsDialog->Create(IDD_DIALOG1, this);
	}
	
}


void CMFCKakuro21View::OnExtrasKombinationenberechnen32773()
{
	if (!m_pCombinationsDialog)
	{
		this->m_pCombinationsDialog = std::make_unique<CCombinationsDialog>(this);
		m_pCombinationsDialog->Create(IDD_DIALOG1, this);
	}
}
