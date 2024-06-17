/*
Usted forma parte del equipo de programación que se encargará de hacer el módulo en cuestión que a
partir de ahora se llamará módulo To-Do:Tareas
Cada empleado tiene un listado de tareas a realizar y debe indicar en el sistema si fueron
realizadas o no. 
*Para ello deberá crear dos listas enlazadas: una para las tareas pendientes y
*otra para las tareas realizadas. Cada vez que se marque una tarea como realizada deberá
*mover la tarea de la lista de tareas pendientes a la lista de tareas realizadas.
Las estructuras de datos necesarias son las siguientes:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TAMA 100

typedef struct Tarea
{
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}Tarea;

typedef struct Nodo
{
    Tarea T;
    struct Nodo* Siguiente;
}Nodo;

int ID = 1000;
int GenerarTareaID();
Nodo* CrearListaVacia();
Nodo* CrearNodo();
void AgregarNodoALista(Nodo* nodo, Nodo ** lista);

int main()
{
    Nodo* listaTareasPendientes = CrearListaVacia();
    Nodo* listaTareasRealizadas = CrearListaVacia();
    int opcion = 0;
    do
    {
        printf("Seleccione una opcion:\n\n");
        printf("1. Agregar tarea pendiente\n");
        printf("2. Marcar tarea como realizada\n");
        printf("3. Mostrar tareas pendientes y realizadas\n");
        printf("4. Buscar tarea\n");

        printf("\n0. Salir\n");
        scanf("%d",&opcion);
        switch (opcion)
        {
        case 1:
            AgregarNodoALista(CrearNodo(),&listaTareasPendientes);
            printf("\nTarea agregada exitosamente.\n\n");
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        case 0:
        printf("Saliendo...\n");
        break;
        default:
        printf("\n ERROR - Opcion no valida\n");
            break;
        }
    } while (opcion != 0);






    return 0;
}

int GenerarTareaID()
{
    return ID++;
}

Nodo* CrearListaVacia()
{
    return NULL;
}

Nodo *CrearNodo()
{
    char descripcion[TAMA];
    int duracion;
    Nodo *nuevoNodo = (Nodo *)malloc(sizeof(Nodo));
    nuevoNodo->T.TareaID = GenerarTareaID();

    printf("Ingrese la descripcion de la tarea: ");
    scanf("%s",&descripcion);
    nuevoNodo->T.Descripcion = (char*)malloc(sizeof(char) * strlen(descripcion) + 1);
    strcpy(nuevoNodo->T.Descripcion, descripcion);

    printf("Ingrese la duracion de la tarea (10-100): ");
    scanf("%d",&duracion);
    while (duracion < 10 || duracion > 100)
    {
        puts("Por favor ingrese un numero valido entre 10 y 100");
        scanf("%d", &duracion);
    }
    nuevoNodo->T.Duracion = duracion;
    nuevoNodo->Siguiente = NULL;
    return nuevoNodo;
}

void AgregarNodoALista(Nodo* nodo, Nodo** lista)
{
       nodo->Siguiente = *lista;
       *lista = nodo;  
}
