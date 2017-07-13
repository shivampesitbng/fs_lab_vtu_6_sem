#include<iostream>
#include<fstream>
using namespace std;
class student {
	public: string name,usn,sem;
		void insert();
		void pack();
		void unpack();
		void mod();
}s[100],temp;
void search();
void error(int);
fstream fp;
int main(){
   while(1){
	cout << "1.insert 2.search & mod  3.exit : ";
	int ch ;cin >> ch ;
	switch (ch){
		case 1:temp.insert();
			fp.open("3.txt",ios::out | ios::app);
			  if(!fp){}
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
	cout <<"s"; int i = 0;int f = -1;
	fp.open("3.txt",ios::in);
	  if(!fp){}
	  while(fp){ s[i].unpack();i++;}
	//  for(int z = 0;z<i;z++){ cout << s[z].usn;}
	  string u; cout << "u : " ; cin >> u;
	  for(int j=0;j<i;j++) { if(u == s[j].usn) {f=j;break; } }
	  if(f==-1){cout << "not f";return ;}
	  cout << s[f].usn << s[f].name << s[f].sem;
	fp.close();
	fp.open("3.txt",ios::out);
	  s[f].mod();
          for(int z = 0; z<i-1;z++){ s[z].pack();}
	fp.close();
}
void student :: insert(){
	cout << "i";
	cout << "n : " ;cin >> name; cout << "u : " ;cin >> usn ; cout << "s : " ; cin >>sem; 
}
void student :: pack(){
	string b = usn + "|" + name + "|" + sem +"|";
	//if(b.length() > 45) {error(1);return ;}
	//while(b.length() <46) b+='_';
	fp << b <<endl;
}
void error(int e){
	if(e ==1) cout << "lim exced len error";
}
void student :: unpack(){
	string r;
	getline(fp,usn,'|');
	getline(fp,name,'|');
	getline(fp,sem,'|');
	getline(fp,r);
}
void student :: mod(){
	while(1){
		cout << "1.nam 2.usn 3.se 4.ex : ";
		int ch ; cin >>ch;
		switch (ch){
			case 1:cout << " n n : " ; cin >> name;break;
			case 2:cout << " n u  : "; cin >>usn;  break;
			case 3:cout << " n s : " ; cin >>sem;break;
			default :return;
		}
	}
}
