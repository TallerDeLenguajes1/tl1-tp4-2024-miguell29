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
void MostrarMenu();
Nodo* CrearListaVacia();
Nodo* CrearNodo();
void AgregarNodoALista(Nodo* nodo, Nodo ** lista);
Nodo* QuitarNodoDeLista(int ID, Nodo** lista);
void MostrarTareasDeUnaLista(Nodo** lista);

int main()
{
    Nodo* listaTareasPendientes = CrearListaVacia();
    Nodo* listaTareasRealizadas = CrearListaVacia();
    int opcion = 0;
    do
    {
        MostrarMenu();
        scanf("%d",&opcion);
        switch (opcion)
        {
        case 1:
            while (opcion != 2)
            {
                AgregarNodoALista(CrearNodo(),&listaTareasPendientes);
                printf("\nTarea agregada exitosamente.\n\n");
                printf("Desea AGREGAR otra tarea?\n");
                printf("1.si\n");
                printf("2.no\n");
                scanf("%d",&opcion);
                if (opcion != 1 && opcion != 2)
                {
                    printf("\nERROR - Ingrese un valor valido\n");
                }
            }
            break;
        case 2:
            int id;
            MostrarTareasDeUnaLista(&listaTareasPendientes);
            printf("ingrese el id de la tarea que desea terminar");
            scanf("%d",&id);
            Nodo* nodo = QuitarNodoDeLista(id,&listaTareasPendientes);
            if (nodo)
            {
                AgregarNodoALista(nodo,&listaTareasRealizadas);
                printf("Tarea completada satisfactoriamente.\n");
            }else
            {
                printf("No se encontro la tarea con el id: %d\n",id);
            }
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

void MostrarMenu()
{
    printf("Seleccione una opcion:\n\n");
    printf("1. Agregar tarea pendiente\n");
    printf("2. Marcar tarea como realizada\n");
    printf("3. Mostrar tareas pendientes y realizadas\n");
    printf("4. Buscar tarea\n");
    printf("\n0. Salir\n");
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
    //!usando la funcion fgets no permite agregar la descripcion y con scanf funciona pero no permite añadir espacios
    //fgets(descripcion, sizeof(descripcion), stdin);
    scanf("%s",&descripcion);
    fflush(stdin);
    
    nuevoNodo->T.Descripcion = (char*)malloc(sizeof(char) * strlen(descripcion) + 1);
    strcpy(nuevoNodo->T.Descripcion, descripcion);

    printf("Ingrese la duracion de la tarea (10-100): ");
    scanf("%d",&duracion);
    while (duracion < 10 || duracion > 100)
    {
        puts("Por favor ingrese un numero valido entre 10 y 100");
        fflush(stdin);
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

Nodo *QuitarNodoDeLista(int ID, Nodo **lista)
{
    Nodo* aux = *lista;
    Nodo* anterior = NULL;
    
    if (aux != NULL)
    {
        while(aux!=NULL && aux->T.TareaID != ID)
        {
            anterior = aux;
            aux = aux->Siguiente;
        }
        if (aux)
        {
            if (anterior == NULL)
            {
                *lista = aux->Siguiente;
            }else
            {
                anterior->Siguiente = aux->Siguiente;
            }
        }
    return aux;
        
    }else
    {
        return NULL;
    }
    
}

void MostrarTareasDeUnaLista(Nodo **lista)
{
    Nodo* aux = *lista;
    if (aux == NULL)
    {
        printf("\nLista Vacia - sin tareas para mostrar\n");
    }else
    {
        while (aux!= NULL)
        {
            printf("Id de Tarea : %d\n",aux->T.TareaID);
            printf("descripcion : %s\n",aux->T.Descripcion);
            printf("Tiempo estimado: %d\n\n",aux->T.Duracion);
            aux = aux->Siguiente;
        }    
    }
}
