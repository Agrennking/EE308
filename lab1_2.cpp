#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	ifstream inFile;
	string filename;
	cout<<"Please input the file name: ";
	cin>>filename;
	cout<<"Please choose the level(1,2,3,4): ";
	int level;
	cin>>level;
	inFile.open(filename.c_str());
	if(inFile.fail())
	{
		cout<<"The file was not successfully opend"<<endl;
		exit(1);
	}
	string keywords[32]={"auto", "break", "case", "char", "const", "continue",
		"default", "do", "double", "else", "enum", "extern", "float",
		"for", "foto", "if", "int", "long" , "register", "return", "short",
		"signed", "sizeof", "static", "struct", "switch", "typeof", "union",
		"unsigned", "void", "volatile", "while"};
	string code;
	vector<string> str;
	int keynum = 0;
	int swinum = 0;
	int casnum = 0;
	int ienum = 0;
	int ieinum = 0;
	int ifnum = 0;
	
	while (getline(inFile,code))
	{
		//cout << code << endl;
		int length = code.size();
		int i=0;
		while(i<length){
			if(code[i]<='z' && code[i]>='a'){
				for(int j=i ; j<length ; j++){
					if(code[j]>'z' || code[j]<'a'){
						string s = code.substr(i, j-i);
						//cout << s << endl; 
						str.push_back(s);
						for(int k=0 ; k<32 ; k++){
							if(s == keywords[k]){
								keynum++;
							}
						}
						if(s == "switch"){
							swinum++;
						}
						
						i = j+1;
					}
				}
			}
			else{
				i = i+1;
			}
		}
	}
	int len = str.size();

	
    
	int pos = 0;
	while(pos < len){
	    if(str[pos] == "if"){
			if(str[pos-1]!="else"){
				ifnum++;
			}
			for(int k=pos ; k<len ; k++){
				if(str[k] == "else"){
					if(str[k+1] == "if"){
						ieinum+=1;
					}
					else{
						ienum+=1;
					}
					pos = k+1;
				}
			
			}
		}
		pos+=1;
	}
	ieinum = ieinum - ifnum;
	ienum = ienum - ieinum;
	
	if(level == 1){
		cout <<"total num: " << keynum << endl;
	}
	else if(level == 2){
		cout << "total num: " << keynum << endl;
		cout << "switch num: " << swinum << endl;
		cout << "case num: " ;
		for(int i=0 ; i<len ; i++){
			if(str[i] == "switch"){ 
				for(int j=i+1 ; j<len ; j++){
					if(str[j] == "case"){
						casnum++;
					}
					if(str[j] == "switch"){
						cout << casnum << " ";   
						i = j;
						casnum = 0;
					}
				}
			}
		}
		cout << casnum << endl;
	}
	else if(level == 3){
		cout << "total num: " << keynum << endl;
		cout << "switch num: " << swinum << endl;
		cout << "case num: ";
		for(int i=0 ; i<len ; i++){
			if(str[i] == "switch"){ 
				for(int j=i+1 ; j<len ; j++){
					if(str[j] == "case"){
						casnum++;
					}
					if(str[j] == "switch"){
						cout << casnum << " ";   
						i = j;
						casnum = 0;
					}
				}
			}
		}
		cout << casnum << endl;
		cout << "if-else num: " << ienum<< endl;
	}
	else{
		cout << "total num: " << keynum << endl;
		cout << "switch num: " << swinum << endl;
		cout << "case num: ";
		for(int i=0 ; i<len ; i++){
			if(str[i] == "switch"){ 
				for(int j=i+1 ; j<len ; j++){
					if(str[j] == "case"){
						casnum++;
					}
					if(str[j] == "switch"){
						cout << casnum << " ";   
						i = j;
						casnum = 0;
					}
				}
			}
		}
	    cout << casnum << endl;
     	cout << "if-else num: " << ienum<< endl;
		cout << "if-elseif-else num: " << ieinum << endl;
	}
	
	
	
}
