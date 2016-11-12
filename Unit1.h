//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "CSPIN.h"
#include <Mask.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Counting;
        TTimer *Timer1;
        TLabel *Label_title;
        TImage *Background;
        TImage *Start_button;
        TImage *Start_button_click;
        TImage *Switch1;
        TImage *Switch2;
        TImage *Stop_button;
        TImage *Stop_button_click;
        TLabel *Lab_za;
        TLabel *Lab_godz;
        TLabel *Label_godz;
        TLabel *Label_min;
        TMaskEdit *SetTime;
        TLabel *Label1;
        TLabel *Label2;
        TMaskEdit *Minutes;
        TLabel *Label3;
        TMaskEdit *Hours;
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall Start_buttonClick(TObject *Sender);
        void __fastcall Start_buttonMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Start_buttonMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Switch1Click(TObject *Sender);
        void __fastcall Switch2Click(TObject *Sender);
        void __fastcall Stop_buttonClick(TObject *Sender);
        void __fastcall Stop_buttonMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Stop_buttonMouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
