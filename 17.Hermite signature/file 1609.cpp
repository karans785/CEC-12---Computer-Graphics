#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
int x1=300;
int z1=0,x,y;
void hermite(vector<pair<int,int> > v){
    vector<pair<int,int> > ret;
    ret.push_back(make_pair(2*v[0].first-2*v[1].first+v[2].first+v[3].first, 2*v[0].second-2*v[1].second+v[2].second+v[3].second));
    ret.push_back(make_pair(-1*3*v[0].first+3*v[1].first-2*v[2].first-v[3].first, -1*3*v[0].second+3*v[1].second-2*v[2].second-v[3].second));
    ret.push_back(make_pair(v[2].first, v[2].second));
    ret.push_back(make_pair(v[0].first, v[0].second));
    for(int i=0;i<4;i++){
        cout<<ret[i].first<<" "<<ret[i].second<<endl;
    }
    for(double t=0; t<=1; t+=0.0001){
        double x = t*t*t*ret[0].first+ t*t*ret[1].first + t*ret[2].first + ret[3].first;
        double y = t*t*t*ret[0].second+ t*t*ret[1].second + t*ret[2].second + ret[3].second;
        //cout<<x<<" "<<y<<endl;
        putpixel(x,y,WHITE);
    }

}
void CircleSymmetry1(int x,int y)
{
    putpixel(x,y,WHITE);
    putpixel(x,-1*y,WHITE);
    putpixel(-1*x,-1*y,WHITE);
    putpixel(-1*x,y,WHITE);
    putpixel(y,x,WHITE);
    putpixel(y,-1*x,WHITE);
    putpixel(-1*y,-1*x,WHITE);
    putpixel(-1*y,x,WHITE);
}

void CircleSymmetry2(int x,int y)
{
    putpixel(x,y,WHITE);
    putpixel(x,-1*y,WHITE);
    putpixel(-1*x,-1*y,WHITE);
    putpixel(-1*x,y,WHITE);
}

void circle2(int x,int y,int r)
{
    x=0;
    y=r;
    int d=1-r;
    int deltaE=3;
    int deltaSE=5-2*r;
    CircleSymmetry2(x,y);
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

        CircleSymmetry2(x,y);
    }
}
void circle1(int x,int y,int r)
{
    x=0;
    y=r;
    int d=1-r;
    int deltaE=3;
    int deltaSE=5-2*r;
    CircleSymmetry1(x,y);
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

        CircleSymmetry1(x,y);
    }
}
void display(double i)
{
    line(300,0,300,200);
    circle(300,300,100);
    circle(300,225,25);
    circle(375,300,25);
    circle(300,375,25);
    circle(225,300,25);
    circle(300,300,10);
    circle(250,250,25);
    circle(250,350,25);
    circle(350,250,25);
    circle(350,350,25);
    circle(350,250,10);
    circle(300,375,10);
    line(300,210,300,240);
    line(350,335,350,365);
    vector<pair<int,int> > v;

    ///2
    v.push_back(make_pair(250,265));
    v.push_back(make_pair(250,235));
    v.push_back(make_pair(50,0));
    v.push_back(make_pair(-50,0));
    hermite(v);
    v.clear();
    line(250,265,260,265);
    //outtextxy(375,300,"6");
    ///6
    v.push_back(make_pair(385,285));
    v.push_back(make_pair(385,310));
    v.push_back(make_pair(-20,15));
    v.push_back(make_pair(5,10));
    hermite(v);
    v.clear();
    v.push_back(make_pair(385,310));
    v.push_back(make_pair(380,300));
    v.push_back(make_pair(15,0));
    v.push_back(make_pair(-75,0));
    hermite(v);
    v.clear();

    v.push_back(make_pair(260,335));
    v.push_back(make_pair(260,360));
    v.push_back(make_pair(-60,0));
    v.push_back(make_pair(40,0));
    hermite(v);
    v.clear();
    v.push_back(make_pair(260,360));
    v.push_back(make_pair(250,350));
    v.push_back(make_pair(40,0));
    v.push_back(make_pair(-50,0));
    hermite(v);
    v.clear();
    ///9

    v.push_back(make_pair(225,290));
    v.push_back(make_pair(225,300));
    v.push_back(make_pair(-25,0));
    v.push_back(make_pair(75,0));
    hermite(v);
    v.clear();
     v.push_back(make_pair(225,305));
    v.push_back(make_pair(225,290));
    v.push_back(make_pair(0,110));
    v.push_back(make_pair(0,-110));
    hermite(v);
    v.clear();

	delay(30);
}
int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    double i;
    while(!kbhit())
	{
		for(i=2;i>1;i=i-0.01)
			display(i);
		for(i=1;i<2;i=i+0.01)
			display(i);
	}

    getch();
    closegraph();
    return 0;
}

