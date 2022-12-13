 #include<stdio.h>

 int main (){
 	int a,i,jj,j,n,k;
 	printf("Nhap n ve Cay Thong : ");
 	scanf("%d",&n);
 	for (i=0;i<=n;i++) {
    for(j=1; j<=n-i; j++){
      printf(" ");
    }
    for(k=1; k<=2*i-1; k++){
     printf("*");
    }
    for(j=1; j<=n-i; j++){
     printf(" ");
	 }
     printf("\n");
 }  
   for (i=0;i<=n;i++) {
    for(j=1; j<=n-i; j++){
      printf(" ");
    }printf("*"); goto A;
}
A:
	  printf("\n");
  for (i=0;i<=n;i++) {
    for(j=1; j<=n-i; j++){
      printf(" ");
    }printf("*"); goto B;
} B:
	return 0;

}