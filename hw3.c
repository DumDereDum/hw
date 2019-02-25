//------point.h------//

#ifndef point_h
#define point_h

#include <stdio.h>

struct point
{
    int x;
    int y;
};

struct point find_point (struct point p1, struct point p2, struct point p3);

#endif /* point_h */

//------point.c (point.cpp)------//

#include "point.h"

struct point find_point (struct point p1, struct point p2, struct point p3)
{
    struct point p4,p;
    
/*  Не тру
    if (p1.x == p2.x)
        p4.x = p3.x;
    else if (p1.x == p3.x)
        p4.x = p2.x;
    else if (p2.x == p3.x)
        p4.x = p1.x;
        
    if (p1.y == p2.y)
        p4.y = p3.y;
    else if (p1.y == p3.y)
        p4.y = p2.y;
    else if (p2.y == p3.y)
        p4.y = p1.y;
*/
//  тру
    p.x=(p1.x+p3.x)/2;
    p.y=(p1.y+p3.y)/2;
        
    p4.x = 2*p.x - p2.x;
    p4.y = 2*p.y - p2.y;
        
    return p4;
}

//------rational.h------//

#ifndef rational_h
#define rational_h

#include <stdio.h>

typedef struct rat
{
    int num, denum;
} Rational ;

Rational add (const Rational *, const Rational *);

Rational sub (const Rational *, const Rational *);

Rational mult (const Rational *, const Rational *);

Rational divv (const Rational *, const Rational *);

void comp(const Rational *,const Rational *);

void print(const Rational *);

#endif /* rational_h */

//------rational.c (rational.cpp)------//

#include "rational.h"


// нахождение наибольшего общего делителя
int NOD(int a, int b)
{
    if(!(a % b)) // if((a % b)==0)
        return b;
    return NOD(b, a % b);
}

// функция сокращения дроби
void decr(Rational * r)
{
    int a;
    a = NOD(r->num, r->denum);
    r->denum /= a;
    r->num /= a;
}

// Фунция определения знака, для печати
void sign(Rational * r)
{
    if(r->denum < 0 && r->num > 0)
    {
        r->denum *= -1;
        r->num *= -1;
    }
}
// Функция сложения двух дробей
// После сложения вызываются функции сокращения дроби и определения знака дроби
Rational add(const Rational *left,
             const Rational *right)
{
    Rational res;
    res.num = left->num * right->denum + left->denum * right->num;
    res.denum = left->denum * right->denum;
    decr(&res);
    sign(&res);
    return res;
}

// Функция вычитания двух дробей
Rational sub(const Rational *left,const Rational *right)
{
    Rational res;
    res.num = left->num * right->denum - left->denum * right->num;
    res.denum = left->denum * right->denum;
    decr(&res);
    sign(&res);
    return res;
}

// Функция умножения двух дробей
Rational mult(const Rational *left,const Rational *right)
{
    Rational res;
    res.num = left->num * right->num;
    res.denum = left->denum * right->denum;
    decr(&res);
    sign(&res);
    return res;
}

// Функция деления двух дробей
Rational divv(const Rational *left,const Rational *right)
{
    Rational res;
    res.num = left->num * right->num;
    res.denum = left->denum * right->denum;
    decr(&res);
    sign(&res);
    return res;
}

void comp(const Rational *left,const Rational *right)
{
    int a,b;
    
    a=left->num*right->denum;
    b=right->num*left->denum;
 
    if (a==b){printf("Дроби равны \n");}
    else
    {
        printf("Дроби не равны \n");
        if(a>b){printf("Первая дробь больше второй \n");}
        else {printf("Первая дробь меньше второй \n");}
    }
}


// печать рациональной дроби
void print(const Rational * r)
{
    Rational copy = *r;
    decr(&copy);
    sign(&copy);
    if(copy.num / copy.denum)
    {
        printf("%d ", (copy.num / copy.denum) );
        copy.num %= copy.denum;
    }
    if(copy.num % copy.denum==0)
    {
        printf("\n");
        return;
    }
    printf("%d/%d\n", copy.num, copy.denum);
}

//------complex.h------//

#ifndef complex_h
#define complex_h

#include <stdio.h>

typedef struct complex
{
    int  real, img;
} Complex ;

Complex add1 (const Complex  *, const Complex  *);

Complex sub1 (const Complex  *, const Complex  *);

Complex mult1 (const Complex  *, const Complex  *);

Complex divv1 (const Complex  *, const Complex  *);

void comp1(const Complex  *,const Complex  *);

void print1(const Complex  *);
#endif /* complex_h */

//------complex.c (complex.cpp)------//

#include "complex.h"

Complex  add1 (const Complex  *a, const Complex  *b)
{
    Complex res;
    res.real=a->real+b->real;
    res.img=a->img+b->img;
    return res;
}

Complex  sub1 (const Complex  *a, const Complex  *b)
{
    Complex res;
    res.real=a->real-b->real;
    res.img=a->img-b->img;
    return res;
}

