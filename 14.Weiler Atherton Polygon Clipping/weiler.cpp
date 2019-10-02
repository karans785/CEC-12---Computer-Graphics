#include <iostream>
#include <vector>
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
    int m,n;
    cout<<"Enter the size of the subject polygon\n";
    cin>>m;
    cout<<"Enter the vertices of the subject polygon\n";
    pt* sp=new pt[m];
    for(int i=0;i<m;i++)
        cin>>sp[i].x>>sp[i].y;
    cout<<"Enter the size of the clipping window\n";
    cin>>n;
    cout<<"Enter the vertices of the clipping window\n";
    pt* cw=new pt[n];
    for(int i=0;i<n;i++)
        cin>>cw[i].x>>cw[i].y;
    vector <pair < pt , float > > nsp;
    vector <pair < pt , float > > ncw;
    for(int i=0;i<m;i++){
        pt p1=sp[i];
        pt p2=sp[(i+1)%m];
        nsp.push_back(make_pair(p1,-1));
        vector<pair<pt,float> > res=cyrusbeck(p1,p2,cw,n);
        for(float i=0;i<res.size();i++)
            nsp.push_back(res[i]);
    }
    for(int i=0;i<n;i++){
        pt p1=cw[i];
        pt p2=cw[(i+1)%n];
        ncw.push_back(make_pair(p1,-1));
        vector<pair<pt,float> >res=cyrusbeck(p1,p2,sp,m);
        for(float i=0;i<res.size();i++)
            ncw.push_back(res[i]);
    }
    cout<<'\n';
    for(float i=0;i<nsp.size();i++)
        cout<<nsp[i].first.x<<" "<<nsp[i].first.y<<" "<<nsp[i].second<<'\n';

    cout<<'\n';

    for(float i=0;i<ncw.size();i++)
        cout<<ncw[i].first.x<<" "<<ncw[i].first.y<<" "<<ncw[i].second<<'\n';
    return 0;
}
