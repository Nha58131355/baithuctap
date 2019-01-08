#include<iostream>
#include<string.h>
#include<vector>
#include<fstream>
#include<stdlib.h>
using namespace std;


ifstream f1("nhanvienvp.txt");
ifstream f2("nhanviensx.txt");
const int dinhmucvang=7, giaphat=50000;
const int DinhMucsp=100, DonGiasp=10000;
class NhanVien
{
	public:
	string hten;
	int gt, namvaolam, socon, luongCb;
	float hsluong;
		
	int thuong()
	{
		int sonamlv = 2019 - namvaolam;
		return sonamlv * 1000000;
	}
	
	void nhapNV()
	{
		cout << "nhap ten: ";
		getline(std::cin,hten);
		fflush(stdin);
		cout << "nhap gioi tinh(1/0): ";
		cin >> gt;
		fflush(stdin);
		cout << "nhap nam vao lam: ";
	   	cin >> namvaolam;
	   	fflush(stdin);
		cout << "nhap he so luong: ";
		cin >> hsluong;
		fflush(stdin);
		cout << "nhap so con: ";
	    cin >> socon;
	    fflush(stdin);
	    cout << "nhap luong co ban: ";
	    cin >> luongCb;
	    fflush(stdin);
	    
	}
		
	void xuatNV()
	{
		cout << "---------------------------------" << endl;
		cout << "ho va ten: " << hten << endl;
		if(gt==0)
			cout << "goi tinh: nu"  << endl;
		else
			cout << "goi tinh: nam"  << endl;	
		cout << "nam vao lam: " << namvaolam << endl;
		cout << "he so luong: " << hsluong << endl;
		cout << "so con: " << socon << endl;
		cout << "luong co ban: " << luongCb << endl;
		cout << "tien thuong theo nam: " << thuong() << endl;
	}
};

class NhanVienVP:public NhanVien
{
	
	
	public:
		int ngayvang; 
	
	void Nhap()
	{
		NhanVien::nhapNV();
		cout << "nhap so ngay vang: ";
		cin >> ngayvang;
	}
	
	void Nhapvp()
	{
		string s;
		getline(f1,s); hten = s;
		getline(f1,s); gt = atoi(s.c_str());
		getline(f1,s); namvaolam = atoi(s.c_str());
		getline(f1,s); hsluong = atoi(s.c_str());
		getline(f1,s); socon = atoi(s.c_str());
		getline(f1,s); luongCb = atoi(s.c_str());
		getline(f1,s); ngayvang = atoi(s.c_str());	
	}	
	
	int phat()
	{
		if(ngayvang > dinhmucvang)
			return ngayvang * giaphat;
		else
			return 0;	
	}
	
	int trocap()
	{
		if(gt==0)
			return 200000*socon*1.5;
		else
			return 200000*socon;	
	}
	
	int luong()
	{
		return luongCb*hsluong-phat();
	}
	
	void Xuatvp()
	{
		NhanVien::xuatNV();
		cout << "So ngay vang: " << ngayvang << endl;
		if(phat()!=0)
			cout << "tien phat: " << phat() << endl;
		if(trocap()!=0)	
		cout << "tro cap: " << trocap() << endl;
		cout << "tien luong: " << luong()	<< endl << endl;
	}
	
	
	
};

class NhanVienSX:public NhanVien
{
	
	
	public:
		int sosanpham;
		
	void Nhap()
	{
		NhanVien::nhapNV();
		cout << "nhap so san pham: ";
		cin >> sosanpham;
	}
	
	void Nhapsx()
	{
		string s;
		getline(f2,s); hten = s;
		getline(f2,s); gt = atoi(s.c_str());
		getline(f2,s); namvaolam = atoi(s.c_str());
		getline(f2,s); hsluong = atoi(s.c_str());
		getline(f2,s); socon = atoi(s.c_str());
		getline(f2,s); luongCb = atoi(s.c_str());
		getline(f2, s); sosanpham = atoi(s.c_str());
			
	}	
	
