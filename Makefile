INCLUDE_FLAGS := ~/Documents/compProgramming/ 

all: 
	gcc insert_file_name_here.c ../../template.c -g -Wall $(INCLUDE_FLAGS)
