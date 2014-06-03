#include <string.h>
#include <stdlib.h>
#include "longint.h"


longint::longint(){
	newlist = new doublylinkedlist;
	int nodresult = 0;
	Setsign('+');
}

longint::longint(string value){	
	newlist = new doublylinkedlist;
	int nodresult = 0;
	initialize(value);
}

//for creating a new longint for math purposes, using a copied list.
longint::longint(doublylinkedlist data){
	int nodresult = 0;	
	newlist = new doublylinkedlist;

struct Node* temp;
temp = data.GetLast();

newlist->insertFront(data.getValue(temp));
temp = data.nextLeft(temp);

	//newlist->isLast(temp->prev) != 1
	//newlist->getValue(temp)
	//cout<<data.getValue(temp)<< '\n';
	while( data.getValue(temp) != -1){
	newlist->insertFront(data.getValue(temp));
	temp = data.nextLeft(temp);
	}
	Setsign('+');
}

longint::~longint(){
	newlist = NULL;
	delete newlist;
}

void longint::Setsign(char S){
	sign = S;
}

char longint::Getsign(){
	return sign;
}

int longint::Overflow(int T){
	int overflow;
	int digits = Digit(T);
	int subtractor;

	if(digits <= 4){
		overflow = 0;
	}
	else{
		overflow = T/10000;
		subtractor = overflow*10000;
		nodresult = T - subtractor;
	}
/*
	cout << "T: " << T << '\n';
	cout << "overflow: " << overflow << '\n';
*/	
	return overflow;
}

int longint::Digit(int T){

int len;
	
	if(T<10){
		len = 1;
	}
	else if(T < 100){
		len = 2;
	}
	else if(T < 1000){
		len = 3;
	}
	else if(T < 10000){
		len = 4;
	}
	else if(T < 100000){
		len = 5;
	}
	else if(T < 1000000){
		len = 6;
	}
	else if(T < 10000000){
		len = 7;
	}
	else if(T < 100000000){
		len = 8;
	}
	else if(T < 1000000000){
		len = 9;
	}
	else{
		len = 10;
	}
/*
	cout << "number: " << len << '\n';
*/
	return len;
}

int longint::Getdigitcount(){
	int intholder;
	struct Node* temp;
	temp = newlist->GetFirst();
	int len;

	intholder = newlist->getValue(temp);

	if(intholder<10){
		len = 1;
	}
	else if(intholder < 100){
		len = 2;
	}
	else if(intholder < 1000){
		len = 3;
	}
	else{
		len = 4;
	}

	while(newlist->isLast(temp) != 1){
		len = len + 4;
		temp = newlist->nextRight(temp);
	} 
/*	
	cout << "number: " << len << '\n';
*/
	return len;
}

void longint::initialize(string value){

	newlist->clear();	

	char t = value[0];
	if(t == '-'){
		Setsign('-');
		int length = value.length();
		value = value.substr(1); 
	}
	else{
		Setsign('+');
	}

	string holder = "";
	

	int size = value.length()-1;
	int counter = 1;
	holder = value[size];

	for(int i = 1; i <= size; i++){

		if(counter % 4 == 0){

			int addnode = atoi(holder.c_str());
			newlist->insertFront(addnode);
			holder = value[size-i];
			counter++;
		}	
		else{
			
			holder =  value[size-i] + holder;
			counter++;
			

		}
	}

	int addnode = atoi(holder.c_str());
	newlist->insertFront(addnode);
	


/*cout << number << '\n';
cout << sign << '\n';
cout << Getdigitcount() << '\n'; */
}
/*
void longint::Print(){

int intholder;
struct Node* temp;
temp = newlist->GetFirst();

string finalnumber = "";

int num = newlist->isLast(temp);



	while(newlist->isLast(temp) != 1){
		intholder = newlist->getValue(temp);
		
		stringstream ss;
		ss << intholder;
		//string str = ss.str();
		finalnumber = finalnumber + ss.str();	

		temp = newlist->nextRight(temp);
	} 
	intholder = newlist->getValue(temp);
	
	stringstream ss;
	ss << intholder;
	finalnumber = finalnumber + ss.str();
	cout << "number: " << sign+finalnumber << '\n';

}
*/

