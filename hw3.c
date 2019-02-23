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





