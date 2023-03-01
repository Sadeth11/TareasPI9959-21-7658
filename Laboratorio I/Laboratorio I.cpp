/*Deberá  construir  un  programa  que  gestione  las  calificaciones  de  alumnos  de  un  colegio  de 
acuerdo con lo siguiente: 
a. Deberá utilizar menús, ciclos y funciones para realizar el programa. 
b. Deberá  permitir  ingresar  varios  alumnos  por  medio  de  un  ciclo  y  al  final  presentar  los 
promedios de las notas de cada curso y de los alumnos. 
c. Deberá ingresar los nombres y apellidos de los alumnos. 
d. Deberá ingresar las notas correspondientes a 5 cursos por alumno. 
e. Deberá desplegar los totales y promedio de notas de cada alumno. */

#include <iostream>
#include <string>

using namespace std;

const int NUM_COURSES = 5; // Definimos una constante para el número de cursos

// Función para obtener las notas de un alumno
void getGrades(double grades[]) {
    for(int i = 0; i < NUM_COURSES; i++) {
        cout << "Ingrese la nota del curso " << i+1 << ": ";
        cin >> grades[i];
    }
}

// Función para calcular el promedio de un alumno
double calculateAverage(double grades[]) {
    double sum = 0;
    for(int i = 0; i < NUM_COURSES; i++) {
        sum += grades[i];
    }
    return sum / NUM_COURSES;
}

int main() {
    int numStudents;
    cout << "Ingrese el número de alumnos: ";
    cin >> numStudents;

    // Creamos los arrays para almacenar los nombres y las notas de los alumnos
    string names[numStudents];
    double grades[numStudents][NUM_COURSES];

    // Ciclo para obtener los datos de los alumnos
    for(int i = 0; i < numStudents; i++) {
        cout << "\nIngrese el nombre del alumno " << i+1 << ": ";
        cin >> names[i];
        cout << "Ingrese las notas del alumno " << i+1 << ":\n";
        getGrades(grades[i]);
    }

    // Ciclo para mostrar los promedios de los alumnos
    cout << "\nPromedio de notas de cada alumno:\n";
    for(int i = 0; i < numStudents; i++) {
        double avg = calculateAverage(grades[i]);
        cout << names[i] << ": " << avg << endl;
    }

    // Ciclo para mostrar los promedios de cada curso
    cout << "\nPromedio de notas de cada curso:\n";
    for(int i = 0; i < NUM_COURSES; i++) {
        double sum = 0;
        for(int j = 0; j < numStudents; j++) {
            sum += grades[j][i];
        }
        double avg = sum / numStudents;
        cout << "Curso " << i+1 << ": " << avg << endl;
    }

    return 0;
}
