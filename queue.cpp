#include<iostream>
using namespace std;



template <class Type> class Queue;
template<class T> ostream & operator <<(ostream &,const Queue<T> &);

template <class Type> class QueueItem
{
	Type item;
	QueueItem *next;
	QueueItem(const Type &t):item(t),next(0){}
	friend class Queue<Type>;
	friend ostream & operator << <Type>(ostream &,const Queue<Type> &);
};


template <class Type> class Queue
{
	private:
		QueueItem<Type> *head;
		QueueItem<Type> *tail;
		void destroy();
		void copy_elements(const Queue &);
	public:
		Queue():head(0),tail(0){}
		Queue(const Queue &q):head(0),tail(0)
		{
			copy_elements(q);
		}
		Queue & operator=(const Queue &);
		~Queue()
		{
			destroy();
		}
		Type & front()
		{
			return head->item;
		}
		const Type & front() const
		{
			return head->item;
		}
		void push(const Type &);
		void pop();
		bool empty() const
		{
			return head==0;
		}
		template <class It> Queue(It beg,It end): head(0),tail(0)
		{
			copy_elements(beg,end);
		}
		template <class Iter>void assign(Iter,Iter);
		template <class It>void copy_elements(It,It);
		friend ostream & operator << <Type>(ostream &,const Queue<Type> &);
};

template<class Type> void Queue<Type>::push(const Type &val)
{
	QueueItem<Type>*pt=new QueueItem<Type>(val);
	if(head==0)
	{
		head=tail=pt;
	}
	else
	{
		tail->next=pt;
		tail=pt;
	}
}

template <class Type>void Queue<Type>::pop()
{
	QueueItem<Type>*p;
	p=head;
	head=head->next;
	delete p;
}

template<class Type>void Queue<Type>::destroy()
{
	while(!empty())
	{
		pop();
	}
}

template<class Type> void Queue<Type>::copy_elements(const Queue &orig)
{
	for(QueueItem <Type> *pt=orig.head;pt;pt=pt->next)
	{
		push(pt->Item);
	}
}

template <class Type> Queue<Type> & Queue<Type>::operator=(const Queue &q)
{
	(*this).destroy();
	(*this).copy_elements(q);
	return *this;
}

template <class T> template<class Iter>void Queue<T>::assign(Iter beg,Iter end)
{
	destroy();
	copy_elements(beg,end);
}

template<class Type>template<class It>void Queue<Type>::copy_elements(It beg,It end)
{
	while(beg!=end)
	{
		push(*beg);
		++beg;
	}
}

template<class Type>ostream & operator<<(ostream &os,const Queue <Type> &q)
{
	os<<"<";
	QueueItem<Type>*p;
	for(p=q.head;p;p=p->next)
	{
		os<<p->item<<" ";
	}
	os<<">"<<endl;
	return os;
}


int main()
{
	Queue<int>q;
	for(int i=0;i<10;i++)
	{
		q.push(i);
	}
	cout<<q;
}
