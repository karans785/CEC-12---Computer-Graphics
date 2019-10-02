#include <bits/stdc++.h>
#include<GraphicsFunctions.h>

using namespace std;
double pi =3.14159265359;
int maxx,maxy;
vector<point> Multiply_matrices(double rotation_mat[4][4],vector<point> verts)
{int i,j;
vector<point> NewVertices(verts.size());
for(j=0;j<verts.size();j++)
{NewVertices[j].x= verts[j].x*rotation_mat[0][0]+ verts[j].y*rotation_mat[0][1]+verts[j].z*rotation_mat[0][2]+verts[j].w*rotation_mat[0][3];
NewVertices[j].y= verts[j].x*rotation_mat[1][0]+ verts[j].y*rotation_mat[1][1]+verts[j].z*rotation_mat[1][2]+verts[j].w*rotation_mat[1][3];
NewVertices[j].z= verts[j].x*rotation_mat[2][0]+ verts[j].y*rotation_mat[2][1]+verts[j].z*rotation_mat[2][2]+verts[j].w*rotation_mat[2][3];
NewVertices[j].w= verts[j].x*rotation_mat[3][0]+ verts[j].y*rotation_mat[3][1]+verts[j].z*rotation_mat[3][2]+verts[j].w*rotation_mat[3][3];


}
return NewVertices;

}
struct Object{
private:
    vector<point> Vertices;
    /*vector<point> Vertices; */
vector<pair<int,int> > Edges;
public:
void initialise_vertices()
{int n;
    cin>>n;
    point A;
    for(int i=0;i<n;i++)
    {cin>>A.x>>A.y>>A.z;
        A.w=1;
        Vertices.push_back(A);
    }
    cin>>n;
    pair<int,int> edge;
    for(int i=0;i<n;i++)
    {cin>>edge.first>>edge.second;
        Edges.push_back(edge);
    }
}
void Rotate_about_x(double theta)
 { double rotation_mat[4][4]={1,0,0,0,0,cos(theta),-sin(theta),0,0,sin(theta),cos(theta),0,0,0,0,1};
Vertices=Multiply_matrices(rotation_mat,Vertices);
 }
 void Rotate_about_y(double theta)
 { double rotation_mat[4][4]={cos(theta),0,sin(theta),0,0,1,0,0,-sin(theta),0,cos(theta),0,0,0,0,1};
Vertices=Multiply_matrices(rotation_mat,Vertices);
 }
 void Rotate_about_z(double theta)
 { double rotation_mat[4][4]={cos(theta),-sin(theta),0,0,sin(theta),cos(theta),0,0,0,0,1,0,0,0,0,1};
Vertices=Multiply_matrices(rotation_mat,Vertices);
 }
void front_view(int color=YELLOW)
{//Viewing along Z axis
    int xc= maxx/6;
int yc=maxy/4;

int i;
for(i=0;i<Edges.size();i++)
 DDA(Vertices[Edges[i].first].x+xc,yc-Vertices[Edges[i].first].y,Vertices[Edges[i].second].x+xc,yc-Vertices[Edges[i].second].y,0,color);



}
void side_view(int color=YELLOW)
{//Viewing along X axis
    int xc= maxx/2;
int yc=maxy/4;

int i;
for(i=0;i<Edges.size();i++)
 DDA(-Vertices[Edges[i].first].z+xc,yc-Vertices[Edges[i].first].y,-Vertices[Edges[i].second].z+xc,yc-Vertices[Edges[i].second].y,0,color);



}
void top_view(int color=YELLOW)
{//Viewing along Z axis
    int xc= (5*maxx )/6;
int yc=maxy/4;

int i;
for(i=0;i<Edges.size();i++)
 DDA(Vertices[Edges[i].first].x+xc,yc- (-Vertices[Edges[i].first].z),Vertices[Edges[i].second].x+xc,yc-(-Vertices[Edges[i].second].z),0,color);



}
void isometric_view(int color=YELLOW)
{
    int xc=maxx/6;
    int yc=(3*maxy)/4;
    vector<point>temp=Vertices;
    Rotate_about_y(-pi/4);
   Rotate_about_x(atan( (double) 1 / sqrt( (double) 2)));
   for(int i=0;i<Edges.size();i++)
    DDA(Vertices[Edges[i].first].x+xc,yc-Vertices[Edges[i].first].y,Vertices[Edges[i].second].x+xc,yc-Vertices[Edges[i].second].y,0,color);
    Vertices=temp;
}
void dimetric_view(int color=YELLOW)
{
 int xc=maxx/2;
 int yc=(3*maxy )/4;
    vector<point>temp=Vertices;
   double k=1.4142135;
    Rotate_about_y(asin(  k/sqrt((double) 2)));
   Rotate_about_x(asin(k/sqrt( (double) (k*k)+ 2)));
   for(int i=0;i<Edges.size();i++)
    DDA(Vertices[Edges[i].first].x+xc,yc-Vertices[Edges[i].first].y,Vertices[Edges[i].second].x+xc,yc-Vertices[Edges[i].second].y,0,color);
    Vertices=temp;

}
void perspective_view(int color=YELLOW)
{ int xc=(5*maxx)/6;
 int yc=(3*maxy )/4;
 int d=80;
double rotation_mat[4][4]={d,0,0,0,0,d,0,0,0,0,0,0,0,0,-1,d};
vector<point> projVertices(Vertices.size());
projVertices=Multiply_matrices(rotation_mat,Vertices);
int i;
for(i=0;i<Edges.size();i++)
DDA( (projVertices[Edges[i].first].x/projVertices[Edges[i].first].w)+xc,yc-(projVertices[Edges[i].first].y/projVertices[Edges[i].first].w),(projVertices[Edges[i].second].x/projVertices[Edges[i].second].w)+xc,yc-(projVertices[Edges[i].second].y/projVertices[Edges[i].second].w),0,color);

}
void hide()
{front_view(BLACK);
top_view(BLACK);
side_view(BLACK);
isometric_view(BLACK);
dimetric_view(BLACK);
perspective_view(BLACK);

}
void display()
{ front_view(YELLOW);
top_view(YELLOW);
side_view(YELLOW);
isometric_view(YELLOW);
dimetric_view(YELLOW);
perspective_view(YELLOW);

}

};
void divide_screen(int color=YELLOW)
{int x=maxx;
int y=maxy;
int first_thirdx=x/3,second_thirdx=(2*x)/3;
DDA(first_thirdx,0,first_thirdx,y,0,color);
DDA(second_thirdx,0,second_thirdx,y,0,color);
DDA(0,y/2,x,y/2,0,color);

}
int main()
{ freopen("input.txt","r",stdin);
    initGraphics();


maxx=getmaxx();
maxy=getmaxy();
divide_screen();
Object prism;
prism.initialise_vertices();
int x_angle=5,y_angle=5,z_angle=5;
char ch;
prism.display();
while(true)
{
ch=getch();

if(ch=='S'||ch=='s')
    break;
 if(ch=='X'||ch=='x')
 { prism.hide();
prism.Rotate_about_x(( x_angle* pi )/180 );

 }
  if(ch=='Y'||ch=='y')
 { prism.hide();
 prism.Rotate_about_y(( y_angle* pi )/180 );

 }
  if(ch=='Z'||ch=='z')
 {   prism.hide();
     prism.Rotate_about_z(( z_angle* pi )/180 );


 }




prism.display();





}



}
