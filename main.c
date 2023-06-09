#include "meio.h"
#include "stdio.h"
#include "cliente.h"
#include "gestor.h"
#include "grafo.h"

#include "utils.h"
#include "menu.h"

Graph* inicia_posicao(){
    Graph* graph = createGraph();

    // Adicionar vértices ao grafo com intervalos de latitude e longitude
    addVertex(graph, 1.0, 100.0, 1.0, 100.0);
    addVertex(graph, 101.0, 200.0, 101.0, 200.0);
    addVertex(graph, 201.0, 300.0, 201.0, 300.0);
    addVertex(graph, 301.0, 400.0, 301.0, 400.0);
    addVertex(graph, 401.0, 500.0, 401.0, 500.0);
    addVertex(graph, 501.0, 600.0, 501.0, 600.0);
    addVertex(graph, 601.0, 700.0, 601.0, 700.0);
    addVertex(graph, 701.0, 800.0, 701.0, 800.0);
    addVertex(graph, 801.0, 900.0, 801.0, 900.0);

    // Adicionar arestas ao grafo
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    addEdge(graph, 4, 5);
    addEdge(graph, 5, 6);
    addEdge(graph, 6, 7);
    addEdge(graph, 7, 8);

    return graph;
}

int pesquisa_vertice (void* graph, Coords c){
    // Encontrar vértice do grafo com base no intervalo de latitude e longitude
    double latitude = c.latitude;
    double longitude = c.longitude;
    Graph* g=(Graph*) graph;
    int vertexIndex = findVertex((Graph *)graph, latitude, longitude);

    if (vertexIndex != -1) {
        printf("Encontra-se no vértice %d do grafo.\n", vertexIndex);
    } else {
        printf("Não foi encontrado em nenhum vértice do grafo.\n");
    }
    return vertexIndex;
    };


int main() {
    /// Listas duplamente ligadas genericas
    Llist *listagestor= lst_init();
    Llist *listaveiculos= lst_init();
    Llist *listacliete = lst_init();
    Graph* graph = inicia_posicao();



    ReadFromTextFile(listaveiculos,"Meios.txt");
    ReadClientFromTextFile(listacliete, "Clientes.txt");
    ReadManagerFromTextFile(listagestor,"Gestor.txt" );

    int choice = -1;
    while (choice != 0) {
        print_main_menu();
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1:
            {
                int ev_choice = -1;
                while (ev_choice != 0) {
                    print_electric_vehicle_menu();
                    if (scanf("%d", &ev_choice)!=1) {
                        CleanStdin();
                        ev_choice = -1;
                    }
                    switch (ev_choice) {

                        case 1:
                            ReadElectricVehicleFromIo(listaveiculos, graph);
                            break;


                        case 2:
                            ShowEletricVehicles(listaveiculos);
                            break;

                        case 3:
                            SetAndReadEletricVehicle(listaveiculos);
                            break;

                        case 4:
                            RmEletricVehicleAndReadId(listaveiculos);
                            break;

                        case 5:
                            WriteToTextFile(listaveiculos, "Meios.txt");
                            break;

                        case 6:
                            write_to_binary_file(listaveiculos, "Meios.bin");
                            break;
                        case 0:
                            break;
                        default:
                            printf("Escolha inválida. Por favor, tente novamente!\n");
                    }
                }
            }
                break;
            case 2:

            {
                int client_choice = -1;
                while (client_choice != 0) {
                    print_client_menu();
                    if (scanf("%d", &client_choice)!=1) {
                        CleanStdin();
                        client_choice = -1;
                    }


                    switch (client_choice) {


                        case 1:
                            ReadClient(listacliete);
                            break;

                        case 2:
                            ShowClient(listacliete);
                            break;

                        case 3:
                            SetAndReadClient(listacliete);
                            break;

                        case 4:
                            RmClienAndReadId(listacliete);
                            break;

                        case 5:
                            WriteClientToTextFile(listacliete, "Clientes.txt");
                            break;

                        case 6:
                            write_to_binary_file_client(listacliete, "Clientes.bin");
                            break;
                        case 7:
                            get_vehicles_within_radius(listacliete, listaveiculos, 5000);
                            break;
                        case 0:
                            break;
                        default:
                            printf("Escolha inválida. Por favor, tente novamente!\n");
                    }
                }
            }
                break;
            case 3:
            {
                int manager_choice = -1;
                while (manager_choice != 0) {
                    print_manager_menu();
                    if (scanf("%d", &manager_choice)!=1) {
                        CleanStdin();
                        manager_choice = -1;
                    }


                    switch (manager_choice) {


                        case 1:
                            ReadManager(listagestor);
                            break;

                        case 2:
                            ShowManager(listagestor);
                            break;

                        case 3:
                            SetAndReadManager(listagestor);
                            break;

                        case 4:
                            RmManagerAndReadId(listagestor);
                            break;

                        case 5:
                            WriteManagerToTextFile(listagestor, "Gestor.txt");
                            break;

                        case 6:
                            write_to_binary_file_manager(listagestor, "Gestor.bin");
                            break;
                        case 0:
                            break;
                        default:
                            printf("Escolha inválida. Por favor, tente novamente!\n");
                    }
                }
            }
                break;
            case 0:
                printf("A sair...\n");
                break;
            default:
                printf("Escolha inválida. Por favor, tente novamente!\n");
        }
    }


    return 0;
}













