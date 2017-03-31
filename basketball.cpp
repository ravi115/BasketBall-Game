#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
#define pi 3.141592654
#define g 10
float Xn, Yn, Xnn, Ynn;
float angle;
int w = 10;
float del_t;
int cloudmomvent = -1200;
float xdist, ydist, rxy;
char str[40] = "BASKET HERE!!";
char str1[60] = "Player Name : ";
char str2[40];
char str3[30] = "Remainig Ball : = ";
char str4[15] = "Game Over";
char str5[2];//to display value of n
char str6[10] = "Score : ";
char str7[20] = "Best Score : ";
char str8[10];
char str9[20];//to display the value of score;
char str10[20] = "Your Score :-->";
char str11[20] = "-RESTART-";
char str12[10] = "MENU";
char str13[10] = "QUIT";
int noc = 5;
int n;
int score;
int rtheta = 75;//rotation of ball
int x_heli = 1400, y_heli = -500;//variable for helicopter translator
float h, x, y, p, q;
float X[100], Y[100];
int t, u;
float y_dec, x_dec;
float velocity = 105;
float tof;
float x_direction = 0, y_direction = 0;
int a = -100;
int x_t = -1225, y_t = 420;
int x_t1 = 220, y_t1 = 600;
int b_x = 400, b_y = 150;
int theta = 0, theta1 = 0;
int flag_tr = 0;//flag for trajectory
int flag_clr = 0;//different color of ball
int flag_er = 1;//flag for bal
int flag_ovr = 0;//flag for game over conditons
void basketcourt()
{
	glColor3f(.55, 0.55, 0.55);
	glBegin(GL_POLYGON);
	glVertex2f(-970, 0);
	glVertex2f(1100, 0);
	glVertex2f(1100, -40);
	glVertex2f(-970, -40);
	glEnd();
	glColor3f(.55, 0.55, 0.55);
	glBegin(GL_POLYGON);
	glVertex2f(-970, 0);
	glVertex2f(-1300, -150);
	glVertex2f(-1300, -190);
	glVertex2f(-970, -40);
	glEnd();
	glColor3f(.55, 0.55, 0.55);
	glBegin(GL_POLYGON);
	glVertex2f(1100, 0);
	glVertex2f(1300, -150);
	glVertex2f(1300, -190);
	glVertex2f(1100, -40);
	glEnd();

	glLineWidth(20);
	glColor3f(1, .6, 0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-1300, -55);
	glVertex2f(-970, 105);
	glVertex2f(1100, 105);
	glVertex2f(1300, -55);
	glEnd();

	glLineStipple(2, 0x000F);
	glEnable(GL_LINE_STIPPLE);
	glColor3f(.9, .6, .2);//lines above the waLL,	,
	glLineWidth(2);
	glBegin(GL_LINES);
	for (int i = 0; i<120; i += 1)
	{
		glVertex2f(-1300, -50 - (i + 2));
		glVertex2f(-970, 100 - i);
		glVertex2f(-970, 100 - i);
		glVertex2f(1100, 100 - i);
		glVertex2f(1100, 100 - i);
		glVertex2f(1300, -50 - (i + 2));
	}
	glEnd();
	glLineStipple(0, 0xFFFF);
	glEnable(GL_LINE_STIPPLE);

	glColor3f(.39, 0.39, 0.39);
	glBegin(GL_POLYGON);
	glVertex2f(-970, -40);
	glVertex2f(1100, -40);
	glVertex2f(1100, -200);
	glVertex2f(-970, -200);
	glEnd();
	glColor3f(.31, 0.31, 0.31);
	glBegin(GL_POLYGON);
	glVertex2f(-970, -40);
	glVertex2f(-1300, -190);
	glVertex2f(-1300, -400);
	glVertex2f(-970, -200);
	glEnd();

	glColor3f(.31, 0.31, 0.31);
	glBegin(GL_POLYGON);
	glVertex2f(1100, -40);
	glVertex2f(1300, -190);
	glVertex2f(1300, -350);
	glVertex2f(1100, -200);
	glEnd();
	glColor3f(0, .31, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-1300, -675);
	glVertex2f(-1300, -400);
	glVertex2f(-970, -200);
	glVertex2f(1100, -200);
	glVertex2f(1300, -350);
	glVertex2f(1300, -675);
	glEnd();

	glColor3f(0, 0.2, 0.3);//base floor
	glBegin(GL_POLYGON);
	glVertex2f(-1210, -580);
	glVertex2f(-790, -250);
	glVertex2f(1000, -250);
	glVertex2f(1300, -580);
	glEnd();

	glColor3f(1, 1, 1);//base floor lines
	glBegin(GL_LINES);
	glVertex2f(-1210, -580);
	glVertex2f(-790, -250);
	glVertex2f(-790, -250);
	glVertex2f(1000, -250);
	glVertex2f(1000, -250);
	glVertex2f(1300, -580);
	glVertex2f(1300, -580);
	glVertex2f(-1210, -580);
	glVertex2f(100, -250);
	glVertex2f(100, -580);
	glEnd();

	glColor3f(1, 1, 1);//base center circle
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i<360; i++)
	{
		h = i*(3.142 / 180);
		x = 100 + 90 * cos(h);
		y = -400 + 70 * sin(h);
		glVertex2f(x, y);
	}
	glEnd();
}
void ball1()
{
	if (flag_clr == 0)glColor3f(1, .5, 0);
	else if (flag_clr == 1)glColor3f(.6, .3, .4);
	else if (flag_clr == 2)glColor3f(.4, .6, .3);
	else if (flag_clr == 3)glColor3f(0, .5, .6);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	if (t<100 && u<100)glTranslatef(X[u], Y[t], 0);
	else glTranslatef(x_dec, y_dec, 0);
	//else glTranslatef(b_x,b_y,0);
	glRotatef(rtheta, 1, 1, 0);
	glutSolidSphere(80.0, 40.0, 120.0);//drawing of sphare
	if (flag_clr == 0)glColor3f(.8, .8, .8);
	else if (flag_clr == 1)glColor3f(.6, .6, .6);
	else if (flag_clr == 2)glColor3f(.6, .8, .56);
	else if (flag_clr == 3)glColor3f(.6, .7, 0);
	glLineWidth(1);
	glutWireSphere(80, 20, 10);
	glPopMatrix();
	//glutPostRedisplay();
	glFlush();
}



