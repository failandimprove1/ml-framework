#include "tools.hpp"
#include "types.hpp"
#include "math.hpp"

int main(int argc, char** argv)
{
	matrix_t data = load_csv("data.csv");
	vector_t y = extract_y_values(data);

	vector_t indexes = {0,2,3};
	matrix_t x = get_from_index(data, indexes);
	matrix_t t = {{2,2},{2,2},{2,2}};
	transpose_matrix(x);
	matrix_t r = dot_product(x, t);
	//pretty_print_matrix(x);
	transpose_matrix(r);
	pretty_print_matrix(r);
}
