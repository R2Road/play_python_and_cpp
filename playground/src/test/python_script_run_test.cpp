#include "pch.h"
#include "python_script_run_test.h"

#include "base/r2_eTestResult.h"

//
// # ref
// https://www.codeproject.com/Articles/820116/Embedding-Python-program-in-a-C-Cplusplus-code
//

namespace python_script_run_test
{
	r2::iTest::TitleFunc SimpleString::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "SimpleString";
		};
	}
	r2::iTest::DoFunc SimpleString::GetDoFunction()
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
				const char* run_string = "print( \'Hello Python.\')";

				std::cout << r2::tab << "+ SimpleString" << r2::linefeed2;
				std::cout << r2::tab2 << "const char* run_string = " << run_string << ";" << r2::linefeed;
				std::cout << r2::tab2 << "PyRun_SimpleString( run_string );" << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << r2::tab3;
				std::cout << "- ";

				PyRun_SimpleString( run_string );
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
