#include<stdio.h>
#include<string.h>
struct hash
{
    char label[10];
    int add;
}hash[20];
void main(){
int i=0,pc,j;
char c[10],d[10],lab[10],op[10],opcode[10];
FILE *f1;
f1=fopen("input.txt","r");
fscanf(f1,"%s%s%s",lab,op,opcode);
pc=atoi(opcode);
while (fscanf(f1,"%s%s%s",lab,op,opcode)!=EOF)
{
if(strcmp(op,"RESW")==0){
if(strcmp(lab,"**")!=0){
strcpy(hash[i].label,lab);
hash[i].add=pc;
i=i+1;
}
pc=pc+(3*atoi(opcode));
}
else if (strcmp(op,"RESWB")==0)
{
if(strcmp(lab,"**")!=0){
strcpy(hash[i].label,lab);
hash[i].add=pc;
i=i+1;
}
pc=pc+atoi(opcode);
}
else if (strcmp(op,"BYTE")==0)
{
if(strcmp(lab,"**")!=0){
strcpy(hash[i].label,lab);
hash[i].add=pc;
i=i+1;
}
pc=pc+strlen(opcode)-3;
}
else
{
if(strcmp(lab,"**")!=0){
strcpy(hash[i].label,lab);
hash[i].add=pc;
i=i+1;
}
pc=pc+3;
}

}
fclose(f1);
for(j=0;j<i;j++)
printf("%s\t%d\n",hash[j].label,hash[j].add);
}