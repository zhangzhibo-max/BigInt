#include"BigInt.h"
BigInt Tmp;
ostream& operator<<(ostream& out,const BigInt &bt)
{
	for(int i=bt.size() ; i>0; --i)
	{
		out<<(int)bt.big[i];
	}
	return out;
}
void BigInt::clear_head_zero()
{
	if(*this == 0)
		return;
	while((*this).back() == 0)
	{
		pop_back();
		if(*this == 0)
			return;
	}
}
BigInt::BigInt(u_long value)
{
	if(value == 0)
	{
		push_back(0);
	}
	while(value)
	{
		push_back(value % 10);
		value /= 10;
	}
}
void BigInt::LoadData(int sz)
{
	srand((unsigned int)time(NULL)); // 保证每次产生的数据不同，采用时间函数
	for(int i = 0;i<sz;++i)
	{
		big.push_back(rand() % 10);

	}
}
void BigInt::ShowData()const
{
	for(int i = big.size() ; i>= 1;--i)
	{
		cout<<(int)big[i]<<" ";
	}
	cout<<endl;
}
u_char BigInt::Sub_base(u_char a, u_char b, u_char &sign)
{
	u_char sub;
	if(a >= b + sign)  // 判断a 与 b 是否够减
	{
		sub = a - b - sign;
		sign = 0;    //借位赋0
	}
	else
	{
		sub = a+10 - b - sign;
		sign = 1;
	}
	return sub;
}
void BigInt::Sub(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
	bt.clean();
	if(bt1 < bt2)
		return;
	bt.clean();
	if(bt1 == bt2)
		bt = 0;
	else
	{
		u_long i, j;
		i = j = 1;
		u_char sign = 0;
		u_char sub = 0;
		while(i<=bt1.size() && j<=bt2.size())
		{
			sub = Sub_base(bt1[i], bt2[j], sign);
			bt.push_back(sub);
			i++;
			j++;
		}
		while(i <= bt1.size())
		{
			sub = Sub_base(bt1[i], 0, sign);
			bt.push_back(sub);
			i++;
		}
	}
	bt.clear_head_zero();
}
void BigInt::MoveAdd(BigInt &bt,const BigInt &bt1 , u_long pos)
{
	u_long i = pos;
	u_long j = 1;
	u_char sign = 0;
	while(i<=bt.size() && j<=bt1.size())
	{
		bt[i] = Add_base(bt[i], bt1[j], sign);
		++i;
		++j;
	}
	while(sign>0 && i<=bt.size())
	{
		bt[i] = Add_base(bt[i], 0, sign);
		++i;
	}
	while(j <= bt1.size())
	{
		u_char sum = Add_base(0, bt1[j], sign);
		bt.push_back(sum);
		++j;
	}
	if(sign > 0)
		bt.push_back(sign);
}
void BigInt::Mul_base(BigInt &bt, const BigInt &bt1, u_char x)
{
	bt.clean();
	u_long i = 1;
	u_char res, sign = 0;
	while(i <= bt1.size())
	{
		res = x * bt1[i] + sign; // 2 * 9 == 18
		sign = res / 10;
		res %= 10;	
		bt.push_back(res);
		++i;
	}
	if(sign > 0)
		bt.push_back(sign);
	bt.clear_head_zero();
}
u_char  BigInt::Add_base(u_char a,u_char b,u_char &sign)//加法基函数
	{

		u_char sum = a + b + sign;
		if(sum >= 10)
		{
			sign = 1;
			sum -= 10;
		}
		else sign=0;
		return sum;
	}
void BigInt::Add(BigInt &bt , const BigInt &bt1,const BigInt &bt2) //加法
{
	bt.clean();
	u_long i,j;
	i = j = 1;
	u_char sum = 0;
	u_char sign = 0;
	while(i <= bt1.size( )&& j <= bt2.size()) //bt1与bt2可能一样长时
	{
		sum = Add_base(bt1[i],bt2[j],sign);
		bt.push_back(sum);
		i++;
		j++;
		/*
		sum = bt1[i] + bt2[j] + sign;
		if(sum >= 10)
		{
			sum -= 10;
			sign =1;
		}
		else
			sign = 0;
		bt.push_back(sum);
		i++;
		j++;*/
	}
	// bt1与bt2长度不相同
	while(i<= bt1.size()) //bt1长度小于bt2时
	{
		sum = Add_base(bt1[i],0,sign);
		bt.push_back(sum);
		i++;
	}
	while(j <= bt2.size())//bt2长度小于bt1时
	{
		sum = Add_base(0,bt2[j],sign);
		bt.push_back(sum);
		j++;
	}
	if(sign > 0)//进位
	{
		bt.push_back(sign);
	}
}
void BigInt::Mul(BigInt &bt , const BigInt &bt1,const BigInt &bt2)
{
	bt.clean();
	if( bt1 == 0 || bt2 == 0)
	{
		bt = 0;
		return;
	}
	for(BigInt i = 0;i<bt2 ;++i)
	{
		bt += bt1;
	}
}
void BigInt::Mul2(BigInt &bt, const BigInt &bt1, const BigInt &bt2)
{
	BigInt tmp;
	tmp.clean();
	for(u_long i=1; i<=bt2.size(); ++i)
	{
		Mul_base(tmp, bt1, bt2[i]); // 
		//cout<<"tmp = "<<tmp<<endl;
		MoveAdd(bt, tmp, i);
		//cout<<"bt = "<<bt<<endl;
	}
}
void BigInt::Div(BigInt &bt,  BigInt &bt1, BigInt &bt2)
{
	if(bt1 < bt2)
		bt = 0;
	else if(bt1 == bt2)
		bt = 1;
	else
	{
		//BigInt div = 0;
		while(bt1 >= bt2)
		{
			++bt;
			bt1 -= bt2;
		}
	}
}
void BigInt::Div2(BigInt &bt , const BigInt &bt1,const BigInt &bt2)
{
	bt.clean();
	bt = 0; 
	if( bt1 < bt2)
		bt = 0;
	else if(bt1 == bt2)
		bt = 1;
	else
	{
		size_t bt1_len = bt1.size();
		size_t bt2_len = bt2.size();
		int k = bt1_len - bt2_len;

		BigInt btd;
		btd.clean();
		for(size_t i = 1;i<bt2.size() ; ++i)
		{
			btd.push_back(bt1[i+k]);
		}
		u_char div = 0;
		while(k >= 0)
		{
			while(btd >= bt2)
			{
				btd -= bt2;
				div++;
				btd.clear_head_zero();
			}
			bt.push_front(div);
			div = 0;
			if(k > 0)
				btd.push_front(bt1[k]);
			--k;
		}
		bt.clear_head_zero();
	}
}

