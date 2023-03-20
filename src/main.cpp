#include "tools.hpp"
#include "types.hpp"
#include "math.hpp"


#define EPOCH 100
#define LEARNING_RATE 0.01f



matrix_t fit(matrix_t x_data, vector_t y_data, float learning_rate)
{

	vector_t weights = {100, 100};

	for (int e = 0; e < EPOCH; e++)
		{
			
		}
}

int main(int argc, char** argv)
{
	matrix_t data = load_csv("housing_cleaned.csv", true);
	vector_t price = extract_y_values(data, 0);
	vector_t indexes = {1,2};
	matrix_t x_data = get_from_index(data, indexes);

	
	transpose_matrix(x_data);

	float learning_rate = LEARNING_RATE;
	// CHECK IF LESS THAN OR GREATER THAN
	// EVERY EPOCH ADD / SUBTRACT LEARNING RATE
	//

	float prediction;
	vector_t x_train;

	fit(x_data, price, learning_rate);
	
}