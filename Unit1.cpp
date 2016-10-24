//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

// czas w sekundach
int czas = 10;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
        czas--;
        int godziny, minuty, sekundy;
        AnsiString godz, min, sek;

        godziny = czas / 3600;
        godz = IntToStr(godziny);
        if (godziny < 10)
                godz = "0" + godz;

        minuty = (czas - godziny * 3600) / 60;
        min = IntToStr(minuty);
        if (minuty < 10)
                min = "0" + min;

        sekundy = czas - godziny * 3600 - minuty * 60;
        sek = IntToStr(sekundy);
        if (sekundy < 10)
                sek = "0" + sek;

        Label1 -> Caption = godz + ":" + min + ":" + sek;
        if (czas <= 0)
        {
                Label1 -> Caption = "Ciao...";
                WinExec("shutdown -s -t 1", SW_SHOW);
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Button1 -> Visible = false;
        ComboBox1 -> Visible = false;
        Label2 -> Visible = false;
        Timer1 -> Enabled = true;
        Label1 -> Visible = true;
        Label1 -> Caption = "No to lecimy...";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
        switch (Form1 -> ComboBox1 -> ItemIndex)
        {
                case 0: czas = 1800+1; break;
                case 1: czas = 3600+1; break;
                case 2: czas = 5400+1; break;
                case 3: czas = 7200+1; break;
                case 4: czas = 9000+1; break;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1CloseUp(TObject *Sender)
{
        Button1 -> Enabled = true;
}
//---------------------------------------------------------------------------

