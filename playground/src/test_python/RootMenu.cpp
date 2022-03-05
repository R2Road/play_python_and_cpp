#include "pch.h"
#include "RootMenu.h"

#include <conio.h>

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"

#include "python_basic_test.h"
#include "python_script_run_test.h"

r2cm::MenuUp RootMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle()
		, "> Add Some One"
	) );

	{
		ret->AddItem( '1', python_basic_test::Initialize_And_Finalize::GetInstance() );
		ret->AddItem( '2', python_basic_test::PythonInfo::GetInstance() );
		ret->AddItem( '3', python_basic_test::PythonPath::GetInstance() );


		ret->AddLineFeed();


		ret->AddItem( '4', python_script_run_test::SimpleString::GetInstance() );
		ret->AddItem( '5', python_script_run_test::SimpleFile_1::GetInstance() );
		ret->AddItem( '6', python_script_run_test::SimpleFile_2::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eTestEndAction { return r2cm::eTestEndAction::Exit; }
		);
	}

	return ret;
}