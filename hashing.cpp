#include<iostream>
#include<fstream>
using namespace std;
class student {
	public:  string usn,name,sem ;
		void  insert();
		void pack();
		void unpack();
		void display();
}temp,temp3;
fstream fp,fp2;
int hash2(string);
void ret();
int main(){
	int ch;
	fp.open("h10.txt",ios::out | ios::app);
	fp.close();
	while(1){
	 cout << "1.insert | 2.retriev | 3.exit : ";
	 cin >>ch;
	 switch(ch){
		case 1: temp.insert();
			fp.open("h10.txt",ios::out | ios::in);
			 temp.pack();
			fp.close();
			break;
		case 2:ret();break;
		default : exit(0);
	 }
	}
return 0;
}
void student :: insert(){
	cout << "usn , name , sem  : ";
	cin >> usn >> name >> sem ;
}
void student :: pack(){
	string b =  usn +"|" +name +"|" + sem  + "|" ;
	if(b.length() > 45 ){
		cout << "length ERROR!" <<endl;
		return ;
	}
	while( b.length()  < 46){
		b+='_';
	}

	int pos = hash2(usn);

	int p2 =fp.tellg(); cout << "p2:" <<p2 <<endl;
	fp.seekg(pos,ios::beg);
	int p3 =fp.tellg(); cout << "p3:" <<p3 <<endl;
	 string temp; getline(fp,temp);  cout <<"temp - > " <<temp <<endl;
	 	int c = temp[0]-48; cout << "c: " << c <<endl;
	 int p4 =fp.tellg(); cout << "p4:" <<p4 <<endl;
fp.close();

fp.open("h10.txt",ios::in|ios::out);
if(c<0){
		fp.seekg(pos,ios::beg);
		fp.put('1');
		pos = pos+1;
}
if(c==1){
	fp.seekg(pos,ios::beg);
	fp.put('2');
	pos = pos + 48;
}
if(c==2){
	cout << "hashing error!" <<endl;
	return;
}
fp.close();


	//write into file
	fp.open("h10.txt",ios::in|ios::out);

	fp.seekg(pos,ios::beg);
	int p1 =fp.tellg(); cout << "p1:" <<p1 <<endl;
	fp<< b <<endl;
	cout<< "wriiten this in file : " << b << " at pos: "<<pos<<endl;
}
int hash2(string u){
	int t = ((u[0]-48)*100 + (u[1]-48)*10 + u[2]-48)%9;
	return t*142;
}
void ret(){
		string us;int f=0;
	cout << "usn : " ;
	cin >> us;
		int pos=hash2(us);
		fp.open("h10.txt",ios::in);
			fp.seekg(pos,ios::beg); cout <<"pos r: " << pos << endl;
			 string t; getline(fp,t); cout << "t --> " << t<<endl;
			 int c =t[0]-48;
			 fp.seekg(pos+1,ios::beg);
			 for(int i =1;i<=c;i++){
				 	temp3.unpack();
				 if(us==temp3.usn){
					 temp3.display(); f=1;
				 }
			 }
		fp.close();
		if(f==0)
			cout<<"nf"<<endl;
}
void student :: unpack(){
	string r;
	getline(fp,usn,'|');
	getline(fp,name,'|');
	getline(fp,sem,'|');
	getline(fp,r);
}
void student :: display(){
	cout << name << " | "<<usn << " | "<<sem<<endl ;
}
