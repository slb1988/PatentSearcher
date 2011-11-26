// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#pragma once

// Change these values to use different versions
#define WINVER		0x0500
#define _WIN32_WINNT	0x0501
#define _WIN32_IE	0x0501
#define _RICHEDIT_VER	0x0200

#define  WM_DISPLAT_SEARCH_VIEW 10001

 #include "winsock2.h"


#include <atlbase.h>
// 修正CString 定义不明确的错误
#include <atlstr.h>
#define _WTL_NO_CSTRING
#include <atlapp.h>

extern CAppModule _Module;

//显示浏览器
#include <atlcom.h>
#include <atlhost.h>
#include <atlwin.h>
#include <atlctl.h>

//Tiff
#include "tiffio.h"

#include <atltime.h>

#include <atlcrack.h>
#include <atlframe.h>
#include <atlmisc.h>
#include <atldlgs.h>
#include <atlsplit.h>			//WTL的分隔窗口类
#include <atlctrls.h>
#include <atlctrlx.h>
#include <atlctrlw.h>
#include <atlddx.h>

#define _WTL_NO_CSTRING
extern CString global_Search_str;
extern CString global_CheckBox_str;



#define END_MSG_MAP_EX	END_MSG_MAP
#pragma warning (disable:4146)
#import "C:\Program Files\Common Files\System\ado\msado15.dll" no_namespace \
	rename("EOF","adoEOF")rename("BOF","adoBOF")

// 
// #include <shlobj.h>
// #include <shlguid.h>
// 
// #include <vector>
// #include <map>
#if defined _M_IX86
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
