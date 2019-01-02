#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <fstream>
#include <vector>
#include "console.h"
using namespace std;
//-------------------------------------------------------------------------------------------------------
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
	char ten[40];
	char sdt[12];
	char email[50];
	char dc[50];
	char gt[10];
}Contact;

void NhapDB(ifstream &filein,Contact &danhba)
{	
	char temp[255];
	filein.getline(temp, 255);
	strcpy(danhba.ten,temp);
	fflush(stdin);
	
	filein.getline(temp, 255);
	strcpy(danhba.sdt,temp);
	fflush(stdin);
	
	filein.getline(temp, 255);
	strcpy(danhba.email,temp);
	fflush(stdin);
	
	filein.getline(temp, 255);
	strcpy(danhba.dc,temp);
	fflush(stdin);
	
	filein.getline(temp, 255);
	strcpy(danhba.gt,temp);
	fflush(stdin);
}

void NhapDB2(ifstream &filein, vector<Contact> &ds)
{
	while (filein.eof()==false)
	{
		Contact danhba;
		NhapDB(filein,danhba);
		ds.push_back(danhba);
	}
}

void NhapDB3(Contact &danhba)
{
	cout << "nhap ten: ";
	cin.getline(danhba.ten,40);
	cout << "nhap so dien thoai: ";
	cin.getline(danhba.sdt,12);
	cout << "nhap email: ";
   	cin.getline(danhba.email,50);
	cout << "nhap dia chi: ";
	cin.getline(danhba.dc,50);
	cout << "nhap gioi tinh(Nam/Nu): ";
    cin.getline(danhba.gt,10);
}

void XuatDB(Contact danhba)
{
	cout<<"Ten: "<<danhba.ten<<endl;
	cout<<"Sdt: "<<danhba.sdt<<endl;
	cout<<"Email: "<<danhba.email<<endl;
	cout<<"Dc: "<<danhba.dc<<endl;
	cout<<"GT: "<<danhba.gt<<endl;
}

void copy(Contact danhba1,Contact danhba2)
{
	strcpy(danhba1.ten,danhba2.ten);
	strcpy(danhba1.sdt,danhba2.sdt);
	strcpy(danhba1.email,danhba2.email);
	strcpy(danhba1.dc,danhba2.dc);
	strcpy(danhba1.gt,danhba2.gt);
}

void LKDB()
{
	clrscr();

	ifstream filein;
	filein.open("danhba.dat",ios_base::in);
	vector<Contact> dsdanhba;
	NhapDB2(filein,dsdanhba);
	filein.close();
		
	for(int i=0;i<dsdanhba.size();i++)
	{
		cout<<"-------------------------------STT: "<<i+1<<"-------------------------------"<<endl;
		XuatDB(dsdanhba[i]);
	}
	system("pause");
}

void themDB()
{
	clrscr();
	ifstream filein;
	filein.open("danhba.dat",ios_base::in);
	vector<Contact> dsdanhba;
	NhapDB2(filein,dsdanhba);
	filein.close();
	
	Contact tam;
	NhapDB3(tam);
	dsdanhba.push_back(tam);
	ofstream outfile;
	   outfile.open("danhba.dat");
	for(int i=0;i<dsdanhba.size();i++)
	{
		if(i==0) 
			outfile<<dsdanhba[i].ten<<endl;
		else
			outfile<<endl<<dsdanhba[i].ten<<endl;
			outfile<<dsdanhba[i].sdt<<endl;
			outfile<<dsdanhba[i].email<<endl;
			outfile<<dsdanhba[i].dc<<endl;
			outfile<<dsdanhba[i].gt;
	}
	cout << "xoa thanh cong" << endl;
	system("pause");
}

