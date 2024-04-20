public class BubbleSort {
    public static void main(String[] args) {
        int X[] = {10, 8, 6, 4, 2, 9, 7, 5, 3, 1}; // Vetor predefinido de 10 posições
        int n, i, aux;

        // Ordenando de forma crescente
        // Laço com a quantidade de elementos do vetor
        for (n = 1; n <= X.length; n++) {
            // Laço que percorre da primeira à penúltima posição do vetor
            for (i = 0; i < 9; i++) {
                if (X[i] > X[i + 1]) {
                    aux = X[i];
                    X[i] = X[i + 1];
                    X[i + 1] = aux;
                }
            }
        }

        // Mostrando o vetor ordenado
        for (i = 0; i < 10; i++) {
            System.out.println((i + 1) + "º número: " + X[i]);
        }
    }
}