void basket()
{

	glColor3f(0.858824, 0.858824, 0.439216);//POLL
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(-970, 260);
	glVertex2f(-970, -390);
	glVertex2f(-950, -430);
	glVertex2f(-930, -390);
	glVertex2f(-930, 260);
	glVertex2f(-950, 260);
	glVertex2f(-950, -350);
	glVertex2f(-950, -430);
	glVertex2f(-950, 220);
	glEnd();

	glColor3f(0.137255, 0.556863, 0.419608);//circle base near poll
	glBegin(GL_POLYGON);
	glVertex2f(-855, -300);
	glVertex2f(-680, -332);
	glVertex2f(-710, -430);
	glVertex2f(-1030, -440);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_LINE_STRIP);//circle lines near the pole 
	for (int i = 0; i<360; i++)
	{
		h = i*(3.142 / 180);
		x = -700 + 70 * cos(h);
		y = -380 + 50 * sin(h);//changes now
		glVertex2f(x, y);
	}
	glEnd();

	glColor3f(1, 1, 1);//outline with white color near poll
	glBegin(GL_LINES);
	glVertex2f(-855, -300);
	glVertex2f(-680, -332);
	glVertex2f(-680, -332);
	glVertex2f(-710, -430);
	glVertex2f(-710, -430);
	glVertex2f(-1030, -440);
	glVertex2f(-1030, -440);
	glVertex2f(-855, -300);
	glEnd();

	// this the other side of the basket base

	glColor3f(0.137255, 0.556863, 0.419608);//circle base near poll
	glBegin(GL_POLYGON);
	glVertex2f(1045, -300);
	glVertex2f(845, -332);
	glVertex2f(855, -430);
	glVertex2f(1170, -440);
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_LINE_STRIP);//circle lines near the pole 
	for (int i = 0; i<360; i++)
	{
		h = i*(3.142 / 180);
		x = 850 + 70 * cos(h);
		y = -380 + 50 * sin(h);//changes now
		glVertex2f(x, y);
	}
	glEnd();

	glColor3f(1, 1, 1);//outline with white color near poll
	glBegin(GL_LINES);
	glVertex2f(1045, -300);
	glVertex2f(845, -332);
	glVertex2f(845, -332);
	glVertex2f(855, -430);
	glVertex2f(855, -430);
	glVertex2f(1170, -440);
	glVertex2f(1170, -440);
	glVertex2f(1045, -300);
	glEnd();



	glBegin(GL_POLYGON);//front side of the poll which is attached with basket board
	glColor3f(0, 0, 1);
	glVertex2f(-930, 260);
	glVertex2f(-700, 260);
	glVertex2f(-700, 220);
	glVertex2f(-950, 220);
	glEnd();

	//below code for basket board

	glColor3f(0.77, 0.77, 0.77);
	glBegin(GL_POLYGON);//board where the basket attached
	glVertex3f(-850, 450, 200);
	glVertex3f(-630, 420, -200);//changes 200 to 300
	glVertex3f(-630, 220, -400);//changes -80 to -900
	glVertex3f(-850, 200, 400);
	glEnd();

	glColor3f(0.90, 0.91, 0.98);
	glBegin(GL_POLYGON);//board where the basket attached of side line from each side of the board
	glVertex3f(-840, 440, 200);
	glVertex3f(-635, 410, -200);//changes 200 to 300
	glVertex3f(-635, 230, -400);//changes -80 to -900
	glVertex3f(-840, 210, 400);
	glEnd();
	glColor3f(0.917647, 0.678431, 0.917647);
	glBegin(GL_POLYGON);//code for hook1
	glVertex3f(-720, 280, 200);
	glVertex3f(-700, 280, -200);//changes 200 to 300
	glVertex3f(-700, 250, -400);//changes -80 to -900
	glVertex3f(-720, 250, 400);
	glEnd();

	//glLineWidth(1);
	glColor3f(0, 1, 0);
	glBegin(GL_LINES);//lines through the hing into board
	glVertex2f(-780, 360);
	glVertex2f(-660, 340);//changes 200 to 300
	glVertex2f(-660, 340);//changes -80 to -900
	glVertex2f(-660, 250);
	glVertex2f(-660, 250);
	glVertex2f(-780, 240);
	glVertex2f(-780, 240);
	glVertex2f(-780, 360);
	glEnd();



	glColor3f(1, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i<180; i += 1)//basket upper ring degree angle
	{
		h = i*(3.142 / 180);
		p = -620 + 110 * cos(h);
		q = 230 + 40 * sin(h);
		x = -620 + 100 * cos(h);
		y = 230 + 30 * sin(h);
		glVertex2f(p, q);
		glVertex2f(x, y);
	}
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_LINE_STRIP);//1st lines between the upper ring and lower ring from front side
	for (int i = 0; i <= 180; i += 14)
	{
		h = i*(3.142 / 180);
		x = -620 + 110 * cos(h);
		y = 230 + 30 * sin(h);
		p = -620 + 90 * cos(h);
		q = 50 + 20 * sin(h);
		glColor3f(0.95, 0.21, .41);
		glVertex2f(x, y);
		glColor3f(1.00, 0.11, 0.68);
		glVertex2f(p, q);
	}
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	for (int i = 0; i<180; i += 1)//lower ring of basket back side
	{
		h = i*(3.142 / 180);
		p = -620 + 90 * cos(h);
		q = 50 + 20 * sin(h);
		x = -620 + 100 * cos(h);
		y = 50 + 30 * sin(h);
		glVertex2f(x, y);
		glVertex2f(p, q);

	}
	glEnd();

	//below code for  ball function call


	//below code calculate the trajectory
	if (flag_tr == 1)
	{
		if (flag_clr == 0)glColor3f(1, .5, 0);
		else if (flag_clr == 1)glColor3f(.6, .3, .4);
		else if (flag_clr == 2)glColor3f(.4, .6, .3);
		else if (flag_clr == 3)glColor3f(0, .5, .6);
		glPointSize(2);
		glBegin(GL_POINTS);
		for (int i = 0; i<100; i++)
			glVertex2f(X[i], Y[i]);
		glEnd();
	}


	if (flag_er == 1 || flag_er == 2)
	{
		ball1();//function to draw the ball

	}





	glColor3f(1, 0, 0);
	glBegin(GL_LINE_STRIP);
	for (int i = 180; i<360; i += 1)//basket upper ring degree angle
	{
		h = i*(3.142 / 180);
		p = -620 + 110 * cos(h);
		q = 230 + 40 * sin(h);
		x = -620 + 100 * cos(h);
		y = 230 + 30 * sin(h);
		glVertex2f(p, q);
		glVertex2f(x, y);
	}
	glEnd();

	glColor3f(.25, .8, .65);
	glBegin(GL_LINE_STRIP);
	for (int i = 180; i <= 360; i += 18)//2nd lines between the upper ring and lower ring from back side
	{
		h = i*(3.142 / 180);
		x = -620 + 110 * cos(h);
		y = 230 + 30 * sin(h);
		p = -620 + 90 * cos(h);
		q = 50 + 20 * sin(h);
		glColor3f(0.798712, 0.29874, .77);
		glVertex2f(x, y);
		glColor3f(0.6356, 0.523564, .2325);
		glVertex2f(p, q);
	}
	glEnd();

	glColor3f(0, 1, 0);
	glBegin(GL_LINES);
	for (int i = 180; i<360; i += 1)//lower ring of basket
	{
		h = i*(3.142 / 180);
		p = -620 + 90 * cos(h);
		q = 50 + 20 * sin(h);
		x = -620 + 100 * cos(h);
		y = 50 + 30 * sin(h);
		glVertex2f(x, y);
		glVertex2f(p, q);

	}
	glEnd();

	glColor3f(0.917647, 0.678431, 0.917647);
	glBegin(GL_POLYGON);//code for hook2
	glVertex3f(-720, 260, 200);
	glVertex3f(-700, 260, 200);//changes 200 to 300
	glVertex3f(-690, 250, -300);//changes -80 to -900
	glVertex3f(-710, 240, 380);
	glEnd();


	glColor3f(1, .4, .5);
	glRasterPos2i(-830, 400);
	int k = 4, a = 15;//to decrement the value of x and y in x,y direction
	for (int i = 0; i<strlen(str); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, str[i]);
		//while(k<1000)
		glRasterPos2i(-830 + a, 400 - k);
		k += 3;
		a += 15;
	}
	//ball();
}


