#include <stdio.h>
#include <stdlib.h>

void compDetalhada(char cidade1[], char cidade2[], unsigned long int valor1, unsigned long int valor2);
void compDetalhadaFloat(char cidade1[], char cidade2[], float valor1, float valor2, int menorVence);

int main() {
    // Declaração de variáveis
    char estado_1, estado_2;
    char codigo_1[10], codigo_2[10];
    char nome_cidade_1[50], nome_cidade_2[50];
    unsigned long int populacao_1, populacao_2; 
    float area_km_1, area_km_2;
    float PIB_1, PIB_2;
    int pontos_turisticos_1, pontos_turisticos_2;
    float densi_Pop1, densi_Pop2;
    float PIB_perCap1, PIB_perCap2;
    float SuperPoder1, SuperPoder2;

    printf("=== Jogo Super Trunfo ===\n\n");

    // CARTA 1
    printf("Digite os dados da primeira carta:\n");
    printf("Estado (A a H): ");
    scanf(" %c", &estado_1);

    printf("Codigo da carta: ");
    scanf("%s", codigo_1);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", nome_cidade_1);

    printf("Populacao: ");
    scanf("%lu", &populacao_1);

    printf("Area (km²): ");
    scanf("%f", &area_km_1);

    printf("PIB: ");
    scanf("%f", &PIB_1);

    printf("Pontos turisticos: ");
    scanf("%d", &pontos_turisticos_1);

    densi_Pop1 = populacao_1 / area_km_1;
    PIB_perCap1 = PIB_1 / populacao_1;
    SuperPoder1 = populacao_1 + area_km_1 + PIB_1 + pontos_turisticos_1 + PIB_perCap1 + (1 / densi_Pop1);

    printf("\n------------------------------------\n");

    // CARTA 2
    printf("Digite os dados da segunda carta:\n");
    printf("Estado (A a H): ");
    scanf(" %c", &estado_2);

    printf("Codigo da carta: ");
    scanf("%s", codigo_2);

    printf("Nome da cidade: ");
    scanf(" %[^\n]", nome_cidade_2);

    printf("Populacao: ");
    scanf("%lu", &populacao_2);

    printf("Area (km²): ");
    scanf("%f", &area_km_2);

    printf("PIB: ");
    scanf("%f", &PIB_2);

    printf("Pontos turisticos: ");
    scanf("%d", &pontos_turisticos_2);

    densi_Pop2 = populacao_2 / area_km_2;
    PIB_perCap2 = PIB_2 / populacao_2;
    SuperPoder2 = populacao_2 + area_km_2 + PIB_2 + pontos_turisticos_2 + PIB_perCap2 + (1 / densi_Pop2);

    printf("\n=== Cartas Cadastradas ===\n");
    printf("\nCarta 1 - %s (%c)\n", nome_cidade_1, estado_1);
    printf("Populacao: %lu\n", populacao_1);
    printf("Area: %.2f km²\n", area_km_1);
    printf("PIB: %.2f\n", PIB_1);
    printf("Pontos Turisticos: %d\n", pontos_turisticos_1);
    printf("Densidade Populacional: %.2f hab/km²\n", densi_Pop1);
    printf("PIB per Capita: %.2f\n", PIB_perCap1);
    printf("Super Poder: %.2f\n", SuperPoder1);

    printf("\nCarta 2 - %s (%c)\n", nome_cidade_2, estado_2);
    printf("Populacao: %lu\n", populacao_2);
    printf("Area: %.2f km²\n", area_km_2);
    printf("PIB: %.2f\n", PIB_2);
    printf("Pontos Turisticos: %d\n", pontos_turisticos_2);
    printf("Densidade Populacional: %.2f hab/km²\n", densi_Pop2);
    printf("PIB per Capita: %.2f\n", PIB_perCap2);
    printf("Super Poder: %.2f\n", SuperPoder2);

    printf("\n=== Comparacao de Atributos ===\n");
    printf("\nPopulacao:\n");
    compDetalhada(nome_cidade_1, nome_cidade_2, populacao_1, populacao_2);

    printf("\nArea:\n");
    compDetalhadaFloat(nome_cidade_1, nome_cidade_2, area_km_1, area_km_2, 0);

    printf("\nPIB:\n");
    compDetalhadaFloat(nome_cidade_1, nome_cidade_2, PIB_1, PIB_2, 0);

    printf("\nPontos Turisticos:\n");
    compDetalhada(nome_cidade_1, nome_cidade_2, pontos_turisticos_1, pontos_turisticos_2);

    printf("\nDensidade Populacional:\n");
    compDetalhadaFloat(nome_cidade_1, nome_cidade_2, densi_Pop1, densi_Pop2, 1); // menor vence

    printf("\nPIB per Capita:\n");
    compDetalhadaFloat(nome_cidade_1, nome_cidade_2, PIB_perCap1, PIB_perCap2, 0);

    printf("\nSuper Poder:\n");
    compDetalhadaFloat(nome_cidade_1, nome_cidade_2, SuperPoder1, SuperPoder2, 0);

    return 0;
}

// Comparação de inteiros
void compDetalhada(char cidade1[], char cidade2[], unsigned long int valor1, unsigned long int valor2) {
    printf("Carta 1 - %s: %lu\n", cidade1, valor1);
    printf("Carta 2 - %s: %lu\n", cidade2, valor2);

    if (valor1 > valor2) {
        printf("Resultado: Carta 1 - %s venceu!\n", cidade1);
    } else if (valor1 == valor2) {
        printf("Resultado: Empate!\n");
    } else {
        printf("Resultado: Carta 2 - %s venceu!\n", cidade2);
    }
}

// Comparação de floats
void compDetalhadaFloat(char cidade1[], char cidade2[], float valor1, float valor2, int menorVence) {
    printf("Carta 1 - %s: %.2f\n", cidade1, valor1);
    printf("Carta 2 - %s: %.2f\n", cidade2, valor2);

    if (menorVence) { // regra especial para densidade populacional
        if (valor1 < valor2) {
            printf("Resultado: Carta 1 - %s venceu!\n", cidade1);
        } else if (valor1 == valor2) {
            printf("Resultado: Empate!\n");
        } else {
            printf("Resultado: Carta 2 - %s venceu!\n", cidade2);
        }
    } else { // regra normal
        if (valor1 > valor2) {
            printf("Resultado: Carta 1 - %s venceu!\n", cidade1);
        } else if (valor1 == valor2) {
            printf("Resultado: Empate!\n");
        } else {
            printf("Resultado: Carta 2 - %s venceu!\n", cidade2);
        }
    }
}
