/*
	
	HexRPNCalcWindow.cpp
	
	Copyright © 1998 Fumihiko Shibata, All Rights Reserved.
	
*/

#include <Application.h>
#include "HexRPNCalcWindow.h"
#include "HexRPNCalcView.h"

const BRect kWindowFrame (100,100,270,360);
const BRect kDisplayFrame (10, 10, 160, 40);
const BRect kButton0Frame (10, 225, 40, 245);
const BRect kButtonTFrame (50, 225, 120, 245);
const BRect kButtonPFrame (130, 225, 160, 245);
const BRect kButton1Frame (10, 190, 40, 210);
const BRect kButton2Frame (50, 190, 80, 210);
const BRect kButton3Frame (90, 190, 120, 210);
const BRect kButtonMFrame (130, 190, 160, 210);
const BRect kButton4Frame (10, 155, 40, 175);
const BRect kButton5Frame (50, 155, 80, 175);
const BRect kButton6Frame (90, 155, 120, 175);
const BRect kButtonNFrame (130, 155, 160, 175);
const BRect kButton7Frame (10, 120, 40, 140);
const BRect kButton8Frame (50, 120, 80, 140);
const BRect kButton9Frame (90, 120, 120, 140);
const BRect kButtonXFrame (130, 120, 160, 140);
const BRect kButtonAFrame (10, 85, 40, 105);
const BRect kButtonBFrame (50, 85, 80, 105);
const BRect kButtonCFrame (90, 85, 120, 105);
const BRect kButtonOFrame (130, 85, 160, 105);
const BRect kButtonDFrame (10, 50, 40, 70);
const BRect kButtonEFrame (50, 50, 80, 70);
const BRect kButtonFFrame (90, 50, 120, 70);
const BRect kButtonIFrame (130, 50, 160, 70);

const char* kWindowName = "HexCalc";

void
Stack::push(int32 pushing)
{
	if (sp < 99)
		stacks[sp++] = pushing;
}

void Stack::pop(int32* popping)
{
	if (sp)
		*popping = stacks[--sp];
}

HexRPNCalcWindow::HexRPNCalcWindow() :
	BWindow(kWindowFrame, kWindowName, B_TITLED_WINDOW,
			B_NOT_RESIZABLE | B_NOT_ZOOMABLE)
{
	fView = new HexRPNCalcView(kDisplayFrame, "Display");
	AddChild(fView);

	AddChild(new BButton(kButton0Frame, "0", "0",
					new BMessage(BUTTON0_MSG)));
	AddChild(new BButton(kButtonTFrame, "ENTER", "ENTER",
					new BMessage(BUTTONT_MSG)));
	AddChild(new BButton(kButtonPFrame, "+", "+",
					new BMessage(BUTTONP_MSG)));
	AddChild(new BButton(kButton1Frame, "1", "1",
					new BMessage(BUTTON1_MSG)));
	AddChild(new BButton(kButton2Frame, "2", "2",
					new BMessage(BUTTON2_MSG)));
	AddChild(new BButton(kButton3Frame, "3", "3",
					new BMessage(BUTTON3_MSG)));
	AddChild(new BButton(kButtonMFrame, "-", "_",
					new BMessage(BUTTONM_MSG)));
	AddChild(new BButton(kButton4Frame, "4", "4",
					new BMessage(BUTTON4_MSG)));
	AddChild(new BButton(kButton5Frame, "5", "5",
					new BMessage(BUTTON5_MSG)));
	AddChild(new BButton(kButton6Frame, "6", "6",
					new BMessage(BUTTON6_MSG)));
	AddChild(new BButton(kButtonNFrame, "NOT", "NOT",
					new BMessage(BUTTONN_MSG)));
	AddChild(new BButton(kButton7Frame, "7", "7",
					new BMessage(BUTTON7_MSG)));
	AddChild(new BButton(kButton8Frame, "8", "8",
					new BMessage(BUTTON8_MSG)));
	AddChild(new BButton(kButton9Frame, "9", "9",
					new BMessage(BUTTON9_MSG)));
	AddChild(new BButton(kButtonXFrame, "XOR", "XOR",
					new BMessage(BUTTONX_MSG)));
	AddChild(new BButton(kButtonAFrame, "A", "A",
					new BMessage(BUTTONA_MSG)));
	AddChild(new BButton(kButtonBFrame, "B", "B",
					new BMessage(BUTTONB_MSG)));
	AddChild(new BButton(kButtonCFrame, "C", "C",
					new BMessage(BUTTONC_MSG)));
	AddChild(new BButton(kButtonOFrame, "OR", "OR",
					new BMessage(BUTTONO_MSG)));
	AddChild(new BButton(kButtonDFrame, "D", "D",
					new BMessage(BUTTOND_MSG)));
	AddChild(new BButton(kButtonEFrame, "E", "E",
					new BMessage(BUTTONE_MSG)));
	AddChild(new BButton(kButtonFFrame, "F", "F",
					new BMessage(BUTTONF_MSG)));
	AddChild(new BButton(kButtonIFrame, "AND", "AND",
					new BMessage(BUTTONI_MSG)));
	
	fStack = new Stack();
	stackflg = 0;
	clrflg = 0xFF;
	xRegister = 0;
	yRegister = 0;
}

