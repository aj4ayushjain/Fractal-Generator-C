#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<SOIL/SOIL.h>//library Simple OpenGL Image Loader to load the images 
#include<unistd.h>
#define PI 3.1415

GLuint tex_2d,tex_2d1,tex_2d2;

typedef struct NODE{

	
	GLfloat final_position[2];
	struct Node* leftbranch;
	struct Node* rightbranch;

}Node;

<<<<<<< Updated upstream
Node* Q[50];
=======
//Node Q[50];
>>>>>>> Stashed changes
int front=0;
int rear=0;

	



//center of circle for drawing simple fractal with radius
int c_x=500,c_y=500,c_r=400;


int screen=-1,i=0,j=645,k=1.0,l=1.0,add=15,filled_radius=50.0f;

GLfloat pt1[]={500.0f,10.0f};
GLfloat pt2[]={500.0f,110.0f};
int theta=53;
int tree_branch_length=47;
int no_of_iterations=4;	
int no_of_iterations_l=4;
int no_of_iterations_r=4;
int aliter=1;
/*
void push(Node *ptr){
	
	Q[front]=ptr;
	
	front++;
}
Node* pop(){
	rear++;
	return Q[rear-1];
	
}
*/
void drawStrokeText(char *string,int x,int y,int z){


	/* Stroke fonts are basically 3D fonts and OpenGL treats them like other object only so we can translate,rotate, scale 
		- for drawing the character it uses the glLine 
	*/
	glPushMatrix();

	glTranslatef(x,y+8,z);

	glScalef(0.33f,0.33f,z);
	glEnable(GL_LINE_SMOOTH);

	glLineWidth(5);

	glutStrokeString(GLUT_STROKE_ROMAN,(unsigned char*)string);
	glDisable(GL_LINE_SMOOTH);
	glLineWidth(1);

	glPopMatrix();
	
}
void drawBitmapText1(char *string,float x,float y){

	char *c;

	glRasterPos2f(x,y);

	for(c=string;*c!='\0';c++){
		
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
	}


}
void idle(){
	
	if(i<130){	i=i+2;
			j-=1;	
			k-=1/65;
			l-=1/65; 
	glutPostRedisplay();
	}


}
void idle2(){
		
	add=(add+1)%15;

	glutPostRedisplay();

}
void title2(){

	glEnable(GL_TEXTURE_2D);
	
	glColor4f(1.0f,1.0f,1.0f,1.0f);

	tex_2d2=SOIL_load_OGL_texture
		(
			"second.jpeg",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS|SOIL_FLAG_COMPRESS_TO_DXT
		);
	if(0==tex_2d){
	
		printf("Error loading the image : %s 	\n",SOIL_last_result());
	}
	glBindTexture(GL_TEXTURE_2D,tex_2d2);
	
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

	glBegin(GL_POLYGON);
		glTexCoord2f(1.0,1.0);
		glVertex2f(1000,0);
		glTexCoord2f(0.0,1.0);
		glVertex2f(0,0);
		glTexCoord2f(0.0,0.0);
		glVertex2f(0,650);
		glTexCoord2f(1.0,0.0);
		glVertex2f(1000,650);

	glEnd();
	glDisable(GL_TEXTURE_2D);
}
void keys(unsigned char key,int x,int y){

	if(key=='n')	screen++;
	
		//if(key=='l')	

	//mydisplay();
	glutPostRedisplay();	

}
void title(){

	glEnable(GL_TEXTURE_2D);
	
	glColor4f(1.0f,1.0f,1.0f,1.0f);

	tex_2d2=SOIL_load_OGL_texture
		(
			"front.jpeg",
			SOIL_LOAD_AUTO,
			SOIL_CREATE_NEW_ID,
			SOIL_FLAG_MIPMAPS|SOIL_FLAG_COMPRESS_TO_DXT
		);
	if(0==tex_2d){
	
		printf("Error loading the image : %s 	\n",SOIL_last_result());
	}
	glBindTexture(GL_TEXTURE_2D,tex_2d2);
	
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

	glBegin(GL_POLYGON);
		glTexCoord2f(1.0,1.0);
		glVertex2f(1000,0);
		glTexCoord2f(0.0,1.0);
		glVertex2f(0,0);
		glTexCoord2f(0.0,0.0);
		glVertex2f(0,650);
		glTexCoord2f(1.0,0.0);
		glVertex2f(1000,650);

	glEnd();
	glDisable(GL_TEXTURE_2D);

} 
void mouse(int button,int state,int x,int y){

	if((pow(500-x,2)+pow(325-y,2) < pow(filled_radius,2)) && button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		screen=0;


}
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius){
	int i;
	int triangleAmount = 200; //# of triangles used to draw circle
	
	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * PI;
	
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount;i++) { 
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)), 
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void startscreen(){


	//-glPushMatrix();

	//set the screen to lightish blue color

	glClearColor(0.0f,0.43f,.75f,1.0f);
	
	//glPopMatrix();
	
	glColor3f(1.0,0.0,0.0);
	
	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	//filled circle

	drawFilledCircle(500.0f,325.0f,filled_radius+add);
//	sleep(0.001);
	//glutMouseFunc(mouse);	
	glutIdleFunc(idle2);
}
void firstscreen(){
	//glPushMatrix();
	title();
	//glPopMatrix();

	glColor3f(1.0,0.5,0.0);
	
	drawStrokeText("CG Project 201",i,580,0);
	drawStrokeText("9",465,j,0);
	
	glColor3f(k,l,0.0);

	drawBitmapText1("Made by:-",130,400);
	

	drawBitmapText1("Ayush Jain",130,350);
	drawBitmapText1("Harsh Chaudhary",130,320);


	drawBitmapText1("1PE16CS037",310,350);
	drawBitmapText1("1PE16CS061",310,320);
	
	glColor3f(0.0,1.0,0.0);

	drawBitmapText1("Press left mouse button to move to next screen",580,20);
		glutIdleFunc(idle);
}
void secondscreen(){
	
//	glClear();
	glPushMatrix();
	title2();
	glPopMatrix();

	glColor3f(1.0,0.5,0.0);

	drawStrokeText("Fractal Generation",80,580,0);

	glColor3f(1.0,0.3,0.0);
	
//	glutKeyboardFunc(keys);

//	glutAddMenuEntry("Next screen",2);

}

