#include <iostream>
#include<vector>

using namespace std;

//--------------------------------------------------------------------------------------------
//My C++ settings (using define)
//--------------------------------------------------------------------------------------------
#define PRINT_VECTOR(a) for(const auto&w:a)cout<<w<<" ";
#define ENTER_DATA_INTO_VECTOR(a) for(auto &w:a)cin>>w;   //Only when we know size of vector
//--------------------------------------------------------------------------------------------



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	unsigned int n, m, k, lx, rx, ly,ry ;
	long long rez, tmp;
	cin >> n >> m >> k;

	vector<vector<long long>>proof(n+1, vector<long long>(m+1,0));	//vector of prefix sum

	for (unsigned int i = 0; i < n; ++i) {
		for (unsigned int j = 0; j < m; ++j) {
			cin >> tmp;												//user matrix data
			proof[i + 1][j + 1] = proof[i][j + 1] + proof[i + 1][j] - proof[i][j] + tmp; //using this formel
																						 //become a prefix sum
		}
	}

	//for (const auto& w : proof) {
	//	for (const auto& s : w)cout << s << " ";
	//	cout << endl;
	//}

	//Prefix sum in rectangle with coordinates(lx,ly,rx,ry) right into our matrix
	for (unsigned int i = 0; i < k; ++i) {
		rez = 0;
		cin >> lx >> ly >> rx >> ry;

		//this is formul to sum in this lx ly and rx ry positions in a prefix matrix
		rez = proof.at(rx).at(ry) - proof.at(lx - 1).at(ry) - proof.at(rx).at(ly - 1) + proof.at(lx - 1).at(ly - 1);

		cout << rez << endl;
	}

	return 0;
}