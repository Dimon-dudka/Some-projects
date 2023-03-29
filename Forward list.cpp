//--------------------------------------------------------------------------------------------
// Made by Dmitrii Dudin
// 29.03.2023
// 
// Forward List realisation
//--------------------------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include<string>
#include<unordered_map>
#include<unordered_set>

using namespace std;

//--------------------------------------------------------------------------------------------
//My C++ settings (using define)
//--------------------------------------------------------------------------------------------
#define ll long long

#define PRINT_VECTOR(a) for(const auto&w:a)cout<<w<<" ";
#define PRINT_REVERSE_VECTOR(a) for(auto it=a.rbegin();it!=a.rend();++it)cout<<*it<<" ";
#define PRINT_2D_VECTOR(a)for(const auto&w:a){for(const auto &s:w)cout<<s<<" ";cout<<endl;}
#define PRINT_SET_OF_PAIRS(a)for(const auto &w:a){cout<<w.first<<" "<<w.second<<endl;}

#define ENTER_DATA_INTO_VECTOR(a) for(auto &w:a)cin>>w;   //Only when we know size of vector

#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
//--------------------------------------------------------------------------------------------


//General view of structure
struct Node {

	//value that we will safe in this node
	int value;

	//Pointer to the next node
	Node* next;
	
};


class NodeList {

private:

	//Pointers on the first element(root) and the last element
	Node* first;
	Node* last;

	//varibale to print size for O(1)
	unsigned int size;

public:

	//Constructor
	NodeList() {
		first = nullptr;
		last = nullptr;
		size = 0;
	}

	//Pushing element on the tail of forward list
	void Push(int val) {

		//Creating new Node with new value and pointer to the nullptr
		Node* tmp = new Node;
		tmp->value = val;
		tmp->next = nullptr;

		size += 1;

		//if it is first node in this list
		if (first == nullptr) {
			
			first = tmp;
			last = tmp;
			return;

		}

		last->next = tmp;
		last = tmp;
		
	}

	//Print all elements in the List
	void PrintAllElements() {

		//if List is empty
		if (first == nullptr) {
			cout << "NO LIST!\n";
			return;
		}

		Node* tmp = new Node;
		tmp = first;

		//while we have some nodes
		while (tmp != nullptr) {

			//output format is "(var)->"
			cout <<"(" << tmp->value<<")" << " -> ";
			tmp = tmp->next;
		}

		cout << endl;
		return;
	}

	//Reverse List O(N)
	void ReverseList() {

		//if list is empty
		if (first == nullptr) {
			return;
		}

		Node* tmp, * next, * prev=nullptr;

		//we have to work with 3 pointers to reverse 
		tmp = first;
		last = tmp;
		
		//while we have nodes in our list
		while (tmp != nullptr) {

			next = tmp->next;
			tmp->next = prev;
			prev = tmp;
			tmp = next;
		}
		
		//reenter our basic pointers
		first = prev;

	}

	//Print size of the list
	void Size() {
		cout << "Size of forward list = " << this->size << "\n";
	}

	//Pop the first element in the list
	void PopFirst() {

		//if list is empty
		if (first == nullptr) {
			return;
		}

		Node* tmp;
		int temp = first->value;
		tmp = first;
		first = first->next;
		
		size -= 1;

		delete tmp;
		cout << "Was deleted first element: " << temp << endl;

	}

	//Pop the last element in forward list
	void PopLast() {

		//if list is empty
		if (first == nullptr) return;

		//if there are only one element in the list
		if (first == last) {
			PopFirst();
			return;
		}

		Node* tmp = first;
		int temp;

		//This part works on O(N) time
		//we have to find element that is bevor the last element
		while (tmp->next != last) {

			tmp = tmp->next;

		}
		tmp->next = nullptr;
		temp = last->value;
		delete last;
		last = tmp;

		size -= 1;

		cout << "Was deleted last element: " << temp << endl;
	}

	//Showing the element on the top of the list
	void Top() {
		if (first != nullptr) {
			cout << last->value << endl;
			return;
		}
		return;
	}

	//Erasing all elements in the list
	void Clear() {

		Node* tmp;
		tmp = first;

		while (tmp != nullptr) {
			first = first->next;
			delete tmp;
			tmp = first;
			size -= 1;
		}
		cout << "Forward List is clear\n";
	}

};


int main() {

	//speed boost
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	//Test input
	NodeList node;

	node.Push(3);
	node.Push(4);
	node.Push(1);
	node.Push(10);
	node.Push(14);
	node.Push(40);

	node.ReverseList();
	
	node.PopLast();
	node.PopFirst();
	node.PrintAllElements();

	return 0;
}