#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<stdbool.h>
#include<limits.h>

void swap(int*nums, int i, int j) {
   int t   = nums[i];
   nums[i] = nums[j];
   nums[j] = t;
}

int s, r;
int input[20000];
int ta  [100000], 
    tb  [100000];


void print_swap(int a, int b){
    ta[r] = a;
    tb[r++] = b;
    int d = (b+1-a)/2;
    for (int i = a; i < a + d; ++i)
        swap(input, i, i+d);
}
void make_dirty_swap(int i, int j, int s){
    if (i == j)
        return;
    if (j - i > s - j) {
        int l = j - i;
        if (l % 2 == 0) 
            l--;
        print_swap(j-l, j);
        j -= (l+1)/2;
    }
    print_swap(i, j + (j-i)-1);
}
int t_(){
    scanf("%d", &s);
    r = 0;
    for(int i = 0; i < s; ++i){
        scanf("%d", &input[i]);
        input[i] -= 1;
    }
    for(int i = 0; i < s; ++i){
        int m_i = i;
        while(input[m_i] != i)
            ++m_i;
        make_dirty_swap(i, m_i, s);
    }
    printf("%d\n", r);
    for(int i = 0; i < r; ++i){
        printf("%d %d\n", ta[i]+1, tb[i]+1);
    }
}
int main(){
    int d;
    scanf("%d", &d);
    while(d--)
        t_();
    return 0;
}
