#pragma once
#include <iostream>
#include "result.hpp"

using namespace std;

class Test {
	public:
		Test();
		~Test() {};
		Result * results;
		void is_equal(bool condition, string error_msg);
		string format_synapsis(int, int, int);
		void conclude();
		//TODO make templates for this or smth idk
		string produce_error_message(int expected, int got);
		string produce_error_message(float expected, float got);

};
