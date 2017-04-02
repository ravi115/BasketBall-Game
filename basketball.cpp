#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
#include<Windows.h>
#define pi 3.141592654
#define g 10


char st1[30]="RNS INSTITUTE OF TECHNOLOGY";
char st2[10]="Hello";
char st3[20]="<<--PLAY GAME -->>";
char st4[20]="HOW TO PLAY";
char st5[150]="|-----------------------------|";
char st6[]="Rules:-->";
char st7[]="1.click mouse left button";
char st8[]="2.drag the mouse back by keeping in same position to set the trajectory";
char st9[]="3.release the mouse to basket"; 
int flag_rule=0;



float Xn,Yn,Xnn,Ynn;
int yp,xp;
float angle;
int w=10;
float del_t;
int cloudmomvent = -1200;
float xdist,ydist,rxy;
char str[40]="BASKET HERE!!";
char str1[60]="Welcome ";
char str2[40];
char str3[30]="Remainig Ball : = ";
char str4[15]="Game Over";
char str5[2];//to display value of n
char str6[10]="Score : ";
char str7[20]="Best Score : ";
char str8[10];
char str9[20];//to display the value of score;
char str10[20]="Your Score :-->";
char str11[20]="-RESTART-";
char str12[10]="HOME";
char str13[10]="QUIT";
char str14[15]="Nice Basket";
char str15[20]="Yeah";
char str16[20]="Ooops Missed";
int noc=6;
int n;
int score;
int rtheta=75;//rotation of ball
int x_heli=1400,y_heli=-500;//variable for helicopter translator
float h,x,y,p,q;
float X[100],Y[100];
int t,u;
float y_dec,x_dec;
float velocity=105;
float tof;
float x_direction=0,y_direction=0;
int a=-100;
int x_t = -1225, y_t = 420;
int x_t1 = 220, y_t1 = 600;
int b_x=400,b_y=150;
int theta=0,theta1=0;
int flag_tr=0;//flag for trajectory
int flag_clr=0;//different color of ball
int flag_er=1;//flag for bal
int flag_ovr=0;//flag for game over conditons
int flag_goal=0;//flag to display type of goal whenever a goal has to be done

