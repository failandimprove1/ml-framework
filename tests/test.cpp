#include <iostream>
#include "result.hpp"
#include "testtools.hpp"
#include "../src/tools.hpp"
#include "../src/types.hpp"
#include "../src/math.hpp"
#include <cassert>

Test test = Test();

void test_create_file()
{
	fstream file = create_file("test_file.txt");
	test.is_equal(!file.is_open(), "Expecting file to not be open after creating file");
	test.is_equal(!!file, "Expecting file to exist");
};

void test_vector_elementwise_multiplication()
{
	vector_t test_field1, test_field2, test_field_result, expected_field_results;

	test_field1.push_back(1.5f);
	test_field1.push_back(2.f);
	test_field1.push_back(3.f);

	test_field2.push_back(-2.f);
	test_field2.push_back(3.f);
	test_field2.push_back(5.f);

	test_field_result = elementwise_multiplication(test_field1, test_field2);
	expected_field_results.push_back(-3.f);
	expected_field_results.push_back(6.f);
	expected_field_results.push_back(15.f);

	test.is_equal(test_field_result.size() != 0, "expects function to return a non-zero size vector if the sizes of input vectors are equal");

	for (int i = 0; i < test_field1.size(); i++)
	{
		float x = test_field_result[i];
		float y = expected_field_results[i];
		test.is_equal(x == y, "elementwise_multiplication| " + test.produce_error_message(y, x));
	}

	test_field1.push_back(10.f);
	test_field_result = elementwise_multiplication(test_field1, test_field2);

	test.is_equal(test_field_result.size() == 0, "expects function to return a zero size vector if the sizes of input vectors are not equal");
}

void test_vector_dot_product()
{
	vector_t test_field1, test_field2;
	float test_result, expected_test_result;

	test_field1.push_back(1.5f);
	test_field1.push_back(2.f);
	test_field1.push_back(3.f);

	test_field2.push_back(-2.f);
	test_field2.push_back(3.f);
	test_field2.push_back(5.f);

	test_result = dot_product(test_field1, test_field2);
	expected_test_result = 18.f;

	test.is_equal(test_result == expected_test_result, "dot product | " + test.produce_error_message(expected_test_result, test_result));

	test_field1.push_back(5.f);
	test_result = dot_product(test_field1, test_field2);

	test.is_equal(test_result == 0, "expected function to return zero when the vectors dimensions are different");

}

void test_median()
{
	vector_t test_field;
	float test_median;
	float expected_test_median;

	//test #1
	test_field.push_back(2.f);
	test_field.push_back(3.f);
	test_field.push_back(4.f);

	test_median = median(test_field);
	expected_test_median = 3.f;

	test.is_equal(test_median == expected_test_median, "test median | " + test.produce_error_message(expected_test_median, test_median));

	//test #2
	test_field.clear();
	test_field.push_back(60.f);
	test_field.push_back(1.f);
	test_field.push_back(100.f);
	test_field.push_back(-50.f);
	test_median = median(test_field);
	expected_test_median = 30.5f;

	test.is_equal(test_median == expected_test_median, "test median | " + test.produce_error_message(expected_test_median, test_median));

	//test #3
	test_field.clear();

	test_median = median(test_field);
	expected_test_median = 0;

	test.is_equal(test_median == expected_test_median, "test median | " + test.produce_error_message(expected_test_median, test_median));

	//test #4
	test_field.clear();
	test_field.push_back(30.f);
	test_field.push_back(5.f);

	test_median = median(test_field);
	expected_test_median = 17.5f;

	test.is_equal(test_median == expected_test_median, "test median | " + test.produce_error_message(expected_test_median, test_median));

}

void test_mean()
{
	float test_mean;
	float expected_test_mean;
	vector_t test_field;
	test_field.push_back(60.f);
	test_field.push_back(1.f);
	test_field.push_back(100.5f);
	test_field.push_back(-50.f);

	test_mean = mean(test_field);
	expected_test_mean = 27.875f;
	test.is_equal(test_mean == expected_test_mean, "test mean | " + test.produce_error_message(expected_test_mean, test_mean));
}

void test_transpose_matrix()
{
	matrix_t transposed_matrix;
	matrix_t to_be_transposed_matrix;

	to_be_transposed_matrix = {{4.f, 2.f}, {3.f,2.f}};
	transposed_matrix = {{4.f, 3.f}, {2.f,2.f}};

	test.is_equal(to_be_transposed_matrix != transposed_matrix, test.produce_error_message(to_be_transposed_matrix, transposed_matrix));

	transpose_matrix(transposed_matrix);

	test.is_equal(to_be_transposed_matrix == transposed_matrix, test.produce_error_message(to_be_transposed_matrix, transposed_matrix));
}

