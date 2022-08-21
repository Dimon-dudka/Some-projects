#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void Selection_Sort(vector<T>& rez);

int main() {

	vector<int> rez{ 3,5,2,8,9,1,45,12,7 };

	Selection_Sort(rez);

	for (const auto& w : rez)cout << w << "\t";

	return 0;
}

template<typename T>
void Selection_Sort(vector<T>& rez) {
	for (size_t i = 0; i < rez.size(); ++i) {
		int min = 1000000;
		size_t tmp;
		for (size_t j = i; j < rez.size(); ++j) {
			if (rez[j] < min) {
				min = rez[j];
				tmp = j;
			}
		}
		swap(rez[i], rez[tmp]);
	}
}