// Hangman Game



#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<process.h>
#include<dos.h>
#include<time.h>
#include<stdlib.h>

#define MAX 40
int data,top=-1,miss=1;
int loop=0;
char stack[MAX];

void menu(int );
void drawboard();
void start(int );
void help();
void developer();
void loading();
void game();
void display_hang(int );
void winner();
void over();

char list[15][30]={"butterfly","aeroplane","helicopter","entrepreneur",
    "accomodation","rhythm","witchcraft","xylophone","computer","fundamental",
    "software","electronics","architecture","calculator","information"};

void main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"c:\\turboc3\\bgi");
    loading();
    int i=1;
    int ch;
    while(1){
	menu(i);
	ch=getch();
	switch(ch){
	case 72:
	    if(i!=1){
		i--;
		menu(i);
	    }
	    break;
	case 80:
	    if(i!=3){
		i++;
		menu(i);
	    }
	    break;
	case 13:
	    start(i);
	    break;
	case 27:
	    exit(1);
	default:
	    break;
	}
    }
    closegraph();
}

void drawboard(){
    int marginl=100,marginb=100;
    int border1=getmaxx()-marginl;
    int border2=getmaxy()-marginb;
    setcolor(2);
    settextstyle(0,0,3);
    outtextxy(getmaxx()/3,20,"HANG-MAN");
    setcolor(BLUE);
    setlinestyle(SOLID_LINE,0,3);
    rectangle(100,50,border1,border2);
    setcolor(RED);
    settextstyle(0,0,1);
    outtextxy(300,360,"Esc-Exit");
}

void loading(){
    cleardevice();
    /*
    drawboard();
    settextstyle(0,0,4);
    setcolor(RED);
    outtextxy(getmaxx()/3-20,getmaxy()/2,"HANG-MAN");
    settextstyle(0,0,2);
    setfillstyle(SOLID_FILL,RED);
    outtextxy(240,310,"Loading...");
    delay(1000);
    rectangle(200,290,220,300);
    floodfill(210,295,RED);
    delay(1000);
    rectangle(220,290,300,300);
    floodfill(225,295,RED);
    delay(1000);
    rectangle(300,290,435,300);
    floodfill(310,295,RED);
    delay(1000);*/
}

void menu(int ch){
    cleardevice();
    drawboard();
    int i=0;
    settextstyle(0,0,2);
    setcolor(0);
    outtextxy(getmaxx()/3-50,450,"Esc-Exit");
    char m[3][30]={"New Game","Help","Developer"};
    while(i<3){
	if(ch==i+1){
	    setcolor(2);
	    outtextxy(250,200,m[i]);
	    setcolor(0);
	}
	setcolor(2);
	outtextxy(getmaxx()/4-50,310,"Press Up or Down Arrow Key");
	i++;
    }
}

void help(){
    int z;
    cleardevice();
    loading();
    cleardevice();
    drawboard();
    settextstyle(0,0,1);
    setcolor(2);
    outtextxy(130,150,"Press any alphabet key to enter the text");
    outtextxy(130,180,"Every wrong input will create a part of hangman");
    outtextxy(130,300,"Press any key to go back to main menu");
    z=getch();
    if(z!=27){
	main();
    }
    else{
	exit(1);
    }
}

void developer(){
    cleardevice();
    loading();
    cleardevice();
    drawboard();
    settextstyle(0,0,1);
    setcolor(WHITE);
    outtextxy(getmaxx()/3-50,175,"DEVELOPERS");
    outtextxy(getmaxx()/3-25,200,"Khwopa Engineering College");
    outtextxy(getmaxx()/3-25,225,"Arbin Shrestha");
    outtextxy(getmaxx()/3-25,250,"Copyright-2023(Arbin Shrestha)");
    outtextxy(130,300,"Press any key to go back to main menu");
    int z=getch();
    if(z!=27){
	main();
    }
    else{
	exit(1);
    }
}

