#include <cmath>
#include <iostream>
#include <algorithm>

const int N = 1000005;
using namespace std;
double w[N]; //古董数量数组
int main()
{
	double c;
	int n;
	cout<<"请输入载重量c及古董的个数n:"<<endl;
	cin>>c>>n;
	cout<<"请输入每个古董的重量，用空格分开："<<endl;
	for(int i = 0;i < n;i++)
	{
		cin>>w[i]; //输入每个物品重量
	}
	sort(w,w+n); //按古董重量升序排序
	double temp=0.0;
	int ans = 0; //tmp为装载到船上的古董重量，ans为已经装载的古董个数
	for(int i = 0;i<n;i++)
	{
		temp+=w[i];
		if(temp<=c)
			ans++;
		else
	 	break;
	}
	cout<<"能装入的古董最大数量Ans=";
	cout<<ans<<endl;
	return 0;
}
