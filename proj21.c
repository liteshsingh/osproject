#include<stdio.h>
int get_dist(int a , int b)
{
  if(a>=b)
     return a-b;
  else
     return b-a;

}
int main()
{
   int num_of_cyl;
   printf("Enter number of Cylinders : ");
   do{
   scanf("%d",&num_of_cyl);
    if(num_of_cyl<0)
      printf("\nPlease enter positive number of cylinders\n");
   else if(num_of_cyl < 100)
      printf("\nplease Enter minimum 100 cylinders\n");    
 

     }while(num_of_cyl <100);
   
   int cur_pos;
   int pre_pos;
printf("Enter current position of Head : ");

   do{
   scanf("%d",&cur_pos);
   if(cur_pos>=num_of_cyl || cur_pos <0)
  printf("\nOOps you entered wrong value ; Try again\n");
   if(cur_pos < 0)
    continue;
    }while((cur_pos>num_of_cyl) || cur_pos<0);


   printf("Enter previous position of Head : ");
  do{
   scanf("%d",&pre_pos);
  if(pre_pos>=num_of_cyl || pre_pos<0)
  printf("\nOOps you entered wrong value ; Try again\n");
   }while(pre_pos>num_of_cyl-1 || pre_pos < 0);
   int n;
   
   printf("Enter number of Queries : ");
  do{
   scanf("%d",&n);
    if(n>num_of_cyl || n<0)
  printf("\nOOps you entered wrong value ; Try again\n");
    } while(n>num_of_cyl || n<0);



   int disk_que[n];
   printf("Enter the cynlinder numbers : ");

   for(int i = 0;i<n;i++){
 
      scanf("%d",&disk_que[i]);
         if(disk_que[i]>=num_of_cyl || disk_que[i]<0){
  printf("\nOOps you entered wrong value ; Try again\n");
   i--;
    continue;
     }
 
              }
   
/*  for(int i=0;i<n;i++)    
 {
  for(int j=i;j<n;j++)
  {
    if(disk_que[i]>disk_que[j])
    {
    int temp=disk_que[i];
    disk_que[i]=disk_que[j];
    disk_que[j]=temp;
    }
  }
 }
 int tot_dist;
 int k = 0;
   for(k=0;k<n;k++)
     if(disk_que[k]>cur_pos)
          break;
   */
int distance[n];



   if(cur_pos<=pre_pos)
   {      

      
  for(int i=0;i<n;i++)    
 {
  for(int j=i;j<n;j++)
  {
    if(disk_que[i]>disk_que[j])
    {
    int temp=disk_que[i];
    disk_que[i]=disk_que[j];
    disk_que[j]=temp;
    }
  }
 }
 int tot_dist;
 int k = 0;
   for(k=0;k<n;k++)
     if(disk_que[k]>cur_pos)
          break;






   
   int l=0;
    if(k!=0){
          distance[0] = get_dist(disk_que[k-1],cur_pos);
          l++;}
         printf("%d - >",cur_pos);
         for(int j = k-1; j>=0;j--){
           if(j!=0) 
           distance[l] = disk_que[j] - disk_que[j-1];
           else if(k!=n && j == 0)
            distance[l] = disk_que[k] - disk_que[0];
           if(j == 0)
              printf("%d - > 0 - >",disk_que[0]);
           else
           printf("%d - >",disk_que[j]);
               l++; }
     
        for(int j = k; j<n;j++){ 
           if(j==0)
             distance[l] = disk_que[j] - cur_pos;
           if(j!=0 && k!=0)
           distance[l] = disk_que[j+1]-disk_que[j];
            if(k==0 && j!=0)
            distance[l] = disk_que[j]-disk_que[j-1];
           
           printf("%d - >",disk_que[j]);
            l++;}
 
         for(int i= 0;i<n;i++)
          printf("\ndistance covered in %d movement %d\n",i+1,distance[i]);
     

      }
  else
   {
       
  for(int i=0;i<n;i++)    
 {
  for(int j=i;j<n;j++)
  {
    if(disk_que[i]<disk_que[j])
    {
    int temp=disk_que[i];
    disk_que[i]=disk_que[j];
    disk_que[j]=temp;
    }
  }
 }
 int tot_dist;
 int k = 0;
   for(k=0;k<n;k++)
     if(disk_que[k]<cur_pos)
          break;


     int l=0;
    if(k!=0){
          distance[0] = get_dist(disk_que[k-1],cur_pos);
          l++;}
         printf("%d - >",cur_pos);
         for(int j = k-1; j>=0;j--){
           if(j!=0) 
           distance[l] = get_dist(disk_que[j] , disk_que[j-1]);
           else if(k!=n && j == 0)
            distance[l] = get_dist(disk_que[k] , disk_que[0]);
           printf("%d - >",disk_que[j]);
               l++; }
     
        for(int j = k; j<n;j++){ 
           if(j==0)
             distance[l] = get_dist(disk_que[j] , cur_pos);
           if(j!=0 && k!=0)
           distance[l] = get_dist(disk_que[j+1],disk_que[j]);
            if(k==0 && j!=0)
            distance[l] = get_dist(disk_que[j],disk_que[j-1]);
            if(j == n-1)
               printf("%d - > 0 " , disk_que[n-1]);
           else
           printf("%d - >",disk_que[j]);
            l++;}
 
         for(int i= 0;i<n;i++)
          printf("\ndistance covered in %d movement %d\n",i+1,distance[i]);
     




  
     
      



      }


}
