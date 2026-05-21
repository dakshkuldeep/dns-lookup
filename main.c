#include <stdio.h>
#include <string.h>

#include "ll_hashtable.c"

int main() {

    hashtable *dns = create_ht(100);

    int choice;

    char domain[100];
    char ip[50];

    while(1) {

        printf("\n===== DNS LOOKUP SYSTEM =====\n");
        printf("1. Add DNS Record\n");
        printf("2. Lookup Domain\n");
        printf("3. Delete Record\n");
        printf("4. Display DNS Table\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter domain name: ");
                scanf("%s", domain);

                printf("Enter IP address: ");
                scanf("%s", ip);

                insert_ht(dns, domain, ip);

                printf("DNS record inserted.\n");
                break;

            case 2:
                printf("Enter domain name: ");
                scanf("%s", domain);

                char *result = search_ht(dns, domain);

                if(strcmp(result, "!") == 0)
                    printf("Domain not found.\n");
                else
                    printf("IP Address: %s\n", result);
                    
                break;

            case 3:
                printf("Enter domain name: ");
                scanf("%s", domain);

                rmfrom_ht(dns, domain);

                printf("Record deleted if it existed.\n");
                break;

            case 4:
                dump_ht(dns);
                break;

            case 5:
                dns = delete_ht(dns);
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}
