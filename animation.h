#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED
#endif // ANIMATION_H_INCLUDED
#include<iostream>
#include<stdlib.h>
#include<windows.h>
using namespace std;
void text_animation(char a[])
{
    int i;
    double k;
    for(i=0;a[i]!='\0';++i)
    {
        Sleep(100);
        cout<<a[i];
    }
}
 void draw_lint(int a)
    {
        for(int i=1;i<a;i++)
        {
            Sleep(0);
            cout <<"-";
        }
    }
void draw_line_perallel()
{
  for(int i=1;i<27;i++)
        {
            Sleep(1);
            cout <<"|"<<endl;
        }
}

