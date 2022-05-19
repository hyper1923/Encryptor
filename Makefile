
CC = g++
O = -o Cracker.exec
FILES = main.cpp


build:
	${CC} ${FILES} ${O}

encrypt:
	./Cracker.exec --encrypt Encrypt.txt Encrypted.txt

deencrypt:
	./Cracker.exec --deencrypt Encrypted.txt


