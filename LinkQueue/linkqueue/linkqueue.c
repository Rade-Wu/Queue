#include <stdio.h>
#include "linkqueue.h"

/*初始化一个队列*/
Status InitQueue(LinkQueue *q)
{
    q->front=q->rear=(QueuePtr)malloc(sizeof(QNode));
    if(!q->front)
    {
        printf("构造队列失败！\n");
        exit(EXIT_FAILURE);
    }
    q->front->next=NULL;
    return Ok;
}

/*入列*/
Status InsertQueue(LinkQueue *q,QElemType e)
{
    QueuePtr p;
    p=(QueuePtr)malloc(sizeof(QNode));
    if(p==NULL)
    exit(EXIT_FAILURE);
    p->next=NULL;
    p->data=e;
    q->rear->next=p;
    q->rear=p;
    return Ok;
}

/*出列*/
Status DeleteQueue(LinkQueue *q,QElemType *e)
{
    QueuePtr p;
    if(q->front==q->rear)
    {
        return Error;
    }
    p=q->front->next;
    *e=p->data;
    q->front->next=p->next;
    if(q->rear==p)           /*如果队列中只有一个元素*/
    {
        q->rear = q->front;
    } 
    free(p);
    return Ok;
}

/*销毁一个队列*/
Status DestoryQueue(LinkQueue *q)
{
    while(q->front)
    {
        q->rear=q->front->next;
        free(q->front);
        q->front=q->rear;
    }
    return Ok;
}

/*清空一个队列*/
Status ClearQueue(LinkQueue *q)
{
    QueuePtr p;
    q->rear=q->front;
    p=q->front->next;
    while(p)
    {
        free(p);
        p=p->next;
    }
    return Ok;
}

/*返回当前队列元素个数*/
int QueueLength(LinkQueue *q)
{
    int count=0;
    QueuePtr p;
    if(q->front==q->rear)
    {
        printf("这是一个空队列！\n");
        return Error;
    }
    p=q->front->next;
    while(p);
    {
        count++;
        p->next;
    }
    return count;
}

/*打印队列中元素*/
void PrintQueue(LinkQueue *q)
{
    QueuePtr p;
    if(q->front==q->rear)
    {
        printf("这是一个空队列！\n");
        return Error;
    }
    p=q->front->next;
    while(p);
    {
        printf("%d\n",p->data);
        p->next;
    }
}