void longint::Print(){

int intholder;
struct Node* temp;
temp = newlist->GetFirst();

string finalnumber = "";

int num = newlist->isLast(temp);
int len;
intholder = newlist->getValue(temp);
stringstream sd;
sd << intholder;
finalnumber = finalnumber + sd.str();	

temp = newlist->nextRight(temp);

while(newlist->isLast(temp->prev) != 1){
		intholder = newlist->getValue(temp);
		stringstream ss;
		//check if our node has 4 digits, checking for 0s.
		len = Digit(intholder);
		ss << intholder;

		if(len==0){	
		finalnumber = finalnumber + "0000";	
		cout << "number: " << finalnumber << '\n';

		temp = newlist->nextRight(temp);
		}	
		else if(len == 1){
		finalnumber = finalnumber + "000" + ss.str();	
		//cout << "number: " << finalnumber << '\n';

		temp = newlist->nextRight(temp);
		}
		else if(len == 2){
		finalnumber = finalnumber + "00" + ss.str();	
		//cout << "number: " << finalnumber << '\n';

		temp = newlist->nextRight(temp);
		}
		else if(len == 3){
		finalnumber = finalnumber + "0" + ss.str();	
		//cout << "number: " << finalnumber << '\n';

		temp = newlist->nextRight(temp);
		}
		else{
		finalnumber = finalnumber + ss.str();	
		//cout << "number: " << finalnumber << '\n';

		temp = newlist->nextRight(temp);
		}
	} 
/*
	intholder = newlist->getValue(temp);
		stringstream ss;
		//check if our node has 4 digits, checking for 0s.
		len = Digit(intholder);
		ss << intholder;

		if(len==0){	
		finalnumber = finalnumber + "0000";	
		//cout << "number: " << finalnumber << '\n';
		}	
		else if(len == 1){
		finalnumber = finalnumber + "000" + ss.str();	
		//cout << "number: " << finalnumber << '\n';
		}
		else if(len == 2){
		finalnumber = finalnumber + "00" + ss.str();	
		//cout << "number: " << finalnumber << '\n';
		}
		else if(len == 3){
		finalnumber = finalnumber + "0" + ss.str();	
		//cout << "number: " << finalnumber << '\n';
		}
		else{
		finalnumber = finalnumber + ss.str();	
		//cout << "number: " << finalnumber << '\n';
		}
	*/
	if(sign == '-'){
	cout << sign+finalnumber << '\n';
	}
	else{
	cout << finalnumber << '\n';
	}	
}

// need to fetch the list we are using.
doublylinkedlist longint::list(){
	return *newlist;
}

//using string for now, just because of step 1.
string longint::Greaterthan(longint Q){

//compare digit count
	//if both negative
	if(Getsign() == '-' && Q.Getsign() == '-'){
		if( Getdigitcount() > Q.Getdigitcount()){
		return "false";
		}
		else if( Getdigitcount() < Q.Getdigitcount()){
			//cout <<  Getdigitcount() << " " << Q.Getdigitcount() << '\n';
			return "true";
		}
		else{  //compare data if same amount of digits
			struct Node* temp;
			temp = newlist->GetFirst(); //first long int data

			struct Node* temp2;
			temp2 = Q.list().GetFirst();

		//cout <<  newlist->getValue(temp) << " " << Q.list().getValue(temp2) << '\n';
	
			while(newlist->getValue(temp) != -1){
			
				if(newlist->getValue(temp) > Q.list().getValue(temp2)){
				return "false";
				}
				else if(newlist->getValue(temp) < Q.list().getValue(temp2)){
					return "true";
				}
				else{
					temp = newlist->nextRight(temp);
					temp2 = Q.list().nextRight(temp2);
				}
			}
		}
	return "false";
	}
	
	else if(Getsign() == '+' && Q.Getsign() == '+'){

		if( Getdigitcount() > Q.Getdigitcount()){
			return "true";
		}
		else if( Getdigitcount() < Q.Getdigitcount()){
			//cout <<  Getdigitcount() << " " << Q.Getdigitcount() << '\n';
			return "false";
		}
		else{  //compare data if same amount of digits
			struct Node* temp;
			temp = newlist->GetFirst(); //first long int data

			struct Node* temp2;
			temp2 = Q.list().GetFirst();

			//cout <<  newlist->getValue(temp) << " " << Q.list().getValue(temp2) << '\n';
	
			while(newlist->getValue(temp) != -1){
			
				if(newlist->getValue(temp) > Q.list().getValue(temp2)){
					return "true";
				}
				else if(newlist->getValue(temp) < Q.list().getValue(temp2)){
					return "false";
				}
				else{
					temp = newlist->nextRight(temp);
					temp2 = Q.list().nextRight(temp2);
				}
			}
		}
	return "false";
	}
	else if(Getsign() == '+' && Q.Getsign() == '-'){
		return "true";
	}
	else {
		return "false";
	}
}

