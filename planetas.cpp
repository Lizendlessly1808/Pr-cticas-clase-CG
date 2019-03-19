
/*

	Semestre 2019-2

	Ramírez Verduzco Lizet

	Práctica #6

	Visual Basic 2017

	Manual de uso:
	El programa muestra la rotación y traslación de los planetas 
	Las teclas configuradas para poder mover la cámara son:
	w:Acerca la cámara
	s: Aleja la cámara
	d:Movimiento a la derecha
	a: Movimiento a la izquierda
*/

#include "Main.h"





// Variables used to calculate frames per second: (Windows)

DWORD dwFrames = 0;

DWORD dwCurrentTime = 0;

DWORD dwLastUpdateTime = 0;

DWORD dwElapsedTime = 0;





//Variables used to create movement
int sol = 0;
int mercurio = 45;
int venus = 90;

int tierra = 0;
int luna_tierra = 0;

int marte = 0;
int luna_marte = 0;

int jupiter = 0;
int luna_jupiter = 0;
int luna_jupiter2 = 0;

int saturno = 0;
int anillo_saturno = 0;

int urano = 0;
int luna_urano = 0;

int neptuno = 0;
int luna_neptuno = 0;
int luna_neptuno2 = 0;

int orbita_mercurio = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position


GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };



GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };



GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };



void InitGL(GLvoid)     // Inicializamos parametros

{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}



void display(void)   // Creamos la funcion donde se dibuja

{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glPushMatrix(); //Sistema solar

		glPushMatrix();//Encapsula solo al sol
			glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
			glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
			glutSolidSphere(4, 12, 12);  //Draw Sun (radio,H numero de lineas horizontales,V num de lineas verticales);
		glPopMatrix();

		glPushMatrix();//orbita mercurio
			glColor3f(1.0, 0.0, 0.0);
			glRotatef(90, 1,0 , 0);//rotacion
			glutWireTorus(0.03, 6.15, 12, 12);
		glPopMatrix();


		glPushMatrix(); //Mercurio
			glRotatef(mercurio, 0, 1, 0);//traslacion
			glTranslatef(6, 0, 0);
			glColor3f(0.8, 0.5, 0);
			glRotatef(mercurio, 0, 1, 0);//rotacion
			glutSolidSphere(0.5, 12, 12);
		glPopMatrix();


		glPushMatrix();//orbita venus
			glColor3f(1.0, 0.0, 0.0);
			glRotatef(venus, 0.1,1, 0);//rotacion
			glutSolidTorus(0.03, 9.3, 12, 12);
		glPopMatrix();

		glPushMatrix(); //Venus
			glRotatef(90, 1, 1, 0);//traslacion
			glTranslatef(9, 0, 0);
			glColor3f(0.9, 0.8, 0.4);
			glRotatef(venus, 0, 1, 0);//rotacion
			glutSolidSphere(0.8, 12, 12);
		glPopMatrix();


		glPushMatrix();
		glColor3f(1.0, 0.0, 0.0);
		glRotatef(90, 0, 1, 0);//rotacion
		glutSolidTorus(0.03, 12.45, 12, 12);
		glPopMatrix();

		glPushMatrix(); //Tierra
			//glRotatef(tierra, 0, 1, 0);//traslacion
			glTranslatef(12, 0, 0);
			glColor3f(0.3, 0.8, 1);
			glRotatef(tierra, 0, 1, 0);//rotacion
			glutSolidSphere(0.8, 12, 12);

			glPushMatrix();
				glRotatef(luna_tierra, 0, 1, 0);//traslacion
				glTranslatef(0.8, 0, 0);
				glColor3f(0.6, 0.6, 0.6);
				glRotatef(luna_tierra, 0, 1, 0);//rotacion
				glutSolidSphere(0.2, 12, 12);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Marte

			glColor3f(1.0, 0.0, 0.0);
			glRotatef(orbita_mercurio, 1, 0, 0);//rotacion
			glutSolidTorus(0.03,16.15, 12, 12);

			//glRotatef(marte, 0, 1, 0);//traslacion
			glTranslatef(16, 0, 0);
			glColor3f(.8, 0.4, 0);
			glRotatef(marte, 0, 1, 0);//rotacion
			glutSolidSphere(0.6, 12, 12);

			glPushMatrix();
				glRotatef(luna_marte, 0, 1, 0);//traslacion
				glTranslatef(0.6, 0, 0);
				glColor3f(0.6, 0.6, 0.6);
				glRotatef(luna_marte, 0, 1, 0);//rotacion
				glutSolidSphere(0.2, 12, 12);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Jupiter

			glColor3f(1.0, 0.0, 0.0);
			glRotatef(orbita_mercurio, 1, 0, 0);//rotacion
			glutSolidTorus(0.03,24.3, 12, 12);

			//glRotatef(jupiter, 0, 1, 0);//traslacion
			glTranslatef(23, 0, 0);
			glColor3f(1, 0.8, 0.5);
			glRotatef(jupiter, 0, 1, 0);//rotacion
			glutSolidSphere(3, 12, 12);

			glPushMatrix();
				glRotatef(luna_jupiter, 0, 1, 0);//traslacion
				glTranslatef(3, 0, 0);
				glColor3f(0.6, 0.6, 0.6);
				glRotatef(luna_jupiter, 0, 1, 0);//rotacion
				glutSolidSphere(0.5, 12, 12);
			glPopMatrix();

			glPushMatrix();
				glRotatef(luna_jupiter2, 0, 1, 0);//traslacion
				glTranslatef(3.5, 1.5, 0);
				glColor3f(0.6, 0.6, 0.6);
				glRotatef(luna_jupiter2, 0, 1, 0);//rotacion
				glutSolidSphere(0.6, 12, 12);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Saturno

			glColor3f(1.0, 0.0, 0.0);
			glRotatef(orbita_mercurio, 1, 0, 0);//rotacion
			glutSolidTorus(0.03, 35.45, 12, 12);

			//glRotatef(venus, 0, 1, 0);//traslacion
			glTranslatef(35, 0, 0);
			glColor3f(0.6, 0.5, 0.1);
			glRotatef(saturno, 0, 1, 0);//rotacion
			glutSolidSphere(2.5, 12, 12);

			glPushMatrix();
				glColor3f(0.6, 0.6, 0.6);
				glRotatef(anillo_saturno, 1, 0, 0);//rotacion
				glutSolidTorus(0.5, 4, 12, 12);
			glPopMatrix();


			glPushMatrix();
				glColor3f(0.9, 0.9, 0.6);
				glRotatef(anillo_saturno, 1, 0, 0);//rotacion
				glutSolidTorus(0.5, 5, 12, 12);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Urano

			glColor3f(1.0, 0.0, 0.0);
			glRotatef(orbita_mercurio, 1, 0, 0);//rotacion
			glutSolidTorus(0.03, 46, 12, 12);

			//glRotatef(urano, 0, 1, 0);//traslacion
			glTranslatef(45, 0, 0);
			glColor3f(0.5, 0.6, 0.9);
			glRotatef(urano, 0, 1, 0);//rotacion
			glutSolidSphere(2, 12, 12);

			glPushMatrix();
				glRotatef(luna_urano, 0, 1, 0);//traslacion
				glTranslatef(2.5, 0, 0);
				glColor3f(0.6, 0.6, 0.6);
				glRotatef(luna_urano, 1, 0, 0);//rotacion
				glutSolidSphere(0.4, 12, 12);
			glPopMatrix();
		glPopMatrix();

		glPushMatrix(); //Neptuno

			glColor3f(1.0, 0.0, 0.0);
			glRotatef(orbita_mercurio, 1, 0, 0);//rotacion
			glutSolidTorus(0.03, 52.3, 12, 12);

			//glRotatef(urano, 0, 1, 0);//traslacion
			glTranslatef(52, 0, 0);
			glColor3f(0.5, 0.5, 0.8);
			glRotatef(urano, 0, 1, 0);//rotacion
			glutSolidSphere(1.5, 12, 12);

			glPushMatrix();
				glRotatef(luna_neptuno, 0, 1, 0);//traslacion
				glTranslatef(1.5, 0, 0);
				glColor3f(0.6, 0.6, 0.6);
				glRotatef(luna_neptuno, 1, 0, 0);//rotacion
				glutSolidSphere(0.4, 12, 12);
			glPopMatrix();

			glPushMatrix();
				glColor3f(0.6, 0.6, 0.6);
				glRotatef(luna_neptuno2, 1, 0, 0);//rotacion
				glutSolidSphere(0.4, 12, 12);
			glPopMatrix();
		glPopMatrix();

	glPopMatrix();

	glutSwapBuffers();



}



