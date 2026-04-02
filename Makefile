#variables
compilador = g++
flags = -Wall -std=c++11
ejecutable = main
archivos = $(wildcard *.cpp)

$(ejecutable): $(archivos)
	$(compilador) $(flags) -o $(ejecutable) $(archivos)

clean:
	rm -f $(TARGET)
