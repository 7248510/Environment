int identify(int valueCheck, const char* identity)
{
    static int key{0};
    key = valueCheck;
    if (valueCheck == 0) {
        printf("\nHost has not been identified");
    }
    if (valueCheck == 1) {
        printf("Host has been identified: %s || Key: %i",identity, key); //Error output in the key
    }
    //printf("\n%p", &key); //Memory address of key
    //printf("\n%d", key); //Testing the key
    return EXIT_SUCCESS; //The issue was the return statement OR 0
}