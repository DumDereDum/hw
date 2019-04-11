int prt(int a, int loc) 
{ 
int buf = a & 1 « loc; 
if (buf == 0) 
return 0; 
else 
return 1; 
} 
void byte(float arg) 
{ 
double pow2; 

if ( arg < 0 ) 
{ 
putchar('-'); 
arg = -arg; 
} 
if ( arg - arg != 0 ) 
{ 
printf("Inf"); 
} 
else 
{ 
for ( pow2 = 1; pow2 * 2 <= arg; pow2 *= 2 ) ; 
while ( arg != 0 || pow2 >= 1 ) { 
if ( pow2 == .5 ) putchar('.'); 
if ( arg < pow2 ) putchar('0'); 
else { 
putchar('1'); 
arg -= pow2; 
} 
pow2 *= .5; 
} 
} 

putchar('\n'); 

return; 
} 

int main() 
{ 
int a; 
float b; 
printf("Enter a\n"); 
scanf_s("%d", &a); 
printf("Enter b\n"); 
scanf_s("%f", &b); 
while((a!=0)&&(b!=0)) 
{ 
for (int i = 15; i >= 0; i--) 
printf("%d", prt(a, i)); 
printf("\n"); 
byte(b); 
printf("\n"); 
printf("Enter a\n"); 
scanf_s("%d", &a); 
printf("Enter b\n"); 
scanf_s("%f", &b); 

} 

}
