// Exercise #2 Katuuk Christian Everhard
// OBJECT ORIENTED PROGRAMMING

#include <iostream>
using namespace std;

class tollboth
{ private:
       int null,pcar,wpcar;
       float tax;
public:
       tollboth()
       {
              tax=0;
              pcar=0;
              wpcar=0;
              null=0;
       }
       void paycar(int a)
       {

       pcar=pcar+a;
       for(null;null<=pcar;null++)
       {
              tax=tax+0.50;
       }
       }
       void withoutpay(int b)
       {
       wpcar=wpcar+b;
       }
       void showdata()
       {
       cout<<"Total jumlah mobil yang membayar adalah:"<<pcar<<endl;
       cout<<"Total pajak adalah: "<<tax<<endl;
       cout<<"Total jumlah mobil yang tidak membayar : "<<wpcar<<endl;
    
       }
};
int main()
{
       tollboth tb;
       char press,input;
       int a,b;
 do{
	   
	   cout << "Tekan 1 untuk membayar pajak mobil" << endl;
       cout << "Tekan 2 untuk mobil tidak membayar pajak" << endl;
       cout << "Tekan 3 untuk total pajak dan Keluar" << endl;
       cin>>press;

       switch(press)
       {
       case '1':
              {
                     cout<<"Masukkan Jumlah mobil yang membayar pajak"<<endl;
                     cin>>a;
                     tb.paycar(a);
                     break;
              }
       case '2':
              {
                     cout<<"Masukkan jumlah mobil tidak membayar pajak"<<endl;
                     cin>>b;
                     tb.withoutpay(b);
                     break;
              }    
       }
       cout<<"Tekan Y untuk melanjutkan dan N untuk Tampilkan data"<<endl;
       cin>>input;
       }
       while(input=='y');
       tb.showdata();
    system("pause");
    return 0;
}

