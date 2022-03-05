#include "pch.h"
#include "python_basic_test.h"

#include "base/r2_eTestResult.h"

//
// # ref
// https://python.flowdas.com/c-api/init.html#c.Py_SetPath
//

namespace python_basic_test
{
	r2::iItem::TitleFunc Initialize_And_Finalize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Python Initialize And Finalize";
		};
	}
	r2::iItem::DoFunc Initialize_And_Finalize::GetDoFunction()
	{
		return []()->r2::eTestResult
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

			return r2::eTestResult::RunTest;
		};
	}



	r2::iItem::TitleFunc PythonInfo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Python Info";
		};
	}
	r2::iItem::DoFunc PythonInfo::GetDoFunction()
	{
		return []()->r2::eTestResult
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

			return r2::eTestResult::RunTest;
		};
	}



	r2::iItem::TitleFunc PythonPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Python Path";
		};
	}
	r2::iItem::DoFunc PythonPath::GetDoFunction()
	{
		return []()->r2::eTestResult
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

			return r2::eTestResult::RunTest;
		};
	}
}
