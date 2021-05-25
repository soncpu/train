//											THEM 1 PTU VAO DSLK DON CO THU TU
#include <iostream>
#include <fstream>
using namespace std;

struct Node{
	int value;
	Node *next;
};

struct list{
	Node *phead;
	Node *ptail;
};

void khoitaods(list &l){
	l.phead=NULL;
	l.ptail=NULL;
}

Node *khoitaoNode(int x){
	Node *temp = new Node;
	temp->next=NULL;
	temp->value=x;
	return temp;
}

void themdau(list &l, Node *temp){
	if(l.phead==NULL)
	l.phead=l.ptail=temp;
	else{
		temp->next=l.phead;
		l.phead=temp;
	}
}

void themcuoi(list &l, Node *temp){ //  nhap 1 day tang dan de xuat ra 1 day tang dan
	if(l.phead==NULL)
	l.phead=l.ptail=temp;
	else{
		l.ptail->next = temp;;  // neu la temp->next = NULL ra loi mat ptu
		l.ptail=temp;
	}
}

void themvaods(list &l, Node *temp){ // thieu truong hop them ptu nho hon gia tri ptu dau
	Node *cs=l.phead, *g;
	
	if(cs->value > cs->next->value){ // neu ds dang giam
	    if(temp->value > cs->value){
	    	themdau(l, temp);
		}
		else{
		while(cs != NULL && cs->value > temp->value){
			g=cs;  // thay the node cs = g 
			cs=cs->next;
		}
		temp->next=g->next; // them node temp sau node g
	    g->next = temp;
	}
}
	else{
		if(temp->value < cs->value)
		themdau(l, temp);
		else{
		while(cs != NULL && cs->value < temp->value){// ds dang tang
			g=cs;
			cs=cs->next;
		}
		temp->next=g->next;
		g->next = temp;
	}
}
}
void xuat(ofstream &FileOut, list &l){
	for(Node* cs=l.phead; cs!= NULL; cs=cs->next)
	FileOut << cs->value << " ";
}

int main(){
	ifstream FileIn;
	FileIn.open("bai5_themdslkdon_thi_input.txt", ios_base::in);
  	ofstream FileOut;
	FileOut.open("bai5_themdslkdon_thi_output.txt", ios_base::out);
	if(FileIn.fail() == true){
		cout << "\nfile ko ton tai";
		system("pause");
		return 0;
	}
	
	int x,n,k;
	list l;
	khoitaods(l);
	FileIn >> n;
	for(int i=0; i<n; i++){
		FileIn >> x;
		Node* temp = khoitaoNode(x);
		themcuoi(l, temp);
	}
	FileOut << "\nDANH SACH LUC DAU LA:\n";
    xuat(FileOut,l);
    
	FileIn >> k;
	Node *p = khoitaoNode(k);
	themvaods(l, p);
	
	FileOut << "\nDANH SACH SAU KHI THEM NODE "<< k <<" LA:\n";
    xuat(FileOut,l);
    
	FileIn.close();
	FileOut.close();
}
