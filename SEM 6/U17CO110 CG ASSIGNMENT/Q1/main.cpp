#include<stdio.h>
#include<conio.h>
#include<graphics.h>
int main()
{
    int gd=DETECT,gm,x=25,y=25,font=10;
    initgraph(&gd,&gm,"C:\\turboC3\\BGI");
    for(font=0;font<=4;font++)
    {
        settextstyle(font,HORIZ_DIR,font+1);// sets font type, font direction, size
        setcolor(font+1); // sets color for text.
        outtextxy(x,y,"text with different fonts"); // prints message on screen at (x,y)
        y=y+25;
    }
    for(font=0;font<=2;font++)
    {
        settextstyle(font,VERT_DIR,font+2);
        setcolor(font+1);
        x=250;
        y=100;
        outtextxy(x,y,"text in vertical direction");
        y=y+25;
    }
    getch();
    closegraph();
}

