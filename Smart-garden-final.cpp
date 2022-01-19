
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string>
#include <windows.h>
using namespace std;
class caytrong
{
    protected:
        string tenc;
        int cay; int gdcay;
    public:
	    caytrong()
 	    {
	        tenc = "\0";
            cay = gdcay = 0;
		}
        void tencay()
        {
        	cout << "Nhap ten cay: ";
        	cin.ignore(1);
            getline(cin, tenc);
        }
        void xuatten()
        {
        	cout << tenc;
		}
    	void loaicay()
        {
            if (cay == 1)
            {
                cout << "Rau xanh";
            }
            else if (cay == 2)
            {
                cout << "Hat cu";
            }
            else if (cay == 3)
            {
                cout << "An qua";
            }
            else if (cay == 4)
            {
                cout << "Hoa";
            }
        }
        void giaidoancay()
        {
            if (gdcay == 1)
            {
                cout << "GD nay mam";
            }
            else if (gdcay == 2)
            {
                cout << "GD ra la";
            }
            else if (gdcay == 3)
            {
                cout << "GD ra hoa";
            }
            else if (gdcay == 4)
            {
                cout << "GD ket qua";
            }
        }
        void chongdcay()
        {
        	cout << "\nChon giai doan cay";
        	int a;
        	cout << "\n1. Nay mam\n2. Ra la\n3. Ra hoa\n4. Ket qua\nNhap lua chon: ";
        	bool kt = true;
        	while (kt)
        	{
        		cin >> a;
        		if (a >= 1 && a <= 4)
        		{
        			gdcay = a;
        			kt = false;
        		}
        		else
        		{
        			cout << "\nKhong co loai nay! - Hay nhap lai: ";
        		}
        	}
        }
        void choncay()
        {
        	cout << "\nBan hay chon loai cay ban trong";
        	int n;
        	cout << "\n1. Rau xanh\n2. Hat cu\n3. An qua\n4. Lay hoa\nNhap lua chon: ";
        	bool kt = true;
        	while (kt)
        	{
        		cin >> n;
        		if (n >=1 && n <= 4)
        		{
        			cay = n;
        			kt = false;
        		}
        		else
        		{
        			cout << "\nKhong co loai nay! - Hay nhap lai: ";
        		}
        	}
        }
};
class doam
{
    protected:
        int da, daht;
    public:
        void nhap_daht()
        { cout<<"\nNhap do am hien tai: "; cin>>daht; }
        void hienthi_daht()
        {
			hienthi_da();
			cout << "\nDo am hien tai la: " << daht << "%";
            bool kt = true;
            while(kt)
			{
				if (daht < da)
            {
            	cout << "\nDo am khong du - Can tuoi nuoc";
            	kt=false;
            }else
            {
            	cout<<"\nDo am da du - Khong can tuoi nuoc";
				break;
			}
			}
        }
        void nhapda()
        {
        	cout << "\nNhap do am thich hop cua giai doan (thuong nam trong khoang 60 - 80%): ";cin>>da;	
        }
        void hienthi_da()
        {
        	cout<<"\nDo am can thiet cua gia doan nay :  "<<da<<"%";
        }
    	
};
class httuoi: public doam, public caytrong
{
	protected:
		bool stt;
		float lgn;
		float them;
	public:
		float tuoithem()
		{
			float them = (da-daht)*75;
			return them;
			}
		void hienthi_ttht()
		{
			if(daht<da)
			{
				cout<<endl<<"May hoat dong";
				cout<<endl<<"Luong nuoc can tuoi them (tang 1% do am = tuoi luong nuoc la 75 m3/ha): "<<tuoithem();
			}else
			{
				cout<<endl<<"May nghi";}
		}

