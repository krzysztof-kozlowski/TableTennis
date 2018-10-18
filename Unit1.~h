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
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *table;
        TImage *paddle1;
        TImage *paddle2;
        TTimer *paddle1up;
        TTimer *paddle1down;
        TTimer *paddle2up;
        TTimer *paddle2down;
        TImage *ball;
        TLabel *whoPoint;
        TLabel *result;
        TButton *ButtonContinueGame;
        TLabel *bounceCounter;
        TLabel *gameDuration;
        TTimer *gameTimer;
        TImage *starYellowLeft;
        TImage *starYellowRight;
        TImage *brick1;
        TTimer *ballMovement;
        TImage *brick2;
        TButton *ButtonNewGame;
        void __fastcall paddle1upTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall paddle1downTimer(TObject *Sender);
        void __fastcall paddle2upTimer(TObject *Sender);
        void __fastcall paddle2downTimer(TObject *Sender);
        void __fastcall gameTimerTimer(TObject *Sender);
        void __fastcall ballMovementTimer(TObject *Sender);
        void __fastcall ButtonContinueGameClick(TObject *Sender);
        void __fastcall ButtonNewGameClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
