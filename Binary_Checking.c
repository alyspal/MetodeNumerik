#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#define max 9

int fraction[max],integer[max];

int check_binary(double *num)
{
    double copy, temp = 0;
    copy = *num;

    while (copy != 0)
    {
        temp = floor(fmod(copy,10));
        if ((temp == 0) || (temp == 1))
        {
            copy = floor(copy / 10);
        }
        else
        {
            printf("Nilai masukan bukan merupakan angka biner\n");
            return 0;
        }
    }

    copy = *num;
    for(int i=0; i<max;i++)
    {
        copy *=10;
        temp = floor(fmod(copy,10));
        if(temp==1)
        {
            copy -=1;

        }
        else if(temp!=0)
        {
            printf("Nilai masukan bukan merupakan angka biner\n");
            return 0;
        }
    }
    return 1;
}

void dectobin()
{
    float num,f;
    int i,cnum,tag;
    printf("Masukkan bilangan desimal : ");
    scanf("%f",&num);
    printf("\n");
    f=num-(int)num;
    for(i=0; i<max; i++)
    {
        f=f-(int)f;
        fraction[i]=(int)(f*2);
        f*=2;
    }

    cnum=(int)num;
    for(i=max-1; i>=0; i--)
    {
        if(cnum%2==0)
        {
            integer[i]=0;
        }
        else
            integer[i]=1;
        cnum/=2;
    }

    printf("Konversi binernya = ");
    tag=0;

    for(i=0; i<max; i++)
    {
        if(integer[i]||tag)
        {
            tag=1;
            printf("%d",integer[i]);
        }
    }
    printf(".");

    for(i=0; i<7; i++)
        printf("%d",fraction[i]);

    printf("\n");
}

void bintodec()
{
    double num,fnum,result=0;
    long inum,i=0,a=0;
    int cb,temp;
    printf("Masukkan bilangan biner : ");
    scanf("%lf",&num);
    cb = check_binary(&num);
    printf("%lf\n", num);

    if (cb == 1)
    {
        inum=num;
        fnum=num-floor(num);
        printf("%ld\t%lf\n",inum,fnum);

        while(inum)
        {
            result+=(inum%10)*pow(2,i++);
            inum/=10;
        }

        for(i=0; i<max; i++)
        {
            fnum*=10;
            a--;

            if (roundl(fnum)>=1)
            //Pada low-level assembly proses perkalian fnum*10 belum selesai namun fnum telah dibandingkan dengan 1 sehingga hasil dari statement if barupa false
            //Oleh karena itu, pada prses selanjutnya, nilai fnum meningkat menjadi 10

            //temp=floor(fnum);
            //if(temp==1)
            {
                printf("fnum %lf\n",fnum);
                fnum-=1;
                result+=pow(2,a);
            }
        }
        printf("Konversi desimal = %lf\n",result);
    }

}

int main()
{
    int i,cnum,ch;
    float num,f;

    while(1)
    {
        printf("Menu Konversi: \n");
        printf("1. Desimal ke Biner\n");
        printf("2. Biner ke Desimal\n");
        printf("3. Keluar\n\n");
        printf("Pilih menu : ");
        scanf("%d",&ch);
        printf("\n");
        switch(ch)
        {
        case 1:
            dectobin();
            break;
        case 2:
            bintodec();
            break;
        case 3:
            exit(1);
        default:
            printf("Menu pilihan tidak ada\n");
        }
        printf("\nTekan enter untuk menampilkan menu\n");
        getch();
    }

    getch();
    return 1;
}
