//--------------------------------------------------------------------------------------------
// Made by Dmitrii Dudin
// 24.04.2023
// 
// My template class Vector
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

template <typename T>
class Vector {
private:

	//Class Vector will have array of template type
	//and max size and max capacity
	T* array_;
	size_t size_{};
	size_t capacity_{};

public:

	//Base constructor
	Vector() {
		array_ = new T[1];
		capacity_ = 1;
	}

	//Constructor that give opportunity initialisation vector with some list of values 
	//Example: Vector<int>test = {1,2,3};
	Vector(const initializer_list<T>& tmp) {
		array_ = new T[1];
		capacity_ = 1;
		for (const auto& w : tmp) {
			push_back(w);
		}
		
	}

	//Move Semantics Constructor
	//l-value
	Vector(Vector& other) {
		if (this != &other) {
			delete[] array_;
			array_ = new T[other.capacity_];
			for (size_t i = 0; i < other.size_; ++i) { 
				array_[i] = other.array_[i];
			}
			size_ = other.size_;
			capacity_ = other.capacity_;
		}
	}

	//Move Semantics Constructor
	//r-value
	Vector(Vector&& other)  noexcept {
		if (this != &other) {
			delete[] array_;
			array_ = other.array_;
			size_ = other.size_;
			capacity_ = other.capacity_;
			other.array_ = nullptr;
			other.size_ = other.capacity_ = 0;
		}
	}
	
	//Destructor of Vector class
	~Vector() {
		delete[] array_;
		size_ = 0;
		capacity_ = 0;
	}

	//Function returns vector size
	size_t Size() {
		return size_;
	}

	//Function returns vector max capacity
	size_t Capacity() {
		return capacity_;
	}

	//Function that makes realocation of vector capacity (capacity*2) 
	//and moved all values in the new place
	void addMemory() {
		//Realacation capacity like multiply on 2
		capacity_ *= 2;
		
		//allocation new dynamic memory with new capacity 
		T* tmp = array_;
		array_ = new T[capacity_];

		//copy all data from old array to the new
		for (size_t i = 0; i < size_; ++i) {
			array_[i] = tmp[i];
		}

		//deleting old array
		delete[]tmp;
	}

	//Returns true if size is equal to 0, and false if not
	bool isEmpty() {
		return size_ == 0;
	}

	//Push back the new value
	void push_back(const T& val) {
		//if size is equal or more then capacity
		//we have to realloc the array with x2 capacity
		if (size_ >= capacity_)
			addMemory();
		array_[size_++] = val;
	}

	//Erasing some value on index that function becomes from user
	void erase(const size_t& index) {
		//if index is incorrect ->break
		if (index<0 || index>size_)return;
		
		//It's works by O(N) time becouse we have to move all elementsby 1 position
		for (size_t i = index; i < size_-1; ++i) {
			array_[i] = array_[i + 1];
		}
		--size_;
	}

	//Operator []
	T& operator[](const size_t& index) {
		return array_[index];
	}
	
	//Const operator []
	const T& operator[](const size_t& index) const {
		return array_[index];
	}

	//define iterators begin and end for this vector class

	//begin iterators
	T* begin() {
		return &array_[0];
	}
	
	//const begin iterator
	const T* begin() const {
		return &array_[0];
	}

	//end iterators
	T* end() {
		return &array_[size_];
	}

	//const end iterator
	const T* end() const {
		return &array_[size_];
	}

	//Operator '=' for l-value
	Vector& operator=(Vector& other) {
		if (this != &other) {
			delete[] array_;
			array_ = new T[other.capacity_];
			for (size_t i = 0; i < other.size_; ++i) {
				array_[i] = other.array_[i];
			}
			size_ = other.size_;
			capacity_ = other.capacity_;
		}
		return *this;
	}

	//Operator '=' for r-value
	Vector& operator=(Vector&& other) noexcept {
		if (this != &other) {
			delete[] array_;
			array_ = other.array_;
			size_ = other.size_;
			capacity_ = other.capacity_;
			other.array_ = nullptr;
			other.size_ = other.capacity_ = 0;
		}
		return *this;
	}

	/*
	Vector& operator +(Vector<T>& first, Vector<T>& second) {
		Vector<T> tmp;
		for (const auto& w : first) {
			tmp.push_back(w);
		}
		for (const auto& w : second) {
			tmp.push_back(w);
		}
		return tmp;
	}
	*/
};


int main() {

	//speed boost
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	Vector<int>a{ 12,3,4,2 };
	Vector<int>b{ 1,2,3,4,5 };
	Vector<int>c;
	c = a;
	for (const auto& w : c)cout << w << " ";

	return 0;
}