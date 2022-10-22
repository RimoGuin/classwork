#include<stdio.h>

int product(int x, int y){
	if(x < y)
		return product(y, x);
	else if(y != 0){
		if(x > 0 && y> 0)	
			return (x + product(x, y - 1));
		else
			return (x + product(x, y + 1));
	}else
		return 0;
}

int main(){
	printf("Enter 2 numbers: ");
	int x, y;
	scanf("%d %d", &x, &y);
	int ans = product(x, y);
	if(x < 0 && y < 0)
		printf("\nProduct: %d", -ans);
	if((x > 0 && y < 0)||(x < 0 && y > 0)){
		ans = -ans;
		printf("\nProduct: %d", ans);
	}
	if(x > 0 && y > 0)
		printf("\nProduct: %d", ans);
	return 0;
}