void DrawCircle(float cx, float cy, float r, int num_segments) 
{ 
	//we have to set a limit till we will divide the circle and draw or recurse	

	
	float theta = 2 * 3.1415926 / num_segments; 
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = r;//we start at angle = 0 
	float y = 0; 
    
	glBegin(GL_LINE_LOOP); 
	for(int ii = 0; ii < num_segments; ii++) 
	{ 
		glVertex2f(x + cx, y + cy);//output vertex 
        
		//apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	} 
	/*The loop which gives the recursive nature to the circles 
		Circle to the top ,bottom,left and right of the circle in half size
	*/
	if(r>20){
	   //r*=0.5;
	   DrawCircle(cx+r,cy,r/2,num_segments);
	   DrawCircle(cx-r,cy,r/2,num_segments);
	   DrawCircle(cx, cy + r, r/2,num_segments);
	   DrawCircle(cx, cy - r, r/2,num_segments);
	}
	
	glEnd(); 
} 
void thirdscreen(){
	//glPushMatrix();
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500,1500,-500,1500,-2000,1500);	

	glColor3f(1.0,0.0,1.0);
	DrawCircle(c_x,c_y,c_r,500);

	//glPopMatrix();
}
void draw(GLfloat *ptr2,GLfloat *ptrnew){

	glBegin(GL_LINES);
    		glVertex2fv(ptr2);
    		glVertex2fv(ptrnew);
	glEnd();


}
void drawBranch(GLfloat *initl,GLfloat *ptrec2,int r){

/*
	glBegin(GL_LINES);
    		glVertex2fv(ptrec1);
    		glVertex2fv(ptrec2);
	glEnd();
*/	
	
	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//glPushMatrix();
	//glRotatef(theta,ptrec2[0],ptrec2[1],1.0);

       if(r==0){
           return;    
        }
        glBegin(GL_LINES);
    		glVertex2fv(initl);
    		glVertex2fv(ptrec2);
	glEnd();

	//Right branch generation
	//GLfloat ptnewpt1[]={ptrec2[0]+sin(theta*PI/180)*tree_branch_length,ptrec2[1]+cos(theta*PI/180)*tree_branch_length};
	//draw(ptrec2,ptnewpt1);

	//GLfloat ptnewpt2[]={ptrec2[0]-sin(theta*PI/180)*tree_branch_length,ptrec2[1]+cos(theta*PI/180)*tree_branch_length};
	//draw(ptrec2,ptnewpt2);
	
	//theta+=7;

	//if(no_of_iterations_r>0){

		//no_of_iterations_r--;
                initl[0] = ptrec2[0];initl[1]=ptrec2[1];
                ptrec2[0] = ptrec2[0]+sin(theta*PI/180)*tree_branch_length; ptrec2[1]=ptrec2[1]+cos(theta*PI/180)*tree_branch_length;
		drawBranch(initl,ptrec2,r--);
                initl[0] = ptrec2[0];initl[1]=ptrec2[1];
                ptrec2[0] = ptrec2[0]-sin(theta*PI/180)*tree_branch_length;ptrec2[1]=ptrec2[1]+cos(theta*PI/180)*tree_branch_length;
                drawBranch(initl,ptrec2,r--);
		//drawBranch(ptnewpt2);
	//}

//Left branch generation
	
/*	
	theta+=7;

if(no_of_iterations_l>0){

		no_of_iterations_l--;
		drawBranch(ptnewpt2);
		//aliter++;

}
*/
}

