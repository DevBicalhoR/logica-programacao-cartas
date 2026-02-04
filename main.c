#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));

    char estado1[10], estado2[10] = "PR";
    char nome_cidade1[50], nome_cidade2[50] = "Curitiba";
    char codigo1[5], codigo2[5] = "A02"; 
    unsigned int ponto_turistico1, ponto_turistico2 = rand() % 10 + 1, comparacaoCartas;
    float populacao1, area1, pib1;
    
    float populacao2 = (rand() % 9000000) / 1000.0 + 1000;
    float area2 = (rand() % 95000) / 100.0 + 50;
    float pib2 = (rand() % 4001) / 10.0 + 10;

    printf("--- Cadastro da Carta 01 ---\n");
    printf("Digite a letra do estado (A-H): ");
    scanf(" %s", estado1);
    printf("Digite o código da carta (ex: 01): ");
    scanf(" %s", codigo1);
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nome_cidade1); 
    printf("Digite a população: ");
    scanf("%f", &populacao1);
    printf("Digite a área (km²): ");
    scanf("%f", &area1);
    printf("Digite o PIB (bilhões): ");
    scanf("%f", &pib1);
    printf("Digite o número de pontos turísticos: ");
    scanf("%u", &ponto_turistico1);

    float densidadepop1 = populacao1 / area1, densidadepop2 = populacao2 / area2;
    float pibpercapita1 = pib1 / populacao1, pibpercapita2 = pib2 / populacao2;
    
    float superPoder1 = populacao1 + area1 + pib1 + ponto_turistico1 + pibpercapita1 + (1/densidadepop1);
    float superPoder2 = populacao2 + area2 + pib2 + ponto_turistico2 + pibpercapita2 + (1/densidadepop2);

    printf("\n=== CARTA 1: %s%s - %s ===\n", estado1, codigo1, nome_cidade1);
    printf("População: %.2f habitantes | Área: %.2f km² | PIB: %.2f bilhões\n", populacao1, area1, pib1);
    printf("Pontos Turísticos: %u | Densidade: %.2f hab/km²\n", ponto_turistico1, densidadepop1);
    printf("Super Poder: %.2f\n", superPoder1);

    printf("\n=== CARTA 2: %s - %s ===\n", codigo2, nome_cidade2);
    printf("População: %.2f habitantes | Área: %.2f km² | PIB: %.2f bilhões\n", populacao2, area2, pib2);
    printf("Pontos Turísticos: %u | Densidade: %.2f hab/km²\n", ponto_turistico2, densidadepop2);
    printf("Super Poder: %.2f\n", superPoder2);

    printf("\n--- Comparação De Cartas ---\n");
    printf("Escolha o atributo para o duelo:\n1. Populacao\n2. Area\n3. PIB\n4. Pontos Turisticos\n5. Densidade Demografica\n");
    scanf("%d", &comparacaoCartas);

    printf("\nRESULTADO DO DUELO:\n");
    switch (comparacaoCartas) {
        case 1:
            printf("Atributo: População (habitantes)\n");
            printf("%s: %.2f vs %s: %.2f\n", nome_cidade1, populacao1, nome_cidade2, populacao2);
            if (populacao1 > populacao2) printf("Vencedor: Carta 1 (%s)\n", nome_cidade1);
            else if (populacao1 < populacao2) printf("Vencedor: Carta 2 (%s)\n", nome_cidade2);
            else printf("Empate!\n");
            break;
        case 2:
            printf("Atributo: Área (km²)\n");
            printf("%s: %.2f km² vs %s: %.2f km²\n", nome_cidade1, area1, nome_cidade2, area2);
            if (area1 > area2) printf("Vencedor: Carta 1 (%s)\n", nome_cidade1);
            else if (area1 < area2) printf("Vencedor: Carta 2 (%s)\n", nome_cidade2);
            else printf("Empate!\n");
            break;
        case 3:
            printf("Atributo: PIB (bilhões)\n");
            printf("%s: %.2f vs %s: %.2f\n", nome_cidade1, pib1, nome_cidade2, pib2);
            if (pib1 > pib2) printf("Vencedor: Carta 1 (%s)\n", nome_cidade1);
            else if (pib1 < pib2) printf("Vencedor: Carta 2 (%s)\n", nome_cidade2);
            else printf("Empate!\n");
            break;
        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %u vs %s: %u\n", nome_cidade1, ponto_turistico1, nome_cidade2, ponto_turistico2);
            if (ponto_turistico1 > ponto_turistico2) printf("Vencedor: Carta 1 (%s)\n", nome_cidade1);
            else if (ponto_turistico1 < ponto_turistico2) printf("Vencedor: Carta 2 (%s)\n", nome_cidade2);
            else printf("Empate!\n");
            break;
        case 5:
            printf("Atributo: Densidade (hab/km² - MENOR vence)\n");
            printf("%s: %.2f vs %s: %.2f\n", nome_cidade1, densidadepop1, nome_cidade2, densidadepop2);
            if (densidadepop1 < densidadepop2) printf("Vencedor: Carta 1 (%s)\n", nome_cidade1);
            else if (densidadepop1 > densidadepop2) printf("Vencedor: Carta 2 (%s)\n", nome_cidade2);
            else printf("Empate!\n");
            break;
        default:
            printf("Opção inválida.\n");
    }

    printf("\nDuelo de Super Poder: ");
    if (superPoder1 > superPoder2) printf("Carta 1 VENCEU!\n");
    else if (superPoder1 < superPoder2) printf("Carta 2 VENCEU!\n");
    else printf("Empate no Super Poder!\n");

    return 0;
}
