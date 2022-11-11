#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "types.hpp"
using namespace std;
fstream create_file(string filename);
void read_file(string filename);
vector_t parse_csv_row(string streambuffer);
vector_t get_from_index(matrix_t data, int index);
matrix_t get_from_index(matrix_t data, vector_t index);
vector_t extract_y_values(matrix_t data, int index_of_y = 1);
matrix_t load_csv(const string filename, bool skip_first_line = true);
void print_matrix(matrix_t x, bool pretty_formating = false);
string pretty_format_matrix_to_string(matrix_t x);
void pretty_print_matrix(matrix_t x);
