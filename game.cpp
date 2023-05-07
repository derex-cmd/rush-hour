//============================================================================
// Name        : Omer Nasir
// Author      : FAST CS Department (D)
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include <string>
#include <cmath> // for basic math functions such as cos, sin, sqrt
#include <fstream>

using namespace std;

/****passColor/1/2 are used as condition to pickup passengers****/
bool passColor = true;
bool passColor1 = true;
bool passColor2 = true;
bool PassengerOnBoard = false;//this will tell us if passenger is in the taxi currently
bool displayDropoff = true; //this is used for dropoff of passengers
/****timeleft is used for timer fucntion****/
int timeleft = 180;

int dropoffx, dropoffy; // these are the random coordinates for passengers
int counter = 0;
/*************These bool expressions are for main menu******************/
bool pressOne = false;
bool pressTwo = false;
bool mainGame = true;
bool menu = true;
bool scoreboard = true;

void SetCanvasSize(int width, int height)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*********drawCar Function will be used for our taxi********/
int xI = 400, yI = 400;
int score = 0; //total score


/*This function will find a random dropoff destination for the passenger*/
void area()
{
	int random = GetRandInRange(1, 3);
	switch (random)
	{
	case 1:
		dropoffx = GetRandInRange(20, 900);
		dropoffy = GetRandInRange(700, 800);
		break;
	case 2:
		dropoffx = GetRandInRange(350, 550);
		dropoffy = GetRandInRange(500, 600);
		break;
	case 3:
		dropoffx = GetRandInRange(550, 730);
		dropoffy = GetRandInRange(0, 300);
		break;
	}
}

void drawCar()
{
	DrawSquare(xI, yI, 25, colors[WHITE]);

	glutPostRedisplay();
}

/***** drawCar1/2/3/4 are used for random moving cars in our game****/
int rx = 150, ry = 665; //these are the coordinates for random car 1

void drawCar1()
{
	DrawSquare(rx, ry, 25, colors[GOLD]);

	glutPostRedisplay();
}

int rx1 = 315, ry1 = 215; //these are the coordinates for random car 2

void drawCar2()
{
	DrawSquare(rx1, ry1, 25, colors[GOLD]);

	glutPostRedisplay();
}

int rx2 = 850, ry2 = 165; //these are the coordinates for random car 3

void drawCar3()
{
	DrawSquare(rx2, ry2, 25, colors[GOLD]);

	glutPostRedisplay();
}

int rx3 = 700, ry3 = 545; //these are the coordinates for random car 4

void drawCar4()
{
	DrawSquare(rx3, ry3, 25, colors[GOLD]);

	glutPostRedisplay();
}

bool flag = true;
void moveCar()
{

	if (xI > 10 && flag)
	{
		xI -= 5;
		cout << "going left";
		if (xI < 100)

			flag = false;
	}
	else if (xI < 1010 && !flag)
	{
		cout << "go right";
		xI += 5;
		if (xI > 900)
			flag = true;
	}
}
/*****The functions used below moveCar1/2/3/4 will be used to move these random cars in random direction****/

/***This function will move our car 1 in left and right direction***/
bool flag1 = true;
void moveCar1()
{

	if (rx > 70 && flag1)
	{
		rx -= 5;
		cout << "going left";
		if (rx < 100)

			flag1 = false;
	}
	else if (rx < 500 && !flag1)
	{
		cout << "go right";
		rx += 5;
		if (rx > 450)
			flag1 = true;
	}
}

/***This function will move our car 2 in up and down direction***/
bool flag2 = true;
void moveCar2()
{

	if (ry1 > 50 && flag2)
	{
		ry1 -= 5;
		cout << "going down";
		if (ry1 < 150)

			flag2 = false;
	}
	else if (ry1 < 500 && !flag2)
	{
		cout << "go up";
		ry1 += 5;
		if (ry1 > 370)
			flag2 = true;
	}
}

/***This function will move our car 3 in left and right direction***/
bool flag3 = true;
void moveCar3()
{

	if (rx2 > 300 && flag3)
	{
		rx2 -= 5;
		cout << "going left";
		if (rx2 < 600)

			flag3 = false;
	}
	else if (rx2 < 900 && !flag3)
	{
		cout << "go right";
		rx2 += 5;
		if (rx2 > 870)
			flag3 = true;
	}
}

