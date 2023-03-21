#pragma once
#include <vector>
#include "types.hpp"
#include <algorithm>
#include <cmath>
#include <numeric>
#include <iostream>
#include <unordered_map>
#include <cassert>

vector_t elementwise_multiplication(vector_t, vector_t);
matrix_t elementwise_multiplication(matrix_t, matrix_t);
vector_t subtract_vectors(vector_t, vector_t);
vector_t add_vectors(vector_t, vector_t);
vector_t divide_vector(vector_t, float);
float max_value(vector_t);
float dot_product(vector_t, vector_t);
matrix_t dot_product(matrix_t, matrix_t);
matrix_t dot_product(matrix_t, vector_t);
matrix_t dot_product(vector_t, matrix_t);
float dot_product_return_total(matrix_t, matrix_t);
void transpose_matrix(matrix_t &matrix);
matrix_t split_matrix(matrix_t*, float);
float median(vector_t);
float mean(vector_t);
vector_t mode(vector_t);
float sigmoid(float);
float tanh(float);
float ReLU(float);
vector_t softmax(vector_t);
float mse(vector_t, vector_t);
float rmse(vector_t, vector_t);
float sum(vector_t);
float sum(matrix_t);
vector_t getpredictions(matrix_t, vector_t);
