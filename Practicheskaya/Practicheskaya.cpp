#include <iostream>
//Task 1
bool validate(int mass, int distance) {
	if (mass <= 0 || distance <= 0) {
		return false;
	}
	return true;
}

int cost_calculation(int mass, int distance) {
	int cost{};
	if (mass <= 2) {
		cost = 150;
	}
	else {
		cost = 250;
	}
	if (distance > 50) {
		cost += 100;
	}
	return cost;
}

//Task 2

bool validate(int c) {
	if (c <= 0) {
		return false;
	}
	return true;
}

int dividers(int c) {
	int count{};
	std::cout << "Dividers: ";
	for (int i = 1; i <= c; ++i) {
		if (c % i == 0) {
			std::cout << i << ' ';
			count++;
		}
	}
	std::cout << '\n';
	return count;

}

int calculating_sum(int c) {
	int sum{};
	for (int i = 1; i <= c; ++i) {
		if (c % i == 0) {
			sum += i;
		}
	}
	return sum;

}

//Task 3

void analyze(int n, int* square, int* cube) {
	int num = n;
	*square = num * num;
	*cube = num * num * num;
}

//task 4

int* memory_allocation(int size) {
	return new int[size];
}

void read(int* arr, int size) {
	for (int i{}; i < size; ++i) {
		std::cin >> arr[i];
	}
}

void print(int* arr, int size) {
	for (int* ptr = arr; ptr != arr + size; ptr++) {
		std::cout << *ptr << ' ';
	}
	std::cout << '\n';
}

void memory_deallocation(int*& arr) {

	delete[] arr;
	arr = nullptr;
}

int count_elem_bigger_then_neighbour(int* arr, int size) {
	int count{};
	for (int i{1}; i < size - 1; ++i) {
		if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) {
			count++;
		}
	}
	return count;
}

void left_shift(int* arr, int size) {
	int first = arr[0];
	for (int i{}; i < size -1; ++i) {
		arr[i] = arr[i + 1];
	}
	arr[size - 1] = first;
}

//Task 5
int** memory_allocation(int rows, int cols) {
	int** matrix = new int* [rows];

	for (int i{}; i < rows; ++i) {
		matrix[i] = new int[cols];
	}
	return matrix;
}



void read_matrix(int** matrix, int rows, int cols, std::istream& stream = std::cin) {
	for (int i{}; i < rows; ++i) {
		for (int j{}; j < cols; ++j) {
			stream >> matrix[i][j];
		}
	}
}

void memory_deallocation(int** matrix, int rows, int cols) {
	for (int i{}; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	matrix = nullptr;
}



void print_matrix(int** matrix, int rows, int cols, const std::string& message = " ") {
	if (!message.empty()) {
		std::cout << message << '\n';

	}
	for (int i{}; i < rows; ++i) {
		for (int j{}; j < cols; ++j) {
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';

	}

}

int find_max(int** matrix, int rows, int cols, int& index_row, int& index_col) {
	int max_num = matrix[0][0];
	for (int i{}; i < rows; ++i) {
		for (int j{}; j < cols; ++j) {
			if (matrix[i][j] > max_num) {    
				max_num = matrix[i][j];
				index_row = i;
				index_col = j;
			}
		}
	}
	return max_num;
}




int main()
{
//Task 1
	std::cout << "Task1" << '\n';
	int mass{};
	int distance{};
	std::cout << "Enter mass: ";
	std::cin >> mass;
	std::cout << "Enter distance: ";
	std::cin >> distance;
	if (validate(mass, distance) == true) {
		int cost = cost_calculation(mass, distance);
		std::cout << "Cost your delivery is " << cost << '\n';
	}
	else{
		std::cout << "Error mass or distance < or = 0" << '\n';
	}
	std::cout << '\n';
//Task 2
	std::cout << "Task2" << '\n';
	int c{};
	std::cout << "Enter number: ";
	std::cin >> c;
	if (validate(c)) {
		int count = dividers(c);
		int sum = calculating_sum(c);
		std::cout << "Count dividers: " << count << '\n' << "Sum: " << sum << '\n';
		std::cout << '\n';
	}
	else {
		std::cout << "c is not natural number";
	}
//Task 3
	std::cout << "Task3" << '\n';

	int n{};
	int square{}, cube{};
	std::cout << "Enter number: ";
	std::cin >> n;

	analyze(n, &square, &cube);
	std::cout << "Number: " << n << '\n';
	std::cout << "Square: " << square << '\n';
	std::cout << "Cube: " << cube << '\n';
	std::cout << '\n';

//Task 4
	std::cout << "Task4" << '\n';
	int size{};
	std::cout << "Enter length of array: ";
	std::cin >> size;
	if (3 <= size && size <= 100) {
		int* arr = memory_allocation(size);
		read(arr, size);
		std::cout << "Your array is :";
		print(arr, size);
		std::cout << '\n';
		std::cout << "Elements array bigger then neighbour: " << count_elem_bigger_then_neighbour(arr, size) << '\n';
		left_shift(arr, size);
		std::cout << "After shift left: ";
		print(arr, size);
		memory_deallocation(arr);	
	}
	else{
		std::cout << "size of array mustn't be less than 3 or more than 100";
	}
	std::cout << '\n';

	//Task 5 
	std::cout << "Task5" << '\n';



	int rows{};
	int cols{};
	std::cout << "Enter count rows: ";
	std::cin >> rows;
	std::cout << "Enter count cols: ";
	std::cin >> cols;

	if (rows >= 1 && rows <= 10 && cols >= 1 && cols <= 10) {
		int index_row{};
		int index_col{};

		int** matrix = memory_allocation(rows, cols);
		std::cout << "Enter your matrix ";
		read_matrix(matrix, rows, cols);
		std::cout << "Your matrix is ";
		print_matrix(matrix, rows, cols);

		std::cout << "Max number is " << find_max(matrix, rows, cols, index_row, index_col) << " Row " << index_row << " Column " << index_col << '\n';
		memory_deallocation(matrix, rows, cols);
	}
	else {
		std::cout << "rows and cols must be > 1 and < 10" << '\n';
	}
}

