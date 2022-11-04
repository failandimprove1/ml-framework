#include "math.hpp"

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

float median(vector_t vector)
{
    int size = vector.size();

    std::sort(vector.begin(), vector.end());

    if (size == 0)
    {
        return 0;
    }
    else if (size % 2 == 0)
    {
        int i = (size / 2) - 1;
        return (vector[i] + vector[i+1]) / 2;
    }
    else
    {
        int i = (size + 1) / 2;
        return vector[i-1];
    }
}

float mean(vector_t vector)
{
    float vector_sum = 0;
    if (vector.size() != 0)
    {
        for (float element : vector) vector_sum += element;
        return vector_sum/vector.size();
    }
    return vector_sum;
}