/******************************************************************/
BigInt BigInt::operator-(const BigInt &bt)
{
	Tmp.clean();
	Sub(Tmp,*this,bt);
	return Tmp;
}
BigInt BigInt::operator+(const BigInt &bt)
{
	Tmp.clean();
	Add(Tmp,*this,bt);
	return Tmp;
}
BigInt BigInt:: operator=(const BigInt &bt)
{
	Add(*this,0,bt);
	//this->big = bt.big;
	return *this;
}
BigInt BigInt::operator*(const BigInt &bt)
{
	Tmp.clean();
	Mul2(Tmp , *this,bt);
	return Tmp;
}
/***************************************************************/
bool BigInt::operator >=(const BigInt &bt)const
{
	if(size() > bt.size())
		return true;
	else if(size() < bt.size())
		return false;
	else
	{
		u_long i;
		i = bt.size();
		while(i > 0)
		{
			if((*this)[i] > bt[i])
				return true;
			else if((*this)[i] < bt[i])
				return false;
			else
				return true;
			--i;
		}
	}
	return false;
}
bool BigInt::operator==(const BigInt &bt)const
{
	if(size() != bt.size())
		return false;
	else
	{
		u_long i;
		i = bt.size();
		while(i > 0)
		{
			if((*this)[i] != bt[i])
				return false;
			--i;
		}
	}
	return true;
}

BigInt BigInt::operator/( BigInt &bt)
{
	Tmp.clean();
	Div(Tmp,*this,bt);
	return Tmp;
}
BigInt& BigInt::operator=(u_long value)
{
	if(value == 0)
	{
		push_back(0);
	}
	while(value)
	{
		push_back(value % 10);
		value /= 10;
	}
	return *this;
}


bool BigInt::operator<(const BigInt &bt)const//return !(*this >= bt);
{
	if(size() < bt.size())
		return true;
	else if(size() > bt.size())
		return false;
	else
	{
		u_long i;
		i = bt.size();
		while(i > 0)
		{
			if((*this)[i] > bt[i])
				return false;
			else if((*this)[i] < bt[i])
				return true;
			--i;
		}
	}
	return false;
}

BigInt& BigInt::operator+=(const BigInt &bt)
{
	u_long i, j;
	i = j = 1;
	u_char sign = 0;
	while(i<=size() && j<=bt.size())
	{
		(*this)[i] = Add_base((*this)[i], bt[j], sign);
		++i;
		++j;
	}
	while(sign>0 && i<=size())
	{
		(*this)[i] = Add_base((*this)[i], 0, sign);
		++i;
	}
	while(j <= bt.size())
	{
		u_char sum = Add_base(0, bt[j], sign);
		push_back(sum);
		++j;
	}
	if(sign > 0)
		push_back(sign);
	return *this;
}
 BigInt&  BigInt::operator-=( BigInt &bt)
{
	u_long i, j;
	i = j = 1;
	u_char sign = 0;
	while(i<=size() && j<=bt.size())
	{
		(*this)[i] = Sub_base((*this)[i], bt[j], sign);
		++i;
		++j;
	}
	while(sign>0 && i<=size())
	{
		(*this)[i] = Sub_base((*this)[i], 0, sign);
		++i;
	}
	while(j <= bt.size())
	{
		u_char sum = Sub_base(0, bt[j], sign);
		push_back(sum);
		++j;
	}
	if(sign > 0)
		push_back(sign);
	return *this;
}
 BigInt& BigInt::operator-=(const BigInt &bt)
 {
	 assert(*this >= bt);
	 if(*this == bt)
	 {
		 *this = 0;
		 return *this;
	 }
	 else
	 {
		 u_char sign = 0;
		 size_t i = 1,j = 1; 
		 while(i <= size() && j<= bt.size())
		 {
			 (*this)[i] = Sub_base((*this)[i],bt[j],sign);
			 ++i;
			 ++j;
		 }
		 while(sign > 0 && i<=size())
		 {
			 (*this)[i] = Sub_base((*this)[i] , 0, sign);
			 ++i;
		 }
	 }
	 return *this;
 }
BigInt& BigInt::operator++()
{
	u_long i = 1;
	u_char sign = 1;

	while(sign>0 && i<=size())
	{
		(*this)[i] = Add_base((*this)[i], 0, sign);
		i++;
	}
	if(sign > 0)
		push_back(sign);
	return *this;
}