void calcu(float Xnn, float Ynn, float theta)
{
	int i;
	tof = 2 * velocity*sin(theta) / g;
	del_t = tof / 100;//time of flight at each point of x and y irrespective to trajectory
	float temp = 0;//variable to calculate time of flight at each point
	for (i = 0; i<100; i++)//this will go in timer func
	{
		x_direction = Xnn + velocity*cos(theta)*temp;//x-initial point + initial velocity * cos(theta) *time of flight at each point
		y_direction = Ynn + velocity*sin(theta)*temp - ((g*temp*temp) / 2);
		X[i] = x_direction;
		Y[i] = y_direction;
		temp += del_t;
		printf("the value of x[100]=%d and y[100]=%d\n\t", X[i], Y[i]);
	}
	x_dec = X[99];
	y_dec = Y[99];
	flag_tr = 1;
	for (i = 0; i<100; i++)
		printf("%f %f\n", X[i], Y[i]);
}
void displayname()
{
	glColor3f(0.196078, 0.8, 0.6);
	glBegin(GL_POLYGON);
	glVertex2f(-250, 675);
	glVertex2f(200, 675);
	glVertex2f(200, 620);
	glVertex2f(-250, 620);
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(-245, 670);
	glVertex2f(195, 670);
	glVertex2f(195, 670);
	glVertex2f(195, 625);
	glVertex2f(195, 625);
	glVertex2f(-245, 625);
	glVertex2f(-245, 625);
	glVertex2f(-245, 670);
	glEnd();
	glColor3f(1, 1, 1);
	glRasterPos2i(-240, 640);
	for (int i = 0; i<strlen(str1); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str1[i]);
	}
	glColor3f(1, 1, 1);
	glRasterPos2i(0, 640);
	for (int i = 0; i<strlen(str2); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str2[i]);
	}


}
void displayboard()
{
	glColor3f(0, .66, .66);//background color of scoreboard and ball
	glBegin(GL_POLYGON);
	glVertex2f(535, 675);
	glVertex2f(1340, 675);
	glVertex2f(1340, 625);
	glVertex2f(535, 625);
	glEnd();

	glColor3f(.0, .0, .66);//score board
	glBegin(GL_POLYGON);
	glVertex2f(810, 670);
	glVertex2f(1000, 670);
	glVertex2f(1000, 630);
	glVertex2f(810, 630);
	glEnd();


	glColor3f(.66, .66, .66);//remaining ball
	glBegin(GL_POLYGON);
	glVertex2f(550, 670);
	glVertex2f(800, 670);
	glVertex2f(800, 630);
	glVertex2f(550, 630);
	glEnd();

	glColor3f(.66, .66, .66);//best score
	glBegin(GL_POLYGON);
	glVertex2f(1010, 670);
	glVertex2f(1330, 670);
	glVertex2f(1330, 630);
	glVertex2f(1010, 630);
	glEnd();

	glColor3f(1, 1, 1);
	glRasterPos2i(570, 640);
	for (int i = 0; i<strlen(str3); i++)//function to write ball
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str3[i]);
	}
	n = noc;
	_itoa_s(n, str5, 10);//converting 10 into ascii of it
	glColor3f(1, 1, 1);
	glRasterPos2i(750, 640);
	for (int i = 0; i<strlen(str5); i++)//printing value of remainig ballinto the box
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str5[i]);
	}
	glColor3f(1, 1, 1);
	glRasterPos2i(820, 640);
	for (int i = 0; i<strlen(str6); i++)//print score
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str6[i]);
	}
	_itoa_s(score, str9, 10);
	glColor3f(1, 1, 0);
	glRasterPos2i(920, 640);
	for (int i = 0; i<strlen(str9); i++)//print score
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str9[i]);
	}

	glColor3f(1, 1, 1);
	glRasterPos2i(1020, 640);
	for (int i = 0; i<strlen(str7); i++)//print best score
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, str7[i]);
	}
}
void dispgameover()
{
	glBegin(GL_POLYGON);
	glColor3f(0.62352, 0.372549, 0.623529);
	glVertex2f(-500, -500);
	glColor3f(0.62352, 0.372549, 0.623529);
	glVertex2f(600, -500);
	glColor3f(0.42352, 0.272549, 0.423529);
	glVertex2f(600, 300);
	glColor3f(0.42352, 0.272549, 0.423529);
	glVertex2f(-500, 300);
	glEnd();
	glColor3f(1, 1, 1);
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i<360; i++)
	{
		h = i*(3.142 / 180);
		x = 50 + 300 * cos(h);
		y = -100 + 300 * sin(h);
		glVertex2f(x, y);
	}
	glEnd();
	glPushMatrix();
	glTranslatef(-180, 30, 0);
	glutSolidTorus(10, 15, 4, 3);
	glPopMatrix();
	glColor3f(.6, .9, 1);
	glRasterPos2i(-50, 30);
	for (int i = 0; i<strlen(str10); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str10[i]);
	}
	glColor3f(.9, .2, 0);//sqaure for displaying score
	glBegin(GL_LINE_LOOP);
	glVertex2f(-150, 5);
	glVertex2f(300, 5);
	glVertex2f(300, -100);
	glVertex2f(-150, -100);
	glEnd();

	glColor3f(1, 1, 1);
	glRasterPos2i(40, -55);
	for (int i = 0; i<strlen(str9); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str9[i]);
	}

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex2f(-120, -150);
	glVertex2f(260, -150);
	glVertex2f(260, -280);
	glVertex2f(-120, -280);
	glEnd();

	glColor3f(.8, .5, .9);//for restert
	glBegin(GL_LINE_LOOP);
	glVertex2f(-120, -150);
	glVertex2f(260, -150);
	glVertex2f(260, -280);
	glVertex2f(-120, -280);
	glEnd();

	glColor3f(.8, .5, .9);
	glRasterPos2i(-20, -225);
	for (int i = 0; i<strlen(str11); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str11[i]);
	}

	glColor3f(.4, .9, .3);//for menu
	glBegin(GL_LINE_LOOP);
	glVertex2f(-480, -300);
	glVertex2f(-220, -300);
	glVertex2f(-220, -400);
	glVertex2f(-480, -400);
	glEnd();

	glColor3f(.4, .9, .3);
	glRasterPos2i(-400, -350);
	for (int i = 0; i<strlen(str12); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str12[i]);
	}

	glColor3f(.4, .9, .3);//for quit
	glBegin(GL_LINE_LOOP);
	glVertex2f(350, -300);
	glVertex2f(580, -300);
	glVertex2f(580, -400);
	glVertex2f(350, -400);
	glEnd();

	glColor3f(.4, .9, .3);
	glRasterPos2i(430, -350);
	for (int i = 0; i<strlen(str13); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str13[i]);
	}

}
void mytimer1(int v)
{
	y_dec -= 14;
	printf("y new vai %f ,%f", y_dec, x_dec);
	if (y_dec <= -400)
	{
		flag_er = 0;
		flag_er = 2;
		u = 0; t = 0, rtheta = 45;
		flag_tr = 0;
		if (noc<1)flag_ovr = 1;
	}
	if (y_dec >= -400)
		glutTimerFunc(50, mytimer1, 20);
	glutPostRedisplay();
}
void mytimer(int v)
{
	u += 1;
	t += 1;
	/*if(X[u]>-510 && X[u]<-560 )//&& Y[t]<251 && Y[t]>208)
	{
	b_x=X[u];
	b_y=Y[t];
	b_x-=1;
	b_y+=5;
	if(b_x>-615 && b_x<-675 && b_y==320)
	glutTimerFunc(50,mytimer1,20);
	}*/
	if (u == 100 && t == 100)
	{
		score += 200;
		glutTimerFunc(50, mytimer1, 20);
	}
	rtheta += 5;
	if (rtheta>720)rtheta = 480;
	if (u <= 100)
		glutTimerFunc(50, mytimer, 20);
	glutPostRedisplay();



}
void clouds(float x, float y, float x2, float y2)
{
	int i;
	float h;
	float x1, y1;
	glColor3f(1, 1, .85644);
	for (i = 0; i<360; i += 1)
	{
		h = i*(3.142 / 180);
		x1 = x + x2 * cos(h);
		y1 = y + y2 * sin(h);
		glVertex2f(x1, y1);
	}
	glEnd();

}
void cloud()
{
	glPushMatrix();
	glTranslatef(cloudmomvent, 0, 0);

	glBegin(GL_POLYGON);
	clouds(-400, 285, 175, 45);
	glBegin(GL_POLYGON);
	clouds(-400, 250, 200, 45);
	glBegin(GL_POLYGON);
	clouds(200, 500, 150, 45);
	glBegin(GL_POLYGON);
	clouds(200, 470, 200, 45);
	glBegin(GL_POLYGON);
	clouds(700, 450, 300, 45);
	glBegin(GL_POLYGON);
	clouds(700, 500, 200, 45);
	glBegin(GL_POLYGON);
	clouds(700, 400, 150, 45);
	glPopMatrix();
}
void cloudtimer(int v)
{
	cloudmomvent += 10;
	if (cloudmomvent >= 1200)cloudmomvent = -1200;
	glutTimerFunc(120, cloudtimer, 20);
	glutPostRedisplay();
}

