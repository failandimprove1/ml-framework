#include "tools.hpp"
#include <vector>

std::vector<float> vector_element_multiplication(std::vector<float> vector1, std::vector<float> vector2)
{
	std::vector<float> return_vector;
	for (int i = 0; i < vector1.size(); i ++)
	{
		return_vector.push_back(vector1[i] * vector2[i]);
	}
	return return_vector;
}


int main()
{
    //fstream file = create_file("coolfile");
    //read_file("coolfile.txt");

	std::vector<float> input_field;
	input_field.push_back(3.f);
	input_field.push_back(4.f);
	input_field.push_back(4.f);

	std::vector<float> input_field2;
	input_field2.push_back(3.f);
	input_field2.push_back(4.f);
	input_field2.push_back(4.f);

	std::vector<float> return_vector = vector_element_multiplication(input_field, input_field2);

	for (float number : return_vector)
	{
		std::cout << number << std::endl;
	}
}
