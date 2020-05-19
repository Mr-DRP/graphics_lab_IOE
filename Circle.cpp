#include <iostream>
#include<dos.h>
#include<graphics.h>
#include<math.h>
using namespace std;
void rendercircle (int circx, int circy, int r,int j)
{
    int x=0,y=r;
    int p;
    p=1-r;
    int i=j%8;
    for(;x<=y;)
    {
        putpixel(y+circx, x+circy,1);
        putpixel(x+circx, y+circy,2);
        putpixel(x+circx, -y+circy,3);
        putpixel(-y+circx, x+circy,4);
        putpixel(-y+circx, -x+circy,5);
        putpixel(-x+circx, -y+circy,6);
        putpixel(y+circx, -x+circy,7);
        putpixel(-x+circx, y+circy,8);


        if(p<0)
        {
            x=x+1;
            y=y;
            p=p+2*x+1;
        }
        else
        {
            x=x+1;
            y=y-1;
            p=p+2*x-2*y+1;
        }
    }
}
int main()
{
    int r,i;
    cout<<"Enter radius::";
    cin>>r;
    initwindow(800,800);
    for(int i=1;i<r;i++){
    for(int j=r-5;j<r;j++)
    {
    rendercircle(500,500,j,i);
    }
    delay(1000);
    }
    getch();
    closegraph();
    return 0;
}
