#include "tools.hpp"
#include "types.hpp"
#include "math.hpp"
#include <vector>

int main()
{

	matrix_t matrix, new_matrix, matrix2;
	vector_t vec, vec2, modes;

	vec.push_back(2.f);
	vec.push_back(3.f);
	vec.push_back(3.f);
	vec.push_back(8.f);
	vec.push_back(8.f);
	vec.push_back(6.f);
	vec.push_back(6.f);
	vec.push_back(6.f);
	vec.push_back(8.f);
	vec.push_back(8.f);
	vec.push_back(8.f);
	vec.push_back(8.f);
	vec.push_back(8.f);
	vec.push_back(8.f);

	vec2.push_back(2.f);
	vec2.push_back(8.f);
	vec2.push_back(0.3f);

	modes = mode(vec);	
	for (int i = 0; i < modes.size(); i++) std::cout << modes[i] << std::endl;

}
