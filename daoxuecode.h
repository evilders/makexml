#pragma once


// daoxuecode 对话框

class daoxuecode : public CDialogEx
{
	DECLARE_DYNAMIC(daoxuecode)

public:
	daoxuecode(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~daoxuecode();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_daxouecode };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// //播放导学时代码
	CString dxcode;
	afx_msg void OnEnChangeEdit1();
};
