function main() {
    var jogadores = [];
    var num_jogadores = parseInt(prompt("Quantos jogadores participarão? "));
    for (var i = 0; i < num_jogadores; i++) {
        jogadores.push({"carteira": 10000, "apostas": []});
    }

    while (true) {
        console.log("\nCarteira dos jogadores:");
        for (var i = 0; i < jogadores.length; i++) {
            console.log("Jogador " + (i+1) + ": " + jogadores[i]["carteira"] + " fichas");
        }

        var opcao = prompt("\nO que você deseja fazer? (a) Adicionar aposta, (b) Imprimir apostas, (c) Sair ");
        if (opcao == "a") {
            var jogador = jogadores[selecionar_jogador(jogadores)];
            if (jogador == null) {
                continue;
            }
            adicionar_aposta(jogador);
        } else if (opcao == "b") {
            imprimir_apostas(jogadores);
        } else if (opcao == "c") {
            break;
        } else {
            console.log("Opção inválida. Tente novamente.");
        }
    }
}

function validar_aposta(valor_aposta, saldo_atual) {
    if (valor_aposta <= 0) {
        console.log("O valor da aposta deve ser maior que zero.");
        return false;
    }
    if (valor_aposta > saldo_atual) {
        console.log("Você não tem saldo suficiente para fazer essa aposta.");
        return false;
    }
    return true;
}

function selecionar_jogador(jogadores) {
    var num_jogadores = jogadores.length;
    if (num_jogadores == 0) {
        console.log("Não há jogadores cadastrados.");
        return null;
    }

    while (true) {
        var opcao = prompt("Selecione um jogador (1-" + num_jogadores + ") ou pressione Enter para voltar: ");
        if (opcao == "") {
            return null;
        }
        try {
            var index = parseInt(opcao) - 1;
            if (index < 0 || index >= num_jogadores) {
                throw new Error();
            }
            return index;
        } catch(e) {
            console.log("Opção inválida. Tente novamente.");
        }
    }
}

function adicionar_aposta(jogador) {
    var aposta = prompt("Insira a sua aposta: ");
    try {
        aposta = parseInt(aposta);
    } catch(e) {
        console.log("A aposta deve ser um número inteiro.");
    }
}
