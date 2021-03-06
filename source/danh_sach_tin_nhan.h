#pragma once


// danh_sach_tin_nhan dialog

class danh_sach_tin_nhan : public CDialogEx
{
	DECLARE_DYNAMIC(danh_sach_tin_nhan)

public:
	danh_sach_tin_nhan(CString nguoi_gui = NULL, CWnd* pParent = nullptr);   // standard constructor
	virtual ~danh_sach_tin_nhan();
	
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DANH_SACH_CAC_TIN_NHAN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl DANH_SACH_TIN;
	CString STR_NGUOI_NHAN;
	int so_lan_an_load_danh_sach_tin;
	virtual BOOL OnInitDialog();
	void XoaTinNhanTrongFile(char *stt_dau_vao);
	afx_msg void OnLvnItemchangedDanhSachTinNhan(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedXoaTinNhan();
	CStatic DOC_TIN;
	afx_msg void OnBnClickedDocTin();
	CString STT_TIN_NHAN_CAN_DOC;
	CStatic hien_thi_noi_dung_tin_nhan;
	
};
