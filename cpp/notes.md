### LSFML Graphics - Mandelbrot compilação

`clang++ -O2 main.cpp -o mandelbrot -lsfml-graphics -lsfml-window -lsfml-system`
`clang++ -O2 src/mandelbrot_anim-1.cpp -o bin/mac/mandelbrot -I/usr/local/Cellar/sfml/2.5.1_2/include/ -lsfml-graphics -L/usr/local/Cellar/sfml/2.5.1_2/lib -lsfml-window -lsfml-system`

### SDL2 - Compilação
`gcc -O2 -Wall -Wextra -pedantic -lSDL2 src/collatz_c.c -o bin/mac/collatz_anim`
