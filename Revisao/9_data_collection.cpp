#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>
#include <cstdlib> // Para rand()
#include <ctime> // Para std::ctime()
#include <arpa/inet.h> // Para sockets
#include <unistd.h> // Para close()

// Estrutura para representar dados de produção
struct DadosProducao {
    std::string timestamp;
    int sensor1;
    int sensor2;
    int sensor3;
};

/** 
 * @brief Coleta dados dos sensores
 * 
 * @return DadosProducao Dados coletados dos sensores
 */
DadosProducao coletarDadosSensores() {
    // Simula a coleta de dados dos sensores
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Simula o tempo de coleta
    DadosProducao dados;
    auto now = std::chrono::system_clock::now();
    auto now_time = std::chrono::system_clock::to_time_t(now);
    dados.timestamp = std::ctime(&now_time);
    dados.sensor1 = rand() % 100;
    dados.sensor2 = rand() % 100;
    dados.sensor3 = rand() % 100;
    return dados;
}

/** 
 * @brief Escreve dados em um arquivo
 * 
 * @param nomeArquivo Nome do arquivo onde os dados serão escritos
 * @param dados Dados a serem escritos no arquivo
 */
void escreverDadosArquivo(const char* nomeArquivo, const DadosProducao& dados) {
    FILE* arquivo = fopen(nomeArquivo, "a");
    if (arquivo) {
        fprintf(arquivo, "Timestamp: %s", dados.timestamp.c_str());
        fprintf(arquivo, "Sensor 1: %d\n", dados.sensor1);
        fprintf(arquivo, "Sensor 2: %d\n", dados.sensor2);
        fprintf(arquivo, "Sensor 3: %d\n\n", dados.sensor3);
        fclose(arquivo);
    } else {
        fprintf(stderr, "Erro ao abrir o arquivo para escrita.\n");
        throw std::runtime_error("Erro ao abrir o arquivo para escrita.");
    }
}

/** 
 * @brief Envia dados via socket
 * 
 * @param socket Descritor do socket
 * @param dados Dados a serem enviados
 */
void enviarDadosSocket(int socket, const DadosProducao& dados) {
    std::string mensagem = dados.timestamp + " | Sensor 1: " + std::to_string(dados.sensor1)
                           + " | Sensor 2: " + std::to_string(dados.sensor2)
                           + " | Sensor 3: " + std::to_string(dados.sensor3);
    ssize_t bytes_enviados = send(socket, mensagem.c_str(), mensagem.size(), 0);
    if (bytes_enviados < 0) {
        fprintf(stderr, "Erro ao enviar dados via socket.\n");
        throw std::runtime_error("Erro ao enviar dados via socket.");
    }
}

/** 
 * @brief Inicializa e conecta o socket
 * 
 * @param endereco Endereço do servidor
 * @param porta Porta do servidor
 * @return int Descritor do socket do cliente
 */
int conectarSocket(const char* endereco, int porta) {
    int socketCliente = socket(AF_INET, SOCK_STREAM, 0);
    if (socketCliente < 0) {
        fprintf(stderr, "Erro ao criar o socket.\n");
        throw std::runtime_error("Erro ao criar o socket.");
    }

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(porta);

    if (inet_pton(AF_INET, endereco, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Endereço inválido.\n");
        throw std::runtime_error("Endereço inválido.");
    }

    int tentativas = 0;
    while (connect(socketCliente, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        ++tentativas;
        if (tentativas >= 3) {
            fprintf(stderr, "Falha ao conectar.\n");
            throw std::runtime_error("Falha ao conectar.");
        }
        printf("Tentando reconectar...\n");
        std::this_thread::sleep_for(std::chrono::seconds(3)); // Espera 3 segundos antes de tentar novamente
    }

    return socketCliente;
}

/** 
 * @brief Fecha o socket
 * 
 * @param socket Descritor do socket a ser fechado
 */
void fecharSocket(int socket) {
    close(socket);
}

int main() {
    // Exemplo de coleta de dados e escrita em arquivo
    for (int i = 0; i < 10; ++i) {
        try {
            DadosProducao dados = coletarDadosSensores();
            escreverDadosArquivo("data_folder/dados_producao.txt", dados);
            printf("Dados de produção coletados e escritos no arquivo.\n");
        } catch (const std::exception& e) {
            fprintf(stderr, "Erro: %s\n", e.what());
        }
    }

    // Exemplo de envio de dados via socket
    const char* enderecoServidor = "127.0.0.1"; // Endereço do servidor
    int portaServidor = 8080; // Porta do servidor
    int socketCliente = conectarSocket(enderecoServidor, portaServidor);
    if (socketCliente >= 0) {
        for (int i = 0; i < 5; ++i) {
            try {
                DadosProducao dados = coletarDadosSensores();
                enviarDadosSocket(socketCliente, dados);
                printf("Dados de produção enviados para o servidor.\n");
            } catch (const std::exception& e) {
                fprintf(stderr, "Erro: %s\n", e.what());
            }
        }
        fecharSocket(socketCliente);
    }

    return 0;
}
