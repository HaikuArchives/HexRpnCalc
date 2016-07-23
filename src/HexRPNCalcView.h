/*
	
	HexRPNCalcView.h
	
	Copyright © 1998 Fumihiko Shibata, All Rights Reserved.
	
*/

#ifndef HEX_RPNCALC_VIEW_H
#define HEX_RPNCALC_VIEW_H

#include <View.h>

class HexRPNCalcView : public BView {

public:
				HexRPNCalcView(BRect frame, char *name); 
virtual	void	AttachedToWindow();
virtual	void	Draw(BRect rect);

		void	displayRegister(int32 dReg);

private:
		int32	dRegister;
};

#endif