#include<iostream>
#include<cmath>
#include<graphics.h>
using namespace std;
int main()
{   float x0,y0,x1,y1,length,dx,dy,absDx,absDy;
    float xinc,yinc,d;
    cout<<"Enter the first coordinate:";
    cin>>x0>>y0;
    cout<<"Enter the last coordinate:";
    cin>>x1>>y1;
    dx=x1-x0;
    dy=y1-y0;
    absDx=abs(dx);
    absDy=abs(dy);
    initwindow(800,600);
    if(x0<x1) //variable declaration
            xinc=1;
          else
            xinc=-1;
    if(y0<y1)
            yinc=1;
          else
            yinc=-1;
    if(absDx>absDy)
    {
        d=2*absDy-absDx;
          while(x0!=x1)
          {
              if(d>0)
              {
                  d=d+2*absDy-2*absDx;
                  y0+=yinc;
              }
              else
                  d=d+2*absDy;
              x0+=xinc;
              putpixel(x0,y0,RED);
              delay(10);
          }
    }
    else
     {
          d=2*absDx-absDy;

          while(y0!=y1)
          {
             if(d>0)  // x changes
             {
                d=d+2*absDx-2*absDy;
                x0+=xinc;
             }
             else   // x remains same
                 d=d+2*absDx;
             y0+=yinc;
             delay(10);
             putpixel(x0,y0,RED);
          }
     }
    getch();
}

