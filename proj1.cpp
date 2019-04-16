
using namespace std;
#include<string.h>
#include<iostream>
#include<unistd.h>

int t = 0;

int br_t =0;
class Process
{
 public:
  int pid;
  int pr;
  int arr_time;
  int burst_time;
  int comp_t;
  int wt_t;
  int ta_t;
public:
  Process()
  {
  
   }
  
  void show()
  {
    
    cout<<this->pid  <<"         " <<this->arr_time <<"               " <<this->pr <<"              " <<this->burst_time <<"\n";
    }
  //friend void Proc_Schedular(Process *p,int n);
 
  

};




void Proc_Schedular(Process *p,int n,int time_q) 
{
 
int count =0;
 int bt[n];
 
for(int i= 0;i<n;i++)
bt[i] = p[i].burst_time;

 printf("%d , %d",t,br_t);
 while (1) 
	{ 
		bool done = true; 
                if(t >= br_t)
                 break;
              
		for (int i = 0 ; i < n; i++) 
		{ 
		    int l =0;
                    if(t >= br_t)
                        break;
               
                      count =0;

                        if(p[i].arr_time <= t)
                           {
                                      if(p[i].burst_time>0){
                                          	done = false; 
                                                printf("\ni : %d \nwait Process %d is running at %d second\n",i,p[i].pid,t);
                                               int j =i+1;
                                                
                                  while(j<n)
                                     {
                                       if(p[j].arr_time>=t+time_q)
                                                    break;
                                          else if(p[j].pr>p[i].pr)
                                               {      int a =0;
                                                      if(p[j].arr_time - t >= 0){
                                                   p[i].burst_time-=p[j].arr_time-t;
                                                            
                                                           a =p[j].arr_time - t;
                                                          t = p[j].arr_time;
                                                           sleep(a/10);}
                                printf("\nprocess %d runs for %d seconds \nprocess %d preempted by process id : %d\n",p[i].pid,a,p[i].pid,p[j].pid);
                                                         
                                                          Process temp =  p[i];
                                                          p[i] = p[j];
                                                          p[j] = temp;
                                                          l++;
                                                          break;
                                                          
                                                               
                                                    }
                                            else
                                                j++;
                                        }
                                    if(l==1)
                                       {i--;
                                         printf("\ni :%d " ,i );
                                          continue;
                                                }
                                              /*  if(p[i].pr <p[i+1].pr && p[i+1].arr_time <=t+time_q)
                                                         { 
                                                           p[i].burst_time-=p[i+1].arr_time-t;
                                                           int a =p[i+1].arr_time - t;
                                                           sleep(a/10);
                                printf("\nprocess %d runs for %d seconds \nprocess %d preempted by process id : %d\n",p[i].pid,a,p[i].pid,p[i+1].pid);
                                                           t = p[i+1].arr_time;
                                                           continue;
                                                              }      */
			                    	if (p[i].burst_time > time_q) 
			                        	{ 
			  		                      
				                        	t += time_q;
                                                                sleep(time_q/10);
                                                                printf("\n%d runs for %d seconds\n",p[i].pid,time_q);
                                                                p[i].burst_time -= time_q;
                                                                
                                                                 
				                          } 

				
				                  else
				                          { 
				                               
				                                t = t + p[i].burst_time; 
                                                                sleep(p[i].burst_time/10);
                                                                printf("\n%d runs for %d seconds\n",p[i].pid,p[i].burst_time);
				                          	p[i].burst_time = 0; 
                                                                p[i].comp_t = t;
                                                                p[i].ta_t  = p[i].comp_t - p[i].arr_time;
                                                                p[i].wt_t = p[i].comp_t-bt[i]-p[i].arr_time;
				                               }            
                                              
			                 }  
                               }

                                 
                      else {
                              done = false;
                                 for(int k =0;k<n-1;k++)
                                      { if(p[k].burst_time>0)
                                           break;
                                          else
                                              count++;
                                           } 
                                //printf("%d",p[i].arr_time);
                               // printf("\n %d ",t);
                               break;
                              }
                       
		} 
                if(count == n-1)
                   break;

		// If all processes are done 
		if (done == true) 
		break; 
	} 
      

    if(t<br_t)
        t = br_t;
     Process *q = p;
    // for(int j=0;j<n;j++)
     //     q[j]=p[j];
   for(int j=0;j<n-1;j++)
    {
     for(int k=0 ;k<n-j-1;k++)
        { 
          if(q[k].pr<q[k+1].pr)
           {
              Process temp = q[k];
              q[k] = q[k+1];
              q[k+1] = temp;
              int tmp = bt[k];
              bt[k] = bt[k+1];
              bt[k+1] = tmp;
              }
          }
      }

  cout<<"\nAll Processes are in ready-state now\n";
  /* cout<<"\nPid  |  Arrival-Time  |  Priority  |  Burst-Time  \n";
    for(int l =0;l<n;l++)
     q[l].show();*/
// ........................................................................start here ................................................................ 

// second queue scheduling ;

   while (1) 
	{ 
		bool done = true; 
          // printf("\nEntered Second Queue");
              
		for (int i = 0 ; i < n; i++) 
		{ 
		      
               
                        if(q[i].arr_time <= t)
                           {
                              
			           if (q[i].burst_time > 0) 
			              { 
			                  	done = false; 
                                                printf("\nwait Process %d is running at %d second \n",q[i].pid,t);
                                    
			                    	if (q[i].burst_time > time_q) 
			                        	{ 
			  		
				                        	t += time_q;
                                                                sleep(time_q/10);
                                                                printf("\n%d runs for %d seconds\n",q[i].pid,time_q);
                                                                q[i].burst_time -= time_q; 
				                          } 

				
				                  else
				                          { 
				
				                           	t = t + q[i].burst_time; 
                                                                sleep(q[i].burst_time/10);
                                                                printf("\n%d runs for %d seconds\n",p[i].pid,q[i].burst_time);
				                          	q[i].burst_time = 0; 
                                                                q[i].comp_t = t;
                                                                q[i].ta_t = q[i].comp_t - q[i].arr_time;
                                                                q[i].wt_t = q[i].comp_t-bt[i]-q[i].arr_time;
				                               }                
                                              
			                   }  
                               }

                                 
                      else {
                              done = false;
                              
                              
                                //printf("\n %d ",t);
                               break;
                              }
                       
		} 
            

		// If all processes are done 
		if (done == true) 
		break; 
	} 
 //..................................................................................................upto this ......................................
  cout<<endl <<"All Processes Executed Successfully \n";
  cout<<"Thank You for your waiting\n";
  
   
  cout<<"----pid----"   <<"----completion-time----"   <<"----wait-time----" << "----Turn-Around-time----"  <<"\n";
   for(int m=0;m<n;m++)
      {
        
         cout<<"|   " <<p[m].pid <<"    |            "  <<p[m].comp_t <<"       |             "  <<p[m].wt_t <<"    |            "<<p[m].ta_t <<endl;
 
          }
 


};




