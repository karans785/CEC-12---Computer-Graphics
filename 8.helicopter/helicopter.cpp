#include<iostream>
#include<graphics.h>
using namespace std;
void ellipseSymmetry(int x,int y,int p)
{
    putpixel(x+200+p,y+200,WHITE);
    putpixel(x+200+p,-1*y+200,WHITE);
    putpixel(-1*x+200+p,-1*y+200,WHITE);
    putpixel(-1*x+200+p,y+200,WHITE);
}
void ellipse(int a,int b,int p)
{
    int x=a;int y=0;
    double d=(a*a)-a*b*b-(b*b*(0.25));
    ellipseSymmetry(x,y,p);
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
        ellipseSymmetry(x,y,p);
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
        ellipseSymmetry(x,y,p);
    }
}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    for(int i=0;i<370;i+=5)
    {
        setcolor(WHITE);
        ellipse(100,30,i);
        ellipse(20,5,i);
        line(200+i,200,200+i,250);
        line(125+i,250,275+i,250);
        line(125+i,320,275+i,320);
        line(125+i,250,125+i,320);
        line(275+i,250,275+i,320);
        line(125+i,320,275+i,320);
        line(175+i,320,165+i,350);
        line(225+i,320,235+i,350);
        line(155+i,350,245+i,350);
        line(50+i,285,125+i,267);
        line(50+i,285,125+i,302);
        circle(50+i,285,10);

        if(i%2!=0)
        {
        setcolor(YELLOW);
        line(200+i,200,260+i,176);
        //nw
        setcolor(BLUE);
        line(200+i,200,140+i,176);
        //sw
        setcolor(GREEN);
        line(200+i,200,140+i,224);
        //se
        setcolor(RED);
        line(200+i,200,260+i,224);
        }
        else if(i%2==0)
        {
             if(i%2==0)
        {

            setcolor(GREEN);
            line(200+i,200+5,200+i,30+200);
            setcolor(YELLOW);
            line(200+i,200-5,200+i,200-30);
            setcolor(RED);
            line(200+20+i,200,200+100+i,200);
            setcolor(CYAN);
            line(200-20+i,200,200-100+i,200);
        }
        else if(i%3==0)
        {
            setcolor(RED);
            line(200+i,200+5,200+i,30+200);
            setcolor(CYAN);
            line(200+i,200-5,200+i,200-30);
            setcolor(YELLOW);
            line(200+20+i,200,200+100+i,200);
            setcolor(GREEN);
            line(200-20+i,200,200-100+i,200);
        }
        else if(i%4==0)
        {
            //upar
            setcolor(CYAN);
            line(200+i,200+5,200+i,30+200);
            //neche
            setcolor(YELLOW);
            line(200+i,200-5,200+i,200-30);
            //right
            setcolor(RED);
            line(200+20+i,200,200+100+i,200);
            //left
            setcolor(GREEN);
            line(200-20+i,200,200-100+i,200);
        }
        else
        {
            //upar
            setcolor(GREEN);
            line(200+i,200+5,200+i,30+200);
            //neche
            setcolor(RED);
            line(200+i,200-5,200+i,200-30);
            //right
            setcolor(CYAN);
            line(200+20+i,200,200+100+i,200);
            //left
            setcolor(YELLOW);
            line(200-20+i,200,200-100+i,200);
        }
        }
        getch();
        delay(300);
        cleardevice();
    }
    getch();
    closegraph();
    return 0;
}

