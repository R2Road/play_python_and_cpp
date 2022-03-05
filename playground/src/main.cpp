#include "pch.h"
#include <Windows.h>

//#if defined( DEBUG ) || defined( _DEBUG )
//	#include <vld.h>
//#endif

#include "base/r2cm_Director.h"
#include "test_python/RootMenu.h"
#include "helper/r2_PythonHelper.h"

int main()
{
	//
	// Environment : Title
	//
	SetConsoleTitle( TEXT( "python_and_cpp_playground" ) );

	//
	// Environment : Size
	//
	system( "mode con lines=60 cols=120" );

	//
	// Environment : Position
	//
	{
		HWND hWnd = GetConsoleWindow();
		RECT rectClient;
		GetClientRect( hWnd, &rectClient );
		MoveWindow( hWnd, 0, 0, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE );
	}

	//
	// Environment : Python
	//
	{
		r2::PythonHelper::PathSetup();
	}

	//
	// Setup
	//
	r2cm::Director director;
	director.Setup( RootMenu::Create( director ) );

	//
	// Process
	//
	director.Run();

	return 0;
}