#include "testtools.hpp"

Test::Test() {
	this->results = new Result();
};

void Test::is_equal(bool condition, string error_msg = "")
{
	if (condition) this->results->add_success();
	else {
		cout << error_msg << endl;
		this->results->add_fail();
	}
};

string Test::format_synapsis(int runs, int fails, int successes)
{
	string color_prefix;
	if (fails) color_prefix = "\033[1;31m"; // red
	else color_prefix = "\033[1;32m";		// green
	return color_prefix + "failed runs: " + to_string(fails) +
		", total runs: " + to_string(runs) +
		", successful runs " + to_string(successes) + "\033[m";
};

void Test::conclude()
{
	int return_code = 0;
	int runs = this->results->get_all_runs();
	int fails = this->results->get_fails();
	int successes = this->results->get_successes();

	string synapsis_message = this->format_synapsis(runs, fails, successes);
	cout << synapsis_message << endl;

	if (fails) return_code = 1;
	exit(return_code);
};

// pre- or suffix this with a identification of the test that was run
// ie: produce_error_message() + "| dot product"
// or: "| dot product" + produce_error_message()
string Test::produce_error_message(int expected, int got)
{
	return "expected: " + to_string(expected) + " got: " + to_string(got);
}

// pre- or suffix this with a identification of the test that was run
// ie: produce_error_message() + "| dot product"
// or: "| dot product" + produce_error_message()
string Test::produce_error_message(float expected, float got)
{
	return "expected: " + to_string(expected) + " got: " + to_string(got);
}

string Test::produce_error_message(matrix_t expected, matrix_t got)
{
	string expected_string = pretty_format_matrix_to_string(expected);
	string got_string = pretty_format_matrix_to_string(got);
	return "expected: \n" + expected_string + "got: \n" + got_string;
}

string Test::produce_error_message(vector_t expected, vector_t got)
{
	matrix_t expected_matrix = {expected};
	matrix_t got_matrix = {got};

	return produce_error_message(expected_matrix, got_matrix);
}
