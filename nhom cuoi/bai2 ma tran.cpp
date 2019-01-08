#include <iostream>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <conio.h>
#include "console.h"

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
//---------------------------------------------------------------------------------------------------------
void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = {1, CursorVisibility};
    SetConsoleCursorInfo(handle, &cursor);
}
//---------------------------------------------------------------------------------------------------------

void Nmt(int *a, int *b, int *m, int *n)
{
	clrscr();
	cout << "nhap m hang: ";
	cin >> *m;
	cout << "nhap n cot: ";
	cin >> *n;
	cout << "ma tran thu 1: " << endl;
	for(int i=0; i<*m; i++)
	  for(int j=0; j<*n; j++)
	    {
	    	cout << "a[" << i << "][" << j << "]=";
	        cin >> *(a + i * (*n) + j);
	    }
	cout << "ma tran thu 2: "<< endl;    
	for(int i=0; i<*m; i++)
	  for(int j=0; j<*n; j++)
	    {
	    	cout << "b[" << i << "][" << j << "]=";
	        cin >> *(b + i * (*n) + j);
	    }  
	cout << "\nda luu ma tran vao file - An phim bat ki de tro lai Menu"<< endl << endl;	 
	system("pause"); 
}
//---------------------------------------------------------------------------------------------------------
void luufilein(int *a, int *b, int *m, int *n)
{
	fstream f;
	f.open("input2.txt", ios::out);
	for(int i = 0; i < *m; i++)
	{
		for(int j = 0; j < *n; j++)
			f << *(a + i * (*n) + j) << " ";
		f << endl;	
	}
	f << endl;
	for(int i = 0; i < *m; i++)
	{
		for(int j = 0; j < *n; j++)
			f << *(b + i * (*n) + j) << " ";
		f << endl;	
	}
	f.close();
}
//---------------------------------------------------------------------------------------------------------
void tong(int *a, int *b, int *c, int *m, int *n)
{
	clrscr();
	for (int i=0; i<*m; i++)
	{
        for (int j=0; j<*n; j++)
		{
            *(c + i * (*n) + j) =*(a + i * (*n) + j)+*(b + i * (*n) + j);
        }
    }
	cout << "\nda luu ket qua vao file - An phim bat ki de tro lai Menu va xem ket qua"<< endl<< endl;
    system("pause");
}
//---------------------------------------------------------------------------------------------------------
void hieu(int *a, int *b, int *c, int *m, int *n)
{
	clrscr();
	for (int i=0; i<*m; i++)
	{
        for (int j=0; j<*n; j++)
		{
            *(c + i * (*n) + j) = *(a + i * (*n) + j) - *(b + i * (*n) + j);
        }
    }
    cout << "\nda luu ket qua vao file - An phim bat ki de tro lai Menu va xem ket qua"<< endl<< endl;
    system("pause");
}
//---------------------------------------------------------------------------------------------------------
void tich(int *a, int *b, int *c, int *m, int *n)
{
	clrscr();
	int sum;
	for (int i = 0; i <= *m-1; i++) 
	{
      	for (int j = 0; j <= *n-1; j++) 
	  	{
	  		sum = 0;
        	for (int k = 0; k <= *n-1; k++) 
			{
        		sum +=  *(a + i * (*n) + k) * *(b + k * (*n) + j);
        	}
        	*(c + i * (*n) + j) = sum;
      	}
   	}
   	cout << "\nda luu ket qua vao file - An phim bat ki de tro lai Menu va xem ket qua" << endl << endl;
	system("pause");
}
//---------------------------------------------------------------------------------------------------------
void luufileout(int *a, int *m, int *n)
{
	fstream f;
	f.open("output2.txt", ios::out);
	for(int i = 0; i < *m; i++)
	{
		for(int j = 0; j < *n; j++)
			f << *(a + i * (*n) + j) << " ";
		f << endl;	
	}
	f.close();
}

void Xuatkq()
{
	clrscr();
	string s;
	ifstream f("output2.txt");
	getline(f, s);// lay so tu file input2.txt
	// vong lap
	do
	{
		cout << s << endl;
		getline(f, s);
	}while(s.compare("") != 0);// neu dong cuoi cung trong file khong co gi het thi ket thuc viet doc
	f.close();	
	cout << "\nAn phim bat ki de tro lai Menu" << endl << endl;
	system("pause");
}
//---------------------------------------------------------------------------------------------------------
void menu()
{
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                                                    M E N U:"<<endl<<endl;
    cout<<"                                                1: Nhap ma tran"<<endl<<endl;
    cout<<"                                                2: Tong ma tran"<<endl<<endl;
    cout<<"                                                3: Hieu ma tran"<<endl<<endl;
    cout<<"                                                4: Tich ma tran"<<endl<<endl;
    cout<<"                                                5: Ket qua"<<endl<<endl;
    cout<<"                                                6: Thoat"<<endl<<endl;
}
int main()
{
	int a[20][20], b[20][20], c[20][20], m, n;
	int d = 0;
	char sl; //dung de lam menu
	ShowCur(false); //an con tro

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
				Nmt((int *)a,(int *)b,&m,&n);
				luufilein((int *)a,(int *)b,&m,&n);
				goto play;
				break;
			}
			//cac lua chon khac - cac chuc nang khac
        	case '2': 
       		{
            	tong((int *)a,(int *)b,(int *)c,&m,&n); 
            	luufileout((int *)c,&m,&n);
            	goto play;
           	 	break;
        	}
        	case '3':
        	{
           	 	hieu((int *)a,(int *)b,(int *)c,&m,&n); 
            	luufileout((int *)c,&m,&n);
           	 	goto play;
           	 	break;
        	}
        	case '4':
        	{
           	 	tich((int *)a,(int *)b,(int *)c,&m,&n); 
            	luufileout((int *)c,&m,&n);
           	 	goto play;
           	 	break;
        	}
        	case '5':
        	{
           	 	Xuatkq();
           	 	goto play;
           	 	break;
        	}
        	case '6':
        	{
          	  	goto quit; //thoat meu
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
  		cout<<"thoat"; //dung menu
	}
	return 0;
	
}