void fan2()
{
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(220, 600);
	glColor3f(0, 0, 0);
	glVertex2f(900, 680);
	glColor3f(1, 1, 1);
	glVertex2f(800, 740);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(220, 600);
	glColor3f(0, 0, 0);
	glVertex2f(-280, 680);
	glColor3f(1, 1, 1);
	glVertex2f(-380, 740);
	glEnd();
	//main fan
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(220, 600);
	glColor3f(0, 0, 0);
	glVertex2f(-280, 540);
	glColor3f(1, 1, 1);
	glVertex2f(-330, 480);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(220, 600);
	glColor3f(0, 0, 0);
	glVertex2f(900, 540);
	glColor3f(1, 1, 1);
	glVertex2f(800, 480);
	glEnd();
	glColor3f(.7, .7, .7);//main fan
	glBegin(GL_POLYGON);
	glVertex2f(220, 600);
	glVertex2f(235, 630);
	glVertex2f(205, 570);
	glEnd();

}
void fan()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(x_heli, y_heli, 0);
	glScalef(.25, .25, .25);
	glRotated(180, 0, 1, 0);

	glTranslated(x_t, y_t, 0);
	glRotated(theta1, 0, 0, 1);
	glTranslated(-(x_t), -(y_t), 0);
	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1);
	glVertex2f(-1225, 420);
	glColor3f(0, 0, 0);
	glVertex2f(-1490, 600);
	glColor3f(1, 1, 1);
	glVertex2f(-1485, 550);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1);
	glVertex2f(-1225, 420);
	glColor3f(0, 0, 0);
	glVertex2f(-940, 600);
	glColor3f(1, 1, 1);
	glVertex2f(-915, 550);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1);
	glVertex2f(-1225, 420);
	glColor3f(0, 0, 0);
	glVertex2f(-940, 240);
	glColor3f(1, 1, 1);
	glVertex2f(-915, 190);
	glEnd();


	glBegin(GL_TRIANGLES);
	glColor3f(1, 1, 1);
	glVertex2f(-1225, 420);
	glColor3f(0, 0, 0);
	glVertex2f(-1490, 240);
	glColor3f(1, 1, 1);
	glVertex2f(-1485, 190);
	glEnd();
	glPopMatrix();
}

