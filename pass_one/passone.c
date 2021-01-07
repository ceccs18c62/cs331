#include<stdio.h>
#include<string.h>
void main(){
    char label[20],op[20],opcode[20],pcs[10];
    int pc;
    FILE *f1,*f2,*f3;
    f1=fopen("prg.txt","r");
    f2=fopen("intermediate.txt","w");
    fscanf(f1,"%s%s%s",label,op,opcode);
    pc=atoi(opcode);
    while ( fscanf(f1,"%s%s%s",label,op,opcode)!=EOF)
    {
    if(strcmp(op,"RESW")==0){
        fprintf(f2,"%d\t%s\t%s\t%s\n",pc,label,op,opcode);
    pc=pc+(3*(atoi(opcode)));
    }
    else if(strcmp(op,"RESB")==0){
        fprintf(f2,"%d\t%s\t%s\t%s\n",pc,label,op,opcode);
    pc=pc+atoi(opcode);
    }
    else if(strcmp(op,"BYTE")==0){
        fprintf(f2,"%d\t%s\t%s\t%s\n",pc,label,op,opcode);
    pc=pc+strlen(opcode)-3;
    }
    else{
     fprintf(f2,"%d\t%s\t%s\t%s\n",pc,label,op,opcode);   
    pc=pc+3;
    }
    }
    fclose(f1);
    fclose(f2);
    f1=fopen("intermediate.txt","r");
    f2=fopen("symtab.txt","w");
    while (fscanf(f1,"%s%s%s%s",pcs,label,op,opcode)!=EOF)
    {
    if(strcmp(label,"**")!=0)    
    fprintf(f2,"%s\t%s\n",label,pcs);
    }
    fclose(f1);
    fclose(f2);
    f1=fopen("prg.txt","r");
    f2=fopen("intermediate.txt","r");
    f3=fopen("symtab.txt","r");
    printf("\n");
    printf("input source program\n");
    printf("\n");
    while (fscanf(f1,"%s%s%s",label,op,opcode)!=EOF)
    {
    printf("%s\t%s\t%s\n",label,op,opcode);
    }
    printf("\n");
    printf("intermediate file\n");
    printf("\n");
    while (fscanf(f2,"%s%s%s%s",pcs,label,op,opcode)!=EOF)
    {
    printf("%s\t%s\t%s\t%s\n",pcs,label,op,opcode);
    }
    printf("\n");
    printf("symtab\n");
    printf("\n");
    while (fscanf(f3,"%s%s",label,opcode)!=EOF)
    {
    printf("%s\t%s\n",label,opcode);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}