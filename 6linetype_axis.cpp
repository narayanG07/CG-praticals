#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
 
class DDA
{
  public:
      float x,y,x1,y1,x2,y2,length,dx,dy,e;
      int i;
      void getdata();
      void display();
      void display(float,float,float,float);
      float sign(float);
      void dotted();
      void dashed();
      void dashdot();
      void thick();
      void thick1();
      DDA();
};
 
DDA::DDA()
{
x=y=x1=y1=x2=y2=length=dx=dy=e=0;
i=0;
line(320,0,320,480);
line(0,240,640,240);
}
 
void DDA::getdata()
{
   cout<<"Enter co-ordinates of 1st line x1<space>y1space>x2<space>y2\n";
   cin>>x1>>y1>>x2>>y2;
   x1=320+x1;y1=240-y1;x2=320+x2;y2=240-y2;
}
 
float DDA::sign(float a)
{
  if(a>0)
    return 1;
  else if(a==0)
    return 0;
  else 
    return 1;
}
 
void DDA::display()
{
   dx=abs(x2-x1);
   dy=abs(y2-y1);
   
   if(dx>dy)
    length=dx;
   else
    length=dy;
    
   dx=(x2-x1)/length;
   dy=(y2-y1)/length;
    
   x=x1+0.5*sign(dx);
   y=y1+0.5*sign(dy);
   
   putpixel(x,y,RED);
   i=0;
     while(i<=length)
       {
          x=x+dx;
          y=y+dy;
          putpixel(x,y,RED);
          i=i+1;
       }           
}
 
void DDA::display(float m1,float n1,float m2,float n2)
{
x1=m1;
y1=n1;
x2=m2;
y2=n2;
 
  dx=abs(x2-x1);
   dy=abs(y2-y1);
   
   if(dx>dy)
    length=dx;
   else
    length=dy;
    
   dx=(x2-x1)/length;
   dy=(y2-y1)/length;
    
   x=x1+0.5*sign(dx);
   y=y1+0.5*sign(dy);
   
   putpixel(x,y,GREEN);
   i=0;
     while(i<=length)
       {
          x=x+dx;
          y=y+dy;
          putpixel(x,y,GREEN);
          i=i+1;
       }           
                    
}
 
void DDA::dotted()
{
 
 
 dx=abs(x2-x1);
   dy=abs(y2-y1);
   
   if(dx>dy)
    length=dx;
   else
    length=dy;
    
   dx=(x2-x1)/length;
   dy=(y2-y1)/length;
    
   x=x1+0.5*sign(dx);
   y=y1+0.5*sign(dy);
   
   
   putpixel(x,y,WHITE);
   i=0;
     while(i<=length)
       {
          x=x+dx;
          y=y+dy;
        
          if(i%2 == 1)
          putpixel(x,y,WHITE);    
          i=i+1;
       }        	
 
}
 
void DDA::dashed()
{
	
 dx=abs(x2-x1);
   dy=abs(y2-y1);
   
   if(dx>dy)
    length=dx;
   else
    length=dy;
    
   dx=(x2-x1)/length;
   dy=(y2-y1)/length;
    
   x=x1+0.5*sign(dx);
   y=y1+0.5*sign(dy);
   
   
   putpixel(x,y,BLUE);
   i=0;
     while(i<=length)
       {
          x=x+dx;
          y=y+dy;
        
          if(!(i%10==1|i%10==2||i%10==3||i%10==4))
          putpixel(x,y,BLUE);    
          i=i+1;
       }        
 
}
 
void DDA::dashdot()
{
	
 dx=abs(x2-x1);
   dy=abs(y2-y1);
   
   if(dx>dy)
    length=dx;
   else
    length=dy;
    
   dx=(x2-x1)/length;
   dy=(y2-y1)/length;
    
   x=x1+0.5*sign(dx);
   y=y1+0.5*sign(dy);
   
   
   putpixel(x,y,YELLOW);
  i=0; 
     while(i<=length)
       {
          x=x+dx;
          y=y+dy;
        
          if(!(i%10==1||i%10==2||i%10==4||i%10==5))
          putpixel(x,y,YELLOW);    
          i=i+1;
       }        
}
 
void DDA::thick()
{
int th;
cout <<"Enter the thickness of line you want:\n";	
cin  >>th;
 
 DDA D5;
 D5.display(x1,y1,x2,y2);
 float m1=x1;
 float n1=y1;
 float m2=x2;
 float n2=y2;
 
   	for(int j=-th/2; j<th/2; j++)
	  	{ 
	   	D5.display(m1+j+1,n1,m2+j+1,n2);    
		}
		
	for(int j=-th/2; j<th/2; j++)
	  	{ 
	   	D5.display(m1,n1+j+1,m2,n2+j+1);    
		}
		
}
 
void DDA::thick1()
{
int th;
cout <<"Enter the thickness of line you want:\n";	
cin  >>th;
 
 DDA D5;
 D5.display(x1,y1,x2,y2);
 
 float wy,wx;
 
 wy = ((th-1)/2)*(sqrt(pow((x2-x1),2)+pow((y2-y1),2))) / abs(x2-x1);
 wx = ((th-1)/2)*(sqrt(pow((x2-x1),2)+pow((y2-y1),2))) / abs(y2-y1);
 
for(int j=0; j<wy; j++)
{
	D5.display(x1,y1+j,x2,y2+j);
	D5.display(x1,y1-j,x2,y2-j);
}
for(int j=0; j<wx; j++)
{
	D5.display(x1+j,y1,x2+j,y2);
	D5.display(x1-j,y1,x2-j,y2);
}
}
 
 
int main()
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,NULL);
   int ch;
   char ans;
   DDA D1,D2,D3,D4,D6,D7;
 
    do
      { 
  cout<<"Enter choice:\n1.Solid\n2.Dotted\n3.Dashed\n4.Dashdot\n5.Thick(Simple Method)\n6.Thick";
        cin >>ch;
       switch(ch)
               { 
               case 1:
               D1.getdata();
               	cout<<"Answer by DDA Algorithm, Solid line:\n";
                D1.display();
               
                break;
                
               case 2:
               D2.getdata();
                cout<<"Answer by DDA Algorithm, Dotted line:\n";
                D2.dotted();
         
                break;
             case 3:
             D3.getdata();
             	cout<<"Answer by DDA Algorithm, Dashed line:\n";
               D3.dashed();
               
                break;
               
             case 4:
               D4.getdata();
             	cout<<"Answer by DDA Algorithm, Dashdot line:\n";
               D4.dashdot();
              
               break;
            case 5:
               D6.getdata();
         cout<<"Answer by DDA Algorithm, thick line(Simple method):\n";
               D6.thick();
               
               break;
               case 6:
               D7.getdata();
             	cout<<"Answer by DDA Algorithm, thick line:\n";
               D7.thick1();
             
               break;
              default:
              cout<<"Wrong choice, try again!\n";
               } 
       cout<<"Do you wish to continue:(y/n)?\t";
       cin>>ans;
      }while(ans=='Y' || ans=='y');
   
   closegraph();
  return 0;
}
