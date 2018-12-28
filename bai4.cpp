#include<iostream>
#include<fstream>

using namespace std;

fstream fi;


void DocFile(int a[100][100],int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j=0;j < n;j++){
			
			fi >> a[i][j];
		}
	}	
	
}

void XuatDoThi(int a[100][100],int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j=0;j < n;j++)
			cout << a[i][j]<<"  ";
		cout<<endl;
	}
		
}

void TaoMoi(int a[100][100], int &n)
{
	cout << "nhap n: ";
	cin >> n;
	fi.open("timduong.txt", ios::out);
	fi << n <<endl;
	for(int i=0; i < n; i++)
	{
		for(int j=0; j < n; j++)
		{
			cout << "trong so "  << i << " den" << j<<": ";
			cin >> a[i][j];
			fi << a[i][j] <<" ";	
		}
		cout<<endl;
		fi << endl;	
	}
	
	fi.close();
}
int main()
{
	int n;
	int a[100][100];
	TaoMoi(a,n);
	fi.open("timduong.txt",ios::in);
	fi>>n;
	DocFile(a,n);
	XuatDoThi(a,n);
	
}
