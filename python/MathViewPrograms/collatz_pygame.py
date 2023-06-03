import pygame
import random
import math
import sys
from collatz_sequence import collatz_sequence

# Inicializa o Pygame
pygame.init()

# Tamanho da janela
width, height = 800, 800

# Cores pastel
colors = [
    (255, 182, 193),  # Light Pink
    (255, 160, 122),  # Light Salmon
    (221, 160, 221),  # Plum
    (147, 112, 219),  # Medium Purple
    (216, 191, 216),  # Thistle
]

# Configura a tela
screen = pygame.display.set_mode((width, height))
pygame.display.set_caption("Collatz Conjecture Tree Animation")

# Relógio para controlar a taxa de quadros
clock = pygame.time.Clock()

# Variáveis para controlar o loop
running = True
sequence_drawn = False

def draw_collatz_tree(screen, n, x, y, angle, length, color):
    if n > 1:
        # Calcula as coordenadas do próximo ponto
        new_x = x + length * math.cos(math.radians(angle))
        new_y = y - length * math.sin(math.radians(angle))

        # Desenha a linha
        pygame.draw.line(screen, color, (x, y), (new_x, new_y), 2)

        # Recursivamente desenha os ramos
        seq = collatz_sequence(n)
        for i in range(1, len(seq)):
            new_angle = angle + seq[i] * 15
            draw_collatz_tree(screen, seq[i], new_x, new_y, new_angle, length * 0.75, color)

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    if not sequence_drawn:
        # Limpa a tela
        screen.fill((255, 255, 255))

        # Gera uma sequência de Collatz aleatória
        n = random.randint(2, 1000)

        # Escolhe uma cor aleatória
        color = random.choice(colors)

        # Desenha a "flor" ou "galhos" de árvore usando a sequência de Collatz
        draw_collatz_tree(screen, n, width / 2, height * 0.9, -90, 150, color)

        # Atualiza a tela
        pygame.display.flip()

        # Aguarda um curto intervalo antes de desenhar a próxima sequência
        pygame.time.delay(3000)
        sequence_drawn = True

    else:
        sequence_drawn = False

    # Controla a taxa de quadros
    clock.tick(30)

# Encerra o Pygame
pygame.quit()
sys.exit()

