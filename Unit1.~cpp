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

int playerLeftPoints = 0;
int playerRightPoints = 0;
int numberOfBallBounced = 0;

int playerLeftNumberOfBouncingInTheMiddle = 0;
int playerRightNumberOfBouncingInTheMiddle = 0;

int gameDurationInSeconds = 0;

AnsiString servingPlayer = "playerLeft";

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        table->Width = Form1->Width - 14;
        table->Height = Form1->Height - 42;

        paddle1->Left = 50;
        paddle2->Left = table->Width - 70;

        ball->Top = table->Height / 2;
        ball->Left = table->Width / 2;

        brick1->Top = table->Top + 100;
        brick1->Left = table->Left + (table->Width / 2) - (brick1->Width / 2);
        brick2->Top = table->Top + table->Height - 100 - brick2->Height;
        brick1->Left = table->Left + (table->Width / 2) - (brick2->Width / 2);

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

        // SPECJALNE ZDOLNOSCI DLA GRACZA LEWEGO
                // zmiana kierunku pi³ki na swojej po³owie + przyspieszenie
        if (Key == 81)
        {
                if (playerLeftNumberOfBouncingInTheMiddle >= 1 && starYellowLeft->Visible == true &&
                    ballX > 0 && ball->Left <= table->Left + (table->Width / 2))
                {
                        ballX += 1;     ballY -= 1;
                        ballY = -ballY;

                        playerLeftNumberOfBouncingInTheMiddle = 0;
                        starYellowLeft->Visible = false;
                }
        }

        // SPECJALNE ZDOLNOSCI DLA GRACZA PRAWEGO
                // zmiana kierunku pi³ki na swojej po³owie + przyspieszenie
        if (Key == VK_LEFT)
        {
                if (playerRightNumberOfBouncingInTheMiddle >= 1 && starYellowRight->Visible == true &&
                    ballX < 0 && ball->Left >= table->Left + (table->Width / 2))
                {
                        ballX -= 1;     ballY += 1;
                        ballY = -ballY;

                        playerRightNumberOfBouncingInTheMiddle = 0;
                        starYellowRight->Visible = false;
                }
        }
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

        if (Key == 81)
                ;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::gameTimerTimer(TObject *Sender)
{
        gameDurationInSeconds++;

        if ((gameDurationInSeconds > 1) &&
            ((ball->Left <= (table->Width / 2 - brick1->Width)) ||
            (ball->Left >= (table->Width / 2 + brick1->Width))))
                brick1->Visible = true;

        if ((gameDurationInSeconds > 3) &&
            ((ball->Left <= (table->Width / 2 - brick2->Width)) ||
            (ball->Left >= (table->Width / 2 + brick2->Width))))
                brick2->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ballMovementTimer(TObject *Sender)
{
        ball->Left += ballX;
        ball->Top += ballY;

        if (ball->Top <= table->Top)
                ballY = -ballY;
        else if (ball->Top + ball->Height >= table->Top + table->Height)
                ballY = -ballY;

//******************************************************************************

        // odbicie lewa paletka
        if (ball->Top >= paddle1->Top - ball->Height &&
        ball->Top + ball->Height <= paddle1->Top + paddle1->Height + ball->Height &&
        ball->Left >= paddle1->Left + 15 &&
        ball->Left <= paddle1->Left + 25)
        {
                if (ball->Top >= paddle1->Top /*+ 30*/ && ball->Top + ball->Height <= paddle1->Top + paddle1->Height/*+ 70*/)
                        playerLeftNumberOfBouncingInTheMiddle++;

                ballX = -ballX;
                numberOfBallBounced++;
        }

        // skucha lewej paletki
        if (ball->Left < paddle1->Left - paddle1->Width)
        {
                playerRightPoints++;
                whoPoint->Caption = "Punkt dla gracza prawego --->";
                servingPlayer = "playerRight";

                ballMovement->Enabled = false;
                gameTimer->Enabled = false;
                ball->Visible = false;
                brick1->Visible = false;
                brick2->Visible = false;
                whoPoint->Visible = true;
                result->Caption = IntToStr(playerLeftPoints) + " : " + IntToStr(playerRightPoints);
                result->Visible = true;
                bounceCounter->Caption = "Ilosc odbic: " + IntToStr(numberOfBallBounced);
                bounceCounter->Visible = true;
                gameDuration->Caption = "Czas gry: " + IntToStr(gameDurationInSeconds) + " s";
                gameDuration->Visible = true;
                ButtonContinueGame->Visible = true;
        }

        if (playerRightNumberOfBouncingInTheMiddle >= 1)
                starYellowRight->Visible = true;

//******************************************************************************

        // odbicie prawa paletka
        if (ball->Top >= paddle2->Top - ball->Height &&
            ball->Top + ball->Height <= paddle2->Top + paddle2->Height + ball->Height &&
            ball->Left + ball->Width >= paddle2->Left - 5 &&
            ball->Left + ball->Width <= paddle2->Left + 5)
        {
                if (ball->Top >= paddle2->Top /*+ 30*/ && ball->Top + ball->Height <= paddle2->Top + paddle2->Height/*+ 70*/)
                        playerRightNumberOfBouncingInTheMiddle++;

                ballX = -ballX;
                numberOfBallBounced++;
        }

        // skucha prawej paletki
        if (ball->Left + ball->Width > paddle2->Left + (paddle2->Width * 2))
        {
                playerLeftPoints++;
                whoPoint->Caption = "<--- Punkt dla gracza lewego";
                servingPlayer = "playerLeft";

                ballMovement->Enabled = false;
                gameTimer->Enabled = false;
                ball->Visible = false;
                brick1->Visible = false;
                brick2->Visible = false;
                whoPoint->Visible = true;
                result->Caption = IntToStr(playerLeftPoints) + " : " + IntToStr(playerRightPoints);
                result->Visible = true;
                bounceCounter->Caption = "Ilosc odbic: " + IntToStr(numberOfBallBounced);
                bounceCounter->Visible = true;
                gameDuration->Caption = "Czas gry: " + IntToStr(gameDurationInSeconds) + " s";
                gameDuration->Visible = true;
                ButtonContinueGame->Visible = true;
        }

        if (playerLeftNumberOfBouncingInTheMiddle >= 1)
                starYellowLeft->Visible = true;


//******************************************************************************
        // odbicie brick1
        //odbicie z lewej strony
        if ((ball->Top >= brick1->Top - ball->Height && ball->Top + ball->Height <= brick1->Top + brick1->Height + ball->Height) &&
            (ball->Left + ball->Width >= brick1->Left - 3 && ball->Left + ball->Width <= brick1->Left + 3) &&
            brick1->Visible == true)
            {
                        ballX = -ballX;
            }

        //odbicie od góry
        else if ((ball->Left >= brick1->Left - ball->Width && ball->Left + ball->Width <= brick1->Left + brick1->Width + ball->Width) &&
                 (ball->Top + ball->Height >= brick1->Top - 3 && ball->Top + ball->Height <= brick1->Top + 3) &&
                 brick1->Visible == true)
                {
                        ballY = -ballY;
                }

        //odbicie z prawej strony
        else if ((ball->Top >= brick1->Top - ball->Height && ball->Top + ball->Height <= brick1->Top + brick1->Height + ball->Height) &&
                 (ball->Left >= brick1->Left + brick1->Width - 3 && ball->Left <= brick1->Left + brick1->Width + 3) &&
                 brick1->Visible == true)
                 {
                        ballX = -ballX;
                 }

        //odbicie od do³u
        else if ((ball->Left >= brick1->Left - ball->Width && ball->Left + ball->Width <= brick1->Left + brick1->Width + ball->Width) &&
                 (ball->Top >= brick1->Top + brick1->Height - 3 && ball->Top <= brick1->Top + brick1->Height + 3) &&
                 brick1->Visible == true)
                 {
                        ballY = -ballY;
                 }

        // odbicie brick2
        //odbicie z lewej strony
        if ((ball->Top >= brick2->Top - ball->Height && ball->Top + ball->Height <= brick2->Top + brick2->Height + ball->Height) &&
            (ball->Left + ball->Width >= brick2->Left - 3 && ball->Left + ball->Width <= brick2->Left + 3) &&
            brick2->Visible == true)
            {
                        ballX = -ballX;
            }

        //odbicie od góry
        else if ((ball->Left >= brick2->Left - ball->Width && ball->Left + ball->Width <= brick2->Left + brick2->Width + ball->Width) &&
                 (ball->Top + ball->Height >= brick2->Top - 3 && ball->Top + ball->Height <= brick2->Top + 3) &&
                 brick2->Visible == true)
                {
                        ballY = -ballY;
                }

        //odbicie z prawej strony
        else if ((ball->Top >= brick2->Top - ball->Height && ball->Top + ball->Height <= brick2->Top + brick2->Height + ball->Height) &&
                 (ball->Left >= brick2->Left + brick2->Width - 3 && ball->Left <= brick2->Left + brick2->Width + 3) &&
                 brick2->Visible == true)
                 {
                        ballX = -ballX;
                 }

        //odbicie od do³u
        else if ((ball->Left >= brick2->Left - ball->Width && ball->Left + ball->Width <= brick2->Left + brick2->Width + ball->Width) &&
                 (ball->Top >= brick2->Top + brick2->Height - 3 && ball->Top <= brick2->Top + brick2->Height + 3) &&
                 brick2->Visible == true)
                 {
                        ballY = -ballY;
                 }


}

//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonContinueGameClick(TObject *Sender)
{
        if (servingPlayer == "playerLeft")
        {
                ballX = 4;
                ballY = 4;
        }
        else
        {
                ballX = -4;
                ballY = -4;
        }

        ballMovement->Enabled = true;
        gameTimer->Enabled = true;
		
        numberOfBallBounced = 0;
        playerLeftNumberOfBouncingInTheMiddle = 0;
        playerRightNumberOfBouncingInTheMiddle = 0;
        gameDurationInSeconds = 0;
		
        whoPoint->Visible = false;
        result->Visible = false;
        bounceCounter->Visible = false;
        ButtonContinueGame->Visible = false;
        gameDuration->Visible = false;
		
        ball->Visible = true;
        ball->Top = table->Height / 2;
        ball->Left = table->Width / 2;

        table->Width = Form1->Width - 14;
        table->Height = Form1->Height - 42;
        paddle1->Left = 50;
        paddle2->Left = table->Width - 70;
        ball->Top = table->Height / 2;
        ball->Left = table->Width / 2;

        starYellowLeft->Visible = false;
        starYellowRight->Visible = false;;
		
        brick1->Visible = false;
        brick2->Visible = false;
}
//---------------------------------------------------------------------------

