#include<iostream>
#include<graphics.h>
using namespace std;
class sfill
{
   int x,y;
  public:
	 void seedfill(int,int,int,int);
	 void draw();
};
void sfill::draw()
{
  int p[20][2],i,n;
  line(320,0,320,480);
  line(0,240,640,240);
  cout<<"\n Enter the number of vertices of polygon";
  cin>>n; cout<<"\n Enter all coordinate by <space>";
   for(i=0;i<n;i++)
  { cin>>p[i][0]>>p[i][1];
    p[i][0]=320+p[i][0];
    p[i][1]=240-p[i][1];}
   p[i][0]=p[0][0];
   p[i][1]=p[0][1];
   for(i=0;i<n;i++)
   {line(p[i][0],p[i][1],p[i+1][0],p[i+1][1]);}
   line(p[i][0],p[i][1],p[0][0],p[0][1]);
}
void sfill::seedfill(int x,int y,int oldcolor,int newcolor)
{
 int color;
 color=getpixel(x,y);
 if(color==oldcolor && color!=newcolor)
   {  
    putpixel(x,y,newcolor);
    delay(2);
    seedfill(x+1,y,oldcolor,newcolor);
    seedfill(x-1,y,oldcolor,newcolor);
    seedfill(x,y+1,oldcolor,newcolor);
    seedfill(x,y-1,oldcolor,newcolor);
   }
}
 
int main()
{
 
 int gd=DETECT,gm=VGAMAX;
 initgraph(&gd,&gm,NULL);
  sfill s;
  s.draw();
  int x,y;
  cout<<"\n enter inside point of poygon";
  cin>>x>>y;
   x=x+320;y=240-y;
   int oldcolor=getpixel(x,y);
   int newcolor=2;
  s.seedfill(x,y,oldcolor,newcolor);
  delay(10000);
 closegraph();
}
