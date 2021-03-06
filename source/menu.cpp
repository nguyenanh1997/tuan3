// menu.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "menu.h"
#include "afxdialogex.h"


// menu dialog

IMPLEMENT_DYNAMIC(menu, CDialog)

menu::menu(CString nguoi_gui, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_MENU, pParent)
{
	STR_NGUOI_GUI = nguoi_gui;
}

menu::~menu()
{
}

void menu::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(menu, CDialog)
	ON_BN_CLICKED(IDC_CHAT, &menu::OnBnClickedChat)
	ON_BN_CLICKED(IDC_DANH_SACH_BAN_BE, &menu::OnBnClickedDanhSachBanBe)
	ON_BN_CLICKED(IDC_DANG_XUAT, &menu::OnBnClickedDangXuat)
	ON_BN_CLICKED(IDC_TIN_NHAN, &menu::OnBnClickedTinNhan)
END_MESSAGE_MAP()


// menu message handlers


void menu::OnBnClickedChat()
{
	chat *CHAT;
	CHAT = new chat(STR_NGUOI_GUI);
	if (CHAT->DoModal() == IDOK)
	{
		CHAT->ShowWindow(SW_SHOW);

	}
}


void menu::OnBnClickedDanhSachBanBe()
{
	DANH_SACH_BAN_BE *ban_be;
	ban_be = new DANH_SACH_BAN_BE(STR_NGUOI_GUI);
	if (ban_be->DoModal() == IDOK)
	{
		ban_be->ShowWindow(SW_SHOW);
	}
}
void menu::OnBnClickedDangXuat()
{
	this->EndDialog(0);
}
void menu::OnBnClickedTinNhan()
{
	danh_sach_tin_nhan *DANH_SACH_TIN;
	DANH_SACH_TIN = new danh_sach_tin_nhan(STR_NGUOI_GUI);
	if (DANH_SACH_TIN->DoModal() == IDOK)
	{
		DANH_SACH_TIN->ShowWindow(SW_SHOW);
	}
}
