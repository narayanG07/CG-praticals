#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class pixel1
{
	public:
		float x,y,length,dx,dy,height,width,X,Y;
		void DDA(float,float,float,float);
		void pattern();
		int sign(float);
};
int pixel1::sign(float x)
{
	if(x<0)
	return -1;
	else if(x==0)
	return 0;
	else
	return 1;
}

void pixel1::DDA(float x1,float y1,float x2,float y2)
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

	for(int i=0;i<length;i++)
	{
	delay(1);
	x=x+dx;
	y=y+dy;

	putpixel(x,y,WHITE);

	}
}

void pixel1:: pattern()
{
	cout<<"\nEnter co-ordinates (X,Y)";
	cin>>X>>Y;

	cout<<"\nEnter width and Height";
	cin>>width>>height;

	DDA(X,Y,X+width,Y);
	DDA(X,Y,X,Y+height);
	DDA(X,Y+height,X+width,Y+height);
	DDA(X+width,Y,X+width,Y+height);

	DDA(X,Y+height/2,X+width/2,Y);
	DDA(X,Y+height/2,X+width/2,Y+height);
	DDA(X+width,Y+height/2,X+width/2,Y);
	DDA(X+width,Y+height/2,X+width/2,Y+height);

	DDA(X+width/4,Y+height/4,X+3*width/4,Y+height/4);
	DDA(X+width/4,Y+3*height/4,X+3*width/4,Y+3*height/4);
	DDA(X+width/4,Y+height/4,X+width/4,Y+3*height/4);
	DDA(X+3*width/4,Y+height/4,X+3*width/4,Y+3*height/4);


}

int main()
{
	int gd=DETECT,gm=VGAMAX;
	initgraph(&gd,&gm,NULL);

	pixel1 s;
	s.pattern();
        delay(10000);
	getch();
	closegraph();
}
