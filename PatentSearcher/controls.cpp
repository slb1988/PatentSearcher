// Controls.cpp
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"
#include "Controls.h"
#include "atlgdix.h"


#define COLOR_HOTLIGHT  26

BOOL CMenuTreeView::PreTranslateMessage(MSG* pMsg)
{
	pMsg;
	return FALSE;
}

LRESULT CMenuTreeView::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	LRESULT lRet = DefWindowProc(uMsg, wParam, lParam);

	bHandled = TRUE;
	return lRet;
}

LRESULT CMenuTreeView::OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled)
{
	bHandled = FALSE;
	return 0;
}


/////////////////////////////////////////////////////////////////////////////
BOOL CSdiDlgView::PreTranslateMessage(MSG* pMsg)
{
	return IsDialogMessage(pMsg);
}

LRESULT CSdiDlgView::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	this->SetWindowText(_T("Dialog View"));

	HICON hIcon = (HICON)::LoadImage(_Module.GetResourceInstance(),
		MAKEINTRESOURCE(IDR_MAINFRAME),IMAGE_ICON, 16, 16, LR_SHARED);
	this->SetIcon(hIcon, ICON_SMALL);

	DlgResize_Init(false, true, WS_CLIPCHILDREN);
	return 0;
}

LRESULT CSdiDlgView::OnForwardMsg(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM lParam, BOOL& /*bHandled*/)
{
	LPMSG pMsg = (LPMSG)lParam;

	return this->PreTranslateMessage(pMsg);
}


/////////////////////////////////////////////////////////////////////////////
LRESULT CCustomListView::OnPaint(UINT uMsg, WPARAM wParam, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	if( wParam != NULL )
	{
		CMemDC memdc((HDC)wParam, NULL);

		memdc.FillSolidRect(&memdc.m_rc, ::GetSysColor(COLOR_WINDOW));
		this->DefWindowProc( uMsg, (WPARAM)memdc.m_hDC, 0);
	}
	else
	{
		CPaintDC dc(m_hWnd);
		CMemDC memdc(dc.m_hDC, &dc.m_ps.rcPaint);

		memdc.FillSolidRect(&dc.m_ps.rcPaint, ::GetSysColor(COLOR_WINDOW));
		this->DefWindowProc( uMsg, (WPARAM)memdc.m_hDC, 0);
	}
	return 0;
}

LRESULT CCustomListView::OnEraseBackground(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// Erase the background in OnPaint
	return 1;
}

DWORD CCustomListView::OnPrePaint(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/)
{
	return CDRF_NOTIFYITEMDRAW;
}

DWORD CCustomListView::OnItemPrePaint(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/)
{
	return CDRF_NOTIFYPOSTPAINT;
}

DWORD CCustomListView::OnItemPostPaint(int /*idCtrl*/, LPNMCUSTOMDRAW lpNMCustomDraw)
{
	CDCHandle dc( lpNMCustomDraw->hdc );

	int nItem = (int)lpNMCustomDraw->dwItemSpec;

	RECT rcItem;
	this->GetItemRect(nItem, &rcItem, LVIR_BOUNDS);

	CPen penOutline;
	if(this->GetItemState(nItem, LVIS_SELECTED) == LVIS_SELECTED)
	{
		penOutline.CreatePen(PS_SOLID, 1, ::GetSysColor(COLOR_HIGHLIGHT));
	}
	else 
	{
		penOutline.CreatePen(PS_SOLID, 1, ::GetSysColor(COLOR_GRAYTEXT));
	}

	CPenHandle penOld = dc.SelectPen(penOutline);

	dc.MoveTo(rcItem.left, rcItem.top);
	dc.LineTo(rcItem.left, rcItem.bottom-1);
	dc.LineTo(rcItem.right-1, rcItem.bottom-1);
	dc.LineTo(rcItem.right-1, rcItem.top);
	dc.LineTo(rcItem.left, rcItem.top);

	dc.SelectPen(penOld);

	return CDRF_DODEFAULT;
}