void latter()
{
	glColor3f(1,.5,0);
	glBegin(GL_POLYGON);
	glVertex2f(-400,400);
	glVertex2f(-300,350);
	glVertex2f(-400,300);
	glVertex2f(-300,250);
	glVertex2f(-400,200);
	glEnd();

	glLineWidth(4);
	glColor3f(1,.5,0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-290,200);
	glVertex2f(-250,400);
	glVertex2f(-210,200);
	glEnd();

	glColor3f(1,.5,0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-150,400);
	glVertex2f(-190,300);
	glVertex2f(-140,250);
	glVertex2f(-190,200);
	glEnd();
	
	glColor3f(1,.5,0);
	glBegin(GL_LINES);
	glVertex2f(-120,400);
	glVertex2f(-120,200);
	glEnd();

	glColor3f(1,.5,0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-60,390);
	glVertex2f(-122,300);
	glVertex2f(-60,210);
	glEnd();

	glColor3f(1,.5,0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(10,400);
	glVertex2f(-40,400);
	glVertex2f(-40,200);
	glVertex2f(10,200);
	glEnd();
	
	glColor3f(1,.5,0);
	glBegin(GL_LINES);
	glVertex2f(8,320);
	glVertex2f(-42,320);
	glEnd();
		
	glColor3f(1,.5,0);
	glBegin(GL_LINES);
	glVertex2f(80,400);
	glVertex2f(30,400);
	glEnd();
	
	glColor3f(1,.5,0);
	glBegin(GL_LINES);
	glVertex2f(55,400);
	glVertex2f(55,200);
	glEnd();

	glColor3f(1,.5,0);
	glBegin(GL_POLYGON);
	glVertex2f(100,400);
	glVertex2f(200,350);
	glVertex2f(100,300);
	glVertex2f(200,250);
	glVertex2f(100,200);
	glEnd();
		
	glColor3f(1,.5,0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(300,200);
	glVertex2f(260,400);
	glVertex2f(220,200);
	glEnd();

	glColor3f(1,.5,0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(320,400);
	glVertex2f(320,200);
	glVertex2f(360,200);
	glEnd();

	glColor3f(1,.5,0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(380,400);
	glVertex2f(380,200);
	glVertex2f(420,200);
	glEnd();
}


void basketcourt()
{
	glColor3f(.33,0.33,0.33);
	glBegin(GL_POLYGON);
	glVertex2f(-970,0);
	glVertex2f(1100,0);
	glVertex2f(1100,-40);
	glVertex2f(-970,-40);
	glEnd();
	//glColor3f(.55,0.55,0.55);
	glBegin(GL_POLYGON);
	glVertex2f(-970,0);
	glVertex2f(-1300,-150);
	glVertex2f(-1300,-190);
	glVertex2f(-970,-40);
	glEnd();
	//glColor3f(.55,0.55,0.55);
	glBegin(GL_POLYGON);
	glVertex2f(1100,0);
	glVertex2f(1300,-150);
	glVertex2f(1300,-190);
	glVertex2f(1100,-40);
	glEnd();

	glLineWidth(20);//relling of the pipe over the wall
	glColor3f(1,.6,0);
	glBegin(GL_LINE_STRIP);
	glVertex2f(-1300,-55);
	glVertex2f(-970,105);
	glVertex2f(1100,105);
	glVertex2f(1300,-55);
	glEnd();

	glLineStipple(2, 0x000F);
    glEnable(GL_LINE_STIPPLE);
	glColor3f(.9,.6,.2);//lines above the waLL,	,
	glLineWidth(2);
	glBegin(GL_LINES);
	for(int i=0;i<120;i+=1)
	{
		glVertex2f(-1300,-50-(i+2));
		glVertex2f(-970,100-i);
		glVertex2f(-970,100-i);
		glVertex2f(1100,100-i);
		glVertex2f(1100,100-i);
		glVertex2f(1300,-50-(i+2));
	}
	glEnd();
	glLineStipple(0, 0xFFFF);
    glEnable(GL_LINE_STIPPLE);

	glColor3f(.22,.22,.22);//center wall
	glBegin(GL_POLYGON);
	glVertex2f(-970,-40);
	glVertex2f(1100,-40);
	glVertex2f(1100,-200);
	glVertex2f(-970,-200);
	glEnd();

	glColor3f(.22,.22,.22);
	glBegin(GL_POLYGON);
	glVertex2f(-970,-40);
	glVertex2f(-1300,-190);
	glVertex2f(-1300,-400);
	glVertex2f(-970,-200);
	glEnd();
	
	glColor3f(.22,.22,.22);
	glBegin(GL_POLYGON);
	glVertex2f(1100,-40);
	glVertex2f(1300,-190);
	glVertex2f(1300,-350);
	glVertex2f(1100,-200);
	glEnd();
	glColor3f(0,.31,0);
	glBegin(GL_POLYGON);
	glVertex2f(-1300,-675);
	glVertex2f(-1300,-400);
	glVertex2f(-970,-200);
	glVertex2f(1100,-200);
	glVertex2f(1300,-350);
	glVertex2f(1300,-675);
	glEnd();

glColor3f(0,0.2,0.3);//base floor
	glBegin(GL_POLYGON);
	glVertex2f(-1210,-580);
	glVertex2f(-790,-250);
	glVertex2f(1000,-250);
	glVertex2f(1300,-580);
	glEnd();

	glColor3f(1,1,1);//base floor lines
	glBegin(GL_LINES);
	glVertex2f(-1210,-580);
	glVertex2f(-790,-250);
	glVertex2f(-790,-250);
	glVertex2f(1000,-250);
	glVertex2f(1000,-250);
	glVertex2f(1300,-580);
	glVertex2f(1300,-580);
	glVertex2f(-1210,-580);
	glVertex2f(100,-250);
	glVertex2f(100,-580);
	glEnd();
	
	glColor3f(1,1,1);//base center circle
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<360;i++)
	{
		h=i*(3.142/180);
		x=100+90*cos(h);
		y=-400+70*sin(h);
		glVertex2f(x,y);
	}
	glEnd();	
}
void ball1()
{
			if(flag_clr==0)glColor3f(1,.5,0);
			else if(flag_clr==1)glColor3f(.6,.3,.4);
			else if(flag_clr==2)glColor3f(.4,.6,.3);
			else if(flag_clr==3)glColor3f(0,.5,.6);
	
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
			if(t<100 && u<100)glTranslatef(X[u],Y[t],0);
			else  glTranslatef(x_dec,y_dec,0);
			//else glTranslatef(b_x,b_y,0);
			glRotatef(rtheta,1,1,0);
			glutSolidSphere(80.0,40.0, 120.0);//drawing of sphare
			if(flag_clr==0)glColor3f(.8,.8,.8);
			else if(flag_clr==1)glColor3f(.6,.6,.6);
			else if(flag_clr==2)glColor3f(.6,.8,.56);
			else if(flag_clr==3)glColor3f(.6,.7,0);
			glLineWidth(1);
			glutWireSphere(80,20,10);
			glPopMatrix();
			//glutPostRedisplay();
			glFlush();
}

void msg(char * st)//to display how fine you basket
{
	glColor3f(0.93,0.16,0.96 );
		glRasterPos2i(-500,250);
		for(int i=0;i<strlen(st);i++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,st[i]);
		}

glFlush();
}
void basket()
{
	
	glColor3f(0.858824,0.858824,0.439216);//POLL
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex2f(-970,260);
	glVertex2f(-970,-390);
	glVertex2f(-950,-430);
	glVertex2f(-930,-390);
	glVertex2f(-930,260);
	glVertex2f(-950,260);
	glVertex2f(-950,-350);
	glVertex2f(-950,-430);
	glVertex2f(-950,220);
	glEnd();

	glColor3f(0.137255,0.556863,0.419608);//circle base near poll
	glBegin(GL_POLYGON);
	glVertex2f(-855,-300);
	glVertex2f(-680,-332);
	glVertex2f(-710,-430);
	glVertex2f(-1030,-440);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINE_STRIP);//circle lines near the pole 
	for(int i=0;i<360;i++)
	{
		h=i*(3.142/180);
		x=-700+70*cos(h);
		y=-380+50*sin(h);//changes now
	glVertex2f(x,y);
	}
	glEnd();

	glColor3f(1,1,1);//outline with white color near poll
	glBegin(GL_LINES);
	glVertex2f(-855,-300);
	glVertex2f(-680,-332);
	glVertex2f(-680,-332);
	glVertex2f(-710,-430);
	glVertex2f(-710,-430);
	glVertex2f(-1030,-440);
	glVertex2f(-1030,-440);
	glVertex2f(-855,-300);
	glEnd();

		// this the other side of the basket base
	
	glColor3f(0.137255,0.556863,0.419608);//circle base near poll
	glBegin(GL_POLYGON);
	glVertex2f(1045,-300);
	glVertex2f(845,-332);
	glVertex2f(855,-430);
	glVertex2f(1170,-440);
	glEnd();
	
	glColor3f(1,1,1);
	glBegin(GL_LINE_STRIP);//circle lines near the pole 
	for(int i=0;i<360;i++)
	{
		h=i*(3.142/180);
		x=850+70*cos(h);
		y=-380+50*sin(h);//changes now
	glVertex2f(x,y);
	}
	glEnd();

	glColor3f(1,1,1);//outline with white color near poll
	glBegin(GL_LINES);
	glVertex2f(1045,-300);
	glVertex2f(845,-332);
	glVertex2f(845,-332);
	glVertex2f(855,-430);
	glVertex2f(855,-430);
	glVertex2f(1170,-440);
	glVertex2f(1170,-440);
	glVertex2f(1045,-300);
	glEnd();



	glBegin(GL_POLYGON);//front side of the poll which is attached with basket board
	glColor3f(0,0,1);
	glVertex2f(-930,260);
	glVertex2f(-700,260);
	glVertex2f(-700,220);
	glVertex2f(-950,220);
	glEnd();

	//below code for basket board
	
	glColor3f(0.77,0.77,0.77);
	glBegin(GL_POLYGON);//board where the basket attached
	glVertex3f(-850,450,200);
	glVertex3f(-630,420,-200);//changes 200 to 300
	glVertex3f(-630,220,-400);//changes -80 to -900
	glVertex3f(-850,200,400);
	glEnd();
	
	glColor3f(0.90,0.91,0.98);
	glBegin(GL_POLYGON);//board where the basket attached of side line from each side of the board
	glVertex3f(-840,440,200);
	glVertex3f(-635,410,-200);//changes 200 to 300
	glVertex3f(-635,230,-400);//changes -80 to -900
	glVertex3f(-840,210,400);
	glEnd();
	glColor3f(0,1,0);
	glBegin(GL_POLYGON);//code for hook1
	glVertex3f(-720,280,200);
	glVertex3f(-700,280,-200);//changes 200 to 300
	glVertex3f(-700,250,-400);//changes -80 to -900
	glVertex3f(-720,250,400);
	glEnd();
	
	glColor3f(0,1,0);
	glBegin(GL_LINES);//lines through the hing into board
	glVertex2f(-780,360);
	glVertex2f(-660,340);//changes 200 to 300
	glVertex2f(-660,340);//changes -80 to -900
	glVertex2f(-660,250);
	glVertex2f(-660,250);
	glVertex2f(-780,240);
	glVertex2f(-780,240);
	glVertex2f(-780,360);
	glEnd();
	
	if(flag_goal==1)// to display how fine you have basketed
		msg(str14);
	else if(flag_goal==2)
		msg(str15);
	else if(flag_goal==3)
		msg(str16);
	glColor3f(1,0,0);
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<180;i+=1)//basket upper ring degree angle
	{
		h=i*(3.142/180);
		p=-620+110*cos(h);
		q=230+40*sin(h);
		x=-620+100*cos(h);
		y=230+30*sin(h);
		glVertex2f(p,q);
		glVertex2f(x,y);
	}
	glEnd();
	glLineWidth(1.5);
	glBegin(GL_LINE_STRIP);//1st lines between the upper ring and lower ring from front side
	for(int i=0;i<=180;i+=14)
	{
		h=i*(3.142/180);
		x=-620+110*cos(h);
		y=230+30*sin(h);
		p=-620+90*cos(h);
		q=50+20*sin(h);
		glColor3f(0,0,.41);
		glVertex2f(x,y);
		glColor3f(1,1,1);
		glVertex2f(p,q);

	}
	glEnd();

	glColor3f(0,1,0);
	glBegin(GL_LINES);
	for(int i=0;i<180;i+=1)//lower ring of basket back side
	{
		h=i*(3.142/180);
		p=-620+90*cos(h);
		q=50+20*sin(h);
		x=-620+100*cos(h);
		y=50+30*sin(h);
		glVertex2f(x,y);
		glVertex2f(p,q);
		
	}
	glEnd();
	
		//below code calculate the trajectory
		if(flag_tr==1)
		{
		     if(flag_clr==0)glColor3f(1,.5,0);
			else if(flag_clr==1)glColor3f(.6,.3,.4);
			else if(flag_clr==2)glColor3f(.4,.6,.3);
			else if(flag_clr==3)glColor3f(0,.5,.6);
			glPointSize(2);
			glBegin(GL_POINTS);
			for(int i=0;i<100;i++)
			glVertex2f(X[i],Y[i]);
			glEnd();
		}

	
	if(flag_er==1 || flag_er==2)
	{
		ball1();//function to draw the ball

	}
	
	
	glColor3f(1,0,0);
	glBegin(GL_LINE_STRIP);
	for(int i=180;i<360;i+=1)//basket upper ring degree angle
	{
		h=i*(3.142/180);
		p=-620+110*cos(h);
		q=230+40*sin(h);
		x=-620+100*cos(h);
		y=230+30*sin(h);
		glVertex2f(p,q);
		glVertex2f(x,y);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	for(int i=180;i<=360;i+=18)//2nd lines between the upper ring and lower ring from back side
	{
		h=i*(3.142/180);
		x=-620+110*cos(h);
		y=230+30*sin(h);
		p=-620+90*cos(h);
		q=50+20*sin(h);
		glColor3f(0,0,.61);
		glVertex2f(x,y);
		glColor3f(1,1,1);
		glVertex2f(p,q);
	}
	glEnd();
	
	glColor3f(0,1,0);
	glBegin(GL_LINES);
	for(int i=180;i<360;i+=1)//lower ring of basket
	{
		h=i*(3.142/180);
		p=-620+90*cos(h);
		q=50+20*sin(h);
		x=-620+100*cos(h);
		y=50+30*sin(h);
		glVertex2f(x,y);
		glVertex2f(p,q);
		
	}
	glEnd();
    glColor3f(0,1,0);
	glBegin(GL_POLYGON);//code for hook2
	glVertex3f(-720,260,200);
	glVertex3f(-700,260,200);//changes 200 to 300
	glVertex3f(-690,250,-300);//changes -80 to -900
	glVertex3f(-710,240,380);
	glEnd();

	

	glColor3f(1,.4,.5);
	glRasterPos2i(-830,400);
	int k=4,a=15;//to decrement the value of x and y in x,y direction
	for(int i=0;i<strlen(str);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,str[i]);
		glRasterPos2i(-830+a,400-k);
		k+=3;
		a+=15;
	}
}


