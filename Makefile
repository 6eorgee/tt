CC=g++

all:
	$(CC) main.cpp -lboost_program_options -o test
	@echo
	@echo Запустите программу с помощью команды ./test
	@echo
	@echo Для запуска со всеми ключами последовательно выполнитe команду make run
	@echo
	@echo Для тестирования, когда готовы файлы generated.txt и collected.txt,
	@echo можно сделать make check

run:
	./test --generate
	./test --split
	./test --shuffle
	./test --collect

check:
	diff generated.txt collected.txt

clean:
	rm -rf *.txt test