		void congtacht_tuychon()
		{
			int x;
			cout << "\nBan muon bat hay tat may tuoi? - Hay chon:";
        	cout << "\n1. BAT\n2. TAT\nNhap lua chon: ";
        	bool kt = true;
        	while (kt)
        	{
        		cin >> x;
        		if (x == 1)
        		{
        			cout<<"\nMay hoat dong!\nLuong nuoc duoc tuoi la: "<<lgn;
        			stt = true;
        			kt = false;
        		}
        		else if (x == 2)
        		{
        			cout<<"\nMay nghi!";
        			stt = false;
        			kt = false;
        		}
        		else
        		{
        			cout << "\nKhong co chuc nang nay! - Hay nhap lai: ";
        		}
        	}
        
		}
		void hienthi_lgn()
		{
			cout <<"\nLuong nuoc duoc tuoi la: "<<lgn << " m3/ha";
		}
		void macdinh_lgn()
		{
			if (gdcay == 1)
            {
                lgn = 250; hienthi_lgn();
            }
            else if (gdcay == 2)
            {
                lgn = 200; hienthi_lgn();
            }
            else if (gdcay == 3)
            {
                lgn = 220;hienthi_lgn();
            }
            else if (gdcay == 4)
            {
                lgn = 170; hienthi_lgn();
            }
            else if (gdcay == 5)
            {
                lgn = 150; hienthi_lgn();
            }
		}
		void congtacht_md()//Cong tac tuoi mac dinh
		{
			int x;
			cout << "\nBan muon bat hay tat may tuoi? - Hay chon:";
        	cout << "\n1. BAT\n2. TAT\nNhap lua chon: ";
        	bool kt = true;
        	while (kt)
        	{
        		cin >> x;
        		if (x == 1)
        		{
        			cout<<"\nMay hoat dong!";
        			macdinh_lgn();
        			stt = true;
        			kt = false;
        		}
        		else if (x == 2)
        		{
        			cout<<"\nMay nghi!";
        			stt = false;
        			kt = false;
        		}
        		else
        		{
        			cout << "\nKhong co chuc nang nay! - Hay nhap lai: ";
        		}
        	}
        
		}
		void nhaplgn()
        {
        	int c;
        	float nuoc;
        	cout<<"\nBan co muon tuoi them "<<tuoithem()<<" m3/ha nuoc khong? ";
        	cout<<"\n1.Co \n2.Khong\n";
			bool kt=true;
			while(kt)
			{
				cin>>c;
				if(c==1)
        		{
				lgn=tuoithem();
				kt=false;
        		cout<<"\nLua chon thanh cong\nMay se tuoi them ";hienthi_lgn();
				cout<<"\nXin cam on!";
        		}
        		else
        			if(c==2)
        			{
					cout << "Moi ban nhap luong nuoc muon tuoi: ";cin>>nuoc;
        			lgn=nuoc;
        			hienthi_lgn();
        			kt=false;
        			}
        			else
        			{
        				cout<<"\n Lua chon khong chinh xac, moi nhap lai\n";
        			}
        	}
		}
	};
	void nhapct(httuoi& tc)
{
    tc.choncay();
    tc.tencay();
    tc.chongdcay();
    tc.nhapda();
};
	void sttht(httuoi& tc)
{
	cout << "\nLoai cay: "; tc.loaicay();
	cout << "\nTen: "; tc.xuatten();
	cout << "\nGiai doan cay: "; tc.giaidoancay();
	tc.nhap_daht();
	tc.hienthi_daht();
	tc.hienthi_ttht();
};
void tnmacdinh(httuoi& tc)
{
	cout << "\nLoai cay: "; tc.loaicay();
	cout << "\nTen: "; tc.xuatten();
	cout << "\nGiai doan cay: "; tc.giaidoancay();
	tc.congtacht_md();
}
	void tntuychon(httuoi& tc)
{
	int key;
    while (true)
    {
        system("cls");
	    cout << "\n------Thiet lap tuy chon------";
	    cout << "\n\n 1. Dieu chinh do am";
	    cout << "\n 2. Dieu chinh luong nuoc";
	    cout << "\n 3. Chay may tuoi";
	    cout << "\n 0. Quay lai";
	    cout << "\n\n----------------------------";
	    cout << "\nNhap lua chon cua ban : ";
	    cin >> key;
	    switch (key)
        {
            case 1:
		        tc.nhapda();
		        cout << "\nBam phim bat ky de tiep tuc!";
                getch();
		    break;
	        case 2:
		        tc.nhaplgn();
		        cout << "\nBam phim bat ky de tiep tuc!";
                getch();
		    break;
		    case 3:
		        tc.congtacht_tuychon();
		        cout << "\nBam phim bat ky de tiep tuc!";
                getch();
		    break;
	        case 0:
		        return;
	        default:
		        cout << "\nKhong co chuc nang nay!";
		        cout << "\nBam phim bat ky de tiep tuc!";
		        getch();
		    break;
	    }
    }
	tc.nhapda();
	tc.nhaplgn();
};
void menu_chinh(httuoi& tc)
{
    int key;
    while (true)
    {
        system("cls");
	    cout << "\n----------------MENU----------------";
	    cout << "\n\n 1. Cai dat cho lan dau su dung";
	    cout << "\n 2. Xem trang thai hien tai";
	    cout << "\n 3. Tuoi nuoc mac dinh";
	    cout << "\n 4. Tuoi nuoc tuy chon";
	    cout << "\n 0. Thoat chuong trinh";
	    cout << "\n\n------------------------------------";
	    cout << "\nNhap lua chon cua ban : ";
	    cin >> key;
	    switch (key)
        {
        	case 1:
		        nhapct(tc);
		        cout << "\nBam phim bat ky de tiep tuc!";
                getch();
		    break;
            case 2:
		        sttht(tc);
		        cout << "\nBam phim bat ky de tiep tuc!";
                getch();
		    break;
	        case 3:
		        tnmacdinh(tc);
		        cout << "\nBam phim bat ky de tiep tuc!";
                getch();
		    break;
	        case 4:
		        tntuychon(tc);
		        cout << "\nBam phim bat ky de tiep tuc!";
		        getch();
		    break;
	        case 0:
		        cout << "\nBan da chon thoat chuong trinh!";
		        getch();
		        return;
	        default:
		        cout << "\nKhong co chuc nang nay!";
		        cout << "\nBam phim bat ky de tiep tuc!";
		        getch();
		    break;
	    }
    }
};
int main()
{
	cout << "-----------WELCOME------------" << "\nHE THONG TUOI NUOC THONG MINH"<<"\n      SMART GARDEN";
	cout << "\n\nHay cai dat ban dau truoc nhe!";
	Sleep(1000);
	system("cls");
	httuoi tc;
	menu_chinh(tc);
	getch();
	return 0;
}

