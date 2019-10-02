#include <iostream>
#include <graphics.h>
using namespace std;

void circlesymm(int x,int y,int a,int b){
    putpixel(x+a,y+b,15);
    putpixel(y+a,x+b,15);
    putpixel(-x+a,y+b,15);
    putpixel(x+a,-y+b,15);
    putpixel(-x+a,-y+b,15);
    putpixel(-y+a,-x+b,15);
    putpixel(y+a,-x+b,15);
    putpixel(-y+a,x+b,15);
}

void mycircle(int a,int b,int r){
    /*a,b=centre r=radius*/
    int x=0;
    int y=r;
    int d=1-r;
    circlesymm(x,y,a,b);
    while(x<=y){
        if(d<0)
            d+=(2*x+3);
        else{
            d+=(2*(x-y)+5);
            y--;
        }
        x++;
        circlesymm(x,y,a,b);
    }
}

void circlesymmb(int x,int y,int a,int b){
    putpixel(x+a,y+b,0);
    putpixel(y+a,x+b,0);
    putpixel(-x+a,y+b,0);
    putpixel(x+a,-y+b,0);
    putpixel(-x+a,-y+b,0);
    putpixel(-y+a,-x+b,0);
    putpixel(y+a,-x+b,0);
    putpixel(-y+a,x+b,0);
}

void mycircleb(int a,int b,int r){
    /*a,b=centre r=radius*/
    int x=0;
    int y=r;
    int d=1-r;
    circlesymmb(x,y,a,b);
    while(x<=y){
        if(d<0)
            d+=(2*x+3);
        else{
            d+=(2*(x-y)+5);
            y--;
        }
        x++;
        circlesymmb(x,y,a,b);
    }
}


/*
y*y=2*p*x
*/
void parabolasymm(int x,int y,int a,int b){
    putpixel(x+a,y+b,15);
    putpixel(x+a,-y+b,15);
}

void myparabola(double x0,double y0,double p,double a,double b)
{
    double x=x0;
    double y=y0;
    double d=(y0-0.5)*(y0-0.5)-(2*p*(x0-1));
    parabolasymm(x,y,a,b);
    while(p<=y){
        if(d>0){
            d+=2*(1-y+p);
            y--;
        }
        else{
            d+=2*p;
        }
        x--;
        parabolasymm(x,y,a,b);
    }
    d=(y-1)*(y-1)-(2*p*(x-0.5));
    while(y>0){
        if(d<0){
            d+=(3-2*y+2*p);
            x--;
        }
        else
            d+=(3-2*y);
        y--;
        parabolasymm(x,y,a,b);
    }
}

void ball(double x0,double y0,double p,double a,double b,double r)
{
    double x,y,d;
    while(1){
        x=x0;
        y=y0;
        d=(y0-0.5)*(y0-0.5)-(2*p*(x0-1));
        mycircle(x+a+r,y+b,r);
        while(p<=y){
            mycircleb(x+a+r,y+b,r);
            myparabola(200,200,100,250,250);
            if(d>0){
                d+=2*(1-y+p);
                y--;
            }
            else{
                d+=2*p;
            }
            x--;
           mycircle(x+a+r,y+b,r);
           Sleep(50);
        }
        d=(y-1)*(y-1)-(2*p*(x-0.5));
        while(y>0){
            mycircleb(x+a+r,y+b,r);
            myparabola(200,200,100,250,250);
            if(d<0){
                d+=(3-2*y+2*p);
                x--;
            }
            else
                d+=(3-2*y);
            y--;
            mycircle(x+a+r,y+b,r);
            Sleep(50);
        }
        x=0;
        y=0;
        d=1-p;
        mycircle(x+a+r,-y+b,r);
        while(p>y){
            mycircleb(x+a+r,-y+b,r);
            myparabola(200,200,100,250,250);
            if(d>0){
                d+=((y+2)*(y+2)-(2*p*(x+1.5)))-((y+1)*(y+1)-(2*p*(x+0.5)));
                x++;
            }
            else{
                d+=((y+2)*(y+2)-(2*p*(x+0.5)))-((y+1)*(y+1)-(2*p*(x+0.5)));
            }
            y++;
            mycircle(x+a+r,-y+b,r);
            Sleep(50);
        }
        d=(y+0.5)*(y+0.5)-(2*p*(x+1));
        while(x<=x0){
             mycircleb(x+a+r,-y+b,r);
             myparabola(200,200,100,250,250);
            if(d<0){
                d+=((y+1.5)*(y+1.5)-(2*p*(x+2)))-((y+0.5)*(y+0.5)-(2*p*(x+1)));
                y++;
            }
            else
                d+=((y+0.5)*(y+0.5)-(2*p*(x+2)))-((y+0.5)*(y+0.5)-(2*p*(x+1)));
            x++;
            mycircle(x+a+r,-y+b,r);
            Sleep(50);
        }
        mycircleb(x+a+r,-y+b,r);
        x=x0;
        y=y0;
        d=(y0-0.5)*(y0-0.5)-(2*p*(x0-1));
        mycircle(x+a+r,-y+b,r);
        while(p<=y){
            mycircleb(x+a+r,-y+b,r);
            myparabola(200,200,100,250,250);
            if(d>0){
                d+=2*(1-y+p);
                y--;
            }
            else{
                d+=2*p;
            }
            x--;
           mycircle(x+a+r,-y+b,r);
           Sleep(50);
        }
        d=(y-1)*(y-1)-(2*p*(x-0.5));
        while(y>0){
            mycircleb(x+a+r,-y+b,r);
            myparabola(200,200,100,250,250);
            if(d<0){
                d+=(3-2*y+2*p);
                x--;
            }
            else
                d+=(3-2*y);
            y--;
            mycircle(x+a+r,-y+b,r);
            Sleep(50);
        }
        mycircleb(x+a+r,-y+b,r);
        x=0;
        y=0;
        d=1-p;
        mycircle(x+a+r,y+b,r);
        while(p>y){
            mycircleb(x+a+r,y+b,r);
            myparabola(200,200,100,250,250);
            if(d>0){
                d+=((y+2)*(y+2)-(2*p*(x+1.5)))-((y+1)*(y+1)-(2*p*(x+0.5)));
                x++;
            }
            else{
                d+=((y+2)*(y+2)-(2*p*(x+0.5)))-((y+1)*(y+1)-(2*p*(x+0.5)));
            }
            y++;
            mycircle(x+a+r,y+b,r);
            Sleep(50);
        }
        d=(y+0.5)*(y+0.5)-(2*p*(x+1));
        while(x<=x0){
             mycircleb(x+a+r,y+b,r);
             myparabola(200,200,100,250,250);
            if(d<0){
                d+=((y+1.5)*(y+1.5)-(2*p*(x+2)))-((y+0.5)*(y+0.5)-(2*p*(x+1)));
                y++;
            }
            else
                d+=((y+0.5)*(y+0.5)-(2*p*(x+2)))-((y+0.5)*(y+0.5)-(2*p*(x+1)));
            x++;
            mycircle(x+a+r,y+b,r);
            Sleep(50);
        }
        mycircleb(x+a+r,y+b,r);
    }
}

int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    myparabola(200,200,100,250,250);
    ball(200,200,100,250,250,50);
    getch();
    closegraph();
    return 0;
}
