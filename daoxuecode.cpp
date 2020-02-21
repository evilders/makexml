// daoxuecode.cpp: 实现文件
//

#include "pch.h"
#include "makexml.h"
#include "daoxuecode.h"
#include "afxdialogex.h"


// daoxuecode 对话框

IMPLEMENT_DYNAMIC(daoxuecode, CDialogEx)

daoxuecode::daoxuecode(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_daxouecode, pParent)
	, dxcode(_T("<@2-导学@>"))
{

}

daoxuecode::~daoxuecode()
{
}

void daoxuecode::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, dxcode);
}


BEGIN_MESSAGE_MAP(daoxuecode, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &daoxuecode::OnEnChangeEdit1)
END_MESSAGE_MAP()


// daoxuecode 消息处理程序


void daoxuecode::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	SetWindowText(_T("<@3-导学@>"));
	// TODO:  在此添加控件通知处理程序代码
}
