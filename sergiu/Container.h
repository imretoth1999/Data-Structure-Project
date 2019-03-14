#pragma once
#include <string>
using namespace std;
class Container {
private:
	string name;
public:
	Container(string s) {
		this->name = s;
	}
	int hashCode() { return int(name[0]); }
	string getName() { return this->name; }
};