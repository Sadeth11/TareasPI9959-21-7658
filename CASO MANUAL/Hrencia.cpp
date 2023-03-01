/*Desarrolle el siguiente tema: PROGRAMACIÓN ORIENTADA  A OBJETOS - PROPIEDAD HERENCIA

     1.Deberá exponer sus ideas acerca del tema solicitado,  como mínimo dos páginas de contenido (1000 palabras).   Debe desarrollarse a MANO.

     2.Deberá colocar un ejemplo de como demostraría (ejecución) el tema anterior en C++ y gestionarlo con Git y Github. 

     Luego haciendo uso del cuadernillo para respuestas pegue las fotos del desarrollo y el link de su repositorio en Github y envié un archivo PDF.    */
#include <iostream>
#include <string>

using namespace std;

class Contacto {
public:
    string nombre;
    string telefono;
    string correo;
};

class ContactoPersonal: public Contacto {
public:
    string relacion;

};

class ContactoProfesional: public Contacto {
public:
    string cargo;
};

int main (){
    ContactoPersonal contacto_personal;
    contacto_personal.nombre = "Samahel Thomas";
    contacto_personal.telefono = "555-1234";
    contacto_personal.correo = "juasjuas@gmail.com";
    contacto_personal.relacion = "Familia";

    ContactoProfesional contacto_profesional;
    contacto_profesional.nombre = "Derek Thomas";
    contacto_profesional.telefono = "555-5678";
    contacto_profesional.correo = "juasjuas@empresa.com";
    contacto_profesional.cargo = "gerente";
    
    cout << "Contacto personal: " << contacto_personal.nombre << ", " << contacto_personal.telefono << ", " << contacto_personal.correo << ", " << contacto_personal.relacion << endl;
    cout << "Contacto profesional: " << contacto_profesional.nombre << ", " << contacto_profesional.telefono << ", " << contacto_profesional.correo << ", " << contacto_profesional.cargo << endl;
    
    return 0;
}

