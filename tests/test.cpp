#include <iostream>
#include "result.h"
#include "testtools.h"
#include "../src/tools.h"
#include <cassert>
Test test = Test();

void test_create_file()
{
	fstream file = create_file("test_file.txt");
	test.is_equal(!file.is_open(), "Expecting file to not be open after creating file");
	test.is_equal(!!file, "Expecting file to exist");
};

int main()
{
	test_create_file();
	exit(test.conclude());
};

