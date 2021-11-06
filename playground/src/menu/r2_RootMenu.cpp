#include "pch.h"
#include "r2_RootMenu.h"

#include <conio.h>
#include <sstream>

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"

#include "test/python_basic_test.h"
#include "test/python_script_run_test.h"

namespace r2
{
	MenuUp RootMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu(
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


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Exit"; }
				, []()->eTestResult { return eTestResult::Exit; }
			);
		}

		return ret;
	}
}