	int thuong()
	{
		if(sosanpham > DinhMucsp)
			return (sosanpham-DinhMucsp) * DonGiasp * 0.03;
		else
			return 0;	
	}
	
	int trocap()
	{
		return socon*120000;
	}
	
	int luong()
	{
		return (sosanpham*DonGiasp) + thuong();
	}	
	
	void Xuatsx()
	{
		NhanVien::xuatNV();
		cout << "So san pham: " << sosanpham << endl;
		if(thuong()!=0)	
			cout << "tien thuong theo san pham: " << thuong() << endl;
		if(trocap()!=0)	
			cout << "tro cap: " << trocap() << endl;	
		cout << "tien luong: " << luong() << endl << endl;	
	}	
	
	
	
};

class DSVP
{
	int n; 
	vector<NhanVienVP> dsvp;
	public:
		
		
	void NhapDSvp() 
	{	
	
		if (f1.fail())
			cout << "Failed to open this file!" << endl;
		else 
		{	
			string s;
			getline(f1, s); n = atoi(s.c_str()); 
			dsvp.resize(n); 		
			for (int i = 0; i < dsvp.size(); i++) 
			{
				dsvp[i].Nhapvp();
			}
		}
		f1.close();
						
	}
	
	void XuatDSvp() 
	{
		for (int i = 0; i < dsvp.size(); i++) 
		{
			dsvp[i].Xuatvp();
		}
	}	
	
	void them()
	{
		string s;
		getline(f1, s); n = atoi(s.c_str()); 
		dsvp.resize(n); 
		
		NhanVienVP tam;
		tam.Nhap();
		ofstream f;
	   		f.open("nhanvienvp.txt");
	   	for(int i=0;i<dsvp.size();i++)
		{
			if(i==0) 
				f<<dsvp[i].hten<<endl;
			else
				f<<endl<<dsvp[i].hten<<endl;
				f<<dsvp[i].gt<<endl;
				f<<dsvp[i].namvaolam<<endl;
				f<<dsvp[i].hsluong<<endl;
				f<<dsvp[i].socon<<endl;
				f<<dsvp[i].luongCb<<endl;
				f<<dsvp[i].ngayvang;
		}	
	   		
	}
};

class DSSX
{
	int n; 
	vector<NhanVienSX> dssx;
	public:
		
		
	void NhapDSsx() 
	{	
	
		if (f2.fail())
			cout << "Failed to open this file!" << endl;
		else 
		{	
			string s;
			getline(f2, s); n = atoi(s.c_str()); 
			dssx.resize(n); 		
			for (int i = 0; i < dssx.size(); i++) 
			{
				dssx[i].Nhapsx();
			}
		}
		f2.close();
						
	}
	
	void XuatDSsx() 
	{
		for (int i = 0; i < dssx.size(); i++) 
		{
			dssx[i].Xuatsx();
		}
	}
	
	void them()
	{
		string s;
		getline(f2, s); n = atoi(s.c_str()); 
		dssx.resize(n); 
		
		NhanVienVP tam;
		tam.Nhap();
		dssx.push_back(tam);
		ofstream f;
	   	f.open("nhanviensx.txt");
	   	for(int i=0;i<dssx.size();i++)
		{
			if(i==0) 
				f<<dssx[i].hten<<endl;
			else
				f<<endl<<dssx[i].hten<<endl;
				f<<dssx[i].gt<<endl;
				f<<dssx[i].namvaolam<<endl;
				f<<dssx[i].hsluong<<endl;
				f<<dssx[i].socon<<endl;
				f<<dssx[i].luongCb<<endl;
				f<<dssx[i].sosanpham;
		}	
	   		
	}	
};
int main()
{
	DSSX sx;
	sx.NhapDSsx();
	sx.XuatDSsx();
	sx.them();
}
