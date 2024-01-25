CC=gcc
AR=ar
OBJECTS_BASIC = basicClassification.o
FLAGS= -Wall -g
FP = -fPIC

all: loops recursives recursived loopd mains maindloop maindrec

loops: libclassloops.a

recursives: libclassrec.a

recursived: libclassrec.so

loopd: libclassloops.so

libclassloops.a: $(OBJECTS_BASIC) advancedClassificationLoop.o
	$(AR) -rcs libclassloops.a $(OBJECTS_BASIC) advancedClassificationLoop.o

libclassrec.a: $(OBJECTS_BASIC) advancedClassificationRecursion.o
	$(AR) -rcs libclassrec.a $(OBJECTS_BASIC) advancedClassificationRecursion.o 

libclassrec.so: $(OBJECTS_BASIC) advancedClassificationRecursion.o
	$(CC) $(FLAGS) -shared $(FP) -o libclassrec.so $(OBJECTS_BASIC) advancedClassificationRecursion.o 

libclassloops.so: $(OBJECTS_BASIC) advancedClassificationLoop.o
	$(CC) $(FLAGS) -shared $(FP) -o libclassloops.so $(OBJECTS_BASIC) advancedClassificationLoop.o

mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o libclassloops.so

maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o libclassrec.so

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c  main.c

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) $(FP) -c  basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) $(FP) -c  advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) $(FP) -c  advancedClassificationRecursion.c

.PHONY: clean all

clean: 
	rm -f mains maindloop maindrec *.o *.a *.so *.gch