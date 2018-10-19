#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

void insertion_sort(unsigned *array, int size){

    int i, j;
    unsigned value;

    for(i = 1; i < size; i++) {
        value = *(array+i);
        j = i - 1;

        while (j >= 0 && *(array+j) > value) {
            *(array+j+1) = *(array+j);
            j--;
        }

        *(array+j+1) = value;
    }

}

void readFileUnsigned(unsigned *input, char *filename, int size) {
    FILE *finput;
    if (finput = fopen(filename, "rb")) {
        fread(input, size * sizeof(unsigned), 1 , finput);
    } else {
        printf("Error reading input file");
        exit(1);
    }
}
int main(int argc, char** argv)
{
    int size, omp_num_threads, iterations;
    char * inputFile, *outputFile;
    unsigned *data;

    if (argc == 5) {
        size = atoi(argv[1]);
        omp_num_threads = atoi(argv[2]);
        inputFile = argv[3];
        outputFile = argv[4];
    } else {
        fprintf(stderr, "Usage: %s <input size> <num_threads> <input file> <output file>\n", argv[0]);
        exit(1);
    }

    data = (unsigned *)malloc(size*sizeof(unsigned));

    readFileUnsigned(data, inputFile, size);

    insertion_sort(data, size);

    FILE *fp;
    if (fp = fopen(outputFile, "wb")) {
        fwrite(data, size * sizeof(unsigned), 1 , fp);
    } else {
        printf("Error writing output file");
        exit(1);
    }
    fclose(fp);

    printf("Done\n");

    return 0;
}
