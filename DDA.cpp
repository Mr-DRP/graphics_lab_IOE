#include<iostream>
#include<cmath>
#include<graphics.h>
using namespace std;
int main()
{   float x0,y0,x1,y1,length,dx,dy;
    float xinc,yinc;
    cout<<"Enter the first coordinate:";
    cin>>x0>>y0;
    cout<<"Enter the last coordinate:";
    cin>>x1>>y1;
    dx=x1-x0;
    dy=y1-y0;
    if (abs(dx)>abs(dy))
        length=abs(dx);
    else
        length=abs(dy);
    xinc=dx/length;
    yinc=dy/length;
    initwindow(500,800);
    for(int v=0;v<length;v++)
    {   putpixel(x0,y0,RED);
        x0=x0+xinc;
        y0=y0+yinc;
        delay(10);
    }
    getch();
}

