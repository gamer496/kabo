#include<iostream>
using namespace std;



template <class Type> class Vector;
template<class T> ostream & operator <<(ostream &,const Vector<T> &);

template <class Type> class VectorItem
{
	Type item;
	VectorItem *next;
	VectorItem(const Type &t):item(t),next(0){}
	friend class Vector<Type>;
	friend ostream & operator << <Type>(ostream &,const Vector<Type> &);
};


template <class Type> class Vector
{
	private:
		VectorItem<Type> *head;
		VectorItem<Type> *tail;
		void destroy();
		void copy_elements(const Vector &);
	public:
		Vector():head(0),tail(0){}
		Vector(const Vector &v):head(0),tail(0)
		{
			copy_elements(v);
		}
		Vector & operator=(const Vector &);
		~Vector()
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
		void push_back(const Type &);
		void pop();
		bool empty() const
		{
			return head==0;
		}
		template <class It> Vector(It beg,It end): head(0),tail(0)
		{
			copy_elements(beg,end);
		}
		template <class Iter>void assign(Iter,Iter);
		template <class It>void copy_elements(It,It);
		friend ostream & operator << <Type>(ostream &,const Vector<Type> &);
};

template<class Type> void Vector<Type>::push_back(const Type &val)
{
	VectorItem<Type>*pt=new VectorItem<Type>(val);
	if(head==0)
	{
		head=tail=pt;
	}
	else
	{
		pt->next=head;
		head=pt;
	}
}

template <class Type>void Vector<Type>::pop()
{
	VectorItem<Type>*p;
	p=head;
	head=head->next;
	delete p;
}

template<class Type>void Vector<Type>::destroy()
{
	while(!empty())
	{
		pop();
	}
}

template<class Type> void Vector<Type>::copy_elements(const Vector &orig)
{
	for(VectorItem <Type> *pt=orig.head;pt;pt=pt->next)
	{
		push_back(pt->Item);
	}
}

template <class Type> Vector<Type> & Vector<Type>::operator=(const Vector &v)
{
	(*this).destroy();
	(*this).copy_elements(v);
	return *this;
}

template <class T> template<class Iter>void Vector<T>::assign(Iter beg,Iter end)
{
	destroy();
	copy_elements(beg,end);
}

template<class Type>template<class It>void Vector<Type>::copy_elements(It beg,It end)
{
	while(beg!=end)
	{
		push(*beg);
		++beg;
	}
}

template<class Type>ostream & operator<<(ostream &os,const Vector <Type> &q)
{
	os<<"<";
	VectorItem<Type>*p;
	for(p=q.head;p;p=p->next)
	{
		os<<p->item<<" ";
	}
	os<<">"<<endl;
	return os;
}

int main()
{
	Vector<int>v;
	for(int i=0;i<10;i++)
	{
		v.push_back(i);
	}
	cout<<v;
	return 0;
}
