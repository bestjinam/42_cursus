class tempratureClass
{
private:
    static int offset = 50;
    static int _i;
    tempratureClass(){};

public:
    static void SetCon(int i)
    {
        _i = i;
    }
};

int main()
{
    int i = 10;
    tempratureClass::SetCon(i);
}
