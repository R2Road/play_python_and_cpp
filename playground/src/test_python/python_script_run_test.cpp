#include "pch.h"
#include "python_script_run_test.h"

#include "base/r2_eTestResult.h"
#include "helper/r2_PythonInstance.h"

//
// # ref
// https://www.codeproject.com/Articles/820116/Embedding-Python-program-in-a-C-Cplusplus-code
//

namespace python_script_run_test
{
	r2cm::iItem::TitleFunc SimpleString::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "SimpleString";
		};
	}
	r2cm::iItem::DoFunc SimpleString::GetDoFunction()
	{
		return []()->r2cm::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			//
			// Python Initialize And Finalize
			//
			r2::PythonInstance python_instance;

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

			return r2cm::eTestResult::RunTest;
		};
	}



	r2cm::iItem::TitleFunc SimpleFile_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "SimpleFile 1";
		};
	}
	r2cm::iItem::DoFunc SimpleFile_1::GetDoFunction()
	{
		return []()->r2cm::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			//
			// Python Initialize And Finalize
			//
			r2::PythonInstance python_instance;

			std::cout << r2::split;

			{
				const char* script_path_string = "resources/pyscript/python_script_run_test__simplestring_1.py";

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "const char* script_path_string = " << script_path_string << ";" << r2::linefeed;
				std::cout << r2::linefeed2;

				FILE* fp = nullptr;
				fopen_s( &fp, script_path_string, "r" );

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "FILE* fp = nullptr;" << r2::linefeed;
				std::cout << r2::tab2 << "fopen_s( &fp, script_path_string, \"r\" );" << r2::linefeed;
				std::cout << r2::linefeed2;

				if( fp )
				{
					std::cout << r2::tab << "+ Run" << r2::linefeed2;
					std::cout << r2::tab2 << "PyRun_SimpleFile( fp, script_path_string );" << r2::linefeed2;

					std::cout << r2::tab2 << "> ";
					PyRun_SimpleFile( fp, script_path_string );
					std::cout << r2::linefeed2;
				}
				else
				{
					std::cout << r2::tab << "Failed : File Open" << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2cm::eTestResult::RunTest;
		};
	}



	r2cm::iItem::TitleFunc SimpleFile_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "SimpleFile 2";
		};
	}
	r2cm::iItem::DoFunc SimpleFile_2::GetDoFunction()
	{
		return []()->r2cm::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			//
			// Python Initialize And Finalize
			//
			r2::PythonInstance python_instance;

			std::cout << r2::split;

			{
				const char* script_path_string = "resources/pyscript/python_script_run_test__simplestring_2.py";

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "const char* script_path_string = " << script_path_string << ";" << r2::linefeed;
				std::cout << r2::linefeed2;

				PyObject *fo = Py_BuildValue( "s", script_path_string );
				FILE* fp = _Py_fopen_obj( fo, "r" );

				std::cout << r2::tab << "+ Declaration" << r2::linefeed2;
				std::cout << r2::tab2 << "PyObject *fo = Py_BuildValue( \"s\", script_path_string );" << r2::linefeed;
				std::cout << r2::tab2 << "FILE* fp = _Py_fopen_obj( fo, \"r\" );" << r2::linefeed;
				std::cout << r2::linefeed2;

				if( fp )
				{
					std::cout << r2::tab << "+ Run" << r2::linefeed2;
					std::cout << r2::tab2 << "PyRun_SimpleFile( fp, script_path_string );" << r2::linefeed2;

					std::cout << r2::tab2 << "> ";
					PyRun_SimpleFile( fp, script_path_string );
					std::cout << r2::linefeed2;
				}
				else
				{
					std::cout << r2::tab << "Failed : File Open" << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2cm::eTestResult::RunTest;
		};
	}
}
