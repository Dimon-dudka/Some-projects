//--------------------------------------------------------------------------------------------
// Made by Dmitrii Dudin
// 12.03.2023
// 
// The Speleologist's Way
// 
// The cave is represented by a cube divided into N parts for each dimension.
// Each cell can be either empty or completely filled with a stone.
// Based on the position of the caver in the cave, it is required to find out what is the minimum number of
// movements through the cells he needs to get to the surface.You can move from cell to cell only if they are 
// both freeand have a common face.
// The first line contains the number N (1 ≤ N ≤ 30). This is followed by N blocks.
// The block consists of an empty line and N lines of N characters : #  - denotes a cell filled with stones, dot - a free cell.
// The initial position of the caver is indicated by the capital letter S.
// The first block represents the upper level of the cave, reaching any of its free cells means reaching the surface.
// Access to the surface is always possible.
// 
// Print one number - the length of the path to the surface.
//--------------------------------------------------------------------------------------------

#include <iostream>
#include<vector>
#include<queue>
#include<tuple>

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

	// n-size of 3d vector
	int n;
	char tempch;
	cin >> n;
	
	// 3D vector is full with '-2' - it is a wall or stone
	// -1 is an empty not visited place, 0 - start point
	vector<vector<vector<int>>>graph(n, vector<vector<int>>(n, vector<int>(n, -2)));

	// queue to proof all neighbors
	queue < tuple<int, int, int>>proof;


	// Enter Data into 3D vector
	// if it is '.' we are painting this place on 3d vector in '-1'
	// if it is 'S' we are painting this place on 3d vector in '0'
	// and if it is '#' we didnt do enything, becouse vector is already full with '-2'
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < n; ++j) {
			for (size_t k = 0; k < n; ++k) {
				cin >> tempch;
				if (tempch == '.') {
					graph.at(i).at(j).at(k) = -1;
				}
				else if (tempch == 'S') {
					graph.at(i).at(j).at(k) = 0;
					proof.push({ i,j,k });
				}
			}
		}
	}
	
	// vector of all posible neighbors position 
	vector<tuple<int, int, int>>dxdydz{ {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };

	// For convenience
	int one, two, three;

	//while we have some neighbors
	while (!proof.empty()) {
		// For convenience
		one = get<0>(proof.front());
		two= get<1>(proof.front());
		three= get<2>(proof.front());
		
		proof.pop();

		// We are going throw vector of all posible neighbors positions
		for (const auto& w : dxdydz) {


			// And if this neighbor exist and it is not a wall('-2') - we calculate the way and add this position 
			// in vector proof
			
			if ((one + get<0>(w) >= 0 && one + get<0>(w) < n) && (two + get<1>(w) >= 0 && two + get<1>(w) < n)
				&& (three + get<2>(w) >= 0 && three + get<2>(w) < n)) {

				if (graph.at(one + get<0>(w)).at(two + get<1>(w)).at(three + get<2>(w)) == -1) {

					graph.at(one + get<0>(w)).at(two + get<1>(w)).at(three + get<2>(w)) = graph.at(one).at(two).at(three) + 1;
					proof.push({ one + get<0>(w) ,two + get<1>(w) ,three + get<2>(w) });
					
					// if we are on the top of the cube and way to this point is already
					// calculated, then we can print this way and stop our programm
					if (one + get<0>(w) == 0) {
						cout << graph.at(one + get<0>(w)).at(two + get<1>(w)).at(three + get<2>(w)) << endl;
						return 0;
					}
				}
			}

		}
	}
	
	return 0;
}