void calcu(float Xnn,float Ynn,float theta)
{
	int i;
	tof = 2*velocity*sin(theta)/g;
   del_t = tof/100;//time of flight at each point of x and y irrespective to trajectory
  float temp=0;//variable to calculate time of flight at each point
 for(i=0;i<100;i++)//this will go in timer func
  {
  x_direction = Xnn+velocity*cos(theta)*temp;//x-initial point + initial velocity * cos(theta) *time of flight at each point
  y_direction = Ynn+velocity*sin(theta)*temp - ((g*temp*temp)/2);
  X[i]=x_direction;
  Y[i]=y_direction;
  temp += del_t;
  printf("the value of x[100]=%d and y[100]=%d\n\t",X[i],Y[i]);
 }
 	x_dec=X[99];
	y_dec=Y[99];
	flag_tr=1;
	for(i=0;i<100;i++)
	printf("%f %f\n",X[i],Y[i]);
}
void displayname()
{
	glLineWidth(2);
	glColor3f(1,1,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(-1250,673);
	glVertex2f(-900,673);
	glVertex2f(-900,620);
	glVertex2f(-1250,620);
	glEnd();

	glColor3f(.56,.0,0);
	glRasterPos2i(-1200,635);
	for(int i=0;i<strlen(str1);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str1[i]);
	}
	glColor3f(05,.56,0);
	glRasterPos2i(-1040,635);
	for(int i=0;i<strlen(str2);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str2[i]);
	}

	glPopMatrix();
}
void displayboard()
{
	glColor3f(0,.66,.66);//background color of scoreboard and ball
	glBegin(GL_POLYGON);
	glVertex2f(535,675);
	glVertex2f(1340,675);
	glVertex2f(1340,625);
	glVertex2f(535,625);
	glEnd();

	glColor3f(.0,.0,.66);//score board
	glBegin(GL_POLYGON);
	glVertex2f(810,670);
	glVertex2f(1000,670);
	glVertex2f(1000,630);
	glVertex2f(810,630);
	glEnd();
	

	glColor3f(.66,.66,.66);//remaining ball
	glBegin(GL_POLYGON);
	glVertex2f(550,670);
	glVertex2f(800,670);
	glVertex2f(800,630);
	glVertex2f(550,630);
	glEnd();

	glColor3f(.66,.66,.66);//best score
	glBegin(GL_POLYGON);
	glVertex2f(1010,670);
	glVertex2f(1330,670);
	glVertex2f(1330,630);
	glVertex2f(1010,630);
	glEnd();
	
	glColor3f(1,1,1);
	glRasterPos2i(570,640);
	for(int i=0;i<strlen(str3);i++)//function to write ball
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str3[i]);
	}
		n=noc;
	_itoa_s(n,str5,10);//converting 10 into ascii of it
	glColor3f(1,1,1);
	glRasterPos2i(750,640);
	for(int i=0;i<strlen(str5);i++)//printing value of remainig ballinto the box
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str5[i]);
	}
	glColor3f(1,1,1);
	glRasterPos2i(820,640);
	for(int i=0;i<strlen(str6);i++)//print score
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str6[i]);
	}
	_itoa_s(score,str9,10);
	glColor3f(1,1,0);
	glRasterPos2i(920,640);
	for(int i=0;i<strlen(str9);i++)//print score
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str9[i]);
	}

	glColor3f(1,1,1);
	glRasterPos2i(1020,640);
	for(int i=0;i<strlen(str7);i++)//print best score
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str7[i]);
	}
	if(n==0)
	{
		_itoa_s(score,str9,10);
		glColor3f(1,0,0);
		glRasterPos2i(1160,640);
		for(int i=0;i<strlen(str9);i++)//print score
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,str9[i]);
		}
	}


}
void dispgameover()
{
	glBegin(GL_POLYGON);
	glColor3f(0.62352,0.372549,0.623529);
	glVertex2f(-500,-500);
	glColor3f(0.62352,0.372549,0.623529);
	glVertex2f(600,-500);
	glColor3f(0.42352,0.272549,0.423529);
	glVertex2f(600,300);
	glColor3f(0.42352,0.272549,0.423529);
	glVertex2f(-500,300);
	glEnd();
	glColor3f(1,1,1);
	glLineWidth(5);
	glBegin(GL_LINE_STRIP);
	for(int i=0;i<360;i++)
	{
		h=i*(3.142/180);
		x=50+300*cos(h);	
		y=-100+300*sin(h);
		glVertex2f(x,y);
	}
	glEnd();
	glPushMatrix();
	glTranslatef(-180,30,0);
	glutSolidTorus(10,15,4,3);
	glPopMatrix();
	glColor3f(.6,.9,1);
	glRasterPos2i(-50,30);
	for(int i=0;i<strlen(str10);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str10[i]);
	}
	glColor3f(.9,.2,0);//sqaure for displaying score
	glBegin(GL_LINE_LOOP);
	glVertex2f(-150,5);
	glVertex2f(300,5);
	glVertex2f(300,-100);
	glVertex2f(-150,-100);
	glEnd();
	
	glColor3f(1,1,1);
	glRasterPos2i(40,-55);
	for(int i=0;i<strlen(str9);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str9[i]);
	}
	
	glColor3f(1,1,1);
	glBegin(GL_POLYGON);
	glVertex2f(-120,-150);
	glVertex2f(260,-150);
	glVertex2f(260,-280);
	glVertex2f(-120,-280);
	glEnd();
	
	glColor3f(.8,.5,.9);//for restert
	glBegin(GL_LINE_LOOP);
	glVertex2f(-120,-150);
	glVertex2f(260,-150);
	glVertex2f(260,-280);
	glVertex2f(-120,-280);
	glEnd();

	glColor3f(.8,.5,.9);
	glRasterPos2i(-20,-225);
	for(int i=0;i<strlen(str11);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str11[i]);
	}
	
	glColor3f(.4,.9,.3);//for menu
	glBegin(GL_LINE_LOOP);
	glVertex2f(-480,-300);
	glVertex2f(-220,-300);
	glVertex2f(-220,-400);
	glVertex2f(-480,-400);
	glEnd();

	glColor3f(.4,.9,.3);
	glRasterPos2i(-400,-350);
	for(int i=0;i<strlen(str12);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str12[i]);
	}
	
	glColor3f(.4,.9,.3);//for quit
	glBegin(GL_LINE_LOOP);
	glVertex2f(350,-300);
	glVertex2f(580,-300);
	glVertex2f(580,-400);
	glVertex2f(350,-400);
	glEnd();

	glColor3f(.4,.9,.3);
	glRasterPos2i(430,-350);
	for(int i=0;i<strlen(str13);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str13[i]);
	}
}

