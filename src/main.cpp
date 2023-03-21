#include "tools.hpp"
#include "types.hpp"
#include "math.hpp"


#define EPOCH 100
#define LEARNING_RATE 30
#define LOSS_FUNCTION float (*loss_function)(vector_t y,vector_t yhat)



matrix_t fit(matrix_t x_data, vector_t y_data, float learning_rate, LOSS_FUNCTION)
{
	matrix_t data_transposed = x_data;
	transpose_matrix(data_transposed);
	vector_t weights = {0.2, 0.1};
	vector_t predictions;
	for (int e = 0; e < EPOCH; e++)
	{
		
		predictions = getpredictions(x_data, weights);
		float biggest_data = max_value(y_data);
		vector_t normalised_predictions = divide_vector(predictions, biggest_data);
		vector_t normalised_y_data = divide_vector(y_data, biggest_data);
		//cout << x_data.size() << " " << predictions.size() << endl;
		float current_cost = loss_function(normalised_y_data, predictions);
		//cout << y_data.size() << " " << predictions.size() << endl;
 		vector_t error = subtract_vectors(normalised_y_data, predictions);
		/*for (auto errors : error)
		{
			cout << errors << endl;
		}*/
		float weight_derivative = (-2/x_data.size()) * sum(dot_product(data_transposed, error));
		
		for(int i = 0; i < weights.size(); i++)
		{
			cout << weights[i] - (learning_rate * weight_derivative) << endl;
			weights[i] = weights[i] - (learning_rate * weight_derivative);
		}
		cout << weight_derivative << endl;	
		cout << current_cost << " " << weights[0] << " " << weights[1] << endl;
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

	fit(x_data, price, learning_rate, mse);
	
}