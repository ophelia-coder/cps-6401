#include<math.h>
#include<stdio.h>
//solving for the function
//tol and max_iter globally using #DEFINE
double f(double x){
	 return x*x*x*x*x*x -x -1;
}

//solving for the derivative
double f_prime(double x){
	 return 6*x*x*x*x*x -1;
}

//fabs is for absolute of the function
double fabs(double x){
	if(x<0)
		return x * - 1;
		
	return x;
}

double secant(int M, double tol){
	double x_0=1;
	double x_1=1.5;
	
	for(int i=0; i<=M; i++){
	double f_x0 = f(x_0);
	double f_x1 =f(x_1);
		if(f_x0 - f_x1 ==0){
			printf("f(%lf) and f(%lf) are same. Aborting(quiting)\n", x_0, x_1);
			return -1.0;
		}
		double x_2 = x_1 - f_x1 *(x_1 - x_0)/ (f_x1 - f_x0);
		if(fabs(x_2 - x_1) <= tol) {
	 		return x_2;
		}
		x_0 = x_1;
		x_1 = x_2;
		
	 	
	 }
	return -1.0;
}
double bisection(int M, double tol){
	double a =1;
	double b=1.5;
	
	printf("Bisection");
	for(int i=0; i<=M; i++){
	double u = f(a);
	double v=f(b);
		if(u*v >=0){
		printf("no root found");
		return -1.0;
		}
		double c = (a+b)/2;
		double w = f(c);
		if (fabs(c) <= tol || fabs(w) <= tol) {
	 	return c;
		}
	 	if(u*v < 0){
	 		b=c;
			c=w;
	 	}else{
	 		a=c;
	 		v=w;
	 	}
	 	
	 	
	}
	
	return -1.0;
}

double newton(int m, double tol){
	double x_0 =-1;
	double v = f_prime(x_0);
	if (fabs(v) < tol) 
	 	return x_0;
	printf("Newton inner loop");
	for (int i =0; i<m; i++){
		double x_1 = x_0 - f(x_0) / f_prime(x_0);
		if (fabs(x_1 - x_0) <= tol || fabs(f(x_1)) <= tol){
			return x_1;
	 	}
	 	
	 	x_0 = x_1;
	}
	
	return -1.0;
}

int main(){
	double tol = .000001;//1e-6
	int m=50;//maximum iterarion
	int option;//to choose whether you are using newton, bisection or secant
	double ans;
	printf("Choose Option\n1: Bisection\n2: Newtons\n3 Secant\n");
	scanf("%d", &option);
	switch(option){
		case 1:
			double a,b;
			printf("Input a and b\n");
			scanf("%lf %lf", &a, &b);
			ans = bisection(m, tol);
			printf("Bisection Root %lf\n", ans);
			printf("f(%lf) = %lf\n", ans, f(ans));
			break;
		case 2: 
		        double x1,x2;
		        printf("Input x1 and x2\n");
			scanf("%lf %lf", &x1, &x2);
		    	ans = newton(m, tol);
			printf("Newtons Root %lf\n", ans);
			printf("f(%lf) = %lf\n", ans, f(ans));
			break;
		case 3: 
		        double v1,v2;
		        printf("Input v1 and v2\n");
			scanf("%lf %lf", &v1, &v2);
			ans = secant(m, tol);
			printf("Secant Root %lf\n", ans);
			printf("f(%lf) = %lf\n", ans, f(ans));
			break;
			
	}
	return 0;
}
