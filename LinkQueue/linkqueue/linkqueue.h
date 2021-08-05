#ifndef LINKQUEUE_H_
#define LINKQUEUE_H_

#include<stdio.h>
#include<stdlib.h>

#define Ok 1
#define Error 0
typedef int QElemType;
typedef int Status;
typedef struct QNode
{
   QElemType data;
   struct QNode *next;
}QNode;
typedef struct QNode *QueuePtr;

typedef struct 
{
 QueuePtr front,rear;   
}LinkQueue;






#endif