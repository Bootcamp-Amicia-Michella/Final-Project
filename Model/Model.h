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

    char name[100];
    int walks; //Brp banyak steps yang ada
    char steps[30][255]; //Langkah2
    struct Ingredients *needs[17]; //Butuh Ingredient ape?

} *CookBook[100];

int CBpages = 0; //brp banyak halaman cookbook