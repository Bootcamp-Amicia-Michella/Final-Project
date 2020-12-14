struct Group{
    
    char groupname[100];
    struct Ingredients *inside[150];
    int totalinside;

} *Storage[200];

int howmany = 0; //Brp banyak storage

struct Ingredients{

    char group[100]; //belong di grup mana
    char name[255]; //nama
    int stock; //stok
    int expired; //Expiration

};

struct Recipe{

    int walks; //Brp banyak steps yang ada
    char steps[30][255]; //Langkah2
    struct Ingredients *needs[15]; //Butuh Ingredient ape?

};