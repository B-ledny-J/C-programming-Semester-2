/*
* @file Lab_3_4.c
* @author Дарчук Г.С., 515i
* @date 24.02.2025
* @brief Лабораторна робота №3, варіант 22
*
* Використання масивів. Завдання 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4 /* кількість мастей */
#define NUM_RANKS 13 /* кількість рангів */

int any_three(int arr[NUM_SUITS][NUM_RANKS])
{
    int count = 0;
    for (int j = 0; j < NUM_RANKS; j++)
    {
        for (int i = 0; i < NUM_SUITS; i++) if (arr[i][j] == 1) count++;
        if (count >= 3) return 1;
        count = 0;
    }
    return 0;
}

void  arrayToNull(int arr[NUM_SUITS][NUM_RANKS])
{
    for (int i = 0; i < NUM_SUITS; i++) {
        for (int j = 0; j < NUM_RANKS; j++) {
            arr[i][j] = 0;
        }
    }
}

int main()
{
    /* карти на руках */
    int player_hand[NUM_SUITS][NUM_RANKS], in_hand[NUM_SUITS][NUM_RANKS] = {0};
    int num_players = 3, num_cards = 6, rank, suit;
    const char rank_code[] = {'2','3','4','5','6','7','8','9','t','j','q','k','a'};
    const char suit_code[] = {'c','d','h','s'};
    /* ініціалізация генератора випадкових чисел */
    srand(time(0));
    for (int i = 0; i < num_players; i++)
    {
        printf("Картки гравця %d:", i + 1);
        for (int j = 0; j < num_cards;)
        {
            /* обрання випадкової масті */
            suit = rand() % NUM_SUITS;
            /* обрання випадкового рангу */
            rank = rand() % NUM_RANKS;
            if (!in_hand[suit][rank])
            {
                in_hand[suit][rank] = 1; /* карта обрана */
                player_hand[suit][rank] = 1;
                printf(" %c%c", rank_code[rank],suit_code[suit]);
                j++;
            }
        }
        printf("\n");
        if (any_three(player_hand)) printf("У гравця %d є комбінація \"трійка\"\n", i + 1);
        else printf("У гравця %d немає комбінації \"трійка\"\n", i + 1);
        // обнулення масиву
        arrayToNull(player_hand);
    }
    return 0;
}