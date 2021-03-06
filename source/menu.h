#pragma once
#include "chat.h"
#include "danh_sach_tin_nhan.h"
#include "DANH_SACH_BAN_BE.h"
// menu dialog

class menu : public CDialog
{
	DECLARE_DYNAMIC(menu)

public:
	menu(CString nguoi_gui = NULL, CWnd* pParent = nullptr);   // standard constructor
	virtual ~menu();
	CString STR_NGUOI_GUI;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MENU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedChat();
	afx_msg void OnBnClickedDanhSachBanBe();
	afx_msg void OnBnClickedDangXuat();
	afx_msg void OnBnClickedTinNhan();
};
