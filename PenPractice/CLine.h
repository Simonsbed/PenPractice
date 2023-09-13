#pragma once
#include <afx.h>
class CLine :
    public CObject
{
    DECLARE_SERIAL(CLine)
    // 아무것도 안적으면 private
    CPoint m_From;
    CPoint m_To;
    int m_Size;
    COLORREF m_Col;
public:
    CLine() {}
    CLine(CPoint From, CPoint To, int Size, COLORREF Col)
    {
        m_From = From;
        m_To = To;
        m_Size = Size;
        m_Col = Col;
    }
    // 어디다가그림을 그릴지 나타내는 함수
    void Draw(CDC* pDC)
    {
        CPen pen(PS_SOLID, m_Size, m_Col);
        pDC->SelectObject(&pen);
        pDC->MoveTo(m_From);
        pDC->LineTo(m_To);
    }
    virtual void Serialize(CArchive& ar);
};

