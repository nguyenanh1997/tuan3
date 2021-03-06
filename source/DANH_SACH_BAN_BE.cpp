// DANH_SACH_BAN_BE.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "DANH_SACH_BAN_BE.h"
#include "afxdialogex.h"
#include "fstream"
#include <sstream>
#include <cstring>
#include <ctime>
#include "chat.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

// DANH_SACH_BAN_BE dialog

IMPLEMENT_DYNAMIC(DANH_SACH_BAN_BE, CDialog)

DANH_SACH_BAN_BE::DANH_SACH_BAN_BE(CString tai_khoan, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DANH_SACH_BAN_BE, pParent)
{
	TAI_KHOAN = tai_khoan;
	so_lan_an_load_danh_sach_tin = 0;
}

DANH_SACH_BAN_BE::~DANH_SACH_BAN_BE()
{
}

void DANH_SACH_BAN_BE::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, danh_sach);
}


BEGIN_MESSAGE_MAP(DANH_SACH_BAN_BE, CDialog)
	ON_BN_CLICKED(IDOK, &DANH_SACH_BAN_BE::OnBnClickedHienThiDanhSach)
	ON_BN_CLICKED(IDC_BUTTON1, &DANH_SACH_BAN_BE::OnBnClickedThemBan)
	ON_BN_CLICKED(IDC_BUTTON2, &DANH_SACH_BAN_BE::OnBnClickedBlock)
END_MESSAGE_MAP()


// DANH_SACH_BAN_BE message handlers


