#pragma warning(disable : 4996)
#include<stdio.h>
#include<string.h>
#include<Windows.h>

#define MAX 2
#define SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

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

kq_t check_kq(HocSinh_t hs)
{
    switch (hs.kv)
    {
    case 1:
        switch (hs.nh)
        {
        case 1:
            if (hs.td > 18) return dau;
            else return rot;
            break;
        case 2:
            if (hs.td > 17.5) return dau;
            else return rot;
            break;
        case 3:
            if (hs.td > 17) return dau;
            else return rot;
            break;
        default:
            break;
        }
        break;
    case 2:
        switch (hs.nh)
        {
        case 1:
            if (hs.td > 17) return dau;
            else return rot;
            break;
        case 2:
            if (hs.td > 16.5) return dau;
            else return rot;
            break;
        case 3:
            if (hs.td > 16) return dau;
            else return rot;
            break;
        default:
            break;
        }
        break;
    case 3:
        switch (hs.nh)
        {
        case 1:
            if (hs.td > 16) return dau;
            else return rot;
            break;
        case 2:
            if (hs.td > 15.5) return dau;
            else return rot;
            break;
        case 3:
            if (hs.td > 15) return dau;
            else return rot;
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    return khongCo;
}

void chen_kc(char str1[], int size)
{
    int len = size - strlen(str1);
    for (int i = 0; i < len; i++)
    {
        printf(" ");
    }
}

HocSinh_t set_hs(char ten[], char gt[], int kv, int nh, float dt)
{
    HocSinh_t kq;
    strcpy(kq.ten, ten);
    strcpy(kq.gt, gt);
    kq.kv = kv;
    kq.nh = nh;
    kq.td = dt;
    kq.kq = check_kq(kq);
    return kq;
}

void xuat_hs(HocSinh_t hs)
{
    printf("Ho ten: | %s |\r\n", hs.ten);
    printf("Gioi tinh: %s \r\n", hs.gt);
    printf("Khu vuc: %d \r\n", hs.kv);
    printf("Nhom: %d \r\n", hs.nh);
    printf("Diem tb: %.2f \r\n", hs.td);
    printf("Ket qua: %d \r\n", hs.kq);
}
void nhap_hs(HocSinh_t *hs)
{
    while (getchar() != '\n');
    printf("Nhap ho va ten: ");
    gets(hs->ten);
    printf("Nhap gioi tinh: ");
    scanf("%s", &hs->gt);
    while (getchar() != '\n');
    printf("Nhap khu vuc: ");
    scanf("%d", &hs->kv);
    printf("Nhap nhom: ");
    scanf("%d", &hs->nh);
    printf("Nhap tong diem: ");
    scanf("%f", &hs->td);
    hs->kq = check_kq(*hs);
}
void nhap_ds(HocSinh_t hs[])
{
    printf("\r\n------------------------------------------\r\n");
    printf("\t\t\t Nhap danh sach hoc sinh \r\n");
    for (int i = 0; i < MAX; i++)
    {
        printf("\t\tHoc sinh thu %d \r\n", i + 1);
        nhap_hs(&hs[i]);
    }
    printf("\r\n------------------------------------------\r\n");
}

void xuat_1_hang(HocSinh_t hs)
{
    
    printf(" %s ", hs.ten);
    chen_kc(hs.ten, 20);
    printf(" |    %s   ", hs.gt);
    chen_kc(hs.gt, 4);
    printf("| %d  ", hs.kv);
    printf("|  %d   |", hs.nh);
    if (hs.td < 10) {
        printf("  %.2f |", hs.td);
    }
    else
    {
        printf(" %.2f |", hs.td);
    }

    if (hs.kq == dau)
    {
        printf("    dau    |\r\n");
    }
    else
    {
        printf("    rot    |\r\n");
    }
}

void xuat_bang(HocSinh_t hs[])
{
    printf("\r\n+----+-----------------------+-----------+----+------+-------+-----------+\r\n");
    printf("| TT | Ho va ten             | Gioi tinh | KV | Nhom | Tong  |  Ket qua  |\r\n");
    for (int i = 0; i < 10; i++)
    {
        printf("+----+-----------------------+-----------+----+------+-------+-----------+\r\n");
        printf("| %2d |", i + 1);
        xuat_1_hang(hs[i]);
    }
    printf("+----+-----------------------+-----------+----+------+-------+-----------+\r\n");
}

void swap(HocSinh_t* a, HocSinh_t* b)
{
    HocSinh_t temp = *a;
    *a = *b;
    *b = temp;
}

void sapXep(HocSinh_t hs[])
{
    for (int i = 0; i < 10 - 1; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (hs[i].td < hs[j].td) {
                swap(&hs[i], &hs[j]);
            }
        }
    }
}

void dsTrungTuyen(HocSinh_t hs[])
{
    int cnt = 1;
    printf("\r\n+----+-----------------------+-----------+----+------+-------+-----------+\r\n");
    printf("| TT | Ho va ten             | Gioi tinh | KV | Nhom | Tong  |  Ket qua  |\r\n");
    for (int i = 0; i < 10; i++)
    {
        if (hs[i].kq == dau)
        {
            printf("+----+-----------------------+-----------+----+------+-------+-----------+\r\n");
            printf("| %2d |", cnt);
            xuat_1_hang(hs[i]);
            cnt++;
        }
    }
    printf("+----+-----------------------+-----------+----+------+-------+-----------+\r\n");
}

void ds_init(HocSinh_t a[])
{
    a[0] = set_hs((char*)"Nguyen van Yue", (char*)"nam", 1, 1, 5);
    a[1] = set_hs((char*)"Nguyen van Thane", (char*)"nam", 1, 2, 16);
    a[2] = set_hs((char*)"Nguyen van Nak", (char*)"nam", 1, 3, 9);
    a[3] = set_hs((char*)"Nguyen van Zuka", (char*)"nu", 2, 1, 27);
    a[4] = set_hs((char*)"Nguyen van Azenka", (char*)"nu", 2, 2, 18);
    a[5] = set_hs((char*)"Nguyen van violet", (char*)"nu", 2, 3, 14);
    a[6] = set_hs((char*)"Nguyen van Yorn", (char*)"nam", 3, 2, 25);
    a[7] = set_hs((char*)"Nguyen Florentino", (char*)"nam", 3, 1, 16);
    a[8] = set_hs((char*)"Nguyen van Enzo", (char*)"nam", 3, 3, 9);
    a[9] = set_hs((char*)"Nguyen van Preyta", (char*)"nam", 3, 3, 30);
}

void ds_Dau_Rot(HocSinh_t hs[], HocSinh_t ds_dau[], HocSinh_t ds_rot[], int *soDau, int *soRot)
{
    int s1 = 0, s2 = 0;
    for (int i = 0; i < 10; i++)
    {
        if (hs[i].kq == dau)
        {
            ds_dau[s1] = hs[i];
            s1++;
        }
        else if (hs[i].kq == rot)
        {
            ds_rot[s2] = hs[i];
            s2++;
        }
    }

    *soDau = s1;
    *soRot = s2;
}

void menu()
{
    printf("\n\t\t Menu \r\n");
    printf("\t1. Nhap danh sach. \r\n");
    printf("\t2. Xuat danh sach sap xep theo thu tu giam dan. \r\n");
    printf("\t3. Xuat danh sach trung tuyen\r\n");
    printf("\t4. Luu file dau va rot. \r\n");
    printf("\t5. Ket thuc. \r\n");
}

void ghifile(HocSinh_t hs[], const char* soure, int size)
{
    FILE* f = fopen(soure, "w");
    for (int i = 0; i < size; i++)
    {
        fprintf(f, " %d - %s\t\t - %s \t - %d - %d - %.2f - %d\n", i + 1, hs[i].ten, hs[i].gt, hs[i].kv, hs[i].nh, hs[i].td, hs[i].kq);
    }
    fclose(f);
}

int main()
{
    HocSinh_t a[10] = { 0 };
    HocSinh_t ds_dau[10] = { 0 };
    HocSinh_t ds_rot[10] = { 0 };

    int soDau = 0;
    int soRot = 0;

    ds_init(a);         // dung cai nay de khoi nhap
    int check = 1;
    while (check)
    {
        menu();
        int key;
        printf("\t\tNhap chuc nang: ");
        scanf("%d", &key);
        system("cls");
        switch (key)
        {
        case 1:
            nhap_ds(a);
            printf("\t\t danh sach vua nhap la: \r\n");
            xuat_bang(a);
            break;
        case 2:
            printf("\r\n\t\t Danh sach sap xep theo thu tu giam dan la: \r\n");
            sapXep(a);
            xuat_bang(a);
            break;
        case 3:
            printf("\r\n\t\t Danh sach trung tuyen la: \r\n");
            dsTrungTuyen(a);
            break;
        case 4:
            ds_Dau_Rot(a, ds_dau, ds_rot, &soDau, &soRot);

            ghifile(ds_dau, "D:\\BaitapC\\dau.txt", soDau);
            ghifile(ds_rot, "D:\\BaitapC\\rot.txt", soRot);
            break;
        case 5:
            check = 0;
            break;
        default:
            break;
        }
    }
    
    printf("\t\t\tEnd");
    return 0;
}