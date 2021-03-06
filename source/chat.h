#pragma once


// chat dialog

class chat : public CDialog
{
	DECLARE_DYNAMIC(chat)

public:
	chat(CString tai_khoan = NULL, CWnd* pParent = nullptr);   // standard constructor
	virtual ~chat();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHAT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedGuiTinNhan();
	int kiem_tra_stt();
	int kiem_tra_da_dang_ky_chua(char *tai_khoan_can_kiem_tra);
	int kiem_tra_block(char *tai_khoan_bi_block);
private:
	CString TEN_NGUOI_NHAN;
	CString TEN_NGUOI_GUI;
	CString NOI_DUNG;
	int STT;
};
