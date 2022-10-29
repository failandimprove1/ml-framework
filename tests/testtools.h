#pragma once
#include <iostream>
#include "result.h"
class Test {
	public:
		Test();
		~Test() {};
		Result * results;
		void is_equal(bool condition, std::string error_msg);
		std::string format_synapsis(int runs, int fails, int successes);
		void conclude();

};
