#include <iostream>
#include <vector>
#include <graphics.h>
#include <algorithm>
using namespace std;
struct pt{
    float x,y;
};
pt diff(pt a,pt b){
    pt temp;
    temp.x=b.x-a.x;
    temp.y=b.y-a.y;
    return temp;
}
pt normal(pt ab){
    pt temp=ab;
    float c=temp.x;
    temp.x=temp.y;
    temp.y=c;
    if(temp.x>0&&temp.y>0)
        temp.x*=-1;
    else if(temp.x<0&&temp.y>0)
        temp.y*=-1;
    else if(temp.x<0&&temp.y<0)
        temp.x*=-1;
    else
        temp.y*=-1;
    return temp;
}
float dotproduct(pt ab,pt cd){
    float res;
    res=ab.x*cd.x+ab.y*cd.y;
    return res;
}
pt sum (pt a, pt b){
    pt temp;
    temp.x = a.x + b.x;
    temp.y = a.y +b.y;

    return temp;
}
pt mulScalar(float t, pt ab) {
    ab.x*=t;
    ab.y*=t;
    return ab;
}
vector <pair < pt , float > > cyrusbeck(pt p1,pt p2,pt* cw, int len){
    vector <pair < pt , float > > res;
    vector <pair<float, float> > tees;
    for (int i =0; i<len; i++){
        pt a=cw[i];
        pt b=cw[(i+1)%len];
        pt ab = diff(a,b);
        pt Nab = normal(ab);
        pt ap1 = diff(a,p1);
        float dot1 = dotproduct(Nab, ap1);
        float dot2 = -1* dotproduct(Nab, diff(p1,p2));
        float t = float((float)dot1/(float)dot2);
        if (t >0 && t<1){
            tees.push_back(make_pair(t, dot2>0?0:1));
        }

    }
    sort(tees.begin(), tees.end());
    for (float i =0; i<tees.size(); i++){
        pt temp = sum(p1,mulScalar(tees[i].first, diff(p1,p2)));
        res.push_back(make_pair(temp, tees[i].second));
    }
    return res;
}
int main()
{
    int n;
    pt p1,p2;
    cout<<"Enter the vertices of the line\n";
    cin>>p1.x>>p1.y>>p2.x>>p2.y;
    cout<<"Enter the size of the clipping window\n";
    cin>>n;
    cout<<"Enter the vertices of the clipping window\n";
    pt* cw=new pt[n];
    for(int i=0;i<n;i++)
        cin>>cw[i].x>>cw[i].y;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TC\\BGI");
    line(p1.x,p1.y,p2.x,p2.y);
    for(int i=0;i<n;i++)
        line(cw[i].x,cw[i].y,cw[(i+1)%n].x,cw[(i+1)%n].y);
    delay(2000);
    vector<pair<pt,float> > res=cyrusbeck(p1,p2,cw,n);
    if(res.size()==2){
        line(res[0].first.x,res[0].first.y,res[1].first.x,res[1].first.y);
        setcolor(BLACK);
        line(p1.x,p1.y,res[0].first.x,res[0].first.y);
        line(res[1].first.x,res[1].first.y,p2.x,p2.y);
    }
    else if(res.size()==1){
        if(res[0].second==1){
            line(p1.x,p1.y,res[0].first.x,res[0].first.y);
            setcolor(BLACK);
            line(res[0].first.x,res[0].first.y,p2.x,p2.y);
        }
        else{
            line(res[0].first.x,res[0].first.y,p2.x,p2.y);
            setcolor(BLACK);
            line(p1.x,p1.y,res[0].first.x,res[0].first.y);
        }
    }
    getch();
    closegraph();
    return 0;
}
