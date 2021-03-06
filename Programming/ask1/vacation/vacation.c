/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.

 * File Name : vacation.c

 * Purpose : 1st exercise on Algorithms

 * Creation Date : 28-11-2011

 * Last Modified : Tue Dec 20 15:14:08 2011

 * Created By : Vasilis Gerakaris <vgerak@gmail.com>

 _._._._._._._._._._._._._._._._._._._._._.*/

#include <stdio.h>
#include <stdlib.h>

int n;
long long int *T;
long long int *left;
long long int *right;

int main()
{
    int i, j, piv, cleft, cright, result;
    int ltemp;

    scanf("%d %d", &n, &ltemp);
    T = calloc(n,sizeof(long long int));

    scanf("%lld", &T[0]);
    T[0] -= ltemp;
    piv = T[0];

    left = calloc(n,sizeof(long long int));
    right = calloc(n,sizeof(long long int));
    if ((left == NULL) || (right == NULL))
    {
        printf( "Out of memory" );
        return -1;
    }
    cleft = 1;
    left[0] = 0;                //Important! to have correct results
    j = 1;
    for (i=1; i<n; i++)
    {
        scanf("%lld", &T[i]);
        T[i] -= ltemp;
        T[i] = T[i] + T[i-1];  //Create prefix sums
        //Create LEFT list while reading
        //from input, to save a pass
        if (T[i] < piv)
        {
            cleft++;
            piv = T[i];
            left[j] = i;
            j++;
        }
    }
    //Create RIGHT list
    cright = 1;
    piv = T[n-1];
    right[0] = n-1;
    j = 1;
    for (i=(n-2); i>= 0; i--)
    {
        if (T[i] > piv)
        {
            cright++;
            piv = T[i];
            right[j] = i;
            j++;
        }
    }

    result = 0;
    j = (cleft-1);
    for (i=0; i<cright; i++)
    {
        if (T[right[i]]>=0)
        {
            if (right[i]>=result)
            {
                result = right[i] + 1;
            }
        }
        while (j>=0)
        {
            if (T[right[i]] - T[left[j]] >= 0)
            {
                if ((right[i] - left[j]) > result)
                {
                    result = right[i] - left[j];
                }
            }
            else
            {
                break;
            }
            j--;
        }
    }

    printf("%d\n",result);
    return 0;
}
