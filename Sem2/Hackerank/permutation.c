#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
test case 1
7
100 100 50 40 40 20 10
4
5 25 50 120

test case 2
6
100 90 90 80 75 60
5
50 65 77 90 102
*/
int *climbingLeaderboard(int ranked_count, int *ranked, int player_count, int *player)
{
    int *rank_array;
    int rank,lowest;
    rank_array = (int *)malloc(ranked_count * sizeof(int));
    for (int i = 0; i < player_count; i++)
    {
        rank=2;
        lowest=rank;
        if (ranked[0] < player[i])
        {
            rank_array[i] = 1;
        }
        else
        {
            for (int j = 1; j < ranked_count - 1; j++)
            {
                if (ranked[j] == ranked[j + 1])
                {
                    continue;
                }
                else
                {
                    if (ranked[j] > player[i] && player[i] >= ranked[j + 1])
                    {
                        rank_array[i] = lowest;
                        break;
                    }
                    lowest++;
                }
            }
            if(ranked[ranked_count-1] > player[i]){
                rank_array[i]=lowest;
            }
        }
    }
    return rank_array;
}

int main()
{
    int rank[6] = {100,90,90,80,75,60};
    int player[5] = {50,65,77,90,102};
    int *k = climbingLeaderboard(6, rank, 5, player);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", k[i]);
    }

    return 0;
}