void animacion() //para que rote solito

{

	// Calculate the number of frames per one second:

	//dwFrames++;

	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()

	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;



	if (dwElapsedTime >= 30)

	{

		sol = (sol - 5) % 360; //velocidad de 5 y modulo de 360

		mercurio = (mercurio + 10) % 360; //velocidad de 5 y modulo de 360

		venus = (mercurio + 7) % 360;

		tierra = (tierra + 7) % 360;



		marte = (marte + 7) % 360;

		jupiter = (jupiter + 7) % 360;

		saturno = (saturno + 7) % 360;

		urano = (urano + 7) % 360;

		neptuno = (neptuno + 7) % 360;





		dwLastUpdateTime = dwCurrentTime;

	}



	glutPostRedisplay();

}



void reshape(int width, int height)   // Creamos funcion Reshape

{

	if (height == 0)										// Prevenir division entre cero

	{

		height = 1;

	}



	glViewport(0, 0, width, height);



	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix

	glLoadIdentity();



	// Tipo de Vista



	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);



	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix

	//glLoadIdentity();

}



void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function

{

	switch (key) {

	case 'w':   //Movimientos de camara

	case 'W':

		camaraZ += 0.5f;

		break;

	case 's':

	case 'S':

		camaraZ -= 0.5f;

		break;

	case 'a':

	case 'A':

		camaraX -= 0.5f;

		break;

	case 'd':

	case 'D':

		camaraX += 0.5f;

		break;



	case 'i':		//Movimientos de Luz

	case 'I':



		break;

	case 'k':

	case 'K':



		break;



	case 'l':   //Activamos/desactivamos luz

	case 'L':

		break;

	case 27:        // Cuando Esc es presionado...

		exit(0);   // Salimos del programa

		break;

	default:        // Cualquier otra

		break;

	}

	glutPostRedisplay();

}



void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)

{

	switch (a_keys) {

	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...



		break;

	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...



		break;

	case GLUT_KEY_LEFT:



		break;

	case GLUT_KEY_RIGHT:



		break;

	default:

		break;

	}

	glutPostRedisplay();

}





int main(int argc, char** argv)   // Main Function

{

	glutInit(&argc, argv); // Inicializamos OpenGL

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )

	glutInitWindowSize(500, 500);	// Tamaño de la Ventana

	glutInitWindowPosition(20, 60);	//Posicion de la Ventana

	glutCreateWindow("Practica 6"); // Nombre de la Ventana

	InitGL();						// Parametros iniciales de la aplicacion

	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo

	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano

	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado

	glutSpecialFunc(arrow_keys);	//Otras

	glutIdleFunc(animacion);

	glutMainLoop();          // 



	return 0;

}