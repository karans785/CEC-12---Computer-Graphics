#include<iostream>
#include<graphics.h>
using namespace std;
class point{
public :
    float x;
    float y;
};
int main()
{
    cout<<"Enter the Xmin,Ymin,Xmax,Ymax points of the clipping window : ";
    int xmin,ymin,xmax,ymax;
    cin>>xmin>>ymin>>xmax>>ymax;
    cout<<"Enter starting and ending points of line : ";
    int x1,y1,x0,y0;
    cin>>x0>>y0>>x1>>y1;
    int gd = DETECT , gm;
    initgraph(&gd,&gm,"c:\\tc\\bgi");
    setcolor(RED);
    line(xmin*100,ymin*100,xmax*100,ymin*100);
    line(xmin*100,ymin*100,xmin*100,ymax*100);
    line(xmax*100,ymax*100,xmax*100,ymin*100);
    line(xmax*100,ymax*100,xmin*100,ymax*100);
    line(x1*100,y1*100,x0*100,y0*100);
    float uk[4],qk[4],pk[4];
    float dx=x1-x0;
    float dy=y1-y0;
    pk[0] = -1*dx;
    pk[1] = dx;
    pk[2] = -1*dy;
    pk[3] = dy;
    qk[0] = x0-xmin;
    qk[1] = xmax-x0;
    qk[2] = y0-ymin;
    qk[3] = ymax-y0;
    point p[4];
    int j=0;
    for(int i=0;i<4;i++)
    {
        uk[i] = (qk[i]/pk[i]);
        if(uk[i]>=0&&uk[i]<=1)
        {
            p[j].x = x0+uk[i]*dx;
            p[j].y = y0+uk[i]*dy;
            j++;
        }
    }
    getch();
    setcolor(YELLOW);
    line(p[0].x*100,p[0].y*100,p[1].x*100,p[1].y*100);
    delay(2000);
    closegraph();
    return 0;
}
