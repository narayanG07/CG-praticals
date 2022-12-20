#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<iostream.h>
#include<dos.h>
float points[4][2];
int xa;
int ya;
void line1(float x2,float y2)
{
	line(points[0][0],points[0][1],x2,y2);
	points[0][0]=x2; points[0][1]=y2;
}

void main()
{
int gd=DETECT,gm,n,i;
void bezier(float,float,float,float,float,float,float,float,int);
initgraph(&gd,&gm,"c:\\turboc3\\bgi");
cleardevice();
cout<<"\nPlease! Enter n : ";
cin>>n;
cout<<"\n Enter the values of all points coordinates";
for(i=0;i<n;i++)
{ cin>>points[i][0];
 cin>>points[i][1];
}
       
bezier(points[0][0],points[0][1],points[1][0],points[1][1],points[2][0],points[2][1],points[3][0],points[3][1],n);
	getch();
}
void bezier(float xa,float ya,float xb,float yb,float xc,float yc,float xd, float yd, int n)
{
	float xab,yab,xbc,ybc,xcd,ycd,xabc,yabc,xbcd,ybcd,xabcd,yabcd;
	if(n==0)
	{
		line1(xb,yb);
		line1(xc,yc);
		line1(xd,yd);
		delay(100);
	}
	else
	{
		xab=(points[0][0]+xb)/2; yab=(points[0][1]+yb)/2;
		xbc=(xb+xc)/2; ybc=(yb+yc)/2;
		xcd=(xc+xd)/2; ycd=(yc+yd)/2;
		xabc=(xab+xbc)/2; yabc=(yab+ybc)/2;
		xbcd=(xbc+xcd)/2; ybcd=(ybc+ycd)/2;
		xabcd=(xabc+xbcd)/2; yabcd=(yabc+ybcd)/2;
		n=n-1;
		bezier(xa,ya,xab,yab,xabc,yabc,xabcd,yabcd,n);
		bezier(xabcd,yabcd,xbcd,ybcd,xcd,ycd,xd,yd,n);
	}
}
