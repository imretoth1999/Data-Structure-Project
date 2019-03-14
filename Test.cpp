#include "Test.h"
#include <string>
#include "Set.h"
#include <assert.h>
using namespace std;
void Test::testAdd()
{
	Set<string> s;

	assert(s.size() == 0);
	assert(s.isEmpty() == 1);
	s.add("DA");
	assert(s.size() == 1);
	s.add("DA");
	assert(s.size() == 1);
	s.add("DU");
	assert(s.size() == 2);
	s.add("Ma");
	assert(s.size() == 3);
	assert(s.isEmpty() == 0);
	s.add("Me");
	assert(s.size() == 4);
	s.add("M1");
	s.add("M2");
	s.add("M3");
	s.add("M4");
	s.add("M5");
	s.add("M6");
	s.add("M7");
	s.add("M8");
	s.add("M9");
	s.add("M10");
	s.add("M11");
	s.add("M12");
	s.add("M13");
	s.add("M14");
	s.add("M15");
	s.add("M16");
	s.add("M17");
	s.add("M18");
	s.add("M19");
	s.add("M20");
	s.add("M21");
	s.add("M22");
	assert(s.size() == 26);
}

void Test::testSearch()
{
	Set<string> s;
	s.add("DA");
	assert(s.search("DA") == true);
	assert(s.search("NU") == false);
}

void Test::testRemove()
{
	Set<string> s;
	s.add("DA");
	s.add("NU");
	s.remove("DA");
	assert(s.size() == 1);
	s.remove("DA");
	assert(s.size() == 1);
	s.remove("NU");
	assert(s.size() == 0);
}
void Test::testIterator()
{
	Set<string> s;
	s.add("NA");
	s.add("NU");
	Iterator<string> i{ s };
	assert(i.valid() == 1);
	assert(i.getCurrent() == "NA");
	i.next();
	assert(i.getCurrent() != "NA");
	assert(i.getCurrent() == "NU");
	for (int w = 0; w < 25; w++)
		i.next();
	assert(i.valid() == 0);
	
}

void Test::testAll()
{
	this->testAdd();
	this->testRemove();
	this->testSearch();
	this->testIterator();
}

