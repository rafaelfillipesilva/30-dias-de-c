#ifndef PONTOS_30_DIAS_DE_C_7_2
#define PONTOS_30_DIAS_DE_C_7_2

#define MAX_NUMBER_LENGTH 32U

#ifdef __cplusplus
extern "C" {
#endif

struct ponto
{
    double x;
    double y;
};

double calcular_distancia(struct ponto a, struct ponto b);

void run_pontos();

#ifdef __cplusplus
}
#endif

#endif // PONTOS_30_DIAS_DE_C_7_2
