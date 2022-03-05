#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace python_basic_test
{
	class Initialize_And_Finalize : public r2::iTest, public r2::SingleTon<Initialize_And_Finalize>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class PythonInfo : public r2::iTest, public r2::SingleTon<PythonInfo>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class PythonPath : public r2::iTest, public r2::SingleTon<PythonPath>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}
