let jogadores = []; // array vazia para armazenar os jogadores

// let numJogadores = parseInt(prompt("Insira o número de jogadores:")); // pede ao usuário para inserir o número de jogadores

// for (let i = 1; i <= numJogadores; i++) {
//   let jogador = prompt(`Insira o nome do jogador ${i}:`); // pede ao usuário para inserir o nome do jogador
//   jogadores.push(jogador); // adiciona o jogador à array de jogadores
// }

function exibirJogadores() {
  // pega a div que irá conter a lista de jogadores
  const listaJogadores = document.getElementById("jogadores-lista");
  
  // limpa a lista de jogadores existente
  listaJogadores.innerHTML = "";
  
  // percorre a lista de jogadores e adiciona cada um à lista na tela
  for (let jogador of jogadores) {
    const jogadorDiv = document.createElement("div");
    jogadorDiv.innerHTML = `<strong>${jogador.nome}</strong> - saldo: R$${jogador.saldo.toFixed(2)}`;
    listaJogadores.appendChild(jogadorDiv);
  }
  
  // atualiza a quantidade de jogadores na tela
  const numJogadores = document.getElementById("num-jogadores");
  numJogadores.innerHTML = jogadores.length;
}

function adicionarJogador() {
  // Pega o input do nome do jogador
  var jogadorInput = document.getElementById("add-jogador-btn");
  var nomeJogador = jogadorInput.value;

  // Cria um objeto jogador com o nome e um array de apostas vazio
  var jogador = {
    nome: nomeJogador,
    apostas: []
  };

  // Adiciona o jogador na lista de jogadores
  jogadores.push(jogador);

  // Limpa o input do nome do jogador
  jogadorInput.value = "";

  // Atualiza a lista de jogadores exibida na tela
  exibirJogadores();
}

function adicionarAposta() {
  // Obter a lista de jogadores cadastrados
  const jogadores = JSON.parse(localStorage.getItem('jogadores')) || [];

  // Verificar se existe pelo menos um jogador cadastrado
  if (jogadores.length === 0) {
    alert('Não há jogadores cadastrados!');
    return;
  }

  // Preencher o select com as opções de jogadores
  const selectJogador = document.getElementById('jogador-select');
  selectJogador.innerHTML = '';
  for (let i = 0; i < jogadores.length; i++) {
    const option = document.createElement('option');
    option.value = jogadores[i].id;
    option.innerText = jogadores[i].nome;
    selectJogador.appendChild(option);
  }

  // Exibir o modal de adicionar aposta
  const modal = document.getElementById('add-aposta-modal');
  modal.style.display = 'block';
}

function verApostas() {
  // Obter a lista de jogadores e apostas
  const jogadores = Object.keys(carteira);
  const listaApostas = jogadores.map(jogador => {
    const valorApostas = carteira[jogador].reduce((total, aposta) => total + aposta, 0);
    return `${jogador}: R$ ${valorApostas.toFixed(2)}`;
  });

  // Atualizar o conteúdo da div "apostas-lista"
  const apostasLista = document.getElementById("apostas-lista");
  apostasLista.innerHTML = "";
  for (const aposta of listaApostas) {
    const apostaElement = document.createElement("p");
    apostaElement.textContent = aposta;
    apostasLista.appendChild(apostaElement);
  }

  // Exibir o modal de ver apostas
  const verApostasModal = document.getElementById("ver-apostas-modal");
  verApostasModal.style.display = "block";
}

document.getElementById("add-jogador-btn").addEventListener("click", adicionarJogador);
document.getElementById("add-aposta-btn").addEventListener("click", adicionarAposta);
document.getElementById("ver-apostas-btn").addEventListener("click", verApostas);

