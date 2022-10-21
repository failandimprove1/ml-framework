#include "../src/tools.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "testtools.h"

void TEST_TEMPLATE_FUNCTION()
{
	// re-define the function name variable to reflect in the error message in case it fails the test.
	FUNCTION_NAME = "TEST_TEMPLATE_FUNCTION";

	// call the function it is supposed to test.
	// and create a test case.
	int x = 2 + 6;

	// assert takes a boolean that handles the result of the operation.
	assert(x == 8);
	// assert(!x == 8);

	// with a real test make sure to add the function in the main function
}

void test_format_content_for_file()
{
	FUNCTION_NAME = "test_format_content_for_file";
	char content[30] = "test1234";
	char prev_content[30] = "test1234";
	format_content_for_file(content);
	char * suffix = ",";
	strcat(prev_content, suffix);
	int n = strcmp(prev_content, content);
	assert(!n);
}

int main()
{
	test_format_content_for_file();
	printf("%d passed!, %d failed!\n", test_stats.passed, test_stats.failed);
}
