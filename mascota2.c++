#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

using namespace std;

class Gato {
private:
    int energia;
    int hambre;
    int felicidad;
    string nombre;

public:
    Gato(string nom) {
        nombre = nom;
        energia = 10;
        hambre = 10;
        felicidad = 10;
    }

    bool esta_vivo() {
        return energia > 0 && hambre <= 10 && felicidad > 0;
    }

    void jugar() {
        cout << nombre << " está jugando:" << endl;
        cout << "     ( =①ω①= )" << endl;
        cout << "    (  /   \\  )" << endl;
        cout << "      \\_   _/  " << endl;
        cout << "      /     \\ " << endl;
        energia -= 2;
        felicidad += 2;
        hambre += 1;
        ajustar();
    }

    void dormir() {
        cout << nombre << " está durmiendo:" << endl;
        cout << "     ( =①ω①= )" << endl;
        cout << "      ZZZZZZZ" << endl;
        energia += 3;
        hambre += 1;
        ajustar();
    }

    void comer() {
        cout << nombre << " está comiendo:" << endl;
        cout << "     ( =①ω①= )" << endl;
        cout << "     (   \"   )" << endl;
        cout << "    * NOM NOM *" << endl;
        hambre -= 3;
        energia += 1;
        ajustar();
    }

    void mostrar_estado() {
        cout << "\nEstado de " << nombre << ":" << endl;
        cout << "Energía: " << energia << " | Hambre: " << hambre << " | Felicidad: " << felicidad << endl;
    }

    void modo_automatico() {
        cout << "\nModo automático activado..." << endl;
        int acciones[] = {1, 2, 3};  // 1 = jugar, 2 = dormir, 3 = comer
        for (int i = 0; i < 3; i++) {
            int accion = acciones[rand() % 3];
            switch (accion) {
                case 1:
                    jugar();
                    break;
                case 2:
                    dormir();
                    break;
                case 3:
                    comer();
                    break;
            }
            sleep(2);  // Pausa entre acciones automáticas
        }
        cout << "Modo automático finalizado." << endl;
    }

private:
    void ajustar() {
        if (hambre < 0) hambre = 0;
        if (hambre > 10) hambre = 10;
        if (energia < 0) energia = 0;
        if (energia > 10) energia = 10;
        if (felicidad < 0) felicidad = 0;
        if (felicidad > 10) felicidad = 10;
    }
};

int main() {
    srand(time(0));
    string nombre;
    int opcion;

    cout << "¡Bienvenido al juego! ¿Cómo se llamará tu gato? ";
    getline(cin, nombre);
    Gato miGato(nombre);

    while (miGato.esta_vivo()) {
        cout << "\n¿Qué deseas hacer con " << nombre << "?" << endl;
        cout << "1. Ver estado del gato" << endl;
        cout << "2. Jugar con " << nombre << endl;
        cout << "3. Dejar que " << nombre << " duerma" << endl;
        cout << "4. Alimentar a " << nombre << endl;
        cout << "5. Activar modo automático" << endl;
        cout << "6. Salir del juego" << endl;
        cout << "Selecciona una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                miGato.mostrar_estado();
                break;
            case 2:
                miGato.jugar();
                break;
            case 3:
                miGato.dormir();
                break;
            case 4:
                miGato.comer();
                break;
            case 5:
                miGato.modo_automatico();
                break;
            case 6:
                cout << "¡Hasta luego! Saliste del juego." << endl;
                return 0;
            default:
                cout << "Opción no válida, por favor selecciona de nuevo." << endl;
                break;
        }
    }

    cout << nombre << " ya no está con nosotros." << endl;
    return 0;
}