/***This function will move our car 4 in left and right direction***/
bool flag4 = true;
void moveCar4()
{

	if (rx3 > 250 && flag4)
	{
		rx3 -= 5;
		cout << "going left";
		if (rx3 < 650)

			flag4 = false;
	}
	else if (rx3 < 900 && !flag4)
	{
		cout << "go right";
		rx3 += 5;
		if (rx3 > 880)
			flag4 = true;
	}
}

void Collision1()
{
	/*****Collsion for building 1*****/
	/****From below****/
	if (yI == 620 && (xI == 80 || xI == 90 || xI == 100 || xI == 110 || xI == 120 || xI == 130 || xI == 140 || xI == 150 || xI == 160 || xI == 170 || xI == 180 || xI == 190 || xI == 200 || xI == 210 || xI == 220 || xI == 230 || xI == 240 || xI == 250 || xI == 260 || xI == 270 || xI == 280 || xI == 290 || xI == 300))
	{
		yI -= 20;
		score -= 2;
	}

	/****From above****/
	if (yI == 650 && (xI == 80 || xI == 90 || xI == 100 || xI == 110 || xI == 120 || xI == 130 || xI == 140 || xI == 150 || xI == 160 || xI == 170 || xI == 180 || xI == 190 || xI == 200 || xI == 210 || xI == 220 || xI == 230 || xI == 240 || xI == 250 || xI == 260 || xI == 270 || xI == 280 || xI == 290 || xI == 300))
	{
		yI += 20;
		score -= 2;
	}

	/****From left****/
	if ((xI == 100 || xI == 90 || xI == 80) && (yI == 650 || yI == 640 || yI == 630 || yI == 660))
	{
		xI -= 20;
		score -= 2;
	}

	/****From right****/
	if (xI == 300 && (yI == 650 || yI == 640 || yI == 630 || yI == 660))
	{
		xI += 20;
		score -= 2;
	}

	/****Collision for Building 2****/
	/****From right****/
	if ((xI == 70 || xI == 80 || xI == 90 || xI == 100) && (yI == 380 || yI == 390 || yI == 400 || yI == 410 || yI == 420 || yI == 430 || yI == 440 || yI == 450 || yI == 460 || yI == 470 || yI == 480 || yI == 490 || yI == 500 || yI == 510 || yI == 520 || yI == 530 || yI == 540 || yI == 550))
	{
		xI -= 20;
		score -= 2;
	}

	/****From left****/
	if ((xI == 100 || xI == 110) && (yI == 380 || yI == 390 || yI == 400 || yI == 410 || yI == 420 || yI == 430 || yI == 440 || yI == 450 || yI == 460 || yI == 470 || yI == 480 || yI == 490 || yI == 500 || yI == 510 || yI == 520 || yI == 530 || yI == 540 || yI == 550))
	{
		xI += 20;
		score -= 2;
	}
	/****From below****/
	if ((xI == 90 || xI == 100 || xI == 110) && (yI == 370 || yI == 380 || yI == 390))
	{
		yI -= 20;
		score -= 2;
	}

	/****From above****/
	if ((xI == 90 || xI == 100 || xI == 110) && (yI == 540 || yI == 550 || yI == 560))
	{
		yI += 20;
		score -= 2;
	}

	/****	Collision for Sqaure Building****/
	/****From left****/
	if ((xI == 80 || xI == 90 || xI == 100) && (yI == 80 || yI == 90 || yI == 100 || yI == 110 || yI == 120 || yI == 130 || yI == 140 || yI == 150 || yI == 160 || yI == 170 || yI == 180 || yI == 190 || yI == 200 || yI == 210))
	{
		xI -= 20;
		score -= 2;
	}

	/****From right****/
	if ((xI == 200) && (yI == 80 || yI == 90 || yI == 100 || yI == 110 || yI == 120 || yI == 130 || yI == 140 || yI == 150 || yI == 160 || yI == 170 || yI == 180 || yI == 190 || yI == 200 || yI == 210))
	{
		xI += 20;
		score -= 2;
	}

	/****From below****/
	if ((yI == 80 || yI == 90 || yI == 100) && (xI == 80 || xI == 90 || xI == 100 || xI == 110 || xI == 120 || xI == 130 || xI == 140 || xI == 150 || xI == 160 || xI == 170 || xI == 180 || xI == 190 || xI == 200 || xI == 210))
	{
		yI -= 20;
		score -= 2;
	}

	/****From above****/
	if ((yI == 200) && (xI == 80 || xI == 90 || xI == 100 || xI == 110 || xI == 120 || xI == 130 || xI == 140 || xI == 150 || xI == 160 || xI == 170 || xI == 180 || xI == 190 || xI == 200 || xI == 210))
	{
		yI += 20;
		score -= 2;
	}

	/****Collision for building 4****/
	/****From below****/
	if ((xI >= 480 && xI <= 800) && (yI == 620))
	{
		yI -= 20;
		score -= 2;
	}

	/****From above****/
	if ((xI >= 480 && xI <= 800) && (yI == 650))
	{
		yI += 20;
		score -= 2;
	}

	/****From left****/
	if ((xI == 480) && (yI == 630 || yI == 640 || yI == 650 || yI == 660))
	{
		xI -= 20;
		score -= 2;
	}

	/****From right****/
	if ((xI == 800) && (yI == 630 || yI == 640 || yI == 650 || yI == 660))
	{
		xI += 20;
		score -= 2;
	}

	/****Collision for building 5****/
	/****From right****/
	if ((xI == 280 || xI == 290 || xI == 300 || xI == 310) && (yI >= 150 && yI <= 350))
	{
		xI += 20;
		score -= 2;
	}

	/****From left****/
	if ((xI == 270 || xI == 280 || xI == 290 || xI == 310) && (yI >= 150 && yI <= 350))
	{
		xI -= 20;
		score -= 2;
	}

	/****From above****/
	if ((xI == 270 || xI == 280 || xI == 290 || xI == 300) && (yI == 340))
	{
		yI += 20;
		score -= 2;
	}

	/****From below****/
	if ((xI == 270 || xI == 280 || xI == 290 || xI == 300) && (yI == 150))
	{
		yI -= 20;
		score -= 2;
	}

	/****Collision for building 6****/
	/****From left****/
	if ((xI == 470 || xI == 480) && (yI >= 0 && yI <= 300))
	{
		xI -= 20;
		score -= 2;
	}

	/****From right****/
	if ((xI == 500 || xI == 510) && (yI >= 0 && yI <= 300))
	{
		xI += 20;
		score -= 2;
	}

	/****From above****/
	if ((xI == 470 || xI == 480 || xI == 490 || xI == 500 || xI == 510) && (yI == 300))
	{
		yI += 20;
		score -= 2;
	}

	/****Collision for building 7****/
	/****From below****/
	if ((xI >= 300 && xI <= 500) && yI == 420)
	{
		yI -= 20;
		score -= 2;
	}

	/****From above****/
	if ((xI >= 300 && xI <= 500) && yI == 450)
	{
		yI += 20;
		score -= 2;
	}

	/****From left****/
	if ((xI == 280) && (yI >= 420 && yI <= 450))
	{
		xI -= 20;
		score -= 2;
	}

	/****From right****/
	if ((xI == 500) && (yI >= 420 && yI <= 450))
	{
		xI += 20;
		score -= 2;
	}

	/****Collision for Building 8****/ /****From below****/
	if ((xI >= 770 && xI <= 1050) && (yI == 120))
	{
		yI -= 20;
		score -= 2;
	}

	/****From above****/
	if ((xI >= 770 && xI <= 1050) && (yI == 150))
	{
		yI += 20;
		score -= 2;
	}

	/****From left****/
	if ((xI == 770) && (yI >= 120 && yI <= 160))
	{
		xI -= 20;
		score -= 2;
	}

	/****Collision for building 9****/
	/****From below****/
	if ((xI >= 570 && xI <= 910) && (yI == 500))
	{
		yI -= 20;
		score -= 2;
	}

	/****From above****/
	if ((xI >= 570 && xI <= 910) && (yI == 540))
	{
		yI += 20;
		score -= 2;
	}

	/****From left****/
	if ((xI == 570) && (yI >= 350 && yI <= 550))
	{
		xI -= 20;
		score -= 2;
	}

	/****From right****/
	if ((xI == 610) && (yI >= 350 && yI <= 550))
	{
		xI += 20;
		score -= 2;
	}

	/****From below (small space)****/
	if ((xI == 580 || xI == 590 || xI == 600) && (yI == 370 || yI == 360 || yI == 350))
	{
		yI -= 20;
		score -= 2;
	}

	/****Collision with tree 1****/
	if ((xI == 590 || xI == 595) && (yI == 610 || yI == 610 || yI == 615 || yI == 620))
	{
		score -= 2;
	}

	/****Collision with tree 2****/
	if ((xI == 70 || xI == 75) && (yI == 195 || yI == 200 || yI == 205))
	{
		score -= 2;
	}

	/****Collision with tree 3****/
	if ((xI == 425 || xI == 430) && (yI == 470 || yI == 475 || yI == 480))
	{
		score -= 2;
	}

	/****Collision with tree 4****/
	if ((xI == 820 || xI == 825) && (yI == 295 || yI == 300 || yI == 305))
	{
		score -= 2;
	}

	/****Collision with tree 5****/
	if ((xI == 745 || xI == 750) && (yI == 490 || yI == 495 || yI == 500))
	{
		score -= 2;
	}

	/****Collision with person 1****/
	/****From left****/
	if ((xI == 680) && (yI == 660 || yI == 670 || yI == 680 || yI == 690 || yI == 700 || yI == 710))
	{
		xI -= 20;
		score -= 5;
	}

	/****From right****/
	if ((xI == 740) && (yI == 660 || yI == 670 || yI == 680 || yI == 690 || yI == 700 || yI == 710))
	{
		xI += 20;
		score -= 5;
	}

	/****Frop top****/
	if ((xI == 680 || xI == 690 || xI == 700 || xI == 710 || xI == 720 || xI == 730 || xI == 740) && (yI == 720))
	{
		yI += 20;
		score -= 5;
	}

	/****Collision with person 2****/
	/****From Left*****/
	if ((xI == 580) && (yI == 0 || yI == 10 || yI == 20 || yI == 30 || yI == 40 || yI == 50))
	{
		xI -= 20;
		score -= 5;
	}

	/****From right****/
	if ((xI == 630) && (yI == 0 || yI == 10 || yI == 20 || yI == 30 || yI == 40 || yI == 50))
	{
		xI += 20;
		score -= 5;
	}

	/****From top****/
	if ((xI == 580 || xI == 590 || xI == 600 || xI == 610 || xI == 620 || xI == 5630) && (yI == 50))
	{
		yI += 20;
		score -= 5;
	}

	/****Collision with person 3****/
	/****From right****/
	if ((xI == 50) && (yI == 280 || yI == 290 || yI == 300 || yI == 310 || yI == 320 || yI == 330 || yI == 340 || yI == 350))
	{
		xI += 20;
		score -= 5;
	}

	/****From below****/
	if ((xI == 0 || xI == 10 || xI == 20 || xI == 30 || xI == 40 || xI == 50) && (yI == 280 || yI == 290))
	{
		yI -= 20;
		score -= 5;
	}

	/****From above****/
	if ((xI == 0 || xI == 10 || xI == 20 || xI == 30 || xI == 40 || xI == 50) && (yI == 360))
	{
		yI += 20;
		score -= 5;
	}
}

