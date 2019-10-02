#include<graphics.h>
#include<iostream>
using namespace std;

void CircleSymmetry(int x,int y)
{
    delay(100);
    putpixel(x+200,y+200,WHITE);
    putpixel(x+200,-1*y+200,WHITE);
    putpixel(-1*x+200,-1*y+200,WHITE);
    putpixel(-1*x+200,y+200,WHITE);
    putpixel(y+200,x+200,WHITE);
    putpixel(y+200,-1*x+200,WHITE);
    putpixel(-1*y+200,-1*x+200,WHITE);
    putpixel(-1*y+200,x+200,WHITE);
}

void Circle(int x,int y,int r)
{
    x=0;
    y=r;
    int d=1-r;
    int deltaE=3;
    int deltaSE=5-2*r;
    CircleSymmetry(x,y);
    while(x<=y)
    {
        if(d<0)/*select E*/
        {
            d+=deltaE;
            deltaE+=2;
            deltaSE+=2;
        }
        else
        {
            d+=deltaSE;
            deltaE+=2;
            deltaSE+=4;
            y--;
        }
        x++;

        CircleSymmetry(x,y);
    }
}


int main()
{

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    int a,b,r;
    cout<<"Enter center coordinates : ";
    cin>>a>>b;
    cout<<"Enter radius : ";
    cin>>r;
    circle (a,b,r);
    getch();
    closegraph();
    return 0;
}
