#include <iostream>

using namespace std;

int main(){
	
	string nama;
	int umur;
	
	cout<<"Nama Anda: ";
	getline(cin, nama);
	
	cout<<"Umur Anda: ";
	cin>>umur;
	
	cout<<"Nama Anda adalah: "<<nama<<endl;
	cout<<"Anda Berumur: "<<umur<<"tahun."<<endl;
	
	return 0;
}
