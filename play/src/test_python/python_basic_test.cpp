﻿#include "pch.h"
#include "python_basic_test.h"

#include "r2cm/r2cm_eTestEndAction.h"

//
// # ref
// https://python.flowdas.com/c-api/init.html#c.Py_SetPath
//

namespace python_basic_test
{
	r2cm::iItem::TitleFuncT Initialize_And_Finalize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Python Initialize And Finalize";
		};
	}
	r2cm::iItem::DoFuncT Initialize_And_Finalize::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				//
				// Python Initialize
				//
				Py_Initialize();

				std::cout << r2::tab << "+ Python Initialize" << r2::linefeed2;
				std::cout << r2::tab2 << "Py_Initialize();" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Check" << r2::linefeed2;
				std::cout << r2::tab2 << "Py_IsInitialized();" << r2::linefeed;
				std::cout << r2::tab3 << "- " << ( Py_IsInitialized() ? "True" : "False" ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				//
				// Python Finalize
				//
				Py_Finalize();

				std::cout << r2::tab << "+ Python Finalize" << r2::linefeed2;
				std::cout << r2::tab2 << "Py_Finalize();" << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Check" << r2::linefeed2;
				std::cout << r2::tab2 << "Py_IsInitialized();" << r2::linefeed;
				std::cout << r2::tab3 << "- " << ( Py_IsInitialized() ? "True" : "False" ) << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT PythonInfo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Python Info";
		};
	}
	r2cm::iItem::DoFuncT PythonInfo::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			//
			// Python Initialize
			//
			{
				Py_Initialize();
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Version : ";
				std::wcout << Py_GetVersion();

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Platform : ";
				std::wcout << Py_GetPlatform();

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Compiler : ";
				std::wcout << Py_GetCompiler();

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Build Info : ";
				std::wcout << Py_GetBuildInfo();

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Program Name : ";
				std::wcout << Py_GetProgramName();

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Program Full Path" << r2::linefeed2;

				std::cout << r2::tab2;

				std::wcout << Py_GetProgramFullPath();

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Python Home" << r2::linefeed2;

				std::cout << r2::tab2;

				std::wcout << ( nullptr != Py_GetPythonHome() ? Py_GetPythonHome() : L"null" );

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Copyright" << r2::linefeed;

				std::wcout << Py_GetCopyright();

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			//
			// Python Finalize
			//
			{
				Py_Finalize();
			}

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT PythonPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Python Path";
		};
	}
	r2cm::iItem::DoFuncT PythonPath::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			//
			// Python Initialize
			//
			{
				Py_Initialize();
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ Path" << r2::linefeed2;

				std::wcout << Py_GetPath();

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			//
			// Python Finalize
			//
			{
				Py_Finalize();
			}

			return r2cm::eTestEndAction::Pause;
		};
	}
}
