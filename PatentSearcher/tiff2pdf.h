#include "stdafx.h"

typedef int ( *PFN_open_PDF)(const char *);
PFN_open_PDF open_PDF; 	
typedef int ( *PFN_close_PDF)(const char *,const char *);
PFN_close_PDF close_PDF;
typedef int ( *PFN_add_TIFF)(const char *);
PFN_add_TIFF add_TIFF;
HINSTANCE hDll;

void LoadDll()
{
	if(hDll=LoadLibrary(_T("tif2pdf.dll"))) {

		open_PDF=(PFN_open_PDF)GetProcAddress(hDll,"open_PDF");
		add_TIFF=(PFN_add_TIFF)GetProcAddress(hDll,"add_TIFF");
		close_PDF=(PFN_close_PDF)GetProcAddress(hDll,"close_PDF");	   	
	}

}


int OpenPDF(const char *n)
{
	if (open_PDF)
		return (*open_PDF)(n);
	else
		return -1;

}


int AddTIFF(const char *n)
{
	if (add_TIFF)
		return (*add_TIFF)(n);
	else
		return -1;

}

int ClosePDF(const char *n,const char *n1)
{
	if (close_PDF)
		return (*close_PDF)(n,n1);
	else
		return -1;
}

