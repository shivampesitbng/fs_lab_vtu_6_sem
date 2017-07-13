#include<iostream>
#include<fstream>
using namespace std;
fstream f1,f2;
int c1=0,c2= 0;
string a[100],b[100];
int main(){

	string n1;
	f1.open("7a1.txt",ios::in);
	cout << "file 1 contents --> \n";
	while(f1){
	 getline(f1,n1,'\n');
	 if(n1.length() == 0)
		continue;
	 c1++;
	 a[c1]=n1;
	 cout << " "<< a[c1] << endl;
	}
	cout << "count1 -->  " << c1<<endl;
	f1.close();
	
	string n2;
	f2.open("7a2.txt",ios::in);
	cout << "file 2 contents -->\n"; 
	while(f2){
	 getline(f2,n2,'\n');
	 if(n2.length()== 0)
		continue;
	 c2++;
	 b[c2]=n2;
	 cout << " " << b[c2] <<endl;
	}
	cout << "count2 -----> " <<c2 <<endl;
	f2.close();

	//sort
	for(int i = 1;i<=c1;i++){
		for(int j=i+1;j<=c1;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	
	for(int i = 1;i<=c2;i++){
                for(int j=i+1;j<=c2;j++){
                        if(b[i]>b[j]){
                                swap(b[i],b[j]);
                        }
                }
        }
	
	//print sorted
	cout << "sorted file 1 in  buf1 ---->\n";
	for(int i =1;i <=c1 ; i++)
		cout << a[i] <<endl;

	cout << "sorted file 2 in buf2 ---->\n";
	for(int i=1;i<=c2;i++)
		cout << b[i] <<endl;

	//sim
 cout << "Matched names in both files are ----- > \n";
 for(int i = 1;i<=c1;i++){
  for(int j = 1;j<=c2;j++){
	if(a[i]==b[j]){
	    cout << a[i] << endl;
	}		
  }
 }
	return 0;
}
