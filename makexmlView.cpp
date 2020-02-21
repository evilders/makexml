
// makexmlView.cpp: CmakexmlView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "makexml.h"
#endif

#include "makexmlDoc.h"
#include "makexmlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <string>
#include <fstream>
#include "xmldata.h"
#include "tips.h"
#include "daoxuecode.h"
#include "codeandtime.h"
#include "sound.h"


// CmakexmlView

IMPLEMENT_DYNCREATE(CmakexmlView, CScrollView)

BEGIN_MESSAGE_MAP(CmakexmlView, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_SAVE,save)
	ON_COMMAND(ID_begin,begin)
	ON_COMMAND(ID_click, click)
	ON_COMMAND(ID_voice, voice)
	ON_COMMAND(ID_end, end)
	ON_COMMAND(ID_voiceth, voiceth)
	//ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	//ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	//ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CmakexmlView 构造/析构

CmakexmlView::CmakexmlView() noexcept
{
	// TODO: 在此处添加构造代码

}

CmakexmlView::~CmakexmlView()
{
}

BOOL CmakexmlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CmakexmlView 绘图

void CmakexmlView::OnDraw(CDC* pDC/*pDC*/)
{
	CmakexmlDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	//sroad.clear();
	// 双缓冲工具
	CDC MemDC;
	CBitmap MemBitmap;
	MemDC.CreateCompatibleDC(nullptr);
	MemBitmap.CreateCompatibleBitmap(pDC, 1600, 1400);
	CBitmap* p0ldBit = MemDC.SelectObject(&MemBitmap);
	MemDC.FillSolidRect(0, 0, 1600, 1400, RGB(337, 337, 337));



	CPen newpen(PS_SOLID, 2, RGB(0, 255, 0));
	CPen* oldpen = MemDC.SelectObject(&newpen);
	MemDC.SelectObject(newpen);
	MemDC.SetTextColor(RGB(255, 255, 255));

	for (int i = 0; i < datleng; i++) {
		if (i == 0) {
			//开始图标绘画

			MemDC.MoveTo(dat[i].distation[0], dat[i].distation[1]);
			MemDC.LineTo(dat[i].distation[0] + 40, dat[i].distation[1]);

			MemDC.MoveTo(dat[i].distation[0] + 40, dat[i].distation[1]);
			MemDC.LineTo(dat[i].distation[0] + 50, dat[i].distation[1] + 10);

			MemDC.MoveTo(dat[i].distation[0] + 50, dat[i].distation[1] + 10);
			MemDC.LineTo(dat[i].distation[0] + 50, dat[i].distation[1] + 30);

			MemDC.MoveTo(dat[i].distation[0] + 50, dat[i].distation[1] + 30);
			MemDC.LineTo(dat[i].distation[0] + 40, dat[i].distation[1] + 40);

			MemDC.MoveTo(dat[i].distation[0] + 40, dat[i].distation[1] + 40);
			MemDC.LineTo(dat[i].distation[0], dat[i].distation[1] + 40);

			MemDC.MoveTo(dat[i].distation[0], dat[i].distation[1] + 40);
			MemDC.LineTo(dat[i].distation[0] - 10, dat[i].distation[1] + 30);

			MemDC.MoveTo(dat[i].distation[0] - 10, dat[i].distation[1] + 30);
			MemDC.LineTo(dat[i].distation[0] - 10, dat[i].distation[1] + 10);

			MemDC.MoveTo(dat[i].distation[0] - 10, dat[i].distation[1] + 10);
			MemDC.LineTo(dat[i].distation[0], dat[i].distation[1]);
			MemDC.TextOutW((int)dat[i].distation[0], (int)dat[i].distation[1] + 10, begins);
			//箭头
			MemDC.MoveTo(dat[i].distation[0] + 20, dat[i].distation[1] + 40);
			MemDC.LineTo(dat[i].distation[0] + 20, dat[i].distation[1] + 70);
			MemDC.MoveTo(dat[i].distation[0] + 20, dat[i].distation[1] + 70);
			MemDC.LineTo(dat[i].distation[0] + 15, dat[i].distation[1] + 65);
			MemDC.MoveTo(dat[i].distation[0] + 20, dat[i].distation[1] + 70);
			MemDC.LineTo(dat[i].distation[0] + 25, dat[i].distation[1] + 65);

			MemDC.MoveTo(dat[i].distation[0] - 10, dat[i].distation[1] + 70);
			MemDC.LineTo(dat[i].distation[0] + 50, dat[i].distation[1] + 70);
			MemDC.MoveTo(dat[i].distation[0] + 50, dat[i].distation[1] + 70);
			MemDC.LineTo(dat[i].distation[0] + 50, dat[i].distation[1] + 100);
			MemDC.MoveTo(dat[i].distation[0] + 50, dat[i].distation[1] + 100);
			MemDC.LineTo(dat[i].distation[0] -10, dat[i].distation[1] + 100);
			MemDC.MoveTo(dat[i].distation[0] - 10, dat[i].distation[1] + 100);
			MemDC.LineTo(dat[i].distation[0] - 10, dat[i].distation[1] + 70);
			MemDC.TextOutW((int)dat[i].distation[0]-10, (int)dat[i].distation[1] + 70, statgame);
			//箭头
			MemDC.MoveTo(dat[i].distation[0] + 20, dat[i].distation[1] + 100);
			MemDC.LineTo(dat[i].distation[0] + 20, dat[i].distation[1] + 130);
			MemDC.MoveTo(dat[i].distation[0] + 20, dat[i].distation[1] + 130);
			MemDC.LineTo(dat[i].distation[0] + 15, dat[i].distation[1] + 125);
			MemDC.MoveTo(dat[i].distation[0] + 20, dat[i].distation[1] + 130);
			MemDC.LineTo(dat[i].distation[0] + 25, dat[i].distation[1] + 125);

			enddistation[0] = dat[i].distation[0] + 20;
			enddistation[1] = dat[i].distation[1] + 130;
		}
		if (i > 0) {
			if (dat[i].type==3) {
				MemDC.MoveTo(enddistation[0] - 40, enddistation[1]);
				MemDC.LineTo(enddistation[0] + 40, enddistation[1]);

				MemDC.MoveTo(enddistation[0] + 40, enddistation[1]);
				MemDC.LineTo(enddistation[0] + 40, enddistation[1] + 30);

				MemDC.MoveTo(enddistation[0] + 40, enddistation[1] + 30);
				MemDC.LineTo(enddistation[0] - 40, enddistation[1] + 30);

				MemDC.MoveTo(enddistation[0] - 40, enddistation[1] + 30);
				MemDC.LineTo(enddistation[0] - 40, enddistation[1] );
				MemDC.TextOutW((int)enddistation[0] - 39, (int)enddistation[1], dat[i].text);
				//箭头
				MemDC.MoveTo(enddistation[0], enddistation[1] + 30);
				MemDC.LineTo(enddistation[0], enddistation[1] + 60);
				MemDC.MoveTo(enddistation[0], enddistation[1] + 60);
				MemDC.LineTo(enddistation[0] - 5, enddistation[1] + 55);
				MemDC.MoveTo(enddistation[0] , enddistation[1]+ 60);
				MemDC.LineTo(enddistation[0] + 5, enddistation[1] + 55); 
				
				
				enddistation[0] = enddistation[0];
				enddistation[1] = enddistation[1] + 60;
			}

			if (dat[i].type == 4) {
				MemDC.MoveTo(enddistation[0], enddistation[1]);
				MemDC.LineTo(enddistation[0] + 70, enddistation[1]+35);

				MemDC.MoveTo(enddistation[0] + 70, enddistation[1]+35);
				MemDC.LineTo(enddistation[0], enddistation[1] + 70);

				MemDC.MoveTo(enddistation[0] , enddistation[1] + 70);
				MemDC.LineTo(enddistation[0] - 70, enddistation[1] + 35);

				MemDC.MoveTo(enddistation[0] - 70, enddistation[1] + 35);
				MemDC.LineTo(enddistation[0], enddistation[1]);
				MemDC.TextOutW((int)enddistation[0] - 50, (int)enddistation[1]+15, dat[i].text);
				//箭头
				MemDC.MoveTo(enddistation[0], enddistation[1] + 60);
				MemDC.LineTo(enddistation[0], enddistation[1] + 100);
				MemDC.MoveTo(enddistation[0], enddistation[1] + 100);
				MemDC.LineTo(enddistation[0] - 5, enddistation[1] + 95);
				MemDC.MoveTo(enddistation[0], enddistation[1] + 100);
				MemDC.LineTo(enddistation[0] + 5, enddistation[1] + 95);
				//左超时处理
				MemDC.MoveTo(enddistation[0]-70, enddistation[1] + 35);
				MemDC.LineTo(enddistation[0] -200, enddistation[1] + 35);
				MemDC.TextOutW((int)enddistation[0] - 190, (int)enddistation[1] + 37,_T("错误处理省略"));
				//错误处理
				MemDC.MoveTo(enddistation[0]+70, enddistation[1] + 35);
				MemDC.LineTo(enddistation[0] + 190, enddistation[1] + 35);
				MemDC.TextOutW((int)enddistation[0] + 90, (int)enddistation[1] + 37, _T("超时处理省略"));
				enddistation[0] = enddistation[0];
				enddistation[1] = enddistation[1] + 100;
			}


			if (dat[i].type == 5) {
				MemDC.MoveTo(enddistation[0]-20, enddistation[1]);
				MemDC.LineTo(enddistation[0] + 20, enddistation[1]);

				MemDC.MoveTo(enddistation[0] + 20, enddistation[1]);
				MemDC.LineTo(enddistation[0] + 30, enddistation[1] + 10);

				MemDC.MoveTo(enddistation[0] + 30, enddistation[1] + 10);
				MemDC.LineTo(enddistation[0] + 30, enddistation[1] + 30);

				MemDC.MoveTo(enddistation[0] + 30, enddistation[1] + 30);
				MemDC.LineTo(enddistation[0] + 20, enddistation[1] + 40);

				MemDC.MoveTo(enddistation[0] + 20, enddistation[1] + 40);
				MemDC.LineTo(enddistation[0]-20, enddistation[1] + 40);

				MemDC.MoveTo(enddistation[0]-20, enddistation[1] + 40);
				MemDC.LineTo(enddistation[0] - 30, enddistation[1] + 30);

				MemDC.MoveTo(enddistation[0] - 30, enddistation[1] + 30);
				MemDC.LineTo(enddistation[0] - 30, enddistation[1] + 10);

				MemDC.MoveTo(enddistation[0] - 30, enddistation[1] + 10);
				MemDC.LineTo(enddistation[0]-20, enddistation[1]);
				MemDC.TextOutW(enddistation[0]-20, enddistation[1] + 10, endss);
			}
		}
	}
	

	//GetClientRect(&oldpen);

	//CRect rect;
	//this->GetClientRect(rect);
	//pDC->Ellipse(rect);

	//释放双缓冲所用的工具
	pDC->BitBlt(0, 0, 1600, 1400, &MemDC, 0, 0, SRCCOPY);
	MemBitmap.DeleteObject();
	MemDC.DeleteDC();

}


