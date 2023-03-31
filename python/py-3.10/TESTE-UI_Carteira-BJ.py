import tkinter as tk
import carteira_bj_func as bj


def iniciar_jogo():
    num_jogadores = int(num_jogadores_entry.get())
    jogadores = []
    for i in range(num_jogadores):
        jogadores.append({"carteira": 10000, "apostas": []})

    instrucoes_label.config(text="Adicione as apostas dos jogadores")
    num_jogadores_label.destroy()
    num_jogadores_entry.destroy()
    iniciar_jogo_button.destroy()

    for i, jogador in enumerate(jogadores):
        jogador_label = tk.Label(frame, text=f"Jogador {i+1}")
        jogador_label.grid(row=i+1, column=0)

        aposta_entry = tk.Entry(frame, width=10)
        aposta_entry.grid(row=i+1, column=1)

        apostar_button = tk.Button(frame, text="Apostar",
                                   command=lambda idx=i: adicionar_aposta(jogadores[idx], aposta_entry))
        apostar_button.grid(row=i+1, column=2)


def adicionar_aposta(jogador, aposta_entry):
    aposta = aposta_entry.get()
    try:
        aposta = int(aposta)
    except ValueError:
        instrucoes_label.config(text="A aposta deve ser um número inteiro.")
        return

    if aposta > jogador["carteira"]:
        instrucoes_label.config(text="Você não tem fichas suficientes para fazer esta aposta.")
        return

    jogador["carteira"] -= aposta
    jogador["apostas"].append(aposta)
    aposta_entry.delete(0, tk.END)
    instrucoes_label.config(text="Aposta adicionada com sucesso.")


# Interface gráfica
root = tk.Tk()
root.title("Blackjack")

frame = tk.Frame(root)
frame.pack(padx=20, pady=20)

num_jogadores_label = tk.Label(frame, text="Quantos jogadores participarão?")
num_jogadores_label.grid(row=0, column=0)

num_jogadores_entry = tk.Entry(frame, width=10)
num_jogadores_entry.grid(row=0, column=1)

iniciar_jogo_button = tk.Button(frame, text="Iniciar Jogo", command=iniciar_jogo)
iniciar_jogo_button.grid(row=0, column=2)

instrucoes_label = tk.Label(frame, text="")
instrucoes_label.grid(row=5, column=0, columnspan=3)

root.mainloop()

