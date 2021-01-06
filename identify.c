/*
char identify(int valueCheck, const char* identity)
{
    int key{0};
    key = valueCheck;
    char output[100];
    if (valueCheck == 0) {
        char output[100] = "Host has not been identified";
        printf("Host has not been identified");
    }
    if (valueCheck == 1) {
        printf("Host has been identified %s, Key: %i",identity, key);
    }
    return output[100];
}
*/

int identify(int valueCheck, const char* identity)
{
    int key{0};
    key = valueCheck;
    if (valueCheck == 0) {
        printf("Host has not been identified");
    }
    if (valueCheck == 1) {
        printf("Host has been identified %s, Key: %i",identity, key); //Error output in the key
    }
    return key;
}