void passenger() //This function is used to pick up the passenger
{
	/****Collision with person 1****/
	/****From left****/
	if ((xI == 670) && (yI == 650 || yI == 660 || yI == 670 || yI == 680 || yI == 690 || yI == 700 || yI == 710 || yI == 720))
	{
		if (PassengerOnBoard==false)
		{
			area();
			passColor = false;
			PassengerOnBoard = true;
		}
	}

	/****From right****/
	if ((xI == 750) && (yI == 660 || yI == 670 || yI == 680 || yI == 690 || yI == 700 || yI == 710 || yI == 720))
	{
		if (PassengerOnBoard==false)
		{
			area();
			passColor = false;
			PassengerOnBoard = true;
		}
	}

	/****Frop top****/
	if ((xI == 680 || xI == 690 || xI == 700 || xI == 710 || xI == 720 || xI == 730 || xI == 740) && (yI == 710))
	{
		if (PassengerOnBoard==false)
		{
			area();
			passColor = false;
			PassengerOnBoard = true;
		}
	}

	PassengerOnBoard = false;
}

void passenger1() //This function is used to pick up the passenger
{
	/****Collision with person 2****/
	/****From Left*****/
	if ((xI == 570) && (yI == 0 || yI == 10 || yI == 20 || yI == 30 || yI == 40 || yI == 50 || yI == 60))
	{
		if (PassengerOnBoard==false)
		{
			area();
			passColor1 = false;
			PassengerOnBoard = true;
		}
	}

	/****From right****/
	if ((xI == 640) && (yI == 0 || yI == 10 || yI == 20 || yI == 30 || yI == 40 || yI == 50 || yI == 60))
	{
		if (PassengerOnBoard==false)
		{
			area();
			passColor1 = false;
			PassengerOnBoard = true;
		}
	}
	

	/****From top****/
	if ((xI == 570 || xI == 580 || xI == 590 || xI == 600 || xI == 610 || xI == 620 || xI == 630) && (yI == 50 || yI == 60))
	{
		if (PassengerOnBoard==false)
		{
			area();
			passColor1 = false;
			PassengerOnBoard = true;
		}
	}
/****If none of the the conditions arent met, bool stays false****/
	PassengerOnBoard = false;
}