void helicopter()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(x_heli, y_heli, 0);
	glScalef(.25, .25, .25);
	glRotated(180, 0, 1, 0);

	glColor3f(0.13, .37, .31);
	glBegin(GL_POLYGON);
	glVertex2f(500, -2);
	glVertex2f(500, 502);
	glVertex2f(-100, 502);
	glVertex2f(-300, 270);
	glVertex2f(-1300, 420);
	glVertex2f(-1300, 350);
	glVertex2f(-200, -2);
	glVertex2f(500, -2);
	glEnd();
	glLineWidth(2);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(-1200, 380);
	glVertex2f(-300, 180);
	glVertex2f(-300, 180);
	glVertex2f(200, 180);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(.7, .7, .7);
	for (int i = 90; i > -90; i--)
	{
		h = i*(3.142 / 180);
		x = 500 + 150 * cos(h);
		y = 250 + 252 * sin(h);
		glVertex2f(x, y);
	}
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.13, .37, .31);
	for (int i = 0; i >= -90; i--)
	{
		h = i*(3.142 / 180);
		x = 500 + 150 * cos(h);
		y = 250 + 252 * sin(h);
		glVertex2f(x, y);
	}
	glVertex2f(500, 300);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glVertex2f(325, 500);
	glColor3f(0, 0, 0);
	glVertex2f(125, 500);
	glColor3f(1, 1, 1);
	glVertex2f(125, 575);
	glColor3f(0, 0, 0);
	glVertex2f(325, 575);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	glVertex2f(325, 525);
	glColor3f(0, 1, 0);
	glVertex2f(350, 525);
	glColor3f(1, 0, 0);
	glVertex2f(350, 550);
	glColor3f(0, 1, 0);
	glVertex2f(325, 550);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex2f(205, 575);
	glColor3f(1, 1, 0);
	glVertex2f(205, 600);
	glColor3f(1, 0, 0);
	glVertex2f(245, 600);
	glColor3f(0, 1, 1);
	glVertex2f(245, 575);
	glEnd();

	glColor3f(.6, .2, .6);
	glBegin(GL_POLYGON);
	glVertex2f(-1200, 345);
	glVertex2f(-1250, 345);
	glVertex2f(-1250, 450);
	glVertex2f(-1200, 450);
	glEnd();





	glBegin(GL_LINE_STRIP);
	glColor3f(1, 1, 1);
	glVertex2f(75, 0);
	glColor3f(1, 1, 1);
	glVertex2f(75, -250);
	glColor3f(1, 1, 1);
	glVertex2f(400, -250);
	glColor3f(1, 1, 1);
	glVertex2f(400, 0);
	glColor3f(1, 1, 1);
	glVertex2f(450, 0);
	glColor3f(1, 1, 1);
	glVertex2f(450, -250);
	glColor3f(1, 1, 1);
	glVertex2f(550, -150);
	glColor3f(1, 1, 1);
	glVertex2f(550, -175);
	glColor3f(1, 1, 1);
	glVertex2f(450, -300);
	glColor3f(1, 1, 1);
	glVertex2f(0, -300);
	glColor3f(1, 1, 1);
	glVertex2f(-100, -150);
	glColor3f(1, 1, 1);
	glVertex2f(-100, -125);
	glColor3f(1, 1, 1);
	glVertex2f(25, -250);
	glColor3f(1, 1, 1);
	glVertex2f(25, 0);
	glEnd();


	glColor3f(.8, .8, .8);
	glBegin(GL_POLYGON);
	glVertex2f(a + 500, 375);
	glVertex2f(a + 475, 425);
	glVertex2f(a + 300, 425);
	glVertex2f(a + 300, 50);
	glVertex2f(a + 500, 50);
	glVertex2f(a + 500, 375);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0, 0, 0);
	glVertex2f(a + 450, 350);
	glColor3f(0, 0, 0);
	glVertex2f(a + 450, 225);
	glColor3f(0, 0, 0);
	glVertex2f(a + 350, 225);
	glColor3f(0, 0, 0);
	glVertex2f(a + 350, 350);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glColor3f(1, 0, 0);
	glVertex2f(a + 325, 150);
	glColor3f(0, 1, 0);
	glVertex2f(a + 400, 150);
	glColor3f(0, 0, 0);
	glVertex2f(a + 400, 125);
	glColor3f(1, 0, 0);
	glVertex2f(a + 360, 125);
	glColor3f(0, 1, 0);
	glVertex2f(a + 360, 140);
	glColor3f(0, 0, 0);
	glVertex2f(a + 325, 140);
	glColor3f(0, 0, 1);
	glVertex2f(a + 325, 150);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(.6, .6, .5);
	glVertex2f(a + 250, 350);
	glVertex2f(a + 50, 350);
	glVertex2f(a + 50, 225);
	glVertex2f(a + 250, 225);
	glEnd();

	glColor3f(.7, .3, .5);
	glBegin(GL_POLYGON);
	glVertex2f(a + 220, 330);
	glVertex2f(a + 70, 330);
	glVertex2f(a + 70, 245);
	glVertex2f(a + 220, 245);
	glEnd();

	glTranslated(x_t1, y_t1, 0);
	glRotated(theta, 0, 1, 0);
	glTranslated(-(x_t1), -(y_t1), 0);
	fan2();
	glPopMatrix();
	fan();

}

