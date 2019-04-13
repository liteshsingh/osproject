
using namespace std;
#include<string.h>
#include<iostream>
#include<exception>
#include<typeinfo>
int t = 0;

int br_t =0;
class Process
{
 public:
  int pid;
  int pr;
  int arr_time;
  int burst_time;
  int comp_t=0;
  int wt_t = 0;
public:
  Process()
  {
  
   }
 void get_attr()
  {
  
    cout<<"Enter Process ID [p(i)]: ";
    cin>>this->pid;
    cout<<"Enter Process Priority:";
    cin>>this->pr;
    cout<<"Enter Arrival Time:";
    cin>>this->arr_time;
    cout<<"Enter Burst Time:";
    cin>>this->burst_time; 
     this->comp_t = 0;
       
    }
  
  void show()
  {
    
    cout<<this->pid  <<"         " <<this->arr_time <<"               " <<this->pr <<"              " <<this->burst_time <<"\n";
    }
  friend void Proc_Schedular(Process *p,int n);
 
  

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
		    
                    if(t >= br_t)
                        break;
               
                      count =0;

                        if(p[i].arr_time <= t)
                           {
                                      if(p[i].burst_time>0){
                                          	done = false; 
                                                printf("\n%d is running at %d time",p[i].pid,t);
                                               
                                                if(p[i].pr >p[i+1].pr && p[i+1].arr_time <=t+time_q)
                                                         { 
                                                           p[i].burst_time-=p[i+1].arr_time-t;
                                                           int a =p[i+1].arr_time - t;
                                              printf("\nprocess %d runs for %d \nprocess %d preempted by %d",p[i].pid,a,p[i].pid,p[i+1].pid);
                                                            t = p[i+1].arr_time;
                                                           continue;
                                                              }       
			                    	else if (p[i].burst_time > time_q) 
			                        	{ 
			  		                      
				                        	t += time_q;
                                                                printf("\n%d runs for %d",p[i].pid,t);
                                                                p[i].burst_time -= time_q;
                                                                
                                                                 
				                          } 

				
				                  else
				                          { 
				                               
				                                t = t + p[i].burst_time; 
                                                                printf("\n%d runs for %d",p[i].pid,t);
				                          	p[i].burst_time = 0; 
                                                                p[i].comp_t = t;
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
     Process q[n];
     for(int j=0;j<n;j++)
          q[j]=p[j];
   for(int j=0;j<n-1;j++)
    {
     for(int k=0 ;k<n-j-1;k++)
        { 
          if(q[k].pr>q[k+1].pr)
           {
              Process temp = q[k];
              q[k] = q[k+1];
              q[k+1] = temp;
              }
          }
      }
   cout<<"\nPid  |  Arrival-Time  |  Priority  |  Burst-Time  \n";
    for(int l =0;l<n;l++)
     q[l].show();
  

 // second queue scheduling ;

   while (1) 
	{ 
		bool done = true; 
           printf("\nEntered Second Queue");
              
		for (int i = 0 ; i < n; i++) 
		{ 
		      
               
                        if(q[i].arr_time <= t)
                           {
                              
			           if (q[i].burst_time > 0) 
			              { 
			                  	done = false; 
                                                printf("\n%d is running at %d time",q[i].pid,t);
                                    
			                    	if (q[i].burst_time > time_q) 
			                        	{ 
			  		
				                        	t += time_q;
                                                                q[i].burst_time -= time_q; 
				                          } 

				
				                  else
				                          { 
				
				                           	t = t + q[i].burst_time; 
				                          	q[i].burst_time = 0; 
                                                                p[i].comp_t = t;
                                                                p[i].wt_t = p[i].comp_t-bt[i]-p[i].arr_time;
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
 
   for(int m=0;m<n;m++)
      {
         cout<<"pid       "   <<"comp_t       "   <<"wait_t     ";
         cout<<p[m].pid <<"       "  <<p[m].comp_t <<"       "  <<p[m].wt_t;
 
          }
 


};




int main()
{
 char ch = 'y';

 do{
  int i = 0,n;
  cout<<"Enter Number of processes you want to schedule";
  cin>>n;
  Process P[n];
  for(;i<n;i++)
   {
        P[i].get_attr(); 
        
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

  
  cout<<"\nPid  |  Arrival-Time  |  Priority  |  Burst-Time  \n";
    for(i=0;i<n;i++){
         P[i].show();  
    }
    
      br_t = P[n-1].arr_time;
      t = P[0].arr_time;
  cout<<"Enter the time Quauntum : ";
  cin>>time_q;
 Proc_Schedular(P,n,time_q);
     
  printf("\ndo you want to run another time :\nEnter: y or n \n");
   cin>>ch;
           
  
  }while(ch == 'y');
}
