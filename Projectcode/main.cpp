#include "header.h"
#include <iostream>
#define MAX 20
int main(int argc,char *argv[])
{
	int i,j,num1=0,num2=0,count=0;
	unsigned char sequence[MAX+1];
	unsigned char pattern[MAX+1];
	char s[3];
	int pos[3][5]={0};	



	int fd1=open(argv[1],O_RDONLY);
	int fd2=open(argv[2],O_RDONLY);



		num1=read(fd1,sequence,MAX*sizeof(char));
		num2=read(fd2,pattern,MAX*sizeof(char));
		sequence[num1*sizeof(char)]='\0';
		pattern[num2*sizeof(char)]='\0';
		
		
		printf("%s",sequence);
		printf("%s",pattern);
		
		int size1 = sequence.length();
		int size2 = pattern.length();


		printf("%d size of sequence\n",size1);
		printf("%d size of pattern\n",size2);

		

	




}//main ends here

