#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(x,y,t) ( (t)=(x), (x)=(y), (y)=(t))
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"

int n = 100;
int compare_count = 0;
int swap_count = 0;

int fixed[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int partition(int list[], int left, int right)
{
    int pivot ,temp;
    int low, high;

    low = left;
    high = right + 1;
    pivot = list[left];
    do {
        do{
             low++;
             compare_count++;
        }while (list[low] <pivot);
        do{
             high--;
             compare_count++;
        }while(list[high]>pivot);
        if (low<high)
        {
            SWAP(list[low], list[high], temp);
            swap_count++;
        }
    }while (low<high);
    SWAP(list[left], list[high], temp);
    return high;
}

void quick_sort(int list[], int left, int right)
{
    if(left < right){
        int q = partition(list, left, right);
        quick_sort(list, left, q- 1 );
        quick_sort(list, q + 1, right);
    }
}




/*
    for random
*/
int main(void) {
    int data[n];
	struct timespec begin, end;
	double tmpValue = 0.0;

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        data[i] = rand()%100;
        //printf("%d ", data[i]);
    }
    printf("-----sort------\n");
	clock_gettime(CLOCK_MONOTONIC, &begin);
	for (int i= 0; i < 1000000; i++) {
		tmpValue += i;
	}
    quick_sort(data, 0, n-1);
	clock_gettime(CLOCK_MONOTONIC, &end);
	for (int i= 0; i < 1000000; i++) {
		tmpValue += i;
	}
    for (int i = 0; i< n; i++)
        printf("%d ", data[i]);
	printf(ANSI_COLOR_BLUE "\ncompare count = %d\n", compare_count);
    printf(ANSI_COLOR_GREEN "swap count = %d\n", swap_count);
	long time = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec);
	printf(ANSI_COLOR_YELLOW "Time(Second): %lf\n", (double)time/1000000000);
    return 0;
}

/* 
    for fixed
*/
// int main(void) {
//     int data[20];
// 	struct timespec begin, end;
// 	double tmpValue = 0.0;

//     srand(time(NULL));
//     for (int i = 0; i < 10; i++)
//     {
//         //fixed[i] = rand()%100 + 1;
//         printf("%d ", fixed[i]);
//     }
//     printf("\n-----sort------\n");
// 	clock_gettime(CLOCK_MONOTONIC, &begin);
// 	for (int i= 0; i < 1000000; i++) {
// 		tmpValue += i;
// 	}
//     quick_sort(fixed, 0, 9);
// 	clock_gettime(CLOCK_MONOTONIC, &end);
// 	for (int i= 0; i < 1000000; i++) {
// 		tmpValue += i;
// 	}
//     for (int i = 0; i< 10; i++)
//         printf("%d ", fixed[i]);
// 	//printf("\ncount = %d\n", count);
// 	long time = (end.tv_sec - begin.tv_sec) + (end.tv_nsec - begin.tv_nsec);
// 	printf("\nTime(Second): %lf\n", (double)time/1000000000);
//     return 0;
// }