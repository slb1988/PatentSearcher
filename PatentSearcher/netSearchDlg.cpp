// netsearchdlg.cpp : implementation of the CNetSearchDlg class
//
/////////////////////////////////////////////////////////////////////////////



#include "stdafx.h"


//#include <afxinet.h>
#include "resource.h"

#include "netsearchdlg.h"
#include <string>
#include <fstream>

using namespace std;

#include <stdio.h>


#include <wininet.h>
#define MAXBLOCKSIZE 1024*16
#pragma comment( lib, "wininet.lib" )

LRESULT CNetSearchDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{

	CenterWindow(GetParent());


	return TRUE;
}

LRESULT CNetSearchDlg::OnCloseCmd(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{

	EndDialog(wID);
	return 0;
}

LRESULT CNetSearchDlg::OnBnClickedBtnSearch(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
{

	 global_Search_str = GetSearchStr();
 	
	 if ( BST_CHECKED == IsDlgButtonChecked(IDC_CHECK_INVENT_PATENT))
	 {
		 global_CheckBox_str.Append(L"&selectbase=11");
	 }
	 else if ( BST_CHECKED == IsDlgButtonChecked(IDC_CHECK_APP_PATENT))
	 {
		 global_CheckBox_str.Append(L"&selectbase=22");
	 }
	 else if ( BST_CHECKED == IsDlgButtonChecked(IDC_CHECK_DESIGN_PATENT))
	 {
		 global_CheckBox_str.Append(L"&selectbase=33");
	 }
	 else global_CheckBox_str=L"";
	 
	 

	 if (L"" != global_Search_str)
	 {
		/* SendMessage(parent_hwnd,WM_SEARCH_RESULT,0,0);*/
	     EndDialog(IDOK);
	 }
	 

	
	return 0;
}

CString CNetSearchDlg::GetSearchStr()
{
	if ( !DoDataExchange(true) )
		exit(0);

	CString num;     //申请（专利）号
	CString zldate;  //公开（公告）日
	CString op_num;  // 公开（公告）号
	CString man;     //申请（专利权）人
	CString cate_num; //分类号
	CString zhaiyao;   //摘要
	CString address;  //地址
	CString name;     //名称
	CString design_man; //发明设计人
	CString zcate_num; //主分类号
	CString sqdate;      //申请日
	CString bzdate;      //颁证日
	CString dl_orga;     //专利代理机构
	CString priority;    //优先权
	CString ysq_num;     //分案原申请号
	CString dl_man;      //代理人
	CString gjgb;     //国际公布
	CString zqx;  //主权项
	CString multi_str;   //用户写的检索表达式
	CString temp_str;  
	CString str;         //检索表达式

	int str_leng;
	int  leng;
	int  mulleng;

	CString  counstr;


	num = m_app_num;             //申请（专利）号
	name = m_app_name;            //名  称
	zhaiyao = m_app_abstract;        //摘要
	sqdate = m_apply_date;          //申请日
	zldate = m_public_date;         //公开（公告）日
	op_num = m_public_num;          //公开（公告）号
	cate_num = m_classify_num;        //分类号
	zcate_num = m_major_classify_num;  //主分类号
	man = m_app_person;          //申请(专利权)人
	design_man = m_invent_person;        //发明（设计）人
	address = m_address;              //地址
	gjgb = m_international_public; //国际公布
	bzdate = m_certification_date;   //颁证日
	dl_orga = m_agent;                //专利代理机构
	dl_man = m_attorney;             //代理人
	priority = m_priority;             //优先权


	leng=num.GetLength();
	mulleng=multi_str.GetLength();

	if (cate_num!="") { 
		cate_num.Replace(L"/",L"\\/");
		//cate_num=cate_num.replace("-","?");
		cate_num.Replace(L"-",L"\\-");        
		str=str + "分类号=('%" + cate_num + "%') and ";         
	}

	if (num!="")
	{
		CString tmpstr;
		for (int  i=0;i < num.GetLength();i++)
		{
			tmpstr="";
			if ((Substring(num,i,i+1) >= '0') && (Substring(num,i,i+1) <= '9'))
			{	
				tmpstr=Substring(num,i,num.GetLength()-i+2);
				break;
			}	
		}

		if (tmpstr.GetLength()>10)
		{
			tmpstr=Substring(tmpstr,0,12);
		}
		else if (tmpstr.GetLength()>0)
		{
			tmpstr=Substring(tmpstr,0,8);
		}
		else
		{
			MessageBox(L"申请号输入错误！");
			exit(0);
		}
		//alert(tmpstr);
		tmpstr.Replace(L" ",L"");
		tmpstr.Replace(L"　",L"");
		str=str + "申请号=('CN%" + tmpstr + "%" + "') and ";

		/*
		num=num.replace("zl","CN");
		num=num.replace("ZL","CN");
		num=num.replace("ＺＬ","CN");
		num=num.replace(" ","");
		num=num.replace("　","");
		counstr=num.substring(0,2);

		if (counstr.toUpperCase()=="CN")
		{	str=str + "申请号=('" + num + "%" + "') and ";}
		else
		{	str=str + "申请号=('CN%" + num + "%" + "') and ";}
		*/
	} 		

	if (zldate!="")
	{
		if (Datechk(zldate)==1)
		{
			MessageBox(L"错误的日期格式！");
			//document.Advanceform1.textfield4.focus();
			exit(0);
		}

		zldate.Replace(L"-",L".");
		zldate.Replace(L"/",L".");
		zldate.Replace(L"——",L".");
		zldate.Replace(L"\\",L".");
		str=str + "公开（公告）日=(" + zldate + ") and ";
	}

	if (op_num!="") 
	{	
		counstr=Substring(op_num,0,2);
		CString Ctr = counstr;
		Ctr.MakeUpper();
		if (Ctr=="CN")
		{	str=str + "公开（公告）号=('" + op_num + "%') and ";
		}
		else
		{
			str=str + "公开（公告）号=('CN%" + op_num + "%') and ";
		}
	}

	if (man!="") 
	{
		/*	while (man.indexOf("%")!=-1)
		{
		man=man.replace("%","");
		}
		*/
		while (man.FindOneOf(L"％")!=-1)
		{
			man.Replace(L"％",L"%");
		}

		str=str + "申请（专利权）人=(" + man + ") and ";
	}

	if (design_man!="")
	{
		/*	while (design_man.indexOf("%")!=-1)
		{
		design_man=design_man.replace("%","");
		}
		*/
		while (design_man.FindOneOf(L"％")!=-1)
		{
			design_man.Replace(L"％",L"%");
		}
		str=str + "发明（设计）人=(" + design_man + ") and "; 
	}

	if (address!="")
	{
		//while (address.indexOf("%")!=-1)
		//{
		//	address=address.replace("%","");
		//}

		while (address.FindOneOf(L"％")!=-1)
		{
			address.Replace(L"％",L"%");
		}
		str=str + "地址=('" + address + "') and ";
	}

	if (name!="") 
	{ 
		//while (name.indexOf("%")!=-1)
		//{
		//	name=name.replace("%","");
		//}

		while (name.FindOneOf(L"％")!=-1)
		{
			name.Replace(L"％",L"%");
		}

		str=str + "名称=(" + name + ") and "; 
	}

	if (zhaiyao!="") 
	{
		//while (zhaiyao.indexOf("%")!=-1)
		//{
		//	zhaiyao=zhaiyao.replace("%","");
		//}

		while (zhaiyao.FindOneOf(L"％")!=-1)
		{
			zhaiyao.Replace(L"％",L"%");
		}

		str=str + "摘要=(" + zhaiyao + ") and ";
	}

	if (zcate_num!="") 
	{
		zcate_num.Replace(L"/",L"\\/");
		//zcate_num=zcate_num.replace("-","?");
		zcate_num.Replace(L"-",L"\\-");
		str=str + "主分类号=('" + zcate_num + "%') and ";
	}       

	if (sqdate!="")
	{
		if (Datechk(sqdate)==1)
		{
			MessageBox(L"错误的日期格式！");
			//document.Advanceform1.textfield12.focus();
			exit(0);
		}
		sqdate.Replace(L"-",L".");
		sqdate.Replace(L"/",L".");
		sqdate.Replace(L"\\",L".");
		sqdate.Replace(L"——",L".");
		str=str + "申请日=(" + sqdate + ") and ";
	}

	if (bzdate!="")
	{
		if (Datechk(bzdate)==1)
		{
			MessageBox(L"错误的日期格式！");
			//document.Advanceform1.textfield12.focus();
			exit(0);
		}         
		bzdate.Replace(L"-",L".");
		bzdate.Replace(L"/",L".");
		bzdate.Replace(L"\\",L".");
		bzdate.Replace(L"——",L".");
		str=str + "颁证日=(" + bzdate + ") and ";
	}

	if (dl_orga!="") 
	{
		/*	while (dl_orga.indexOf("%")!=-1)
		{
		dl_orga=dl_orga.replace("%","");
		}
		*/
		while (dl_orga.FindOneOf(L"％")!=-1)
		{
			dl_orga.Replace(L"％",L"%");
		}

		str=str + "专利代理机构=('" + dl_orga + "') and ";
	}

	if (dl_man!="") {
		/*	while (dl_man.indexOf("%")!=-1)
		{
		dl_man=dl_man.replace("%","");
		}
		*/
		while (dl_man.FindOneOf(L"％")!=-1)
		{
			dl_man.Replace(L"％",L"%");
		}

		str=str + "代理人=('" + dl_man + "') and ";
	}
	if (gjgb!="") {
		//gjgb=gjgb.replace(".","\\*");
		//gjgb=gjgb.replace(".","\\.");

		str=str + "国际公布=('%" + gjgb + "%') and ";
		str.Replace(L"/",L"\\/");
		str.Replace(L"-",L"\\-");
		str.Replace(L",",L"\\,");
		str.Replace(L".",L"\\*");
		str.Replace(L".",L"\\.");
		str.Replace(L"\\*",L"\\.");
	}

	if (priority!="") { 
		/*	while (priority.indexOf("%")!=-1)
		{
		priority=priority.replace("%","");
		}
		*/
		while (priority.FindOneOf(L"％")!=-1)
		{
			priority.Replace(L"％",L"%");
		}

		str=str + "优先权=('" + priority + "') and ";

		str.Replace(L"/",L"\\/");
		str.Replace(L"-",L"\\-");
		str.Replace(L",",L"\\,");
		str.Replace(L".",L"\\*");
		str.Replace(L".",L"\\.");
		str.Replace(L"\\*",L"\\.");

	}

	//if(flzt!="") { str=str + "法律状态=%" + flzt+ "% and ";} 

	if (zqx!="") 
	{
		str=str + "主权项=(" + zqx + ") and ";
	}
	if (ysq_num!="")
	{ 
		str=str + "分案原申请号=('%" + ysq_num + "%') and ";
	}

	str_leng=str.GetLength();
	if (str_leng==0)
	{   
		str="";
	}
	else
	{    
		str=Substring(str,0,str_leng-4);
	}

	if(str=="")
	{
		MessageBox(L"检索条件不能为空");
		//exit(0);
	}

	

	return str;
}

int CNetSearchDlg::Datechk(CString str)
{  
	//全部为字母
	CString strSource ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	LPCTSTR   ch ;
	int  i;
	int  temp;

	for (i=0;i<=(str.GetLength()-1);i++)
	{

		ch = new wchar_t( str.GetAt(i)) ;
		temp = strSource.FindOneOf((LPCTSTR) ch);
		if (temp==-1) 
		{
			return 0;
		}
	}
	if (strSource.FindOneOf((LPCTSTR)ch)==-1)
	{
		return 0;
	}
	else
	{
		return 1;
	} 
}

CString CNetSearchDlg::Substring(CString oldstr,int i,int j)
{
	CString sbstring;
	if (i>=oldstr.GetLength() ||/* j>=oldstr.GetLength() ||*/ i>=j)
	{
		return "";
	}


	//oldstr.Delete(j,oldstr.GetLength()-(j-i));

	sbstring = oldstr.Mid(i,j-i);

	return sbstring;
}