void start(int ch){
    cleardevice();
    switch(ch){
    case 1:
	loading();
	game();
	break;
    case 2:
	help();
	break;
    case 3:
	developer();
	break;
    default:
       break;
    }
}

void game(){
    setcolor(GREEN);
    settextstyle(0,0,2);
    char z;
    int number;
    srand(time(NULL));
    number=rand()%15;
    int count=0;
    int space=0;
    cleardevice();
    drawboard();
    setcolor(GREEN);
    settextstyle(0,0,2);
    int let=strlen(list[number]);
    outtextxy(getmaxx()/3,200,"Press Any Key");
    z=getchar();
    if(z!=27){
	cleardevice();
	drawboard();
	settextstyle(0,0,1);
	setcolor(WHITE);
	outtextxy(180,260,"Enter Guess : ");
	outtextxy(180,310,"Wrong Guesses : ");
	for(int i=0;i<let;i++){
	    outtextxy(180+count,285,"_");
	    count=count+20;
	}
	char letter=' ';
	int b=0;
	while(miss<=4){
	    start:
	    letter=getchar();
	    getchar();
	    if(top==MAX-1){
		outtextxy(getmaxx()/2,getmaxy()/2,"Stack Overflow");
		over();
	    }
	    top+=1;
	    stack[top]=letter;
	    if(letter==27){
		exit(0);
	    }
	    for(int p=0;p<top;p++){
		if(stack[p]==stack[top]){
		    top-=1;
		    goto start;
		}
	    }
	    for(int j=0;j<let;j++){
		if(letter==list[number][j]){
		     char arr[2];
		     setcolor(WHITE);
		     sprintf(arr,"%c",letter);
		     outtextxy(180+j*20,280,arr);
		     loop++;
		     b=b+10;
		     delete arr;
		}
	    }
	    if(b==0){
		char arr1[1];
		setcolor(WHITE);
		sprintf(arr1,"%c",letter);
		outtextxy(320+space,310,arr1);
		display_hang(miss);
		miss++;
		space=space+20;
		delete arr1;
	    }
	    b=0;
	    if(loop==let){
		delay(2000);
		winner();
	    }
	}
    }
}
void winner(){
    cleardevice();
    drawboard();
    setcolor(GREEN);
    settextstyle(0,0,3);
    outtextxy(getmaxx()/3,getmaxy()/2,"YOU WON!!!");
    delay(3000);
    loop=0;
    top=-1;
    miss=1;
    main();
}

void over(){
     miss=1;
     top=-1;
     loop=0;
     cleardevice();
     drawboard();
     setcolor(GREEN);
     settextstyle(0,0,3);
     outtextxy(getmaxx()/3-20,getmaxy()/2,"-GAME OVER-");
     delay(1000);
     main();
}

void display_hang(int miss){
    setcolor(RED);
    switch(miss){
    case 1:
	line(getmaxx()/2,80,getmaxx()/2,70);
	line(getmaxx()/2,70,getmaxx()/2+50,70);
	line(getmaxx()/2+50,70,getmaxx()/2+50,200);
	line(getmaxx()/2+40,200,getmaxx()/2+60,200);
	circle(getmaxx()/2,90,10);
	setfillstyle(SOLID_FILL,RED);
	floodfill(getmaxx()/2+5,95,RED);
	break;
    case 2:
	line(getmaxx()/2,100,getmaxx()/2,150);
	break;
    case 3:
	line(getmaxx()/2,120,getmaxx()/2-20,140);
	line(getmaxx()/2,120,getmaxx()/2+20,140);
	break;
    case 4:
	line(getmaxx()/2,150,getmaxx()/2-20,180);
	line(getmaxx()/2,150,getmaxx()/2+20,180);
	settextstyle(0,0,1);
	outtextxy(getmaxx()/2-60,220,"You have been hanged");
	delay(2000);
	over();
	break;
    default:
	break;
    }
}
