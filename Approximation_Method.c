#include <stdio.h>
#include <math.h>

int main()
{
    int ch;
    while (1)
    {
        printf("Pilih Metode : \n");
        printf("1. Biseksi\n");
        printf("2. Regula Falsi\n");
        printf("3. Iterasi Sederhana\n");
        printf("4. Iterasi Aitken\n");
        printf("5. Newton Raphson\n");
        printf("6. Keluar\n\n");
        printf("Pilih menu : ");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1:
            biseksi();
            break;
        case 2:
            regulaFalsi();
            break;
        case 3:
            iterasiSederhana();
            break;
        case 4:
            aitken();
            break;
        case 5:
            newtonRhapson();
            break;
        case 6:
            exit(1);
        default:
            printf("Menu pilihan tidak disediakan\n");
        }
        printf("\nTekan tombol apapun untuk kembali ke menu\n");
        getch();
    }

    getch();
    return 1;
}

int newtonRhapson()
{
    float x, fx, fxx;
    int n, t, iterasi = 0;

    printf("Masukan pangkat persamaan polinomial tertinggi : ");
    scanf("%d", &n);

    float arrx[n + 1], arry[n];

    for (int i = n; i >= 0; i--)
    {
        printf("Masukan nilai untuk koefisien ke-x^%d : ", i);
        scanf("%f", &arrx[i]);
    }

    printf("Masukan tebakan nilai x : ");
    scanf("%f", &x);

    printf("Masukan tingkat ketelitian : ");
    scanf("%d", &t);

    // Turunan
    for (int i = 0; i < n; i++)
    {
        arry[i] = (i + 1) * arrx[i + 1];
    }

    while (1)
    {
        iterasi++;
        fx = 0;
        fxx = 0;
        for (int i = 0; i < n + 1; i++)
        {
            fx = fx + arrx[i] * powf(x, i);
        }
        for (int i = 0; i < n; i++)
        {
            fxx = fxx + arry[i] * powf(x, i);
        }
        printf("fx: %f , fxx: %f\n", fx, fxx);

        x = x - (fx / fxx);
        printf("x%d : %f\n", iterasi, x);
        if (fabs(fx / fxx) < powf(10, -t))
        {
            break;
        }
    }
    printf("Nilai x yang diperoleh adalah : %f", x);
    return 1;
}

int iterasiSederhana()
{
    float x, xNew, akar;
    int n, t, iterasi = 0;

    printf("Masukan pangkat persamaan polinomial tertinggi : ");
    scanf("%d", &n);
    akar = powf(n, -1);

    float arrx[n + 1], arry[n];

    for (int i = n; i >= 0; i--)
    {
        printf("Masukan nilai untuk koefisien ke-x^%d : ", i);
        scanf("%f", &arrx[i]);
    }

    printf("Masukan tebakan nilai x : ");
    scanf("%f", &x);

    printf("Masukan tingkat ketelitian : ");
    scanf("%d", &t);

    for (int i = 0; i < n; i++)
    {
        arry[i] = -1 * arrx[i];
    }

    while (1)
    {
        iterasi++;
        xNew = 0;
        for (int i = 0; i < n; i++)
        {
            xNew = xNew + arry[i] * powf(x, i);
        }

        xNew = powf(xNew / arrx[n], akar);
        printf("x%d : %f\n", iterasi, xNew);

        if (fabs(xNew - x) < powf(10, -t))
        {
            break;
        }

        x = xNew;
    }
    printf("Nilai x yang diperoleh adalah : %f", xNew);
    return 1;
}

int regulaFalsi()
{
    float a, b, x, fa, fb, fx;
    int n, t, iterasi = 0;
    printf("Masukan pangkat persamaan polinomial tertinggi : ");
    scanf("%d", &n);
    float arrx[n + 1];

    for (int i = n; i >= 0; i--)
    {
        printf("Masukan nilai untuk koefisien ke-x^%d : ", i);
        scanf("%f", &arrx[i]);
    }

    printf("Masukan nilai batas bawah : ");
    scanf("%f", &a);

    printf("Masukan nilai batas atas : ");
    scanf("%f", &b);

    printf("Masukan tingkat ketelitian : ");
    scanf("%d", &t);

    for (int i = 0; i < n + 1; i++)
    {
        fa = fa + arrx[i] * powf(a, i);
        fb = fb + arrx[i] * powf(b, i);
    }

    if (fa * fb > 0)
    {
        printf("Nilai akar tidak terdapat pada rentang nilai batas bawah dan atas yang dimasukkan \natau bentuk grafik tidak dapat dilakukan menggunakan metode biseksi");
        return 1;
    }

    while (1)
    {
        iterasi++;

        x = 0;
        fa = 0;
        fb = 0;
        fx = 0;
        for (int i = 0; i < n + 1; i++)
        {
            fa = fa + arrx[i] * powf(a, i);
            fb = fb + arrx[i] * powf(b, i);
        }

        x = ((a * fb) - (b * fa)) / (fb - fa);
        for (int i = 0; i < n + 1; i++)
        {
            fx = fx + arrx[i] * powf(x, i);
        }

        printf("x%d : %f\n", iterasi, x);

        if ((fa * fx) < 0)
        {
            if (fabs(b - x) < powf(10, -t))
            {
                break;
            }
            b = x;
        }
        else if ((fb * fx) < 0)
        {
            if (fabs(a - x) < powf(10, -t))
            {
                break;
            }
            a = x;
        }
    }

    printf("Nilai x yang diperoleh adalah : %f", x);

    return 1;
}

