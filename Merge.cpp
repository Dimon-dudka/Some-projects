#include <iostream>
#include<vector>

using namespace std;

//My C++ settings (using define)

#define PRINT_VECTOR(a) for(const auto&w:a)cout<<w<<" ";
#define ENTER_DATA_INTO_VECTOR(a) for(auto &w:a)cin>>w;   //Only when we know size of vector

template <typename T>
vector<T> MERGE(const vector <T>&a, const vector <T>&b) {
    vector<T>rez;

    size_t i_a = 0, i_b = 0,size_a=a.size(),size_b=b.size();
    while (i_a < size_a && i_b < size_b) {
        if (a.at(i_a) < b.at(i_b)) {
            rez.push_back(a.at(i_a));
            i_a += 1;
        }
        else if (a.at(i_a) >= b.at(i_b)) {
            rez.push_back(b.at(i_b));
            i_b += 1;
        }
    }
    if (i_a >= size_a && i_b < size_b) {                 //This statement is using for a moment,when
 							 //some vector is empty
        while (i_b < size_b) {
            rez.push_back(b.at(i_b)); i_b += 1;
        }
    }
    else if (i_b >= size_b && i_a < size_a) {
        while (i_a < size_a) {
            rez.push_back(a.at(i_a)); i_b += 1;
        }
    }
    return rez;
}