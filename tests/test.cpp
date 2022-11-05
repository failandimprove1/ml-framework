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

	test.is_equal(to_be_transposed_matrix != transposed_matrix, "expecting matrices to NOT be equal when NOT transposed");
	transpose_matrix(transposed_matrix);

	test.is_equal(to_be_transposed_matrix == transposed_matrix, "expecting matrices to be the equal when transposed");
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


	test.is_equal(result_matrix == expected_matrix, "expecting matrix dot produce correct matrix");
}

int main()
{
	test_create_file();

	// vector math
	test_vector_elementwise_multiplication();
	test_vector_dot_product();

	// statistics math
	test_median();
	test_mean();

	// matrix math
	test_transpose_matrix();
	test_matrix_dot_product();

	// concludes test
	test.conclude();
};

