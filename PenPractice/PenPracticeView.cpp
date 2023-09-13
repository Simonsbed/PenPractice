
// PenPracticeView.cpp: CPenPracticeView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "PenPractice.h"
#endif

#include "PenPracticeDoc.h"
#include "PenPracticeView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPenPracticeView
IMPLEMENT_DYNCREATE(CPenPracticeView, CView)

BEGIN_MESSAGE_MAP(CPenPracticeView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SELECT_COLOR, &CPenPracticeView::OnSelectColor)
	ON_COMMAND(ID_SIZE_1, &CPenPracticeView::OnSize1)
	ON_COMMAND(ID_SIZE_2, &CPenPracticeView::OnSize2)
	ON_COMMAND(ID_SIZE_4, &CPenPracticeView::OnSize4)
	ON_COMMAND(ID_SIZE_8, &CPenPracticeView::OnSize8)
	ON_COMMAND(ID_SIZE_16, &CPenPracticeView::OnSize16)
	ON_COMMAND(ID_SIZE_32, &CPenPracticeView::OnSize32)
END_MESSAGE_MAP()

// CPenPracticeView 생성/소멸

CPenPracticeView::CPenPracticeView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPenPracticeView::~CPenPracticeView()
{
}

BOOL CPenPracticeView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPenPracticeView 그리기
#include "CLine.h"
void CPenPracticeView::OnDraw(CDC* pDC)
{
	CPenPracticeDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// CObArray m_oa;.GetSize;
	int n = pDoc->m_oa.GetSize();
	for (int i = 0; i < n; i++)
	{
		// 타입 캐스팅
		CLine* pLine = (CLine*)pDoc->m_oa[i];
		pLine->Draw(pDC);
	}

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CPenPracticeView 인쇄

BOOL CPenPracticeView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPenPracticeView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPenPracticeView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPenPracticeView 진단

#ifdef _DEBUG
void CPenPracticeView::AssertValid() const
{
	CView::AssertValid();
}

void CPenPracticeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPenPracticeDoc* CPenPracticeView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPenPracticeDoc)));
	return (CPenPracticeDoc*)m_pDocument;
}
#endif //_DEBUG


// CPenPracticeView 메시지 처리기
CPoint opnt;
COLORREF Col;
int size = 0;
#include "CLine.h"
void CPenPracticeView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nFlags == MK_LBUTTON)
	{
		//Doc를 넣어준다
		CPenPracticeDoc* pDoc = GetDocument();
		CLine* pLine = new CLine(opnt, point, size, Col);
		// Doc에 cob로 m_oa에 저장했다
		pDoc->m_oa.Add(pLine);
		// 화면을 새로 그려주세요 Invalidate
		Invalidate(FALSE);
	}
	opnt = point;
	CView::OnMouseMove(nFlags, point);
}


void CPenPracticeView::OnSelectColor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK)
	{
		Col = dlg.GetColor();
	}
}


void CPenPracticeView::OnSize1()
{
	size = 1;
}


void CPenPracticeView::OnSize2()
{
	size = 2;

}


void CPenPracticeView::OnSize4()
{
	size = 4;
}



void CPenPracticeView::OnSize8()
{
	size = 8;
}


void CPenPracticeView::OnSize16()
{
	size = 16;
}


void CPenPracticeView::OnSize32()
{
	size = 32;
}
