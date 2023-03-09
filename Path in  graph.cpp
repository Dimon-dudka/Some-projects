//--------------------------------------------------------------------------------------------
// Made by Dmitrii Dudin
// 10.03.2023
// 
// Shortest path in an undirected graph
// Output of the length of the shortest path and the vertices through which it passes
//--------------------------------------------------------------------------------------------

#include <iostream>
#include<vector>
#include<queue>

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

	// n -size of graph, start and finish - first and the last edges
	int n, tmp,start,finish;
	cin >> n;

	vector<vector<int>>graph(n + 1);
	vector<int>proof(n + 1, -1);

	vector<int>ans(n + 1, 0);

	//Adjacency matrix input:
	for (size_t i = 1; i < n + 1; ++i) {
		for (size_t j = 1; j < n + 1; ++j) {
			cin >> tmp;
			if (tmp != 0) {
				graph.at(i).push_back(j);
			}
		}
	}

	cin >> start >> finish;

	queue<int> back_add;

	back_add.push(start);
	proof.at(start) = 0;

	//While the queue is not zero, or we have not found the length to the end
	while (!back_add.empty()&&proof.at(finish)==-1) {
		tmp = back_add.front();
		back_add.pop();

		//Going throw all neighbors of the edge
		for (auto& w : graph.at(tmp)) {
			//if edge is not visited
			if (proof.at(w) == -1) {

				ans.at(w) = tmp;

				back_add.push(w);
				proof.at(w) = proof.at(tmp) + 1;

			}
		}

	}
	//if it is no way to final edge it will be printed '-1'
	//or it will be size of the way
	cout << proof.at(finish)<<endl;
	
	//We also have to print sequence of edges that are on our way
	//if size is not equal to '-1' or size is more then 0
	if (proof.at(finish) > 0) {
		vector<int>rez;
		rez.push_back(finish);
		int temp1 = ans.at(finish);

		//Restoring the response
		while (temp1 != 0) {
			rez.push_back(temp1);
			temp1 = ans.at(temp1);
		}
		//And print reverse sequence
		PRINT_REVERSE_VECTOR(rez);

	}
	return 0;
}