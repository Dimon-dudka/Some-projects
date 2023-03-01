//--------------------------------------------------------------------------------------------
// Made by Dmitrii Dudin
// 01.03.2023
// 
// The longest common subsequence problem
// Solution in dynamic programming
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

	//sizes of sequences n and m
	int n, m;
	cin >> n;
	//first sequence, it also can be char
	vector<int>first(n);
	ENTER_DATA_INTO_VECTOR(first);
	cin >> m;
	//second sequence
	vector<int>second(m);
	ENTER_DATA_INTO_VECTOR(second);

	//2D vector of dynamic programming prefixes
	//+1 for sizes is becouse we have some start conditions
	//to posibility to using dynamic programming formel
	vector<vector<int>>proof(n+1, vector<int>(m+1,0));

	for (size_t i = 1; i < n+1; ++i) {
		for (size_t j = 1; j < m+1; ++j) {

			if (first.at(i-1) == second.at(j-1)) {
				proof.at(i).at(j) = proof.at(i - 1).at(j - 1) + 1;
			}
			else {
				proof.at(i).at(j) = MAX(proof.at(i - 1).at(j), proof.at(i).at(j - 1));
			}

		}
	}

	//vector of the longest common subsequence
	vector<int>ans;

	int a = n, b = m ;
	
	while (a!=0&&b!=0) {

		if (first.at(a-1) == second.at(b-1)) {
			ans.push_back(first.at(a-1));
			a -= 1;
			b -= 1;
		}
		else if (proof.at(a - 1).at(b) == proof.at(a).at(b) ) {
			a -= 1;
		}
		else {
			b -= 1;
		}
		
	}
	//The longest common subsequence size is on the latest proof position(proof[n][m])
	
	//To correct answer we have to print reverse reverse
	PRINT_REVERSE_VECTOR(ans);

	return 0;
}