<<<<<<< Updated upstream
=======
}
/*
>>>>>>> Stashed changes
Node* createNode(GLfloat *ptr){
	
	Node *n=malloc(sizeof(Node));
	
	n->final_position[0]=ptr[0];
	n->final_position[1]=ptr[1];
	
	return n;
	
}
/*
Node* drawBranch3(GLfloat *ptrfirst){
	
	Node *treeroot;

	treeroot=(Node *)malloc(sizeof(Node));
	
	treeroot->initial_position[0]=ptrfirst[0];
	treeroot->initial_positon[1]=ptrfirst[1];

	if(no_of_iterations>0){
		
		no_of_iterations--;			
		GLfloat ptnewpt1[]={ptrfirst[0]+sin(theta*PI/180)*tree_branch_length,ptrfirst[1]+cos(theta*PI/180)*tree_branch_length};
		rightbranch=createNode(ptnewpt1);		
		
		GLfloat ptnewpt2[]={ptrfirst[0]-sin(theta*PI/180)*tree_branch_length,ptrfirst[1]+cos(theta*PI180)*tree_branch_length};		
		leftbranch=drawBranch3(ptnewpt2);
		
		
		
		
	}
	else{

		leftBranch=null;
		rightBranch=null;
		return treeroot;
	}
}
*/
<<<<<<< Updated upstream
void drawBranch4(GLfloat *ptrf){
	Node* rightb;
	Node* leftb;
	GLfloat ptnewpt1[2];
	GLfloat ptnewpt2[2];
	int i=0,j=0;
	Node *treeroot=malloc(sizeof(Node));
	
	treeroot->final_position[0]=ptrf[0];
	treeroot->final_position[1]=ptrf[1];
	push(treeroot);
	for(i=0;i<no_of_iterations;i++){
			
		for(j=pow(2,i);j>0;j++){
						
			ptnewpt1[0]=Q[front]ptrf[0]+sin(theta*PI/180)*tree_branch_length;
			ptnewpt1[1]=ptrf[1]+cos(theta*PI/180)*tree_branch_length;

			rightb=createNode(ptnewpt1);
			push(rightb);
		
			ptnewpt2[0]=ptrf[0]-sin(theta*PI/180)*tree_branch_length;
			ptnewpt2[1]=ptrf[1]+cos(theta*PI/180)*tree_branch_length;
			
			leftb=createNode(ptnewpt2);
			push(leftb);
			treeroot=pop();
			treeroot->leftbranch=leftb;
			treeroot->rightbranch=rightb;
		}
	}



}

=======
>>>>>>> Stashed changes
void fourthscreen(){

	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.0,0.0);
	glLineWidth(3.0);
	/*
	GLfloat origin[]={500,10};
	float length=100;
	float rotate=0;

	drawBranch(origin,length,rotate);
	*/
	/*glBegin(GL_LINES);
    		glVertex2fv(pt1);
	    	glVertex2fv(pt2);
	glEnd();
<<<<<<< Updated upstream
	
	drawBranch4(pt2);
	//drawBranch(pt2);
=======
	*/
      
	//drawBranch3(pt2);
	drawBranch(pt1,pt2,9);
>>>>>>> Stashed changes

	
	glLineWidth(1.0);
}

void mydisplay(){

	/* This is ortho position setting as to give the images a correct fullscreen covering display which has to be altered later on for fractals
		-Inside the soil api as well we have to adjust accordingly to ortho view.	
	*/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,1000,10.0,650,-2000,1500);

	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,0.0);

	if(screen==-1)
		startscreen();
	if(screen==0)
		firstscreen();
	if(screen==1)
		secondscreen();
	if(screen==2)
		thirdscreen();
	//glutPostRedisplay();
	if(screen==3)
		fourthscreen();
	//glutSwapBuffers();
	glFlush();
}
void menu(int id){
	//glClear(GL_COLOR_BUFFER_BIT);
	switch(id){
		case 0:screen=0;
		       break;
		case 1:screen=1;
			break;
		default:exit(0);

		
	}
	glutKeyboardFunc(keys);
	
	glutPostRedisplay();

}
void reshape(int w, int h){
        
    glViewport(0, 0, w, h);
   
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	
    if(w<=h)
    	glFrustum(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
    else
	glFrustum(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
   
     glMatrixMode(GL_MODELVIEW);
    

}

int  main(int argc,char **argv){

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);

	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	
	glEnable(GL_DEPTH_TEST);
	glutCreateWindow("CG Project");


	glutCreateMenu(menu);
	glutAddMenuEntry("Made by:-",0);
	glutAddMenuEntry("Next screen",1);
	glutAttachMenu(GLUT_RIGHT_BUTTON);	
	glutMouseFunc(mouse);
	glutKeyboardFunc(keys);
	//myinit();
	startscreen();
	glutReshapeFunc(reshape);
	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;
}

