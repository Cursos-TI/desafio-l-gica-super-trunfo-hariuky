#include <stdio.h>
#include <stdlib.h>

// Funcoes para comparacao detalhada
void compDetalhada(char cidade1[20], char cidade2[20], unsigned long int val1, unsigned long int val2, int* resultado) {
    printf("  %s: %lu vs %lu\n", cidade1, val1, val2);

    if (val1 > val2) {
        *resultado = 1; // carta 1 vence
    } else if (val1 == val2) {
        *resultado = 0; // empate
    } else {
        *resultado = 2; // carta 2 vence
    }
}

void compDetalhadaFloat(char cidade1[20], char cidade2[20], float val1, float val2, int menorVence, int* resultado) {
    printf("  %s: %.2f vs %.2f\n", cidade1, val1, val2);

    if (!menorVence) {
        if (val1 > val2) *resultado = 1;
        else if (val1 == val2) *resultado = 0;
        else *resultado = 2;
    } else {
        if (val1 < val2) *resultado = 1;
        else if (val1 == val2) *resultado = 0;
        else *resultado = 2;
    }
}

// Funcao para exibir o nome do atributo
void nomeAtributo(int op) {
    switch (op) {
        case 1: printf("Populacao"); break;
        case 2: printf("Area"); break;
        case 3: printf("PIB"); break;
        case 4: printf("Densidade Populacional"); break;
        case 5: printf("PIB per Capita"); break;
        case 6: printf("Super Poder"); break;
        default: printf("Atributo invalido"); break;
    }
}

