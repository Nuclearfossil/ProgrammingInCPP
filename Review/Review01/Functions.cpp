unsigned int Fibbonaci(unsigned int i)
{
    if (i <= 1)
        return i;

    return Fibbonaci(i - 1) + Fibbonaci(i - 2);
}