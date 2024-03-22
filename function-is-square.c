int is_square(int x)
{
    int i = 0;
    while (i * i <= x)
    {
        if (i * i == x)
            return 1;
        i++;
    }
    return 0;
}
