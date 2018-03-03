#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

#define file "/home/vijay/practice2/tmpfile2.txt"
#define mode "a+"
class Customer;

void save(Customer &obj);

class Customer{
	public:
		typedef	enum _AccoutType{SAVINGS=0,CURRENT}AccountType;
	private:
		string _name;
		int _acc_num;
		double _balance;
		AccountType _type;
	
	public:

	/*	bool validateAccount(int acc_num){
			return ;
		}*/
/*		void deposit(int acc_num,double amount){
		//	validateAccount(acc_num);
			_balance += amount; 
		}	
*/
		void createAccount(string name, int acc_num, double balance=0, AccountType type=SAVINGS){
			_name=name;
			_acc_num=acc_num;
			_balance=balance;
			_type=type;
			FILE *fd = fopen(file,mode);
			if(NULL == fd){
				cout << "File busy/not found" << endl;
				exit(1);
			}
			fseek(fd,0,SEEK_END);
			fwrite(reinterpret_cast<char*>(this),sizeof(Customer),1,fd);
			fclose(fd);
		}

		//		void displayObj(Customer obj)

};/*
void save(Customer &obj){
	FILE *fd = fopen(file,mode);
	if(NULL == fd){
		cout << "File busy/not found" << endl;
		exit(1);
	}
	fseek(fd,0,SEEK_END);
	fwrite(obj,sizeof(Customer),1,fd);
	fclose(fd);
}*/

void display(){
	FILE *fd = fopen(file,mode);
	if(NULL == fd){
		cout << "File busy/not found" << endl;
		exit(1);
	}
	
	fseek(fd,0,SEEK_SET);

	Customer *buff = new Customer;
//	memset(&buff,'\0',sizeof(Customer));
	while(fread(reinterpret_cast<char*>(buff),sizeof(buff)-1,1,fd))
	{
//		displayObj(buf);
	}
	fclose(fd);	
	
}

int main(){
	Customer c1;
	cout << "before = " << sizeof(c1) << endl;
	c1.createAccount("naveenjfakjkfjasasfaseaeavaeaaaraaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",123464);
	cout << "after = " << sizeof(c1) << endl;
	display();
}

