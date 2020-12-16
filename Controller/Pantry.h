#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ingredients *newIngredients(char * names, int stocks, char* groups, int baii){
    Ingredients *temp = (Ingredients *) malloc (sizeof (Ingredients));
    strcpy(temp->name, names);
    strcpy(temp->group, groups);
    temp->expired = baii;
    temp->stock =  stocks;

    return temp;
}

struct Group *newGroup(char* name){
    Group *temp = (Group*) malloc (sizeof(Group));
    temp->totalinside = 0;
    strcpy(temp->groupname, name);

    for (int i=0; i<150; i++) temp->inside[i] = NULL;
    return temp;

}

void PantryShowAll(){

    if (howmany == 0) {
        puts("Nothing Here :/");
        return;
    }

    printf("========================================================\n");
    printf ("| %-3s | %-30s | %-4s | %-7s |\n", "No.", "Ingredients", "Stocks", "Expired");
    printf("========================================================\n");

    for (int i=0; i<howmany; i++){
        printf ("|%-47s|", Storage[i]->groupname);
        printf("========================================================\n");
        Group *now = Storage[i];
        for (int j=0; j<now->totalinside; j++){
            printf ("| %-3d | %-30s | %-4d | %-2d days |\n", j+1, now->inside[j]->name, now->inside[j]->stock, now->inside[j]->expired);
        }
        printf("========================================================\n");
    }
}

void PantrySearch(char * inputs){
    for (int i=0; i<howmany; i++){
        Group *now = Storage[i];
        for (int j=0; j<now->totalinside; j++){
            if (strcmp(inputs, now->inside[j]->name)){
                puts("FOUND!!!");
                printf("Name    : %s\n", now->inside[j]->name);
                printf("Stock   : %d\n", now->inside[j]->stock);
                printf("Expired : %d days\n", now->inside[j]->expired);
                return;
            }
        }
    }
    puts("We cannot find your ingredient :/");
}

void PantryAdd(char * inputs, int ins, char * groups, int exp){ //Inputs buat nama ingredients, ins buat brp banyak yang masuk
    //Kalau dah ada, tambah total, kl tidak ada, tambah isi array...
    //Sort menurut Group. Kl grup baru, pushtail, kl grup ada tapi belakang, pushtail juga
    //Kl group didepan, pushhead. Pastikan kapital didepan

    Ingredients *temp = newIngredients((char*)inputs, ins, (char*)groups, exp);

    int idx = howmany;
    for (int i=0; i<howmany; i++){
        if (strcmp(Storage[i]->groupname, groups) == 0){
            idx = i;
            break;
        }
    }

    if (idx == howmany){
        Storage[idx] = newGroup((char*)groups);
        Storage[idx]->inside[0] = temp;
        howmany++;
        Storage[idx]->totalinside += 1;
    }

    else{
        Storage[idx]->inside[Storage[idx]->totalinside] = temp;
        Storage[idx]->totalinside += 1;
    }

}

void PantryRemove(char *gudbaii){
    for (int i=0; i<howmany; i++){
        Group *now = Storage[i];
        for (int j=0; j<now->totalinside; j++){
            if (strcmp(gudbaii, now->inside[j]->name)){
                int ok = j;
                while (now->inside[ok+1] != NULL){
                    now->inside[ok] = now->inside[ok+1];
                    ok++;
                }
                now->inside[ok] = NULL;
                now->totalinside -= 1;
                puts("Success...");
                return;
            }
        }
    }
    puts("Nothing here :/");
}

int IsPut(int code, Ingredients* s1, Ingredients* s2){
    if (code == 2){
        if (strcmp(s1->name, s2->name) < 0) return 1;
        else return 0;
    }
    else {
        if (s1->expired < s2->expired) return 1;
        else return 0;
    }

}

void Glue (int code, Group* arrays, int L, int C, int R){
    int S1 = L;
    int S2 = C+1;
    Ingredients *temp[150];
    int stand = 0;

    while (S1 <= C && S2 <= R){
        /*
            Jika code 2, maka isput = 1 jika nama s1 < nama s2 (lexicographic)
            Jika code 3, maka isput = 1 jika exp s1 < exp s2 (kecil ke besar)
        */
        if (IsPut(code, arrays->inside[S1], arrays->inside[S2]) == 1){ 
            temp[stand++] = arrays->inside[S1++];
        }
        else {
            temp[stand++] = arrays->inside[S2++];
        }
    }

    while (S1 <= C) temp[stand++] = arrays->inside[S1++];

    for (int i=0; i<=stand; i++){
        arrays->inside[L+i] = temp[i]; 
    }

}

void MS(int code, Group* arrays, int L, int R){
    if (L != R){
        int C = (L+R)/2;
        MS(code, arrays, L, C);
        MS(code, arrays, C+1, R);
        Glue(code, arrays, L, C, R);
    }
}

void PantrySort(int code){
    //Code 1=Group, 2=Name, 3=ExpirationDate

    for (int i=0; i<howmany; i++){

        Group *now = Storage[i];
        if (now->totalinside <= 1) continue; 

        else if (code == 2){
            MS(2, now, 0, now->totalinside-1);
        }
        else if (code == 3){
            MS(2, now, 0, now->totalinside-1);
        }
    }

    PantryShowAll();
    

}