void suaDB()
{
	clrscr();
	ifstream filein;
	filein.open("danhba.dat",ios_base::in);
	vector<Contact> dsdanhba;
	NhapDB2(filein,dsdanhba);
	filein.close();
	
	int vt;
	fflush(stdin);
	cout<<"Nhap vao vi tri ban ghi: "<<endl;
	cin>>vt;
	vt--;
	fflush(stdin);
	Contact tam;
	cout<<endl;
	if(vt>dsdanhba.size()||vt<=0) cout<<"Khong co ban ghi";
	else
	{
		NhapDB3(tam);
		strcpy(dsdanhba[vt].ten,tam.ten);
		strcpy(dsdanhba[vt].sdt,tam.sdt);
		strcpy(dsdanhba[vt].email,tam.email);
		strcpy(dsdanhba[vt].dc,tam.dc);
		strcpy(dsdanhba[vt].gt,tam.gt);
		ofstream outfile;
		   outfile.open("danhba.dat");
		for(int i=0;i<dsdanhba.size();i++)
		{
			if(i==0) 
				outfile<<dsdanhba[i].ten<<endl;
			else
				outfile<<endl<<dsdanhba[i].ten<<endl;
				outfile<<dsdanhba[i].sdt<<endl;
				outfile<<dsdanhba[i].email<<endl;
				outfile<<dsdanhba[i].dc<<endl;
				outfile<<dsdanhba[i].gt;
		}
	}
	cout << "sua thanh cong" << endl;
	system("pause");
}

void xoaDB()
{
	clrscr();
	ifstream filein;
	filein.open("danhba.dat",ios_base::in);
	vector<Contact> dsdanhba;
	NhapDB2(filein,dsdanhba);
	filein.close();
	
	int vt;
	fflush(stdin);
	cout<<"Nhap vao vi tri ban ghi muon xoa: "<<endl;
	cin>>vt;
	fflush(stdin);
	vt--;
	
	dsdanhba.erase(dsdanhba.begin()+vt);
	ofstream outfile;
	   outfile.open("danhba.dat");
	for(int i=0;i<dsdanhba.size();i++)
	{
		if(i==0) 
			outfile<<dsdanhba[i].ten<<endl;
		else
			outfile<<endl<<dsdanhba[i].ten<<endl;
			outfile<<dsdanhba[i].sdt<<endl;
			outfile<<dsdanhba[i].email<<endl;
			outfile<<dsdanhba[i].dc<<endl;
			outfile<<dsdanhba[i].gt;
	}
	cout << "xoa thanh cong" << endl;
	system("pause");
}

void TimKiem()
{
	clrscr();
	ifstream filein;
	filein.open("danhba.dat",ios_base::in);
	vector<Contact> dsdanhba;		
	NhapDB2(filein,dsdanhba);
	filein.close();
		
	char temp2[255],*s;
	printf("Nhap ten can tim kiem: ");
	gets(temp2);
	for(int i=0;i<dsdanhba.size();i++)
	{
		s=strstr(dsdanhba[i].ten,temp2);
		if(s!=NULL) 
		{
			cout<<"-------------------------------STT: "<<i+1<<"-------------------------------"<<endl;
			XuatDB(dsdanhba[i]);
		}
	}
	system("pause");	
    	
}

void menu()
{
	clrscr();
	TextColor(12);
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"                                                    M E N U:    "<<endl<<endl;
	TextColor(14);
    cout<<"                                                1: Liet ke danh ba  "<<endl<<endl;
    cout<<"                                                2: Them danh ba        "<<endl<<endl;
    cout<<"                                                3: Sua danh ba     "<<endl<<endl;
    cout<<"                                                4: Xoa danh ba     "<<endl<<endl;
    cout<<"                                                5: Tim kiem     "<<endl<<endl;
    cout<<"                                                6: Thoat        "<<endl<<endl;
    TextColor(7);
}

int main()
{
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
				LKDB();
				goto play;
				break;
			}
			//cac lua chon khac - cac chuc nang khac
        	case '2': 
       		{
            	themDB(); 
            	goto play;
           	 	break;
        	}
        	case '3':
        	{
           	 	suaDB();
           	 	goto play;
           	 	break;
        	}
        	case '4':
        	{
           	 	xoaDB();
           	 	goto play;
           	 	break;
        	}
        	case '5':
        	{
           	 	TimKiem();
           	 	goto play;
           	 	break;
        	}
        	case '6':
        	{
          	  	goto quit; //thoat danh ba
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
