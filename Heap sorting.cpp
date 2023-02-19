//--------------------------------------------------------------------------------------------
// Made by Dmitrii Dudin
// 19.02.2023
// 
// Heap-sort
// Based on my realisation Max-Heap
// But method Extract was changed
// it was void and now it is int and it returns max element
//--------------------------------------------------------------------------------------------

#include <iostream>
#include <string>
#include<vector>
#include<deque>

using namespace std;

//--------------------------------------------------------------------------------------------
//My C++ settings (using define)
//--------------------------------------------------------------------------------------------
#define ll long long

#define PRINT_VECTOR(a) for(const auto&w:a)cout<<w<<" ";
#define ENTER_DATA_INTO_VECTOR(a) for(auto &w:a)cin>>w;   //Only when we know size of vector
//--------------------------------------------------------------------------------------------


class Heap {
private:
	//vector of heap data
	vector<int>rez;
public:
	Heap() {}

	//Insert element x 
	void Insert(const int &x) {
		rez.push_back(x);
		int pos = rez.size() - 1;	//last element

		while (pos > 0 && rez.at(pos) > rez.at((pos - 1) / 2)) {	//(i-1)/2  -  formel to find a father inthe three
			swap(rez.at(pos), rez.at((pos - 1) / 2));				//swap 2 elements
			pos = (pos - 1) / 2;									//new position using father formel
		}
	}

	//Show and pop the maximum element of the heap
	int Extract() {
		//cout << rez.at(0)<<endl;			//print the maximum element
		int ans = rez.at(0);
		rez.at(0) = rez.at(rez.size() - 1); //first element now is the last element

		int pos = 0;
		while ((pos * 2) + 2 < rez.size() ) {	//(i*2)+1 and (i*2)+2 are formel to find a child note in vector
			int min_son_index = (pos * 2) + 1;
			if (rez.at((pos * 2) + 2) > rez.at(min_son_index)) {
				min_son_index = (pos * 2) + 2;
			}
			if (rez.at(pos) < rez.at(min_son_index)) {
				swap(rez.at(pos), rez.at(min_son_index));
				pos = min_son_index;
			}
			else {
				break;
			}
		}
		rez.pop_back();	
		return ans;//delete last element
	}

	void HeapSort(const int& n) {
		deque<int>proof;

		for (size_t i = 0; i <n; ++i) {
			proof.push_front(Extract());
		}

		PRINT_VECTOR(proof);
	}
};


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	Heap q;
	int n,tmp;
	cin >> n;

	for (size_t i = 0; i < n; ++i) {

		cin >> tmp;
		q.Insert(tmp);

	}
	
	q.HeapSort(n);
	
	
	return 0;
}
