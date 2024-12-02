#include <stdio.h>

#define printArray(nums, numsSize)                                                                                     \
    {                                                                                                                  \
        int i = 0;                                                                                                     \
        for (; i < numsSize; i++)                                                                                      \
        {                                                                                                              \
            printf("%i ", nums[i]);                                                                                    \
        }                                                                                                              \
        printf("\n");                                                                                                  \
    }

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int low, int high)
{

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int *arr, int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

//
// ░▒▓██████████████▓▒░   ░▒▓██████▓▒░  ░▒▓█▓▒░ ░▒▓███████▓▒░
// ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░
// ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░
// ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓████████▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░
// ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░
// ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░
// ░▒▓█▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░ ░▒▓█▓▒░░▒▓█▓▒░
//

int largestValsFromLabels(int *values, int valuesSize, int *labels, int labelsSize, int numWanted, int useLimit)
{
    int maxVal = 0;

    for (int i = 0; i < valuesSize; i++)
    {
        maxVal = (labels[i] > maxVal) ? labels[i] : maxVal;
    }
    int size = (maxVal + 1) * labelsSize;

    int array[size] = {};

    for (int i = 0; i < labelsSize; i++)
    {
        for (int j = 0; j < labelsSize; j++)
        {
            if (array[(labels[i] * labelsSize) + j] == 0)
            {
                array[(labels[i] * labelsSize) + j] = values[i];
                break;
            }
        }
    }
    for (int i = 0; i < labelsSize; i++)
    {
        quickSort(&array[labels[i] * labelsSize], 0, labelsSize - 1);
    }
    printArray(array, maxVal * labelsSize);

    int ind = 0;
    int maxNumArray[useLimit * valuesSize] = {};

    for (int i = 0; i < labelsSize; i++)
    {
        for (int j = valuesSize - 1; j >= 0 && j >= valuesSize - useLimit; j--)
        {
            if (((i * valuesSize) + j) < size)
            {
                maxNumArray[ind++] = array[(i * valuesSize) + j];
            }
        }
    }
    printArray(maxNumArray, useLimit * valuesSize);
    quickSort(&maxNumArray[0], 0, (useLimit * valuesSize) - 1);
    printArray(maxNumArray, useLimit * valuesSize);
    int ans = 0;
    int numWant = numWanted;
    for (int i = (useLimit * valuesSize) - 1; i >= 0 && numWant > 0; i--)
    {
        ans += maxNumArray[i];
        numWant--;
    }
    return ans;
}

int main()
{
    int values[] = {5, 4, 3, 2, 1};
    int labels[] = {1, 1, 2, 2, 3};

    int numWanted = 3;
    int useLimit = 1;

    int values1[] = {9, 8, 8, 7, 6};
    int labels1[] = {0, 0, 0, 1, 1};

    int numWanted1 = 3;
    int useLimit1 = 1;

    // int ans = largestValsFromLabels(values, 5, labels, 5, numWanted, useLimit);
    //  int ans = largestValsFromLabels(values1, 5, labels1, 5, numWanted1, useLimit1);
    printf("ans :%i\n", ans);
}
