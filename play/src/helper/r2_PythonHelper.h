#pragma once

// 다음 학습 때 참고할 자료 : https://www.codeproject.com/Articles/820116/Embedding-Python-program-in-a-C-Cplusplus-code

namespace r2
{
	class PythonHelper
	{
	private:
		PythonHelper() = delete;

	public:
		static void PathSetup();
	};
}
