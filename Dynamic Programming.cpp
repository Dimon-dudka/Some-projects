#include <iostream>

using namespace std;

//--------------------------------------------------------------------------------------------
//My C++ settings (using define)
//--------------------------------------------------------------------------------------------
#define ll long long

#define PRINT_VECTOR(a) for(const auto&w:a)cout<<w<<" ";
#define ENTER_DATA_INTO_VECTOR(a) for(auto &w:a)cin>>w;   //Only when we know size of vector
//--------------------------------------------------------------------------------------------


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << 1 % 2;
	int n, k, a, b;
	cin >> n >> k >> a >> b;

	int  tmp, var_petja, 
		place_petja = ((a - 1) * 2) + b;

	if (k < place_petja) {
		if (place_petja % k != 0) {
			var_petja = place_petja % k;
		}
		else {
			var_petja = k;
		}
	}
	else {
		var_petja =place_petja;
	}

	if (var_petja + 1 > k)tmp = 1;
	else tmp = var_petja + 1;

	int x1, y1, x2, y2=0;
	bool flag = false;
	int pred_mesto=-1;
	for (size_t i = place_petja+1; i <= n; ++i) {

		if (tmp == var_petja) {
			
			
			if (i % 2 != 0) {
				x1 = (i / 2) + 1;
				y1 = 1;
				flag = true;
				break;
			}
			else {
				x1 = i / 2; 
				y1 = 2;
				flag = true;
				break;
			}

		}

		tmp += 1;
		if (tmp > k)
			tmp = 1;

	}


		pred_mesto = place_petja - k;
		if(pred_mesto<1)cout << x1 << " " << y1;
		else {
			//if(place_petja+k>n)
			if (pred_mesto % 2 != 0) {
				if (pred_mesto == 1) {
					tmp = 1;
				}
				else tmp = (pred_mesto % 2) + 1;

				y2 = 1;
			}
			
			else {
				tmp = pred_mesto / 2;
				y2 = 2;
			}
			if (place_petja + k > n)cout << tmp << " " << y2;
			else if (a - tmp < x1 - a)cout << tmp << " " << y2;
			else if (a - tmp >= x1 - a) cout << x1 << " " << y1;
			else cout << -1;
		}

		
	
	return 0;
}