// tips.cpp: 实现文件
//

#include "pch.h"
#include "makexml.h"
#include "tips.h"
#include "afxdialogex.h"


// tips 对话框

IMPLEMENT_DYNAMIC(tips, CDialogEx)

tips::tips(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_tips, pParent)
	, Tips(0)
{

}

tips::~tips()
{
}

void tips::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Tips);
}


BEGIN_MESSAGE_MAP(tips, CDialogEx)
END_MESSAGE_MAP()


// tips 消息处理程序
