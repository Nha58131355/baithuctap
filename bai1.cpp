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
	char gtinh[3];
}Contact;

//them moi contact vao dl
//them vao du lieu
//ghi du lieu vao file
void ThemMoi(Contact c)
{
	cout << "nhap ten: ";
	cin.getline(c.ten, 20);
	cout << "nhap sdt: ";
	cin.getline(c.sdt,11);
	cout << "nhap email: ";
	cin.getline(c.email,20);
	cout << "nhap dia chi: ";
	cin.getline(c.diachi,50);
	cout << "nhap gioi tinh(Nam/Nu): ";
	cin.getline(c.gtinh,3);
}

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

void xuatContact(Contact c)
{	
	cout<<"Ten: "<<c.ten<<endl;
	cout<<"Sdt: "<<c.sdt<<endl;
	cout<<"Email: "<<c.email<<endl;
	cout<<"Dc: "<<c.diachi<<endl;
	cout<<"Gt: "<<c.gtinh<<endl;

}


int main()
{
	ifstream filein;
	filein.open("D:/baithuctap/danhba.txt",ios_base::in);
	vector<Contact> dsdanhba;
	Nhapdanhba2(filein,dsdanhba);
	filein.close();
	for(int i=0;i<dsdanhba.size();i++)
	{cout<<"===========================STT: "<<i+1<<"==========================="<<endl;
		xuatContact(dsdanhba[i]);
	}
}
