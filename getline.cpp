#include <iostream>

using namespace std;

int main(){
	
	char nama[20];
	
	cout<<"Nama Anda: ";
	cin.getline(nama, sizeof(nama) - 1);
	
	cout<<"Nama Anda adalah: "<<nama<<endl;
	
	return 0;
}
