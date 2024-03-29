#include "math.hpp"


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


void transpose_matrix(matrix_t &matrix)
{
	matrix_t transposed_matrix;
	vector_t transposed_vector;

	int max_y = matrix[0].size();
	int max_x = matrix.size();
	for (int x = 0; x < max_y; x++)
	{
		for (int y = 0; y < max_x; y ++)
		{
			float val = matrix[y][x];
			transposed_vector.push_back(val);
		}

		transposed_matrix.push_back(transposed_vector);
		transposed_vector.clear();
	}
	matrix = transposed_matrix;
	return;
}

// https://en.wikipedia.org/wiki/Dot_product
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

// takes two matrices with (m,n) dimensions and produces the dot product of them
// NOTE: input matrices follow the laws of mathematics where n1 == m2
// You should transpose the matrices before calling this function if dimensions are incompatible
//
// example:
// (3,3) x (2,3) == error
// (3,3) x (3,2) == OK
//
matrix_t dot_product(matrix_t matrix1, matrix_t matrix2)
{
	vector_t result_vec;
	matrix_t return_matrix;

	transpose_matrix(matrix2);
	int m1,m2,n1,n2;
	m1 = matrix1.size(); //columns
	m2 = matrix2.size(); //columns
	n1 = matrix1[0].size(); //rows
	n2 = matrix2[0].size(); //rows
	if (n1 == m2)
	{
		for (int i = 0; i < m1; i++)
		{
			for (int j = 0; j < m2; j++)
				result_vec.push_back(dot_product(matrix1[i], matrix2[j]));

			return_matrix.push_back(result_vec);
			result_vec.clear();
		}
	}
	else
		cerr << "ERROR: invalid dimensions for dot product" << endl << "size:"<<m1<<","<<n1<<" incompatible with size:"<<m2<<","<<n2<<endl;
	return return_matrix;
}

matrix_t dot_product(matrix_t matrix1, vector_t vector1)
{
    matrix_t m2 = {vector1};
    return dot_product(matrix1, m2);
}

matrix_t dot_product(vector_t vector1, matrix_t matrix1 )
{
    return dot_product(matrix1, vector1);
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

vector_t mode(vector_t vec)
{
	std::unordered_map<float, int> hashmap;

	int highest_value = 1;
    vector_t highest_value_keys;

	for( float value_in_vector : vec )
	    hashmap[value_in_vector] += 1;


	for (float value_in_vector : vec)
	{
		int amount_of_occurences = hashmap[value_in_vector];
		if(amount_of_occurences > highest_value)
            highest_value = amount_of_occurences;

	}
    for (float value_in_vector : vec)
    {
        if (hashmap[value_in_vector] == highest_value)
        {
            hashmap[value_in_vector] = 0;
            highest_value_keys.push_back(value_in_vector);
        }
    }
    sort(highest_value_keys.begin(), highest_value_keys.end());
	return highest_value_keys;
}

float sigmoid(float x)
{
    return 1/1+exp(-x);
}
float tanh(float x)
{
    return exp(x) - exp(-x)/exp(x) + exp(-x);
}

float ReLU(float x)
{
    if (x < 0)
    {
        return 0;
    }
    
    return x;
}

float mse(vector_t y, vector_t yhat)
{
    vector_t delta = subtract_vectors(y, yhat);
    vector_t squared_vector = elementwise_multiplication(delta, delta);
    return (sum(squared_vector) / y.size());
}

float rmse(vector_t y, vector_t yhat)
{
    return sqrt(mse(y, yhat));
}

//Subtracts the elements of the first vector with the elements of the second vector elementwise
vector_t subtract_vectors(vector_t vector1, vector_t vector2)
{
    assert (vector1.size() == vector2.size());
    vector_t new_vector;
    for (int i = 0; i < vector1.size(); i++)
        new_vector.push_back(vector1[i] - vector2[i]);
    return new_vector;
}

//Adds two vectors of the same length together elementwise
vector_t add_vectors(vector_t vector1, vector_t vector2)
{
    assert (vector1.size() == vector2.size());
    vector_t new_vector;
    for (int i = 0; i < vector1.size(); i++)
        new_vector.push_back(vector1[i] + vector2[i]);
    return new_vector;
}

vector_t divide_vector(vector_t vector, float divider)
{
    vector_t new_vector;
    for (auto value : vector)
    {
        new_vector.push_back(value / divider);
    }
    return new_vector;
}

float sum(vector_t vector)
{
    float sum;
    for (int i = 0; i < vector.size(); i++) 
        sum += vector[i];
    return sum;
}

float sum(matrix_t matrix)
{
    float vecsum;
    for (auto vector : matrix)
    {
        vecsum += sum(vector);
    }
    return vecsum;
}
vector_t getpredictions(matrix_t x_data, vector_t weights)
{
	vector_t predictions;
	for (int i = 0; i < x_data.size(); i++)
    {
        vector_t x_train = x_data[i];
        predictions.push_back( dot_product(x_train, weights));
    }
    return predictions;
}

float max_value(vector_t input)
{
    float max = -INFINITY;
    for (int i = 0; i < input.size(); i++)
        max = std::max(max, input[i]);

    return max;
}

vector_t softmax(vector_t input)
{
    vector_t output;
    float sum = 0;
    float m =  max_value(input);
    for (int i = 0; i < input.size(); i++)
        sum += exp(input[i] - m);

    float constant = m + log(sum);
    for (int i = 0; i < input.size(); i++)
        output.push_back(exp(input[i] - constant));

    return output;
}

matrix_t split_matrix(matrix_t* input, float percent)
{
    matrix_t validation_matrix;

    if (percent < 0.01f)
    {
        cerr << "The input percent at which the matrix splits has to be larger than or equal to 1%" << endl;
        return validation_matrix;
    }
    else if (percent > 1)
    {
        cerr << "The input percent at which the matrix splits has to be smaller than 100% (less than 1)" << endl;
        return validation_matrix;
    }
    int rows = input->size();
    int split_point = (int) (rows * percent);
    int remaining_elements = rows - split_point;

    for (int i = 0; i < remaining_elements; i++)
    {
        validation_matrix.push_back(input->at(split_point + i));
    }
    for (int i = 0; i < remaining_elements; i++)
    {
        input->pop_back();
    }
    return validation_matrix;
}