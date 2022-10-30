#include <iostream>
#include<vector>

using namespace std;

//My C++ settings (using define)

#define PRINT_VECTOR(a) for(const auto&w:a)cout<<w<<" ";
#define ENTER_DATA_INTO_VECTOR(a) for(auto &w:a)cin>>w;   //Only when we know size of vector

template<typename T>
void MERGE(vector<T> &rez, vector<T> &left, vector<T> &right) {

    size_t size_l = left.size();
    size_t size_r = right.size();
    size_t i_l = 0;
    size_t i_r = 0;


    while (i_l < size_l && i_r < size_r) {

        if (left.at(i_l) < right.at(i_r))
            rez.push_back(left.at(i_l++));

        else
            rez.push_back(right.at(i_r++));
    }

    while (i_l < size_l) rez.push_back(left.at(i_l++));
    while (i_r < size_r) rez.push_back(right.at(i_r++));
}

template<typename T>
void MERGE_SORT(vector<T>&a) {
    if (a.size()<=1)return;
    else {
        auto iter = a.begin() + a.size() / 2;
        vector<T>left(a.begin(), iter);
        vector<T>right(iter, a.end());

        MERGE_SORT(left);
        MERGE_SORT(right);
        a.clear();

        MERGE(a,left,right);
    }
}

int main()
{
    
    vector<int>b{2,-5,56, -6,0,5,6,1,12, 3,-10};

    PRINT_VECTOR(b);
    cout << endl;
    MERGE_SORT(b);
   
    PRINT_VECTOR(b);
   
    return 0;
}