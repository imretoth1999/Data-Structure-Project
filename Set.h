#pragma once
#define CAPACITY 26
#include <iostream>
template <typename TElement>
class Set {
private:
	TElement * elems;
	int m;
	int hashfunction(TElement e) { return int(e[0]) % CAPACITY; }
public:
	Set();
	~Set();
	void add(TElement e);
	bool search(TElement e);
	void remove(TElement e);
	bool isEmpty();
	int size();
	TElement* getElems() { return this->elems; }
};
template <typename TElement>
class Iterator {
private:
	int currentPos;
	Set<TElement> set;
public:
	Iterator(Set<TElement> s);
	void next();
	bool valid();
	TElement getCurrent();
	int getPos() {
		return this->currentPos;
	}
};
template <typename TElement>
Set<TElement>::Set(){
	this->m = 26;
	this->elems = new TElement[this->m];
for (int i = 0; i < m; i++)
	this->elems[i] = "";
}
template <typename TElement>
Set<TElement>::~Set()
{
	//delete[] this->elems;
}
template <typename TElement>
bool Set<TElement>::search(TElement e)
{
	for (int i = 0; i < this->m; i++)
		if (this->elems[i] == e)
			return true;
	return false;
}
template <typename TElement>
void Set<TElement>::add(TElement e)
{
	if (this->search(e) == false)
	{
		int pos = hashfunction(e);
		if (this->elems[pos] == "")
			this->elems[pos] = e;
		else
		{
			int ok = 0;
			for (int i = pos; i < this->m; i++)
				if (this->elems[i] == "")
				{
					this->elems[i] = e;
					ok = 1;
					break;
				}
			if (ok == 0)
				for (int i = 0; i < pos; i++)
					if (this->elems[i] == "")
					{
						this->elems[i] = e;
						break;
					}
		}
	}
}
template <typename TElement>
void Set<TElement>::remove(TElement e)
{
		for(int i = 0;i<this->m;i++)
		if (this->elems[i] == e)
		{
			this->elems[i] = "";
			break;
		}
}
template <typename TElement>
bool Set<TElement>::isEmpty() 
{
	int k = 0;
	for (int i = 0; i < this->m; i++)
		if (this->elems[i] == "")
			k++;
	if (k == this->m)
		return true;
	return false;
}
template <typename TElement>
int Set<TElement>::size()
{
	int k = 0;
	for (int i = 0; i < this->m; i++)
		if (this->elems[i] != "")
			k++;
	return k;
}
template <typename TElement>
Iterator<TElement>::Iterator(Set<TElement> s)
{
	this->set = s;
	this->currentPos = 0;
}
template <typename TElement>
void Iterator<TElement>::next()
{
	this->currentPos++;
}
template <typename TElement>
bool Iterator<TElement>::valid()
{
	return (this->currentPos >= 0 && this->currentPos < 26);
}
template <typename TElement>
TElement Iterator<TElement>::getCurrent()
{
	if (this->valid())
	{
		int i = this->currentPos;
		return this->set.getElems()[i];
	}
}