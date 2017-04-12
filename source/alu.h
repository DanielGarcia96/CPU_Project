typedef struct addsubImpl
{
    char op; 
    char t;
    int a;
    int b;
} addSub;

int addsub(addSub packet, char verbose);
int twos_complement(int a, char verbose);
