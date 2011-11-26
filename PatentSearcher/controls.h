// Controls.h
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTROLS_H__3A3EDE40_24E0_4EB6_8AEE_6A03B7E6BD67__INCLUDED_)
#define AFX_CONTROLS_H__3A3EDE40_24E0_4EB6_8AEE_6A03B7E6BD67__INCLUDED_

#pragma once

class CMenuTreeView : public CWindowImpl<CMenuTreeView, CTreeViewCtrlEx>
{
public:
	//	DECLARE_WND_SUPERCLASS(_T("MyTree"), CTreeViewCtrlEx::GetWndClassName())

	BOOL PreTranslateMessage(MSG* pMsg);

	BEGIN_MSG_MAP(CMenuTreeView)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		DEFAULT_REFLECTION_HANDLER()
	END_MSG_MAP()

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnSelChanged(int /*idCtrl*/, LPNMHDR /*pNMHDR*/, BOOL& /*bHandled*/);
};


/////////////////////////////////////////////////////////////////////////////
class CSdiDlgView :
	public CDialogImpl<CSdiDlgView>,
	public CDialogResize<CSdiDlgView>
{
public:
	enum { IDD = IDD_DLG_LOCALSEARCH1 };

	BOOL PreTranslateMessage(MSG* pMsg);

	BEGIN_MSG_MAP(CSdiDlgView)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		MESSAGE_HANDLER(WM_FORWARDMSG, OnForwardMsg)
		CHAIN_MSG_MAP(CDialogResize<CSdiDlgView>)
		DEFAULT_REFLECTION_HANDLER()
	END_MSG_MAP()

	BEGIN_DLGRESIZE_MAP(CSdiDlgView)
		//	DLGRESIZE_CONTROL(IDC_EDIT1, DLSZ_SIZE_X)
		//	DLGRESIZE_CONTROL(IDC_BUTTON1, DLSZ_MOVE_X)
		//	DLGRESIZE_CONTROL(IDC_EDIT2, (DLSZ_SIZE_X | DLSZ_SIZE_Y))
	END_DLGRESIZE_MAP()

	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnForwardMsg(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
};


/////////////////////////////////////////////////////////////////////////////
class CCustomListView :
	public CWindowImpl<CCustomListView, CListViewCtrl>,
	public CCustomDraw<CCustomListView>
{
public:
	//	DECLARE_WND_SUPERCLASS(_T("MyList"), CListViewCtrl::GetWndClassName())

	BOOL PreTranslateMessage(MSG* pMsg) { pMsg; return FALSE; }

	BEGIN_MSG_MAP(CCustomListView)
		MESSAGE_HANDLER(WM_PAINT, OnPaint)
		MESSAGE_HANDLER(WM_PRINTCLIENT, OnPaint)
		MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBackground)
		CHAIN_MSG_MAP_ALT(CCustomDraw<CCustomListView>, 1)
		DEFAULT_REFLECTION_HANDLER()
	END_MSG_MAP()

	LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnEraseBackground(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);

	// Overrides of CCustomDraw to do our custom list view drawing
public:
	DWORD OnPrePaint(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/);
	DWORD OnItemPrePaint(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/);
	DWORD OnItemPostPaint(int /*idCtrl*/, LPNMCUSTOMDRAW /*lpNMCustomDraw*/);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONTROLS_H__3A3EDE40_24E0_4EB6_8AEE_6A03B7E6BD67__INCLUDED_)
