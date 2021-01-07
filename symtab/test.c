#include <stdio.h>
#include<string.h>
void main()
{
    char in_name[10],label[50],op[40],opcode[50],dis[10],key[10],mod[10],tem[10];
    FILE *f1,*f2,*f3,*f4;
    int pc,f=1,n,c=0,pctr,d=1;
    while (1)
   {
     printf("\n");  
     printf("Select the option\n");
     printf("1-create 2-insert 3-modify 4-search 5-display 6-exit\n");
     scanf("%d",&n);
     if(n==1){ 
         if(c==0){ 
    f1= fopen("test.txt", "r");
    f2=fopen("out.txt","w+");
    
    if (f1 == NULL)
        printf("Can't open for reading.\n");
    else
    { 
    
    fscanf(f1, "%s%s%s", label,op,opcode);
    
         pc=atoi(opcode);
    
        while (fscanf(f1, "%s%s%s", label,op,opcode) != EOF)
        

        {  
            if (strcmp(label,"**")!=0 && strcmp(label," ")!=0 )
        { 
            f=0;
          if(strcmp(op,"RESW")==0){
              fprintf(f2,"%s\t%d\n",label,pc);
            
                pc=pc+(3*atoi(opcode));
                
            }
            else if (strcmp(op,"RESB")==0)
            {   fprintf(f2,"%s\t%d\n",label,pc);
                pc=pc+atoi(opcode);
                 
            }
             else if (strcmp(op,"BYTE")==0)
            {   fprintf(f2,"%s\t%d\n",label,pc);
                pc=pc+strlen(opcode)-3;
            }
            else
            {   fprintf(f2,"%s\t%d\n",label,pc);
                pc=pc+3;
                 
            }
            
        }
        if(f==1){
        
            pc=pc+3;
                

        }
           
            
        }
        fclose(f1);
        fclose(f2);
    }
    printf("symbol table created\n");
    printf("\n");
    c=1;
   }
    else
    printf("already created\n");
     }
     else if (n==2)
     {
        f1=fopen("out.txt","a");
         printf("enter the label and address to insert\n");
         scanf("%s%s",dis,in_name);
         fprintf(f1,"%s\t%s\n",dis,in_name);
         fclose(f1);
         printf("inserted\n");
         printf("\n");

     }
     
     else if (n==3)
     {
         printf("enter the label to modify\n");
         scanf("%s",key);
        
            f3=fopen("out.txt","r");
            f4=fopen("temp.txt","w");
        while (fscanf(f3,"%s%s",dis,label)!= EOF){
         if(strcmp(key,dis)==0){
             d=0;
            scanf("%s",mod);
            fprintf(f4,"%s\t%s\n",dis,mod);
         }
         else
         fprintf(f4,"%s\t%s\n",dis,label);
         
        }
        if(d==0)
         printf("modified");
         else
         printf("not found");
        fclose(f4);
        fclose(f3);
        f1=fopen("out.txt","w");
        fclose(f1);
        f1=fopen("out.txt","a");
        f2=fopen("temp.txt","r");
         while (fscanf(f2, "%s%s", label,opcode) != EOF){
              fprintf(f1,"%s\t%s\n",label,opcode);
         }
          fclose(f1);
           fclose(f2);
     }
     
     else if (n==4)
     {
        printf("enter the label\n");
        scanf("%s",key);
        
         f3=fopen("out.txt","r");
        while (fscanf(f3,"%s%s",dis,label)!= EOF){
         if(strcmp(key,dis)==0)
         printf("%s\t%s",dis,label);
        }
        
     }
     
     else if (n==5){
     f3=fopen("out.txt","r");
        while (fscanf(f3,"%s%s",dis,label)!= EOF)
         printf("%s\t%s\n",dis,label);

     }
     
   else if (n==6)
     break;
   
   }
}
