
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

const int FILAS = 10; // Número de alumnos por facultad
const int COLUMNAS = 4; // Número de exámenes

// Función para generar notas aleatorias entre 0 y 100
int generarNota() {
    return rand() % 101;
}

// Función para calcular el promedio de una fila
double calcularPromedio(int fila[]) {
    double sum = 0;
    for (int j = 0; j < COLUMNAS; j++) {
        sum += fila[j];
    }
    return sum / COLUMNAS;
}

int main() {
    // Inicializar semilla aleatoria
    srand(time(NULL));

    // Declarar matrices para las facultades
    int ingenieria[FILAS][COLUMNAS];
    int arquitectura[FILAS][COLUMNAS];
    int administracion[FILAS][COLUMNAS];

    // Generar notas aleatorias para cada facultad
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            ingenieria[i][j] = generarNota();
            arquitectura[i][j] = generarNota();
            administracion[i][j] = generarNota();
        }
    }

    // Calcular promedio de cada alumno y guardar el mejor de cada facultad
    double mejorIngenieria = 0, mejorArquitectura = 0, mejorAdministracion = 0;
    string mejorAlumnoIngenieria, mejorAlumnoArquitectura, mejorAlumnoAdministracion;
    for (int i = 0; i < FILAS; i++) {
        double promedioIngenieria = calcularPromedio(ingenieria[i]);
        double promedioArquitectura = calcularPromedio(arquitectura[i]);
        double promedioAdministracion = calcularPromedio(administracion[i]);

        if (promedioIngenieria > mejorIngenieria) {
            mejorIngenieria = promedioIngenieria;
            mejorAlumnoIngenieria = "Alumno " + to_string(i+1);
        }
        if (promedioArquitectura > mejorArquitectura) {
            mejorArquitectura = promedioArquitectura;
            mejorAlumnoArquitectura = "Alumno " + to_string(i+1);
        }
        if (promedioAdministracion > mejorAdministracion) {
            mejorAdministracion = promedioAdministracion;
            mejorAlumnoAdministracion = "Alumno " + to_string(i+1);
        }
    }

    // Calcular promedio general y guardar el mejor alumno
    double promedioGeneralMejor = 0;
    string mejorAlumnoGeneral;
    for (int i = 0; i < FILAS; i++) {
        double promedio = (calcularPromedio(ingenieria[i]) + calcularPromedio(arquitectura[i]) + calcularPromedio(administracion[i])) / 3.0;
        if (promedio > promedioGeneralMejor) {
            promedioGeneralMejor = promedio;
            mejorAlumnoGeneral = "Alumno " + to_string(i+1);
        }
 }