string longint::Lessthan(longint Q){

//compare digit count
	//if both negative
	if(Getsign() == '-' && Q.Getsign() == '-'){
		if( Getdigitcount() > Q.Getdigitcount()){
			return "true";
		}
		else if( Getdigitcount() < Q.Getdigitcount()){
			//cout <<  Getdigitcount() << " " << Q.Getdigitcount() << '\n';
			return "false";
		}
		else{  //compare data if same amount of digits
			struct Node* temp;
			temp = newlist->GetFirst(); //first long int data

			struct Node* temp2;
			temp2 = Q.list().GetFirst();

		//cout <<  newlist->getValue(temp) << " " << Q.list().getValue(temp2) << '\n';
	
			while(newlist->getValue(temp) != -1){
			
				if(newlist->getValue(temp) > Q.list().getValue(temp2)){
					return "true";
				}
				else if(newlist->getValue(temp) < Q.list().getValue(temp2)){
					return "false";
				}
				else{
					temp = newlist->nextRight(temp);
					temp2 = Q.list().nextRight(temp2);
				}
			}
		}
	return "false";
	}
	
	else if(Getsign() == '+' && Q.Getsign() == '+'){

		if( Getdigitcount() > Q.Getdigitcount()){
			return "false";
		}
		else if( Getdigitcount() < Q.Getdigitcount()){
			//cout <<  Getdigitcount() << " " << Q.Getdigitcount() << '\n';
			return "true";
		}
		else{  //compare data if same amount of digits
			struct Node* temp;
			temp = newlist->GetFirst(); //first long int data

			struct Node* temp2;
			temp2 = Q.list().GetFirst();

			//cout <<  newlist->getValue(temp) << " " << Q.list().getValue(temp2) << '\n';
	
			while(newlist->getValue(temp) != -1){
			
				if(newlist->getValue(temp) > Q.list().getValue(temp2)){
					return "false";
				}
				else if(newlist->getValue(temp) < Q.list().getValue(temp2)){
					return "true";
				}
				else{
					temp = newlist->nextRight(temp);
					temp2 = Q.list().nextRight(temp2);
				}
			}
		}
	return "false";
	}
	else if(Getsign() == '+' && Q.Getsign() == '-'){
		return "false";
	}
	else {
		return "true";
	}
}

