#include<graphics.h>
#include<iostream>
using namespace std;

void draw(int x1,int y1,int x2,int y2)
{
    int dx=x2-x1;
    int dy=y2-y1;

    int d=2*dy-dx;
    putpixel(x1,y1,WHITE);

    while(x1<=x2)
    {
        if(d<0)
        {
            d+=2*dy;
        }
        else
        {
            d+=2*(dy-dx);
            y1++;
        }
        x1++;
        putpixel(x1,y1,WHITE);
    }
}
void line1(int x1,int y1,int x2,int y2)
{
    int dx=x2-x1;
    int dy=y2-y1;
    int d=2*dx-dy;
    while(y1<=y2)
    {
        if(d<0)
        {
            d+=2*dx;
        }
        else
        {
            d+=2*(dx-dy);
            x1++;
        }
        y1++;
        putpixel(x1,y1,WHITE);
    }
}
int main()
{
    char ch;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\tc\\bgi");

    for(int i=0;i<450;i+=5)
    {
    draw(0,320,800,320);
    draw(50+i,10,150+i,10);
    draw(50+i,50,150+i,50);
    draw(20+i,80,180+i,80);
    draw(20+i,180,180+i,180);
    draw(20+i,220,85+i,220);
    draw(20+i,220,180+i,220);
    line1(20+i,80,10+i,130);
    line1(50+i,10,50+i,50);
    line1(150+i,10,150+i,50);
    line1(85+i,50,85+i,80);
    line1(115+i,50,115+i,80);
    line1(20+i,80,20+i,180);
    line1(180+i,80,180+i,180);
    line1(20+i,180,20+i,220);
    line1(180+i,180,180+i,220);
    line1(100+i,180,85+i,220);
    line1(100+i,20,100+i,30);
    line(20+i,80,10+i,170);
    line1(180+i,80,190+i,170);

    circle(100+i,40,5);
    circle(70+i,20,5);
    circle(130+i,20,5);
    if(i%2==0){
    line1(50+i,220,90+i,320);
    line1(150+i,220,150+i,320);

    //circle(70,20,5);
    //draw(125,20,135,20);
    }
    else
    {
        line1(50+i,220,50+i,320);
        line1(150+i,220,190+i,320);
        //circle(130,20,5);
        //draw(65,20,75,20);
    }
    delay(500);
    cleardevice();
    }
    getch();
    closegraph();
    return 0;
}
