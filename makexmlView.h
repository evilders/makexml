
// makexmlView.h: CmakexmlView 类的接口
//

#pragma once


class CmakexmlView : public CScrollView
{
protected: // 仅从序列化创建
	CmakexmlView() noexcept;
	DECLARE_DYNCREATE(CmakexmlView)

// 特性
public:
	CmakexmlDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate() { SetScrollSizes(MM_TEXT, CSize(1500, 1500)); };
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CmakexmlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void save();
	afx_msg void begin();
	afx_msg void voice();
	afx_msg void click();
	afx_msg void voiceth();
	afx_msg void end();
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // makexmlView.cpp 中的调试版本
inline CmakexmlDoc* CmakexmlView::GetDocument() const
   { return reinterpret_cast<CmakexmlDoc*>(m_pDocument); }
#endif

