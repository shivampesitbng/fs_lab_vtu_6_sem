#include<iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
using namespace std;
class student{ //
	public:	
		string usn, name , sem ; 
		void input(); //
		void disp(); 
		void pack(); //
		void unpack();
		void modify();
}s[100],temp;
fstream fp;
void search();
void error(int );
int main(){
	while(1){
		cout << "1.Insert | 2.Search & Modify | 3.Exit :  ";
		int ch ; cin >> ch ;
		switch (ch ){
			case 1 : temp.input();
				fp.open("2.txt",ios::out | ios::app); //app -> write at end of file, overwirte  prevent
				if(!fp)
					error(1);
				temp.pack();
				fp.close();
				//cout << "insert" ;
				break;
			case 2 : search(); break;
			default : exit(0);
		}
	}
	return 0;
}
void student  ::  input(){
	cout << "insert";
	cout << " name : " ; cin >> name;
	cout << " usn : " ; cin >> usn ;
	cout << " sem : " ; cin >>sem ;
}
void error(int e){
	if(e == 1) cout << "file error ";
	if(e == 2) cout << "buf len excd";
	cout <<endl; 
}
void student :: pack(){
	string buf = usn + "|" + name + "|" + sem + "|";
	if(buf.length() > 45 ){
		error(2);
		return;
	}
	while(buf.length() < 46)
		buf+='_';
	fp << buf << endl;
}
void search (){
	string usn_srch ; cout << "Enter USN : "; cin >> usn_srch;
	fp.open("2.txt",ios::in);
	if(!fp) error(1);
	int i = 0; int srch_flag = -1;
	while(fp){
		s[i].unpack(); i++;
	}
	fp.close();
	for(int j =0 ;j <i ; j++){
		if(usn_srch == s[j].usn){
			//cout << "key found at" << j << " "  ;
			//s[j].disp();
			srch_flag = j ;
		}
	}
	s[srch_flag].disp();
	int mod_flag = -1;
	cout << "1.Modify | 2.cancel : "; cin >>  mod_flag;
	if(mod_flag){
		cout << 	"//mod";
		s[srch_flag].modify();
		fp.open("2.txt",ios::out);
		if(!fp) error(1);
		for(int z = 0; z < i-1 ; z++)
			s[z].pack();
		fp.close();
	}
}
void student :: unpack(){
	string seg;
	getline(fp,usn,'|');
	getline(fp,name,'|');
	getline(fp,sem,'|');
	getline(fp,seg);
}
void student :: disp (){
	cout << "Name : " << name  << " | USN : " << usn << " | Sem: " << sem <<endl;
}
void student :: modify(){
	while(1){
		cout << "field to mod : 1.Name | 2.USN | 3.Sem | 4.Exit ->  ";
		int ch ; cin >> ch;
		switch(ch ) {
			case 1 :cout << "new name : "; cin >> name; break;
			case 2 :cout << "new usn : "; cin >> usn ; break;		
			case 3 :cout << "new sem: ";cin >> sem;break;
			default: return; 
		}
	}
}
