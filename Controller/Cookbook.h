#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Recipe *newRecipe (char *name, int walks, char steps[30][255], Ingredients *needs[]){
    Recipe *temp = (Recipe*) malloc (sizeof(Recipe));
    strcpy(temp->name, name);
    temp->walks = walks;

    for (int i=0; i<=walks; i++){
        strcpy(temp->steps[i], steps[i]);
    }

    for (int i=0; needs[i] != NULL; i++){ //Nanti stlh input ing, kasih null utk next
        temp->needs[i] = needs[i];
    }

    return temp;
}

void PushRecipe(char *name, int walks, char steps[30][255], Ingredients *needs[]){
    Recipe *temp = newRecipe ((char *)name, walks, steps, needs);

    CookBook[CBpages] = temp;
    CBpages += 1;

}

void FindRecipe(char *wanted[], int input){
    for (int i=0; i<CBpages; i++){
        int ct = 0;
        for (int j=0; CookBook[i]->needs[j] != NULL; j++){
            if (strcmp(wanted[ct] == CookBook[i]->needs[j]) == 0){
                ct++;
            }
        }
        if (ct == input){
            Recipe *p = CookBook[i];
            printf ("Recipe for %s\n", p->name);
            puts("Ingredients ====================");
            for (int k=0; p->needs[k] != NULL; k++){
                printf ("%s -> %d\n", p->needs[k]->name, p->needs[k]->stock);
            }
            puts("Steps       ====================");
            for (int k=0; k < p->walks; k++){
                printf ("%d. %s\n", k+1, p->steps[k]);
            }
            puts("===============================================");
        }
    }
}



