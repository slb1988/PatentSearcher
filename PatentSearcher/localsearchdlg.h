// localsearchdlg.h : interface of the CLocalSearchDlg class
//
/////////////////////////////////////////////////////////////////////////////
/**
* @file
* Copyright (C) suxin.com
* @brief 定义专利检索对话框
* @author  sunlaibing88@gmail.com
* @date  2011-11-8
*/

#pragma once

class CLocalSearchDlg : public CDialogImpl<CLocalSearchDlg>,
		public CWinDataExchange<CLocalSearchDlg>
{
public:
	enum { IDD = IDD_DLG_LOCALSEARCH };

	BEGIN_MSG_MAP(CLocalSearchDlg)
		COMMAND_HANDLER(ID_BTN_SEARCH, BN_CLICKED, OnBnClickedBtnSearch)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		COMMAND_ID_HANDLER(IDOK, OnCloseCmd)
		COMMAND_ID_HANDLER(IDCANCEL, OnCloseCmd)
	END_MSG_MAP()

	// Handler prototypes (uncomment arguments if needed):
	//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	BEGIN_DDX_MAP(CLocalSearchDlg)
		DDX_TEXT(IDC_EDIT_APP_NUM, m_app_num)
		DDX_TEXT(IDC_EDIT_APP_NAME, m_app_name)
		DDX_TEXT(IDC_EDIT_APP_ABSTRACT, m_app_abstract)
		DDX_TEXT(IDC_EDIT_APPLY_DATE, m_apply_date)
		DDX_TEXT(IDC_EDIT_PUBLIC_DATE, m_public_date)
		DDX_TEXT(IDC_EDIT_PUBLIC_NUM, m_public_num)
		DDX_TEXT(IDC_EDIT_CLASSIFY_NUM, m_classify_num)
		DDX_TEXT(IDC_EDIT_MAJOR_CLASSIFY_NUM, m_major_classify_num)
		DDX_TEXT(IDC_EDIT_APP_PERSON, m_app_person)
		DDX_TEXT(IDC_EDIT_INVENT_PERSON, m_invent_person)
		DDX_TEXT(IDC_EDIT_ADDRESS, m_address)
		DDX_TEXT(IDC_EDIT_INTERNATIONAL_PUBLIC, m_international_public)
		DDX_TEXT(IDC_EDIT_CERTIFICATION_DATE, m_certification_date)
		DDX_TEXT(IDC_EDIT_AGENT, m_agent)
		DDX_TEXT(IDC_EDIT_ATTORNEY, m_attorney)
		DDX_TEXT(IDC_EDIT_PRIORITY, m_priority)
	END_DDX_MAP();
	
	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnCloseCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnBnClickedBtnSearch(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

private:
	CString m_app_num;             //申请（专利）号
	CString m_app_name;            //名  称
	CString m_app_abstract;        //摘要
	CString m_apply_date;          //申请日
	CString m_public_date;         //公开（公告）日
	CString m_public_num;          //公开（公告）号
	CString m_classify_num;        //分类号
	CString m_major_classify_num;  //主分类号
	CString m_app_person;          //申请(专利权)人
	CString m_invent_person;        //发明（设计）人
	CString m_address;              //地址
	CString m_international_public; //国际公布
	CString m_certification_date;   //颁证日
	CString m_agent;                //专利代理机构
	CString m_attorney;             //代理人
	CString m_priority;             //优先权
};