Complex  mult1 (const Complex  *a, const Complex  *b)
{
    Complex res;
    res.real=(a->real*b->real) - (a->img*b->img);
    res.img=(a->real*b->img) + (a->img*b->real);
    return res;
}


// вывод работает норм, но возвращает она округленные значения int, фиксить ленб :))
Complex  divv1 (const Complex  *a, const Complex  *b)
{
    Complex res;
    int n,ni,den;
    
    n=(a->real*b->real) + (a->img*b->img);
    ni=(a->img*b->real) - (a->real*b->img);
    den=(b->real*b->real)+(b->img*b->img);
    
    if (((ni>0)&&(den>0))||((ni<0)&&(den<0)))
        printf("(%d/%d)+(%d/%d)*i \n",n,den,ni,den);
    else if (((ni>0)&&(den<0))||((ni<0)&&(den>0)))
        printf("(%d/%d)-(%d/%d)*i \n",n,den,abs(ni),abs(den));
    else printf("%d/%d \n",n,den);
        
    res.real=n/den;
    res.img=ni/den;
    return(res);
    
    /*res.real=((a->real*b->real) + (a->img*b->img))/((b->real*b->real)+(b->img*b->img));
    res.img=((a->img*b->real) - (a->real*b->img))/((b->real*b->real)+(b->img*b->img));
     return res;*/
}

void comp1(const Complex  *a,const Complex  *b)
{
    if((a->img==b->img)&&(a->real==b->real)){printf("Числа равны \n");}
    else{printf("Числа не равны \n");}
}

void print1(const Complex  * num)
{
    if(num->real!=0)
    {
        if(num->img>0){printf("%d+%d*i \n",num->real,num->img);}
        else if(num->img==0){printf("%d \n",num->real);}
        else if(num->img<0) printf("%d-%d*i \n",num->real,abs(num->img));
    }
    else if (num->img==0){printf("0 \n");}
    else {printf("%d*i \n",num->img);}

}

//------circle.h------//

#ifndef circle_h
#define circle_h

#include <stdio.h>
#include <math.h>

struct point { int x; int y;} ;

struct circle
{
    int radius;
    struct point center;
};

int find_concentric( struct circle c[], int i);

int find_nedte(struct circle c[], int i);

int find_cross(struct circle c[], int i);

int find_alone(struct circle c[], int i);

#endif /* circle_h */

//------circle.c (circle.cpp)------//

#include "circle.h"

int find_concentric( struct circle c[], int i)
{
    int res=0;
    
    for (int j=0; j<i; j++)
    {
        for(int k=j+1; k<i; k++)
        {
            if ((c[j].center.x==c[k].center.x)&&(c[j].center.y==c[k].center.y)&&(c[j].radius!=c[k].radius))
                res+=2;
        }
    }
    printf("Кол-во концентрических окружностей: %d \n",res);
    return res;
}

int find_nedte(struct circle c[], int i)
{
    int res=0;
    
    double x1,x2,y1,y2,r1,r2;
    double x0,y0,r0;
    double d12;
    
    for (int j=0; j<i-1;j++)
    {
        for (int k=0;k<i;k++)
        {
            if (j!=k)
            {
                r1=c[j].radius;
                x1=c[j].center.x;
                y1=c[j].center.y;
                
                r2=c[k].radius;
                x2=c[k].center.x;
                y2=c[k].center.y;
        
                r0=r1-r2;
                x0=x1-x2;
                y0=y1-y2;
                d12=sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
                
                
                
                //printf(" (%.0f,%.0f,%.0f)(%d)  (%.0f,%.0f,%.0f)(%d) (%.0f,%.0f,%.0f)  \n",r1,x1,y1,j+1,r2,x2,y2,k+1,r0,x0,y0 );
                
                if(((x0*x0)+(y0*y0)<=(r0*r0))&&(r0>=0)) res++;
                //printf("(%.0f,%.0f,%.0f)",r0,x0,y0);
                //printf("(%d,%d) %d \n",j+1,k+1,res);
            }
        }
    }
    
    printf("Кол-во вложенных окружностей: %d \n",res);
    return res;
}

int find_cross(struct circle c[], int i)
{
    int res=0;
    double x1,x2,x3,y1,y2,y3,r1,r2,r3;
    double d12,d23,d13;
    for (int j=0; j<i; j++)
    {
        for(int k=j+1; k<i; k++)
        {
            for (int n=k+1; n<i; n++)
            {
                r1=c[j].radius;
                x1=c[j].center.x;
                y1=c[j].center.y;
                
                r2=c[k].radius;
                x2=c[k].center.x;
                y2=c[k].center.y;
                
                r3=c[n].radius;
                x3=c[n].center.x;
                y3=c[n].center.y;
                
                d12=sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
                d23=sqrt( (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3) );
                d13=sqrt( (x2-x3)*(x2-x3) + (y2-y3)*(y2-y3) );
                
                //printf(" (%.0f,%.0f,%.0f)(%d)  (%.0f,%.0f,%.0f)(%d)  (%.0f,%.0f,%.0f)(%d) \n",r1,x1,y1,j+1,r2,x2,y2,k+1,r3,x3,y3,n+1);
                
                //printf("      d12=%f (%.0f) | d23=%f (%.0f) | d13=%f (%.0f) \n",d12,r1+r2,d23,r2+r3,d13,r1+r3);
                
                if( (d12<=(r1+r2)) && (d23<=(r2+r3)) && (d13<=(r1+r3)) )
                    res+=3;
            }
        }
    }
    printf("Кол-во трипопарно пресекающихся окружностей: %d \n",res/2);
    return res/2;
}

