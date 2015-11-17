
// p04-editDoc.cpp : Cp04editDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "p04-edit.h"
#endif

#include "p04-editDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cp04editDoc

IMPLEMENT_DYNCREATE(Cp04editDoc, CDocument)

BEGIN_MESSAGE_MAP(Cp04editDoc, CDocument)
END_MESSAGE_MAP()


// Cp04editDoc 생성/소멸

Cp04editDoc::Cp04editDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

Cp04editDoc::~Cp04editDoc()
{
}

BOOL Cp04editDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

			//변수 초기화
			str = "";

	return TRUE;
}




// Cp04editDoc serialization

void Cp04editDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
		//ar에 모든것을 넣어라
		ar << str;
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
		//읽어오는것
		str = "";
		while(1) {
			CString line;
			ar.ReadString(line);
			str += line + "\r\n";
			if(ar.IsBufferEmpty()) break;
		}
		
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void Cp04editDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
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

// 검색 처리기를 지원합니다.
void Cp04editDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void Cp04editDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Cp04editDoc 진단

#ifdef _DEBUG
void Cp04editDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cp04editDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cp04editDoc 명령
