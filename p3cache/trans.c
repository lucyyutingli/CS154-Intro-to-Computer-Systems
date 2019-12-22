/*
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/*
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded.
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, x, y, tmp, tmp1, w, z, flag;
    if ((M == 32) && (N == 64)) {
    for (x = 0; x < N; x+=8) {
        for (y = 0; y < M; y+=4) {
            for (i = x; i < (x+8); i++) {
                for (j = y; j < (y+4); j++) {
                    tmp = A[i][j];
                    B[j][i] = tmp;
                }
            }
        }
    }
    } else if ((M == 32) && (N == 32)) {
    for (y = 0; y < M; y+=8) {
        for (x = 0; x < N; x+=8) {
            if (x == y) {
            for (i = x; i < (x+8); i++) {
                for (j = y; j < (y+8); j++) {
                    if (i == j) {
                        tmp1 = A[i][j]; 
                    } else {
                    tmp = A[i][j];
                    B[j][i] = tmp;
                    }
                }
                    B[i][i] = tmp1;
            }
        } else {
            for (i = x; i < (x+8); i++) {
                for (j = y; j < (y+8); j++) {
                    tmp = A[i][j];
                    B[j][i] = tmp;
                }
            }
        }
    }
}
    } else if ((M == 64) && (N == 64)) {
    for (y = 0; y < M; y+=4) {
        for (x = 0; x < N; x+=4) {
            for (i = x; i < (x+4); i++) {
                for (j = y; j < (y+4); j++) {
                    if ((i == j) || (i == (j+4)) || (j == (i+4))) {
                        w = i;
                        z = j;
                        tmp1 = A[i][j];
                        flag = 1;
                    } else {
                    tmp = A[i][j];
                    B[j][i] = tmp;
                    }
                }
                if (flag == 1) {
                    B[z][w] = tmp1;
                    flag = 0;
                }
            }
        }
    }
}
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
char trans_eight[] = "Transpose by blocks of 8";
void trans_by_eight(int M, int N, int A[N][M], int B[M][N]) {
    int i, j, x, y, tmp, tmp1;
    for (y = 0; y < M; y+=8) {
        for (x = 0; x < N; x+=8) {
            if (x == y) {
            for (i = x; i < (x+8); i++) {
                for (j = y; j < (y+8); j++) {
                    if (i == j) {
                        tmp1 = A[i][j]; 
                    } else {
                    tmp = A[i][j];
                    B[j][i] = tmp;
                    }
                }
                    B[i][i] = tmp1;
            }
        } else {
            for (i = x; i < (x+8); i++) {
                for (j = y; j < (y+8); j++) {
                    tmp = A[i][j];
                    B[j][i] = tmp;
                }
            }
        }
    }
}
}

char trans_eightfour[] = "Transpose by blocks of 8x4";
void trans_by_eight_four(int M, int N, int A[N][M], int B[M][N]) {
    int i, j, x, y, tmp;
    for (x = 0; x < N; x+=8) {
        for (y = 0; y < M; y+=4) {
            for (i = x; i < (x+8); i++) {
                for (j = y; j < (y+4); j++) {
                    tmp = A[i][j];
                    B[j][i] = tmp;
                }
            }
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
    registerTransFunction(trans_by_eight, trans_eight);
    registerTransFunction(trans_by_eight_four, trans_eightfour);

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

