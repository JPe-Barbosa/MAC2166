

#include <stdio.h>
#include <math.h>

/*double dist(double p1x, double p1y, double p2x, double p2y)*/
double dist(double p1x, double p1y, double p2x, double p2y){
    double d;
    d = (p1x-p2x)*(p1x-p2x)+ (p1y-p2y)*(p1y-p2y);

    return sqrt(d);
}

/*Esta função recebe um caractere c ∈ {’x’, ’y’}, um inteiro i ∈ {0, 1, 2}, e dados
que especificam três corpos: corpo B0 na posição (x0, y0) com massa m0, corpo B1
na posição (x1, y1) com massa m1, e corpo B2 na posição (x2, y2) com massa m2.
Esta função devolve a componente c da força gravitacional total que os corpos Bj
com j 6= i exercem sobre o corpo i.*/
double forca(char c, int i,
double x0, double y0, double m0,
double x1, double y1, double m1,
double x2, double y2, double m2){
double G = 6.67 * pow(10,-11), f1 = 0, f2 = 0,f = 0;

switch (c)
{
case 'x':
    switch (i)
    {
    case 0:
        f1 = (G * m0 * m1)/ (dist(x0,y0,x1,y1)*dist(x0,y0,x1,y1));
        f2 = (G * m0 * m2)/ (dist(x0,y0,x2,y2)*dist(x0,y0,x2,y2));
        
        /*decomposição para os eixos*/
        f1 = ((x1-x0)/dist(x0,y0,x1,y1))*f1;
        f2 = ((x2-x0)/dist(x0,y0,x2,y2))*f2;
        
        f = f1 + f2;
        
    break;

    case 1:
        f1 = (G * m1 * m0)/ (dist(x1,y1,x0,y0)*dist(x1,y1,x0,y0));
        f2 = (G * m1 * m2)/ (dist(x1,y1,x2,y2)*dist(x1,y1,x2,y2));
        
        /*decomposição para os eixos*/
        f1 = ((x0-x1)/dist(x1,y1,x0,y0))*f1;
        f2 = ((x2-x1)/dist(x1,y1,x2,y2))*f2;

        
        f = f1 + f2;
    break;
    
    case 2:
        f1 = (G * m2 * m0)/ (dist(x2,y2,x0,y0)*dist(x2,y2,x0,y0));
        f2 = (G * m2 * m1)/ (dist(x2,y2,x1,y1)*dist(x2,y2,x1,y1));
        
        /*decomposição para os eixos*/
        f1 = ((x0-x2)/dist(x2,y2,x0,y0))*f1;
        f2 = ((x1-x2)/dist(x2,y2,x1,y1))*f2;
        
        
        f = f1 + f2;
    break;
    
    default:
        break;
    }
break;

case 'y':
    switch (i)
        {
            case 0:
                f1 = (G * m0 * m1)/ (dist(x0,y0,x1,y1)*dist(x0,y0,x1,y1));
                f2 = (G * m0 * m2)/ (dist(x0,y0,x2,y2)*dist(x0,y0,x2,y2));
                
                /*decomposição para os eixos*/
                f1 = ((y1-y0)/dist(x0,y0,x1,y1))*f1;
                f2 = ((y2-y0)/dist(x0,y0,x2,y2))*f2;
                
                
                f = f1 + f2;
            break;

            case 1:
                f1 = (G * m1 * m0)/ (dist(x1,y1,x0,y0)*dist(x1,y1,x0,y0));
                f2 = (G * m1 * m2)/ (dist(x1,y1,x2,y2)*dist(x1,y1,x2,y2));
                
                /*decomposição para os eixos*/
                f1 = ((y0-y1)/dist(x1,y1,x0,y0))*f1;
                f2 = ((y2-y1)/dist(x1,y1,x2,y2))*f2;
                
                
                f = f1 + f2;
            break;
            
            case 2:
                f1 = (G * m2 * m0)/ (dist(x2,y2,x0,y0)*dist(x2,y2,x0,y0));
                f2 = (G * m2 * m1)/ (dist(x2,y2,x1,y1)*dist(x2,y2,x1,y1));
                
                /*decomposição para os eixos*/
                f1 = ((y0-y2)/dist(x2,y2,x0,y0))*f1;
                f2 = ((y1-y2)/dist(x2,y2,x1,y1))*f2;
                
                
                f = f1 + f2;
            break;
            default:
                break;

        }
break;

default:
    break;
}


return f;
}

/*Esta função recebe a posição (∗x, ∗y), a velocidade (∗vx , ∗vy) e a aceleração (ax , ay)
de um corpo em um dado instante, digamos t. Esta função atualiza os valores
de (∗vx , ∗vy) e (∗x, ∗y) usando (3) e (4) acima, onde ∆t = dt, de forma que (∗x, ∗y)
torna-se a posição do corpo no instante t + ∆t.*/
void atualize(double *x, double *y, double *vx, double *vy,
double ax, double ay, double dt){
    *vx = *vx + ax * dt;
    *vy = *vy + ay * dt;
    
    *x = *x + *vx * dt;
    *y = *y + *vy * dt;
}

int main(){
    double x0,y0,vx0,vy0,ax0,ay0,m0;
    double x1,y1,vx1,vy1,ax1,ay1,m1;
    double x2,y2,vx2,vy2,ax2,ay2,m2;
    double T,dt,i;

    scanf("%lf %lf %lf %lf %lf", &x0,&y0,&vx0,&vy0,&m0);
    scanf("%lf %lf %lf %lf %lf", &x1,&y1,&vx1,&vy1,&m1);
    scanf("%lf %lf %lf %lf %lf", &x2,&y2,&vx2,&vy2,&m2);
    scanf("%lf %lf", &T, &dt);
   
   /* printf("%e %e %e %e %e %e\n", x0, y0, x1, y1, x2, y2); */
    for(i= 0; i <= T; i = i + dt){
        ax0 = forca('x', 0,x0,y0,m0,x1,y1,m1,x2,y2,m2)/m0;
        ax1 = forca('x', 1,x0,y0,m0,x1,y1,m1,x2,y2,m2)/m1;
        ax2 = forca('x', 2,x0,y0,m0,x1,y1,m1,x2,y2,m2)/m2;
        
        ay0 = forca('y', 0,x0,y0,m0,x1,y1,m1,x2,y2,m2)/m0;
        ay1 = forca('y', 1,x0,y0,m0,x1,y1,m1,x2,y2,m2)/m1;
        ay2 = forca('y', 2,x0,y0,m0,x1,y1,m1,x2,y2,m2)/m2;

        printf("%g %g %g %g %g %g\n", x0, y0, x1, y1, x2, y2);

        atualize(&x0, &y0, &vx0, &vy0, ax0, ay0, dt);
        atualize(&x1, &y1, &vx1, &vy1, ax1, ay1, dt);
        atualize(&x2, &y2, &vx2, &vy2, ax2, ay2, dt);
        
       
    }
    return 0;
}