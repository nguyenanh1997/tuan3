#pragma once


// DANH_SACH_BAN_BE dialog

class DANH_SACH_BAN_BE : public CDialog
{
	DECLARE_DYNAMIC(DANH_SACH_BAN_BE)

public:
	DANH_SACH_BAN_BE(CString tai_khoan = NULL, CWnd* pParent = nullptr);   // standard constructor
	virtual ~DANH_SACH_BAN_BE();
	CString TAI_KHOAN;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DANH_SACH_BAN_BE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl danh_sach;
	CString tai_khoan_cua_ban_be;
	int kiem_tra_stt();
	afx_msg void OnBnClickedHienThiDanhSach();
	afx_msg void OnBnClickedThemBan();
	afx_msg void OnBnClickedBlock();
	int STT;
	int so_lan_an_load_danh_sach_tin;
	CString THOI_GIAN_KET_BAN;
	CString KHOANG_THOI_GIAN;
	void chuyen_sang_block(char *stt_dau_vao);
	int kiem_tra_da_ket_ban_chua(CString ten_nguoi_can_kiem_tra, CString ten_file, CString tai_khoan_cua_ban);
};
