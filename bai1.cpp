#include <iostream>
#include <stdio.h>
#include<conio.h>
#include <fstream>
#include <string>
#include<vector>
#include<time.h>
#include<windows.h>
#include <cstdlib>
using namespace std;

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
	ifstream filein;
	filein.open("danhba.dat",ios_base::in);
	vector<Contact> dsdanhba;
	NhapDB2(filein,dsdanhba);
	filein.close();
	
	for(int i=0;i<dsdanhba.size();i++)
	{cout<<"===========================STT: "<<i+1<<"==========================="<<endl;
	XuatDB(dsdanhba[i]);}
}

void themDB()
{
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
}

void suaDB()
{
	ifstream filein;
	filein.open("danhba.dat",ios_base::in);
	vector<Contact> dsdanhba;
	NhapDB2(filein,dsdanhba);
	filein.close();
	
	int vt;
	fflush(stdin);
	cout<<"Nhap vao vi tri ban ghi"<<endl;
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
		{if(i==0) outfile<<dsdanhba[i].ten<<endl;
		else
		outfile<<endl<<dsdanhba[i].ten<<endl;
		outfile<<dsdanhba[i].sdt<<endl;
		outfile<<dsdanhba[i].email<<endl;
		outfile<<dsdanhba[i].dc<<endl;
		outfile<<dsdanhba[i].gt;
		}
	}
}
int main()
{
	LKDB();
	suaDB();
	
}
