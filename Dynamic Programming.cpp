//--------------------------------------------------------------------------------------------
// Made by Dmitrii Dudin
// 28.02.2023
// 
// Dynamic Programming Problem
// Print the route of the maximum cost (with letters 'R'-right and 'D'-down)
// And Print the maximum cost of the route
//--------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

//--------------------------------------------------------------------------------------------
//My C++ settings (using define)
//--------------------------------------------------------------------------------------------
#define ll long long

#define PRINT_VECTOR(a) for(const auto&w:a)cout<<w<<" ";
#define ENTER_DATA_INTO_VECTOR(a) for(auto &w:a)cin>>w;   //Only when we know size of vector

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
//--------------------------------------------------------------------------------------------

int main() {

	//speed bost
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//NxM-size of table
	int n, m;
	cin >> n >> m;

	vector<vector<int>>proof(n, vector<int>(m));	//table with user data about cost of every place in the table
	vector<vector<int>>rez(n, vector<int>(m));	//dynamic programming solution

	vector<char>ans;				//vector of route directions

	//user data enter
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			cin >> proof.at(i).at(j);
		}
	}

	rez.at(0).at(0) = proof.at(0).at(0);	//first element will not be changed

	//dinamic programming solution for rows first elements
	for (size_t i = 1; i < n; ++i) {
		rez.at(i).at(0) = rez.at(i - 1).at(0) + proof.at(i).at(0);
	}
	//dinamic programming solution for column first elements
	for (size_t i = 1; i < m; ++i) {
		rez.at(0).at(i) = rez.at(0).at(i-1) + proof.at(0).at(i);
	}

	for (size_t i = 1; i < n; ++i) {
		for (size_t j = 1; j < m; ++j) {
			//Formel to find a lokal maximum
			//this is dinamic programming solution for this [i][j] element!
			rez.at(i).at(j) = MAX(rez.at(i).at(j - 1), rez.at(i - 1).at(j)) + proof.at(i).at(j);
		}
	}

	size_t i = n-1, j = m-1;
	//we gonna go throw our way from the end to start point
	//and also choise the lokal maximum
	//It will be our solution

	//while we are not in the start point...
	while (j!=0||i!=0 ) {

		//if columns coordinate is equel to zero we have to move only in 'i' coordinate 
		//And in answer it will be down - 'D'
		if (j == 0) {
			ans.push_back('D');
			i -= 1;
		}
		//if rows coordinate is equel to zero we have to move only in 'j' coordinate 
		//And in answer it will be right - 'R'
		else if (i == 0) {
			ans.push_back('R');
			j -= 1;
		}
		else {
			//We choise a lokal maximum and go there
			if (rez.at(i).at(j - 1) > rez.at(i - 1).at(j)) {
				ans.push_back('R');
				j -= 1;
			}
			else {
				ans.push_back('D');
				i -= 1;
			}
		}
	}

	//Our maximum way will be in the last cell of the result(rez) table
	cout << rez.at(n - 1).at(m - 1)<<endl;

	//reverse print becouse we went from the end of the table
	for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
		cout << *it << " ";
	}

	return 0;
}
