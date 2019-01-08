#include<iostream>
#include<vector>
#include <fstream>
using namespace std;

void DocFile(int stt[], int tgsua[], int tgtra[])
{
	ifstream f;
	f.open("dsxe.txt", ios::in);
	for(int i=0; i<5; i++)
		f >> stt[i];
	for(int i=0; i<5; i++)
		f >> tgsua[i];
	for(int i=0; i<5; i++)
		f >> tgtra[i];
	f.close();
}

void XuatFile(int stt[], int tgsua[], int tgtra[])
{
	for(int i=0; i<5; i++)
		cout << stt[i] <<" ";
	cout << endl;	
	for(int i=0; i<5; i++)
		cout << tgsua[i] <<" ";
	cout << endl;	
	for(int i=0; i<5; i++)
		cout << tgtra[i] <<" ";	
	cout << endl;	
}

void SapXep(int stt[], int tgsua[], int tgtra[])
{
	for(int i=0;i<5-1;i++)
		for(int j=i+1;j<5;j++)
			if(tgtra[i]>tgtra[j])
			{
				swap(stt[i], stt[j]);
				swap(tgsua[i], tgsua[j]);
				swap(tgtra[i], tgtra[j]);	
			}
}

void dmk(int stt[], int tgsua[], int tgtra[])
{
	SapXep(stt,tgsua,tgtra);
	int tam=0;
	tam=tgsua[0];
	
	fstream f;
	f.open("kq.txt", ios::out);
	f << stt[0] << " ";
	for(int i=0;i<5;i++)	
	{
		if(tgtra[i]>=tam+tgsua[i])
			{
				tam+=tgsua[i];
				f << stt[i] << " ";
			}	
	}
}

void XuatKQ()
{
	cout << "thu tu xe sua khong qua thoi han: ";
	string s;
	ifstream f("kq.txt");
	// vong lap
	getline(f, s);
	do
	{
		cout << s << endl;
		getline(f, s);
	}while(f.eof()==false);
	f.close();
}
int main()
{
	int stt[6], tgsua[6], tgtra[6];
	DocFile(stt,tgsua,tgtra);
	XuatFile(stt,tgsua,tgtra);
	
	dmk(stt,tgsua,tgtra);
	XuatKQ();
}
