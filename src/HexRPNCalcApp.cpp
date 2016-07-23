/*
	
	HexRPNCalcApp.cpp
	
	Copyright © 1998 Fumihiko Shibata, All Rights Reserved.
	
*/

#include "HexRPNCalcApp.h"
#include "HexRPNCalcWindow.h"

main()
{
	HexRPNCalcApp* app = new HexRPNCalcApp();
	app->Run();
	
	exit(0);
}

HexRPNCalcApp::HexRPNCalcApp():BApplication("application/x-vnd.fmhk.hrcalc")
{
}

void HexRPNCalcApp::ReadyToRun()
{
	fWindow = new HexRPNCalcWindow();
	fWindow->Show();
}