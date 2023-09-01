//--------------------------------------------------------------------------------------------
// Made by Dmitrii Dudin
// 28.04.2023
// 
// UIRS Project
//--------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <set>
#include <queue>

#include <Windows.h>

using namespace std;

//--------------------------------------------------------------------------------------------
//My C++ settings (using define)
//--------------------------------------------------------------------------------------------
#define ll long long

#define PRINT_VECTOR(a) for(const auto&w:a)cout<<w<<" ";
#define PRINT_REVERSE_VECTOR(a) for(auto it=a.rbegin();it!=a.rend();++it)cout<<*it<<" ";
#define PRINT_2D_VECTOR(a)for(const auto&w:a){for(const auto &s:w)cout<<s<<" ";cout<<endl;}
#define PRINT_SET_OF_PAIRS(a)for(const auto &w:a){cout<<w.first<<" "<<w.second<<endl;}

#define ENTER_DATA_INTO_VECTOR(a) for(auto &w:a)cin>>w;   //Only when we know size of vector

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
//--------------------------------------------------------------------------------------------

enum Colors {
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray,
	DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

template<Colors txt = LightGray, Colors bg = Black>
ostream& color(ostream & text) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((bg << 4) | txt));
	return text;
}

int main() {

	//speed boost
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//cout << color<Green, Black> << "test " << color<Red, Black> << "test2\n" << color;

	map<pair<int, int>, int> koordinate_and_edges;
	map<int, pair<int, int>>edges_per_koordinates;

	size_t n, m, counter_of_edges = 0;
	cin >> n >> m;
	if (n < 2 && m < 2) {
		cout << "Incorect input data!\n";
		return 0;
	}
	vector<vector<int>>start_map(n, vector<int>(m));

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			cin >> start_map.at(i).at(j);
			if (start_map.at(i).at(j) == 1)counter_of_edges += 1;
		}
	}

	vector<set<int>>graph(counter_of_edges + 1);

	int edge = 0;

	//Creating map of edges with koordinates of them
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {

			if (start_map.at(i).at(j) == 1) {

				if (koordinate_and_edges[{i, j}] == 0) {
					edge += 1;
					koordinate_and_edges[{i, j}] = edge;
					edges_per_koordinates[edge] = { i, j };
				}

				if (i - 1 >= 0 && start_map.at(i - 1).at(j) == 1) {
					if (koordinate_and_edges[{i - 1, j}] == 0) {
						edge += 1;
						koordinate_and_edges[{i - 1, j}] = edge;
						edges_per_koordinates[edge] = { i - 1, j };
					}
				}
				if (i + 1 < n && start_map.at(i + 1).at(j) == 1) {
					if (koordinate_and_edges[{i + 1, j}] == 0) {
						edge += 1;
						koordinate_and_edges[{i + 1, j}] = edge;
						edges_per_koordinates[edge] = { i + 1, j };
					}
				}
				if (j - 1 >= 0 && start_map.at(i).at(j - 1) == 1) {
					if (koordinate_and_edges[{i, j - 1}] == 0) {
						edge += 1;
						koordinate_and_edges[{i, j - 1}] = edge;
						edges_per_koordinates[edge] = { i, j - 1 };
					}
				}
				if (j + 1 < m && start_map.at(i).at(j + 1) == 1) {
					if (koordinate_and_edges[{i, j + 1}] == 0) {
						edge += 1;
						koordinate_and_edges[{i, j + 1}] = edge;
						edges_per_koordinates[edge] = { i, j + 1 };
					}
				}

			}
		}
	}

	//adding edges into graph list
	for (const auto& w : koordinate_and_edges) {
		if (w.first.first - 1 >= 0 && koordinate_and_edges[{w.first.first - 1, w.first.second}] != 0) {
			graph.at(w.second).insert(koordinate_and_edges[{w.first.first - 1, w.first.second}]);
		}
		if (w.first.first + 1 < n && koordinate_and_edges[{w.first.first + 1, w.first.second}] != 0) {
			graph.at(w.second).insert(koordinate_and_edges[{w.first.first + 1, w.first.second}]);
		}
		if (w.first.second - 1 >= 0 && koordinate_and_edges[{w.first.first, w.first.second - 1}] != 0) {
			graph.at(w.second).insert(koordinate_and_edges[{w.first.first, w.first.second - 1}]);
		}
		if (w.first.second + 1 < m && koordinate_and_edges[{w.first.first, w.first.second + 1}] != 0) {
			graph.at(w.second).insert(koordinate_and_edges[{w.first.first, w.first.second + 1}]);
		}
	}

	queue<int> back_add;
	vector<int>proof(edge + 1, -1);
	vector<int>visited;
	vector<int>answer(edge + 1, 0);

	int start_x, start_y, finish_x, finish_y;
	cin >> start_x >> start_y >> finish_x >> finish_y;

	start_x -= 1;
	start_y -= 1;
	finish_x -= 1;
	finish_y -= 1;

	system("cls");

	if (koordinate_and_edges[{start_x, start_y}] == 0) {
		cout << "Incorect start position!\n";
		return 0;
	}

	if (koordinate_and_edges[{finish_x, finish_y}] == 0) {
		cout << "Incorect finish position!\n";
		return 0;
	}

	if (finish_x == start_x && finish_y == start_y) {
		cout << "Start position and the finish position are equal\n";
		return 0;
	}

	back_add.push(koordinate_and_edges[{start_x, start_y}]);
	proof.at(koordinate_and_edges[{start_x, start_y}]) = 0;

	int tmp;
	while (!back_add.empty() && proof.at(koordinate_and_edges[{finish_x, finish_y}]) == -1) {

		tmp = back_add.front();
		back_add.pop();

		for (auto& w : graph.at(tmp)) {
			if (proof.at(w) == -1) {
				answer.at(w) = tmp;
				back_add.push(w);
				proof.at(w) = proof.at(tmp) + 1;
			}
		}
	}

	if (proof.at(koordinate_and_edges[{finish_x, finish_y}]) == -1) {
		cout << "There are not any way to finish point!\n";
		return 0;
	}


	cout << "The Length of path from start point {"<<start_x<<", "<<start_y<< "} to finifh point{" 
		<< finish_x << ", " << finish_y << "} is: ";
	cout << proof.at(koordinate_and_edges[{finish_x, finish_y}]);
	cout << " meter" << endl;

	vector<int>way;

	way.push_back(koordinate_and_edges[{finish_x, finish_y}]);

	int temp1 = answer.at(koordinate_and_edges[{finish_x, finish_y}]);

	while (temp1 != 0) {
		way.push_back(temp1);
		temp1 = answer.at(temp1);
	}

	map<pair<int,int>, int>green_way;

	cout << "The way is: \n";
	for (auto it = way.rbegin(); it != way.rend(); ++it) {
		cout << edges_per_koordinates[*it].first + 1 << ", " << edges_per_koordinates[*it].second + 1 << endl;
		green_way[{edges_per_koordinates[*it].first, edges_per_koordinates[*it].second}]=1;
	}


	cout << "\n\t";
	for (size_t i = 1; i <= n; ++i)cout << i << "  ";
	cout << "\n\n\n";

	for (int i = 0; i < n; ++i) {
		cout << i+1 << "\t";
		for (int j = 0; j < m; ++j) {
			if (green_way[{i, j}] != 0) {
				cout << color<Green, Black>;
				cout << start_map.at(i).at(j) << "  ";
				cout << color;
			}
			else {
				cout << start_map.at(i).at(j) << "  ";
			}
		}
		cout << endl;
	}

	return 0;
}