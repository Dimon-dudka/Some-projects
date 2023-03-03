//--------------------------------------------------------------------------------------------
// Made by Dmitrii Dudin
// 04.03.2023
// 
// Calculator
// Solution in dynamic programming
// We need to become count of operations and temporary values
// while becoming number N from 1
//Operations: multiply the number X by 2;
//            multiply the number X by 3;
//            add one to the number X.
//--------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

//--------------------------------------------------------------------------------------------
//My C++ settings (using define)
//--------------------------------------------------------------------------------------------
#define ll long long

#define PRINT_VECTOR(a) for(const auto&w:a)cout<<w<<" ";
#define PRINT_REVERSE_VECTOR(a) for(auto it=a.rbegin();it!=a.rend();++it)cout<<*it<<" ";
#define PRINT_2D_VECTOR(a)for(const auto&w:a){for(const auto &s:w)cout<<s<<" ";cout<<endl;}

#define ENTER_DATA_INTO_VECTOR(a) for(auto &w:a)cin>>w;   //Only when we know size of vector

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
//--------------------------------------------------------------------------------------------

int main() {

	//speed boost
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,tmp;
	cin >> n;
	n += 1;

	vector<int>value(n, 0);	//Vector with just a numbers from 1 to N
	vector<int>dp(n, 0);	//Vector of temporary count of operations
	vector<int>index(n, 0);	//Vector for indexes for every operation result

	//Start filling of there arays 
	for (int i = 1; i < n; ++i) {
		value.at(i) = i;
	}

	for (int i = 2; i < n; ++i) {
		dp.at(i) = 1;
	}

	for (int i = 2; i < n; ++i) {
		index.at(i) = 1;
	}

	//Start of main algorythm
	for (size_t i = 4; i < n; ++i) {

		tmp = dp.at(i - 1) + 1;
		index.at(i) = i - 1;

		if (value.at(i) % 2 == 0) {
			if (tmp >= dp.at(i / 2) + 1) {
				tmp = dp.at(i / 2) + 1;
				index.at(i) = i / 2;
			}
			
		}
		if (value.at(i) % 3 == 0) {
			if (tmp >= dp.at(i / 3) + 1) {
				tmp = dp.at(i / 3) + 1;
				index.at(i) = i / 3;
			}
		}
		
		dp.at(i) = tmp;
	}

	//Print minimal count of operations
	cout << dp.at(n - 1) << endl;
	
	int index_t = index.at(n - 1);

	vector<int>ans;

	//Going throw our indexes and add values to final result vector
	ans.push_back(n - 1);
	while (index_t > 0) {
		ans.push_back(index_t);
		index_t = index.at(index_t);
	}
	PRINT_REVERSE_VECTOR(ans);

	return 0;
}
