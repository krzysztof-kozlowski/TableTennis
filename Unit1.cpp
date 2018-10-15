//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int ballX = 4;
int ballY = 4;

int punktyGraczLewy = 0;
int punktyGraczPrawy = 0;
int iloscOdbic = 0;

int seconds = 0;

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

void __fastcall TForm1::ballMoveWallTimer(TObject *Sender)
{
        ball->Top += ballX;
        ball->Left += ballY;

        if (ball->Top <= table->Top)
                ballX = -ballX;

        if (ball->Top + ball->Height >= table->Top + table->Height)
                ballX = -ballX;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::ballMoveLeftTimer(TObject *Sender)
{
        // ODBICIE
        if (ball->Top + (ball->Height / 2) > paddle1->Top &&
            ball->Top + (ball->Height / 2) < paddle1->Top + paddle1->Height &&
            (ball->Left > paddle1->Left + paddle1->Width - 10 &&
            ball->Left < paddle1->Left + paddle1->Width + 10))
            {
                 /*       // PRZYSPIESZENIE PILKI
                        if (ball->Top > paddle1->Top + 30 && ball->Top < paddle1->Top + 50)
                        {
                                if (ballX > 0 && ballY > 0)
                                {
                                        ballX += 1;     ballY += 1;
                                }
                                else if (ballX < 0 && ballY < 0)
                                {
                                        ballX -= 1;     ballY -= 1;
                                }
                                else if (ballX > 0 && ballY < 0)
                                {
                                        ballX += 1;     ballY -= 1;
                                }
                                else if (ballX < 0 && ballY > 0)
                                {
                                        ballX -= 1;     ballY += 1;
                                }
                        }   */

                        ballY = -ballY;
                        iloscOdbic++;
            }

        // SKUCHA
        if (ball->Left < paddle1->Left - paddle1->Width)
        {
                ballMoveLeft->Enabled = false;
                ballMoveRight->Enabled = false;
                gameTimer->Enabled = false;
                punktyGraczPrawy++;
                ball->Visible = false;
                whoPoint->Caption = "Punkt dla gracza prawego --->";
                whoPoint->Visible = true;
                result->Caption = IntToStr(punktyGraczPrawy) + " : " + IntToStr(punktyGraczLewy);
                result->Visible = true;
                bounceCounter->Caption = "Ilosc odbic: " + IntToStr(iloscOdbic);
                bounceCounter->Visible = true;
                gameDuration->Caption = "Czas gry: " + IntToStr(seconds) + " s";
                gameDuration->Visible = true;
                ButtonContinueGame->Visible = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ballMoveRightTimer(TObject *Sender)
{
        // ODBICIE
        if (ball->Top + (ball->Height / 2) > paddle2->Top &&
            ball->Top + (ball->Height / 2) < paddle2->Top + paddle2->Height &&
            (ball->Left + ball->Width > paddle2->Left - 10 &&
            ball->Left + ball->Width < paddle2->Left + 10))
            {
                    /*    // PRZYSPIESZENIE PILKI
                        if (ball->Top > paddle2->Top + 30 && ball->Top < paddle2->Top + 50)
                        {
                                if (ballX > 0 && ballY > 0)
                                {
                                        ballX += 1;     ballY += 1;
                                }
                                else if (ballX < 0 && ballY < 0)
                                {
                                        ballX -= 1;     ballY -= 1;
                                }
                                else if (ballX > 0 && ballY < 0)
                                {
                                        ballX += 1;     ballY -= 1;
                                }
                                else if (ballX < 0 && ballY > 0)
                                {
                                        ballX -= 1;     ballY += 1;
                                }
                        }   */

                        ballY = -ballY;
                        iloscOdbic++;
            }

        // SKUCHA
        if (ball->Left + ball->Width > paddle2->Left + (paddle1->Width * 2))
        {
                ballMoveLeft->Enabled = false;
                ballMoveRight->Enabled = false;
                gameTimer->Enabled = false;
                punktyGraczLewy++;
                ball->Visible = false;
                whoPoint->Caption = "<--- Punkt dla gracza lewego";
                whoPoint->Visible = true;
                result->Caption = IntToStr(punktyGraczLewy) + " : " + IntToStr(punktyGraczPrawy);
                result->Visible = true;
                bounceCounter->Caption = "Ilosc odbic: " + IntToStr(iloscOdbic);
                bounceCounter->Visible = true;
                gameDuration->Caption = "Czas gry: " + IntToStr(seconds) + " s";
                gameDuration->Visible = true;
                ButtonContinueGame->Visible = true;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ButtonContinueGameClick(TObject *Sender)
{
        ballX = 4;
        ballY = 4;
        ballMoveLeft->Enabled = true;
        ballMoveRight->Enabled = true;
        gameTimer->Enabled = true;
        iloscOdbic = 0;
        seconds = 0;
        whoPoint->Visible = false;
        result->Visible = false;
        bounceCounter->Visible = false;
        ButtonContinueGame->Visible = false;
        gameDuration->Visible = false;
        ball->Visible = true;
        ball->Top = table->Height / 2;
        ball->Left = table->Width / 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::gameTimerTimer(TObject *Sender)
{
        seconds++;
}
//---------------------------------------------------------------------------

