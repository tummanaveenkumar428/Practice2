#include<stdio.h>
union Endian{
	unsigned int a;
	struct{
		unsigned char a1;	
		unsigned char a2;	
		unsigned char a3;	
		unsigned char a4;	
	}aa;
};


int main(){
	int x = 0x12345678;

	printf("%p\n",x);
	union Endian b;
	printf("Sizeof = %ld\n",sizeof(b));
	b.a=x;

	unsigned char t;
	t=b.aa.a1;
	b.aa.a1=b.aa.a4;
	b.aa.a4=t;

	t=b.aa.a2;
	b.aa.a2=b.aa.a3;
	b.aa.a3=t;

	x=b.a;

	printf("%p\n",x);
}


