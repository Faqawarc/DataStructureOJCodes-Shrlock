/**
 * wtf
 * not by me as well :(
 * accepted
 */
#include <stdio.h>
 
typedef struct {
    int Gold;
    int Medal;
    int Population;
    int id;
    double GoldAver;
    double MedalAver;
}Country;
 
void Gold_QuickSort(Country array[], int low, int high) {    
    int i = low;
    int j = high;
    if(i >= j) {
        return;
    }
    int temp = array[low].Gold;
    while(i != j) {
        while(array[j].Gold <= temp && i < j) {
            j--;
        }
        while(array[i].Gold >= temp && i < j) {
            i++;
        }
        if(i < j) {
            Country tempr = array[j];
            array[j] = array[i];
            array[i] = tempr;
        }
    }
    Country tempr = array[low];
    array[low] = array[i];
    array[i] = tempr;
    Gold_QuickSort(array, low, i - 1);
    Gold_QuickSort(array, i + 1, high);
}
 
void Medal_QuickSort(Country array[], int low, int high) {    
    int i = low;
    int j = high;
    if(i >= j) {
        return;
    }
    int temp = array[low].Medal;
    while(i != j) {
        while(array[j].Medal <= temp && i < j) {
            j--;
        }
        while(array[i].Medal >= temp && i < j) {
            i++;
        }
        if(i < j) {
            Country tempr = array[j];
            array[j] = array[i];
            array[i] = tempr;
 
        }
    }
    Country tempr = array[low];
    array[low] = array[i];
    array[i] = tempr;
    Medal_QuickSort(array, low, i - 1);
    Medal_QuickSort(array, i + 1, high);
}
 
void GP_QuickSort(Country array[], int low, int high) {    
    int i = low;
    int j = high;
    if(i >= j) {
        return;
    }
    double temp = array[low].GoldAver;
    while(i != j) {
        while(array[j].GoldAver <= temp && i < j) {
            j--;
        }
        while(array[i].GoldAver >= temp && i < j) {
            i++;
        }
        if(i < j) {
            Country tempr = array[j];
            array[j] = array[i];
            array[i] = tempr;
 
        }
    }
    Country tempr = array[low];
    array[low] = array[i];
    array[i] = tempr;
    GP_QuickSort(array, low, i - 1);
    GP_QuickSort(array, i + 1, high);
}
 
void MP_QuickSort(Country array[], int low, int high) {    
    int i = low;
    int j = high;
    if(i >= j) {
        return;
    }
    double temp = array[low].MedalAver;
    while(i != j) {
        while(array[j].MedalAver <= temp && i < j) {
            j--;
        }
        while(array[i].MedalAver  >= temp && i < j) {
            i++;
        }
        if(i < j) {
            Country tempr = array[j];
            array[j] = array[i];
            array[i] = tempr;
 
        }
    }
    Country tempr = array[low];
    array[low] = array[i];
    array[i] = tempr;
    MP_QuickSort(array, low, i - 1);
    MP_QuickSort(array, i + 1, high);
}
 
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    
    Country country[N];
    for(int i = 0;i<N;i++){
        country[i].id = i;
        scanf("%d %d %d",&country[i].Gold,&country[i].Medal,&country[i].Population);
        if(country[i].Population) {
            country[i].GoldAver = 1.0 * country[i].Gold / country[i].Population * 1.0;
            country[i].MedalAver = 1.0 * country[i].Medal / country[i].Population * 1.0;
        }
        else{
            country[i].GoldAver = 0;
            country[i].MedalAver = 0;
        }
    }
    int x;
    for (int i = 0; i < M; ++i) {
        scanf("%d",&x);
        int rank = 32767;
        int way = 0;
        Gold_QuickSort(country,0,N-1);
        for (int j = 0; j < N; ++j) {
            if(x == country[j].id){
                while(j!=0 && country[j].Gold == country[j-1].Gold)
                    j--;
                if(j<rank){
                    rank = j;
                    way = 1;
                }
                break;
            }
        }
 
        Medal_QuickSort(country,0,N-1);
        for (int j = 0; j < N; ++j) {
            if(x == country[j].id){
                while(j!=0 && country[j].Medal == country[j-1].Medal)
                    j--;
                if(j<rank){
                    rank = j;
                    way = 2;
                }
                break;
            }
        }
 
        GP_QuickSort(country,0,N-1);
        for (int j = 0; j < N; ++j) {
            if(x == country[j].id){
                while(j!=0 && country[j].GoldAver == country[j-1].GoldAver)
                    j--;
                if(j<rank){
                    rank = j;
                    way = 3;
                }
                break;
            }
        }
        MP_QuickSort(country,0,N-1);
        for (int j = 0; j < N; ++j) {
            if(x == country[j].id){
                while(j!=0 && country[j].MedalAver == country[j-1].MedalAver)
                    j--;
                if(j<rank){
                    rank = j;
                    way = 4;
                }
                break;
            }
        }
        if(i == M-1)
            printf("%d:%d",rank+1,way);
        else printf("%d:%d ",rank+1,way);
 
    }
    return 0;
}