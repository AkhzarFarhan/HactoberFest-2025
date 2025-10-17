//PRESS BAR GAME

//header file for c language functions
#include <stdio.h>

//header file for c++ language functions
#include <conio.h>

//header file for the delay function which makes graphics looks like animation
#include <dos.h>

//header file for grapics realeted function
#include <graphics.h>

//header file for keyboard and mouse realeted functions
#include <stdlib.h>

//declearation part
     union REGS i, o;
int left = 265, top = 250;

void initialize_graphics_mode()
{
  int  gd = DETECT, gm, error, x ;
  char a[5];

  initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");//location where the file is going to be saved in your PC

//TEXT GRAPHICS FOR CREDITS PART FROM US

cleardevice();
setbkcolor(BLACK);//HERE's THE CHANGE IN BACKGROUND COLOR
setcolor(RED);//HERE IS THE CHANGE IN TEXT COLOR
//settextstyle(DEFAULT_FONT,HORIZ_DIR,20);
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
outtextxy(200,20,"PROJECT BY 'DARKKNIGHT'");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
outtextxy(180,400,"PRESS [x] TO START");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,10);
outtextxy(30,120,"BAR GAME");
settextstyle(SANS_SERIF_FONT,HORIZ_DIR,2);
outtextxy(550,450,"BY DK07");
delay(4000);
//here i dont required it so i made it for comment part
/*settextjustify(CENTER_TEXT, CENTER_TEXT);
settextstyle(DEFAULT_FONT,HORIZ_DIR,20);
setcolor(RED);
outtextxy(300,300,"BAR GAME");
outtextxy(300,400,"BY DK07");*/


//grapics for RAINBOW [7 colours] coloured animation

for(x=0;x<450;x++)
{
setcolor(RED);
circle(0,0,20+x);
delay(1);
setcolor(YELLOW);
circle(50,50,20+x);
delay(1);
setcolor(GREEN);
circle(100,100,20+x);
delay(1);
setcolor(BLUE);
circle(150,150,20+x);
delay(1);
setcolor(CYAN);
circle(200,200,20+x);
delay(1);
setcolor(MAGENTA);
circle(250,250,20+x);
delay(1);
setcolor(RED);
circle(300,300,20+x);
delay(1);
setcolor(YELLOW);
circle(350,350,20+x);
delay(1);
setcolor(GREEN);
circle(350,350,20+x);
delay(1);
setcolor(BLUE);
circle(400,400,20+x);
delay(1);
setcolor(CYAN);
circle(450,450,20+x);
delay(1);
setcolor(MAGENTA);
circle(500,500,20+x);
delay(1);
setcolor(RED);
circle(550,550,20+x);
delay(1);
}
cleardevice();
//graphics for COUNTDOWN from 3 to 0...
  settextjustify(CENTER_TEXT, CENTER_TEXT);//TO MAKE TEXT IN CENTER OF SCREEN
  setbkcolor(WHITE);
for (x = 3; x >=0; x--)//LOOP FOR MINIMUM NUMBER TO SHOW
{
settextstyle(DEFAULT_FONT,HORIZ_DIR,4);
setcolor(1);
outtextxy(300,100,"GAME STARTS IN...");
outtextxy(300,400,"SECONDS");
sprintf(a,"%d",x);
setcolor(RED);
settextstyle(DEFAULT_FONT,HORIZ_DIR,60);
outtextxy(getmaxx()/2, getmaxy()/2, a);
delay(1000);

if ( x == 0 )
break;
cleardevice();//TO CLEAR THE DEVICE
}
// commands for mouse coursor on the bar
  error = graphresult();

  if (error != grOk)
  {
    perror("Error ");
    printf("Press any key to exit...\n");
    getch();
    exit(EXIT_FAILURE);
  }
}

void showmouseptr()
{
  i.x.ax = 1;
  int86(0x33,&i,&o);
}

void hidemouseptr()
{
  i.x.ax = 2;
  int86(0x33,&i,&o);
}

void getmousepos(int *x,int *y)
{
  i.x.ax = 3;
  int86(0x33,&i,&o);

  *x = o.x.cx;
  *y = o.x.dx;
}
//graphics for the bar
void draw_bar()
{
  hidemouseptr();
  setfillstyle(SOLID_FILL,GREEN);
  bar(190,180,450,350);
  showmouseptr();
}

void draw_button(int x, int y)
{
  hidemouseptr();
  setfillstyle(SOLID_FILL,RED);
  bar(x,y,x+150,y+30);
  moveto(x+4,y);
  setcolor(GREEN);
  outtext(""); //you can write any name in it but i had left it blank
  showmouseptr();
}
//grapics of the game page and text on that page
void draw()
{
  cleardevice();
  setbkcolor(BLUE);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  outtextxy(300,459,"\t\t\tProject by DARKKNIGHT07");
  setcolor(GREEN);
  rectangle(0,0,639,450);
  setcolor(RED);
  settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
  outtextxy(300,20,"TRY TO CATCH THE RED BAR ");
  outtextxy(300,380,"PRESS esc KEY TO EXIT");
  setfillstyle(XHATCH_FILL,MAGENTA);
  setcolor(CYAN);
  bar(1,1,75,449);
  bar(565,1,638,449);
  showmouseptr();
  draw_bar();
  draw_button(left,top);
}
//this command is for any error if found while running your programe
void initialize()
{
  initialize_graphics_mode();

  if( !initmouse() )
  {
    closegraph();
    printf("Unable to initialize the mouse");
    printf("Press any key to exit...\n");
    getch();
    exit(EXIT_SUCCESS);
  }

  draw();
}
//these command are for the mouse cursor
int initmouse()
{
  i.x.ax = 0;
  int86(0x33,&i,&o);
  return ( o.x.ax );
}

void get_input()
{
  int x, y;

  while(1)
  {
    getmousepos(&x,&y);

    /* mouse pointer in left of button */

    if( x >= (left-3) && y >= (top-3) && y <= (top+30+3) && x < left )
    {
      draw_bar();
      left = left + 4;

      if (left > 350)
	left = 190;

      draw_button(left,top);
    }

    /* mouse pointer in right of button */

    else if (x<=(left+100+3)&&y>=(top-3)&&y<=(top+30+3)&&x>(left+100))
    {
      draw_bar();
      left = left - 4;

      if (left < 190)
	left = 350;

      draw_button(left,top);
    }

    /* mouse pointer above button */

    else if(x>(left-3) && y>=(top-3) && y<(top) && x<= (left+100+3))
    {
      draw_bar();
      top = top + 4;

      if (top > 320)
	top = 180;

      draw_button(left,top);
    }

    /* mouse pointer below button */

    else if (x>(left-3)&&y>(top+30)&&y<=(top+30+3)&&x<=(left+100+3))
    {
      draw_bar();
      top = top - 4;

      if (top < 180)
	top = 320;

      draw_button(left,top);
    }

    if (kbhit())
    {
      if (getkey() == 1)
	exit(EXIT_SUCCESS);
    }
  }
}

int getkey()
{
  i.h.ah = 0;
  int86(22,&i,&o);

  return( o.h.ah );
}

//command to get the output
main()
{
  initialize();

  get_input();
  return 0;
}
