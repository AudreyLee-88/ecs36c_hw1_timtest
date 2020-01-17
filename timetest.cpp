/*
 Xiangning Gao 998547853
*/
#include "CPUTimer.h"
#include "CursorList.h"
vector< CursorNode <int> > cursorSpace(500001);
#include "LinkedList.h"
#include "QueueAr.h"
#include "SkipList.h"
#include "StackAr.h"
#include "StackLi.h"
#include <iostream>
#include <fstream>

#include <stdlib.h>


int getChoice();
void RunList (char* name);
void RunCursorList (char* name);
void RunStackAr (char* name);
void RunStackLi (char* name);
void RunQueueAr (char* name);
void RunSkipList (char* name);
int main()
{
  char Name[20];
  int choice;
  cout << "Filename >> ";
  cin >> Name;
  CPUTimer ct;
  do
  {
    choice = getChoice();
    ct.reset();
    switch (choice)
    {
      case 1: RunList (Name); break;
      case 2: RunCursorList (Name); break;
      case 3: RunStackAr (Name); break;
      case 4: RunStackLi (Name); break;
      case 5: RunQueueAr (Name); break;
      case 6: RunSkipList (Name); break;
    }
    cout << "CPU time: " << ct.cur_CPUTime() << endl;;
  } while (choice > 0);

}

int getChoice()
{
  int choice = 0;
  cout << endl;
  cout << "      ADT Menu" << endl;
  cout << "0. Quit" << endl;
  cout << "1. LinkedList" << endl;
  cout << "2. CursorList" << endl;
  cout << "3. StackAr" << endl;
  cout << "4. StackLi" << endl;
  cout << "6. SkipList" << endl;
  cout << "Your choice >> " ;
  cin >> choice;
  return choice;
}

void RunList (char* name)
{
  List<int> list;
  char x;
  int num;
  ListItr<int> position;
  position = list.zeroth();
  ifstream myfile;
  myfile.open(name);
  myfile.ignore(500, '\n');
  while (myfile >> x >> num)
  {
      if (x =='i')
      {
          list.insert(num,position);
      }
      else{
          list.remove(num);
      }
  }

}

void RunCursorList (char* name)
{
    CursorList<int> cursor(cursorSpace);
    CursorListItr<int> position = cursor.zeroth();
    char x;
    int num;
    ifstream myfile;
    myfile.open(name);
    myfile.ignore(500, '\n');
    while (myfile >> x >> num)
    {
        if (x =='i')
        {
            cursor.insert(num,position);
        }
        else{
            cursor.remove(num);
        }
    }
    
}

void RunStackAr (char* name)
{
  StackAr<int> stackar(500001);
  char x;
  int num;
    ifstream myfile;
    myfile.open(name);
    myfile.ignore(500, '\n');
    while (myfile >> x >> num)
    {
        if (x =='i')
        {
            stackar.push(num);
        }
        else{
            stackar.pop();
        }
    }
}

void RunStackLi (char* name)
{
  StackLi<int> stackli;
  char x;
  int num;
    ifstream myfile;
    myfile.open(name);
    myfile.ignore(500, '\n');
    while (myfile >> x >> num)
    {
        if (x =='i')
        {
            stackli.push(num);
        }
        else
        {
            stackli.pop();
        }
    }
}

void RunQueueAr (char* name)
{
  Queue<int> queue(5000000);
  char x;
  int num;
    ifstream myfile;
    myfile.open(name);
    myfile.ignore(500, '\n');
    while (myfile >> x >> num)
    {
        if (x =='i')
        {
            queue.enqueue(num);
        }
        else{
            queue.dequeue();
        }
    }
}

void RunSkipList (char* name)
{
  SkipList<int> skiplist(-1, 250000);
  char x;
  int num;
  ifstream myfile;
  myfile.open(name);
  myfile.ignore(500, '\n');
  while (myfile >> x >> num)
  {
     if (x =='i')
     {
          skiplist.insert(num);
     }
     else
     {
         skiplist.deleteNode(num);
     }
  }
}
