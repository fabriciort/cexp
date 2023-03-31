def main():
    jogadores = []
    num_jogadores = int(input("Quantos jogadores participarão? "))
    for i in range(num_jogadores):
        jogadores.append({"carteira": 10000, "apostas": []})

    while True:
        print("\nCarteira dos jogadores:")
        for i, jogador in enumerate(jogadores):
            print(f"Jogador {i+1}: {jogador['carteira']} fichas")

        opcao = input("\nO que você deseja fazer? (a) Adicionar aposta, (b) Imprimir apostas, (c) Sair ")
        if opcao == "a":
            jogador = jogadores[selecionar_jogador(jogadores)]
            if jogador is None:
                continue
            adicionar_aposta(jogador)
        elif opcao == "b":
            imprimir_apostas(jogadores)
        elif opcao == "c":
            break
        else:
            print("Opção inválida. Tente novamente.")

def validar_aposta(valor_aposta, saldo_atual):
    if valor_aposta <= 0:
        print("O valor da aposta deve ser maior que zero.")
        return False
    if valor_aposta > saldo_atual:
        print("Você não tem saldo suficiente para fazer essa aposta.")
        return False
    return True

def selecionar_jogador(jogadores):
    num_jogadores = len(jogadores)
    if num_jogadores == 0:
        print("Não há jogadores cadastrados.")
        return None

    while True:
        opcao = input(f"Selecione um jogador (1-{num_jogadores}) ou pressione Enter para voltar: ")
        if opcao == "":
            return None
        try:
            index = int(opcao) - 1
            if index < 0 or index >= num_jogadores:
                raise ValueError()
            return index
        except ValueError:
            print("Opção inválida. Tente novamente.")

def adicionar_aposta(jogador):
    aposta = input("Insira a sua aposta: ")
    try:
        aposta = int(aposta)
    except ValueError:
        print("A aposta deve ser um número inteiro.")
        return

    if aposta > jogador["carteira"]:
        print("Você não tem fichas suficientes para fazer esta aposta.")
        return

    jogador["carteira"] -= aposta
    jogador["apostas"].append(aposta)
    print("Aposta adicionada com sucesso.")

def imprimir_apostas(jogadores):
    for i, jogador in enumerate(jogadores):
        if len(jogador["apostas"]) > 0:
            print(f"\nApostas do jogador {i+1}:")
            for aposta in jogador["apostas"]:
                print(f" - {aposta} fichas")
        else:
            print(f"\nO jogador {i+1} ainda não fez nenhuma aposta.")

if __name__ == "__main__":
    main()

