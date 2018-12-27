#include <iostream>
#include <string.h>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef struct 
{
	string cauhoi;
	string A,B,C;
	string da;	
}CauHoi;

vector<CauHoi> dscau;

bool KiemTra (string A,string B)
{
	if(A.compare(B)==0)//ham so sanh chuoi string
	 return true;
	else
		return false; 
}

void luudiem(string ten, int diem)
{	
	fstream f;
	f.open("luudiem.txt", ios::out | ios::app); // ios::out mo file de ghi, ios::app kg ghi de
	f << ten << "\t" << diem << endl;
	f.close();
}

void DocDe()
{
	ifstream f("de1.txt");
	int sl,diem=0;
	string s,da,ten;
	CauHoi bd1;
	getline(f,s);
	sl=atoi(s.c_str()); //doi string sang int
	for(int i=0; i<sl; i++) //xuat cau hoi
	{
		getline(f,s); bd1.cauhoi=s; cout <<s<< endl;
		getline(f,s); bd1.A=s; cout << s << endl;
		getline(f,s); bd1.B=s; cout << s << endl;
		getline(f,s); bd1.C=s; cout << s << endl;
		getline(f,s); bd1.da=s;
		cout << "dap an: ";
		getline(cin,da);
		if(KiemTra(bd1.da,da) == true)
			diem+=2;	
		dscau.push_back(bd1);
	}
	cout << "diem: " << diem << endl;
	fflush(stdin);
	cout << "nhap ten: ";
	fflush(stdin); // xoa bo nho dem
	getline(cin,ten);
	luudiem(ten,diem);
}

void xemdiem()
{
	string s;
		ifstream f3("luudiem.txt");
		// vong lap
		getline(f3, s);// lay ten va diem tu file luudiem
		do
		{
			cout << s << endl;
			getline(f3, s);
		}while(s.compare("") != 0);// neu dong cuoi cung trong file txt khong co gi het thi ket thuc viet doc
		f3.close();
}


int main()
{
	DocDe();
	xemdiem();
}
