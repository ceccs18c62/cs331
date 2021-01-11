#include<stdio.h>
void main(){
    int burst[100],wait[100],ta[100],ar[100],com[100],temp[100];
    int n,j,i,q,g=0,f=1,p=0,a;
    float at=0,aw=0;
    
    printf("\n");
     printf("Give the no. of process \n");
    scanf("%d",&n);
    printf("\n");
    printf("give the burst time and arriving time of \n");
    for(i=0;i<n;i++){
        printf("P%d:",i+1);
        scanf("%d",&burst[i]);
        scanf("%d",&ar[i]);
        temp[i]=burst[i];

    }
    printf("Give quantum time \n");
    scanf("%d",&q);
    
    a=burst[0];
    for(i=1;i<n;i++){
     if(a<burst[i]){
         a=burst[i];
         p=i;
     }
    }
    
    while (f!=0){
    f=0;
    for(i=0;i<n;i++){
    if(burst[i]!=0){
    
    if(burst[i]>q){
        f = 1;
        burst[i]=burst[i]-q;
        g=g+q;

    }
    else if (burst[i]>0 && burst[i]<=q)
    {
      g=g+burst[i];
      com[i]=g;

        burst[i]=0;
    }
    
    }
}
    }
    com[p]=g;
    for(i=0;i<n;i++){
ta[i]=com[i]-ar[i];
wait[i]=ta[i]-temp[i];
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
printf("%d",temp[j]);
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