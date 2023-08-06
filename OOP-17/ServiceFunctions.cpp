#include "ServiceFunctions.h"

int getIntSA()
{
    std::string a;
    std::cin.sync();
    std::cin.clear();
    getline(std::cin, a);
    if (a != "") {
        if ((a.find_first_not_of("- 0123456789") == -1)) {
            for (int i = 1; i < a.size(); i++) {
                if (a[i] == '-') {
                    std::cout << "INPUT ERROR: Mispositioned minus. [INT] expected\n";
                    return getIntSA();
                }
            }
            try {
                return stoi(a);
            }
            catch (std::out_of_range) {
                std::cout << "INPUT ERROR: Data overflow. [INT] expected\n";
                return getIntSA();
            }
        }
        else {
            std::cout << "INPUT ERROR: Symbol mismatch. [INT] expected\n";
            return getIntSA();
        }
    }
    else {
        std::cout << "INPUT ERROR: NULL input. [INT] expected\n";
        return getIntSA();
    }
}

int getIntPos()
{
    std::string a;
    std::cin.sync();
    std::cin.clear();
    getline(std::cin, a);
    if (a != "") {
        if ((a.find_first_not_of("0123456789") == -1)) {
            try {
                return stoi(a);
            }
            catch (std::out_of_range) {
                std::cout << "INPUT ERROR: overflow. Positive [INT] expected\n";
            }
        }
        else {
            std::cout << "INPUT ERROR: Positive [INT] expected\n";
            return getIntPos();
        }
    }
    else
        std::cout << "INPUT ERROR: NULL input. Positive [INT] expected\n";
    return getIntPos();
}

int getIntPos(int bottomLim, int upLim, std::string comment)
{
    std::string a;
    std::cin.sync();
    std::cin.clear();
    getline(std::cin, a);
    if (a != "")
    {

        if ((a.find_first_not_of("0123456789") == -1))
        {
            try {
                int try_to_get_int = stoi(a);
                if (try_to_get_int < bottomLim || try_to_get_int > upLim)
                {
                    std::cout << comment;
                    return getIntPos(bottomLim, upLim, comment);
                }

                return stoi(a);
            }
            catch (std::out_of_range) {
                std::cout << "INPUT ERROR: overflow. Positive [INT] expected.\n";
            }
        }
        else
        {
            std::cout << "INPUT ERROR: Positive [INT] expected.\n";
            return getIntPos(bottomLim, upLim, comment);
        }
    }
    else
        std::cout << "INPUT ERROR: NULL input. Positive [INT] expected.\n";
    return getIntPos(bottomLim, upLim, comment);
}

int getIntPG()
{
    int a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "INPUT ERROR: [INT] expected. Repeat please...\n";
    }
    return a;
}

double getDblSA()
{
    std::string a;
    std::cin.sync();
    getline(std::cin, a);
    if (a == "") { std::cout << "\nINPUT ERROR : NULL input\n"; return getDblSA(); }
    if ((a.find_first_not_of("-.0123456789") == -1))
    {
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i] == '-')
            {
                std::cout << "\nINPUT ERROR: Mispositioned minus. [DBL] expected.\n";
                return getDblSA();
            }

        }
        bool Dot_Flag = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == '.')
            {
                if (Dot_Flag == 1)
                {
                    std::cout << "\nINPUT ERROR: Mispositioned dot. [DBL] expected.\n";
                    return getDblSA();
                }
                Dot_Flag = 1;
            }

        }
        try {
            return stod(a);
        }
        catch (std::out_of_range) {
            std::cout << "INPUT ERROR: overflow. [DBL] expected.\n";
            return getDblSA();
        }
    }
    else {
        std::cout << "Incorrect symbols: [DBL] expected.\nUse dot instead of coma. Example 50.64\n";
        return getDblSA();
    }
}

double getDblPos()
{
    std::string a, dot = ".";
    std::cin.sync();
    std::cin.clear();
    getline(std::cin, a);
    if (a != "")
    {
        if ((a.find_first_not_of(".0123456789") == -1))
        {
            bool One_Dot_already = false;
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] == dot[0] && One_Dot_already == true)
                {
                    std::cout << "INPUT ERROR: Mispositioned dot. Positive [DBL] expected.\n";
                    return getDblPos();
                }
                if (a[i] == dot[0])	One_Dot_already = true;
            }
            try
            {
                return stod(a);
            }
            catch (std::out_of_range)
            {
                std::cout << "INPUT ERROR: Data type overflow. Positive [DBL] expected.\n";
                return getDblPos();
            }
        }
        else
        {
            std::cout << "Incorrect symbols: Positive [DBL] expected.\nUse dot instead of coma. Example 50.64\n";
            return getDblPos();
        }
    }
    else
    {
        std::cout << "INPUT ERROR: NULL input. Positive [DBL] expected.\n";
        return getDblPos();
    }
    return getDblPos();
}

double getDblPG()
{
    double a;
    while (!(std::cin >> a) || (std::cin.peek() != '\n'))
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "INPUT ERROR: [DBL] expected. Repeat please...\n";
    }
    return a;
}

int getRand(int minRange = -999, int maxRange = 999)
{
    if (minRange > maxRange)
    {
        std::cout << "\nERROR: minRange > maxRange. New range: [maxRange..minRange]\n";
        std::swap(minRange, maxRange);
    }
    double Krand = double((rand() % RAND_MAX)) / RAND_MAX;
    int rand = minRange + ((maxRange - minRange) * Krand);
    return rand;
}

double getRand(double minRange = -99999.9, double maxRange = 99999.9)
{
    if (minRange > maxRange)
    {
        std::cout << "\nERROR: minRange > maxRange. New range: [maxRange..minRange]\n";
        std::swap(minRange, maxRange);
    }
    return 	minRange + (maxRange - minRange) * double(rand() % RAND_MAX) / RAND_MAX;
}

 

