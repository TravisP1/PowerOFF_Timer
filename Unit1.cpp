//---------------------------------------------------------------------------

#include <vcl.h>
#include <time.h>
#include <string>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;

// czas w sekundach
int czas = 10;
// sprawdzanie trybu dzia³ania programu
bool tryb = 1;
bool clean = true;

void ClockOption()
{
        time_t a;
        tm * presentTime;
        time (&a);
        presentTime = localtime(&a);
        int hh = (*presentTime).tm_hour, mm = (*presentTime).tm_min;
        int hh_end, mm_end, sek_toend;
        // Wyci¹ganie godzin i minut ze stringa
        AnsiString godz, min;
        godz = Form1 -> SetTime -> Text;
        min = Form1 -> SetTime -> Text;
        godz = godz.Delete(3,3);
        min = min.Delete(1,3);
        hh_end = StrToInt(godz);
        mm_end = StrToInt(min);

        if (hh_end > 23 || mm_end > 59)
        {
                Application -> MessageBox("Nieprawid³owy format godziny!","Error", MB_ICONSTOP | MB_OK);
                Form1 -> SetTime -> Text = "00:00";
                clean = false;
        }
        else
                clean = true;

        if (hh_end > hh)
        {
                sek_toend = (hh_end - hh) * 3600;
                if (mm_end > mm)
                        sek_toend += (mm_end - mm) * 60;
                else
                        sek_toend -= (mm - mm_end) * 60;
        }
        else
        {
                sek_toend = (hh_end - hh + 24) * 3600;
                if (mm_end > mm)
                        sek_toend += (mm_end - mm) * 60;
                else
                        sek_toend -= (mm - mm_end) * 60;
        }

        czas = sek_toend;
}

void TimeOption()
{
        int hh_end, mm_end;
        // Wyci¹ganie godzin i minut ze stringow
        AnsiString ile = Form1 -> Hours -> Text;
        hh_end = StrToInt(ile);
        ile = Form1 -> Minutes -> Text;
        mm_end = StrToInt(ile);
        czas = hh_end * 3600 + mm_end * 60;
}


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

        Counting -> Caption = godz + ":" + min + ":" + sek;
        if (czas <= 0)
        {
                Counting -> Caption = "Ciao...";
                WinExec("shutdown -s -t 1", SW_SHOW);
        }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Start_buttonClick(TObject *Sender)
{
        switch (tryb)
        {
                case 0: ClockOption(); break;
                case 1: TimeOption(); break;
        }
        if (clean)
        {
                Timer1 -> Enabled = true;
                Counting -> Visible = true;
                Counting -> Caption = "No to lecimy...";
                Stop_button -> Visible = true;
                Start_button -> Visible = true;

                Label_title -> Visible = false;
                Switch1 -> Visible = false;
                Switch2 -> Visible = false;
                Lab_godz -> Visible = false;
                SetTime -> Visible = false;
                Lab_za -> Visible = false;
                Label_godz -> Visible = false;
                Label_min -> Visible = false;
                Hours -> Visible = false;
                Minutes -> Visible = false;
                Label1 -> Visible = false;
                Label2 -> Visible = false;
                Label3 -> Visible = false;
        }
        else
                clean = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Start_buttonMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Start_button_click -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Start_buttonMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Start_button_click -> Visible = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Switch1Click(TObject *Sender)
{
        tryb = 1;
        Switch1 -> Picture -> LoadFromFile("img/switch_on.bmp");
        Switch2 -> Picture -> LoadFromFile("img/switch_off.bmp");
        Switch1 -> Enabled = false;
        Switch2 -> Enabled = true;
        Lab_za -> Enabled = true;
        Label_godz -> Enabled = true;
        Label_min -> Enabled = true;
        Hours -> Enabled = true;
        Minutes -> Enabled = true;
        Lab_godz -> Enabled = false;
        SetTime -> Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Switch2Click(TObject *Sender)
{
        tryb = 0;
        Switch1 -> Picture -> LoadFromFile("img/switch_off.bmp");
        Switch2 -> Picture -> LoadFromFile("img/switch_on.bmp");
        Switch1 -> Enabled = true;
        Switch2 -> Enabled = false;
        Lab_godz -> Enabled = true;
        SetTime -> Enabled = true;
        Lab_za -> Enabled = false;
        Label_godz -> Enabled = false;
        Label_min -> Enabled = false;
        Hours -> Enabled = false;
        Minutes -> Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Stop_buttonClick(TObject *Sender)
{
        Label_title -> Visible = true;
        Timer1 -> Enabled = false;
        Counting -> Visible = false;
        Start_button -> Visible = true;
        Stop_button -> Visible = false;
        czas = 10;

        Switch1 -> Visible = true;
        Switch2 -> Visible = true;
        Lab_godz -> Visible = true;
        SetTime -> Visible = true;
        Lab_za -> Visible = true;
        Label_godz -> Visible = true;
        Label_min -> Visible = true;
        Hours -> Visible = true;
        Minutes -> Visible = true;
        Label1 -> Visible = true;
        Label2 -> Visible = true;
        Label3 -> Visible = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Stop_buttonMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Stop_button_click -> Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Stop_buttonMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
        Stop_button_click -> Visible = false; 
}
//---------------------------------------------------------------------------