string longint::Equalto(longint Q){


//compare digit count
	//if both negative
	if(Getsign() == '-' && Q.Getsign() == '-'){
		if( Getdigitcount() > Q.Getdigitcount()){
			return "false";
		}
		else if( Getdigitcount() < Q.Getdigitcount()){
			//cout <<  Getdigitcount() << " " << Q.Getdigitcount() << '\n';
			return "false";
		}
		else{  //compare data if same amount of digits
			struct Node* temp;
			temp = newlist->GetFirst(); //first long int data

			struct Node* temp2;
			temp2 = Q.list().GetFirst();

		//cout <<  newlist->getValue(temp) << " " << Q.list().getValue(temp2) << '\n';
	
			while(newlist->getValue(temp) != -1){
			
				if(newlist->getValue(temp) > Q.list().getValue(temp2)){
					return "false";
				}
				else if(newlist->getValue(temp) < Q.list().getValue(temp2)){
					return "false";
				}
				else{
					temp = newlist->nextRight(temp);
					temp2 = Q.list().nextRight(temp2);
				}
			}
		}
	return "true";
	}
	
	else if(Getsign() == '+' && Q.Getsign() == '+'){

		if( Getdigitcount() > Q.Getdigitcount()){
			return "false";
		}
		else if( Getdigitcount() < Q.Getdigitcount()){
			//cout <<  Getdigitcount() << " " << Q.Getdigitcount() << '\n';
			return "false";
		}
		else{  //compare data if same amount of digits
			struct Node* temp;
			temp = newlist->GetFirst(); //first long int data

			struct Node* temp2;
			temp2 = Q.list().GetFirst();

			//cout <<  newlist->getValue(temp) << " " << Q.list().getValue(temp2) << '\n';
	
			while(newlist->getValue(temp) != -1){
			
				if(newlist->getValue(temp) > Q.list().getValue(temp2)){
					return "false";
				}
				else if(newlist->getValue(temp) < Q.list().getValue(temp2)){
					return "false";
				}
				else{
					temp = newlist->nextRight(temp);
					temp2 = Q.list().nextRight(temp2);
				}
			}
		}
	return "true";
	}
	else if(Getsign() == '+' && Q.Getsign() == '-'){
		return "false";
	}
	else {
		return "false";
	}
}

longint longint::add(longint Q){

longint * long1 = new longint(list());
longint * long2 = new longint(Q.list());

longint * sum = new longint();

	//cout <<  Getsign() << Q.Getsign() << '\n';
	if(Getsign() == Q.Getsign()){
		//cout <<  "same" << '\n';
		char addsign = Getsign();
		sum->Setsign(addsign);

		struct Node * nod1;
		struct Node * nod2;
		nodresult = 0;

		int overflow = 0;

		nod1 = long1->list().GetLast();
		nod2 = long2->list().GetLast();

		//cout<<long1->list().getValue(nod1)<< '\n';

		//cout<<long2->list().getValue(nod2)<< '\n';

		while(long1->list().getValue(nod1) != -1 && long2->list().getValue(nod2) != -1){
			nodresult = long1->list().getValue(nod1) + long2->list().getValue(nod2) + overflow;	
			//cout<<nodresult<< '\n';

			nod1 = long1->list().nextLeft(nod1);
			nod2 = long2->list().nextLeft(nod2);
	
			overflow = Overflow(nodresult);
			//cout<<overflow<< '\n';
			//cout<<nodresult<< '\n';

			sum->list().insertFront(nodresult);
		}
		while(long1->list().getValue(nod1) != -1){
			nodresult = long1->list().getValue(nod1) + overflow;
			nod1 = long1->list().nextLeft(nod1);
			overflow = Overflow(nodresult);
			sum->list().insertFront(nodresult);
		}		
		while(long2->list().getValue(nod2) != -1){
			nodresult = long2->list().getValue(nod2) + overflow;
			nod2 = long2->list().nextLeft(nod2);
			overflow = Overflow(nodresult);
			sum->list().insertFront(nodresult);
		}	
		if(overflow != 0){
		nodresult = overflow;
		sum->list().insertFront(nodresult);
		}	
		return *sum;
	}
	else{
		if(Getsign() == '-'){
			return long2->subtract(*long1);
		}
		else{
			return long1->subtract(*long2);
		}
		cout << "different" << '\n';
	}


//long2->Print();
//long1->Print();
return *sum;
}

