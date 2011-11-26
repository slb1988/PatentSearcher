// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include <string>
using namespace std;

#include "MySplitterWindowT.h"
//#include "ClipSpyListCtrl.h"
#include "MyPaneContainer.h"
#include "TreeCtrl.h"
#include "controls.h"
#include "myfunction.h"




const int INFOLISTVIEW = 1;
const int DOWNLOADLISTVIEW = 2;
const int SEARCHLISTVIEW = 4;

class CMainFrame : public CFrameWindowImpl<CMainFrame>, public CUpdateUI<CMainFrame>,
		public CMessageFilter, public CIdleHandler
{
public:
	DECLARE_FRAME_WND_CLASS(NULL, IDR_MAINFRAME)

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnIdle();

	BEGIN_UPDATE_UI_MAP(CMainFrame)
		UPDATE_ELEMENT(ID_VIEW_TOOLBAR, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_VIEW_STATUS_BAR, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(1, UPDUI_STATUSBAR)  // clock status
		UPDATE_ELEMENT(2, UPDUI_STATUSBAR)  // CAPS indicator
		UPDATE_ELEMENT(3, UPDUI_STATUSBAR)  // clock status
		UPDATE_ELEMENT(4, UPDUI_STATUSBAR)  // CAPS indicator
	END_UPDATE_UI_MAP()

	BEGIN_MSG_MAP(CMainFrame)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
		NOTIFY_CODE_HANDLER(TVN_SELCHANGED, OnSelChanged)
		NOTIFY_CODE_HANDLER(NM_RCLICK, OnNMRClickList)
		COMMAND_ID_HANDLER(ID_APP_EXIT, OnFileExit)
		COMMAND_ID_HANDLER(ID_FILE_NEW, OnFileNew)
		COMMAND_ID_HANDLER(ID_VIEW_TOOLBAR, OnViewToolBar)
		COMMAND_ID_HANDLER(ID_VIEW_STATUS_BAR, OnViewStatusBar)
		COMMAND_ID_HANDLER(ID_VIEW_TREE, OnViewTree)
		COMMAND_ID_HANDLER(ID_VIEW_DOWNLOAD, OnViewDownLoad)
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
		COMMAND_ID_HANDLER(ID_NET_SEARCH, OnNetSearch)
		COMMAND_ID_HANDLER(ID_LOCAL_SEARCH, OnLocalSearch)

		/************************************************************************/
		/* bellow added by aiwen                                               */
		/************************************************************************/

        COMMAND_ID_HANDLER(ID_SEARCH_LOADSELECT, OnSearchLoadselect)                //下载文件

		COMMAND_ID_HANDLER(ID_DOWNLOAD_START, OnStartDownloadSelect)      // 开始下载文件
		COMMAND_ID_HANDLER(ID_DOWNLOAD_STOP, OnStopDownload)              // 停止下载文件

		COMMAND_ID_HANDLER(ID_INFO_OPEN, OnOpenPdf)                                 //打开pdf文件

        COMMAND_ID_HANDLER(ID_SEARCH_PREV, OnSearchPrev)							//上一页
        COMMAND_ID_HANDLER(ID_SEARCH_NEXT, OnSearchNext)							//下一页

		CHAIN_MSG_MAP(CUpdateUI<CMainFrame>)
		CHAIN_MSG_MAP(CFrameWindowImpl<CMainFrame>)
		REFLECT_NOTIFICATIONS()				/*handle TVN_SELCHANGED etc.*/
//		DEFAULT_REFLECTION_HANDLER()
	END_MSG_MAP()
/************************************************************************/
/* 在父窗口中定义了REFLECT_NOTIFICATIONS(),
则必须在子控件的消息映射到最后加上 DEFAULT_REFLECTION_HANDLER();否则会出错。           
*/
/************************************************************************/

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnDestroy(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& bHandled);
	LRESULT OnFileExit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnFileNew(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewToolBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewStatusBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewTree(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewDownLoad(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnNetSearch(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnLocalSearch(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnOpenPdf(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSelChanged(int idCtrl, LPNMHDR pNMHDR, BOOL& bHandled);
	LRESULT OnNMRClickList(int idCtrl, LPNMHDR pNMHDR, BOOL& bHandled);



	/************************************************************************/
	/* bellow added by aiwen                                                */
	/************************************************************************/
	LRESULT OnSearchLoadselect(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);


	LRESULT OnSearchPrev(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnSearchNext(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

    LRESULT OnStartDownloadSelect(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnStopDownload(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	void InitLeftTreeView(CTreeViewCtrlEx *m_pTreeView);
	void InitListView(CListViewCtrl *m_pListView,int nType);
//	bool GetListValue();

	/************************************************************************/
	/*                                                                      */
	/************************************************************************/


protected:
	//先垂直分割，后水平分割
	CSplitterWindow m_wndVertSplitter;
	CHorSplitterWindow m_wndHorzSplitter;
	CSplitterWindow m_TopVertSplitter;
	CSplitterWindow m_BottomVertSplitter;
	CHorSplitterWindow m_TopHorzSplitter;

//	CMySplitterWindowT<true> m_wndVertSplitter;
//	CMySplitterWindowT<false> m_wndHorzSplitter;

	CMyPaneContainer m_wndTreeContainer;
	CMyPaneContainer m_wndIEContainer;
	

	CTreeCtrl m_Tree;

	CImageList m_LeftTreeImageList;
	CImageList m_StatusListImageList;
	
	CTreeViewCtrlEx m_MenuTree;			//左边树形菜单
	CAxWindow m_MainWebBrowser;					//初始介绍界面
	CAxWindow m_InfoWebBrowser;					//专利详细信息介绍

	CListViewCtrl m_InfoListView;
	CListViewCtrl m_DownloadListView;
	CListViewCtrl m_SearchListView;

	CMultiPaneStatusBarCtrl m_wndStatusBar;

	LRunSql m_runsql;					//连接数据库接口
	CString sql;						//数据库执行语句

	CString m_localSearchStr;

	CString currentPath ;

	string m_page_content;              // 页面内容

	int search_total_page;              // 查询结果的总页数

    int current_search_page;            // 当前查询结果的页号

    int current_display_groupid;            // 当前显示的groupid

	int last_dispay_page;                 // 当前显示页号

	bool stop_download_flag ; // 1 为下载停止，0为下载中

	bool download(CString url,const char *save_as);//下载页面

	string  UrlGB2312(char * str);     // 地址编码转化

	bool GetPatents(string pageCont, CString url);  // 获取专利列表

	int GetPageNum(string pageCont) ;  // 获取列表页数

	string ReadHtmlPage(string filename);  // 读取下载的a.html页面

	bool DoMerge(CString szPath, CString pdfPath);			//Tiff转化为pdf

	static UINT StartNetSearchThread(LPVOID); //ThreadProc1()
	static UINT StartDownloadThread(LPVOID);  //ThreadProc2()

    static UINT StartDownloadUnfinishedThread(LPVOID); //ThreadProc5()

	static UINT SearchNextThread(LPVOID);  //ThreadProc3()
	static UINT SearchPrevThread(LPVOID);  //ThreadProc4()

	bool ThreadProc1();  // 获取tmp.html
	bool ThreadProc2();  // 开始下载TIF文件
	bool ThreadProc3();  // next page
	bool ThreadProc4();  // prev page
	bool ThreadProc5();  // 下载未完成的

public:
 
	void Parse_Invent_Design_PatentDetails(string pgcontent ,string save_as_path,CString application_number,int item_index);//解析专利细节

	void Parse_Appearance_PatentDetails(string pgcontent,string save_as_path,CString application_number,int item_index);//解析专利细节

	// 下载专利说明
	void Patent_Specification_Download(string patent_num,string specification_url, string pgtotal,string save_as_path,int item_index);


	CString BCD_to_AnsiString(char *P_BCD,int length);

	string  Get_application_number(string url);

	bool Is_Stop_Current_Download(CString cstr_patent_number); // 判断是否要停止当前的下载
};
