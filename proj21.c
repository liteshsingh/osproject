#include<stdio.h>

int main()
{
   int num_of_cyl;
   printf("Enter number of Cylinders : ");
   scanf("%d",&num_of_cyl);
   
   int cur_pos;
   int pre_pos;
   printf("Enter current position of Head : ");
   scanf("%d",&cur_pos);
   printf("Enter previous position of Head : ");
   scanf("%d",&pre_pos);
   int n;
   printf("Enter number of Queries : ");
   scanf("%d",&n);
   int disk_que[n];
   printf("Enter the cynlinder numbers : ");
   for(int i = 0;i<n;i++)
   scanf("%d",&disk_que[i]);
   
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
 int k = 0;
   for(k=0;k<n;k++)
     if(disk_que[k]>cur_pos)
          break;
   
   if(cur_pos<=pre_pos)
   {     printf("%d - >",cur_pos);
         for(int j = k-1; j>=0;j--) 
           printf("%d - >",disk_que[j]);
     
        for(int j = k; j<n;j++) 
           printf("%d - >",disk_que[j]);


      }
  else
   {
     
      printf("%d - >",cur_pos);
        for(int j = k; j<n;j++) 
           printf("%d - >",disk_que[j]); 
   
         for(int j = k-1; j>=0;j--) 
           printf("%d - >",disk_que[j]);
     
        



      }


}
