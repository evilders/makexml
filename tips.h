#pragma once


// tips 对话框

class tips : public CDialogEx
{
	DECLARE_DYNAMIC(tips)

public:
	tips(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~tips();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_tips };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// //生成代码中的tips为整数类型
	int Tips;
};
