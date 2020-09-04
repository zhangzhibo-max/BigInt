#pragma once
#include"utili.h"


template <class Type>
class Seqlist
{
public:
	Seqlist(int sz = SEQLIST_DEFAULT_SIZE)
	{
		capacity = sz > SEQLIST_DEFAULT_SIZE ? sz  : SEQLIST_DEFAULT_SIZE;
		base = new Type[capacity + 1];
		memset(base , 0,sizeof(Type)*(capacity+1));
		assert(base != NULL);
			len = 0;
	}
	~Seqlist()
	{
		delete []base;
		base = NULL;
		capacity = len = 0;
	}
public:
	bool push_back(const Type&x)
	{
		if(IsFull() && !_Inc())
		{
			cout<<"Push Back error."<<endl;
			return false;
		}
		base[++len ] = x;
		return true;
	}
	bool push_front(const Type &x)
	{
		if(IsFull() && !_Inc())
		{
			cout<<"Push Front error."<<endl;
			return false;
		}
		for(int i = len ; i>=1 ;--i)
		{
			base[i+1] = base[i];
		}
		base[1] = x;
		len ++;
		return true;
	}
	Type& pop_back()
	{
		if(len == 0)
			return base[len];
		//len --;
		return base[len--];
	}
	void pop_front()
	{
		if(IsEmpty())
			return false;
		for(int i = 1 ; i<len ;++i)
		{
			base[i] = base[i+1];
		}
		len --;
		return true;
	}
	size_t size()const{return len;}
	size_t size(){return len;}
	Type * front()
	{
		assert(len != 0);
		return base[1];
	}
	Type * front()const
	{
		assert(len != 0);
		return base[1];
	}
	Type& back()
	{
		return base[len];
	}
	Type& back()const
	{
		return base[len];
	}
	void sort();
	void showlist()
	{
		for(int i = 1;i <= len ;++i)
		{
			cout<<(int)base[i]<<" ";
		}
		cout<<endl;
	}
	void clean(){len = 0;}
/*****************ÖØÔØº¯Êý**********************/
	/*Seqlist& operator=( Seqlist& n)
	{	
		this->capacity = n.capacity;
		this->len = n.len;
		
		Type* temp=new Type[n.capacity];
		memcpy(temp,n.base,capacity);
		delete []base;
		return *this;
	}*/
	const Type& operator[](int pos)const
	{
		//assert(pos >= 0 && pos <= len);
		return base[pos];
	}
	Type& operator[](int pos)
	{
		//assert(pos >= 0 && pos <= len);
		return base[pos];
	}
	
protected:
	bool _Inc()
	{
		Type * new_base = new Type[capacity+INC_SIZE+1];
		assert(new_base != NULL);
		memset(new_base,0,sizeof(Type)*(capacity+1));
		memcpy(new_base, base,sizeof(Type)*(capacity+1));
		capacity += INC_SIZE;
		delete []base;
		base = new_base;
		return true;
	}
protected:
	bool IsFull()const{return len >= capacity;}
	bool IsEmpty()const{return len == 0;}

private:
	enum{SEQLIST_DEFAULT_SIZE = 20,INC_SIZE = 10};
	Type *base;
	size_t capacity;
	size_t len;
};