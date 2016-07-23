/*
	
	HexRPNCalcView.cpp
	
	Copyright © 1998 Fumihiko Shibata, All Rights Reserved.
	
*/

#include "HexRPNCalcView.h"
#include <stdio.h>

HexRPNCalcView::HexRPNCalcView(BRect rect, char *name)
	   	   : BView(rect, name, B_FOLLOW_ALL, B_WILL_DRAW)
{
	dRegister  = 0;
}

void HexRPNCalcView::AttachedToWindow()
{
	SetFont(be_fixed_font);
	SetFontSize(24);
	SetDrawingMode(B_OP_COPY);
}

void HexRPNCalcView::Draw(BRect rect)
{
	displayRegister(dRegister);
}

void HexRPNCalcView::displayRegister(int32 dReg)
{
	char display[18];

	dRegister = dReg;

	sprintf(display, "%08X", dReg);
	SetHighColor(200, 200, 200, 0);
	FillRect(BRect(2, 2, 148, 28));
	SetHighColor(20, 0, 128, 0);
	StrokeRect(BRect(0, 0, 150, 30));
	MovePenTo(BPoint(20, 22));
	DrawString(display);
}