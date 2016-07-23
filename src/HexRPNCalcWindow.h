/*
	
	HexRPNCalcWindow.h
	
	Copyright © 1998 Fumihiko Shibata, All Rights Reserved.
	
*/

#ifndef HEX_RPNCALC_WIN_H
#define HEX_RPNCALC_WIN_H

#include <Window.h>
#include <Button.h>
#include "HexRPNCalcView.h"

#define BUTTON0_MSG 'PRE0'
#define BUTTONT_MSG 'PRET'
#define BUTTONP_MSG 'PREP'
#define BUTTON1_MSG 'PRE1'
#define BUTTON2_MSG 'PRE2'
#define BUTTON3_MSG 'PRE3'
#define BUTTONM_MSG 'PREM'
#define BUTTON4_MSG 'PRE4'
#define BUTTON5_MSG 'PRE5'
#define BUTTON6_MSG 'PRE6'
#define BUTTONN_MSG 'PREN'
#define BUTTON7_MSG 'PRE7'
#define BUTTON8_MSG 'PRE8'
#define BUTTON9_MSG 'PRE9'
#define BUTTONX_MSG 'PREX'
#define BUTTONA_MSG 'PREA'
#define BUTTONB_MSG 'PREB'
#define BUTTONC_MSG 'PREC'
#define BUTTONO_MSG 'PREO'
#define BUTTOND_MSG 'PRED'
#define BUTTONE_MSG 'PREE'
#define BUTTONF_MSG 'PREF'
#define BUTTONI_MSG 'PREI'

class Stack
{
	public:
		Stack() {sp = 0;};
		void push(int32 pushing);
		void pop(int32* popping);
	private:
		int32 stacks[100];
		int sp;
};

class HexRPNCalcWindow : public BWindow
{
	public:
						HexRPNCalcWindow();
		virtual bool	QuitRequested();
		virtual void	MessageReceived(BMessage* message);

	private:
		HexRPNCalcView*			fView;
		Stack*			fStack;

		int32 xRegister;
		int32 yRegister;
		
		int	clrflg;
		int stackflg;
		
		void	updateX(int32 pushed);
};

#endif