#include<stdio.h>
#include<string.h>
void main(){
    char label[20],op[20],opcode[20],pc[20],op2[10],hex[10],label2[10],pc2[10],ob;
    FILE *f1,*f2,*f3,*f4;
    f1=fopen("intermediate.txt","r");
    f4=fopen("obj.txt","w");
    while (fscanf(f1,"%s%s%s%s",pc,label,op,opcode)!=EOF)
    {
    if(strcmp(op,"START")!=0){
    f2=fopen("optab.txt","r");
    if (strcmp(op,"WORD")==0 || strcmp(op,"BYTE")==0){
    fprintf(f4,"%s\t%s\t%s\t%s\n",label,op,opcode,opcode);
    
    }
    
    while (fscanf(f2,"%s%s",op2,hex)!=EOF){   
    if(strcmp(op,op2)==0)
    {
    f3=fopen("symtab.txt","r");
    while (fscanf(f3,"%s%s",label2,pc2)!=EOF){
    if(strcmp(opcode,label2)==0){
    
    fprintf(f4,"%s\t%s\t%s\t%s\n",label,op,opcode,strcat(hex,pc2));
    break;
    }
    }
    }
    }
    }
    }
    
}