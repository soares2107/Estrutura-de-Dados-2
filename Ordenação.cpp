#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

// Função auxiliar para dividir o vetor em duas partes no QuickSort
int partition(vector<string> &arr, int low, int high) {
    string pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Função principal do QuickSort
void quickSort(vector<string> &arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Função para ordenação por SelectionSort
void selectionSort(vector<string> &arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}

// Função auxiliar para comparar strings alfabeticamente
bool comparaAlfabeticamente(const string &a, const string &b) {
    string letrasA = "";
    string letrasB = "";

    // Remove os números iniciais das strings
    for (char c : a) {
        if (isalpha(c)) {
            letrasA += c;
        }
    }

    for (char c : b) {
        if (isalpha(c)) {
            letrasB += c;
        }
    }

    return letrasA < letrasB;
}

int main() {
    fstream arquivo;
    string linha;
    vector<string> linhas;

    arquivo.open("input.txt", ios::in);

    if (arquivo.is_open()) {
        while (getline(arquivo, linha)) {
            linhas.push_back(linha);
        }
        arquivo.close();
       
    
        // Ordenação numérica (QuickSort)
        vector<string> numericoOrdenado = linhas;

        // Mede o tempo de execucao do quicksort (numerico)
        clock_t startQuickNum = clock();

        quickSort(numericoOrdenado, 0, numericoOrdenado.size() - 1);

        clock_t endQuickNum = clock();
        double temQuickNum = static_cast<double>(endQuickNum - startQuickNum) / CLOCKS_PER_SEC;

        // Ordenação numérica (SelectionSort)
        vector<string> numericoOrdenadoSelectionSort = linhas;

        // Mede o tempo de execucao do selection (numerico)
        clock_t startSelNum = clock();

        selectionSort(numericoOrdenadoSelectionSort);

        clock_t endSelNum = clock();
        double temSelNum = static_cast<double>(endSelNum - startSelNum) / CLOCKS_PER_SEC;

        // imprimi a lista ordenada numericamente pelo SelectionSort
        cout << "\nLista ordenada numericamente:" << endl;
        for (const string &str : numericoOrdenadoSelectionSort) {
            cout << str << endl;
        }

        // Imprimi o tempo de execucao
        cout << "Tempo gasto pelo QuickSort na ordenacao numerica: " << temQuickNum << " segundos." << endl;
        
        // Imprimi o tempo de execucao
        cout << "Tempo gasto pelo SelectionSort na ordenacao numerica: " << temSelNum << " segundos." << endl;

        // Ordenação alfabética pelo QuickSort
        vector<string> alfabeticoOrdenadoQuickSort = linhas;

        // Mede o tempo de execucao do quicksort (alfabetico)
        clock_t startQuickAlf = clock();

        sort(alfabeticoOrdenadoQuickSort.begin(), alfabeticoOrdenadoQuickSort.end(), comparaAlfabeticamente);

        clock_t endQuickAlf = clock();
        double temQuickAlf = static_cast<double>(endQuickAlf - startQuickAlf) / CLOCKS_PER_SEC;


        // Ordenação alfabética pelo SelectionSort
        vector<string> alfabeticoOrdenadoSelectionSort = linhas;

        // Mede o tempo de execucao do selectionsort (alfabetico)
        clock_t startSelAlf = clock();

        selectionSort(alfabeticoOrdenadoSelectionSort);

        clock_t endSelAlf = clock();
        double temSelAlf = static_cast<double>(endSelAlf - startSelAlf) / CLOCKS_PER_SEC;
        
        // imprimi a lista ordenada alfabeticamente
        cout << "\nLista ordenada alfabeticamente:" << endl;
        for (const string &str : alfabeticoOrdenadoQuickSort) {
            cout << str << endl;
        }

        // Imprimi o tempo de execucao
        cout << "Tempo gasto pelo QuickSort na ordenacao alfabetica: " << temQuickAlf << " segundos." << endl;
        
        // Imprimi o tempo de execucao
        cout << "Tempo gasto pelo SelectionSort na ordenacao alfabetica: " << temSelAlf << " segundos." << endl;

    } else {
        cout << "Não foi possível abrir o arquivo 'input.txt'!" << endl;
    }

    return 0;
}
