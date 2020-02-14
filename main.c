/*Programa que anima una flecha para que baile el Payaso de Rodeo*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#define DEFAULTCOORD 0

#define XSTARTCOORD DEFAULTCOORD+8
#define YSTARTCOORD DEFAULTCOORD+8

#define XCOORD XSTARTCOORD
#define YCOORD YSTARTCOORD

#define FACINGFRONT 0
#define FACINGLEFT 1
#define FACINGBACK 2
#define FACINGRIGHT 3
#define FACINGDEFAULT FACINGFRONT

#define MOVINGRIGHT 3
#define MOVINGLEFT 1
#define MOVINGBACK 2
#define MOVINGFRONT 0
#define MOVINGDEFAULT MOVINGRIGHT

//116 bpm es el tempo de la canción
#define XTEMPO 510
#define YTEMPO 500

char uparrowtop[] = " ^ ";
char uparrowmid[] = "/|\\";
char uparrowdwn[] = "---";

char dwarrowtop[] = "---";
char dwarrowmid[] = "\\|/";
char dwarrowdwn[] = " v ";

char lfarrowtop[] = " /|";
char lfarrowmid[] = "<-|";
char lfarrowdwn[] = " \\|";

char riarrowtop[] = "|\\ ";
char riarrowmid[] = "|->";
char riarrowdwn[] = "|/ ";

COORD coord = {0,0}; //center of axis is set to the top left cornor of the screen

void gotoxy(int x,int y);
void drawArrow(int xcoord, int ycoord, int facing);
void defaultArrow(int xcoord, int ycoord, int facing);
int moveleft(int xcoord, int ycoord, int facing);
int moveright(int xcoord, int ycoord, int facing);
int moveup(int xcoord, int ycoord, int facing);
int movedown(int xcoord, int ycoord, int facing);

int main() {
	int nextxcoord = XCOORD, nextycoord = YCOORD, nextfacing = FACINGDEFAULT, nextmovement = MOVINGDEFAULT;
	defaultArrow(nextxcoord,nextycoord,nextfacing);
	//system("pause");

    while(1==1) {
        //DEFAULT
        nextxcoord = moveright(nextxcoord,nextycoord,nextfacing);
        nextxcoord = moveleft(nextxcoord,nextycoord,nextfacing);
        nextycoord = movedown(nextxcoord,nextycoord,nextfacing);
        nextycoord = moveup(nextxcoord,nextycoord,nextfacing);
        nextfacing++;

        //DEFAULT-90°
        nextycoord = moveup(nextxcoord,nextycoord,nextfacing);
        nextycoord = movedown(nextxcoord,nextycoord,nextfacing);
        nextxcoord = moveright(nextxcoord,nextycoord,nextfacing);
        nextxcoord = moveleft(nextxcoord,nextycoord,nextfacing);
        nextfacing++;

        //DEFAULT-180°
        nextxcoord = moveleft(nextxcoord,nextycoord,nextfacing);
        nextxcoord = moveright(nextxcoord,nextycoord,nextfacing);
        nextycoord = moveup(nextxcoord,nextycoord,nextfacing);
        nextycoord = movedown(nextxcoord,nextycoord,nextfacing);
        nextfacing++;

        //DEFAULT-270°
        nextycoord = movedown(nextxcoord,nextycoord,nextfacing);
        nextycoord = moveup(nextxcoord,nextycoord,nextfacing);
        nextxcoord = moveleft(nextxcoord,nextycoord,nextfacing);
        nextxcoord = moveright(nextxcoord,nextycoord,nextfacing);
        nextfacing = FACINGDEFAULT;
    }

	//BACK TO DEFAULT
	return 0;
}

void gotoxy(int x,int y) {
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void drawArrow(int xcoord, int ycoord, int facing) {
	/*
		 ^      /|    ---    |\
		/|\    <-|    \|/    |->
		---     \|     v     |/
	*/
	gotoxy(xcoord-1,ycoord-1);
	switch(facing) {
		case FACINGFRONT: {fputs(uparrowtop,stdout);break;}
		case FACINGLEFT: {fputs(lfarrowtop,stdout);break;}
		case FACINGBACK: {fputs(dwarrowtop,stdout);break;}
		case FACINGRIGHT: {fputs(riarrowtop,stdout);break;}
	}
	gotoxy(xcoord-1,ycoord);
	switch(facing) {
		case FACINGFRONT: {fputs(uparrowmid,stdout);break;}
		case FACINGLEFT: {fputs(lfarrowmid,stdout);break;}
		case FACINGBACK: {fputs(dwarrowmid,stdout);break;}
		case FACINGRIGHT: {fputs(riarrowmid,stdout);break;}
	}
	gotoxy(xcoord-1,ycoord+1);
	switch(facing) {
		case FACINGFRONT: {fputs(uparrowdwn,stdout);break;}
		case FACINGLEFT: {fputs(lfarrowdwn,stdout);break;}
		case FACINGBACK: {fputs(dwarrowdwn,stdout);break;}
		case FACINGRIGHT: {fputs(riarrowdwn,stdout);break;}
	}
}

void defaultArrow(int xcoord, int ycoord, int facing) {
	drawArrow(xcoord,ycoord,facing);
	Sleep(XTEMPO);
	system("cls");
}

int moveleft(int xcoord, int ycoord, int facing) {
	int i;
	for(i=xcoord-3;i>xcoord-7;i-=3) {
		drawArrow(i,ycoord,facing);
		Sleep(XTEMPO);
		system("cls");
	}
	return i+3;
}

int moveright(int xcoord, int ycoord, int facing) {
	int i;
	for(i=xcoord+3;i<xcoord+7;i+=3) {
		drawArrow(i,ycoord,facing);
		Sleep(XTEMPO);
		system("cls");
	}
	return i-3;
}

int moveup(int xcoord, int ycoord, int facing) {
	int i;
	for(i=ycoord-3;i>ycoord-7;i-=3) {
		drawArrow(xcoord,i,facing);
		Sleep(YTEMPO);
		system("cls");
	}
	return i+3;
}

int movedown(int xcoord, int ycoord, int facing) {
	int i;
	for(i=ycoord+3;i<ycoord+7;i+=3) {
		drawArrow(xcoord,i,facing);
		Sleep(YTEMPO);
		system("cls");
	}
	return i-3;
}
