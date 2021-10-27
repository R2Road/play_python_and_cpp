#include "pch.h"
#include "python_basic_test.h"

#include "base/r2_eTestResult.h"

namespace python_basic_test
{
	r2::iTest::TitleFunc Initialize_And_Finalize::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Python Initialize And Finalize";
		};
	}
	r2::iTest::DoFunc Initialize_And_Finalize::GetDoFunction()
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



	r2::iTest::TitleFunc PythonVersion::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Python Version";
		};
	}
	r2::iTest::DoFunc PythonVersion::GetDoFunction()
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
				std::cout << r2::tab << "+ Version" << r2::linefeed2;

				std::cout << r2::tab2;
				std::wcout << Py_GetVersion();

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



	r2::iTest::TitleFunc PythonPath::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Python Path";
		};
	}
	r2::iTest::DoFunc PythonPath::GetDoFunction()
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
				std::cout << r2::tab2 << "const char* run_string = ( " << run_string << " );" << r2::linefeed;
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
