#include<iostream>
#include<fstream>

using namespace std;

fstream fi;


void DocFile(int a[10][10],int n)
{
	for(int i = 0; i < n; i++)
		for(int j=0;j < n;j++)
			fi >> a[i][j];
	fi.close();
}

void XuatDoThi(int a[10][10],int n)
	{
		for(int i = 0; i < n; i++)
		{
		for(int j=0;j < n;j++)
		
			cout << a[i][j]<<"  ";
			cout<<endl;
		}
	}

int main()
{
	int n;
	fi.open("timduong.txt",ios::in);
	fi>>n;
	int a[10][10];
	DocFile(a,n);
	XuatDoThi(a,n);
}
