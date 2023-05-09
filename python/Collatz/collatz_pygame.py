import pygame
import random
import sys
from collatz_sequence_PIL import collatz_sequence  # Importe a função collatz_sequence do exemplo anterior

# Inicializa o Pygame
pygame.init()

# Tamanho da janela
width, height = 800, 600

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
pygame.display.set_caption("Collatz Conjecture Animation")

# Relógio para controlar a taxa de quadros
clock = pygame.time.Clock()

# Variáveis para controlar o loop
running = True
sequence_drawn = False

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    if not sequence_drawn:
        # Gera uma sequência de Collatz aleatória
        n = random.randint(2, 10000)
        seq = collatz_sequence(n)

        # Escolhe uma cor aleatória
        color = random.choice(colors)

        # Desenha a sequência de Collatz na tela
        max_value = max(seq)
        x_step = float(width) / len(seq)
        y_step = float(height) / max_value

        for i in range(1, len(seq)):
            x1, y1 = (i - 1) * x_step, height - seq[i - 1] * y_step
            x2, y2 = i * x_step, height - seq[i] * y_step
            pygame.draw.line(screen, color, (x1, y1), (x2, y2), 2)

        # Atualiza a tela
        pygame.display.flip()

        # Aguarda um curto intervalo antes de desenhar a próxima sequência
        pygame.time.delay(1000)
        sequence_drawn = True

    else:
        # Limpa a tela e prepara para desenhar a próxima sequência
        screen.fill((255, 255, 255))
        sequence_drawn = False

    # Controla a taxa de quadros
    clock.tick(30)

# Encerra o Pygame
pygame.quit()
sys.exit()
