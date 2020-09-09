
// MFCKakuro21Doc.h: Schnittstelle der CMFCKakuro21Doc-Klasse
//


#pragma once


class CMFCKakuro21Doc : public CDocument
{
protected: // Nur aus Serialisierung erstellen
	CMFCKakuro21Doc() noexcept;
	DECLARE_DYNCREATE(CMFCKakuro21Doc)

// Attribute
public:

// Vorgänge
public:

// Überschreibungen
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementierung
public:
	virtual ~CMFCKakuro21Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generierte Funktionen für die Meldungstabellen
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Hilfsfunktion, die Suchinhalt für Suchhandler festlegt
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
