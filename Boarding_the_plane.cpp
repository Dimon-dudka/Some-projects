#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

//My C++ settings (using define)

#define PRINT_VECTOR(a) for(const auto&w:a)cout<<w<<" ";
#define ENTER_DATA_INTO_VECTOR(a) for(auto &w:a)cin>>w;   //Only when we know size of vector

int main() {

		//Aircraft plan:
		// A | B | C | | D | E | F
		//1	      _
		//2	      _
		//.........................

	
	int n, m;					//n - row count 
	cin >> n;
	vector<vector<char>>proof(n, vector<char>(7));	//2d vector(plan of boarding seats)

	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < 7; ++j) {
			cin >> proof.at(i).at(j);	//Enter the data into this plan with symbols:'.','_','#'
		}					//where '.' - free seat, '_' - passage, '#' - ocupied seat
	}
	

	int num, left, right, pos;
	string side, position;
	cin >> m;					//m - number of requests

	for (size_t tmp = 0; tmp < m; ++tmp) {

		cin >> num >> side >> position;		//people count, left or right, desired location

		if (side.at(0) == 'l') {

			if (position.at(0) == 'w') pos = 0;	//by left window
			else if (position.at(0) == 'a')pos = 2; //by left aisle
		}
		else if (side.at(0) == 'r') {

			if (position.at(0) == 'w')pos = 6;	//by right window
			else if (position.at(0) == 'a')pos = 4; //by right aisle
		}

		bool flag = false;
		set<int>three;					//the places for print

		for (size_t i = 0; i < n; ++i) {
			three.clear();

			if (proof.at(i).at(pos) == '.') {	//if desired seat is free
				int count = 1;			//count of people that can sit

				if (pos == 0 || pos == 4) {	//if left window or right aisle we gonna check in this way:-->
					three.insert(pos);	//insert the first free position
					for (size_t j = 1; j < num; ++j) {

						if (proof.at(i).at(j + pos) == '.') {//proof that the next seat is free
							++count;
							three.insert(j + pos);
						}
						else break;
						if (count == num)break;		//if count of people that have a ticket == count 
										//of people in request --> break
					}

				}
				else if (pos == 2 || pos == 6) {  		//if right window or left aisle we gonna check in this way:<--
					three.insert(pos);
					for (size_t j = 1; j < num; ++j) {

						if (proof.at(i).at(pos - j) == '.') {//proof that the next seat is free
							++count;
							three.insert(pos - j);
						}
						else break;
						if (count == num)break;		//if count of people that have a ticket == count 
										//of people in request --> break
					}
				}

				if (count == num) {
					flag = true;
					cout << "Passengers can take seats:";

					for (const auto &w:three) {
						cout<<" " << i + 1;
						if (w < 3)cout << char(w + 65); //ASCII code
						else cout << char(w + 64);	//65-1 becouse we have a passage
						
						proof.at(i).at(w) = 'X';	//to print theres places on jet plan
					}
					cout << endl;

					for (size_t a=0; a < n; ++a) {		//just print jet plan
						for (size_t b = 0; b < 7; ++b) {
							cout << proof.at(a).at(b);
							if (proof.at(a).at(b) == 'X')proof.at(a).at(b) = '#'; //if we are already printed 
													      //symbol 'X' it gonna be '#'
						}
						cout << endl;
					}

					break;
				}
			}

		}
		if (flag == false)cout << "Cannot fulfill passengers requirements" << endl; //if there are not places for
											    //this request

	}

	return 0;
}
