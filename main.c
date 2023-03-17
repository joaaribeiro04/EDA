#include "meio.h"
#include "stdio.h"
#include "cliente.h"
#include "gestor.h"

#include "utils.h"
#include "menu.h"

int main() {
    /// Listas duplamente ligadas genericas
    Llist *listagestor= lst_init();
    Llist *listaveiculos= lst_init();
    Llist *listacliete = lst_init();

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
                            ReadElectricVehicleFromIo(listaveiculos);
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

