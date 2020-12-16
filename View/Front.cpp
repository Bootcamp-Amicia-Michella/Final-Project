#include "../Controller/Utilities.h"

int main(){
    while (1){
        int pick = 0;
        Entt();
        puts("Welcome to WHISK!!!");
        puts("1. Cookbook");
        puts("2. Kitchen");
        puts("3. Pantry");
        puts("4. Exit");

        PrintRec();
        printf (">> ");

        scanf ("%d", &pick); getchar();

        if (pick == 1) MenuCookBook();
        else if (pick == 2) MenuKitchen();
        else if (pick == 3) MenuPantry();
        else if (pick == 4) break;
    }
    puts("Thanks :)");
}

