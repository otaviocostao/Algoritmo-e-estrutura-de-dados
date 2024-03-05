#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void fibonacci(int n){
    int b = 1;
    int a = 0;
    int i, val;
    
    if(n>=1){
        printf("%d\n", b);
    }

    for(i=2; i<=n; i++){
        val = a + b;
        a = b;
        b = val;

        printf("%d\n", val);
    }

}

int main() {

    setlocale(LC_ALL, "Portuguese");

    int n;

    printf("-- Série de Fibonacci --\n\n");
    printf("Digite um valor: ");
    scanf("%d", &n);

    fibonacci(n);

    system("pause");
    return 0;
}