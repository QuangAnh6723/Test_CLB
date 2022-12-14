//Tim thu dua tren thuat toan Doomsday
#include<stdio.h>

typedef enum {
    KhongNhuan, Nhuan
}nam_Nhuan;

typedef enum 
{
    KhongHopLe = 0,
    HopLe = 1,
} KiemTra;

nam_Nhuan check_namNhuan(int nam)
{
    if((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0))
    {
        return Nhuan;
    }
    return KhongNhuan;
}

KiemTra check_date(int ngay, int thang, int nam)
{
    if(thang < 1 && thang > 12){
        return KhongHopLe;
    }
    if (ngay < 0)
    {
        return KhongHopLe;
    }
    switch (thang)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if(ngay > 31){
            return KhongHopLe;
        }
        break;
    case 2:
        if(check_namNhuan(nam) == Nhuan && (ngay > 29)){
            return KhongHopLe;
        } 
        else if(check_namNhuan(nam) != Nhuan && (ngay > 28))
        {
            return KhongHopLe;
        }
    case 4:
    case 6:
    case 9:
    case 11:
        if(ngay > 30){
            return KhongHopLe;
        }
        break;
    default:
        return KhongHopLe;
        break;
    }
    return HopLe;  
}


int main()
{
    int ngay, thang, nam;
    do{
        printf("Nhap Ngay: ");
        scanf("%d", &ngay);
        printf("Nhap Thang: ");
        scanf("%d", &thang);
        printf("Nhap Nam: ");
        scanf("%d", &nam);
        if(check_date(ngay, thang, nam) == HopLe)
        {
            break;
        }
        printf("\t\tNhap lai!!!\r\n");
    }
    while (1);

    int temp = nam / 100;
    int AD;
    switch (temp)
    {
    case 0:
        AD = 3;
        break;
    case 1:
        AD = 0;
    case 2:
        AD = 6;
    case 3:
        AD = 4;
    default:
        break;
    }

    int a, b, c, s, t, thu;
    temp = nam % 100;
    a = temp / 12;
    b = temp % 12;
    c = b / 4;
    s = a + b + c;
    t = s % 7;
    thu = t + AD;

    int MD;
    switch (thang)
    {
    case 1:
        if(check_namNhuan(nam) == Nhuan)
        {
            MD = 4;
        }
        else 
        {
            MD = 3;
        }
        break;
    case 2:
        if(check_namNhuan(nam) == Nhuan)
        {
            MD = 29;
        }
        else 
        {
            MD = 28;
        }
        break;
    case 3:
        MD = 0;
        break;
    case 4:
        MD = 4;
        break;
    case 5:
        MD = 9;
        break;
    case 6:
        MD = 6;
        break;
    case 7:
        MD = 11;
        break;
    case 8:
        MD = 8;
        break;
    case 9:
        MD = 5;
        break;
    case 10:
        MD = 10;
        break;
    case 11:
        MD = 7;
        break;
    case 12:
        MD = 12;
        break;
    default:
        break;
    }

    thu = thu + ngay - MD;
    while (thu < 0)
    {
        thu = thu + 7;
    }
    thu = thu % 7 - 1;

    switch (thu)
    {
    case 0:
        printf("Ngay %d / %d / %d la Thu 7.\r\n", ngay, thang, nam);
        break;
    case 1:
        printf("Ngay %d / %d / %d la Chu nhat.\r\n", ngay, thang, nam);
        break;
    case 2:
        printf("Ngay %d / %d / %d la Thu 2.\r\n", ngay, thang, nam);
        break;
    case 3:
        printf("Ngay %d / %d / %d la Thu 3.\r\n", ngay, thang, nam);
        break;
    case 4:
        printf("Ngay %d / %d / %d la Thu 4.\r\n", ngay, thang, nam);
        break;
    case 5:
        printf("Ngay %d / %d / %d la Thu 5.\r\n", ngay, thang, nam);
        break;
    case 6:
        printf("Ngay %d / %d / %d la Thu 6.\r\n", ngay, thang, nam);
        break;
    default:
        break;
    }


    return 0;
}



