//--------------------------------------------------------------------------------------------
// Made by Dmitrii Dudin
// 08.03.2023
// 
// Topological sorting with checking the directed graph for a cycle
// The graph is given by the number of vertices and edges (n and m)
// The graph itself is given by an adjacency list
//--------------------------------------------------------------------------------------------

#include <iostream>
#include<vector>

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

//Global varibale "flag", that contains info about the presence of a cycle in the graph.
// if true - no cycle
// if false - it is cycle on the graph
bool G_flag = true;

//recursive function DFS
void DFS(vector<vector<int>>&graph, vector<int>&proof,vector<int>&rez, int edge) {

	//At the entrance to the graph we "painting" the input edge in a grey
	proof.at(edge) = 1;
	
	//Going throw all neighbors of the edge 
	for (auto& w : graph.at(edge)) {

		if (proof.at(w) == 1) {		//if some neighbor is "grey" - we find the cycle
			G_flag = false;	
			return;	
		}
		else if (proof.at(w) == 0) {	//if some neighbor if not painting, we mace a recursive call of DFS
			
			DFS(graph, proof, rez, w);
		}
	}

	//In the end we paintnig our edge in "black"
	//And put the edge into our answer-vector
	proof.at(edge) = 2;
	rez.push_back(edge);
}


int main() {

	//speed boost
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//Enter count of edges and verticels
	int n,m, tmp1,tmp2;
	cin >> n>>m;

	vector<vector<int>>graph(n + 1);	//adjacency graph list
	vector<int>proof(n + 1, 0);		//proof that some edge is not painted
	vector<int>rez;				//vector of topological sorted edges

	//Enter data into adjacency graph list
	for (size_t i = 0; i < m; ++i) {
		cin >> tmp1 >> tmp2;
		graph.at(tmp1).push_back(tmp2);
	}

	for (size_t i = 1; i < n + 1; ++i) {
		if (G_flag == false)break;		//if global flag is false we have not to proof all anothers edges
							//becouse we find the cycle

		if (proof.at(i) == 0)DFS(graph, proof, rez, i);
	}

	if (G_flag) {
		PRINT_REVERSE_VECTOR(rez);		//we have to reverse the result vector to correct answer
	}
	else cout << -1;				//if it is some cycle in the graph we have to print "-1"

	return 0;
}