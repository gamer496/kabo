#include<iostream>
#include<string.h>
using namespace std;


class String
{
	private:
		char *p;
		int i;
	public:
		String();
		String(char *q);
		String(const String & s);
		int len();
		void insert(int a,char *b);
		void erase(int a,int b);
		int find(char c);
		String operator+(String & s1);
		int operator>(String &s1);
		friend istream & operator>>(istream & s,String & s1);
		friend ostream & operator<<(ostream & s,String & s1);
};


int String::find(char c)
{
	for(int j=0;j<strlen(p);j++)
	{
		if(c==p[j])
		{
			return j;
		}
	}
	return -1;
}

int String::operator>(String & s1)
{
	return strcmp(this->p,s1.p);
} 

void String::insert(int a,char *b)
{
	char *t=new char[i];
	strcpy(t,p);
	i*=10;
	p=new char[i];
	for(int j=0;j<a;j++)
	{
		p[j]=t[j];
	}
	int j=a,l=0;
	for(int k=a;b[l]!=0;k++)
	{
		p[k]=b[l++];
	}
	strcat(p,t+a);
}
	

void String::erase(int a,int b)
{
	for(int j=a;j<=strlen(p)-1-b+a;j++)
	{
		p[j]=p[j+b+1-a];
	}
}


int String:: len()
{
	return this->i;
}

String::String()
{
	i=0;
}

String::String(char *q)
{
	p=new char[strlen(q)];
	i=strlen(q);
	strcpy(p,q);
}

String::String(const String & s)
{
	p=new char[strlen(s.p)];
	i=strlen(s.p);
	strcpy(p,s.p);
}

String String::operator+(String & s1)
{
	String s3;
	s3.i=this->len()+strlen(s1.p);
	s3.p=new char[i];
	strcpy(s3.p,this->p);
	strcat(s3.p,s1.p);
	return s3;
}

istream & operator>>(istream & s,String & s1)
{
	char *q;
	int j=10;
	s1.i=0;
	s1.p=new char[10];
	do
	{
		s1.p[s1.i++]=s.get();
		if(s1.i%10==0)
		{
			j*=2;
			q=new char[j];
			strcpy(q,s1.p);
			s1.p=q;
		}
	}while(s1.p[s1.i-1]!='\n');
	s1.p[--s1.i]=0;
	return s;
}

ostream & operator<<(ostream & s,String & s1)
{
	s<<s1.p;
	return s;
}


int main()
{
	String s1;
	cin>>s1;
	cout<<s1<<endl;
	return 0;
}
