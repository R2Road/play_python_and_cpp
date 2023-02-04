#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace python_basic_test
{
	class Initialize_And_Finalize : public r2cm::iItem, public r2::SingleTon<Initialize_And_Finalize>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class PythonInfo : public r2cm::iItem, public r2::SingleTon<PythonInfo>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class PythonPath : public r2cm::iItem, public r2::SingleTon<PythonPath>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}
