#include <stdio.h>
#include <math.h>

long double caudal = 0.0;
long double longitud = 0.0;
long double headLoss= 0.0;
long double viscosidad = 0.0;
long double densidad = 0.0;
long double rugosidad = 0.0;
long double a = 0.0;
long double reConst= 0.0;
long double f_i = 4e-1;
const long double g = 9.81;

long double inline fifthroot (long double radicando){
	return pow(radicando, 1.0/5.0);
}

int main (){
	printf("Caudal [m3/s]: ");
	scanf("%Le",&caudal);
	printf("Longitud [m]: ");
	scanf("%Le", &longitud);
	printf("Rugosidad absoluta [m]: ");
	scanf("%Le", &rugosidad);
	printf("Pérdida admisible de cabeza [m]: ");
	scanf("%Le", &headLoss);
	printf("Viscosidad dinámica [kg/m·s]: ");
	scanf("%Le", &viscosidad);
	printf("Densidad [kg/m3]: ");
	scanf ("%Le", &densidad);
	a = 8 * caudal * caudal * longitud / (headLoss * g * 9.8696);
	printf("a = %Le\n", a);
	reConst = 3.14159 * caudal / (4 * (viscosidad/densidad));
	while (1){
		printf("\tDiámetro: %Lg\n", fifthroot(a*f_i));
		printf("\tReynolds: %Le\n", reConst * fifthroot(a*f_i));
		printf("\tRugosidad relativa: %Le\n", rugosidad / fifthroot(a*f_i));
		/*TO DO: Make a function out of this if, with recursion if it seems appropriate*/
		if (reConst * fifthroot(a*f_i) < 2000) { /*Si es régimen laminar*/
			if (f_i - 64 / (reConst * fifthroot(a*f_i)) < 0.0001) {
				if (64 / (reConst * fifthroot(a*f_i)) - f_i < 0.0001) {
					printf("Diámetro final: %Lg", fifthroot(a*f_i));
					printf(" metros\n");
					return 0;
				}
			}
			f_i = 64 / (reConst * fifthroot(a*f_i));
			printf("Se asignó f_i según régimen laminar\n");
		}
		else {/*Si no es régimen laminar*/
			printf("¿f_i+1?: ");
			scanf ("%Le", &f_i);
		}
		if (f_i <= 0.0) {return 0;}
	}
	return 0;
}
