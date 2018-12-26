#include <iostream>
#include <vector>
#include <fstream>
#include <string.h>
using namespace std;

typedef struct 
{
	char ten[20];
	char sdt[11];
	char email[20],diachi[50];
	char gtinh[4];
}Contact;

void Nhapdanhba(ifstream &filein,Contact &c)
{	
	char temp[255];
	filein.getline(temp, 255);
	strcpy(c.ten,temp);
	fflush(stdin);
	
	filein.getline(temp, 255);
	strcpy(c.sdt,temp);
	fflush(stdin);
	
	filein.getline(temp, 255);
	strcpy(c.email,temp);
	fflush(stdin);
	
	filein.getline(temp, 255);
	strcpy(c.diachi,temp);
	fflush(stdin);
	
	filein.getline(temp, 255);
	strcpy(c.gtinh,temp);
	fflush(stdin);
}

void Nhapdanhba2(ifstream &filein, vector<Contact> &ds)
{
	while (filein.eof()==false)
	{
		Contact danhba;
		Nhapdanhba(filein,danhba);
		ds.push_back(danhba);
	}
}

void ThemMoi(Contact c)
{
	cout << "nhap ten: ";
	cin.getline(c.ten,20);
	cout << "nhap so dien thoai: ";
	cin.getline(c.sdt,11);
	cout << "nhap email: ";
   	cin.getline(c.email,20);
	cout << "nhap dia chi: ";
	cin.getline(c.diachi,50);
	cout << "nhap gioi tinh(Nam/Nu): ";
    cin.getline(c.gtinh,4);	
}

void xuatContact(Contact c)
{	
	cout<<"Ten: "<<c.ten<<endl;
	cout<<"Sdt: "<<c.sdt<<endl;
	cout<<"Email: "<<c.email<<endl;
	cout<<"Dc: "<<c.diachi<<endl;
	cout<<"Gt: "<<c.gtinh<<endl;

}

void copy(Contact c1,Contact c2)
{
	strcpy(c1.ten,c2.ten);
	strcpy(c1.sdt,c2.sdt);
	strcpy(c1.email,c2.email);
	strcpy(c1.diachi,c2.diachi);
	strcpy(c1.gtinh,c2.gtinh);
}

void LietKe()
{
	ifstream filein;
	filein.open("danhba.dat",ios_base::in);
	vector<Contact> dsdanhba;
	Nhapdanhba2(filein,dsdanhba);
	filein.close();
	
	for(int i=0;i<dsdanhba.size();i++)
	{
		cout<<"===========================STT: "<<i+1<<"==========================="<<endl;
		xuatContact(dsdanhba[i]);
	}
}

void ThemDB()
{
	ifstream filein;
	filein.open("danhba.dat",ios_base::in);
	vector<Contact> dsdanhba;
	Nhapdanhba2(filein,dsdanhba);
	filein.close();
	
	cout << "\nthem danh ba moi:" << endl;
	Contact tam;
	ThemMoi(tam);
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
			outfile<<dsdanhba[i].diachi<<endl;
			outfile<<dsdanhba[i].gtinh;
	}
	filein.close();
}

void SuaDB()
{
	ifstream filein;
	filein.open("D:/baithuctap/danhba.dat",ios_base::in);
	vector<Contact> dsdanhba;
	Nhapdanhba2(filein,dsdanhba);
	filein.close();
	
	int vt;
	fflush(stdin);
	cout<<"Nhap vao vi tri ban ghi"<<endl;
	cin>>vt;
	fflush(stdin);
	
	if(vt>dsdanhba.size()||vt<=0) cout<<"Khong co ban ghi";
	else
	{
		Contact tam;
		cout<<endl;
		ThemMoi(tam);
		strcpy(dsdanhba[vt].ten,tam.ten);
		strcpy(dsdanhba[vt].sdt,tam.sdt);
		strcpy(dsdanhba[vt].email,tam.email);
		strcpy(dsdanhba[vt].diachi,tam.diachi);
		strcpy(dsdanhba[vt].gtinh,tam.gtinh);
		ofstream outfile;
		   outfile.open("D:/baithuctap/danhba.dat");
		for(int i=0;i<dsdanhba.size();i++)
		{
			if(i==0) 
				outfile<<dsdanhba[i].ten<<endl;
			else
				outfile<<endl<<dsdanhba[i].ten<<endl;
				outfile<<dsdanhba[i].sdt<<endl;
				outfile<<dsdanhba[i].email<<endl;
				outfile<<dsdanhba[i].diachi<<endl;
				outfile<<dsdanhba[i].gtinh;
		}
	}
}

int main()
{
	LietKe();
	ThemDB();
}
