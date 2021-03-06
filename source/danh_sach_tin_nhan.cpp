// danh_sach_tin_nhan.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "danh_sach_tin_nhan.h"
#include "afxdialogex.h"
#include <sstream>
#include <fstream>
#include <cstring>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
// danh_sach_tin_nhan dialog

IMPLEMENT_DYNAMIC(danh_sach_tin_nhan, CDialogEx)

danh_sach_tin_nhan::danh_sach_tin_nhan(CString nguoi_gui, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DANH_SACH_CAC_TIN_NHAN, pParent)
	, STT_TIN_NHAN_CAN_DOC(_T(""))
{
#ifndef _WIN32_WCE
	EnableActiveAccessibility();
#endif
	STR_NGUOI_NHAN = nguoi_gui;
	so_lan_an_load_danh_sach_tin = 0;
}

danh_sach_tin_nhan::~danh_sach_tin_nhan()
{
}

void danh_sach_tin_nhan::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DANH_SACH_TIN_NHAN, DANH_SACH_TIN);
	DDX_Text(pDX, IDC_STT_TIN_NHAN_CAN_DOC, STT_TIN_NHAN_CAN_DOC);
	DDX_Control(pDX, IDC_NOI_DUNG_TIN_NHAN_CAN_DOC, hien_thi_noi_dung_tin_nhan);
}


BEGIN_MESSAGE_MAP(danh_sach_tin_nhan, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_DANH_SACH_TIN_NHAN, &danh_sach_tin_nhan::OnLvnItemchangedDanhSachTinNhan)
	ON_BN_CLICKED(IDC_BUTTON2, &danh_sach_tin_nhan::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_XOA_TIN_NHAN, &danh_sach_tin_nhan::OnBnClickedXoaTinNhan)
	ON_BN_CLICKED(IDC_BUTTON1, &danh_sach_tin_nhan::OnBnClickedDocTin)
END_MESSAGE_MAP()

// danh_sach_tin_nhan message handlers


BOOL danh_sach_tin_nhan::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	DANH_SACH_TIN.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);
	DANH_SACH_TIN.InsertColumn(0, _T("STT"), LVCFMT_LEFT, 50);
	DANH_SACH_TIN.InsertColumn(1, _T("TEN NGUOI GUI"), LVCFMT_LEFT, 100);
	DANH_SACH_TIN.InsertColumn(2, _T("NOI_DUNG"), LVCFMT_LEFT, 200);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}


