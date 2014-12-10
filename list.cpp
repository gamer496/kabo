#include <iostream> 

//list is stl class implemented as a doubly linked list
//fully generic program would work with almost any data
//basically uses association and aggregation


using namespace std;

template <class T> class Link;
template <class T> class List_iterator;


//class 1:list is the core of this library uses other classes as is the library implemented in main
template <class T> 
class List
{
public:
   typedef List_iterator<T> iterator;

   List();
   List(const List<T> & l);
   ~List();

   bool empty() const;
   unsigned int size() const; 
   T & back() const;
   T & front() const;
   void push_front(const T & x);
   void push_back(const T & x);
   void pop_front();
   void pop_back();
   iterator begin() const;
   iterator end() const;
   void insert(iterator pos, const T & x);
   void erase(iterator & pos); 
   List<T> & operator=(const List<T> & l);

protected:
   Link<T> * start;
   Link<T> *  end1;
   unsigned int my_size;
};

template <class T>
List<T>::List()                               //constructor(DEfault)
{
        start = 0;
         end1 = 0;
        my_size = 0;
}

template <class T>
List<T>::List(const List & l)                //copy constructor
{
        start = 0;
         end1 = 0;
        my_size = 0;
        for (Link<T> * current = l.start; current != 0; current = current -> next)
                push_back(current -> value);
}

template <class T>
typename List<T>::iterator List<T>::begin() const    //returns the first(head) of list
{
        return iterator(start);
}


//link is each element of the list and contains pointers next and prev like struct in used in c the main feature of this implementation is 
//encapsulation
template <class T> 
class Link 
{
private:
   Link(const T & x): value(x), next(0), prev_link(0) {}

   T value;     
   Link<T> * next;
   Link<T> * prev_link;

   friend class List<T>;
   friend class List_iterator<T>;
};

//iterator is the fancy element of this library preventing any overflow and null pointer assignment it elimates any need for exception handling

template <class T> class List_iterator
{
public:
   typedef List_iterator<T> iterator;      //names are as clear as possible for the sake of clarity of the code took me extra time to do it!!

   List_iterator(Link<T> * source_link): current_link(source_link) { }
   List_iterator(): current_link(0) { }
   List_iterator(List_iterator<T> * source_iterator): current_link(source_iterator.current_link) { }

   T & operator*();  
   iterator & operator=(const iterator & rhs);
   bool operator==(const iterator & rhs) const;
   bool operator!=(const iterator & rhs) const;
   iterator & operator++(); 
   iterator operator++(int);
   iterator & operator--(); 
   iterator operator--(int); 

protected:
   Link<T> * current_link;

   friend class List<T>;
};

template <class T>
T & List_iterator<T>::operator*()       //overloaded deferencing function to make iterator as a pointer
{
        return current_link -> value;
}

template <class T>
List_iterator<T> & List_iterator<T>::operator++()   //overloaded pre increment function
{
        current_link = current_link -> next;
        return *this;
}

template <class T>
void List<T>::push_back(const T & x)      //push back to implement push back in the list will insert in the end(like stack)
{
    Link<T> *  temp = new Link<T> (x);
    if (start == 0)
    start =  end1 =  temp;                   //normal dll implementation
    else
    {
     temp->prev_link =  end1;
         end1->next =  temp;    
         end1 =  temp;
    }
    my_size++;
}

template <class T>
typename List<T>::iterator List<T>::end() const       //to return next of end (will always be end except for cll)
{
        return iterator( end1->next);
}

template <class T>
List <T>::~List()  //destructor for clean up this shows the extend of encapsulation of this library memory leaks are prevented as much as possible
{
    Link <T> * first = start;
    while (first != 0)
    {
    Link <T> * next = first->next;
        delete first;
    first = next;
    }
}

template<class T>
bool List_iterator<T>::operator==(const iterator & rhs) const  //just for convience not used that much
{
    return ( this->current_link == rhs.current_link ); 
}

template <class T>
bool List_iterator<T>::operator!=(const iterator & rhs) const //to do comparison in main
{
    return !( *this == rhs );
}

int main()
{
   List<int> l;

   l.push_back(44);  
   l.push_back(33);  
   l.push_back(11);  
   l.push_back(22);  

   List<int> m(l);

   List<int>::iterator itr(m.begin());
   while (itr != m.end()) {
        cout << *itr << endl;
        ++itr;
   }
   return 0;
}
