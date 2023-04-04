//--------------------------------------------------------------------------------------------
// Made by Dmitrii Dudin
// 04.04.2023
// 
// Binary tree realisation
//--------------------------------------------------------------------------------------------

#include <iostream>

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


//Binary tree node structure
//Node have one value and two pointers to the next two elements
struct Node {
	int value;
	Node* left;
	Node* right;
};

//Class that contains describe and some
//Binary tree methods
class BinaryTree {
private:
	//Ponters that is showing on the top of the binary tree
	Node* root;

public:

	//Constructor
	BinaryTree() {
		root = nullptr;
	}

	//Method Push with one argument, that will be added in the tree
	void Push(const int &x) {

		//new Node that contains pointers to nullptr and value x
		Node* tmp = new Node;
		tmp->left = nullptr;
		tmp->right = nullptr;
		tmp->value = x;

		//if tree is empty
		if (root == nullptr) {
			root = tmp;
			return;
		}

		//pointer to find position for new Node
		Node* pointer = root;

		while (true) {

			//if new value is higher then value on our pointer
			//then we are going to right side of the tree
			if (x > pointer->value) {

				//if the right side of our pointer is equal to nullptr
				//then we have find the new Node position
				if (pointer->right == nullptr) {
					pointer->right = tmp;
					break;
				}
				//else we have to move to the right side
				else {
					pointer = pointer->right;
				}

			}

			//if new value is less then value on our pointer
			//then we have to go by left side of the tree
			else {
				//if the left side of our pointer is equal to nullptr
				//then we have find the new Node position
				if (pointer->left == nullptr) {
					pointer->left = tmp;
					break;
				}
				//else we have to move to the left side
				else {
					pointer = pointer->left;
				}
			}

		}

	}

	//Print tree in directional way
	void PrintTreeByLeft(Node* tmp) {

		//if our pointer is null then we have not value on this position
		if (tmp == nullptr)return;

		//Print value
		cout << tmp->value << " ";

		//Two recursive calls of this function
		//At first? by left side, and then by right side
		PrintTreeByLeft(tmp->left);
		PrintTreeByLeft(tmp->right);
	}

	//Print tree in this variant:1) root 2) right side 3) left side
	void PrintTreeByRight(Node* tmp) {

		//if our pointer is null then we have not value on this position
		if (tmp == nullptr)return;

		//Print value
		cout << tmp->value << " ";

		//Two recursive calls of this function
		//At first? by left side, and then by right side
		PrintTreeByRight(tmp->right);
		PrintTreeByRight(tmp->left);
	}

	//Method to become root of the tree
	Node* GetRoot() {
		return this->root;
	}

	//Method that proof, that value is on tree 
	bool IsElementAlreadyInTree(const int& val, Node* tmp) {

		//if we are on the nullptr, that means, that tree didnt contains this element
		if (tmp == nullptr) {
			cout << "Number " << val << " is not on the tree\n";
			return 0;
		}
		
		//if we have find this element return true
		if (tmp->value == val) {
			cout << "Number " << val << " is on the tree\n";
			return 1;
		}
		//else we have choise between two side
		else {
			if (val < tmp->value) {
				IsElementAlreadyInTree(val, tmp->left);
			}
			else {
				IsElementAlreadyInTree(val, tmp->right);
			}
		}
	}

};



int main() {

	//speed boost
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	BinaryTree ss;
	ss.Push(10);
	ss.Push(45);
	ss.Push(1);
	ss.Push(25);
	ss.Push(15);
	ss.Push(50);
	ss.Push(0);
	ss.Push(35);

	ss.IsElementAlreadyInTree(35, ss.GetRoot());

	//ss.PrintTreeByLeft(ss.GetRoot());
	//ss.PrintTreeByRight(ss.GetRoot());
	return 0;
}