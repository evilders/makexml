#pragma once


// codeandtime 对话框

class codeandtime : public CDialogEx
{
	DECLARE_DYNAMIC(codeandtime)

public:
	codeandtime(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~codeandtime();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_codandtime };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// //码值
	int Code;
	//等待超时时间
	int Timeout;
	//正确跳转的次数
	int Skips;
private:
	CComboBox edit;
public:
	afx_msg void OnCbnSelchangeCombo1();
	CString errorvalu;
};
