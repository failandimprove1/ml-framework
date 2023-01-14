#pragma once
#include <vector>
#include "types.hpp"
#include <algorithm>
#include <cmath>
#include <numeric>
#include <iostream>
#include <unordered_map>


matrix_t elementwise_multiplication(matrix_t, matrix_t);
float dot_product_return_total(matrix_t, matrix_t);
vector_t elementwise_multiplication(vector_t, vector_t);
matrix_t dot_product(matrix_t, matrix_t);
void transpose_matrix(matrix_t &matrix);
float dot_product(vector_t, vector_t);
float median(vector_t);
float mean(vector_t);
vector_t mode(vector_t);
float sigmoid(float);
float tanh(float);
vector_t softmax(vector_t);
matrix_t split_matrix(matrix_t*, float);
