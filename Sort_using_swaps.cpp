#include <iostream>
#include<vector>

using namespace std;

template <typename T>					
void sort_with_swap(vector<T>& numbers) {		//function will sorting our vector and not make a new vector

	unsigned long int is_sort = 0;              //if it will be a lot of numbers in vector
	while (true) {
		for (size_t i = 1; i < numbers.size(); i++) {         //function will go into vector and swap 2 elements pro step
			if (numbers[i] < numbers[i - 1]) {
				numbers[i - 1] = numbers[i - 1] + numbers[i]; //swap using arithmetic
				numbers[i] = numbers[i - 1] - numbers[i];	  //we also can use XOR or the 3 varible
				numbers[i - 1] = numbers[i - 1] - numbers[i];
				is_sort++;                            
			}
		}
		if (is_sort == 0)break;                 //if it was no one swap in vector then break
		else {
			is_sort = 0;
		}
	}
}

template <typename T>
void cout_of_vector(const vector<T>& a) {
	for (size_t i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
}

int main() {

	vector<double> num{ 103,4,7,1,87,32,333,45.5 };   //test vector
	sort_with_swap(num);							  
	cout_of_vector(num);

	return 0;
}