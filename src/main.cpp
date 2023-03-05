#include "tools.hpp"
#include "types.hpp"
#include "math.hpp"


#define EPOCH 100
#define LEARNING_RATE 0.05f

int main(int argc, char** argv)
{
	matrix_t data = load_csv("housing_cleaned.csv", true);
	vector_t price = extract_y_values(data, 0);
	vector_t indexes = {1,2};
	matrix_t x_data = get_from_index(data, indexes);

	vector_t weights = {10, 3.55};
	transpose_matrix(x_data);

	float learning_rate = 0.01f;
	// CHECK IF LESS THAN OR GREATER THAN
	// EVERY EPOCH ADD / SUBTRACT LEARNING RATE
	//

	float prediction;
	vector_t x_train;
	for (int e = 0; e < EPOCH; e++)
	{
		for (int i = 0; i < x_data.size(); i++)
		{
			vector_t x_train = x_data[i];
			float y = price[i];

			prediction = dot_product(x_train, weights);
			//cout << "prediction: "<< prediction << endl;
			//cout << "actual: "<< y << endl;
			//cout << "diff: "<< y - prediction <<endl;
			cout << "(perc:) " << (y - prediction)/ y << endl;
			//cout << "\n" << endl;
			if ((y - prediction) > 0 )
			{
				weights[0] = weights[0] + learning_rate;
				weights[1] = weights[1] + learning_rate;
			}
			else {
				weights[0] = weights[0] - learning_rate;
				weights[1] = weights[1] - learning_rate;
			}
		}
		cout << "weights: " << weights[0] <<" "<< weights[1] << weights[2] << endl;
	}
}
