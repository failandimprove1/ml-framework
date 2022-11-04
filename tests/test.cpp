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
		test.is_equal(test_field_result[i] == expected_field_results[i] , "expecting elementwise multiplication to produce " + to_string(expected_field_results[i]) + 
		" but got " + to_string(test_field_result[i]));
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

	test.is_equal(test_result == expected_test_result, "expected the dot product to produce " + to_string(expected_test_result) + ", got " + to_string(test_result));

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

	test.is_equal(test_median == expected_test_median, "expected median function to produce " + to_string(expected_test_median) + ", got " + to_string(test_median));

	//test #2
	test_field.clear();
	test_field.push_back(60.f);
	test_field.push_back(1.f);
	test_field.push_back(100.f);
	test_field.push_back(-50.f);
	
	test_median = median(test_field);
	expected_test_median = 30.5f;

	test.is_equal(test_median == expected_test_median, "expected median function to produce " + to_string(expected_test_median) + ", got " + to_string(test_median));

	//test #3
	test_field.clear();

	test_median = median(test_field);
	expected_test_median = 0;

	test.is_equal(test_median == expected_test_median, "expected median function to produce " + to_string(expected_test_median) + ", got " + to_string(test_median));

	//test #4
	test_field.clear();
	test_field.push_back(30.f);
	test_field.push_back(5.f);

	test_median = median(test_field);
	expected_test_median = 17.5f;

	test.is_equal(test_median == expected_test_median, "expected median function to produce " + to_string(expected_test_median) + ", got " + to_string(test_median));

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
	test.is_equal(test_mean == expected_test_mean, "expected mean function to produce " + to_string(expected_test_mean)+ ", got" + to_string(test_mean));
}

int main()
{
	test_create_file();
	test_vector_elementwise_multiplication();
	test_vector_dot_product();
	test_median();
	test_mean();

	test.conclude();
};

