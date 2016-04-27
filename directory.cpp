#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Directory{
	private:
		Directory *parent;
		vector<Directory> children;
		string name;
	public:
		Directory(string dirName, Directory *dirParent){
			this->name = dirName;
			this->parent = dirParent;
		}
		void addChild(Directory *newChild){
			this->children.push_back(*newChild);
		}
		vector<Directory> getChildren(){
			return this->children;
		}
		string getName(){
			return this->name;
		}
		Directory * getParent(){
			return this->parent;
		}
		void setName(string newName){
			this->name = newName;
		}
		void setParent(Directory *newParent){
			this->parent = newParent;
		}
};