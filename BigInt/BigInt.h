#pragma once

#include"Seqlist.h"
class BigInt;
ostream& operator<<(ostream &out, const BigInt &bt);
class BigInt
{
public:
	BigInt(){}
	BigInt(u_long value);
	BigInt(const BigInt &bt)
	{
		Add(*this,0,bt);
	}
	friend ostream& operator<<(ostream &out, const BigInt &bt);//声明友元函数，让其可以访问私有数据成员
public:
	u_char back()const{return big.back();}
	void clean(){big.clean();}
	void LoadData(int sz);
	void ShowData()const;
public:
	BigInt operator=(const BigInt &bt);
	BigInt operator+(const BigInt &bt);
	BigInt operator-(const BigInt &bt);
	BigInt operator*(const BigInt &bt);
	BigInt operator/( BigInt &bt);
	BigInt operator%(const BigInt &bt);
	BigInt& operator+=(const BigInt &bt);
    BigInt& operator-=(BigInt &bt);
	BigInt& operator-=(const BigInt &bt);
	BigInt& operator=(u_long value);
	BigInt& operator++();
public:
	void pop_back(){big.pop_back();}
	void push_front(u_char x){big.push_front(x);}
	bool push_back(const char&x){return big.push_back(x);}
	void clear_head_zero(void);
	size_t size()const{return big.size();}
	static u_char Sub_base(u_char a, u_char b, u_char &sign);
	static u_char Add_base(u_char a,u_char b,u_char &sign);
	static void Mul_base(BigInt &bt, const BigInt &bt1, u_char x);
	static void MoveAdd(BigInt &bt,const BigInt &bt1 , u_long pos);
	static void Add(BigInt &bt , const BigInt &bt1,const BigInt &bt2);	//不需要借助对象来调用，在类中调动
	static void Mul(BigInt &bt , const BigInt &bt1,const BigInt &bt2);
	static void Mul2(BigInt &bt, const BigInt &bt1, const BigInt &bt2);
	static void Sub(BigInt &bt , const BigInt &bt1,const BigInt &bt2); 
	static void Div2(BigInt &bt , const BigInt &bt1,const BigInt &bt2); 
	static void Div(BigInt &bt ,  BigInt &bt1, BigInt &bt2); 
	static void Mod(BigInt &bt , const BigInt &bt1,const BigInt &bt2); 
	static void Square(BigInt &bt , const BigInt &bt1,const BigInt &bt2); 
public:
	u_char operator[](u_long pos)const{return big[pos];}
	u_char& operator[](u_long i){return big[i];}
	bool operator>=(const BigInt &bt)const;
	bool operator==(const BigInt &bt)const;
	bool operator<(const BigInt &bt)const;
	
private:
	Seqlist<u_char> big;

};