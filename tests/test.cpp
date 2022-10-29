#include <iostream>
#include "result.hpp"
#include "testtools.hpp"
#include "../src/tools.hpp"
#include "../src/math.hpp"
#include <cassert>
Test test = Test();

void test_create_file()
{
	fstream file = create_file("test_file.txt");
	test.is_equal(!file.is_open(), "Expecting file to not be open after creating file");
	test.is_equal(!!file, "Expecting file to exist");
};

void test_vector_elementwise_multiplication()
{
	std::vector<float> test_field1, test_field2, test_field_result, expected_field_results;
	test_field1.push_back(1.f);
	test_field1.push_back(2.f);
	test_field1.push_back(3.f);

	test_field2.push_back(-2.f);
	test_field2.push_back(3.f);
	test_field2.push_back(5.f);

	test_field_result = elementwise_multiplication(test_field1, test_field2);
	expected_field_results.push_back(-2.f);
	expected_field_results.push_back(6.f);
	expected_field_results.push_back(15.f);

	test.is_equal(test_field_result.size() != 0, "expects function to return a non-zero size vector if the sizes of input vectors are equal");

	for (int i = 0; i < test_field1.size(); i++)
	{
		test.is_equal(test_field_result[i] == expected_field_results[i] , "expecting elementwise multiplication to produce " + to_string(expected_field_results[i]) + 
		" but got " + to_string(test_field_result[i]));
	}

	test_field1.push_back(10.f);
	test_field_result = elementwise_multiplication(test_field1, test_field2);

	test.is_equal(test_field_result.size() == 0, "expects function to return a zero size vector if the sizes of input vectors are not equal");
}

int main()
{
	test_create_file();
	test_vector_elementwise_multiplication();

	test.conclude();
};

