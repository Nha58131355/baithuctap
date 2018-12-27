#include <iostream>
#include <string.h>
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <vector>
#include "console.h"
#include <conio.h>

using namespace std;
//------------------------------------------------------------------------------------
int inputKey()
{
	if (_kbhit())
	{
		int key = _getch();

		if (key == 224)	// special key
		{
			key = _getch();
			return key + 1000;
		}

		return key;
	}
	else
	{
		return key_none;
	}

	return key_none;
}


//-------------------------Screen-------------------------
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;                  
	HANDLE	hConsoleOut;
	COORD	Home = {0,0};
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut,&csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut,' ',csbiInfo.dwSize.X * csbiInfo.dwSize.Y,Home,&dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut,csbiInfo.dwCursorPosition);
}

void TextColor (int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE) , color);
}

void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}
//---------------------------------------------------------------------------------------------------------

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

void DocDe1()
{
	clrscr();
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
	system("pause");
}

void DocDe2()
{
	clrscr();
	ifstream f("de2.txt");
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
	system("pause");
}

void xemdiem()
{
	clrscr();
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
		system("pause");
}

void menu()
{
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                                                1: de 1  "<<endl<<endl;
    cout<<"                                                2: de 2        "<<endl<<endl;
    cout<<"                                                3: Xem diem     "<<endl<<endl;
    cout<<"                                                4: Thoat        "<<endl<<endl;
}
int main()
{
	int d=0;
	char sl;
	ShowCur(false);
	while(1)
	{
		if(d==0) goto play;	
		play:
		menu();
		sl = _getch();
		switch(sl)
		{
			case '1':
			{
				DocDe1();
				goto play;
				break;
			}
			//cac lua chon khac - cac chuc nang khac
        	case '2': 
       		{
            	DocDe2(); 
            	goto play;
           	 	break;
        	}
        	case '3':
        	{
           	 	xemdiem();
           	 	goto play;
           	 	break;
        	}
        	case '4':
        	{
          	  	goto quit; //thoat 
          	  	break;
        	}
       		default:
        	{
          	  	goto play;
          	  	break;
        	}
    	}
    	d++; //kiem tra so lan thuc hien cac truc nang
	}
	quit:
	{
  		cout<<"thoat"; //dung menu, dong und dung.
	}
	return 0;
}
