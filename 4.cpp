#include<iostream>
#include<fstream>
using namespace std;
class student {
	private : string name,usn,sem;
	public : void insert(); 	
		void display();
		void pack();
		void unpack(int);
}temp;
//void insert();
void search();
void rrn_v();
fstream fp;
int rrn[100] ; int cnt = 0;
int main(){
 rrn_v();
 while(1){
	int ch;
	cout << "1.insert 2.search 3.exit : ";	cin >> ch;
	switch (ch){
		case 1:temp.insert();
			temp.display();
			fp.open("4d.txt",ios::out | ios::app);
			 temp.pack();
			fp.close();		
			break;
		case 2:search();break;
		default : exit(0);
	}
 }
	return 0;
}
void search(){
	cout << "s";
	cout << "rrn : " ; int ri ; cin >> ri;
	if(ri > cnt || ri < 1){cout << "out of range";return ;}
	int pos  = rrn[ri];
	fp.open("4d.txt",ios::in);
	 temp.unpack(pos);
	 temp.display();
	fp.close();
}
void student ::  insert(){
	cout << "i";
	cout << " n : "; cin >> name ;cout << " u : " ; cin >> usn ; cout << "s : ";cin >> sem;
}
void student :: display(){
	cout << name << usn << sem ;
}
void student :: pack(){
	int pos  = fp.tellg();
	string b = name + "|" + sem + "|" + usn + "|"; cout << b <<endl; fp << b << endl;  
	rrn[++cnt] = pos; cout << pos;
}
void student :: unpack(int pos){
	fp.seekg(pos, ios::beg);getline(fp,name,'|');getline(fp,sem,'|');getline(fp,usn,'|');
}
void rrn_v(){
	cout << "//";
	fp.open("4d.txt",ios::in); 
	while(fp){
	 int pos = fp.tellg(); cout << pos << "$";
	 string r ; getline(fp,r); 
	 if(r.length() == 0 ) break; 
	 rrn[++cnt] = pos; cout << rrn[cnt] << "*";
	}
	fp.close();
}