int main()
{
 char ch = 'y';

 do{
  int i = 0,n;
  do{
  cout<<"\nEnter Number of processes you want to schedule : ";
  cin>>n;
    if(n<= 0)
   cout<<"\nOOps wrong value , Try Again\n"; 
   }while(n<=0);
  
  Process P[n];
  for(;i<n;i++)
   {
             int a ;
    cout<<"\n Enter Process ID [p(i)] : ";
       cin>>a;
       if(a < 0)
         {printf("\nOOps wrong value ; Try again \n");i--;continue;}
       P[i].pid =a;
    
    cout<<"\n Enter Process Priority :";
      cin>>a;
        if(a < 0)
         {printf("\nOOps wrong value ; Try again \n");i--;continue;}
       P[i].pr =a ;
    cout<<"\n Enter Arrival Time :";
      cin>>a;
      if(a < 0)
         {printf("\nOOps wrong value ; Try again \n");i--;continue;}
   P[i].arr_time =a;
    cout<<"\n Enter Burst Time :";
     cin>>a;
     if(a < 0)
         {printf("\nOOps wrong value ; Try again \n");i--;continue;}
   P[i].burst_time =a; 
     P[i].comp_t = 0;
     P[i].wt_t =0;
     P[i].ta_t = 0; 
        cout<<endl <<i+1 <<" Process added Successfully \n";
      }

for(int i=0;i<n-1;i++)
    {
     for(int j=0 ;j<n-i-1;j++)
        { 
          if(P[j].arr_time >P[j+1].arr_time)
           {
              Process temp = P[j];
              P[j] = P[j+1];
              P[j+1] = temp;
              }
          }
      }


int time_q=0;
  
  do {cout<<"\n Enter the time Quauntum : ";
  cin>>time_q;
   if(time_q  <=0)
    cout<<"\nOOps wrong value ; Try again \n";
   }while(time_q<=0);
   
  system("clear");
  cout<<"\n Review what you have added \n";
   
  cout<<"\nPid  |  Arrival-Time  |  Priority  |  Burst-Time  \n";
    for(i=0;i<n;i++){
         P[i].show();  
    }
   cout<<"\n Time Quantum is : " <<time_q <<endl;
      br_t = P[n-1].arr_time;
      t = P[0].arr_time;
   //sleep(5);
   Proc_Schedular(P,n,time_q);
     
   printf("\ndo you want to run another time :\nEnter: y or n \n");
   cin>>ch;
           
  
  }while(ch == 'y');
}
