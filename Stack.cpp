#include <iostream>
#include <string>

using namespace std;

//--------------------------------------------------------------------------------------------
//My C++ settings (using define)
//--------------------------------------------------------------------------------------------
#define PRINT_VECTOR(a) for(const auto&w:a)cout<<w<<" ";
#define ENTER_DATA_INTO_VECTOR(a) for(auto &w:a)cin>>w;   //Only when we know size of vector
//--------------------------------------------------------------------------------------------

//Stack realisation using forward list

//Stack structure
template <typename T>
struct NodeStack
{
    T item;
    NodeStack<T>* next;
};

//Stack realisations
template <typename T>
class StackList
{
private:
    NodeStack<T>* pTop;

public:
    StackList() { pTop = nullptr; }

    //Method is pushing some element on the top of stack
    //and writing "ok"
    void Push(T item)
    {
        NodeStack<T>* p;
        p = new NodeStack<T>; 
        
        p->item = item;
        p->next = pTop; 

        pTop = p;
        cout << "ok\n";
    }

    //Method is printing "0" if stack is empty or
    //count of elements in the stack
    void Count()
    {
        if (pTop == nullptr)
            cout<<0<<endl;
        else
        {
            NodeStack<T>* p = pTop;
            int count = 0;

            while (p != nullptr)
            {
                count++;
                p = p->next;
            }
            cout << count << endl;
        }
    }

    //Method is deleting all element in the stack
    //and writing "ok"
    void Empty()
    {
        NodeStack<T>* p; 
        NodeStack<T>* p2;

        p = pTop;

        while (p != nullptr)
        {
            p2 = p; 
            p = p->next; 
            delete p2; 
        }
        pTop = nullptr; 
        cout << "ok\n";
    }

    //                              ^
    //                              |
    //Destructor that use function "Empty"
    ~StackList()
    {
        Empty();
        cout << "bye" << endl;
    }


    //Method is deleting some element on the top of stack
    //and writing "error" if stack is empty or value of this item
    void Pop()
    {
        if (pTop == nullptr)
            cout << "error" << endl;
        else {
            NodeStack<T>* p2; 
            T item;
            item = pTop->item;

            p2 = pTop;
            pTop = pTop->next;

            delete p2;
            cout << item << endl;
           
        }
    }


    //Method is writing some element on the top of stack
    void Back()
    {
        if (pTop == nullptr)
            cout << "error" << endl;
        else {
            NodeStack<T>* p2; 
            T item;
            item = pTop->item;
            cout << item << endl;
        }
    }
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    //Request string
    string ss;
    //Some element that can be pushed into stack
    int tmp;

    StackList<int> SL;
    cin >> ss;

    if (ss.at(0) != 'e') {              //if request != "exit"
        while (ss.at(0) != 'e') {       //while request != "exit"

            switch (ss.at(0)) {         //proof what kind of letter is the first in the word
                                        //to didnt proof every element in a string

            case 'p':                   //in case of 'p' it is posible 2 variants: "push" or "pop"

                if (ss.at(1) == 'u') {  //Push
                    cin >> tmp;         //if push then user have to write whal element will be pushed in the stack
                    SL.Push(tmp);
                }
                else {                  //Pop
                    SL.Pop();
                }
                break;
            case 'b':
                SL.Back();              //Back
                break;
            case 's':
                SL.Count();             //Count/Size
                break;
            case 'c':
                SL.Empty();             //Empty/Clear
                break;
            }

            cin >> ss;
        }
    }
    
    SL.~StackList();                    //Class Destructor             
	
	return 0;
}