void danh_sach_tin_nhan::OnLvnItemchangedDanhSachTinNhan(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

// hien thi danh sach tin nhan!
void danh_sach_tin_nhan::OnBnClickedButton2()
{
	if (so_lan_an_load_danh_sach_tin != 0)
	{
		DANH_SACH_TIN.DeleteAllItems();
	}
	ifstream file_tin_nhan;
	char ten_nguoi_gui[100], ten_nguoi_nhan[100], noi_dung[100],stt[100];
	CString cstr_stt;
	CString STR_ten_nguoi_gui, STR_ten_nguoi_nhan, STR_noi_dung;
	file_tin_nhan.open("tin_nhan.txt", ios::in);
	if (file_tin_nhan.good()) {
		while (!file_tin_nhan.eof())
		{
			file_tin_nhan.getline(stt, 100);
			if (!file_tin_nhan.eof())
			{
				cstr_stt = CString(stt);
			}
			file_tin_nhan.getline(ten_nguoi_gui, 100);
			file_tin_nhan.getline(ten_nguoi_nhan, 100);
			file_tin_nhan.getline(noi_dung, 100);
			STR_ten_nguoi_gui = CString(ten_nguoi_gui);
			STR_ten_nguoi_nhan = CString(ten_nguoi_nhan);
			STR_noi_dung = CString(noi_dung);
			if (STR_NGUOI_NHAN.Compare(STR_ten_nguoi_nhan) == 0)
			{
				DANH_SACH_TIN.InsertItem(0, cstr_stt);
				DANH_SACH_TIN.SetItemText(0, 1, STR_ten_nguoi_gui);
				DANH_SACH_TIN.SetItemText(0, 2, STR_noi_dung);
			}
		}
		file_tin_nhan.close();
		so_lan_an_load_danh_sach_tin++;
	}
	else
		MessageBox(_T("khong co file tin nhan"));
}

void danh_sach_tin_nhan::XoaTinNhanTrongFile(char *stt_dau_vao)
{
	ifstream  file_can_xoa("tin_nhan.txt",ios::app);
	ofstream file_sau_khi_xoa("tin_nhan_tam.txt",ios::app);
	char ten_nguoi_gui[100], ten_nguoi_nhan[100], noi_dung[100], stt[100];
	CString ten_nguoi_nhan_de_so_sanh;
	while (!file_can_xoa.eof())
	{

		file_can_xoa.getline(stt, 100);
		file_can_xoa.getline(ten_nguoi_gui, 100);
		file_can_xoa.getline(ten_nguoi_nhan, 100);
		file_can_xoa.getline(noi_dung, 100);
		ten_nguoi_nhan_de_so_sanh = CString(ten_nguoi_nhan);
		if (strcmp(stt, stt_dau_vao) == 0 && ten_nguoi_nhan_de_so_sanh.Compare(STR_NGUOI_NHAN) == 0)
		{
			continue;
		}
		file_sau_khi_xoa << stt << endl;
		file_sau_khi_xoa << ten_nguoi_gui << endl;
		file_sau_khi_xoa << ten_nguoi_nhan << endl;
		file_sau_khi_xoa << noi_dung << endl;
	}
	file_can_xoa.close();
	file_sau_khi_xoa.close();
	remove("tin_nhan.txt");
	rename("tin_nhan_tam.txt", "tin_nhan.txt");

}
void danh_sach_tin_nhan::OnBnClickedXoaTinNhan()
{
	CString cac_stt_can_xoa;
	char stt[255];
	GetDlgItemText(IDC_STT, cac_stt_can_xoa);
	int vi_tri = 0;
	CString stt_con = cac_stt_can_xoa.Tokenize(_T(","), vi_tri);
	while (!stt_con.IsEmpty())
	{
		strcpy_s(stt, CStringA(cac_stt_can_xoa).GetString());
		XoaTinNhanTrongFile(stt);
		stt_con = cac_stt_can_xoa.Tokenize(_T(","), vi_tri);
	}
	OnBnClickedButton2();
}
void danh_sach_tin_nhan::OnBnClickedDocTin()
{
	GetDlgItemText(IDC_STT_TIN_NHAN_CAN_DOC, STT_TIN_NHAN_CAN_DOC);
	ifstream file_tin_nhan("tin_nhan.txt", ios::app);
	char stt_vua_lay_duoc[100];
	CString NOI_DUNG_TIN_NHAN_CAN_DOC;
	CString nguoi_nhan;
	char ten_nguoi_gui[100], ten_nguoi_nhan[100], noi_dung[100], stt[100];
	strcpy_s(stt_vua_lay_duoc, CStringA(STT_TIN_NHAN_CAN_DOC).GetString());
	while (!file_tin_nhan.eof())
	{

		file_tin_nhan.getline(stt, 100);
		file_tin_nhan.getline(ten_nguoi_gui, 100);
		file_tin_nhan.getline(ten_nguoi_nhan, 100);
		file_tin_nhan.getline(noi_dung, 100);
		nguoi_nhan = CString(ten_nguoi_nhan);
		if (STR_NGUOI_NHAN.Compare(nguoi_nhan) == 0)
		{
			if (strcmp(stt_vua_lay_duoc, stt) == 0)
			{	
				NOI_DUNG_TIN_NHAN_CAN_DOC = CString(noi_dung);
				hien_thi_noi_dung_tin_nhan.SetWindowTextW(NOI_DUNG_TIN_NHAN_CAN_DOC);
				break;
			}
		}
	}

}
