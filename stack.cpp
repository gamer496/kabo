#include<iostream>
using namespace std;
#define nullptr 0


template <class T>
class Stack {

public:
	Stack()
	{
		elements=0;
		root_node=nullptr;
	}
	void push(T);     
	bool empty();     
	T top();          
	void pop();       
	int size();       
	void print();     

	struct node 
	{     

		T node_data;
		node *next;

		
		node() { next = nullptr;  }

		
		~node() { delete root_node; }
	};

private:
	node *root_node;
	int elements ;
};


template <class T>
bool Stack<T>::empty() 
{ 
	return (root_node == nullptr); 
}


template <class T>
int Stack<T>::size() 
{ 
	return elements;
}


template <class T>
void Stack<T>::push(T data) 
{
	if ( empty() ) 
	{
		root_node = new node;
		root_node->node_data = data;
		root_node->next = nullptr;
		elements++;
	}

		
		
	else  
	{
		node *new_node = new node;
		*new_node = *root_node;
		root_node->next = new_node;
		root_node->node_data = data;
		elements++;
 	}
}


template <class T>
void Stack<T>::pop() 
{

	if (size() > 1) 
	{
		node *temp_node = new node;
		temp_node = root_node->next;

		root_node = temp_node;
		elements--;
	}

	else if (size() == 1) 
	{
		root_node = nullptr;
		elements--;
	}

	else 
	{
		cout << "\nOperation pop() failed: Stack is empty!" << endl;
	}
}


template <class T>
T Stack<T>::top() 
{
	if (!empty()) 
	{
		return root_node->node_data;
	}
	else 
	{
		cout << "\nOperation top() failed: Stack is empty!" << endl; 
		return -1;
	}
}


template <class T>
void Stack<T>::print() 
{
	int index = size();
	for (int i = 1; i < index; i++) 
	{
        cout << "Element " << i << ": " << "  "  << top() << endl;
        pop();
    }
}

int main()
{
	Stack<int>s;
	for(int i=0;i<10;i++)
	{
		s.push(i);
	}
	s.print();
	return 0;
}
