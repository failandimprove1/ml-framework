#include "math.hpp"

std::vector<float> elementwise_multiplication(std::vector<float> vector1, std::vector<float> vector2)
{
    std::vector<float> return_vector;
    if(vector1.size() != vector2.size())
    {
        return return_vector;
    }

    for (int i = 0; i < vector1.size(); i++)
    {
        return_vector.push_back(vector1[i] * vector2[i]);
    }

    return return_vector;
}

//https://en.wikipedia.org/wiki/Dot_product
float dot_product(std::vector<float> vector1, std::vector<float> vector2)
{
    
    float return_value = 0;
    if(vector1.size() != vector2.size())
    {
        return return_value;
    }

    for (int i = 0; i < vector1.size(); i++)
    {
        return_value += vector1[i] * vector2[i];
    }
    return return_value;
}
float median(std::vector<float> vector1)
{
    if (vector1.size() % 2 == 0)
    {
        
    }
}