/*
 IFSC - Campus São José
 Desenvolvido por - Vinicius Tonini
 Projeto - Gerador de Texto a Partir do Formulário
 Programação II
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {

    string argumentos[4], palavras_chave[4], a = argv[1];

    if (argc < 6 || argc > 6) { // Verificação no número de argumentos da entrada de dados
        cerr << argv[0] << " Ouve um erro na entrada de dados..." << endl;
    } else {
        argumentos[0] = argv[2];
        argumentos[1] = argv[3];
        argumentos[2] = argv[4];
        argumentos[3] = argv[5];

        palavras_chave[0] = "$cidade";
        palavras_chave[1] = "$data";
        palavras_chave[2] = "$aluno";
        palavras_chave[3] = "$disciplina";
    }

    ifstream arquivo("../" + a); // abre o arquivo para leitura

    if (!arquivo.is_open()) { // verifica se o arquivo foi aberto
        cerr << "Ocorreu um erro ao abrir o arquivo ..." << endl;
        return 0;
    }

    string linha;
    while (getline(arquivo, linha)) { // lê cada linha do arquivo, e apresenta em tela
        for (int i = 0; i < 4; i++) { // Loop com base nos vetores de argumentos e palavra chave
            int pos_i = 0;
            while ((pos_i = linha.find(palavras_chave[i], pos_i)) != std::string::npos) { // Loop para encontrar a palavra chave e substituir
                linha.replace(pos_i, palavras_chave[i].length(), argumentos[i]); // Substitui a palavra chave
                pos_i += argumentos[i].length();
            }
        }
        cout << linha << endl; // Mostra em tela as linhas do arquivo
    }

    return 0;
}
