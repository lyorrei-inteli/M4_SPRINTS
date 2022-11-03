#include <iostream>
#include <string>

using namespace std;

/*
1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente entre dois valores mínimo e máximo e retorna esse valor
*/

int converteSensor(int valor, int min, int max)
{
    // Convertendo valor em uma porcentagem
    float valor1 = max - min;
    float valor2 = valor - min;
    float porcentagem = valor2 / valor1;

    // Retorno da porcentagem
    return porcentagem * 100;
}

// ----------------------------------------------------------

/*
2 - Faça uma função que simule a leitura de um sensor lendo o valor do teclado ao final a função retorna este valor
*/

int leComando()
{
    // Registrando input do usuário em uma variável
    cout << "Digite um valor: ";
    int valor;
    cin >> valor;

    return valor;
}

/*
3 - Faça uma função que armazena uma medida inteira qualquer em um vetor fornecido. Note que como C não possui vetores nativos da linguagem, lembre-se que você precisa passar o valor máximo do vetor assim como a última posição preenchida.
Evite também que, por acidente, um valor seja escrito em uma área de memória fora do vetor
*/
int insereVetor(int valor, int valorMax, int ultimaPosicao, int arr[])
{
    // Chegagem se o array ainda tem espaço para adicoinar elementos
    if (ultimaPosicao < valorMax)
    {
        // Registrando o valor da distância no array
        arr[ultimaPosicao] = valor;
    }
    else
    {
        // Erro caso o array não tenha mais espaço
        cout << "Erro: valorMax: " << valorMax << endl;
    }

    // Retornando a próxima posição para o armazenamento de novos valores
    return ultimaPosicao + 1;
}



/*
4 - Faça duas funções que recebem um vetor com 4 posições que contém o valor da distância de um pequeno robô até cada um dos seus 4 lados.
A primeira função deve retornar a direção de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a segunda função deve retornar esta maior distância.
*/

char *dirMaiorDist(int posicoes[4])
{
    // Checagem de qual direção tem a maior distância
    if (posicoes[0] > posicoes[1] && posicoes[0] > posicoes[2] && posicoes[0] > posicoes[3])
    {
        return "Direita";
    }
    else if (posicoes[1] > posicoes[0] && posicoes[1] > posicoes[2] && posicoes[1] > posicoes[3])
    {
        return "Esquerda";
    }
    else if (posicoes[2] > posicoes[0] && posicoes[2] > posicoes[1] && posicoes[2] > posicoes[3])
    {
        return "Frente";
    }
    else if (posicoes[3] > posicoes[0] && posicoes[3] > posicoes[1] && posicoes[3] > posicoes[2])
    {
        return "Atrás";
    }
}

int maiorDist(int *posicoes)
{
    // Variável controle para registrar a maior distância
    int maiorDistancia = posicoes[0];

    // Loop que passa entre as 4 direções possiveis (direita, esquerda, frente e atrás)
    for (int i = 0; i < 4; i++)
    {
        // Checagem da maior distância em cada direção
        if (posicoes[i] > maiorDistancia)
        {
            // Armazenamento da maior distância na variável de controle
            maiorDistancia = posicoes[i];
        }
    }

    // Retornando a maior distância
    return maiorDistancia;
}

// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e retorna verdadeiro ou falso

int continuar()
{
    // Variável para checar se o usuário deseja continuar ou parar o sistema
    int wishToContinue;

    // Armazenamento do input do usuário na variável
    cout << "Digite 1 para parar o mapeamento!" << endl;
    cin >> wishToContinue;

    // If para checar se o usuário decidiu continuar ou parar a execução do sistema
    if (wishToContinue == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/*
6 - Escreva uma função que vai "dirigindo" virtualmente um robô e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", "Frente", "Tras").
A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno para uma movimentação futura.
Ele vai armazenando estas distancias em um vetor fornecido como parâmetro e retorna a ultima posicao preenchida do vetor.
Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado.
Para simular os sensores e os comandos de pare, use as funções já construídas nos ítens anteriores e em um looping contínuo até que um pedido de parada seja enviado pelo usuário.
A função final deve utilizar as funções declaradas acima para ler os sensores e o movimento do robô e no final percorrer o vetor e mostrar o movimento a cada direção na maior distância a cada movimento.
*/

int dirige(int *v, int maxv)
{
    int maxVetor = maxv;
    int *vetorMov = v;
    int posAtualVetor = 0;

    // Variável de controle para continuar o loop que está definido a seguir
    int dirigindo = 1;

    // Loop para a execução das funções de armazenamento de posição do usuário
    while (dirigindo == 1)
    {
        // Loop em cada uma das direções possíveis (frente, atrás, esquerda e direita)
        for (int i = 0; i < 4; i++)
        {
            // Lendo o input do usuário
            int medida = leComando();

            // Transformando o valor "medida" em uma porcentagem
            medida = converteSensor(medida, 0, 830);

            // Inserindo valor da distância em um Array para deixar registrado
            posAtualVetor = insereVetor(medida, maxVetor, posAtualVetor, vetorMov);
        }

        // Checando se usuário deseja continuar a execução do sistema
        dirigindo = continuar();
    }

        return posAtualVetor;
}

// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado
// na maior distância a cada movimento
void percorre(int *v, int tamPercorrido)
{
    int *vetorMov = v;
    int maiorDir = 0;

    for (int i = 0; i < tamPercorrido; i += 4)
    {
        char *direcao = dirMaiorDist(&(vetorMov[i]));
        int maiorDir = maiorDist(&(vetorMov[i]));
        cout << maiorDir << endl;
        printf("Movimentando para %s distancia = %i% \n", direcao, maiorDir);
    }
}

int main(int argc, char **argv)
{
    int maxVetor = 100;
    int vetorMov[maxVetor * 4];
    int posAtualVet = 0;

    posAtualVet = dirige(vetorMov, maxVetor);
    percorre(vetorMov, posAtualVet);

    return 0;
}