longint longint::subtract(longint Q){
longint * long1 = new longint(list());
longint * long2 = new longint(Q.list());

longint * dif = new longint();

if(Getsign() == '-' && Q.Getsign() == '+'){
	*dif = long1->add(*long2);
	dif->Setsign('-');
}
else if(Getsign() == '+' && Q.Getsign() == '-'){
	*dif = long1->add(*long2);
}
else if(Getsign() == '-' && Q.Getsign() == '-'){
	long1->Setsign('-');
	*dif = long1->add(*long2);
}
else{
	if(long1->Lessthan(*long2) == "true"){
		*dif = long2->subtract(*long1);
		dif->Setsign('-');
	}
	else if(long1->Greaterthan(*long2) == "true"){
		struct Node * nod1;
		struct Node * nod2;
		nodresult = 0;

		nod1 = long1->list().GetLast();
		nod2 = long2->list().GetLast();

		int data1 = long1->list().getValue(nod1);
		int data2 = long2->list().getValue(nod2);

		while(long1->list().getValue(nod1) != -1 && long2->list().getValue(nod2) != -1){
			nodresult = data1 - data2;	
			//cout<<nodresult<< '\n';

				if(nodresult >= 0){
					dif->list().insertFront(nodresult);
					nod1 = long1->list().nextLeft(nod1);
					nod2 = long2->list().nextLeft(nod2);

				 	data1 = long1->list().getValue(nod1);
					data2 = long2->list().getValue(nod2);
				}
				else{
					nodresult = 10000 + data1 - data2;
					dif->list().insertFront(nodresult);
					nod1 = long1->list().nextLeft(nod1);
					nod2 = long2->list().nextLeft(nod2);

					data1 = long1->list().getValue(nod1) - 1;
					data2 = long2->list().getValue(nod2);
				}
		}
		while(long1->list().getValue(nod1) != -1){
			if(data1 >=0){
				nodresult = data1;
				dif->list().insertFront(nodresult);
				nod1 = long1->list().nextLeft(nod1);
				data1 = long1->list().getValue(nod1);
			}
			else{
				nodresult = data1 + 10000;
				dif->list().insertFront(nodresult);
				nod1 = long1->list().nextLeft(nod1);
				data1 = long1->list().getValue(nod1) - 1;
			}
		}
		while(dif->list().getValue(dif->list().GetFirst()) == 0){
			dif->list().deleteNode(dif->list().GetFirst());
		}
	}
	else{
		dif->list().insertFront(0);
	}

}
return *dif;
}

longint longint::multiply(longint Q){
longint * long1 = new longint(list());
longint * long2 = new longint(Q.list());

longint * mult = new longint("0");
//mult->Setsign('+');

if(long1->list().getValue(long1->list().GetLast()) == 0 && long1->list().getValue(long1->list().nextLeft(long1->list().GetLast())) == -1){

	mult->list().insertFront(0);

}
else if(long2->list().getValue(long2->list().GetLast()) == 0 && long2->list().getValue(long2->list().nextLeft(long2->list().GetLast())) == -1){

	mult->list().insertFront(0);

}
else{

		struct Node * nod1;
		struct Node * nod2;
		nodresult = 0;

		nod1 = long1->list().GetLast();
		nod2 = long2->list().GetLast();

		int data1 = long1->list().getValue(nod1);
		int data2 = long2->list().getValue(nod2);

	//mult->list().insertFront(0);

	//mult->Print();
	//mult->Setsign('+');
	//mult->Print();
	int counter2 = 0;
	int counter = 0;
	int overflow;
	while(long2->list().getValue(nod2) != -1){
	
		while(long1->list().getValue(nod1) != -1){
			longint * adder = new longint();
			nodresult = long2->list().getValue(nod2)*long1->list().getValue(nod1);
			overflow = Overflow(nodresult);
			if(overflow > 0){
				adder->list().insertFront(nodresult);
				adder->list().insertFront(overflow);
				int i = 0;
				for( i = 0; i < counter; i++){
					adder->list().insertBack(0);
				}
				i = 0;
				for( i = 0; i < counter2; i++){
					adder->list().insertBack(0);
				}
				//adder->Print();
			}
			else if(overflow == 0 && nodresult > 0){
				adder->list().insertFront(nodresult);
				int i = 0;
				for( i = 0; i < counter; i++){
					adder->list().insertBack(0);
				}
				i = 0;
				for( i = 0; i < counter2; i++){
					adder->list().insertBack(0);
				}
				//adder->Print();
			}
			else{
				adder->list().insertFront(0);
				//adder->Print();	
			}
			//adder->Print();
			//mult->Print();
			longint * RSLT = new longint("0");
			*mult = adder->add(*mult);
			//mult->Print();
			nod1 = long1->list().nextLeft(nod1);
			counter++;
			adder=NULL;
			delete adder;

		}
	nod2 = long2->list().nextLeft(nod2);
	counter2++;
	counter = 0;
	nod1 = long1->list().GetLast(); 
	}

	 
}

	if(Getsign() == '-' && Q.Getsign() == '+'){
		mult->Setsign('-');
	}
	if(Getsign() == '+' && Q.Getsign() == '-'){
		mult->Setsign('-');
	} 

return *mult;
}

