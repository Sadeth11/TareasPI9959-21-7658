#include <iostream>
#include <string>

using namespace std;

int main() {
    const int N = 10; // Número de preguntas
    const string respuestas_correctas = "ABBADCDBCA"; // Respuestas correctas
    string respuestas_alumno; // Respuestas del alumno
    int calificacion = 0; // Calificación del alumno
    
    // Pedir al usuario que ingrese las respuestas del examen
    cout << "Ingrese las respuestas del examen (A, B, C o D): ";
    getline(cin, respuestas_alumno);
    
    // Comparar las respuestas del alumno con las respuestas correctas y calcular la calificación
    for (int i = 0; i < N; i++) {
        if (respuestas_alumno[i] == respuestas_correctas[i]) {
            calificacion++;
        }
    }
    
    // Mostrar la calificación obtenida
    cout << "La calificacion obtenida es: " << calificacion << "/" << N << endl;
    
    return 0;
}
