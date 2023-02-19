//--------------------------------------------------------------------------------------------
// Made by Dmitrii Dudin
// 19.02.2023
// 
// Queue realisation based on List
// That also is processing some base requests
// Request becoms from user string input
//--------------------------------------------------------------------------------------------

#include <iostream>
#include<string>

using namespace std;

//--------------------------------------------------------------------------------------------
//My C++ settings (using define)
//--------------------------------------------------------------------------------------------
#define ll long long

#define PRINT_VECTOR(a) for(const auto&w:a)cout<<w<<" ";
#define ENTER_DATA_INTO_VECTOR(a) for(auto &w:a)cin>>w;   //Only when we know size of vector
//--------------------------------------------------------------------------------------------

//Structure that describe some Node
struct Node {
	int value;
	Node* next;
};

//class Queue that contains in private filed pointers 
//and in public field - methods: Push(int x), Pop, Front, Size, Clear
class Queue {
private:
	//Pointers on the first and the last Node
	Node* first_element;
	Node* last_element;
public:

	//Base constructor that fill 2 pointers
	Queue() {
		first_element = nullptr;
		last_element = nullptr;
	}

	//Method push element on the tail of queue
	void Push(const int& number) {

		//Enter the data into new Node
		Node* tmp;
		tmp = new Node;
		tmp->value = number;
		tmp->next = nullptr;

		if (first_element != nullptr) {
			last_element->next = tmp;
			last_element = tmp;
		}
		else {
			first_element = tmp;
			last_element = tmp;
		}
		cout << "ok\n";
	}

	//Method is deleting the first element in queue
	void Pop() {
		//if queue is not empty (first element pointer is not equal to zero)
		if (first_element != nullptr) {
			Node* tmp;
			tmp = first_element;
			cout << first_element->value << endl;
			first_element = first_element->next;
			delete tmp;
		}
		else cout << "error" << endl;
	}
	
	//Print the first element from queue
	//with also proof that queue is not empty
	void Front() {
		if (first_element != nullptr) {
			Node* tmp = first_element;
			cout << tmp->value << endl;
		}
		else cout << "error\n";
	}

	//Print the size of queue
	//works with O(N) time
	//my modifed by enter some counter varibale, that will be increase or decrease
	//by using some methods like "Push" or "Pop"
	void Size() {
		Node* tmp = first_element;
		int rez = 0;
		while (tmp != nullptr) {
			rez += 1;
			tmp = tmp->next;
		}
		cout << rez << endl; //rez is our counter
	}
	
	//Clearing our queue
	//works with O(N) time
	void Clear() {
		Node* tmp = first_element;
		Node* tmp2;
		while (tmp != nullptr) {
			tmp2 = tmp;
			tmp = tmp->next;
			delete tmp2;
		}
		first_element = nullptr;
		cout << "ok" << endl;
	}
	~Queue() {}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	Queue q;

	//ss is our request
	string ss;
	cin >> ss;

	//we dont need a proof each letter of our word
	while (ss.at(0) != 'e') { //if request is not "exit"
		switch (ss.at(0))
		{
		case 'p':
			//but if first letter is 'P',then we have 2 posible methods
			//and we have to proof the second letter of request word

			//Push num
			if (ss.at(1) == 'u') { 
				int num;
				cin >> num;
				q.Push(num);
			}
			//Pop
			else {
				q.Pop();
			}

			break;
		case 'f':
			//Front
			q.Front();
			break;
		case 's':
			//Size
			q.Size();
			break;
		case 'c':
			//Clear
			q.Clear();
			break;
		}
		cin >> ss;
		
	}
	//request answer to "exit"
	cout << "bye\n";
	q.~Queue();
	return 0;
}