#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>

int main() {

	int a, b, wynik, p1, p2;
	int temp, temp2;
	int i, j, k;
	
	printf("a = ");	scanf("%d", &a);			
	printf("b = "); scanf("%d", &b);
	
	wynik = a * b;
	
	if ((a < INT_MIN - b) || (a > INT_MAX - b)) {
		printf("\nWartosci sa zbyt duze lub zbyt male\n");
	}

	if ((b < 0) || (a < 0) || wynik < 0) {
		printf("non-negative value expected\n");
	} else {
	
	printf("\n");
	
	int max = a > b ? a : b;
	int min = a < b ? a : b;

	int width_max_a_b = max > 0 ? log10(max) + 1 : 1 ;
	int width_min_a_b = min > 0 ? log10(min) + 1 : 1 ;
	
	int size = wynik > 0 ? log10(wynik) + 3 : 3 ;
	
	int carry[width_min_a_b][width_max_a_b];
	
	int add[width_min_a_b];
	
	if (a == 0 || b == 0) {
		size = width_max_a_b + 2;
	}
	
	temp = min;
	
	for (i = 0; i < width_min_a_b; i++) {
		temp2 = max;
		p1 = temp % 10;
		add[i] = max * p1;
		for (j = width_max_a_b; j > 0; j--) {
			p2 = temp2 % 10;
			if (j == width_max_a_b) {
			carry[i][j] = (p1 * p2) / 10;	
			}
			else {
			carry[i][j] = ((p1 * p2 + carry[i][j+1]) / 10);
			}
			temp2 = temp2 / 10;
		}
		temp = temp / 10;	
	}	
		
	for (i = width_min_a_b - 1; i >= 0; i--) {
		
		if (add[i] == 0 || add[i] == max) {
			continue;
		}
		for(j = 0; j < size - width_max_a_b - 1; j++){
			printf(" ");
		}
		for (j = 1; j < width_max_a_b + 1; j++) {
			if (carry[i][j] == 0) printf(" ");
			else printf("%d", carry[i][j]);
		}
		printf("\n");
	}	
	
		printf("%*d\n", size, max);
		
		for (i = 0; i < size - width_max_a_b - 2; i++) {
			printf(" ");
		}
		
		printf("* %*d\n", width_max_a_b, min);
		
		for(i = 0; i < size - width_max_a_b - 2; i++){
			printf(" ");
		}
		
		for(i = 0; i < width_max_a_b + 2; i++) printf("-");
	
		printf("\n");
		
		if (width_max_a_b != 1 && width_min_a_b != 1){
	
			int pom = size;
		
			for(i = 0; i < width_min_a_b; i++) {
				if (add[i] == 0) {
					pom -= 1;
					continue;
				}
				
				if(i == width_min_a_b - 1) printf("+ %*d\n", width_max_a_b, add[i]);
				
				else printf("%*d\n", pom, add[i]);
				
				pom -= 1;
			}
	
			for(i = 0; i < size; i++) printf("-");
				
				printf("\n");
		}
		
		printf("%*d\n", size, wynik);
	}
  return 0;
}
