# C compiler
CC = gcc -g
CC_FLAGS = -fopenmp

destDir = /tmp/insertion_sort

all: gen_bin gen_data mv_bin

gen_bin: insertion_sort.c generateInput.c
	$(CC) $(CC_FLAGS) insertion_sort.c -o insertion_sort
	$(CC) $(CC_FLAGS) generateInput.c -o genInput 

gen_data: gen_bin
	./genInput
	./insertion_sort 50000 1 inputsort_134217728 gold_50000

mv_bin: gen_data
	mkdir -p $(destDir)
	mkdir -p lastDataCreated
	cp inputsort_134217728 gold_50000 lastDataCreated
	mv genInput insertion_sort inputsort_134217728 gold_50000 $(destDir)
	@echo "All Done, executables should be in the $(destDir)"