#include "header.h"
#include <iostream>
#define MAX 20
using namespace std;
//unsigned char sequence[MAX+1];
//unsigned char pattern[MAX+1];
int stab_pos[256][257];
int ptab_pos[256][257];
void stab(int num1,unsigned char s[]);
void ptab(int num1,unsigned char s[]);
void stab_print(void);
void ptab_print(void);
int main(int argc,char *argv[])
{
	int i,j,num1=0,num2=0,count=0;
	unsigned char sequence[MAX+1];
	unsigned char pattern[MAX+1];
	char s[3];
//	int pos[256][257];
	int seq_val=0;
	int seq_int;	
		

	int fd1=open(argv[1],O_RDONLY);
	int fd2=open(argv[2],O_RDONLY);



		num1=read(fd1,sequence,MAX*sizeof(char));
		num2=read(fd2,pattern,MAX*sizeof(char));
		sequence[num1*sizeof(char)]='\0';
		pattern[num2*sizeof(char)]='\0';
		
		
		cout<<"size of sequence"<<num1<<endl;			
		cout<<"size of pattern"<<num2<<endl;

		
			stab(num1,sequence);				
			ptab(num2,pattern);
			stab_print();
			ptab_print();




/*		

		for(i=0;i<num1;i++)
		 for(j=0;j<257;j++)
		  {     seq_int = sequence[i];
			if(pos[seq_int][j]!=0)
			continue;
			else
			{
			    pos[seq_int][j]=i;
			    pos[seq_int][256]=pos[seq_int][256]+1;
			    break;
	



			}


		  }
			
		int conv = sequence[0];		
		  printf("ACGT VALUE:%d\n",sequence[0]);
		  printf("ACGT VALUE:%d\n",conv);
		  printf("ACGT value%dcount %d\n",pos[27][0],pos[27][256]);
		  printf("AGTA value%d\n",pos[44][0]);
		  printf("GGTA value%d\n",pos[173][0]);
		  printf("CCAG value%d\n",pos[82][0]);

*/







}//main ends here
void stab(int num,unsigned char seq[])
{
	
	int i,j,seq_int=0;
//	int pos[256][257];


				

		
	


		for(i=0;i<num;i++)
		{
		    for(j=0;j<257;j++)
		  {     seq_int = seq[i];
			if(stab_pos[seq_int][j]!=0)
			continue;
			else
			{
			    stab_pos[seq_int][j]=i;
			    stab_pos[seq_int][256]=stab_pos[seq_int][256]+1;
			    break;
	



			}


		  }
		}	



}
void ptab(int num,unsigned char seq[])
{
	
	int i,j,seq_int=0;
//	int pos[256][257];


				



		
	


		for(i=0;i<num;i++)
		 {
		  for(j=0;j<257;j++)
		  {     seq_int = seq[i];
			if(ptab_pos[seq_int][j]!=0)
			continue;
			else
			{
			    ptab_pos[seq_int][j]=i;
			    ptab_pos[seq_int][256]=ptab_pos[seq_int][256]+1;
			    break;
	



			}


		  }
		}	



}
void stab_print(void)
{
	int i,j;

		cout<<"\tSTAB_PRINT\t"<<endl;		

 
		for(i=0;i<256;i++)
		  {
			if(stab_pos[i][0]==0)
			continue;
			else
			{
				printf("Basepair: %d\tposition:",i);

			}
			for(j=0;j<257;j++)
		   	{

				if(stab_pos[i][j]!=0 && j!=256)
				printf("%d,",stab_pos[i][j]);

				if(j==256)
				printf("\tCount: %d",stab_pos[i][j]);




		   	}	
			printf("\n");

		   }//print for loop ending


		  










}
void ptab_print(void)
{
	int i,j;

		
		cout<<"\tPTAB_PRINT\t"<<endl;		
	
		 for(i=0;i<256;i++)
		  {
			if(ptab_pos[i][0]==0)
			continue;
			else
			{
				printf("Basepair: %d\tposition:",i);

			}
			for(j=0;j<257;j++)
		   	{

				if(ptab_pos[i][j]!=0 && j!=256)
				printf("%d,",ptab_pos[i][j]);

				if(j==256)
				printf("\tCount: %d",ptab_pos[i][j]);




		   	}	
			printf("\n");

		   }//print for loop ending















}//end of for loop


