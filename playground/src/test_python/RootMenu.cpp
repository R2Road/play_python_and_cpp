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
		ret->AddChild( '1', python_basic_test::Initialize_And_Finalize::GetInstance() );
		ret->AddChild( '2', python_basic_test::PythonInfo::GetInstance() );
		ret->AddChild( '3', python_basic_test::PythonPath::GetInstance() );


		ret->AddLineFeed();


		ret->AddChild( '4', python_script_run_test::SimpleString::GetInstance() );
		ret->AddChild( '5', python_script_run_test::SimpleFile_1::GetInstance() );
		ret->AddChild( '6', python_script_run_test::SimpleFile_2::GetInstance() );


		ret->AddSplit();


		ret->AddChild(
			27
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eTestEndAction { return r2cm::eTestEndAction::Exit; }
		);
	}

	return ret;
}