longint longint::power(int Q){
longint * long1 = new longint(list());

	if(Getsign() == '-'){
		long1->Setsign('-');
	}

	//if power is equal to 1, return long1.
	if(Q == 1){
		//long1->Print();
		return *long1;
	}

	//if power is divisible by 2
	else if(Q%2 == 0){
		*long1 = long1->power(Q/2);   //run power with half exponent
		*long1 = long1->multiply(*long1); //square result
		//long1->Print();
		return *long1;
	}

	else{
		*long1 = long1->multiply(long1->power(Q-1));
		//long1->Print();
		return *long1;
	}
}

longint longint::divided(longint Q){
longint * long1 = new longint(list());
longint * long2 = new longint(Q.list());
longint * quotient = new longint("0");

if( long2->Greaterthan(*long1) == "true"){
	return *quotient;
}

	while( long1->Greaterthan(*long2) == "true" || long1->Equalto(*long2) == "true"){
		int l1 = long1->Getdigitcount();
		int l2 = long2->Getdigitcount();
		int dif = l1 - l2;
		string zeros = "1";
		
		for( int i = 0; i < dif; i++){
			zeros = zeros+"0";
		
		}	
			
		longint * z = new longint(zeros);
		longint * divisor = new longint;
		*divisor = long2->multiply(*z);
		
		if( divisor->Greaterthan(*long1) == "true" ){
			zeros = zeros.substr(0, zeros.size()-1);
			z = new longint(zeros);
			*divisor = z->multiply(*long2);
		}
		
		int divided;
		int divider;
		
		if(long1->Getdigitcount() == divisor->Getdigitcount()){
			divided = long1->list().getValue(long1->list().GetFirst());
			divider = divisor->list().getValue(divisor->list().GetFirst());
		}
		else{
			divided = long1->list().getValue(long1->list().GetFirst());
			if( long1->list().getValue(long1->list().nextRight(long1->list().GetFirst())) != -1){
				divided = divided * 10000;
				int ad = long1->list().getValue(long1->list().nextRight(long1->list().GetFirst()));
				divided = divided + ad;
			}
			divider = divisor->list().getValue(divisor->list().GetFirst());
			if( divisor->list().getValue(divisor->list().nextRight(divisor->list().GetFirst())) != -1){
				divider = divider * 10000;
				int ad = divisor->list().getValue(divisor->list().nextRight(divisor->list().GetFirst()));
				divider = divider + ad;
			}

			while(divided >= 10000){
				divided = divided/10;
			}
			while(divider >= 1000){
				divider = divider/10;
			}
		}

		int re = divided/divider;
		stringstream ss;
		ss << re;
		string str = ss.str();

		longint * reint = new longint(str);
		longint * subtractor = new longint("1");
		longint * zero = new longint("0");
		longint * checker = new longint("0");
		longint * checker2 = new longint("0");

		*checker2 = reint->multiply(*divisor);
		*checker = long1->subtract(*checker2);
		while( checker->Getsign() == '-' ){
			*reint = reint->subtract(*subtractor);
			*checker2 = reint->multiply(*divisor);
			*checker = long1->subtract(*checker2);
		}
		
		long1 = checker;
		*z = z->multiply(*reint);
		*quotient = quotient->add(*z);
	}

	if(Getsign() == '-' && Q.Getsign() == '+'){
		quotient->Setsign('-');
	}
	if(Getsign() == '+' && Q.Getsign() == '-'){
		quotient->Setsign('-');
	} 
		
return *quotient;
}