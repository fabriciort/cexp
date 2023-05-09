import os
import math
import random
from PIL import Image, ImageDraw
from math import gcd

# Número de iterações
iterations = 1000

# Tamanho da imagem
width, height = 800, 600

# Cores pastel
colors = [
    (255, 182, 193),  # Light Pink
    (255, 160, 122),  # Light Salmon
    (221, 160, 221),  # Plum
    (147, 112, 219),  # Medium Purple
    (216, 191, 216),  # Thistle
]

# Duração da animação (30 segundos)
animation_duration = 30

# Duração de cada frame em milissegundos
frame_duration = int(1000 * animation_duration / iterations)

def collatz_sequence(n):
    seq = [n]
    while n != 1:
        if n % 2 == 0:
            n = n // 2
        else:
            n = 3 * n + 1
        seq.append(n)
    return seq

def draw_collatz_sequence(draw, seq, color):
    max_value = max(seq)
    x_step = float(width) / len(seq)
    y_step = float(height) / max_value

    for i in range(1, len(seq)):
        x1, y1 = (i - 1) * x_step, height - seq[i - 1] * y_step
        x2, y2 = i * x_step, height - seq[i] * y_step
        draw.line([(x1, y1), (x2, y2)], fill=color, width=2)

frames = []

for i in range(iterations):
    # Crie uma imagem vazia com fundo branco
    image = Image.new("RGB", (width, height), "white")
    draw = ImageDraw.Draw(image)

    # Selecione um número aleatório e calcule a sequência de Collatz
    n = random.randint(2, 10000)
    seq = collatz_sequence(n)

    # Desenhe a sequência de Collatz com uma cor aleatória
    color = random.choice(colors)
    draw_collatz_sequence(draw, seq, color)

    # Adicione a imagem à lista de frames
    frames.append(image)

# Salve a animação em loop como um arquivo GIF
frames[0].save(
    "collatz_animation.gif",
    save_all=True,
    append_images=frames[1:],
    duration=frame_duration,
    loop=0,
)

