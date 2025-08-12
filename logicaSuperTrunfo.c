#include <stdio.h>
#include <stdlib.h>

// Funções para comparação detalhada
void compDetalhada(char cidade1[20], char cidade2[20], unsigned long int val1, unsigned long int val2) {
    printf("Carta 1 - %s: %lu\n", cidade1, val1);
    printf("Carta 2 - %s: %lu\n", cidade2, val2);

    if (val1 > val2) {
        printf("Resultado: Carta 1 - %s venceu!\n", cidade1);
    } else if (val1 == val2) {
        printf("Resultado: Carta 1 - %s e Carta 2 - %s empataram\n", cidade1, cidade2);
    } else {
        printf("Resultado: Carta 2 - %s venceu!\n", cidade2);
    }
}

void compDetalhadaFloat(char cidade1[20], char cidade2[20], float val1, float val2, int menorVence) {
    printf("Carta 1 - %s: %.2f\n", cidade1, val1);
    printf("Carta 2 - %s: %.2f\n", cidade2, val2);

    if (!menorVence) {
        if (val1 > val2) {
            printf("Resultado: Carta 1 - %s venceu!\n", cidade1);
        } else if (val1 == val2) {
            printf("Resultado: Carta 1 - %s e Carta 2 - %s empataram\n", cidade1, cidade2);
        } else {
            printf("Resultado: Carta 2 - %s venceu!\n", cidade2);
        }
    } else {
        if (val1 < val2) {
            printf("Resultado: Carta 1 - %s venceu!\n", cidade1);
        } else if (val1 == val2) {
            printf("Resultado: Carta 1 - %s e Carta 2 - %s empataram\n", cidade1, cidade2);
        } else {
            printf("Resultado: Carta 2 - %s venceu!\n", cidade2);
        }
    }
}

int main() {
    // Declaração das variáveis
    char estado_1[3], estado_2[3];
    char codigo_1[10], codigo_2[10];
    char nome_cidade_1[20], nome_cidade_2[20];
    unsigned long int populacao_1, populacao_2;
    float area_km_1, area_km_2;
    float PIB_1, PIB_2;
    int pontos_turisticos_1, pontos_turisticos_2;
    float densi_Pop1, densi_Pop2;
    float PIB_perCap1, PIB_perCap2;
    float SuperPoder1, SuperPoder2;

    printf("=== Jogo Super Trunfo ===\n");

   // CARTA 1
    printf("Digite os dados da primeira carta -->\n");
    printf("Digite o estado da carta de A a H: \n");
    scanf(" %c", &estado_1);

    printf("Digite o codigo da carta (estado + numero de 01 a 04): \n");
    scanf("%s", codigo_1);

    printf("Digite o nome da cidade: \n");
    scanf("%s", nome_cidade_1); 

    printf("Digite a populacao da cidade: \n");
    scanf("%lu", &populacao_1);

    printf("Digite a area (em km quadrado) da cidade: \n");
    scanf("%f", &area_km_1);

    printf("Digite PIB da cidade: \n");
    scanf("%f", &PIB_1);

    printf("Digite o numero de pontos turisticos da cidade: \n");
    scanf("%d", &pontos_turisticos_1);
    
    densi_Pop1 = populacao_1 / area_km_1;
    PIB_perCap1 = PIB_1 / populacao_1;
    SuperPoder1 = populacao_1 + area_km_1 + PIB_1 + pontos_turisticos_1 + PIB_perCap1 + (1 / densi_Pop1);
    
    

    printf("\n ____________________________________________________ \n");

    // CARTA 2
    printf("Digite os dados da segunda carta --> \n");
    printf("Digite o estado da carta de A a H: \n");
    scanf(" %c", &estado_2);

    printf("Digite o codigo da carta (estado + numero de 01 a 04): \n");
    scanf("%s", codigo_2);

    printf("Digite o nome da cidade: \n");
    scanf("%s", nome_cidade_2); 

    printf("Digite a populacao da cidade: \n");
    scanf("%lu", &populacao_2);

    printf("Digite a area (em km quadrado) da cidade: \n");
    scanf("%f", &area_km_2);

    printf("Digite PIB da cidade: \n");
    scanf("%f", &PIB_2);

    printf("Digite o numero de pontos turisticos da cidade: \n");
    scanf("%d", &pontos_turisticos_2);
    
    densi_Pop2 = populacao_2 / area_km_2;
    PIB_perCap2 = PIB_2 / populacao_2;
    SuperPoder2 = populacao_2 + area_km_2 + PIB_2 + pontos_turisticos_2 + PIB_perCap2 + (1 / densi_Pop2);
    
    printf("\n====================================================\n");

    // ESCOLHA DO ATRIBUTO NO CÓDIGO
    // 1=População, 2=Área, 3=PIB, 4=Densidade Populacional, 5=PIB per capita, 6=Super Poder
    int atributoEscolhido = 6; // altere aqui para escolher o atributo

    printf("Comparacao de cartas (Atributo: ");

    switch (atributoEscolhido) {
        case 1:
            printf("Populacao):\n");
            compDetalhada(nome_cidade_1, nome_cidade_2, populacao_1, populacao_2);
            break;
        case 2:
            printf("Area):\n");
            compDetalhadaFloat(nome_cidade_1, nome_cidade_2, area_km_1, area_km_2, 0);
            break;
        case 3:
            printf("PIB):\n");
            compDetalhadaFloat(nome_cidade_1, nome_cidade_2, PIB_1, PIB_2, 0);
            break;
        case 4:
            printf("Densidade Populacional):\n");
            compDetalhadaFloat(nome_cidade_1, nome_cidade_2, densi_Pop1, densi_Pop2, 1);
            break;
        case 5:
            printf("PIB per Capita):\n");
            compDetalhadaFloat(nome_cidade_1, nome_cidade_2, PIB_perCap1, PIB_perCap2, 0);
            break;
        case 6:
            printf("Super Poder):\n");
            compDetalhadaFloat(nome_cidade_1, nome_cidade_2, SuperPoder1, SuperPoder2, 0);
            break;
        default:
            printf("Atributo invalido!\n");
            break;
    }

    return 0;
}
