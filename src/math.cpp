#include "math.hpp"

std::vector<float> elementwise_multiplication(std::vector<float> vector1, std::vector<float> vector2)
{
    std::vector<float> return_vector;
    for (int i = 0; i < vector1.size(); i++)
    {
        return_vector.push_back(vector1[i] * vector2[i]);
    }
    return return_vector;
}