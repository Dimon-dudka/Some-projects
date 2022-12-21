#include <iostream>
#include<vector>

using namespace std;

//My C++ settings (using define)

#define PRINT_VECTOR(a) for(const auto&w:a)cout<<w<<" ";
#define ENTER_DATA_INTO_VECTOR(a) for(auto &w:a)cin>>w;   //Only when we know size of vector

template<typename T>
void Selection_Sort(vector<T>&rez);   //First defenition of function

int main() {

	vector<int> rez{ 3,5,2,8,9,1,45,12,7 }; //array of our elements
	//PRINT_VECTOR(rez);
	//cout << endl;
	Selection_Sort(rez);                    //Our function

	PRINT_VECTOR(rez);						//"rez" array output

	return 0;
}

template<typename T>						//if we didnt know varibale type(int,float,double,short...)
void Selection_Sort(vector<T>&rez) {

	for (size_t i = 0; i < rez.size(); ++i) {

		int min = rez.at(i);				//smallest element on start is on i position
		size_t tmp=i;							//just varible

		for (size_t j = i; j < rez.size(); ++j) //the second loop to find min element in the remaining part
		{
			if (rez[j] < min) {				//if our new element
				min = rez.at(j);			//min element = rez[i]
				tmp = j;					//tmp.index = j
				
			}
		}
		swap(rez.at(i), rez.at(tmp));		//swap 2 elements in the array
		//PRINT_VECTOR(rez);
		//cout << endl;
	}
}
