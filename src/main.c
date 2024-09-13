#include <stdio.h>

void read_rii(double* a, size_t n){
    for(size_t i=0; i<n; i++){
        if(scanf("%lf", &a[i]) != 1){
            return;
        }
    }    
    return;
}

void read_rii_from_file(double* a, size_t n, FILE* file){
    int num;
    if(fscanf(file, "%d", &num) != 1){
        return;
    }
    for(size_t i=0; i<n; i++){
        if(fscanf(file, "%lf", &a[i]) != 1){
            return;
        }
    }    
    return;
}

void read_first_line(int* a, FILE* file){
    if(fscanf(file, "%d", a) != 1){
        return;
    }
    return;
}

int main(){
    char *filename = "input.txt";
    FILE *file = fopen(filename, "r");
    int num;
    read_first_line(&num, file);
    fclose(file);

    const int x = 1;

    file=fopen(filename, "r");
    double a[num];
    read_rii_from_file(a, num, file);
    fclose(file);

    return 0;
}
