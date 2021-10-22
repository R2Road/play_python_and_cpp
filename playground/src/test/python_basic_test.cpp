﻿#include "pch.h"
#include "python_basic_test.h"

#include "base/r2_eTestResult.h"

namespace lua_state_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Lua State";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			//lua_State* lua_state_obj = nullptr;

			//std::cout << r2::tab << "+ Variable" << r2::linefeed2;
			//std::cout << r2::tab2 << "lua_State* lua_state_obj = nullptr;" << r2::linefeed;

			//std::cout << r2::split;

			//{
			//	//
			//	// Make Lua State
			//	//
			//	lua_state_obj = luaL_newstate();

			//	std::cout << r2::tab << "+ Make lua_State" << r2::linefeed2;
			//	std::cout << r2::tab2 << "lua_state_obj = luaL_newstate();" << r2::linefeed;
			//}

			//std::cout << r2::split;

			//{
			//	//
			//	// Close Lua State
			//	//
			//	lua_close( lua_state_obj );

			//	std::cout << r2::tab << " + Close lua_State" << r2::linefeed2;
			//	std::cout << r2::tab2 << "lua_close( lua_state_obj );" << r2::linefeed;
			//}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}
