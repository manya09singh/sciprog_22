#include<stdio.h>
#include<math.h>
// use const as it is a better practice

double arctanh1(const double x, const double delta);

double arctanh2(const double x);

int main(){
	double delta,x;
	printf("Enter the precision for Maclaurin Series\n");
	scanf("%lf", &delta);
	
	int length = 1000;
	double tan1[length]; // Store the results of arctanh1 for each x
	double tan2[length]; //Store the results of arctanh2 for each x


	int j =0;
	x = -0.9;
	while(x<=0.9 && j<length){
		tan1[j] = arctanh1(x,delta);
		tan2[j] = arctanh2(x);
		printf("The difference at x=%lf between them is %.10lf\n",x,fabs(tan1[j]-tan2[j]));
		j++;
		x=x+0.1; // try with 0.01
		}
	return 0;
}


double arctanh1(const double x, const double delta){
	
	double arcTan = 0;  // approximate result
	double elem, val;
	int n=0; //sum parameter
	
	do {	
		val = 2*n+1;
		elem = pow(x,val)/val;
		arcTan+=elem;
		n++;

	} while(fabs(elem) >= delta); // fabs returns absolute value of the float


	return arcTan;
} 


double arctanh2(const double x){
	return (log(1+x)-log(1-x)/2);


}