void test_matrix_dot_product()
{
	matrix_t test_matrix, another_test_matrix, result_matrix;
	matrix_t expected_matrix;

	test_matrix = {
		{1.f, 2.f, 3.f,},
		{4.f, 5.f, 6.f,},
		{7.f, 8.f, 9.f},
	};
	another_test_matrix = {
		{2.f, 8.f, 0.3f,},
		{2.f, 3.f, 3.f,},
		{2.f, 3.f, 3.f},
	};
	expected_matrix = {
		{12.f, 23.f, 15.3f,},
		{30.f, 65.f, 34.2f,},
		{48.f, 107.f, 53.1f},
	};

	result_matrix = dot_product(test_matrix, another_test_matrix);
	test.is_equal(result_matrix == expected_matrix, test.produce_error_message(expected_matrix, result_matrix));
}

void test_advanced_matrix_dot_product()
{
	matrix_t test_matrix, another_test_matrix, result_matrix;
	matrix_t expected_matrix;
	test_matrix = {
		{1.f, 2.f, 3.f,},
		{4.f, 5.f, 6.f,},
		{7.f, 8.f, 9.f},
	};
	another_test_matrix = {
		{2.f, 8.f, 0.3f},
		{2.f, 3.f, 3.f}
	};
	expected_matrix = {
		{18.9f, 17.f},
		{49.8f, 41.f},
		{80.7f, 65.f},
	};

	// this needs to be transposed because you cannot take a
	// (3,3) sized matrix and mulitply it with a (2,3)
	transpose_matrix(another_test_matrix);

	result_matrix = dot_product(test_matrix, another_test_matrix);

	int m, n;
	m = result_matrix.size();
	n = result_matrix[0].size();
	test.is_equal(2 == n, "advanced dot product | " + test.produce_error_message(2, n));
	test.is_equal(3 == m, "advanced dot product | " + test.produce_error_message(3, m));
	test.is_equal(result_matrix == expected_matrix,"advanced dot product | " + test.produce_error_message(expected_matrix, result_matrix));

}

void test_mode()
{
	vector_t test_vector = {2,1,5,5,7,10,-5,10,0};
	vector_t test_mode = mode(test_vector);
	vector_t expected_test_mode = {5.f, 10.f};

	for (int i = 0; i < expected_test_mode.size(); i++)
		test.is_equal(test_mode[i] == expected_test_mode[i], "mode function | " + test.produce_error_message(expected_test_mode[i], test_mode[i]));

	test_vector = {1,2,3,4,5};
	test_mode = mode(test_vector);
	expected_test_mode = test_vector;

	for (int i = 0; i < expected_test_mode.size(); i++)
		test.is_equal(test_mode[i] == expected_test_mode[i], "mode function | " + test.produce_error_message(expected_test_mode[i], test_mode[i]));

	test_vector = {-100,5,-24,1000,-1,2001,-5,-24,-50,1,-100,-1,-24,90,5,-100,5,1};

	test_mode = mode(test_vector);
	expected_test_mode = {-100, -24, 5};

	for (int i = 0; i < expected_test_mode.size(); i++)
		test.is_equal(test_mode[i] == expected_test_mode[i], "mode function | " + test.produce_error_message(expected_test_mode[i], test_mode[i]));

}

void test_softmax()
{
	vector_t test_vector = {5,5,5,5};
	vector_t test_softmax = softmax(test_vector);
	vector_t expected_softmax{0.25, 0.25, 0.25, 0.25};

	for (int i = 0; i < expected_softmax.size(); i++)
		test.is_equal(test_softmax[i] == expected_softmax[i], "softmax function | " + test.produce_error_message(expected_softmax[i], test_softmax[i]));

}

