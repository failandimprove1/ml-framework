# Basic Usage

This is an example on how to load your desired data file and seperate the rows in to vectors / matrices
```c++
#include "tools.hpp"
#include "types.hpp"
#include "math.hpp"

int main(int argc, char** argv)
{
	matrix_t data = load_csv("data.csv");
	vector_t y = extract_y_values(data);

	vector_t indexes = {0,2,3};
	matrix_t x = get_from_index(data, indexes);

	pretty_print_matrix(x);
}
```


# Basic Math

This is an example on how to transpose your matrices and find the dot product of your matrices.
```c++
#include "tools.hpp"
#include "types.hpp"
#include "math.hpp"

int main(int argc, char** argv)
{
	matrix_t some_data;
	matrix_t some_other_data;

	// ensure that the dimension of the dot product are valid
	// potentially you can transpose the matrices to make them valid dimensions with.
	// transpose_matrix(some_data);
	matrix_t aggregated_result_data = dot_product(some_data, some_other_data);

	pretty_print_matrix(aggregated_result_data);
	// SEE MORE IN DOT_PRODUCT DEFINITION / COMMENT
}
```

# Basic Data Cleaning

This is an example on how to clean, manipulate and split datasets.
```c++
#include "tools.hpp"
#include "types.hpp"
#include "math.hpp"

int main(int argc, char** argv)
{
	matrix_t some_data;
	vector_t some_data_but_only_first_index = extract_y_values(some_data);

	vector_t indexes = {1,2,3};
	matrix_t data_but_only_some_indexes = get_from_index(some_data, indexes);
	pretty_print_matrix(data_but_only_some_indexes);

	// data but only some indexes transposed
	transpose_matrix(data_but_only_some_indexes);

	pretty_print_matrix(aggregated_result_data);

	
	vector_t sample_observation = some_data[0];
	vector_t softmax_of_observation = softmax(sample_observation);

	matrix_t test_set = data_but_only_some_indexes;
	matrix_t validation_data = split_matrix(test_data);

}
```
