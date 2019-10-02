#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;

void drawLine(int x1,int y1,int x2,int y2)
{
    int x=x1;
    int y=y1;
    int dx=abs(x2-x1);
    int dy=abs(y2-y1);
    if(dx>dy){
    int d=2*dy-dx;
    putpixel(x,y,GREEN);

    while(x<=x2)
    {
        if(d<0)
        {
            d+=2*dy;
        }
        else
        {
            d+=2*(dy-dx);
            y--;
        }
        x++;
        delay(10);
        putpixel(x,y,GREEN);
    }
    }
    else if(dy>=dx)
    {
    int d=2*dx-dy;
    while(y<=y2)
    {
        if(d<0)
        {
            d+=2*dx;
        }
        else
        {
            d+=2*(dx-dy);
            x++;
        }
        y++;
        delay(10);
        putpixel(x,y,GREEN);
    }
    }
}

int main()
{

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    drawLine(50,80,200,400);
    getch();
    closegraph();
    return 0;
}
