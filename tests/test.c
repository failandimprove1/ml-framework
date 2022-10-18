#include "../src/tools.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct test_stats test_stats_t;
struct test_stats {
	int passed;
	int failed;
};

test_stats_t test_stats = {
	0,
	0
};

void assert(bool isEqual)
{
	if (isEqual)
	{
		test_stats.passed ++;
	}
	else test_stats.failed ++;
}

void test_format_content_for_file()
{
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
