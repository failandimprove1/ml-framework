#include <iostream>
#include "result.h"
#include "testtools.h"
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
	std::vector<float> test_field1, test_field2;
	test_field1.push_back(1.f);
	test_field1.push_back(2.f);
	test_field1.push_back(3.f);

	test_field2.push_back(1.f);
	test_field2.push_back(2.f);
	test_field2.push_back(3.f);

	elementwise_multiplication(test_field1, test_field2)

	test.is_equal(!)
}

int main()
{
	test_create_file();
	exit(test.conclude());
};

