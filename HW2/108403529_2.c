#include <stdio.h>
#include <stdlib.h>

struct queue
{
  int data;
  struct queue *link;
};
struct queue *front;
struct queue *rear;

void Enqueue(int input);
void Dequeue();
void PrintFront();
char output[100] = {'\0'};
int main()
{

  int option, input_num;
  strcat(output, ">");
  while (1)
  {

    scanf("%d", &option);
    if (option == -1)
    {
      break;
    }

    if (option == 1)
    {
      scanf("%d", &input_num);

      Enqueue(input_num);
    }
    else if (option == 2)
    {
      if (front != NULL)
      {
        PrintFront();
      }
      else
        strcat(output, " -2");
    }
    else if (option == 3)
    {
      if (front != NULL)
      {
        Dequeue();
      }
      else
        strcat(output, " -3");
    }
  }
  printf("%s", output);
  return 0;
}

void Enqueue(int input)
{
  struct queue *temp;

  temp = (struct queue *)malloc(sizeof(struct queue)); //分配node空間
  temp->data = input;                                  //把資料放進node
  temp->link = NULL;                                   // node的指向NULL

  if (front == NULL)
  { // queue裡面有資料
    front = temp;
    rear = temp;
    front->link = NULL;
    rear->link = NULL;
  }
  else
  { // queue 為空 插入為第一個新的值
    rear->link = temp;
    rear = temp;
    rear->link = NULL;
  }
}

void Dequeue()
{
  struct queue *temp;
  temp = front;
  front = front->link;
  free(temp);
}

void PrintFront()
{
  char tmp[5];

  tmp[0] = front->data + '0';

  strcat(output, " ");
  strncat(output, tmp, 1);
  tmp[0] = '\0';
}