int find_alone(struct circle c[], int i)
{
    int res=0;
    int p=0;
    double x1,x2,y1,y2,r1,r2;
    double d12;
    
    for (int j=0; j<i-1;j++)
    {
        for (int k=0;k<i;k++)
        {
            if (j!=k)
            {
            r1=c[j].radius;
            x1=c[j].center.x;
            y1=c[j].center.y;
            
            r2=c[k].radius;
            x2=c[k].center.x;
            y2=c[k].center.y;
            
            d12=sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
            
            //printf(" (%.0f,%.0f,%.0f)(%d)  (%.0f,%.0f,%.0f)(%d) (%f) \n",r1,x1,y1,j+1,r2,x2,y2,k+1, d12);
            
            if(d12>r1+r2) p++;
            }
        }
        //printf("%d %d \n",j+1,p);
        if (p==i) res++;
        p=0;
    }
    
    printf("Кол-во уединенных окружностей: %d \n",res);
    
    return res;
}

//------main.c (main.cpp)------//

#define TASK 2

#if TASK == 1
#include "point.h"
int main()
{
/*
Написать функцию, которая по трем точкам, являющимися вершинами некоторого прямоугольника , определяет его четвертую фершину
 */
//    struct point a = {2,0}, b = {2,2}, c = {0,2};  // point 4 = (0,0)
//    struct point a = {2,4}, b = {-3,7}, c = {-6,6};  // point 4 = (-1,3)
    struct point a,b,c;
    printf("Введите точки \n");
    scanf("%d %d", &a.x, &a.y);
    scanf("%d %d", &b.x, &b.y);
    scanf("%d %d", &c.x, &c.y);
    struct point p;
    p = find_point(a,b,c);
    printf("Кординаты: %d %d \n", p.x,p.y);

    return 0;
}
#endif

#if TASK == 2
#include "rational.h"
#include "complex.h"

int main()
{
    
/*
Написать в виде структуры
a) рациональную дробь
b) комплексное число
Разработать совокупность операций для данных этого типа (+, -, *, /, <, >, ==, !=); реализовать каждую из них в виде функции.
*/
    
    struct rat a={1,10},b={1,3};
    struct rat res;
    
    res=add (&a,&b);
    print(&res);
    res=sub (&a,&b);
    print(&res);
    res=mult (&a,&b);
    print(&res);
    res=divv (&a,&b);
    print(&res);
    comp(&a,&b);
    print(&a);
    print(&b); 
    
    struct complex c={1,2},d={2,-4},e={0,1},f={1,0};
    struct complex res1;
    
    res1=add1(&c,&d);
    print1(&res1);
    res1=sub1(&c,&d);
    print1(&res1);
    res1=mult1(&c,&d);
    print1(&res1);
    res1=(divv1(&c, &d));
    print1(&res1);
    
    comp1(&c, &d);
    print1(&c);
    print1(&d);
    print1(&e);
    print1(&f);
    
    return 0;
}
#endif

#if TASK==3
#include "circle.h"

int main()
{
    /*
     Пусть целосиленная окружность описана следующим образом:
     struct point { int x; int y;};
     struct circle { int radius; struct point center;} ;
     Пусть есть массив struct circle plane[50], содержащий информацию об окружностьях на плоскости ю Написать функцию определяющую:
     a. есть ли среди этих окружностей хотя бы две концентрированые окружности;
     b. есть ли среди этих окружностей хотя бы две две вложенные (не обязательно концентрические) окружности;
     c. есть ли среди этих окружностей трипопарно пресекающихся окружностей;
     d. есть ли среди этих окружностей хотя бы одна уединенная окружность (ни с чем не пересекается);
     */
    int i=11;
    struct circle plane[11]={
        {2,2,2},   //1
        {3,2,7},   //2
        {2,4,4},   //3
        {2,-2,-2}, //4
        {1,-8,-4}, //5
        {2,-8,4},  //6
        {4,-8,4},  //7
        {2,-10,12},//8
        {2,6,0},   //9
        {3,6,-3},  //10
        {1,6,-5}   //11
    };
    //struct circle c={1,2,3};
    
    find_concentric( &plane[0],i);
    
    find_nedte(&plane[0],i);
    
    find_cross( &plane[0], i);
    
    find_alone( &plane[0], i);
    
    //printf("%d %d %d",c.radius, c.center.y,c.center.x);
    return 0;
}
#endif





