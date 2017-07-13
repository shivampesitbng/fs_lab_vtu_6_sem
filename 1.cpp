#include<iostream>
#include<fstream> 
using namespace std;
string revfunc(string);
int main(){
	int n;
	string name,rev , infn, outfn;
	fstream inf , outf ;
	cout << "input file name : "; cin >> infn ;
	inf.open(infn,ios::in);
	cout << "out file name : "; cin >>outfn;
	outf.open(outfn,ios::out);
	if(!inf)
		cout << "file error!";
	if(!outf) cout <<"file2 er";
	while(inf){
		getline(inf,name);
		string r   = revfunc(name);
	outf << r << endl;
		
	}
	return 0;
} 
string revfunc(string name){
		string rev;
        rev.erase();
        for(int j = name.length()-1 ; j >=0 ; j--)
            rev+=name[j];
		cout << rev << endl;
		return rev;
}
