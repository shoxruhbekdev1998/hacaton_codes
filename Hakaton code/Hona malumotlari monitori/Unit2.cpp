//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
 #include <windows.h>

#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int son = 0;
float temperatura, namlik, co_miqdori, Lux, organik;
String hona = "Oshxona";

HANDLE hSerial;
   int chang1=0;
   int chang2=0;
   int chang10=0;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
hSerial =  CreateFile(L"COM3", GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL); // COM portni ochish
	DCB dcbSerialParams = { 0 };
	dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
	GetCommState(hSerial, &dcbSerialParams);
	dcbSerialParams.BaudRate = CBR_9600; // Baud tezligi
	dcbSerialParams.ByteSize = 8;
	dcbSerialParams.StopBits = ONESTOPBIT;
	dcbSerialParams.Parity = NOPARITY;
	SetCommState(hSerial, &dcbSerialParams);
	COMMTIMEOUTS timeouts = { 0 };
	timeouts.ReadIntervalTimeout = 50;
	timeouts.ReadTotalTimeoutConstant = 50;
	timeouts.ReadTotalTimeoutMultiplier = 10;
	timeouts.WriteTotalTimeoutConstant = 50;
	timeouts.WriteTotalTimeoutMultiplier = 10;
	SetCommTimeouts(hSerial, &timeouts);
}
//---------------------------------------------------------------------------







void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
CloseHandle(hSerial);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
 for (int i = Memo1->Lines->Count - 1; i >= 0; i--)
		{
			if (Memo1->Lines->Strings[i].Trim() == "")
			{
				Memo1->Lines->Delete(i);
			}
		}
	if (Memo1->Lines->Count >= 6) {
		Memo1->Lines->Clear();

		}





 DWORD bytesRead;
	char incomingData[1024] = ""; // Kiritilgan malumot
	ReadFile(hSerial, incomingData, sizeof(incomingData), &bytesRead, NULL); // Portdan malumotni o'qish
	Memo1->Lines->Add(incomingData);



}
//---------------------------------------------------------------------------




void __fastcall TForm2::Button1Click(TObject *Sender)
{
 Image1->Visible=true;
 Image2->Visible=false;

}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
 Image2->Visible=true;
 Image1->Visible=false;
 Label1->Color=clRed;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
//CloseHandle(hSerial);
Timer1->Interval=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
 Timer1->Interval=500;
//  DWORD bytesRead;
//	char incomingData[1024] = ""; // Kiritilgan malumot
//	ReadFile(hSerial, incomingData, sizeof(incomingData), &bytesRead, NULL); // Portdan malumotni o'qish
//	Memo1->Lines->Add(incomingData);
//	Label1->Caption = Memo1->Lines->Strings[0];
//	Label2->Caption = Memo1->Lines->Strings[1];
//	Label3->Caption = Memo1->Lines->Strings[2];
//	Label4->Caption = Memo1->Lines->Strings[3];
//	Label5->Caption = Memo1->Lines->Strings[4];
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TForm2::Timer2Timer(TObject *Sender)
{
  String soz = Memo1->Text.Trim();

if (soz != "") {


   if (Memo1->Lines->Strings[0] != 1 && Memo1->Lines->Strings[1] != 1 && Memo1->Lines->Strings[2] != 1 ) {


	chang1 = StrToInt(Memo1->Lines->Strings[0]);
	chang2 = StrToInt(Memo1->Lines->Strings[1]);
	chang10 = StrToInt(Memo1->Lines->Strings[2]);
   }
	String a  = Memo1->Lines->Strings[3];
	String b = StringReplace(a, ".", ",", TReplaceFlags() << rfReplaceAll);
	temperatura = StrToFloat(b);

	String a1  = Memo1->Lines->Strings[4];
	String b1 = StringReplace(a1, ".", ",", TReplaceFlags() << rfReplaceAll);
	namlik = StrToFloat(b1);

	String a2  = Memo1->Lines->Strings[5];
	String b2 = StringReplace(a2, ".", ",", TReplaceFlags() << rfReplaceAll);
	co_miqdori = StrToFloat(b2);

	String a3  = Memo1->Lines->Strings[6];
	String b3 = StringReplace(a3, ".", ",", TReplaceFlags() << rfReplaceAll);

	 Lux = StrToFloat(b3);

	String a4  = Memo1->Lines->Strings[7];
	String b4 = StringReplace(a4, ".", ",", TReplaceFlags() << rfReplaceAll);
	organik = StrToFloat(b4);

	Series1->Clear();
	Chart1->Title->Clear();

	Series1->Add(chang1, " Chang PM[1.0]", clYellow);
	Series1->Add(chang2, " Chang PM[2.5]", clGreen);
	Series1->Add(chang10, " Chang PM[10.0]", clBlue);
	Series1->Add(temperatura, " Temperatura", clRed);
	Series1->Add(namlik, " Namlik", clGreen);
	Series1->Add(co_miqdori, " Co miqdori(PPM)", clGreen);
   //	Series1->Add(Lux, " Lux darajasi", clGreen);
   Label9->Caption = FloatToStr(Lux);
	Series1->Add(organik, " Organik gaz(PPM)", clRed);

	Chart1->Legend->Visible = true;
	Chart1->Legend->TextStyle = ltsLeftValue;
	Chart1->Title->Text->Add("Hona ma'lumotlari");

	son = son+1;
	if (son > 5) {
	String vaqt = FormatDateTime("yyyy-mm-dd hh:nn:ss", Now());
		DataModule1->ADOQuery1->Close();
		DataModule1->ADOQuery1->SQL->Text = " insert into hona (hona, temperatura, namlik, organik_gaz, is_gazi, chang1, chang2, chang3, lux, vaqt) values ('"+hona+"', '"+temperatura+"', '"+namlik+"', '"+organik+"', '"+co_miqdori+"', '"+chang1+"', '"+chang2+"', '"+chang10+"', '"+Lux+"', '"+vaqt+"') ";
		DataModule1->ADOQuery1->ExecSQL();
		DataModule1->ADOQuery1->SQL->Text = " select * from hona ";
		DataModule1->ADOQuery1->Open();
		son = 0;


	}

}

}
//---------------------------------------------------------------------------