void mytimer1(int v)
{
		y_dec-=24;
		printf("y new vai %f ,%f",y_dec,x_dec);
		if(y_dec<=-400)
		{
				flag_goal=0;
				flag_er=0;
				flag_er=2;
				u=0;t=0,rtheta=75;
				flag_tr=0;
				Sleep(200);
				if(noc<1)flag_ovr=1;
		}
		if(y_dec>=-400)
		glutTimerFunc(50,mytimer1,20);
		glutPostRedisplay();
}
void mytimer(int v)
{
	u+=2;
	t+=2;
	if(u==100 && t==100)
	{
		if(X[99]>-660 && X[99]<-560)
		{
			flag_goal=1;
			score+=200;
		}
		else if(X[99]>-560 && X[99]<-510  || X[99]<-660 && X[99]>-730)
		{
			flag_goal=2;
			score+=100;
		}
		else if(X[99]>-510 || X[99]<-730)
		{
			flag_goal=3;
			score+=0;
		}
		
		glutTimerFunc(50,mytimer1,20);
	}
	rtheta+=5;
	if(rtheta>720)rtheta=360;
	if(u<=100)
	glutTimerFunc(50,mytimer,20);
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
	clouds(-400, 585, 175, 45);
	glBegin(GL_POLYGON);
	clouds(-400, 550, 200, 45);
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
	glScalef(.2, .2, .2);
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
	glScalef(.2, .2, .2);
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
	glColor3f(.7,.7,.7);
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
	glVertex2f(500,300);
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
	glColor3f(.6,.6,.5);
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
	glClearColor(0.22,0.69,0.87,0.1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	cloud();//draw sky
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(180,0,1,0);
	helicopter();//fn to draw helicopter
	glPopMatrix();
	basketcourt();
	basket();//function to design basket platform
	displayname();//function to display player name
	displayboard();//function to display score remaining ball e.t.c
	if(flag_ovr==1)dispgameover();
	glutSwapBuffers();
	glFlush();
}

void rules()
{
	glClearColor(.3,.35,.3,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	glColor3f(.6,0,0);
	glRasterPos2i(-300,600);
	for(int i=0;i<strlen(st1);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,st1[i]);
	}
	glColor3f(0,0,.7);
	glRasterPos2i(-320,580);
	for(int i=0;i<strlen(st5);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,st5[i]);
	}


	glColor3f(1,0,0);
	glRasterPos2i(-650,200);
	for(int i=0;i<strlen(st6);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,st6[i]);
	}
	glColor3f(1,1,1);
	glRasterPos2i(-650,100);
	for(int i=0;i<strlen(st7);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,st7[i]);
	}
	
	glColor3f(1,1,1);
	glRasterPos2i(-650,0);
	for(int i=0;i<strlen(st8);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,st8[i]);
	}
	glColor3f(1,1,1);
	glRasterPos2i(-650,-100);
	for(int i=0;i<strlen(st9);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,st9[i]);
	}

	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(500,-375);
	glVertex2f(900,-375);
	glVertex2f(900,-450);
	glVertex2f(500,-450);
	glEnd();
	
	glColor3f(1,1,0);
	glRasterPos2i(550,-425);
	for(int i=0;i<strlen(st3);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,st3[i]);
	}
}

