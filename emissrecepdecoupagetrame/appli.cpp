//---------------------------------------------------------------------------
 #include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <vcl.h>
#pragma hdrstop
#include <sstream>
#include <iostream.h>
#include <stdlib.h>
#include <vector>
#include <deque>
#include "mysql.h"
#include "appli.h"
#define __WIN__
#include "appli.h"
#include "RS232.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	port.Open();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonSendClick(TObject *Sender)
{

	MYSQL *conn;
	mySQL = mysql_init(NULL);
	std::stringstream stringbuilder;
	Latitude2=Latitude.ToDouble();
	Longitude2=Longitude.ToDouble();
 conn=mysql_real_connect(mySQL, "192.168.65.233", "root", "root", "lawrence", 0, NULL, 0);



		if(conn==NULL)
		{

		}
		else
		{
			stringbuilder << "INSERT INTO `positionETvitess` ( `Latitude`,`Longitude`) VALUES (" << Latitude2 << "," << Longitude2 << ")";
			mysql_query(mySQL, stringbuilder.str().c_str());
		}


//	char * test = new char[Edit1->Text.Length()];
//	wcstombs(test, Edit1->Text.w_str(), Edit1->Text.Length() + 1);
//	port.Write(test, strlen(test) + 1);
//	Edit1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonReceiveClick(TObject *Sender)
{
	 char *buf =  port.Read();
	 Latitude="" ;
	 Longitude="" ;
	UnicodeString str = "";
	for(int i = 0; i < 50; i++)
	{
				str += buf[i];
			if (buf[i]=='N' && buf[i-1]==',' && buf[i-19] =='A' && buf[i-20] == 'G' && buf[i-21] == 'G') {
			   Latitude+= buf[i-10];
			   Latitude+= buf[i-9];
			   Latitude+= buf[i-8];
			   Latitude+= buf[i-7];
			   Latitude+= buf[i-5];
			   Latitude+= buf[i-4];
			   Latitude+= buf[i-3];
			   Latitude+= buf[i-2];

			}
			if (buf[i]=='E' && buf[i-1]==','&& buf[i-34] =='G' && buf[i-33] == 'G' && buf[i-32] == 'A') {
			   Longitude+= buf[i-11];
			   Longitude+= buf[i-10];
			   Longitude+= buf[i-9];
			   Longitude+= buf[i-8];
			   Longitude+= buf[i-7];
			   Longitude+= buf[i-5];
			   Longitude+= buf[i-4];
			   Longitude+= buf[i-3];
			   Longitude+= buf[i-2];
			}

		Memo1->Lines->Add(str);

	}
	//latitude.ToDouble();
	 Memo1->Lines->Add(buf);
	 Memo2->Lines->Add(Latitude);
	 Memo3->Lines->Add(Longitude);


}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
    port.Close();
}
//---------------------------------------------------------------------------

