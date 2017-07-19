enum Executables
{
    ex01 = 0,
    ex02,
    endoflist
};

void main()
{
    Executables toRun = ex02;

    switch (toRun)
    {
    case ex01:
    {
        break;
    }

    case ex02:
    {
        break;
    }

    default:
        break;
    }
}