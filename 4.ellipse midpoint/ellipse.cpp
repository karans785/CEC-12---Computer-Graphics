#include<graphics.h>
#include<iostream>
using namespace std;

void ellipseSymmetry(int x,int y)
{
    putpixel(x+200,y+200,GREEN);
    putpixel(x+200,-1*y+200,GREEN);
    putpixel(-1*x+200,-1*y+200,GREEN);
    putpixel(-1*x+200,y+200,GREEN);
}
void ellipse(int a,int b)
{
    int x=a;int y=0;
    double d=(a*a)-a*b*b-(b*b*(0.25));
    ellipseSymmetry(x,y);
    while(abs(b*b*x)>=abs(a*a*y))
    {
         if(d<0)
        {
            d+=a*a*(3+2*y);
        }
        else
        {
            d+=a*a*(3+2*y) + 2*b*b*(1-x);
            x--;
        }
        y++;
        ellipseSymmetry(x,y);
    }
    d=(b*b)*(x-1)*(x-1)+(a*a*(y+0.5)*(y+0.5))-(a*a*b*b);
    while(!(x<0))
    {
        if(d<0)
        {
            d+=(b*b)*(3-2*x) + 2*a*a*(1+y);
            y++;
        }
        else
        {
            d+=b*b*(3-2*x);
        }
        x--;
        ellipseSymmetry(x,y);
    }
}
int main()
{

    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    cout<<"Enter a and b values for ellipse : ";
    int a,b;
    cin>>a>>b;
    ellipse(a,b);
    getch();
    closegraph();
    return 0;
}
