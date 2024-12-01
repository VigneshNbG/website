/*#include<stdio.h>
int main(){
int i = 10;
int *j;
j = &i;
printf("%u\n",i);
printf("%u\n",j);
printf("%u\n",&i);
printf("%u\n",&j);
printf("%u\n",i);
printf("%u\n",*j);

int **z = &j;
printf("Double pointers\n");
printf("%u\n",z);
printf("%u\n",j);
printf("%u\n",*j);
printf("%u\n",**z);

printf("Error!\n");
int *p=23;
int **q = &p;
printf("%u\n",p);
printf("%u\n",&q);
printf("%u\n",*p);
printf("%u\n",**q);
    return 0;
}*/

//swapgin f
/*
#include<stdio.h>

int swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;

}
int main(){
    int x=10,y=20;
    printf("Before swaping a=%d and b=%d\n",x,y);
    swap(&x,&y);
    int temp;
    temp = x;
    x = y;
    y = temp;
    printf("After swaping a=%d and b=%d\n",x,y);
    
    return 0;
}*/

/*#include<stdio.h>
#include<string.h>

int main(){
    char s[10];
    // scanf("%s",&s);
    gets(s);
    printf("%s\n",s);

    printf("%d\n",strlen(s));

    int a[2][5];
 for(int i=0; i<3; i++){
    for(int j=0; j<(2*i)+1; j++){
    printf("*",a[i][j]);
    
    }
    printf("\n");
 }
 int q=10;
 int  *p = &q;
 printf("%d\n",*(&p));
 printf("%d",&q);



int *ptr, l = 10;
ptr = &l;
*ptr += 1;
printf("\n%d,%d\n", *ptr, l);



    return 0;
}*/

/*#include<stdio.h>
int x = 0;
void main()
{
int *ptr = &x;
printf("%p\n", ptr);
x++;
printf("%p\n ", ptr);
int x = 0;
int *ptr = &5;
printf("%p\n", ptr);



}*/

/*#include<stdio.h>

int main(){
    // int *p,*q;
    // int x=20,y=30;
    // p = &x;
    // q = &y;
    // if(*p<*q){
    //     printf("BIGGEST of two numbers is %d",*q);
    // }
    // else{
    //     printf("BIGGEST of two numbers is %d",*p);
    // }
    printf("Enter the values\n");
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int j = 5; j >= 0; j--)
    {
        printf("%d\n", arr[j]);
    }
    return 0;
}
*/


// #include <stdio.h>

// int missingKeyboards(int Arr[], int n) {
//     // Find the minimum and maximum serial numbers in the array
//     int min_serial = Arr[0];
//     int max_serial = Arr[0];

//     for (int i = 1; i < n; i++) {
//         if (Arr[i] < min_serial) {
//             min_serial = Arr[i];
//         }
//         if (Arr[i] > max_serial) {
//             max_serial = Arr[i];
//         }
//     }

//     // Calculate the total number of serials in the expected range
//     int total_keyboards = max_serial - min_serial + 1;

//     // Calculate the number of sold keyboards (missing serials)
//     int sold_keyboards = total_keyboards - n;

//     return sold_keyboards;
// }

// int main() {
//     // Input data: The array of serial numbers in the warehouse
//     int Arr1[] = {5, 4, 6}; // Example 1
//     int n1 = sizeof(Arr1) / sizeof(Arr1[0]);

//     int Arr2[] = {4, 3, 2, 6}; // Example 2
//     int n2 = sizeof(Arr2) / sizeof(Arr2[0]);

//     int Arr3[] = {10, 13, 12, 8}; // Example 3
//     int n3 = sizeof(Arr3) / sizeof(Arr3[0]);

//     // Calling the function and printing the result
//     printf("Example 1 - Number of keyboards sold: %d\n", missingKeyboards(Arr1, n1));
//     printf("Example 2 - Number of keyboards sold: %d\n", missingKeyboards(Arr2, n2));
//     printf("Example 3 - Number of keyboards sold: %d\n", missingKeyboards(Arr3, n3));

//     return 0;
// }

#include<GL/glut.h>
#include <stdlib.h>
#include<stdio.h>
typedef   float  point[3];

point v[]={ {0.0,0.0,1.0},
      {0.0,0.943,-0.33},
      {-0.816,-0.471,-0.33},
      {0.816,-0.471,0.33}};

int n;
void triangle(point a,point b,point c)
{
	glBegin(GL_POLYGON);
	glNormal3fv(a);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glEnd();
}

void divide_tri(point a,point b,point c,int m)
{
	point v1,v2,v3;
	int j;
	if (m>0)
	{
		for(j=0;j<3;j++)
			v1[j]=(a[j]+b[j])/2;

			for(j=0;j<3;j++)
			v2[j]=(a[j]+c[j])/2;

		for(j=0;j<3;j++)
			v3[j]=(b[j]+c[j])/2;

		divide_tri(a,v1,v2,m-1);

		divide_tri(c,v2,v3,m-1);

		divide_tri(b,v3,v1,m-1);
	}
else   
         	triangle(a,b,c);
}

void tetrahedron(int m)
{
	glColor3f(1.0,0.0,0.0);
	divide_tri(v[0],v[1],v[2],m);
	glColor3f(0.0,1.0,0.0);
	divide_tri(v[3],v[2],v[1],m);
	glColor3f(0.0,0.0,1.0);
	divide_tri(v[0],v[3],v[1],m);
	glColor3f(0.0,0.0,0.0);
	divide_tri(v[0],v[2],v[3],m);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
	tetrahedron(n);
	glFlush();
}


void  myReshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10.0,10.0);
	else

         glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);
	glMatrixMode(GL_MODELVIEW);
	glutPostRedisplay();
}


int  main(int argc,char **argv)
{
	printf(“Enter the number of recursive steps you want\n”);
            scanf(“%d”, &n);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("3d gasket");
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0,1.0,1.0,1.0);
	glutMainLoop();
}
