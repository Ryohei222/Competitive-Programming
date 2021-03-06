#include <stdio.h>

void quickSort(long numbers[], long array_size);
void q_sort(long numbers[], long left, long right);

int main(){
    long N_product_cout;
    long K_takahashi_cout;
    scanf("%ld %ld", &N_product_cout, &K_takahashi_cout);
    long price[N_product_cout];
    int i = 0;
    for(i = 0; i < N_product_cout; i++){
        scanf("%ld", &price[i]);
    }
    quickSort(price, N_product_cout);
    long j = 0L;
    long need_price = 0L;
    for(i = 0; i < K_takahashi_cout; i++){
        need_price = need_price + price[i] + j;
        j++;
    }
    printf("%ld", need_price);
}

void quickSort(long numbers[], long array_size)
{
    q_sort(numbers, 0, array_size - 1);
}



void q_sort(long numbers[], long left, long right)
{
    long pivot, l_hold, r_hold;

    l_hold = left;
    r_hold = right;
    pivot = numbers[left];
    while (left < right)
    {
        while ((numbers[right] >= pivot) && (left < right))
            right--;
        if (left != right)
        {
            numbers[left] = numbers[right];
            left++;
        }
        while ((numbers[left] <= pivot) && (left < right))
            left++;
        if (left != right)
        {
            numbers[right] = numbers[left];
            right--;
        }
    }
    numbers[left] = pivot;
    pivot = left;
    left = l_hold;
    right = r_hold;
    if (left < pivot)
        q_sort(numbers, left, pivot-1);
    if (right > pivot)
        q_sort(numbers, pivot+1, right);
}