bool HexRPNCalcWindow::QuitRequested()
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return BWindow::QuitRequested();
}

void HexRPNCalcWindow::MessageReceived(BMessage* message)
{
	switch(message->what)
	{
		case BUTTON0_MSG:
			updateX(0);
		break;
		case BUTTON1_MSG:
			updateX(1);
		break;
		case BUTTON2_MSG:
			updateX(2);
		break;
		case BUTTON3_MSG:
			updateX(3);
		break;
		case BUTTON4_MSG:
			updateX(4);
		break;
		case BUTTON5_MSG:
			updateX(5);
		break;
		case BUTTON6_MSG:
			updateX(6);
		break;
		case BUTTON7_MSG:
			updateX(7);
		break;
		case BUTTON8_MSG:
			updateX(8);
		break;
		case BUTTON9_MSG:
			updateX(9);
		break;
		case BUTTONA_MSG:
			updateX(0x0A);
		break;
		case BUTTONB_MSG:
			updateX(0x0B);
		break;
		case BUTTONC_MSG:
			updateX(0x0C);
		break;
		case BUTTOND_MSG:
			updateX(0x0D);
		break;
		case BUTTONE_MSG:
			updateX(0x0E);
		break;
		case BUTTONF_MSG:
			updateX(0x0F);
		break;
		case BUTTONT_MSG:
			if (stackflg++ > 1)
				fStack->push(yRegister);
			yRegister = xRegister;
			clrflg = 0x80;
		break;
		case BUTTONP_MSG:
			xRegister += yRegister;
			if (stackflg > 1)
				fStack->pop(&yRegister);
			stackflg--;
			clrflg = -1;
			fView->displayRegister(xRegister);
		break;
		case BUTTONM_MSG:
			xRegister = yRegister - xRegister;
			if (stackflg > 1)
				fStack->pop(&yRegister);
			clrflg = -1;
			fView->displayRegister(xRegister);
		break;
		case BUTTONI_MSG:
			xRegister &= yRegister;
			if (stackflg > 1)
				fStack->pop(&yRegister);
			clrflg = -1;
			fView->displayRegister(xRegister);
		break;
		case BUTTONO_MSG:
			xRegister |= yRegister;
			if (stackflg > 1)
				fStack->pop(&yRegister);
			clrflg = -1;
			fView->displayRegister(xRegister);
		break;
		case BUTTONX_MSG:
			xRegister ^= yRegister;
			if (stackflg > 1)
				fStack->pop(&yRegister);
			clrflg = -1;
			fView->displayRegister(xRegister);
		break;
		case BUTTONN_MSG:
			xRegister = ~xRegister;
			clrflg = -1;
			fView->displayRegister(xRegister);
		break;
		default:
			BWindow::MessageReceived(message);
	};
}

void HexRPNCalcWindow::updateX(int32 pushed)
{
		if (clrflg) {
			if (clrflg != 0x80) {
				if (stackflg++ > 1)
					fStack->push(yRegister);
				yRegister = xRegister;
				};
			clrflg = 0;
			xRegister = 0;
			};
		xRegister = xRegister * 16 + pushed;
		fView->displayRegister(xRegister);
}
