#include "header.h"
#define MAX 20
#define POS MAX/4 
int main(int argc,char *argv[])
{
      //VARIABLE DECLARATION START      
        char a=0;
        char c=1;
        char g=2;
        char t=3;
        int k,mask;
        char temp=0,z;
        int i,j,num=0,size,r;
        //FILE *ip,*op;
        int fd = open(argv[1],O_RDONLY);
        int fd1 = open(argv[2],O_CREAT |O_WRONLY,S_IRUSR | S_IWUSR);


 char input[MAX+1];
        unsigned char output[POS];
       // while(!(feof(ip)))
        do
        {
        //INPUT FILE READ AND STORE IN THE INPUT ARRAY
        num = read(fd,input,MAX*sizeof(char));
        input[num*sizeof(char)]= '\0';

        if(num == 0)
        break;

//      printf("%s\n",input); 
//      printf("num %d\n",num);
//        printf(".......................\n");


        for(i=0;i<num;i=i+4)
        {
          for(j=i;j<i+4;j++)
          {
            if(input[j] == 'a' || input[j] == 'A')
            temp = temp | a;
            if(input[j] == 'c' || input[j] == 'C')
            temp = temp | c;
            if(input[j] == 'g' || input[j] == 'G')
            temp = temp | g;
            if(input[j] == 't' || input[j] == 'T')
            temp = temp | t;

            if(j != i+3)
            temp = temp << 2;


                                                                                                                           
          }//END OF SECOND FOR LOOP

            output[i/4] = temp;
            temp=0;



        }//END OF FIRST FOR LOOP


        //fprintf(op,"%s",output);       
        write(fd1,output,strlen(output));

        for(z=0;z<POS;z++)
        output[z]=0;

        }while(num == MAX*sizeof(char));

        close(fd);
        close(fd1);
        //fclose(ip);
        //fclose(op);

}

