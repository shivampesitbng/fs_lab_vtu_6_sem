#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;
class student{ private : string usn,name,sem;
	public : void insert();void pack();// student();// ~student();
}temp;
int cnt = 0;
void end();void start();
struct index {int pos;string usn;}i1[100];fstream fp, fp2;
int  main (){
	start();
 while(1){
	cout << "1.insert 2. search 3. del : " ; int ch ; cin >> ch; switch(ch ){
		case 1:temp.insert();fp.open("5a.txt",ios::out | ios::app); temp.pack();fp.close();break; case 2:break;  case 3:break;
		 default : end();exit(0);
	}
 }
return 0;
}
void student :: insert(){
	cout << "insert - > "; cout << "n : " ; cin >> name;  cout << "s : " ; cin >> sem; cout << "u :  "; cin >>usn;
}
void student :: pack(){
	int pos = fp.tellg();string b = usn+"|"+name+"|" +sem+"|";cout << b << endl; fp << b << endl; cnt++;i1[cnt].pos=pos; i1[cnt].usn = usn;
}
void start(){
	cout << "start "; fp.open("5ac.txt",ios::in) ;if(!fp){return ;}  string r; getline(fp,r); cout<< "initial count - > "<<r; fp.close();
	stringstream cnvrt(r);
	//int x = 0;
	 cnvrt >> cnt ;
	cout <<cnt ;
	
}
void end(){
	cout << "desc"; fp.open("5ac.txt",ios::out);  fp<<cnt<<endl; fp.close();
	fp.open("5ai.txt",ios::out) ; 
	int i =0; 
	while(i<=cnt){

	}
	fp.close();
}