void display()
{
	glColor3f(.6,0,0);
	glRasterPos2i(-300,600);
	for(int i=0;i<strlen(st1);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,st1[i]);
	}
	glColor3f(0,0,.7);
	glRasterPos2i(-320,580);
	for(int i=0;i<strlen(st5);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,st5[i]);
	}

	glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(-200,75);
	glVertex2f(200,75);
	glVertex2f(200,00);
	glVertex2f(-200,00);
	glEnd();
	
	glColor3f(1,1,0);
	glRasterPos2i(-150,25);
	for(int i=0;i<strlen(st3);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,st3[i]);
	}

	glColor3f(.3,.35,.3);
	glBegin(GL_POLYGON);
	glVertex2f(-400,-75);
	glVertex2f(400,-75);
	glVertex2f(400,-150);
	glVertex2f(-400,-150);
	glEnd();
	
	glColor3f(1,1,1);
	glRasterPos2i(-100,-125);
	for(int i=0;i<strlen(st4);i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15,st4[i]);
	}
	if(flag_rule==1)rules();
	glFlush();
}
void disp1()
{
	glClearColor(0,.8,.6,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	display();
	latter();
	glutSwapBuffers();
	glFlush();
}



void mykey(unsigned char key,int x,int y)
{
	if(key==27)exit(0);
}
void move(int x,int y)
{
	Ynn=495-y;
	Xnn=x-675;
	xdist=Xnn-675;//distance of base from left partof the windows to the now present postion of x value
	ydist=Ynn-Yn;//this is the distance between mouse click yn and move ynn
	rxy=(ydist/xdist);//ratio of perpendicular/base
	angle=atan(rxy);//{tan(Q)=y/x; so atan(y/x)=angle}
	angle=angle*(300/3.142);//changing in radian to degree
	printf("xdist=%f\tydist=%f\tangle=%f\n",xdist,ydist,angle);
	printf("xnn=%f,ynn=%f",Ynn,Xnn,Yn,Xn);
	if(flag_er==1|| flag_er==2)
	{
		calcu(Xn,Yn,angle);
	}
	glFlush();
}
void restart()
{
	glutDisplayFunc(disp);
	printf("rdgdG");
}
void mymouse(int btn,int state,int x,int y)
{
	Yn=495-y;
	Xn=x-675;
	
	yp=10-y;
	xp=x-1000;

	//printf("y_dec[100]=%f",y_dec);
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
	{
		printf("xp=%d\typ=%d\n",xp,yp);
		
				
		if(Xn>-100 && Xn<100 && Yn>0 && Yn<500)
		{
			if(flag_er==1|| flag_er==2 && (noc>=0) && (noc!=0))
			glutTimerFunc(90,mytimer,20);
			noc-=1;//decreamenting number of ball every click
		}
	}
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		if(xp>-450 && xp<-215 && yp>-360 && yp<-320)//fuction call  to display basketball game
 			glutDisplayFunc(disp);
	   
		if(Xn>275 && Xn<500 && Yn>-130 && Yn<-85)//to restart the game
		{
			noc+=3;
			restart();//check out this why it is not working;
		}

		if(xp>-540 && xp<-100 && yp>-440 && yp<-400)//function to display instruction formate
			flag_rule=1;	
		
		if(Xn>-245 && Xn<-105 && Yn>-70 && Yn<-20 && (noc<=0))//function to take into home
			glutDisplayFunc(disp1);
			
	     if(Xn>-145 && Xn<-50 && Yn>0 && Yn<55 && (noc<=0))
			 glutDisplayFunc(disp);
		
		if(Xn>190 && Xn<315 && Yn>-70 && Yn<-20)//function to exit from game mode
			exit(0);
	}
	glutPostRedisplay();
}
void menu(int d)
{
	switch(d)
	{
	case 1: flag_clr=1;
		break;
	case 2: flag_clr=2;
		break;
	case 3: flag_clr=3;
		break;
	case 4:flag_clr=0;
	}
	glutPostRedisplay();
}
void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-675,675, -675, 675,-675,675);
	glMatrixMode(GL_MODELVIEW);
}
void myreshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w>h)
		glOrtho(-675* (GLfloat)w / (GLfloat)h, 675 * (GLfloat)w / (GLfloat)h, -675, 675,-675,675);
	else
		glOrtho(-675, 675, -675* (GLfloat)h / (GLfloat)w, 675 * (GLfloat)h / (GLfloat)w,-675,675);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}
int main()
{

	//PlaySound("C:\sound\heli.mp3", NULL, SND_ASYNC);
	printf("enter player name\t");
	scanf("%s",str2);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glutInitWindowSize(1350, 900);
	glutCreateWindow("BASKET-BALL");
	myinit();
	glutReshapeFunc(myreshape);
	glutDisplayFunc(disp1);
	glutTimerFunc(80, cloudtimer, 20);
	glutTimerFunc(20,helitimer,20);
	glutMouseFunc(mymouse);
	glutMotionFunc(move);
	glutKeyboardFunc(mykey);
	glutCreateMenu(menu);
	glutAddMenuEntry("Ball_type-1",1);
	glutAddMenuEntry("Ball_type-2",2);
	glutAddMenuEntry("Ball_type-3",3);
	glutAddMenuEntry("Original_ball",4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
}
