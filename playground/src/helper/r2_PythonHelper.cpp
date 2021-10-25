#include "pch.h"
#include "r2_PythonHelper.h"

#include <filesystem>
#include <string>

namespace r2
{
	void PythonHelper::PathSetup()
	{
		const std::filesystem::path pivot_path = std::filesystem::current_path() / "python64";
		//std::cout << pivot_path << r2::linefeed;

		const std::filesystem::path dll_path = pivot_path / "DLLs";
		//std::cout << dll_path << r2::linefeed;

		const std::filesystem::path lib_path = pivot_path / "Lib";
		//std::cout << lib_path << r2::linefeed;

		std::wstring paths;
		paths += dll_path.c_str();
		paths += L";";
		paths += lib_path.c_str();
		paths += L";";

		Py_SetPath( paths.c_str() );
		//std::wcout << Py_GetPath();
	}
}
