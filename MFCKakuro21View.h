
// MFCKakuro21View.h: Schnittstelle der CMFCKakuro21View-Klasse
//

#pragma once
#include "CombinationsDialog.h"
#include <memory>


class CMFCKakuro21View : public CView
{
protected: // Nur aus Serialisierung erstellen
	CMFCKakuro21View() noexcept;
	DECLARE_DYNCREATE(CMFCKakuro21View)

// Attribute
public:
	CMFCKakuro21Doc* GetDocument() const;

// Vorgänge
public:

// Überschreibungen
public:
	virtual void OnDraw(CDC* pDC);  // Überschrieben, um diese Ansicht darzustellen
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementierung
public:
	virtual ~CMFCKakuro21View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Funktionen für die Meldungstabellen
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnExtrasKombinationenberechnen();

private:
	std::unique_ptr<CCombinationsDialog> m_pCombinationsDialog = nullptr;
public:
	afx_msg void OnExtrasKombinationenberechnen32773();
};

#ifndef _DEBUG  // Debugversion in MFCKakuro21View.cpp
inline CMFCKakuro21Doc* CMFCKakuro21View::GetDocument() const
   { return reinterpret_cast<CMFCKakuro21Doc*>(m_pDocument); }
#endif

