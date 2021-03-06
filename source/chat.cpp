// chat.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "chat.h"
#include "afxdialogex.h"
#include <sstream>
#include <fstream>
#include <cstring>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

// chat dialog

IMPLEMENT_DYNAMIC(chat, CDialog)

chat::chat(CString tai_khoan, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CHAT, pParent)
	, TEN_NGUOI_NHAN(_T(""))
	, TEN_NGUOI_GUI(_T(""))
	, NOI_DUNG(_T(""))
{
	this->TEN_NGUOI_GUI = tai_khoan;
}
chat::~chat()
{
}
void chat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TEN_NGUOI_NHAN, TEN_NGUOI_NHAN);
	DDX_Text(pDX, IDC_TEN_NGUOI_GUI, TEN_NGUOI_GUI);
	DDX_Text(pDX, IDC_NOI_DUNG_TIN_NHAN, NOI_DUNG);
}

BEGIN_MESSAGE_MAP(chat, CDialog)
	ON_BN_CLICKED(IDOK_GUI_TIN_NHAN, &chat::OnBnClickedGuiTinNhan)
END_MESSAGE_MAP()


// chat message handlers
int chat::kiem_tra_da_dang_ky_chua(char *tai_khoan_can_kiem_tra)
{
	ifstream file_thong_tin("thong_tin.txt", ios::app);
	char tai_khoan[255], mat_khau[255], ho_ten[255], ngay_sinh[255], gioi_tinh[255], noi_o[255];
	while (!file_thong_tin.eof())
	{
		file_thong_tin.getline(tai_khoan, 255);
		file_thong_tin.getline(mat_khau, 255);
		file_thong_tin.getline(ho_ten, 255);
		file_thong_tin.getline(ngay_sinh, 255);
		file_thong_tin.getline(gioi_tinh, 255);
		file_thong_tin.getline(noi_o, 255);
		if (strcmp(tai_khoan, tai_khoan_can_kiem_tra) == 0)
		{
			file_thong_tin.close();
			return 1;
		}

	}
	file_thong_tin.close();
	return 0;
}
int chat::kiem_tra_block(char *tai_khoan_bi_block)
{
	CString tai_khoan;
	char ten_tai_khoan[100], ten_ban_be[100], trang_thai_ket_ban[100], stt[100], gio[100];
	ifstream file_ban_be("ban_be.txt", ios::app);
	while (!file_ban_be.eof())
	{
		file_ban_be.getline(stt, 100);
		file_ban_be.getline(ten_tai_khoan, 100);
		file_ban_be.getline(ten_ban_be, 100);
		file_ban_be.getline(trang_thai_ket_ban, 100);
		file_ban_be.getline(gio, 100);
		tai_khoan = CString(ten_tai_khoan);
		if (tai_khoan.Compare(this->TEN_NGUOI_GUI) == 0)
		{
			if (strcmp(tai_khoan_bi_block, ten_ban_be) == 0)
			{
				file_ban_be.close();
				return 0;
			}
		}
	}
	file_ban_be.close();
	return 1;
}
int chat::kiem_tra_stt()
{
	ifstream file_tin_nhan;
	int int_stt = 0;
	char ten_nguoi_gui[100], ten_nguoi_nhan[100], noi_dung[100], stt[100];
	file_tin_nhan.open("tin_nhan.txt", ios::in);
	CString cstr_stt, cstr_ten_nguoi_gui;
	while (!file_tin_nhan.eof())
	{
		file_tin_nhan.getline(stt, 100);
		file_tin_nhan.getline(ten_nguoi_gui,100);
		file_tin_nhan.getline( ten_nguoi_nhan,100);
		file_tin_nhan.getline(noi_dung,100);
		if (!file_tin_nhan.eof())
		{
			cstr_ten_nguoi_gui = CString(ten_nguoi_gui);
			if(cstr_ten_nguoi_gui.Compare(this->TEN_NGUOI_GUI) == 0)
			cstr_stt = CString(stt);
		}
	}
	int_stt = _wtoi(cstr_stt);
	file_tin_nhan.close();
	return int_stt;
}
void chat::OnBnClickedGuiTinNhan()
{
	ofstream file_tin_nhan;
	file_tin_nhan.open("tin_nhan.txt",ios::app);
	char ten_nguoi_gui[100], ten_nguoi_nhan[100], noi_dung[1000];
	this->STT = kiem_tra_stt();
	this->STT++;
	strcpy_s(ten_nguoi_gui, CStringA(this->TEN_NGUOI_GUI).GetString());
	GetDlgItemText(IDC_TEN_NGUOI_NHAN, this->TEN_NGUOI_NHAN);
	strcpy_s(ten_nguoi_nhan, CStringA(this->TEN_NGUOI_NHAN).GetString());
	GetDlgItemText(IDC_NOI_DUNG_TIN_NHAN, this->NOI_DUNG);
	strcpy_s(noi_dung, CStringA(this->NOI_DUNG).GetString());
	if (kiem_tra_da_dang_ky_chua(ten_nguoi_nhan) == 1)
	{
		if (kiem_tra_block(ten_nguoi_nhan) == 1)
		{
			file_tin_nhan << this->STT << endl;
			file_tin_nhan << ten_nguoi_gui << endl;
			file_tin_nhan << ten_nguoi_nhan << endl;
			file_tin_nhan << noi_dung << endl;
			file_tin_nhan.close();
			MessageBox(_T("Da gui roi nhe"));
		}
	}
	else
		MessageBox(_T("tai khoan chua ton tai hoac da bi block"));
}
