#include<iostream>
#include<fstream>
using namespace std; 
string b[10], r[100]; int p[10], c = 0,  f = 0; fstream fp; //init
void fo(int); 
void fa(int);
int main(){
	for(int i =1;i<=8;i++){
		fo(i);
		fa(i);
	}
 while(f!=8){
	string m = "zzzzz";int pos;
	for(int i = 1;i<=8;i++){
		if(b[i] < m){
			m=b[i];
			pos=i;
		}
	}
	c++;
	r[c] = m;
	for(int i =1; i<=c;i++){
		if(r[i] == r[i+1]){
			c--;
		}
	}
	fo(pos);
	fa(pos);
 }
 cout <<"sorted :\n";
 for(int i =1; i<=c ; i++){
	cout << r[i] <<endl;
 }
return 0;
}
void fo(int ch){
	switch(ch){
		case 1:fp.open("81.txt",ios::in);break;
		case 2:fp.open("82.txt",ios::in);break;
		case 3:fp.open("83.txt",ios::in);break;
		case 4:fp.open("84.txt",ios::in);break;
		case 5:fp.open("85.txt",ios::in);break;
		case 6:fp.open("86.txt",ios::in);break;
		case 7:fp.open("87.txt",ios::in);break;
		case 8:fp.open("88.txt",ios::in);break;
	}
}
void fa(int ch){
	string t;
	fp.seekg(p[ch],ios::beg);
	getline(fp,t);
	p[ch]=fp.tellp();
	if(t.length() ==  0){
		b[ch] = "zzzzz";
		f++;
		return;
	}
	b[ch]=t;	
	fp.close();
}