BOOL DANH_SACH_BAN_BE::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  Add extra initialization here
	danh_sach.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);
	danh_sach.InsertColumn(0, _T("STT"), LVCFMT_LEFT,100 );
	danh_sach.InsertColumn(1, _T("Ten"), LVCFMT_LEFT, 100);
	danh_sach.InsertColumn(2, _T("Thoi gian them"), LVCFMT_LEFT, 100);
	danh_sach.InsertColumn(3, _T("khoang thoi gian ket ban"), LVCFMT_LEFT, 200);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void DANH_SACH_BAN_BE::OnBnClickedHienThiDanhSach()
{
	// TODO: Add your control notification handler code here
	if (so_lan_an_load_danh_sach_tin != 0)
	{
		danh_sach.DeleteAllItems();
	}
	ifstream file_ban_be;
	char ten_tai_khoan[255], ban_be[255], trang_thai_ban_be[255],stt[100],gio[100];
	CString tai_khoan_de_nghi_ket_ban, tai_khoan_ket_ban, trang_thai, STR_GIO, cstr_khoang_thoi_gian, cstr_stt;
	file_ban_be.open("ban_be.txt", ios::in);
	if (file_ban_be.good())
	{
		while (!file_ban_be.eof())
		{
			file_ban_be.getline(stt, 100);
			file_ban_be.getline(ten_tai_khoan, 255);
			file_ban_be.getline(ban_be, 255);
			file_ban_be.getline(trang_thai_ban_be, 255);
			file_ban_be.getline(gio, 255);
			// chuyen doi tat ca du lieu sang cstring
			tai_khoan_de_nghi_ket_ban = CString(ten_tai_khoan);
			cstr_stt = CString(stt);
			tai_khoan_ket_ban = CString(ban_be);
			STR_GIO = CString(gio);
			// chuyen sang dang ngay gio
			trang_thai = CString(trang_thai_ban_be);
			if (TAI_KHOAN.Compare(tai_khoan_de_nghi_ket_ban) == 0)
			{
				if (trang_thai == _T("1"))
				{
					danh_sach.InsertItem(0, cstr_stt);
					danh_sach.SetItemText(0, 1, tai_khoan_ket_ban);
					danh_sach.SetItemText(0, 2, STR_GIO);
					danh_sach.SetItemText(0, 3, _T("  "));
				}
			}
		}
		file_ban_be.close();
		so_lan_an_load_danh_sach_tin++;
	}
	else
		MessageBox(_T("khong co file ban be"));

}
int DANH_SACH_BAN_BE::kiem_tra_stt()
{
	ifstream file_ban_be;
	int int_stt = 0;
	char ten_tai_khoan[100], ten_ban_be[100], trang_thai_ket_ban[100], stt[100],gio[100];
	file_ban_be.open("ban_be.txt", ios::in);
	CString cstr_stt, cstr_ten_tai_khoan;
	while (!file_ban_be.eof())
	{
		file_ban_be.getline(stt, 100);
		file_ban_be.getline(ten_tai_khoan, 100);
		file_ban_be.getline(ten_ban_be, 100);
		file_ban_be.getline(trang_thai_ket_ban, 100);
		file_ban_be.getline(gio, 100);
		if (!file_ban_be.eof())
		{
			cstr_ten_tai_khoan = CString(ten_tai_khoan);
			if (cstr_ten_tai_khoan.Compare(TAI_KHOAN) == 0)
				cstr_stt = CString(stt);
		}
	}
	int_stt = _wtoi(cstr_stt);
	file_ban_be.close();
	return int_stt;
}
int DANH_SACH_BAN_BE::kiem_tra_da_ket_ban_chua(CString ten_nguoi_can_kiem_tra, CString ten_file,CString tai_khoan_cua_ban)
{
	ifstream file_ban_be("ban_be.txt", ios::app);
	char ten_tai_khoan[255], ban_be[255], trang_thai_ban_be[255], stt[100], gio[100];
	CString tai_khoan_de_nghi_ket_ban, tai_khoan_ket_ban, tai_khoan_de_nghi_ket_ban_1, tai_khoan_ket_ban_1;
	tai_khoan_de_nghi_ket_ban_1 = ten_nguoi_can_kiem_tra;
	tai_khoan_ket_ban_1 = tai_khoan_cua_ban;
	while (!file_ban_be.eof())
	{
		file_ban_be.getline(stt, 100);
		file_ban_be.getline(ten_tai_khoan, 255);
		file_ban_be.getline(ban_be, 255);
		file_ban_be.getline(trang_thai_ban_be, 255);
		file_ban_be.getline(gio, 100);
		tai_khoan_de_nghi_ket_ban = CString(ten_tai_khoan);
		tai_khoan_ket_ban = CString(ban_be);
		if (tai_khoan_de_nghi_ket_ban_1.Compare(tai_khoan_de_nghi_ket_ban) == 0)
		{
			if (tai_khoan_ket_ban_1.Compare(tai_khoan_ket_ban) == 0)
			{
				file_ban_be.close();
				return 1;
			}
		}
	}
	return 0;
	file_ban_be.close();
}
void DANH_SACH_BAN_BE::OnBnClickedThemBan()
{
	chat CHAT;
	CString ten_file;
	int kiem_tra;
	char tai_khoan_can_them[255], char_TAI_KHOAN[255], trang_thai_ket_ban[255] ="1",thoi_gian_ket_ban[255];
	ten_file = _T("ban_be.txt");
	ofstream file_ban_be(ten_file, ios::app);
	GetDlgItemText(IDC_TEN_NGUOI_CAN_THEM, tai_khoan_cua_ban_be);
	strcpy_s(tai_khoan_can_them, CStringA(tai_khoan_cua_ban_be).GetString());
	if (CHAT.kiem_tra_da_dang_ky_chua(tai_khoan_can_them) == 1)
	{
		kiem_tra = kiem_tra_da_ket_ban_chua(TAI_KHOAN, ten_file, tai_khoan_cua_ban_be);
		if (kiem_tra == 1)
		{
			MessageBox(_T("da ket ban hoac gui loi moi ket ban roi"));
		}
		else
		{
			CTime gio = CTime::GetCurrentTime();
			THOI_GIAN_KET_BAN = gio.Format(_T("%A, %B %d, %Y"));
			strcpy_s(char_TAI_KHOAN, CStringA(TAI_KHOAN).GetString());
			strcpy_s(thoi_gian_ket_ban, CStringA(THOI_GIAN_KET_BAN).GetString());
			STT = kiem_tra_stt();
			STT++;
			file_ban_be << STT << endl;
			file_ban_be << char_TAI_KHOAN << endl;
			file_ban_be << tai_khoan_can_them << endl;
			file_ban_be << trang_thai_ket_ban << endl;
			file_ban_be << THOI_GIAN_KET_BAN << endl;
			MessageBox(_T("da gui loi moi ket ban"));
		}
	}
	else
		MessageBox(_T("tai khoan chua ton tai"));
	file_ban_be.close();
}
void DANH_SACH_BAN_BE::chuyen_sang_block(char *stt_dau_vao)
{
	ifstream  file_can_xoa("ban_be.txt", ios::app);
	ofstream file_sau_khi_xoa("ban_be_tam.txt", ios::app);
	char ten_tai_khoan[100], ban_be[100], trang_thai[100], gio[100], stt[100];
	CString tai_khoan_so_sanh;
	while (!file_can_xoa.eof())
	{
		file_can_xoa.getline(stt, 100);
		file_can_xoa.getline(ten_tai_khoan, 255);
		file_can_xoa.getline(ban_be, 255);
		file_can_xoa.getline(trang_thai, 255);
		file_can_xoa.getline(gio, 255);
		tai_khoan_so_sanh = CString(ten_tai_khoan);
		file_sau_khi_xoa << stt << endl;
		file_sau_khi_xoa << ten_tai_khoan << endl;
		file_sau_khi_xoa << ban_be << endl;
		if (strcmp(stt, stt_dau_vao) == 0 && tai_khoan_so_sanh.Compare(TAI_KHOAN) == 0)
		{
			file_sau_khi_xoa << "0" << endl;
		}
		else
		{
			file_sau_khi_xoa << trang_thai << endl;
		}
		file_sau_khi_xoa << gio << endl;
	}
	file_can_xoa.close();
	file_sau_khi_xoa.close();
	remove("ban_be.txt");
	rename("ban_be_tam.txt", "ban_be.txt");
}
void DANH_SACH_BAN_BE::OnBnClickedBlock()
{
	// TODO: Add your control notification handler code here
	CString cac_stt_can_xoa;
	char stt[255];
	GetDlgItemText(IDC_STT_NGUOI_CAN_CHAN, cac_stt_can_xoa);
	int vi_tri = 0;
	CString stt_con = cac_stt_can_xoa.Tokenize(_T(","), vi_tri);
	while (!stt_con.IsEmpty())
	{
		strcpy_s(stt, CStringA(cac_stt_can_xoa).GetString());
		chuyen_sang_block(stt);
		stt_con = cac_stt_can_xoa.Tokenize(_T(","), vi_tri);
	}
	OnBnClickedHienThiDanhSach();
}
