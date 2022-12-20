#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;
class pixel1
{
	public:
		float x,y,length,dx,dy,x1,y1,x2,y2;
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
	cin>>x1>>y1;

	cout<<"\nEnter width and Height";
	cin>>x2>>y2;

	DDA(x1,y1,x2,y1);
	DDA(x1,y1,x1,y2);
	DDA(x1,y2,x2,y2);
	DDA(x2,y1,x2,y2);

	DDA(x1,y2/2,x2/2,y1);
	DDA(x1,y2/2,x2/2,y2);
	DDA(x2,y2/2,x2/2,y1);
	DDA(x2,y2/2,x2/2,y2);

	DDA(x2/4,y2/4,x1+3*x2/4,y2/4);
	DDA(x2/4,y1+3*y2/4,x1+3*x2/4,y1+3*y2/4);
	DDA(x2/4,y2/4,x2/4,y1+3*y2/4);
	DDA(x1+3*x2/4,y2/4,x1+3*x2/4,y1+3*y2/4);


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
