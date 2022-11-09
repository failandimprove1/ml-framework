#include "tools.hpp"

fstream create_file(string filename)
{
    fstream FileObj;
    FileObj.open(filename, ios::out);
    if (!FileObj)
        cout << "Error opening file";
    else
        FileObj.close();
    return FileObj;
}

void read_file(string filename)
{
    string filestreambuffer;
    fstream filestream;
    if (!filestream.is_open())
    {
        filestream.open(filename, ios::in);
    }
    while (getline(filestream, filestreambuffer))
        cout << filestreambuffer << endl;

    filestream.close();
}

vector_t parse_csv_row(string streambuffer)
{
	vector_t row;
	string value;
	for (auto x : streambuffer)
	{
		// checks for comma to push
		// to vector and reset string buffer
		if(x == ',')
		{
			row.push_back(stof(value));
			value = "";
		}

		else
			value += x;
	}

	// pushes the trailing information as the one above
	// only pushes upon encountering comma which leads this
	// to not push the last string buffer, aka.
	// the last value in the row
	row.push_back(stof(value));
	return row;
}

vector_t get_from_index(matrix_t data, int index)
{
	vector_t y;

	if(index > data[0].size())
	{
		cerr << "ERROR: get_from_index index parameter out of range" << endl;
		return y;
	}

	for (int i = 0; i < data.size(); i++)
		y.push_back(data[i][index]);

	return y;
}

matrix_t get_from_index(matrix_t data, vector_t index)
{
	matrix_t x;

	for (float i : index)
		x.push_back(get_from_index(data, (int)i));

	return x;
}


// extracts every value of a certain index
// index_of_y being the index that gets mapped to the return vector
vector_t extract_y_values(matrix_t data, int index_of_y)
{
	return get_from_index(data, index_of_y);
}

matrix_t load_csv(const string filename, bool skip_first_line)
{
    string filestreambuffer;
    fstream filestream;
	matrix_t data;

    if (!filestream.is_open())
        filestream.open(filename, ios::in);

    while (getline(filestream, filestreambuffer))
		if (skip_first_line) skip_first_line = false;
		else data.push_back(parse_csv_row(filestreambuffer));

    filestream.close();

	return data;

}

void pretty_print_matrix(matrix_t x)
{
	int amount_of_rows = x[0].size();
	int amount_of_columns = x.size();
	for (int i = 0; i < amount_of_rows; i++)
		for (int j = 0; j < amount_of_columns; j++)
			(j == amount_of_columns-1) ? cout << x[j][i] << endl: cout << x[j][i] << ", ";
}

void print_matrix(matrix_t x, bool pretty_formating)
{
	if (pretty_formating) pretty_print_matrix(x);
	else {
		for (int i = 0; i < x.size(); i++)
			for (int j = 0; j < x[i].size(); j++)
				cout << x[i][j] << endl;
	}
}
