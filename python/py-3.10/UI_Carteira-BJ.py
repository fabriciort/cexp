import tkinter as tk
from carteira_bj_func import selecionar_jogador, adicionar_aposta, imprimir_apostas

jogadores = []
quantidade_jogadores = 0
apostas_feitas = False

def criar_apostas_frame():
    global jogadores_frame, jogadores_entries, botao_apostar, label_apostas

    jogadores_frame = tk.Frame(janela)

    global jogadores_entries
    jogadores_entries = []
    for i, jogador in enumerate(jogadores):
        label_nome = tk.Label(jogadores_frame, text=jogador[0])
        label_nome.grid(row=i, column=0)

        entry_aposta = tk.Entry(jogadores_frame)
        entry_aposta.grid(row=i, column=1)

        jogadores_entries.append(entry_aposta)

    botao_apostar = tk.Button(jogadores_frame, text="Apostar", command=fazer_apostas)
    botao_apostar.grid(row=quantidade_jogadores, column=1)

    jogadores_frame.pack()


def criar_jogadores():
    global quantidade_jogadores
    quantidade_jogadores = int(entrada_jogadores.get())

    if quantidade_jogadores > 0:
        for i in range(quantidade_jogadores):
            nome_jogador = f"Jogador {i + 1}"
            jogadores.append((nome_jogador, 0))

        label_apostas.config(text="")
        botao_apostar.config(state=tk.NORMAL)

def fazer_apostas():
    global apostas_feitas
    apostas_feitas = True

    for i, jogador in enumerate(jogadores):
        qtd_aposta = int(jogadores_entries[i].get())
        jogadores[i] = (jogador[0], qtd_aposta)

    for jogador in jogadores:
        label_apostas["text"] += f"{jogador[0]}: {jogador[1]} fichas\n"

    botao_apostar.config(state=tk.DISABLED)

def iniciar_jogo():
    global jogadores, quantidade_jogadores, apostas_feitas

    apostas_feitas = False
    jogadores = []
    quantidade_jogadores = 0
    entrada_jogadores.delete(0, tk.END)
    jogadores_frame.destroy()
    label_apostas.config(text="")

    criar_jogadores_frame()

def criar_jogadores_frame():
    global jogadores_frame, jogadores_entries

    jogadores_frame = tk.Frame(janela)

    label_jogadores = tk.Label(jogadores_frame, text="Quantos jogadores irão jogar?")
    label_jogadores.pack()

    global entrada_jogadores
    entrada_jogadores = tk.Entry(jogadores_frame)
    entrada_jogadores.pack()

    botao_criar = tk.Button(jogadores_frame, text="Criar jogadores", command=criar_jogadores)
    botao_criar.pack()

    jogadores_frame.pack()

janela = tk.Tk()

label_apostas = tk.Label(janela)
label_apostas.pack()

botao_apostar = tk.Button(janela, text="Apostar", state=tk.DISABLED, command=fazer_apostas)
botao_novo_jogo = tk.Button(janela, text="Novo jogo", command=iniciar_jogo)

criar_jogadores_frame()

botao_novo_jogo.pack()
botao_apostar.pack()

janela.mainloop()

