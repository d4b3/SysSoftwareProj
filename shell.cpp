#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "directory.cpp"

using namespace std;

class Shell{
	private:
		Directory *rootDirectory;
		Directory *currentDirectory;
		void exitCommand(){
			cout<<"Bye!"<<endl;
			exit(0);
		}
		void helpCommand(){
			cout<<endl<<"List of Commands:"<<endl<<endl;
			cout<<"cd <dirname> - Changes the current working directory"<<endl<<endl;
			cout<<"exit - Exits the program"<<endl<<endl;
			cout<<"help - Displays a list of commands"<<endl<<endl;
			cout<<"ls - Displays the contents of the current directory"<<endl<<endl;
			cout<<"mkdir <dirname> - Creates a new directory"<<endl<<endl;
			cout<<"mkfile <filename> - Creates a new file"<<endl<<endl;
			cout<<"mkfs - Creates a new file system, deleting the current one"<<endl<<endl;
			cout<<"rmdir <dirname> - Removes a directory"<<endl<<endl;
			cout<<"rmfile <filename> - Removes a file"<<endl<<endl;
			cout<<"stats <name> - Show the status of the given file or directory"<<endl<<endl;
		}
		void lsCommand(){
			list<string> childList;
			vector<Directory> currChildren = this->currentDirectory->getChildren();
			vector<Directory>::iterator it;
			for(it = currChildren.begin(); it < currChildren.end(); ++it){
				childList.push_back(it->getName());
			}
			childList.sort();
			list<string>::const_iterator lit;
			for(lit = childList.begin(); lit != childList.end(); ++lit){
				cout<<lit->c_str()<<"/"<<endl;
			}
		}
		void mkdirCommand(string dirName){
			vector<Directory> currChildren = this->currentDirectory->getChildren();
			vector<Directory>::iterator it;
			for(it = currChildren.begin(); it < currChildren.end(); ++it){
				if(strToUpper(it->getName()).compare(strToUpper(dirName))==0){
					cout<<"That directory already exists."<<endl;
					return;
				}
			}
			this->currentDirectory->addChild(new Directory(dirName, this->currentDirectory));
		}
	public:
		Shell(Directory *rootDirectory){
			this->rootDirectory = rootDirectory;
			this->currentDirectory = rootDirectory;
		}
		void forwardCommand(vector<string> commandArguments){
			string commandName;
			if(commandArguments.size() > 0){
				vector<string>::iterator it = commandArguments.begin();
				commandName = *it;
				if(commandName.compare("exit")==0){
					exitCommand();
					return;
				}
				if(commandName.compare("help")==0){
					helpCommand();
					return;
				}
				if(commandName.compare("ls")==0){
					lsCommand();
					return;
				}
				if(commandName.compare("mkdir")==0){
					++it;
					if(it != commandArguments.end()){
						string newDirName = *it;
						++it;
						if(it == commandArguments.end()){
							mkdirCommand(newDirName);
						} else{
							cout<<"Too many arguments given. Usage: mkdir <dirname>"<<endl;
						}
					} else{
						cout<<"No arguments given. Usage: mkdir <dirname>"<<endl;
					}
					return;
				}
				cout<<"Command '"<<commandName<<"' not recognized. Type 'help' for a list of valid commands."<<endl;
			} else{
				return;
			}
		}
		string getCurrentDirectoryName(){
			Directory * currDir = this->currentDirectory;
			string currDirName = currDir->getName();
			while(currDir->getParent()!=NULL){
				currDirName = currDir->getParent()->getName() + "/" + currDirName;
			}
			return currDirName;
		}
		Directory * getCurrentDirectory(){
			return this->currentDirectory;
		}
		Directory * getRoot(){
			return this->rootDirectory;
		}
		string strToUpper(string s){
			string::iterator it;
			for(it = s.begin(); it < s.end(); ++it){
				*it = toupper(*it);
			}
			return s;
		}
};