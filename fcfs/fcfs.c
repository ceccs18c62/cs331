#include<stdio.h>

void main(){
    int n,i,j,burst[100],wait[100],ta[100];
    float at=0,aw=0;
    printf("\n");
    printf("Give the no. of process \n");
    scanf("%d",&n);
    printf("\n");
    printf("give the burst time of \n");
    for(i=0;i<n;i++){
        printf("P%d:",i+1);
        scanf("%d",&burst[i]);
    }
    
    for(i=0;i<n;i++){
        if(i==0){
            wait[i]=0;
            
        }
        else
        {
            wait[i]=wait[i-1]+burst[i-1];
            
        }
        ta[i]=wait[i]+burst[i];
    }
    for(i=0;i<n;i++){
        aw=aw+wait[i];
        at=at+ta[i];
    }
    
     printf("\n");
    printf("Process");
    
    printf("\t");
     printf("\t");
    printf("Burst time");
    printf("\t");
    printf("Waiting time");
    printf("\t");
    
printf("Turn around time");
printf("\n");
for(j=0;j<n;j++){

    
printf("P%d",j+1);
 printf("\t");
     printf("\t");
printf("%d",burst[j]);
printf("\t");
     printf("\t");
printf("%d",wait[j]);
printf("\t");
     printf("\t");
printf("%d",ta[j]);
printf("\t");
     printf("\t");
printf("\n");

}
printf("\n");
printf("Average waiting time = %0.2f",aw/n);
printf("\n");
printf("Average turnaround time = %0.2f",at/n);
printf("\n");
}