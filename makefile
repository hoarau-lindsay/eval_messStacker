#Makefile

SRC = src
BUILD = build
TEST = test

#Compilation de la librairie messStacker
$(BUILD)/messStacker.o : $(SRC)/messStacker.c $(SRC)/messStacker.h
	@echo "compilation.o de la librairie messStacker"
	gcc -c -Wall $(SRC)/messStacker.c -o $(BUILD)/messStacker.o

#Compilation intermédiaire du test
$(BUILD)/test.o : $(TEST)/test.c
	@echo "compilation.o du test"
	gcc -I $(SRC) -c -Wall $(TEST)/test.c -o $(BUILD)/test.o

#Compilation des tests 
$(BUILD)/test : $(BUILD)/test.o $(BUILD)/messStacker.o
	@echo "compilation du test"
	gcc -Wall $(BUILD)/test.o $(BUILD)/messStacker.o -o $(BUILD)/test

#Nettoyage du projet 
clean : 
	@echo "supression de tous les fichiers dans build"
	rm -r $(BUILD)/*
	
#run