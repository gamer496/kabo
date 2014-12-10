#include<iostream>
#include<string>
using namespace std;

//pair and using that map association and aggregation

template<class Type1,class Type2> class Pair                    //pair of stl
{
	public:
		Type1 first;
		Type2 second;
		Pair():first(),second()
		{
		}
		Pair(Type1 f,Type2 s):first(f),second(s)
		{
		}
		void makepair(Type1 a,Type2 b)
		{
			first=a;
			second=b;
		}
		void operator=(Pair <Type1,Type2> & p)          //assignment operator of pair this show that pair heavily depends on other libraries
		{
			this->first=p.first;
			this->second=p.second;
		}
		int operator<(Pair<Type1,Type2> & p)
		{
			return this->first<p.first;
		}
};


template<class Type1,class Type2>class Map
{
	private:
		Pair<Type1,Type2> p[100];
		int i;
	public:
		Map()
		{
			i=0;
		}
		void sort()
		{
			Pair<Type1,Type2>e,f,t;
			for(int j=0;j<i;j++)
			{
				if(p[i]<p[j])
				{
					t=p[i];
					e=p[j+1];
					f=p[j];
					int k;
					for(k=j;k<i-1;k++)
					{
						p[k+1]=f;
						f=e;
						e=p[k+2];
					}
					p[k+1]=f;
					p[j]=t;
					break;
				}
			}
		}
		void insert(Type1 a,Type2 b=1)
		{
			for(int j=0;j<i;j++)
			{
				if(p[j].first==a)
				{
					p[j].second+=b;
					return ;
				}
			}
			p[i].makepair(a,b);
			this->sort();
			i++;
		}
		void show()
		{
			for(int j=0;j<i;j++)
			{
				cout<<p[j].first<<"  "<<p[j].second<<endl;
			}
		}
};

int main()
{
	Pair<string,int>p("ok",1);
	//cout<<p.first<<"  "<<p.second<<endl;
	Map<string,int>m;
	string s;
	for(int i=0;i<10;i++)
	{
		cin>>s;
		m.insert(s);
	}
	m.show();
	return 0;
}
