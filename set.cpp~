#include<iostream>
using namespace std;

template<class Type>class Set;

template<class Type>class SetItem
{
	Type item;
	SetItem *left;
	SetItem *right;
	SetItem(const Type & t):item(t),left(0),right(0){}
	friend class Set<Type>;
};

template<class Type>class Set
{
	private:
		SetItem<Type> *root;
		int k,flag;
	public:
		Set():root(0),k(0){};
		void insert(Type t)
		{
			if(!this->present(t))
			{
				SetItem<Type> *temp,*p,*q;
				temp=new SetItem<Type>(t);
				if(root==0)
				{
					root=temp;
					k++;
				}
				else
				{
					p=q=root;
					while(q!=0)
					{
						p=q;
						if(t<p->item)
						{
							q=q->left;
						}
						else
						{
							q=q->right;
						}
					}
					if(t==p->item)
					{}
					else if(t<p->item)
					{
						p->left=temp;
					}
					else
					{
						p->right=temp;
					}
					k++;
				}
			}
			flag=0;
		}
		int present(Type t)
		{
			int k;
			k=present1(t,root);
			return k;
		}
		int present1(Type t,SetItem<Type>*temp)
		{
			if(temp==0)
			{
				return 0;
			}
			present1(t,temp->left);
			if(temp->item==t)
			{
				flag=1;
			}
			present1(t,temp->right);
			return flag;
		}
		void show()
		{
			show1(root);
		}
		void show1(SetItem<Type>*temp)
		{
			if(temp==0)
			{
				return ;
			}
			show1(temp->left);
			cout<<temp->item<<endl;
			show1(temp->right);
		}
		int nofitems()
		{
			return k;
		}
		void setall1(SetItem<Type>*temp)
		{
			if(temp==0)
			{
				return ;
			}
			setall1(temp->left);
			setall1(temp->right);
			temp=0;
		}
		void setall()
		{
			setall1(root);
		}
		~Set()
		{
			setall();
		}
};

int main()
{
	Set<int>s;
	int i,j;
	for(int i=0;i<10;i++)
	{
		cin>>j;
		s.insert(j);
	}
	cout<<"---"<<endl;
	/*cin>>j;
	if(s.present(j))
	{
		cout<<"yes"<<endl;
	}*/
	s.show();
	return 0;
}
