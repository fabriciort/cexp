from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np

"""

    Cubo para visualização dos vetores do exercicio no. 4,
    da lista 1 de MAT0112 1o. Semestre 2023

Aluno:

    Nome: Fabricio Ribeiro Teixeira
    No.USP: 11909887

Motivo/Explicação:
    Já fiz as disciplinas de computação MAC0115, e aprendi mais sozinho.
    E decidi já testar aplicações e resolver problemas usando os meios
    computacionais, e em meu cotidiano preciso passar boa parte do tempo 
    em frente ao computador para trabalho, é mais prático para mim usar de 
    linguagems de programação e tecnologias para resolver os problemas do dia a dia.

    Entendo a importância de se aprender com o método tradicional, ainda 
    resolvo e formulo problemas no papel para manter a habilidade que obtemos
    somente fazendo muito, e muitos exercicios de matemática, pois só assim
    realmente aprendemos.

    - O que o programa faz?

    O programa "gera" um cubo 'ABCDEFGH' com dimensões (x,y,z), e adiciona 
    os vetores, para a visualização no computador usando a linguagem Python, e
    funções da biblioteca Matplotlib para a visualização da figura em questão, 
    e usa a biblioteca Numpy p/ criar e definir os vetores nos chamados 'arrays'.
    Usei os arrays, como uma forma de alocar os três valores que representam as
    coordenadas, em uma só variavel, como observado no código onde fica mais facil
    até de entender o que esta acontencendo, pois já dou o nome da variavel com o 
    nome do vertice e defino suas propiedades. Assim representando uma coordenada 
    no espaço criado neste ambiente.

    Para executar este código, tenha as ferramentas necessarias no seu computador:
        
        - 1. Instale o interpretador Python, pelo https://python.org
        - 2. Instale as dependências necessarias
            
            Em um 'Emulador de Terminal' execute o seguinte comandos:
            
                pip3 install matplotlib numpy

        - 3. Baixe o arquivo de código fonte (É este arquivo onde esta lendo isto!)
        - 4. Execute-o!
            
            Pode ser executado pelo terminal também com o comando python3

                python3 ./mat0112_lista_1_no_4.py

            Lembre-se de estar no mesmo diretório do código fonte.

    Caso surjam duvidas, pesquise na internet sobre.
            
"""

# Define as coordenadas dos vértices do cubo
A = np.array([0, 0, 0])
B = np.array([1, 0, 0])
C = np.array([1, 1, 0])
D = np.array([0, 1, 0])
E = np.array([0, 0, 1])
F = np.array([1, 0, 1])
G = np.array([1, 1, 1])
H = np.array([0, 1, 1])
O = np.array([0.5, 0.5, 0.5])

# Define os vetores
v1 = O - B
v2 = np.array([0.5, 0, 0.5]) - np.array([0.5, 0.5, 0])
v3 = np.array([0.5, 1, 1]) - H
v4 = np.array([0.5, 0.5, 1]) - H
v5 = np.array([0.5, 1, 0.5]) - np.array([0, 0.5, 0.5])

# Plota o cubo e os vetores
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.plot([A[0], B[0], C[0], D[0], A[0]], [A[1], B[1], C[1], D[1], A[1]], [A[2], B[2], C[2], D[2], A[2]], 'k')
ax.plot([E[0], F[0], G[0], H[0], E[0]], [E[1], F[1], G[1], H[1], E[1]], [E[2], F[2], G[2], H[2], E[2]], 'k')
ax.plot([A[0], E[0]], [A[1], E[1]], [A[2], E[2]], 'k')
ax.plot([B[0], F[0]], [B[1], F[1]], [B[2], F[2]], 'k')
ax.plot([C[0], G[0]], [C[1], G[1]], [C[2], G[2]], 'k')
ax.plot([D[0], H[0]], [D[1], H[1]], [D[2], H[2]], 'k')
ax.quiver(*B, *v1, color='r')
ax.quiver(0.5, 0.5, 0, *v2, color='b')
ax.quiver(*H, *v3, color='g')
ax.quiver(*H, *v4, color='m')
ax.quiver(0, 0.5, 0.5, *v5, color='y')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
plt.show()

