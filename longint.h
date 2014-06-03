#include <string>
#include <iostream>
#include "doublylinkedlist.h"
#include <sstream>
#include <stdlib.h>

using namespace std;

#ifndef LONGINT_H
#define LONGINT_H

class longint
{
public:
	longint();
	virtual ~longint();
	longint(string value);
	longint(doublylinkedlist data);
	int Getdigitcount();
	int Digit(int T);
	int Overflow(int T);
	char Getsign();
	void Setsign(char S);
	//string Findsign(string value);
	void initialize(string value);
	void Print();
	doublylinkedlist list();
	string Greaterthan(longint Q);
	string Lessthan(longint Q);
	string Equalto(longint Q);
	longint add(longint Q);
	longint subtract(longint Q);
	longint multiply(longint Q);
	longint divided(longint Q);
	longint power(int Q);
	int nodresult;
private:
	doublylinkedlist * newlist;
	int T;
	char sign;
	//int nodresult;
		

};	
	

#endif