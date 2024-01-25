CC=gcc
AR=ar
OBJECTS_BASIC = basicClassification.o
FLAGS= -Wall -g
FP = -fPIC

all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so mains maindloop maindrec

libclassloops.a: $(OBJECTS_BASIC) advancedClassificationLoop.o
	$(AR) -rcs libclassloops.a $(OBJECTS_BASIC) advancedClassificationLoop.o
	ranlib libclassloops.a 

libclassrec.a: $(OBJECTS_BASIC) advancedClassificationRecursion.o
	$(AR) -rcs libclassrec.a $(OBJECTS_BASIC) advancedClassificationRecursion.o 
	ranlib libclassrec.a

libclassrec.so: $(OBJECTS_BASIC) advancedClassificationRecursion.o
	$(CC) -shared $(FP) -o libclassrec.so $(OBJECTS_BASIC) advancedClassificationRecursion.o 

libclassloops.so: $(OBJECTS_BASIC) advancedClassificationLoop.o
	$(CC) -shared $(FP) -o libclassloops.so $(OBJECTS_BASIC) advancedClassificationLoop.o

mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o libclassloops.so

maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o libclassrec.so

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c  basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c  advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c  advancedClassificationRecursion.c

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c  main.c

.PHONY: clean all 

clean: 
	rm -f *.o *.a *.so mains maindloop maindrec
			