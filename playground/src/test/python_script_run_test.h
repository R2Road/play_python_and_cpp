#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace python_script_run_test
{
	class SimpleString : public r2::iTest, public r2::SingleTon<SimpleString>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class SimpleFile_1 : public r2::iTest, public r2::SingleTon<SimpleFile_1>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class SimpleFile_2 : public r2::iTest, public r2::SingleTon<SimpleFile_2>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}
