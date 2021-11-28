#include <stdio.h>
#include <stdlib.h>

/*
    Le coefficient binomial de deux entiers n et k tel que n >= k >= 0
    est défini récursivement comme suit :
        - Si k = 0 ou n = k alors -> 1.
        - Sionon CoefBinomial(n, k) = CoefBinomial(n - 1, k) + CoefBinomial(n - 1, k - 1).
*/

int coefBinomial(int n, int k) {
    if (k == 0 || k == n) return 1; // Cas de base
    else return coefBinomial(n - 1, k) + coefBinomial(n - 1, k - 1); // Relation de récurrence
}

int main() {
    int n, k, c;
    printf("Donnez la val de n : ");
    scanf("%d", &n);
    printf("Donnez la val de k : ");
    scanf("%d", &k);
    if (n >= k && k >= 0) {
        c = coefBinomial(n, k);
        printf("Le coefficient binomial de %d et %d est %d", n, k, c);
    }
    else printf("Impossible de calculer le coef1");
    return 0;
}
