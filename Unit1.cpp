//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddle1upTimer(TObject *Sender)
{
        if (paddle1->Top > table->Top + 10)
                paddle1->Top -= 8;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::paddle1downTimer(TObject *Sender)
{
        if (paddle1->Top + paddle1->Height < table->Top + table->Height -10)
        paddle1->Top += 8;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 65)
                paddle1up->Enabled = true;
        if (Key == 90)
                paddle1down->Enabled = true;
        if (Key == VK_UP)
                paddle2up->Enabled = true;
        if (Key == VK_DOWN)
                paddle2down->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 65)
                paddle1up->Enabled = false;
        if (Key == 90)
                paddle1down->Enabled = false;
        if (Key == VK_UP)
                paddle2up->Enabled = false;
        if (Key == VK_DOWN)
                paddle2down->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::paddle2upTimer(TObject *Sender)
{
        if (paddle2->Top > table->Top + 10)
                paddle2->Top -= 8;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::paddle2downTimer(TObject *Sender)
{
        if (paddle2->Top + paddle2->Height < table->Top + table->Height -10)
        paddle2->Top += 8;
}
//---------------------------------------------------------------------------

