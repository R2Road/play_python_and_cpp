#include "pch.h"
#include "r2_RootMenu.h"

#include <conio.h>
#include <sstream>

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"

#include "test/python_basic_test.h"

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
			ret->AddChild( '1', lua_state_test::Basic::GetInstance() );

			ret->AddLineFeed();


			ret->AddSplit();


			ret->AddChild(
				32
				, []()->const char* { return "All"; }
				, []()->eTestResult
				{
					int input = 0;
					bool process = true;
					while( process )
					{
						input = _getch();
						system( "cls" );

						switch( input )
						{
						case '5':
							//step::OpenLibs();
							break;

						case 27: // ESC
							process = false;
							break;
						}

						std::cout << r2::linefeed << "Press Any Key" << r2::linefeed;
						_getch();
						system( "cls" );
					}

					return eTestResult::RunTest;
				}
			);


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