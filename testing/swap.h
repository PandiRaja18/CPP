void passByValue(int a,int b)
{
    a = a + b;
    b = a-b;
    a = a-b;
    cout <<"Value swapped : a =" <<a <<" b ="<<b <<endl;
}
void passByReference(int *a,int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
    cout <<"Value swapped : a =" <<*a <<" b ="<<*b <<endl;
}