int biseksi()
{
    float a, b, x, fa, fb, fx;
    int n, t, iterasi = 0;
    printf("Masukan pangkat persamaan polinomial tertinggi : ");
    scanf("%d", &n);
    float arrx[n + 1];

    for (int i = n; i >= 0; i--)
    {
        printf("Masukan nilai untuk koefisien ke-x^%d : ", i);
        scanf("%f", &arrx[i]);
    }

    printf("Masukan nilai batas bawah : ");
    scanf("%f", &a);

    printf("Masukan nilai batas atas : ");
    scanf("%f", &b);

    printf("Masukan tingkat ketelitian : ");
    scanf("%d", &t);

    for (int i = 0; i < n + 1; i++)
    {
        fa = fa + arrx[i] * powf(a, i);
        fb = fb + arrx[i] * powf(b, i);
    }

    if (fa * fb > 0)
    {
        printf("Nilai akar tidak terdapat pada rentang nilai batas bawah dan atas yang dimasukkan \natau bentuk grafik tidak dapat dilakukan menggunakan metode biseksi");
        return 1;
    }

    while (1)
    {
        iterasi++;
        x = (a + b) / 2;
        fa = 0;
        fb = 0;
        fx = 0;
        for (int i = 0; i < n + 1; i++)
        {
            fa = fa + arrx[i] * powf(a, i);
            fb = fb + arrx[i] * powf(b, i);
            fx = fx + arrx[i] * powf(x, i);
        }
        printf("x%d : %f\n", iterasi, x);

        if ((fa * fx) < 0)
        {
            if (fabs(b - x) < powf(10, -t))
            {
                break;
            }
            b = x;
        }
        else if ((fb * fx) < 0)
        {
            if (fabs(a - x) < powf(10, -t))
            {
                break;
            }
            a = x;
        }
    }

    printf("Nilai x yang diperoleh adalah : %f", x);

    return 1;
}

int aitken()
{
    float akar, x0, x1, x2, xNew, dx0, dx1, d2xn0;
    int n, t, iterasi = 0;

    printf("Masukan pangkat persamaan polinomial tertinggi : ");
    scanf("%d", &n);
    akar = powf(n, -1);

    float arrx[n + 1], arry[n];

    for (int i = n; i >= 0; i--)
    {
        printf("Masukan nilai untuk koefisien ke-x^%d : ", i);
        scanf("%f", &arrx[i]);
    }

    printf("Masukan tebakan nilai x :");
    scanf("%f", &x0);

    printf("Masukan tingkat ketelitian :");
    scanf("%d", &t);

    for (int i = 0; i < n; i++)
    {
        arry[i] = -1 * arrx[i];
    }

    while (1)
    {
        iterasi++;

        x1 = 0;
        for (int i = 0; i < n; i++)
        {
            x1 = x1 + arry[i] * powf(x0, i);
        }
        x1 = powf(x1 / arrx[n], akar);

        dx0 = fabs(x1 - x0);

        x2 = 0;
        for (int i = 0; i < n; i++)
        {
            x2 = x2 + arry[i] * powf(x1, i);
        }
        x2 = powf(x2 / arrx[n], akar);

        dx1 = fabs(x2 - x1);

        d2xn0 = x2 - (2 * x1) + x0;

        xNew = x2 - (powf(dx1, 2) / d2xn0);

        printf("x%d : %f\n", iterasi, xNew);

        if (fabs((powf(dx1, 2) / d2xn0)) < powf(10, -t))
        {
            break;
        }

        x0 = xNew;
    }
    printf("Nilai x yang diperoleh adalah : %f", xNew);
    return 1;
}
