#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "shell.cpp"

using namespace std;

string userInput;

vector<string> returnArgArray(string str){
	string delim = " ";
	string tempString = "";
	string curr;
	vector<string> argList;
	string::iterator it;
	for(it = str.begin(); it < str.end(); ++it){
		curr = *it;
		if(curr.compare(delim)!=0){
			tempString+=*it;
		} else{
			if(tempString.compare("")!=0){
				argList.push_back(tempString);
				tempString = "";
			}
		}
	}
	if(tempString.compare("")!=0){
		argList.push_back(tempString);
	}
	return argList;
}

int main(){
	Shell *shell = new Shell(new Directory("root", NULL));
	while(true){
		cout<<"ShellProject/"<<shell->getCurrentDirectoryName()<<"> ";
		getline(cin, userInput);
		shell->forwardCommand(returnArgArray(userInput));
	}
}