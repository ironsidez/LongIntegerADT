#include <string>
#include <iostream>
#include <sstream>

using namespace std;
//#include "doublylinkedlist.h"
#include "longint.h"


int main() {
/* 	
	doublylinkedlist list1;
	
	list1.insertFront(2); 
	list1.insertFront(3);
	list1.insertFront(4);
	list1.insertBack(1);
	list1.insertFront(5);
	list1.insertFront(6);
	list1.Print();

	struct Node* tempnode;
	struct Node* tempnode2;	

	

	tempnode = list1.GetLast();
	tempnode2 = list1.GetFirst();
	//printf("%d ",tempnode->value);	
	//printf("%d ",tempnode2->value);
	tempnode = list1.nextLeft(tempnode);
	tempnode2 = list1.nextRight(tempnode2);
	//printf("%d ",tempnode->value);	
	//printf("%d ",tempnode2->value);
	tempnode = list1.nextLeft(tempnode);
	tempnode2 = list1.nextRight(tempnode2);
	//printf("%d ",tempnode->value);	
	//printf("%d ",tempnode2->value);





string number;
cout << "Enter the number: " << flush;
cin >> number;

longint * long1;
longint * long2;

long1 = new longint(number);
long2 = new longint("321432");

long1->Print();
long2->Print();

long1->Getdigitcount();
long2->Getdigitcount();

string answer = long1->Greaterthan(*long2);
cout<< answer << '\n';

answer = long1->Lessthan(*long2);
cout<< answer << '\n';


answer = long1->Equalto(*long2);
cout<< answer << '\n';

*/

cout<< "step1: test cases" <<'\n';

longint * A;
longint * B;
longint * C;
longint * D;
longint * AX;
longint * AZ;

A = new longint("2222");
B = new longint("99999999");
C = new longint("246813575732");
D = new longint("180270361023456789");
AX = new longint("29302390234702973402973420937420973420937420937234872349872934872893472893749287423847");
AZ = new longint("-98534342983742987342987339234098230498203894209928374662342342342356723423423");

A->Print();
B->Print();
C->Print();
D->Print();
AX->Print();
AZ->Print();

int digits;

digits = A->Getdigitcount();
cout<< "Digits: " << digits << '\n';
digits = B->Getdigitcount();
cout<< "Digits: " << digits << '\n';
digits = C->Getdigitcount();
cout<< "Digits: " << digits << '\n';
digits = D->Getdigitcount();
cout<< "Digits: " << digits << '\n';
digits = AX->Getdigitcount();
cout<< "Digits: " << digits << '\n';
digits = AZ->Getdigitcount();
cout<< "Digits: " << digits << '\n';


string answer = A->Greaterthan(*B);
cout<< "A > B: "<< answer << '\n';
answer = A->Lessthan(*B);
cout<< "A < B: "<< answer << '\n';
answer = A->Equalto(*B);
cout<< "A = B: "<< answer << '\n';

answer = A->Greaterthan(*C);
cout<< "A > C: "<< answer << '\n';
answer = A->Lessthan(*C);
cout<< "A < C: "<< answer << '\n';
answer = A->Equalto(*C);
cout<< "A = C: "<< answer << '\n';

answer = A->Greaterthan(*D);
cout<< "A > D: "<< answer << '\n';
answer = A->Lessthan(*D);
cout<< "A < D: "<< answer << '\n';
answer = A->Equalto(*D);
cout<< "A = D: "<< answer << '\n';

answer = A->Greaterthan(*AX);
cout<< "A > AX: "<< answer << '\n';
answer = A->Lessthan(*AX);
cout<< "A < AX: "<< answer << '\n';
answer = A->Equalto(*AX);
cout<< "A = AX: "<< answer << '\n';

answer = A->Greaterthan(*AZ);
cout<< "A > AZ: "<< answer << '\n';
answer = A->Lessthan(*AZ);
cout<< "A < AZ: "<< answer << '\n';
answer = A->Equalto(*AZ);
cout<< "A = AZ: "<< answer << '\n';

answer = B->Greaterthan(*C);
cout<< "B > C: "<< answer << '\n';
answer = B->Lessthan(*C);
cout<< "B < C: "<< answer << '\n';
answer = B->Equalto(*C);
cout<< "B = C: "<< answer << '\n';

answer = B->Greaterthan(*D);
cout<< "B > D: "<< answer << '\n';
answer = B->Lessthan(*D);
cout<< "B < D: "<< answer << '\n';
answer = B->Equalto(*D);
cout<< "B = D: "<< answer << '\n';

answer = B->Greaterthan(*AX);
cout<< "B > AX: "<< answer << '\n';
answer = B->Lessthan(*AX);
cout<< "B < AX: "<< answer << '\n';
answer = B->Equalto(*AX);
cout<< "B = AX: "<< answer << '\n';

answer = B->Greaterthan(*AZ);
cout<< "B > AZ: "<< answer << '\n';
answer = B->Lessthan(*AZ);
cout<< "B < AZ: "<< answer << '\n';
answer = B->Equalto(*AZ);
cout<< "B = AZ: "<< answer << '\n';

answer = C->Greaterthan(*D);
cout<< "C > D: "<< answer << '\n';
answer = C->Lessthan(*D);
cout<< "C < D: "<< answer << '\n';
answer = C->Equalto(*D);
cout<< "C = D: "<< answer << '\n';

answer = C->Greaterthan(*AX);
cout<< "C > AX: "<< answer << '\n';
answer = C->Lessthan(*AX);
cout<< "C < AX: "<< answer << '\n';
answer = C->Equalto(*AX);
cout<< "C = AX: "<< answer << '\n';

answer = C->Greaterthan(*AZ);
cout<< "C > AZ: "<< answer << '\n';
answer = C->Lessthan(*AZ);
cout<< "C < AZ: "<< answer << '\n';
answer = C->Equalto(*AZ);
cout<< "C = AZ: "<< answer << '\n';

answer = D->Greaterthan(*AX);
cout<< "D > AX: "<< answer << '\n';
answer = D->Lessthan(*AX);
cout<< "D < AX: "<< answer << '\n';
answer = D->Equalto(*AX);
cout<< "D = AX: "<< answer << '\n';

answer = D->Greaterthan(*AZ);
cout<< "D > AZ: "<< answer << '\n';
answer = D->Lessthan(*AZ);
cout<< "D < AZ: "<< answer << '\n';
answer = D->Equalto(*AZ);
cout<< "D = AZ: "<< answer << '\n';

answer = AX->Greaterthan(*AZ);
cout<< "AX > AZ: "<< answer << '\n';
answer = AX->Lessthan(*AZ);
cout<< "AX < AZ: "<< answer << '\n';
answer = AX->Equalto(*AZ);
cout<< "AX = AZ: "<< answer << '\n';

digits = A->Overflow(99999999);
cout<< "overflow is: "<< digits << '\n';

cout<< "step2: test cases" <<'\n';

longint * E;
E = new longint;
longint * F;
F = new longint;
longint * G;
G = new longint;
longint * H;
H = new longint;
longint * I;
I = new longint;
longint * J;
J = new longint;
longint * K;
K = new longint;
longint * L;
L = new longint;
longint * M;
M = new longint;
longint * N;
N = new longint;
longint * O;
O = new longint;
longint * P;
P = new longint;
longint * Q;
Q = new longint;
longint * R;
R = new longint;
longint * S;
S = new longint;
longint * T;
T = new longint;
longint * U;
U = new longint;
longint * V;
V = new longint;


*E = A->add(*D);
cout << "E = A + D = ";
E->Print();

*F = B->add(*C);
cout << "F = B + C = ";
F->Print();

*G = C->add(*D);
cout << "G = C + D = ";
G->Print();

*H = E->add(*E);
cout << "H = E + E = ";
H->Print();

*I = A->add(*E);
cout << "I = A + E = ";
I->Print();

*J = B->add(*G);
cout << "J = B + G = ";
J->Print();

*K = A->subtract(*D);
cout << "K = A - D = ";
K->Print();

*L = C->subtract(*D);
cout << "L = C - D = ";
L->Print();

*M = D->subtract(*C);
cout << "M = D - C = ";
M->Print();

*N = H->subtract(*H);
cout << "N = H - H = ";
N->Print();

*O = L->subtract(*K);
cout << "O = L - K = ";
O->Print();

*P = J->subtract(*M);
cout << "P = J - M = ";
P->Print();


*Q = A->multiply(*D);
cout << "Q = A x D = ";
Q->Print();

*R = B->multiply(*C);
cout << "R = B x C = ";
R->Print();

*S = D->multiply(*D);
cout << "S = D x D = ";
S->Print();

*T = K->multiply(*E);
cout << "T = K x E = ";
T->Print();

*U = F->multiply(*L);
cout << "U = F x L = ";
U->Print();

*V = I->multiply(*J);
cout << "V = I x J = ";
V->Print();

cout<< "step3: test cases" <<'\n';

longint * W;
W = new longint;
longint * X;
X = new longint;
longint * Y;
Y = new longint;
longint * Z;
Z = new longint;
longint * AA;
AA = new longint;
longint * AB;
AB = new longint;
longint * AC;
AC = new longint;
longint * AD;
AD = new longint;
longint * AE;
AE = new longint;
longint * AF;
AF = new longint;
longint * AG;
AG = new longint;
longint * AH;
AH = new longint;


*W = D->power(2);
cout << "W = D^2 = ";
W->Print();

*X = A->power(5);
cout << "X = A^5 = ";
X->Print();

*Y = B->power(10);
cout << "Y = B^10 = ";
Y->Print();

*Z = W->power(4);
cout << "Z = W^4 = ";
Z->Print();

*AA = E->power(2);
cout << "AA = E^2 = ";
AA->Print();

*AB = K->power(2);
cout << "AB = K^2 = ";
AB->Print();


*AC = D->divided(*B);
cout << "AC = D/B = ";
AC->Print();

*AD = D->divided(*A);
cout << "AD = D/A = ";
AD->Print();

*AE = Q->divided(*D);
cout << "AE = Q/D = ";
AE->Print();

*AF = T->divided(*K);
cout << "AF = T/K = ";
AF->Print();

*AG = H->divided(*E);
cout << "AG = H/E = ";
AG->Print();

*AH = U->divided(*U);
cout << "AH = U/U = ";
AH->Print();

cout<< "step3 bonus: test cases" <<'\n';

longint * E1;
E1 = new longint;
longint * E2;
E2 = new longint;
longint * E3;
E3 = new longint;
longint * E4;
E4 = new longint;
longint * E5;
E5 = new longint;
longint * E6;
E6 = new longint;
longint * E7;
E7 = new longint;
longint * E8;
E8 = new longint;

*E1 = AX->multiply(*AZ);
cout << "E1 = AX*AZ = ";
E1->Print();

*E2 = AX->multiply(*AX);
cout << "E2 = AX*AX = ";
E2->Print();

*E3 = AZ->multiply(*AZ);
cout << "E3 = AZ*AZ = ";
E3->Print();

*E4 = E2->multiply(*E3);
cout << "E4 = E2*E3 = ";
E4->Print();

*E5 = AX->power(10);
cout << "E5 = AX^10 = ";
E5->Print();

*E6 = AZ->power(14);
cout << "E6 = AZ^14 = ";
E6->Print();

*E7 = E2->power(4);
cout << "E7 = E2^4 = ";
E7->Print();

*E8 = E3->power(7);
cout << "E8 = E3^7 = ";
E8->Print();

/*
A = new longint("2");
B = new longint("221111");



*B = B->divided(*A);
cout << "B = B/A = ";
B->Print();


A = new longint("0");
B = new longint("41153237");
*A = A->add(*B);
A->Print();
*/
return 0;
}