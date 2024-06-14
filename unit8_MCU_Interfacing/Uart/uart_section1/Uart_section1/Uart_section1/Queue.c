
#include "Queue.h"
#define Queue_Max_size  100
int Queue[Queue_Max_size];

int rear=-1,front=-1 ;


bool isEmpty()
{
    if(rear ==-1 && front==-1)
    {
        return true;
    }
    else 
       return false;
}

bool isFULL()

{
     if(rear ==Queue_Max_size-1)
    {
        return true;
    }
    else 
       return false;
}


void Queue_push(uint8_t data)
{
   
   if(!isFULL())
   {
      Queue[++rear]=data;
   }
   else
   {
//     printf("Over flow\n");
     return -1;
   }


}

uint8_t Queue_pop()
{
    if(!isEmpty())
    {
        return Queue[front++];
    }
    else
    {
  //      printf("Under flow\n");
        return -1;
    }
}


