
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

char transpose_submit_desc[] = "Transpose submission";
//cache是s=5,E=1,b=5的规格，每个块是32（2的5次方）个字节，可以存储8个int值，
void transpose_submit(int M, int N, int** A, int** B)
{
    /********* Begin *********/
    if (M == 32 && N == 32)
    {
        int t1, t2, t3, t4, t5, t6, t7, t8;
        for (int a1 = 0; a1 < 32; a1 += 8)
        {
            for (int a2 = 0; a2 < 32; a2 += 8)
            {
                for (int i = 0; i < 8; i++)
                {
                    t1 = A[a1 + i][a2];
                    t2 = A[a1 + i][a2 + 1];
                    t3 = A[a1 + i][a2 + 2];
                    t4 = A[a1 + i][a2 + 3]; 
                    t5 = A[a1 + i][a2 + 4];
                    t6 = A[a1 + i][a2 + 5];
                    t7 = A[a1 + i][a2 + 6];
                    t8 = A[a1 + i][a2 + 7];
                    B[a2][a1 + i] = t1;
                    B[a2 + 1][a1 + i] = t2;
                    B[a2 + 2][a1 + i] = t3;
                    B[a2 + 3][a1 + i] = t4;
                    B[a2 + 4] [a1 + i]= t5;
                    B[a2 + 5][a1 + i] = t6;
                    B[a2 + 6][a1 + i] = t7;
                    B[a2 + 7][a1 + i] = t8;


                }
            }
        }
    }
    else if (M == 64 && N == 64)
    {
        int t1, t2, t3, t4;
        for (int a1 = 0; a1 < 64; a1 += 4)
        {
            for (int a2 = 0; a2 < 64; a2 += 4)
            {
                for (int i = 0; i < 4; i++)
                {
                    t1 = A[a1 + i][a2];
                    t2 = A[a1 + i][a2 + 1];
                    t3 = A[a1 + i][a2 + 2];
                    t4 = A[a1 + i][a2 + 3];
                    B[a2][a1 + i] = t1;
                    B[a2 + 1][a1 + i] = t2;
                    B[a2 + 2][a1 + i] = t3;
                    B[a2 + 3][a1 + i] = t4;
                  
                }
            }
        }
    }

    if (M == 61)
    {
        int t1, t2, t3, t4;
        int max1 = M / 4 * 4;
        int max2 = N / 4 * 4;
        for (int a1 = 0; a1 < max1; a1 += 4)
        {
            for (int a2 = 0; a2 < max2; a2 += 4)
            {
                for (int i = 0; i < 4; i++)
                {
                    t1 = A[a1 + i][a2];
                    t2 = A[a1 + i][a2 + 1];
                    t3 = A[a1 + i][a2 + 2];
                    t4 = A[a1 + i][a2 + 3];
                    B[a2][a1 + i] = t1;
                    B[a2 + 1][a1 + i] = t2;
                    B[a2 + 2][a1 + i] = t3;
                    B[a2 + 3][a1 + i] = t4;
                }
            }
        }
        for (int a1 = max1; a1 < M; a1++)
        {
            for (int a2 = 0; a2 < max2; a2++)
            {
                t1 = A[a1][a2];
                B[a2][a1] = t1;
            }
        }
        for (int a1 =0; a1 <  max1; a1++)
        {
            for (int a2 = max2; a2 < N; a2++)
            {
                t1 = A[a1][a2];
                B[a2][a1] = t1;
            }
        }
        for (int a1 = max1; a1 < M; a1++)
        {
            for (int a2 = max2; a2 < N; a2++)
            {
                t1 = A[a1][a2];
                B[a2][a1] = t1;
            }
        }
    }
    /********* End *********/
}

/*
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started.
 */

 /*
  * trans - A simple baseline transpose function, not optimized for the cache.
  */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc);

}

/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