void helitimer(int v)
{
	x_heli -= 20;
	if (x_heli<-1400)x_heli = 1200;
	y_heli += 20;
	if (y_heli>380)y_heli = 380;
	theta += 150;
	if (theta>360)theta = 0;
	theta1 += 60;
	if (theta1>360)theta1 = 0;

	glutTimerFunc(105, helitimer, 20);
	glutPostRedisplay();

}

void disp()
{
	glClearColor(0.22, 0.69, 0.87, 0.1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	cloud();//draw sky
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	helicopter();//fn to draw helicopter
	glPopMatrix();
	basketcourt();
	basket();//function to design basket platform
	displayname();//function to display player name
	displayboard();//function to display score remaining ball e.t.c
	if (flag_ovr == 1)dispgameover();
	glutSwapBuffers();
	glFlush();
}
void mykey(unsigned char key, int x, int y)
{
	if (key == 27)exit(0);
}
void move(int x, int y)
{
	Ynn = 495 - y;
	Xnn = x - 675;
	xdist = Xnn - 675;//distance of base from left partof the windows to the now present postion of x value
	ydist = Ynn - Yn;//this is the distance between mouse click yn and move ynn
	rxy = (ydist / xdist);//ratio of perpendicular/base
	angle = atan(rxy);//{tan(Q)=y/x; so atan(y/x)=angle}
	angle = angle*(300 / 3.142);//changing in radian to degree
	printf("xdist=%f\tydist=%f\tangle=%f\n", xdist, ydist, angle);
	printf("xnn=%f,ynn=%f", Ynn, Xnn, Yn, Xn);
	if (flag_er == 1 || flag_er == 2)
	{
		calcu(Xn, Yn, angle);
	}
	glFlush();
}
void mymouse(int btn, int state, int x, int y)
{
	Yn = 495 - y;
	Xn = x - 675;
	printf("y_dec[100]=%f", y_dec);
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		printf("xn=%f\tyn=%f\n", Xn, Yn);
		if (flag_er == 1 || flag_er == 2)
			glutTimerFunc(90, mytimer, 20);
		if (Xn>-100 && Xn<100 && Yn>0 && Yn<500)
			noc -= 1;//decreamenting number of ball every click
	}
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		if (Xn>-65 && Xn<140 && Yn>-30 && Yn<35)
			printf("hii");
		else if (Xn>-265 && Xn<-125 && Yn>-100 && Yn<-45){}
		else if (Xn>195 && Xn<320 && Yn>-100 && Yn<-45)
			exit(0);
	}
	glutPostRedisplay();
}
void menu(int d)
{
	switch (d)
	{
	case 1: flag_clr = 1;
		break;
	case 2: flag_clr = 2;
		break;
	case 3: flag_clr = 3;
		break;
	case 4:flag_clr = 0;
	}
	glutPostRedisplay();
}
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-675, 675, -675, 675, -675, 675);
	glMatrixMode(GL_MODELVIEW);
}
void myreshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w>h)
		glOrtho(-675 * (GLfloat)w / (GLfloat)h, 675 * (GLfloat)w / (GLfloat)h, -675, 675, -675, 675);
	else
		glOrtho(-675, 675, -675 * (GLfloat)h / (GLfloat)w, 675 * (GLfloat)h / (GLfloat)w, -675, 675);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
int main()
{
	printf("enter player name\t");
	scanf_s("%s", str2);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glutInitWindowSize(1350, 900);
	glutCreateWindow("BASKET-BALL");
	myinit();
	glutReshapeFunc(myreshape);
	glutDisplayFunc(disp);
	glutTimerFunc(80, cloudtimer, 20);
	glutTimerFunc(20, helitimer, 20);
	glutMouseFunc(mymouse);
	glutMotionFunc(move);
	glutKeyboardFunc(mykey);
	glutCreateMenu(menu);
	glutAddMenuEntry("Ball_type-1", 1);
	glutAddMenuEntry("Ball_type-2", 2);
	glutAddMenuEntry("Ball_type-3", 3);
	glutAddMenuEntry("Original_ball", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}
