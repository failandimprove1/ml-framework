#include "tools.hpp"
#include "types.hpp"
#include "math.hpp"
#include <vector>

int main()
{

	matrix_t matrix, new_matrix, matrix2;
	vector_t vec, vec2;

	vec.push_back(2.f);
	vec.push_back(3.f);
	vec.push_back(3.f);

	vec2.push_back(2.f);
	vec2.push_back(8.f);
	vec2.push_back(0.3f);

	matrix.push_back(vec);
	matrix.push_back(vec);
	matrix.push_back(vec2);

	matrix2.push_back(vec2);
	matrix2.push_back(vec);
	matrix2.push_back(vec);

	new_matrix = elementwise_multiplication(matrix2, matrix);

	for (vector_t vect : new_matrix)
		for (float v : vect)
			std::cout << v << std::endl;

	std::cout << "..." << std::endl;
	matrix_t victor = dot_product(matrix, matrix2);
	for (vector_t vect : victor)
		for (float v : vect)
			std::cout << v << std::endl;

}
