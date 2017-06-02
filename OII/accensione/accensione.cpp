void Accendi(int N, int acceso[], int pulsante[])
{
    for(int i = N; i > 0; i--)
    {
        for(int j = 2*i; j <= N; j+=i)
            if(pulsante[j])
                acceso[i] ^= 1;
        if(!acceso[i])
            pulsante[i] = 1;
    }

}
