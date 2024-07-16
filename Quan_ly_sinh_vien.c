#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char ID[10];
    float Toan,Van,Anh;
    float dtb;
}SinhVien;

 
int main()
 {
    SinhVien a[100];
    int n;
    while(n <= 0)
    {
        printf("Nhap so luong sinh vien: ");
        scanf("%d", &n);
    }
    
    for(int i=0; i<n; i++ )
    {
        printf("------------------");
        printf("\nNhap thong tin sinh vien %d", i+1);
        printf("\nNhap ID: ");
        scanf("%s", a[i].ID);
        do
        {
            printf("Nhap diem Toan Van Anh: ");
            scanf("%f %f %f", & a[i].Toan, &a[i].Van, &a[i].Anh); 
        } while (((a[i].Toan ) > 10) || ((a[i].Van ) > 10)  || (((a[i].Anh ) > 10)));  
     }

    for(int i=0; i<n; i++)
    {
        a[i].dtb = (a[i].Toan + a[i].Van + a[i].Anh)/3;
    }
    int hsxs =0, hsg = 0, hsk=0 ;
    
    for(int i=0; i<n; i++)
    {
        printf("\n----------------\n");
        printf("Thong tin sinh vien %d\n", i+1);
        printf("ID = %s\t\tDiem Toan = %.2f\t\tDiem Van = %.2f\t\tDiem Anh = %.2f\t\tDiem TB =%.2f\t\tXep loai: ",a[i].ID, a[i].Toan, a[i].Van, a[i].Anh, a[i].dtb);
        if( (a[i].dtb > 8) && ((a[i].Toan) >= 7) && ((a[i].Van) >= 7) && ((a[i].Anh) >= 7))
        {
            printf("Xuat sac");
            hsxs++;
        }
        
        else if ( (7 <= (a[i].dtb) <= 8) && ((a[i].Toan) >= 5) && ((a[i].Van) >= 5) && ((a[i].Anh) >= 5) )
        {
            printf("Gioi");
            hsg++;
        }
        
        else
        {
            printf("Kha");
            hsk++;
        }
        
    }
        printf("\n-----------------");
        printf("\n Tong so hsxs: %d", hsxs);
        printf("\n Tong so hsg: %d", hsg);
        printf("\n Tong so hsk: %d", hsk);
    return 0;

 }