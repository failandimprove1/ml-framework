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

char * FUNCTION_NAME;
void assert(bool isEqual)
{
	if (isEqual) test_stats.passed ++;
	else {
		test_stats.failed ++;
		printf("%s failed!\n", FUNCTION_NAME);
	}
}
