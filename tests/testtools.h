void assert(bool isEqual);
extern char * FUNCTION_NAME;
typedef struct test_stats test_stats_t;
struct test_stats {
	int passed;
	int failed;
};
extern test_stats_t test_stats;
