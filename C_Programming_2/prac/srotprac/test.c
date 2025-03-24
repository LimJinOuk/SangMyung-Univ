#include <stdio.h>
#include <string.h>

// 문자열 비교 함수
int compare(const char *a, const char *b) {
    return strcmp(a, b);
}

//정렬 함수
void sort(char *arr[], int n) {
    for (int i = 1; i < n; i++) {
        char *key = arr[i];
        int j = i - 1;
        while (j >= 0 && compare(arr[j], key) > 0) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char *argv[]) {
    //정렬로 문자열 정렬
    sort(&argv[1], argc - 1);

    //-r옵션 확인
    if(strcmp(argv[1] , "-r") == 0)
    {for(int i = argc - 1 ; i > 1 ; i--){printf("%s\n" , argv[i]);}}

    // 정렬된 문자열 출력
    else {for(int i = 1; i < argc; i++) {printf("%s\n", argv[i]);}}


    return 0;
}
