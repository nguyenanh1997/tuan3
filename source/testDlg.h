
// testDlg.h : header file
//

#pragma once
#include "menu.h"

// CtestDlg dialog
class CtestDlg : public CDialogEx
{
// Construction
public:
	CtestDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
private:
	CString TAI_KHOAN;
	CString MAT_KHAU;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedDangKy();
private:
	CString GIOI_TINH;
	CString NOI_O;
	CString NGAY_SINH;
	CString HO_TEN;
	int TRANG_THAI_DANG_NHAP;
};
