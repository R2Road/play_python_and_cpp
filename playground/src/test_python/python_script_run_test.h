#pragma once

#include "base/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace python_script_run_test
{
	class SimpleString : public r2cm::iItem, public r2::SingleTon<SimpleString>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class SimpleFile_1 : public r2cm::iItem, public r2::SingleTon<SimpleFile_1>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class SimpleFile_2 : public r2cm::iItem, public r2::SingleTon<SimpleFile_2>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}
