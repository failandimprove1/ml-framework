#include "math.hpp"
#include <numeric>
#include <iostream>

vector_t elementwise_multiplication(vector_t vector1, vector_t vector2)
{
    vector_t return_vector;
    if(vector1.size() != vector2.size()) return return_vector;

    for (int i = 0; i < vector1.size(); i++) return_vector.push_back(vector1[i] * vector2[i]);

    return return_vector;
}

// needs to take matrices with identical sizes for now.
// should make a function to saturate the sizes of matrices.
matrix_t elementwise_multiplication(matrix_t matrix1, matrix_t matrix2)
{
    matrix_t return_matrix;
	size_t m1_size = matrix1.size();
	size_t m2_size = matrix2.size();
    if(m2_size != m1_size) return return_matrix;

	return_matrix.resize(matrix1.size());

    for (int i = 0; i < matrix1.size(); i++)
		for (int v = 0; v < matrix1[i].size(); v++)
		{
			float value = matrix1[i][v] * matrix2[i][v];
			return_matrix[i].push_back(value);
		}

    return return_matrix;
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


matrix_t transpose_matrix(matrix_t &matrix)
{
	matrix_t transposed_matrix;
	vector_t transposed_vector;

	for (int x = 0; x < matrix.size(); x++)
	{
		for (int y = 0; y < matrix[x].size(); y ++)
		{
			float val = matrix[y][x];
			transposed_vector.push_back(val);
		}

		transposed_matrix.push_back(transposed_vector);
		transposed_vector.clear();
	}
	matrix = transposed_matrix;
	return transposed_matrix;
}

matrix_t dot_product(matrix_t matrix1, matrix_t matrix2)
{
	vector_t result_vec, transposed_vector;
	matrix_t return_matrix;
	transpose_matrix(matrix2);

	for (int i = 0; i < matrix1.size(); i++)
	{
		for (int j = 0; j < matrix1[i].size(); j++)
			result_vec.push_back(dot_product(matrix1[j], matrix2[i]));

		return_matrix.push_back(result_vec);
		result_vec.clear();
		transposed_vector.clear();
	}
	return transpose_matrix(return_matrix);
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
