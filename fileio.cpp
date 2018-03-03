#include<iostream>
   #include <stdio.h>
 #include <stdlib.h>
#include <string.h>

using namespace std;
#define file "/home/vijay/practice2/tmpfile.txt"
#define mode "r+"


int main(){
	FILE *fd = fopen(file,mode);
	if(NULL == fd){
		cout << "File busy/not found" << endl;
		exit(1);
	}
	
	fwrite("Hello",5,1,fd);
	long pos=ftell(fd);
	cout <<"current pos = " <<  pos << endl;

	fseek(fd,5L,SEEK_SET);

	pos=ftell(fd);
	cout <<"current pos = " <<  pos << endl;

	fwrite("vijay",5,1,fd);


	fseek(fd,0,SEEK_SET);

	char buff[6];
	memset(buff,'\0',6);
	while(fread(buff,sizeof(buff)-1,1,fd))
	{
		cout << buff << endl;
	}
	fclose(fd);	
}

