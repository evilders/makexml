// codeandtime.cpp: 实现文件
//

#include "pch.h"
#include "makexml.h"
#include "codeandtime.h"
#include "afxdialogex.h"
#include "xmldata.h"


// codeandtime 对话框

IMPLEMENT_DYNAMIC(codeandtime, CDialogEx)

codeandtime::codeandtime(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_codandtime, pParent)
	, Code(0)
	, Timeout(0)
	, Skips(0)
	, errorvalu(_T(""))
{

}

codeandtime::~codeandtime()
{
}

void codeandtime::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Code);
	DDX_Text(pDX, IDC_EDIT2, Timeout);
	DDX_Text(pDX, IDC_EDIT3, Skips);
	DDX_Control(pDX, IDC_COMBO1, edit);
	edit.AddString(TEXT("默认方式"));
	edit.AddString(TEXT("自定义方式"));
	edit.SetCurSel(0);
	DDX_Text(pDX, IDC_EDIT4, errorvalu);
}


BEGIN_MESSAGE_MAP(codeandtime, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &codeandtime::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// codeandtime 消息处理程序


void codeandtime::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	int i = edit.GetCurSel();//获得当前下拉框的位置
	CString str;//储存下拉框中的内容
	edit.GetLBText(i,str);//根据i值将下拉框中的内容赋值给str
	errortype = i;
	//CString c;
	//	c.Format(_T("%d"), i);
	//MessageBox(c);
}
