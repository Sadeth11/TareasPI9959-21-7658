# Definir una función para ingresar las calificaciones de un alumno
def ingresar_calificaciones():
    calificaciones = []
    for i in range(5):
        nota = float(input(f"Ingrese la nota del curso {i+1}: "))
        calificaciones.append(nota)
    return calificaciones

# Definir una función para calcular el promedio de un conjunto de notas
def calcular_promedio(notas):
    total = sum(notas)
    promedio = total / len(notas)
    return promedio

# Definir una función para ingresar los datos de un alumno
def ingresar_alumno():
    nombre = input("Ingrese el nombre del alumno: ")
    apellido = input("Ingrese el apellido del alumno: ")
    calificaciones = ingresar_calificaciones()
    promedio = calcular_promedio(calificaciones)
    return nombre, apellido, calificaciones, promedio

# Definir una función para imprimir los datos de un alumno
def imprimir_alumno(nombre, apellido, calificaciones, promedio):
    print(f"{nombre} {apellido}: {calificaciones} - Promedio: {promedio:.2f}")

# Definir una función para imprimir los promedios de todas las calificaciones
def imprimir_promedios(promedios_alumnos):
    promedios_cursos = []
    for i in range(5):
        notas_curso_i = [alumno[2][i] for alumno in promedios_alumnos]
        promedio_curso_i = calcular_promedio(notas_curso_i)
        promedios_cursos.append(promedio_curso_i)
    print(f"Promedios de los cursos: {promedios_cursos}")
    print(f"Promedio de los alumnos: {calcular_promedio(promedios_alumnos)}")

# Definir una función principal para ejecutar el programa
def main():
    alumnos = []
    while True:
        opcion = input("Seleccione una opción:\n1. Ingresar alumno\n2. Salir\nOpción: ")
        if opcion == "1":
            alumno = ingresar_alumno()
            alumnos.append(alumno)
            imprimir_alumno(*alumno)
        elif opcion == "2":
            break
        else:
            print("Opción inválida")
    imprimir_promedios(alumnos)

# Ejecutar la función principal
main()
