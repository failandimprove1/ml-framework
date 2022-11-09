
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


