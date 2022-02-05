#include <iostream>
#include <iomanip>
#include<vector>

using namespace std;

int main() {

    
    int infinit = 1000;           //biggest number for first proof of points
    vector<vector<int>> dlina;    //enter the array with lengtes from one point to another
    bool proof[4] = { 0,0,0,0 };  //proof that this point was check out
    vector<int> min_length(4, infinit);
    for (int i = 0; i < 4; i++) {
        min_length[i] = infinit;  //fill the array with min length to a max num
    }
    
    dlina.resize(4);              //making array 4x4
    for (int i = 0; i < 4; i++) {
        dlina[i].resize(4);
    }
    dlina = { {0, 3, 5, 0},       //fill array with length
              {3, 0, 1, 13},
              {5, 1, 0, 10},
              {0, 13,10,0} };

    // i will use a first point as start

    min_length[0] = 0;            //this is start point, point number '0'
    int minindex,min,temp;
    do {
        minindex = 10000;
        min = 10000;
        for (int i = 0; i < 4; i++) {
            if (proof[i] == 0 && min_length[i] < min) { //searching for min number of points
                min = min_length[i];                    //if found enter this number to a min number
                minindex = i;                           //enter the index of this number
            }
        }
        if (minindex != 10000) {
            for (int i = 0; i < 4; i++)
            {
                if (dlina[minindex][i] > 0)            // if we can go on some point, this point will be more then 0
                {
                    temp = min + dlina[minindex][i];   //become a second number how summ of ways
                    if (temp < min_length[i])          
                    {
                        min_length[i] = temp;
                    }
                }
            }
            proof[minindex] = 1;                      //we was in this point
        }


    } while (minindex < 10000);
    
        
    
    for (const auto& w : min_length) {     //cout of min ways to points
        cout << w << " ";
    }
    

    return 0;
}