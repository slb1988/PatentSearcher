// localsearchdlg.cpp : implementation of the CLocalSearchDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "localsearchdlg.h"

LRESULT CLocalSearchDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	CenterWindow(GetParent());
	return TRUE;
}

LRESULT CLocalSearchDlg::OnCloseCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	EndDialog(wID);
	return 0;
}

LRESULT CLocalSearchDlg::OnBnClickedBtnSearch(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{
	DoDataExchange(TRUE);

	CString str_Search = "";
	bool changed = false;
	if (m_app_num != "")
	{
		str_Search += "application_number like '%"+m_app_num + "%'";
		changed = true;
	}
	if (m_app_name != "")
	{
		if ( changed )
			str_Search += " and ";
		str_Search += " title like '%" + m_app_name + "%'";
		changed = true;
	}
	if (m_app_abstract != "")
	{
		if ( changed )
			str_Search += " and ";
		str_Search += " abstracts like '%" + m_app_abstract + "%'";
		changed = true;
	}
	if (m_apply_date != "")
	{
		if ( changed )
			str_Search += " and ";
		str_Search += " application_date='" + m_apply_date + "'";
		changed = true;
	}
	if (m_public_date != "")
	{
		if ( changed )
			str_Search += " and ";
		str_Search += " publication_date='" + m_public_date + "'";
		changed = true;
	}
	if (m_public_num != "")
	{
		if ( changed )
			str_Search += " and ";
		str_Search += " publication_number='" + m_public_num + "'";
		changed = true;
	}
	if (m_classify_num != "")
	{
		if ( changed )
			str_Search += " and ";
		str_Search += " classification='" + m_classify_num + "'";
		changed = true;
	}
	if (m_major_classify_num != "")
	{
		if ( changed )
			str_Search += " and ";
		str_Search += " main_classification='" + m_major_classify_num + "'";
		changed = true;
	}
	if (m_app_person != "")
	{
		if ( changed )
			str_Search += " and ";
		str_Search += " applicant like '%" + m_app_person + "%'";
		changed = true;
	}
	if (m_invent_person != "")
	{
		if ( changed )
			str_Search += " and ";
		str_Search += " inventor like ='%" + m_invent_person + "%'";
		changed = true;
	}
	if (m_address != "")
	{
		if ( changed )
			str_Search += " and ";
		str_Search += " address like '%" + m_address + "%'";
		changed = true;
	}
	if (m_international_public != "")
	{
		if ( changed )
			str_Search += " and ";
		str_Search += " international_publication like '%" + m_international_public + "%'";
		changed = true;
	}
	if (m_certification_date != "")
	{
		if ( changed )
			str_Search += " and ";
		str_Search += " grant_date='" + m_certification_date + "'";
		changed = true;
	}
	if (m_agent != "")
	{
		if ( changed )
			str_Search += " and ";
		str_Search += " agent like '%" + m_agent + "%'";
		changed = true;
	}
	if (m_attorney != "")
	{
		if ( changed )
			str_Search += " and ";
		str_Search += " attorney like '%" + m_attorney + "%'";
		changed = true;
	}
	if (m_priority != "")
	{
		if ( changed )
			str_Search += " and ";
		str_Search += " priority like '%" + m_priority + "%'";
		changed = true;
	}

	global_Search_str = "select * from sipo_data where " + str_Search;

	EndDialog(IDOK);

	return 0;
}
