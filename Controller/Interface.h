
void Entt(){
    puts("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void Press(){
    puts("Press ENTER to continue");
    getchar();
}

void PrintRec(){
    srand(time(0));
    //Print random menu maks 3
    if (CBpages == 0) return;
    else if (CBpages <= 3){
        for (int i=0; i<3; i++){
            printf("%d. %s\n", i+1, CookBook[i]->name);
        }
    }
    else {
        int pick[4] = {-1, -1, -1};
        int now = 0;

        while (1){
            int p = (rand() % CBpages);
            //Checker
            int no = 0;
            for (int j=0; j<now; j++){
                if (pick[j] == p) no = 1; 
            } 
            if (no == 1) continue;

            pick[now++] = p;
            printf("%d. %s\n", now, CookBook[i]->name);
        }
    }
}

void MenuCookBook(){
    Entt();
    if (CBpages == 0){
        puts("Nothing here :/");
        Press();
        return;
    }
    puts("Showing all recipes available");
    for (int i=0; i<CBpages; i++){
        puts("==========================================");
        printf("Name : %s\n", CookBook[i]->name);
        puts("Ingredients :");
        for (int j=0; CookBook[i]->needs != NULL; j++){
            printf("-> %s --- %d\n", CookBook[i]->needs->name, CookBook[i]->needs->stock);
        }
        puts("==========================================");
        puts("STEPS!!!!!");
        for (int j=0; j < CookBook[i]->walks; j++){
            printf("%d. %s\n", j+1, CookBook[i]->steps[j]);
        }
        puts("==========================================\n");
    }

    puts("Need something to search? [1 for yes, others for no]");
    int pick1;
    scanf ("%d", &pick1); getchar();

    if (pick1 == 1){
        print("Amount of desired ingredients: ");
        int much;
        scanf ("%d\n", &much);
        char filters[much+1][100];
        for (int i=0; i<much; i++){
            printf("Ingredients #%d name : ", i+1);
            scanf ("%[^\n]", filters[i]); getchar();
        }
        FindRecipe(filters, much);
    }

    Press();
}

void MenuKitchen(){
    Entt();
    printf("What do you want to cook [Case insensitive]: ");
    char pick[100];
    scanf ("%[^\n]", pick); getchar();
    int found = 0;
    for (int i=0; i<CBpages; i++){
        if (strcasecmp(pick, CookBook[i]->name) == 0){
            puts("==========================================");
            printf("Name : %s\n", CookBook[i]->name);
            puts("Ingredients :");
            for (int j=0; CookBook[i]->needs != NULL; j++){
                printf("-> %s --- %d\n", CookBook[i]->needs->name, CookBook[i]->needs->stock);
            }
            puts("==========================================");
            puts("STEPS!!!!!");
            for (int j=0; j < CookBook[i]->walks; j++){
                printf("%d. %s\n", j+1, CookBook[i]->steps[j]);
            }
            puts("==========================================\n");
            found = 1;
            break;
        }
    }
    if (found == 0) puts("Cannot found your recipe :/");
    Press();

}
