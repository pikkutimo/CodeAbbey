bool isCoprime(unsigned long m, unsigned long n)
{
    for (unsigned long i = 2; i < n/2; ++i)
        if (m%i==0 && n%i==0)
            return false;
    return true;
}

void pythagtriples()
{
    string line;
    int tests;
    unsigned long max = 3000;

    getline(cin, line);
    stringstream(line) >> tests;
    vector<unsigned long> data;
    // input data
    for(int i = 0; i < tests; i++)
    {
        unsigned long sum;
        getline(cin, line);
        stringstream(line) >> sum;
        data.push_back(sum);
    }
    
    for(unsigned long m = 2; m <= max; ++m)
    {
        for(unsigned long n = 1; n < m; ++n)
        {
            // a == m*m-n*n
            // b == 2*m*n
            // c == m*m+n*n
            if(isCoprime(m,n) && ((m-n)%2==1))
            {
                unsigned long a = m*m - n*n;
                unsigned long b = 2*m*n;
                unsigned long c = m*m+n*n;
                for(vector<unsigned long>::iterator i = data.begin(); i != data.end(); i++)
                {
                    if(a + b + c == *i)
                    {
                        cout << c*c << " ";
                    }
                }
            }
        }
    }
}