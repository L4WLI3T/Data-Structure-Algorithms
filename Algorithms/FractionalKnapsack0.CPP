#include<stdio.h>
//#include<conio.h>
int i, j;
int n=7, max=15;
float weight[20]={2,3,5,7,1,4,1}, profit[20]={10,5,15,7,6,18,3};

void sort();
float knapsack();

int main() {
	//clrscr();
	/*
	printf("Enter the no. of element : ");
	scanf("%d", &n);
	printf("Enter the max. capacity : ");
	scanf("%d", &max);
	printf("WEIGHTS && PROFITS : \n");
	for(i=0;i<n;i++) {
		printf("\tProfit -> %d : ", i+1);
		scanf("%f",&profit[i]);
		printf("\tWeight -> %d : ", i+1);
		scanf("%f",&weight[i]);
	} */

	printf("The optimal solution is %.2f", knapsack());

	//getch();
	return 0;

}

float knapsack() {
	float x[20] = {0};
	float totalProfit=0;
	int capacity;

	capacity = max;
	sort();
	i=0;
	while(i<n && weight[i]<=capacity) {
		x[i] = 1;
		capacity -= weight[i];
		i++;
	}
	if(i<n) {
		x[i] = capacity/weight[i];
	}
	for(i=0; i<n; i++){
		totalProfit += x[i]*profit[i];
	}

	return totalProfit;
}

void sort() {
	int temp;
	for(i=n-1; i>0; i--) {
		for(j=0; j<i; j++){
			if(profit[j]/weight[j] < profit[j+1]/weight[j+1]) {
				temp = profit[j];
				profit[j] = profit[j+1];
				profit[j+1] = temp;
				temp = weight[j];
				weight[j] = weight[j+1];
				weight[j+1]= temp;
			}
		}
	}
	for(i=0;i<n;i++)
		printf("%.2f ",profit[i]/weight[i]);
	printf("\n");
}