void passenger2() //This function is used to pick up the passenger
{
	/****Collision with person 3****/
	/****From right****/
	if ((xI == 60) && (yI == 280 || yI == 290 || yI == 300 || yI == 310 || yI == 320 || yI == 330 || yI == 340 || yI == 350))
	{
		if (PassengerOnBoard==false)
		{
			area();
			passColor2 = false;
			PassengerOnBoard = true;
		}
	}

	/****From below****/
	if ((xI == 0 || xI == 10 || xI == 20 || xI == 30 || xI == 40 || xI == 50) && (yI == 280 || yI == 290 || yI == 300))
	{
		if (PassengerOnBoard==false)
		{
			area();
			passColor2 = false;
			PassengerOnBoard = true;
		}
	}

	/****From above****/
	if ((xI == 0 || xI == 10 || xI == 20 || xI == 30 || xI == 40 || xI == 50) && (yI == 360 || yI == 370))
	{
		if (PassengerOnBoard==false)
		{
			area();
			passColor2 = false;
			PassengerOnBoard = true;
		}
	}
/****If none of the the conditions arent met, bool stays false****/
	PassengerOnBoard = false;
}

void GameDisplay() /**/
{

	glClearColor(0 /*Red Component*/, 0,						 //148.0/255/*Green Component*/,
				 0.0 /*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear(GL_COLOR_BUFFER_BIT);								 //Update the colors
	//This will display the main menu
	if (menu == true)
	{
		DrawString(250, 700, "-------------------------", colors[CYAN]);
		DrawString(300, 600, "        RUSH HOUR        ", colors[CYAN]);
		DrawString(250, 500, "-------------------------", colors[CYAN]);
		DrawString(300, 400, "   1 - View ScoreBoard   ", colors[CYAN]);
		DrawString(300, 300, "     2 - Start Game      ", colors[CYAN]);
	}

	if (pressOne) //if user presses one, display scoreboard
	{
		menu = false;
		DrawString(250, 700, "--------SCOREBOARD--------", colors[CYAN]);
	}

	if (pressTwo) //if user presses two, start the game
	{
		if (mainGame == true)
		{
			scoreboard = false;
			menu = false;

	/****all of the drawline functions are used for buildings****/
	/****All Dark_SLATE_GRAY lines represents builings****/

			DrawString(50, 800, "Score=", colors[MISTY_ROSE]);
			/****This will display the score****/
			DrawString(200, 800, to_string(score), colors[MISTY_ROSE]);

			DrawLine(100, 400, 100, 550, 15, colors[DARK_SLATE_GRAY]);

			DrawSquare(100, 100, 110, colors[DARK_SLATE_GRAY]);

			DrawCircle(85, 200, 10, colors[CRIMSON]); //represents a tree

			DrawLine(100, 650, 300, 650, 15, colors[DARK_SLATE_GRAY]);

			DrawLine(500, 650, 800, 650, 15, colors[DARK_SLATE_GRAY]);

			DrawCircle(600, 625, 10, colors[CRIMSON]); //represents a tree

			DrawLine(300, 450, 500, 450, 15, colors[DARK_SLATE_GRAY]);

			DrawCircle(425, 475, 10, colors[CRIMSON]); //represents a tree

			DrawLine(500, 0, 500, 300, 15, colors[DARK_SLATE_GRAY]);

			DrawCircle(825, 300, 10, colors[CRIMSON]); //represents a tree

			DrawLine(300, 150, 300, 350, 15, colors[DARK_SLATE_GRAY]);

			DrawLine(800, 150, 1020, 150, 15, colors[DARK_SLATE_GRAY]);

			DrawLine(600, 530, 900, 530, 15, colors[DARK_SLATE_GRAY]);

			DrawCircle(750, 505, 10, colors[CRIMSON]); //represents a tree

			DrawLine(600, 540, 600, 370, 15, colors[DARK_SLATE_GRAY]);

			// person 1
			if (passColor)
			{
				DrawTriangle(700, 660, 720, 710, 740, 660, colors[MISTY_ROSE]);
				DrawCircle(720, 710, 10, colors[MISTY_ROSE]);
			}
			else
			{
				DrawTriangle(700, 660, 720, 710, 740, 660, colors[BLACK]);
				DrawCircle(720, 710, 10, colors[BLACK]);
	/****This if loop with disappear the destination mark****/
				if (displayDropoff)
				{
					DrawCircle(dropoffx, dropoffy, 10, colors[FOREST_GREEN]);
				}
			}

			//person 2
			if (passColor1)
			{
				DrawTriangle(600, 0, 620, 50, 640, 0, colors[MISTY_ROSE]);
				DrawCircle(620, 50, 10, colors[MISTY_ROSE]);
			}
			else
			{
				DrawTriangle(600, 0, 620, 50, 640, 0, colors[BLACK]);
				DrawCircle(620, 50, 10, colors[BLACK]);
	/****This if loop with disappear the destination mark****/
				if (displayDropoff)
				{
					DrawCircle(dropoffx, dropoffy, 10, colors[FOREST_GREEN]);
				}
			}
			//person 3
			if (passColor2)
			{
				DrawTriangle(0, 300, 20, 350, 40, 300, colors[MISTY_ROSE]);
				DrawCircle(20, 350, 10, colors[MISTY_ROSE]);
			}
			else
			{
				DrawTriangle(0, 300, 20, 350, 40, 300, colors[BLACK]);
				DrawCircle(20, 350, 10, colors[BLACK]);
	/****This if loop with disappear the destination mark****/
				if (displayDropoff)
				{
					DrawCircle(dropoffx, dropoffy, 10, colors[FOREST_GREEN]);
				}
			}
	/****This will display the time remaining for the game****/
			DrawString(600, 800, "Time= " + Num2Str(timeleft) + "seconds", colors[MISTY_ROSE]);

			drawCar();
			drawCar1();
			drawCar2();
			drawCar3();
			drawCar4();
		}
	}
	glutSwapBuffers(); // do not modify this line..
}

