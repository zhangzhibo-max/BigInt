#include"Seqlist.h"
#include"BigInt.h"
#include<Windows.h>
#include<time.h>
#include<string>
#include"Seqlist.h"
/*
void main()
{
	BigInt bt,bt1 (10) ,bt2(2) ;
	BigInt::Div2(bt,bt1,bt2);
	cout<<bt<<endl;
}*/
#if 1
void main()
{
	time_t start ,end ;  
    double cost;  
    time(&start);  
	BigInt bt,bt2,bt1;
	bt1.LoadData(10000);
	Sleep(100);
	bt2.LoadData(10000);
	cout<<"bt1 = "<<bt1<<endl;
	cout<<"bt2 = "<<bt2<<endl;
	//BigInt::Add(bt,bt1,bt2);
	bt = bt1 + bt2;
	cout<<"bt = "<<bt<<endl; 
    time(&end); 
	cost=difftime(end,start);  
    cout<<"程序所用的时间："<<cost<<endl; 
}
#endif
/*int main()
{

	BigInt bt,bt1 ,bt2 ;
	bt1 = 1251234345;
	bt2 = 1001342355;
	cout<<"bt1 ="<<bt1<<endl;
	cout<<"bt2 ="<<bt2<<endl;
	bt = bt1 + bt2;
	cout<<"bt  ="<<bt<<endl;
	
	return 0;
}
*/




/*
void main()
{ 
	BigInt bt,bt1 = 6,bt2 = 3;
	bt = bt1 + bt2;
	cout<<bt<<endl;
}


/*
void main()
{
	BigInt bt1 ;
	bt1.LoadData(3);
	cout<<"bt1 = "<<bt1<<endl;
	BigInt bt2 ;
	Sleep(1000);
	bt2.LoadData(3);
	cout<<"bt2 = "<<bt2<<endl;
	BigInt bt;
	BigInt::Add(bt,bt1,bt2);
//	bt = bt1 + bt2;
	cout<<"bt = "<<bt<<endl;
}






/*
void main()
{
	/*
	Seqlist<int> l1;
	for(int i = 1;i<=10;++i)
	l1.push_back(i);
	l1.showlist();

	Seqlist<int> l2;
	for(int i = 1;i<=10;++i)
	l2.push_back(i);
	l2.showlist();
	BigInt bt,bt1,bt2;
	bt1.LoadData(10);
	cout<<"bt1 =";
	bt1.ShowData();
	Sleep(1000);
	bt2.LoadData(10);
	cout<<"bt2 =";
	bt2.ShowData();

	BigInt::Add(bt,bt1,bt2);
	cout<<"bt=";
	bt.ShowData();
}
*/