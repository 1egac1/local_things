test: polygone.c module1.c
	gcc module1.c -o model.out
	gcc polygone.c 
	./a.out
