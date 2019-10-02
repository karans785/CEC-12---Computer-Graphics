#include<graphics.h>
#include<iostream>
#include<math.h>
using namespace std;
void parabola( int x,int y,double p)
{
    double d =1-p;
    putpixel(x+200,y+200,GREEN);
    while(x<p)
    {
        if(d<0)
        {
            d+=(2*x+3);
        }
        else
        {
            d+=((2*x)+3-(2*p));
            y--;
        }
        x++;
        putpixel(x+200,y+200,GREEN);
        delay(20);
        putpixel(-1*x+200,y+200,GREEN);
    }
    d=pow((x+1/2),2)+(2*(y-1)*p);
    while(y>-170)
    {
        if(d<0)
        {
            d+=2*x-2*p+2;
            x++;
        }
        else
        {
            d+=(-2*p);
        }
        y--;
        putpixel(x+200,y+200,GREEN);
        delay(20);
        putpixel(-1*x+200,y+200,GREEN);
    }

}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    setcolor(YELLOW);
    line(200,700,200,-100);
    line(-200,200,800,200);
    cout<<"Enter the value of 'a' for parabola : ";
    int a;
    cin>>a;
    parabola(0,0,a);
    getch();
    closegraph();
    return 0;
}