int main() {
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

    // Entrada da primeira carta
    printf("Digite os dados da primeira carta -->\n");
    printf("Estado da carta (A-H): ");
    scanf(" %c", &estado_1[0]);
    estado_1[1] = '\0';

    printf("Codigo da carta (estado + numero 01 a 04): ");
    scanf("%s", codigo_1);

    printf("Nome da cidade: ");
    scanf("%s", nome_cidade_1);

    printf("Populacao da cidade: ");
    scanf("%lu", &populacao_1);

    printf("Area (km2): ");
    scanf("%f", &area_km_1);

    printf("PIB da cidade: ");
    scanf("%f", &PIB_1);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos_1);

    densi_Pop1 = populacao_1 / area_km_1;
    PIB_perCap1 = PIB_1 / populacao_1;
    SuperPoder1 = populacao_1 + area_km_1 + PIB_1 + pontos_turisticos_1 + PIB_perCap1 + (1 / densi_Pop1);

    printf("\n____________________________________________________\n");

    // Entrada da segunda carta
    printf("Digite os dados da segunda carta -->\n");
    printf("Estado da carta (A-H): ");
    scanf(" %c", &estado_2[0]);
    estado_2[1] = '\0';

    printf("Codigo da carta (estado + numero 01 a 04): ");
    scanf("%s", codigo_2);

    printf("Nome da cidade: ");
    scanf("%s", nome_cidade_2);

    printf("Populacao da cidade: ");
    scanf("%lu", &populacao_2);

    printf("Area (km2): ");
    scanf("%f", &area_km_2);

    printf("PIB da cidade: ");
    scanf("%f", &PIB_2);

    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos_turisticos_2);

    densi_Pop2 = populacao_2 / area_km_2;
    PIB_perCap2 = PIB_2 / populacao_2;
    SuperPoder2 = populacao_2 + area_km_2 + PIB_2 + pontos_turisticos_2 + PIB_perCap2 + (1 / densi_Pop2);

    printf("\n====================================================\n");

    int primeiroAtributo, segundoAtributo;

    // Escolha do primeiro atributo
    do {
        printf("Escolha o primeiro atributo para comparar:\n");
        printf("1=Populacao, 2=Area, 3=PIB, 4=Densidade Populacional, 5=PIB per capita, 6=Super Poder\n");
        scanf("%d", &primeiroAtributo);
        if (primeiroAtributo < 1 || primeiroAtributo > 6)
            printf("Atributo invalido! Tente novamente.\n");
    } while (primeiroAtributo < 1 || primeiroAtributo > 6);

    // Escolha do segundo atributo (nao pode ser igual ao primeiro)
    do {
        printf("Escolha o segundo atributo para comparar (diferente do primeiro):\n");
        printf("1=Populacao, 2=Area, 3=PIB, 4=Densidade Populacional, 5=PIB per capita, 6=Super Poder\n");
        scanf("%d", &segundoAtributo);
        if (segundoAtributo < 1 || segundoAtributo > 6)
            printf("Atributo invalido! Tente novamente.\n");
        else if (segundoAtributo == primeiroAtributo)
            printf("Voce ja escolheu esse atributo. Escolha outro.\n");
    } while (segundoAtributo < 1 || segundoAtributo > 6 || segundoAtributo == primeiroAtributo);

    printf("\nComparacao entre as cidades %s e %s:\n", nome_cidade_1, nome_cidade_2);

    // Variaveis para armazenar os valores dos atributos escolhidos
    float val1_atr1 = 0, val2_atr1 = 0;
    float val1_atr2 = 0, val2_atr2 = 0;

    int res1 = 0, res2 = 0; // Resultado da comparacao de cada atributo (1=carta1 vence, 2=carta2 vence, 0=empate)

    // Funcao para pegar valor do atributo pela opcao
    float getValorAtributo(int atributo, unsigned long int pop1, unsigned long int pop2, float area1, float area2, float pib1, float pib2,
                          float densi1, float densi2, float pibpc1, float pibpc2, float sp1, float sp2, int carta) {
        switch (atributo) {
            case 1: return (carta == 1) ? pop1 : pop2;
            case 2: return (carta == 1) ? area1 : area2;
            case 3: return (carta == 1) ? pib1 : pib2;
            case 4: return (carta == 1) ? densi1 : densi2;
            case 5: return (carta == 1) ? pibpc1 : pibpc2;
            case 6: return (carta == 1) ? sp1 : sp2;
            default: return 0;
        }
    }

    // Obter valores dos atributos
    val1_atr1 = getValorAtributo(primeiroAtributo, populacao_1, populacao_2, area_km_1, area_km_2, PIB_1, PIB_2, densi_Pop1, densi_Pop2, PIB_perCap1, PIB_perCap2, SuperPoder1, SuperPoder2, 1);
    val2_atr1 = getValorAtributo(primeiroAtributo, populacao_1, populacao_2, area_km_1, area_km_2, PIB_1, PIB_2, densi_Pop1, densi_Pop2, PIB_perCap1, PIB_perCap2, SuperPoder1, SuperPoder2, 2);

    val1_atr2 = getValorAtributo(segundoAtributo, populacao_1, populacao_2, area_km_1, area_km_2, PIB_1, PIB_2, densi_Pop1, densi_Pop2, PIB_perCap1, PIB_perCap2, SuperPoder1, SuperPoder2, 1);
    val2_atr2 = getValorAtributo(segundoAtributo, populacao_1, populacao_2, area_km_1, area_km_2, PIB_1, PIB_2, densi_Pop1, densi_Pop2, PIB_perCap1, PIB_perCap2, SuperPoder1, SuperPoder2, 2);

    printf("\nAtributos comparados:\n");

    // Comparar primeiro atributo
    printf("1) ");
    nomeAtributo(primeiroAtributo);
    printf(":\n");

    if (primeiroAtributo == 1 || primeiroAtributo == 4 || primeiroAtributo == 5) {
        int menorVence = (primeiroAtributo == 4) ? 1 : 0;
        if (primeiroAtributo == 1) {
            compDetalhada(nome_cidade_1, nome_cidade_2, (unsigned long int)val1_atr1, (unsigned long int)val2_atr1, &res1);
        } else {
            compDetalhadaFloat(nome_cidade_1, nome_cidade_2, val1_atr1, val2_atr1, menorVence, &res1);
        }
    } else {
        compDetalhadaFloat(nome_cidade_1, nome_cidade_2, val1_atr1, val2_atr1, 0, &res1);
    }

    // Comparar segundo atributo
    printf("\n2) ");
    nomeAtributo(segundoAtributo);
    printf(":\n");

    if (segundoAtributo == 1 || segundoAtributo == 4 || segundoAtributo == 5) {
        int menorVence = (segundoAtributo == 4) ? 1 : 0;
        if (segundoAtributo == 1) {
            compDetalhada(nome_cidade_1, nome_cidade_2, (unsigned long int)val1_atr2, (unsigned long int)val2_atr2, &res2);
        } else {
            compDetalhadaFloat(nome_cidade_1, nome_cidade_2, val1_atr2, val2_atr2, menorVence, &res2);
        }
    } else {
        compDetalhadaFloat(nome_cidade_1, nome_cidade_2, val1_atr2, val2_atr2, 0, &res2);
    }

    // Soma dos valores dos atributos para cada carta
    float somaCarta1 = val1_atr1 + val1_atr2;
    float somaCarta2 = val2_atr1 + val2_atr2;

    printf("\nSoma dos atributos:\n");
    printf(" %s: %.2f\n", nome_cidade_1, somaCarta1);
    printf(" %s: %.2f\n", nome_cidade_2, somaCarta2);

    // Decidir vencedor pela soma
    if (somaCarta1 > somaCarta2) {
        printf("\nResultado final: Carta 1 - %s venceu a rodada!\n", nome_cidade_1);
    } else if (somaCarta1 < somaCarta2) {
        printf("\nResultado final: Carta 2 - %s venceu a rodada!\n", nome_cidade_2);
    } else {
        printf("\nResultado final: Empate!\n");
    }

    return 0;
}
