#include <iostream>
#include <string>
#include <vector>

using namespace std;

//--------------------------------------------------------------------------------------------
//My C++ settings (using define)
//--------------------------------------------------------------------------------------------
#define PRINT_VECTOR(a) for(const auto&w:a)cout<<w<<" ";
#define ENTER_DATA_INTO_VECTOR(a) for(auto &w:a)cin>>w;   //Only when we know size of vector
//--------------------------------------------------------------------------------------------

template<typename T>						//its works for std::string,std::array or std::vector of char
void RLE_ENCODING(const T & start) {

	for (size_t i = 0; i < start.size(); ++i) {		//algorythm is going through all word

		int count = 1;					//count of repetitions of letter

		while (i < start.size() - 1 && start.at(i) == start.at(i + 1)) {	//while this letter is repeating
			++count;								
			++i;								//increase of i to not proof it in the next time
		}

		if (count == 1)cout << start.at(i);			//if count == 1 we have to print only the letter without count
		else cout << start.at(i) << count;

	}
	cout << endl;
}

int main() {


	string start;
	vector<char>a{ 'A','A','A','B','B','C' };

	cin >> start;
	
	RLE_ENCODING(start);
	RLE_ENCODING(a);
	
	return 0;
}
