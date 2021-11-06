#include "pch.h"
#include "r2_PythonInstance.h"

#include <filesystem>
#include <string>

namespace r2
{
	PythonInstance::PythonInstance()
	{
		Py_Initialize();
	}

	PythonInstance::~PythonInstance()
	{
		Py_Finalize();
	}
}
