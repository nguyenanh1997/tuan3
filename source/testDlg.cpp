
// testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include "afxdialogex.h"
#include <sstream>
#include <fstream>
#include <winsqlite/winsqlite3.h>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CtestDlg dialog



CtestDlg::CtestDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEST_DIALOG, pParent)
	, TAI_KHOAN(_T(""))
	, MAT_KHAU(_T(""))
	, GIOI_TINH(_T(""))
	, NOI_O(_T(""))
	, NGAY_SINH(_T(""))
	, HO_TEN(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_TAI_KHOAN, TAI_KHOAN);
	DDX_Text(pDX, IDC_MAT_KHAU, MAT_KHAU);
	DDX_Text(pDX, IDC_GIOI_TINH, GIOI_TINH);
	DDX_Text(pDX, IDC_NOI_O, NOI_O);
	DDX_Text(pDX, IDC_NGAY_SINH, NGAY_SINH);
	DDX_Text(pDX, IDC_HO_TEN, HO_TEN);
}

BEGIN_MESSAGE_MAP(CtestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CtestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CtestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_DANG_KY, &CtestDlg::OnBnClickedDangKy)
END_MESSAGE_MAP()


// CtestDlg message handlers

BOOL CtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CtestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtestDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}

// dang nhap ne
void CtestDlg::OnBnClickedButton1()
{
	ifstream file_thong_tin;
	char tai_khoan[100], mat_khau[100], ho_ten[100], gioi_tinh[100], noi_o[100], ngay_sinh[100];
	CString Cstring_Tai_khoan, CString_mat_khau;
	file_thong_tin.open("thong_tin.txt");
	GetDlgItemText(IDC_TAI_KHOAN, this->TAI_KHOAN);
	GetDlgItemText(IDC_MAT_KHAU, this->MAT_KHAU);
	while (!file_thong_tin.eof())
	{
		file_thong_tin.getline(tai_khoan, 100);
		file_thong_tin.getline(mat_khau, 100);
		file_thong_tin.getline(ho_ten, 100);
		file_thong_tin.getline(gioi_tinh, 100);
		file_thong_tin.getline(ngay_sinh, 100);
		file_thong_tin.getline(noi_o, 100);
		Cstring_Tai_khoan = CString(tai_khoan);
		CString_mat_khau = CString(mat_khau);
		if (Cstring_Tai_khoan.Compare(this->TAI_KHOAN)==0)
		{
			if (CString_mat_khau.Compare(this->MAT_KHAU) == 0)
			{
				MessageBox(_T("Dang nhap thanh cong"));
				this->TRANG_THAI_DANG_NHAP = 1;
				this->ShowWindow(SW_HIDE);
				menu *MENU = new menu(this->TAI_KHOAN);
				if (MENU->DoModal() == IDOK)
				{
					MENU->ShowWindow(SW_SHOW);
					break;
				}
				else
				{
					this->ShowWindow(SW_SHOW);
					this->TRANG_THAI_DANG_NHAP = 0;
					break;
				}
			}
			else
			{
				MessageBox(_T("Nhap sai mat khau roi"));
			}
		}
	}
	file_thong_tin.close();
}
void CtestDlg::OnBnClickedDangKy()
{
	ofstream file_thong_tin;
	char tai_khoan[100], mat_khau[100], ho_ten[100], gioi_tinh[100], noi_o[100], ngay_sinh[100];
	file_thong_tin.open("thong_tin.txt",ios::app);
	GetDlgItemText(IDC_TAI_KHOAN_DANG_KY, this->TAI_KHOAN);
	strcpy_s(tai_khoan, CStringA(this->TAI_KHOAN).GetString());
	file_thong_tin << tai_khoan << endl;
	GetDlgItemText(IDC_MAT_KHAU_DANG_KY, this->MAT_KHAU);
	strcpy_s(mat_khau, CStringA(this->MAT_KHAU).GetString());
	file_thong_tin << mat_khau << endl;
	GetDlgItemText(IDC_HO_TEN, this->HO_TEN);
	strcpy_s(ho_ten, CStringA(this->HO_TEN).GetString());
	file_thong_tin << ho_ten << endl;
	GetDlgItemText(IDC_GIOI_TINH, this->GIOI_TINH);
	strcpy_s(gioi_tinh, CStringA(this->GIOI_TINH).GetString());
	file_thong_tin << gioi_tinh << endl;
	GetDlgItemText(IDC_NGAY_SINH, this->NGAY_SINH);
	strcpy_s(ngay_sinh, CStringA(this->NGAY_SINH).GetString());
	file_thong_tin << ngay_sinh << endl;
	GetDlgItemText(IDC_NOI_O, this->NOI_O);
	strcpy_s(noi_o, CStringA(this->NOI_O).GetString());
	file_thong_tin << noi_o << endl;
	file_thong_tin.close();
}

void CtestDlg::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void CtestDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
}



