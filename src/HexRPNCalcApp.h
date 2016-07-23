/*
	
	HexRPNCalcApp.h
	
	Copyright © 1998 Fumihiko Shibata, All Rights Reserved.
	
*/

#ifndef HEX_RPNCALC_APP_H
#define HEX_RPNCALC_APP_H

#include <Application.h>

#include "HexRPNCalcWindow.h"

class HexRPNCalcApp: public BApplication
{
	public:
						HexRPNCalcApp();
		virtual void	ReadyToRun();
	private:
		HexRPNCalcWindow*	fWindow;
};

#endif