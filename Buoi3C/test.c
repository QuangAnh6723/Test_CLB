#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum {
	rot = 0, dau = 1, khongCo = 3
} kq_t;
typedef struct HocSinh
{
	char ten[20];
	char gt[4];
	int kv;
	int nh;
	float td;
	kq_t kq;
} HocSinh_t;

int main()
{
    HocSinh_t hs;
    FILE *fp = fopen("D:\\BaitapC\\dau.txt", "r");
    char buffer[255] ;
    int i;
    // fscanf(fp,"%[^\n]", buffer);
    // printf("Data from the file:\n%s", buffer);
    fgets(buffer, 100, fp);
    printf("%s", buffer);
        sscanf(buffer, "%d, %[^,], %[^,], %d, %d, %f, %d\n",&i, &hs.ten, &hs.gt, &hs.kv, &hs.nh, &hs.td, &hs.kq);
        // printf(" %d,%s,%s,%d,%d,%.2f,%d.\t\t\n",i, hs.ten,hs.gt,hs.kv, hs.nh, hs.td, hs.kq);
        printf("\n%s ", hs.ten);
        printf("\n%s ", hs.gt);
        printf("\n%d ", hs.kv);
        printf("\n%d ", hs.nh);
        printf("\n%.2f", hs.td);
        printf("\n%d ", hs.kq);
        
    while (fgets(buffer, 100, fp) != NULL)
    {
        printf("%s", buffer);
        // printf(" %d,%s,%s,%d,%d,%.2f,%d.\t\t\n",i, hs.ten,hs.gt,hs.kv, hs.nh, hs.td, hs.kq);
        sscanf(buffer, "%d, %[^,], %[^,], %d, %d, %f, %d\n",&i, &hs.ten, &hs.gt, &hs.kv, &hs.nh, &hs.td, &hs.kq);
        printf("\n%s ", hs.ten);
        printf("\n%s ", hs.gt);
        printf("\n%d ", hs.kv);
        printf("\n%d ", hs.nh);
        printf("\n%.2f", hs.td);
        printf("\n%d \n", hs.kq);
    }

    fclose(fp);
    return 0;
}