void NonPrintableKeys(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/)
	{
		// what to do when left key is pressed...
		xI -= 10;
	}
	else if (key == GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/)
	{
		xI += 10;
	}
	else if (key == GLUT_KEY_UP /*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/)
	{
		yI += 10;
	}

	else if (key == GLUT_KEY_DOWN /*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/)
	{
		yI -= 10;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	Collision1();
	glutPostRedisplay();
}

void PrintableKeys(unsigned char key, int x, int y)
{
	if (key == 27 /* Escape key ASCII*/)
	{
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 32) //Key for space
	{
		counter++;//increament in counter
/****If space bar is pressed once, passengers will be picked****/
		if (counter % 2 != 0)
		{
			passenger();
			passenger1();
			passenger2();
			displayDropoff = true;
		}
/****If space bar is pressed twice, passgeners will be dropped and score will be incremented by 10****/
		else
		{
			DrawCircle(dropoffx, dropoffy, 10, colors[BLACK]);
			displayDropoff = false;
			score += 10;
		}
	}

	if (key == 49) //ASCII for 1
	{
		pressOne = true;
	}

	if (key == 50) //ASCII for 2
	{
		pressTwo = true;
	}

	area();

	glutPostRedisplay();
}


void Timer(int m)
{

	moveCar1();
	moveCar2();
	moveCar3();
	moveCar4();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
	glutPostRedisplay();
}

/****This function created for timer with faster fps****/

void Timer1(int m)
{
	glutTimerFunc(1000, Timer1, 0);
	glutPostRedisplay();
	if (timeleft > 0)
	{
		timeleft -= 1;
	}
}

void MousePressedAndMoved(int x, int y)
{
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y)
{
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

void MouseClicked(int button, int state, int x, int y)
{

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
	{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;
	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		cout << "Right Button Pressed" << endl;
	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */


int main(int argc, char *argv[])
{

	int width = 1020, height = 840;
	InitRandomizer();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(width, height);
	glutCreateWindow("Rush Hour by Omer Nasir");
	SetCanvasSize(width, height); // set the number of pixels...

	glutDisplayFunc(GameDisplay);
	glutSpecialFunc(NonPrintableKeys);
	glutKeyboardFunc(PrintableKeys);
	glutTimerFunc(100, Timer, 0);
	glutTimerFunc(1000, Timer1, timeleft);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved);	  // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
