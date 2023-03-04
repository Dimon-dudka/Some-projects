//--------------------------------------------------------------------------------------------
// Made by Dmitrii Dudin
// 04.03.2023
// 
// Translate time from one format to another
// 2:00 --> "Two hours"
//--------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <map>
#include <string>

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

	map<unsigned int, string>minutes;
	minutes[1] = "one";
	minutes[2] = "two";
	minutes[3] = "three";
	minutes[4] = "four";
	minutes[5] = "five";
	minutes[6] = "six";
	minutes[7] = "seven";
	minutes[8] = "eight";
	minutes[9] = "nine";
	minutes[10] = "ten";
	minutes[11] = "eleven";
	minutes[12] = "twelve";
	minutes[13] = "thirteen";
	minutes[14] = "fourteen";
	minutes[15] = "quarter";
	minutes[16] = "sixteen";
	minutes[17] = "seventeen";
	minutes[18] = "eighteen";
	minutes[19] = "nineteen";
	minutes[20] = "twenty";
	minutes[30] = "half";

	int h, m;
	char tmp;
	string answer="";
	cin >> h >> tmp >> m;

	if (m == 0) {
		answer += minutes[h] ;
	}
	else {

		if (m <= 30) {
			if (minutes.find(m) != minutes.end()) {
				if (m == 30) {
					answer += minutes[m] + " " + minutes[h];
				}
				else if (m == 15) {
					answer += minutes[m] + " after " + minutes[h];
				}
				else answer += minutes[m] + " minutes after " + minutes[h];
				
			}
			else {
				answer+= minutes[20] + " " + minutes[m % 20] + " minutes after " + minutes[h] ;
			}
		}
		else {
			int m_tmp = 60 - m;

			if (h + 1 >= 13)h = 0;

			if (minutes.find(m_tmp) != minutes.end()) {
				if (m_tmp == 15) {
					answer+= minutes[m_tmp]+" for "+ minutes[h + 1];
				}
				else answer += minutes[m_tmp] + " minutes for " + minutes[h + 1];
			}
			else {
				answer+= minutes[20] + " " + minutes[m_tmp % 20] + " minutes for " + minutes[h + 1];
			}
		}

	}
	
	answer+= " hours\n";
	answer.at(0) = char(answer.at(0) - 32);
	cout << answer;

	return 0;
}