// CmakexmlView 打印

BOOL CmakexmlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CmakexmlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CmakexmlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CmakexmlView 诊断

#ifdef _DEBUG
void CmakexmlView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CmakexmlView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CmakexmlDoc* CmakexmlView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CmakexmlDoc)));
	return (CmakexmlDoc*)m_pDocument;
}
#endif //_DEBUG

void CmakexmlView::save(){
	CStdioFile file;
	CString filepath;
	TCHAR szFilter[] = _T("文本文件(*.xml)|*.xml|所有文件(*.*)|*.*||");
	string s = "</tasks> ";
	CFileDialog fileDlg(FALSE, _T("txt"), NULL, OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);
	datas = datas + s;
	if (IDOK == fileDlg.DoModal())
	{
		filepath = fileDlg.GetPathName();
		//file.Open(filepath, CFile::modeCreate | CFile::modeWrite | CFile::typeText);
		//if (!wfs.is_open()) {
		//	std::cout << "write file error" << std::endl; return;
		//}
		//wfs.write((char*)byte,sizeof(byte));
		//file.Close();
		std::ofstream wfs(filepath, std::ios::out);
		wfs << datas;
		wfs.close();
		MessageBox(_T("保存成功："));
	}
	
}

//点击添加开始时代码块
void CmakexmlView::begin() {
	if (datleng == 0) {
		datleng++;
		dat[datleng - 1].type = 1;
		dat[datleng - 1].distation[0] = 500;
		dat[datleng - 1].distation[1] = 50;
		dat[datleng - 1].next = 1;
		tips tip;
		if (tip.DoModal() == IDOK) {
			dat[datleng - 1].tips = tip.Tips;
		}
		string s1 = "	<task id=\"1\" next=\"2\" id=\"1\" type=\"game\" sysType=\"game_begin\" taskParam=\"{&quot;tips&quot;:0}\"/>\n";
		string s = "	<task id=\"2\" next=\"3\" type=\"game\" sysType=\"game_say\" taskParam=\"{&quot;type&quot;:1,&quot;code&quot;:&quot;SH_<@2-导学@>_0&quot;,&quot;lang&quot;:0}\" />\n";
		datas = datas + s1 + s;
		id=3;
		dat[datleng - 1].next = 3;
		Invalidate();
		UpdateData(TRUE);
	}
	else
	{
		MessageBox(_T("已经添加过此项请勿重复添加："));
	}
	
}
//点击添加点击块
void CmakexmlView::click() {
	if (datleng > 0) {
		int ids = dat[datleng - 1].next;
		datleng++;
		int idclick=id++;
		int idctimeout = id++;
		int idfaile = id++;
		int idctimeoutvoice = id++;
		int idfailevoice = id++;
		int idtrue = id++;
		dat[datleng - 1].next = idtrue;
		codeandtime codtim;
		if (codtim.DoModal() == IDOK) {
			dat[datleng - 1].text="Wait_click:";
			dat[datleng - 1].timeout = codtim.Timeout;
			dat[datleng - 1].cods = codtim.Code;
			dat[datleng - 1].type = 4;
			CString t;
			t.Format(_T("%d"), codtim.Timeout);
			CString c;
			c.Format(_T("%d"), codtim.Code);
			dat[datleng - 1].text = _T("Multi_wait_click:") + t+CString(":")+c;
			string s = string("	<task id=\"") + \
				string(to_string(ids)) + \
				string("\" next=\"") + \
				string(to_string(idtrue))+\
				string("\" next2=\"")+\
				string(to_string(idctimeout))+\
				string("\" next3 =\"")+\
				string(to_string(idfaile)) + \
				string("\"") + \
				string("sysType=\"game_wait_click\" type=\"game\" taskParam=\"{&quot; timeout&quot;:")+\
				string(to_string(codtim.Timeout))+\
				string(",&quot;res&quot;:{&quot;type&quot;:1,&quot;code&quot;:&quot;SH_")+\
				string(to_string(codtim.Code))+\
				string("_0& quot;},&quot;anyclick& quot;:0}\" />\n");

			//超时判断
			string s1 = string("	<task id=\"") + \
						string(to_string(idctimeout)) + \
						string("\"next = \"")+\
						string(to_string(ids))+\
						string("\" next3 = \"")+\
						string(to_string(idctimeoutvoice))+\
						string("\"sysType =\"game_count\" type =\"game\" taskParam=\"{ &quot;count& quot;:3}\"/>\n");
			//错误操作
			string s2= string("	<task id=\"") + \
						string(to_string(idfaile)) + \
						string("\"next = \"")+\
						string(to_string(ids))+\
						string("\" next3 = \"")+\
						string(to_string(idfailevoice))+\
						string("\"sysType =\"game_count\" type =\"game\" taskParam=\"{ &quot;count& quot;:3}\"/>\n");
			//超时提示音
			string s3 = "	<task id=\""+\
				string(to_string(idctimeoutvoice))+\
				string("\" next=\"0\"")+\
				string(" sysType=\"game_say\" type=\"game\" taskParam=\"{&quot;type&quot;:1,&quot;code&quot;:&quot;SH_&lt;@2-未操作提示@ &gt;_0&quot;,&quot;lang&quot;:0}\"  />\n");

			//错误提示音
			string s4;
			if (errortype == 0) {
				s4 = "	<task id=\"" + \
					string(to_string(idfailevoice)) + \
					string("\" next=\"0\"") + \
					string(" sysType=\"game_say\" type=\"game\" taskParam=\"{&quot;type&quot;:1,&quot;code&quot;:&quot;SH_&lt;@2-未操作提示@ &gt;_0&quot;,&quot;lang&quot;:0}\"  />\n");
			}
			else {
				s4 = "	<task id=\"" + \
					string(to_string(idfailevoice)) + \
					string("\" next=\"0\"") + \
					string(" sysType=\"game_say\" type=\"game\" taskParam=\"{&quot;type&quot;:1,&quot;code&quot;:&quot;SH_&lt;@")+\
					string(CT2A(codtim.errorvalu.GetBuffer()))+\
					string("@ &gt;_0&quot;,&quot;lang&quot;:0}\"  />\n");
				errortype = 0;
			}
			

			datas = datas + s + s1 + s2 + s3 + s4;
			Invalidate();
			UpdateData(TRUE);
		}
	
	}
	else
	{
		MessageBox(_T("请添加开始框在添加后面的操作框："));
	}

}
void CmakexmlView::voice() {

	if (datleng > 0) {
		int ids = dat[datleng - 1].next;
		datleng++;
		id++;
		dat[datleng - 1].next = id;
		sound Sounddog;
		if (Sounddog.DoModal() == IDOK) {
			dat[datleng - 1].type = 3;
			dat[datleng - 1].text = _T("say:");
			dat[datleng - 1].text = dat[datleng - 1].text + Sounddog.Sound.GetBuffer();
			string scode = CT2A(Sounddog.Sound.GetBuffer());//码值cod
			string s = "	<task id=\"" + \
				string(to_string(id - 1)) + \
				string("\" next=\"") + \
				string(to_string(id)) + \
				string("\" type=\"game\" sysType=\"game_say\" taskParam=\"{&quot;type&quot;:1,&quot;code&quot;:&quot;SH__0&quot;SH_&lt;") + \
				scode + \
				string("&gt;_0&quot;,&quot;lang&quot;:0}\",&quot;lang&quot;:0}\" />\n");
			datas = datas + s;
			Invalidate();
			UpdateData(TRUE);

		}
	}
	else
	{
		MessageBox(_T("请添加开始框在添加后面的操作框："));
	}

}
void CmakexmlView::voiceth() {

	if (datleng > 0) {
		int ids = dat[datleng - 1].next;
		datleng++;
		id++;
		dat[datleng - 1].next = id;
		daoxuecode daoxuec;
		if (daoxuec.DoModal() == IDOK) {
			dat[datleng - 1].type = 3;
			dat[datleng - 1].text = _T("say:");
			dat[datleng - 1].text = dat[datleng - 1].text + daoxuec.dxcode.GetBuffer();
			string scode = CT2A(daoxuec.dxcode.GetBuffer());//码值cod
			string s = "	<task id=\""+\
				string(to_string(id - 1)) + \
				string("\" next=\"")+\
				string(to_string(id))+\
				string("\" type=\"game\" sysType=\"game_say\" taskParam=\"{&quot;type&quot;:1,&quot;code&quot;:&quot;SH_") + \
				scode + \
				string("_0&quot;,&quot;lang&quot;:0}\" />\n");
			datas = datas + s;
			Invalidate();
			UpdateData(TRUE);

		}
	}
	else
	{
		MessageBox(_T("请添加开始框在添加后面的操作框："));
	}

}
void CmakexmlView::end() {

	if (datleng > 0) {
		int ids = dat[datleng - 1].next;
		datleng++;
		dat[datleng - 1].type = 5;
		string s1 = "	<task id=\"0\" sysType=\"game_end\" type=\"game\" taskParam =\"\" next=\"-1\"/>\n";
		string s2 = "	<task id=\""+\
			string(to_string(id-1))+\
			string("\" sysType=\"game_end\" type=\"game\" taskParam =\"\" next=\"10000\"/>\n");
		datas = datas + s1 + s2;
		Invalidate();
		UpdateData(TRUE);
	}
	else
	{
		MessageBox(_T("请添加开始框在添加后面的操作框："));
	}
}
std::string format(const char* fmt, ...) {
	va_list args1;
	va_start(args1, fmt);
	va_list args2;
	va_copy(args2, args1);
	std::vector<char> buf(1 + std::vsnprintf(nullptr, 0, fmt, args1));
	va_end(args1);
	std::vsnprintf(buf.data(), buf.size(), fmt, args2);
	va_end(args2);
	return buf.data();
}

// CmakexmlView 消息处理程序