void test_split_matrix()
{
	matrix_t test_matrix;
	matrix_t expected_validation_matrix;
	matrix_t expected_test_matrix;
	matrix_t validation_matrix;

	test_matrix = {
		{2,3,10},
		{10,-10,5},
		{5,1000,10},
		{1.5f, 10.1f, 6},
		{6.4f, 91, 1},
		{8.8f, 1.1f, 100},
		{1.5f, 60, 61},
		{1.5f, 10.1f, 6},
		{4, 5, 0},
		{1.5f, 10.1f, 6}
		};
		expected_test_matrix = {
		{2,3,10},
		{10,-10,5},
		{5,1000,10},
		{1.5f, 10.1f, 6},
		{6.4f, 91, 1},
		};
	expected_validation_matrix = {
		{8.8f, 1.1f, 100},
		{1.5f, 60, 61},
		{1.5f, 10.1f, 6},
		{4, 5, 0},
		{1.5f, 10.1f, 6}
		};


	validation_matrix = split_matrix(&test_matrix, 0.5f);
	test.is_equal(validation_matrix == expected_validation_matrix, "split matrix | " + test.produce_error_message(expected_validation_matrix, validation_matrix));
	test.is_equal(test_matrix == expected_test_matrix, "split matrix | " + test.produce_error_message(expected_test_matrix, test_matrix));

	test_matrix = {
		{2,3,10},
		{10,-10,5},
		{5,1000,10},
		{1.5f, 10.1f, 6},
		{6.4f, 91, 1},
		{8.8f, 1.1f, 100},
		{1.5f, 60, 61},
		{1.5f, 10.1f, 6},
		{4, 5, 0},
		{1.5f, 10.1f, 6}
		};
		expected_test_matrix = {
		{2,3,10},
		{10,-10,5},
		{5,1000,10},
		{1.5f, 10.1f, 6}
		};
	expected_validation_matrix = {
		{6.4f, 91, 1},
		{8.8f, 1.1f, 100},
		{1.5f, 60, 61},
		{1.5f, 10.1f, 6},
		{4, 5, 0},
		{1.5f, 10.1f, 6}
		};

	
	validation_matrix = split_matrix(&test_matrix, 0.4f);
	test.is_equal(validation_matrix == expected_validation_matrix, "split matrix | " + test.produce_error_message(expected_validation_matrix, validation_matrix));
	test.is_equal(test_matrix == expected_test_matrix, "split matrix | " + test.produce_error_message(expected_test_matrix, test_matrix));
}

void test_sum()
{
	vector_t test_vector = {23,23,4,22,42,4,24};
	float expected_sum_vector = 142;
	
	matrix_t test_matrix =  {
		{10.5f, 4, 30.1f},
		{2, 3.3f, 100},
		{1.5f, 10.1f, 6},
		{23,23,24},
		{2,42,4}
	};

	float test_sum_matrix = sum(test_matrix);
	float expected_sum_matrix = 285.5f;

	float test_sum_vector = sum(test_vector);


	test.is_equal(test_sum_vector == expected_sum_vector, "vector sum | " + test.produce_error_message(expected_sum_vector, test_sum_vector));
	test.is_equal(test_sum_matrix == expected_sum_matrix, "matrix sum | " + test.produce_error_message(expected_sum_matrix, test_sum_matrix));
}

void test_add_vectors()
{
	vector_t test_vector1 = {5, 9, 154, 1, 9, 7, 3, 2, 1};
	vector_t test_vector2 = {10, 12, 600, 21, 1, 5, 6, 3, 329};
	vector_t expected_vector = {15, 21, 754, 22, 10, 12, 9, 5, 330};
	vector_t added_vector = add_vectors(test_vector1, test_vector2);

	test.is_equal(added_vector == expected_vector, "vector addition | " + test.produce_error_message(expected_vector, added_vector));
}

void test_subtract_vectors()
{
	vector_t test_vector1 = {10, 12, 600, 21, 9, 7, 6, 3, 329};
	vector_t test_vector2 = {5, 9, 154, 1, 1, 5, 3, 2, 1.3f};
	vector_t expected_vector1 = {5, 3, 446, 20, 8, 2, 3, 1, 327.7f};
	vector_t subtracted_vector1 = subtract_vectors(test_vector1, test_vector2);

	test.is_equal(subtracted_vector1 == expected_vector1, "vector subtraction | " + test.produce_error_message(expected_vector1, subtracted_vector1));

	vector_t test_vector3 = {10, 12, 600, 21, 9, 7, 6, 3.3f, 329.3f};
	vector_t test_vector4 = {25, 9, 601, 1, 1, 5, 3, 5.2f, 1.3f};
	vector_t expected_vector2 = {-15, 3, -1, 20, 8, 2, 3, -2.1f, 327.7f};
	vector_t subtracted_vector2 = subtract_vectors(test_vector3, test_vector4);

	test.is_equal(subtracted_vector1 == expected_vector1, "vector subtraction | " + test.produce_error_message(expected_vector1, subtracted_vector1));
}

/*void test_mse()
{
	vector_t test_vector1 = {10, 12, 600, 21, 9, 7, 6, 3, 329};
	vector_t test_vector2 = {5, 9, 154, 1, 1, 5, 3, 2, 1.3f};
	mse(test_vector1, test_vector2)
}*/

int main()
{
	test_create_file();

	// vector math
	test_vector_elementwise_multiplication();
	test_vector_dot_product();
	test_add_vectors();
	test_subtract_vectors();


	// statistics math
	test_median();
	test_mean();
	test_mode();

	// advanced statistics math
	test_softmax();

	// math
	test_sum();

	// matrix math
	test_transpose_matrix();
	test_matrix_dot_product();

	// advanced matrix math
	test_advanced_matrix_dot_product();

	// data handling/cleaning
	test_split_matrix();

	// concludes test
	test.conclude();
};

