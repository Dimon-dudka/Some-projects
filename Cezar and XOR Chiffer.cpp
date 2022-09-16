#include <iostream>
#include<string>

using namespace std;


string Cezar_Chiffer(const string& message) {
	string rez = "";                               //it will be a result message after Cezar Chiffer
	unsigned int step;
	
	cout << "Enter the step of the shift: ";
	cin >> step;

	if (step < 0)step = 0;
	else if (step > 25)step = 25;
	
	for (unsigned i = 0; i < message.size(); ++i) {
		unsigned tmp = toascii(message[i]);
		if (tmp >= 65 && tmp <= 90) {
			if (tmp + step > 90) {
				rez.push_back(char(65 + (step - (90 - tmp) - 1)));
			}
			else {
				rez.push_back(char(tmp + step));
			}
		}
		else if (tmp >= 97 && tmp <= 122) {
			if (tmp + step > 122) {
				rez.push_back(char(97 + (step - (122 - tmp) - 1)));
			}
			else {
				rez.push_back(char(tmp + step));
			}
		}
		else {
			rez.push_back(message[i]);
		}
	}
	return rez;
}

string XOR_Chiffer(const string &message,const string &f_key) {
	string key = f_key;
	if (message.size() > f_key.size()) {
		while (key.size() < message.size()) {           //if key is to smal i will push any zeros back in key
			key.push_back('0');
		}
	}

	string tmp = "";
	for (unsigned i = 0; i < message.size(); ++i) {
		tmp += message[i] ^ key[i];
	}
	return tmp;
}


int main() {
	
	
	cout << XOR_Chiffer(Cezar_Chiffer("Hello World!"), "QESDj5f");  //test
	

	return 0;
}