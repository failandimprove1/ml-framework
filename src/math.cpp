#include "math.hpp"
#include "types.hpp"

vector_t elementwise_multiplication(vector_t vector1, vector_t vector2)
{
    vector_t return_vector;
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
float dot_product(vector_t vector1, vector_t vector2)
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
