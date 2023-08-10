//Maria Fernanda Araponga e Emilly Rodrigues
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Função para gerar números aleatórios
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Inicializa o gerador de números aleatórios

    const int totalNumbers = 6;
    const int minValue = 1;
    const int maxValue = 60;

    cout << "Bem-vindo ao jogo Mega Senai!" << endl;

    while (true) {
        vector<int> playerNumbers;
        vector<int> winningNumbers;

        // Solicitar ao jogador para escolher 6 números
        cout << "Escolha " << totalNumbers << " números distintos entre " << minValue << " e " << maxValue << ":" << endl;
        for (int i = 0; i < totalNumbers; ++i) {
            int num;
            cin >> num;
            playerNumbers.push_back(num);
        }

        // Realizar o sorteio de 6 números aleatórios
        while (winningNumbers.size() < totalNumbers) {
            int num = generateRandomNumber(minValue, maxValue);
            if (find(winningNumbers.begin(), winningNumbers.end(), num) == winningNumbers.end()) {
                winningNumbers.push_back(num);
            }
        }

        // Ordenar os números escolhidos pelo jogador e os números sorteados
        sort(playerNumbers.begin(), playerNumbers.end());
        sort(winningNumbers.begin(), winningNumbers.end());

        // Comparar e contar os acertos
        int numMatches = 0;
        for (int i = 0; i < totalNumbers; ++i) {
            if (find(playerNumbers.begin(), playerNumbers.end(), winningNumbers[i]) != playerNumbers.end()) {
                ++numMatches;
            }
        }

        // Exibir os resultados
        cout << "Números sorteados: ";
        for (int num : winningNumbers) {
            cout << num << " ";
        }
        cout << endl;

        cout << "Você acertou " << numMatches << " números." << endl;

        if (numMatches == totalNumbers) {
            cout << "Parabéns! Você acertou todos os números!" << endl;
            break;
        } else {
            cout << "Tente novamente." << endl;
        }

        // Opção para sair do jogo
        cout << "Deseja jogar novamente? (S/N): ";
        char playAgain;
        cin >> playAgain;
        if (playAgain != 'S' && playAgain != 's') {
            cout << "Obrigado por jogar o Mega Senai!" << endl;
            break;
        }
    }

    return 0;
}


