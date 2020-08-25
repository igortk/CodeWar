// find_short.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;
int find_shortt(const string& str)
{
    istringstream inp(str);
    string s;
    int len = -1;
    while (std::getline(inp, s, ' '))
        if (s.length() < len)
            len = s.length();
    return len;
}

int find_short(string str)
{
    vector <string> vecstr;
    string word;
    stringstream s(str);
    vector <int> _wordLength;

    while (s >> word) vecstr.push_back(word);

    for (int i = 0; i < vecstr.size(); i++)
    {
        _wordLength.push_back(vecstr[i].size());
    }
    int min= _wordLength[0];

    for (int i = 0; i < _wordLength.size(); i++)
    {
        if (min> _wordLength[i])
        {
            min = _wordLength[i];
        }
    }
    return min;
}

string highestScoringWord(const string& str)
{
    vector <string> vecstr;
    string word;
    stringstream s(str);
    vector <int> _wordScore;
    int _scoreWorld=0;
    while (s >> word) vecstr.push_back(word);

    for (int i = 0; i < vecstr.size(); i++)
    {
        word = vecstr[i];
        for (int j = 0; j < word.size(); j++)
        {
            _scoreWorld += static_cast<int>(word[j])-96;
        }
        _wordScore.push_back(_scoreWorld);
        _scoreWorld = 0;
    }

    int k, max = 0;
    for (int i = _wordScore.size()-1; i >= 0; i--)
    {
        if (max < _wordScore[i])
        {
            max = _wordScore[i];
            k = i;
        }
    }

    return vecstr[k];
}

bool valid_bracesSS(string braces)
{
    int count = 0;
    for (int i = 0; i < braces.size(); i++)
    {
        if (braces[i]=='('|| braces[i] == '['|| braces[i] == '{')
        {
            count++;
        }
        else if (braces[i] == ')' || braces[i] == ']' || braces[i] == '}')
        {
            count--;
        }

    }
    if (count < 0)
    {
        return false;
    }
    return true;
    // valid or not valid?
}
bool valid_bracesS(string braces)
{
    int count = 0;
    if (braces.size()%2==0)
    {
        for (int i = 0; i < braces.size(); i++)
        {
            if (braces[i]=='(')
            {
                for (int j = i+1; j < braces.size(); j++)
                {
                    if (braces[j]==')')
                    {
                        count++;
                        break;
                    }
                }
            }
            else if (braces[i] == '[')
            {
                for (int j = i + 1; j < braces.size(); j++)
                {
                    if (braces[j] == ']')
                    {
                        count++;
                        break;
                    }
                }
            }
            else if (braces[i] == '{')
            {
                for (int j = i + 1; j < braces.size(); j++)
                {
                    if (braces[j] == '}')
                    {
                        count++;
                        break;
                    }
                }
            }
        }
    }
    if (count == braces.size()/2)
    {
        return true;
    }
    return false;
}
bool valid_braces(string braces)
{
    if (braces.size() % 2 == 0)
    {
        stack<char> _openingBrackets;
        int k = 0;
        for (int i = 0; i < braces.size(); i++)
        {
            if (braces[i] == '(' || braces[i] == '[' || braces[i] == '{')
            {
                _openingBrackets.push(braces[i]);

            }
            else if (braces[i] == ')' || braces[i] == ']' || braces[i] == '}')
            {
                if (!_openingBrackets.empty())
                {
                    if (braces[i] == ')')
                    {
                        k++;
                    }
                    else if (braces[i] == ']' || braces[i] == '}')
                    {
                        k += 2;
                    }
                    if (static_cast<int>(_openingBrackets.top()) == static_cast<int>(braces[i]) - k)
                    {
                        _openingBrackets.pop();
                    }
                    else
                    {
                        return false;
                    }
                    k = 0;
                }
                else
                {
                    return false;
                }
            }
        }
        if (!_openingBrackets.empty())
        {
            return false;
        }
        return true;
    }
    return false;
}
long sumTwoSmallestNumbers2(vector<int> numbers)
{
    int min1, min2, itMin;
    vector<int> numbers2;
    for (int i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] >= 0)
        {
            numbers2.push_back(numbers[i]);
        }
    }
    if (numbers2[0] < numbers2[1])
    {
        min1 = 0;
        min2 = 1;
    }
    else
    {
        min1 = 1;
        min2 = 0;
    }
    for (int i = 2; i < numbers2.size(); i++)
    {
        if (numbers2[min1] >numbers2[i])
        {
            itMin = min1;
            min1 =i;
            if (numbers2[itMin]<numbers2[min2])
            {
                min2 = itMin;
            }
        }
        else if(numbers2[i] >= 0)
        {
            if (numbers2[i]<numbers2[min2])
            {
                min2 = i;
            }
        }
    }
     return (numbers2[min1]+ numbers2[min2]);
}
long sumTwoSmallestNumbers3(vector<int> numbers)
{
    int min1, min2, itMin;
    vector<int> numbers2;
    for (int i = 0; i < numbers.size(); i++)
    {
        numbers2.push_back(numbers[i]);
    }
    if (numbers2[0] < numbers2[1])
    {
        min1 = 0;
        min2 = 1;
    }
    else
    {
        min1 = 1;
        min2 = 0;
    }
    for (int i = 2; i < numbers2.size(); i++)
    {
        if (numbers2[min1] > numbers2[i])
        {
            itMin = min1;
            min1 = i;
            if (numbers2[itMin] < numbers2[min2])
            {
                min2 = itMin;
            }
        }
        else
        {
            if (numbers2[i] < numbers2[min2])
            {
                min2 = i;
            }
        }
    }
    return (numbers2[min1] + numbers2[min2]);
}
long sumTwoSmallestNumbers(vector<int> numbers)
{
    nth_element(begin(numbers), next(begin(numbers)), end(numbers));
    return (unsigned int)(numbers[0] + numbers[1]);
}
class Kata3
{
public:
    vector<string> towerBuilder(int nFloors)
    {
        int basis = nFloors+2;
        string floor = "";
        vector<string> tower, tower2;
        int k=0;
        for (int i = 0; i < nFloors; i++)
        {
            if (i>0)
            {
                k+=2;
            }
            for (int j = 0; j < basis -k; j++)
            {
                    floor += "*";
            }
            tower.push_back(floor);
            floor = "";
        }

        for (int i = nFloors-1; i >= 0; i--)
        {
            tower2.push_back(tower[i]);
        }

        int difference;
        string timeStr="",timeStr2;
        for (int i = 0; i < nFloors; i++)
        {
            difference = tower2[nFloors-1].size() -tower2[i].size();
            for (int i = 0; i < difference/2; i++)
            {
                timeStr += " ";
            }
            timeStr2 = timeStr;
            tower2[i] += timeStr;
            timeStr2 += tower2[i];
            tower2[i] = timeStr2;
            timeStr = "";
        }
        return tower2;
    }
};
class Kata2
{
public:
    vector<string> towerBuilder(int nFloors)
    {
        int basis = nFloors*2-1;
        string floor ="";
        vector<string> tower;

        for (int i = 0; i < nFloors; i++)
        {
            for (int j = 0; j < basis; j++)
            {
                if ((j>=(basis -2*(i+1)+1)/2)&&(j<(basis +2*(i+1)-1)/2))
                {
                    floor += "*";
                }
                else
                {
                    floor += " ";
                }
            }
            tower.push_back(floor);
            floor = "";
        }
        return tower;
    }
};
class Kata
{
public:
    std::vector<std::string> towerBuilder(int nFloors)
    {
        std::vector<std::string> ret;
        for (int i = 0; i < nFloors; i++)
        {
            ret.push_back(string(nFloors - i - 1, ' ') +string((i * 2) + 1, '*') +string(nFloors - i - 1, ' '));
        }
        return ret;
    }
};

int solution2(string roman) 
{
    int sum = 0;
    int old = 0;
    vector<int> _number;
    map<char, int> _romanNumber =
    {
      {'I', 1}, {'V', 5},
      {'X', 10}, {'L', 50},
      {'C', 100}, {'D', 500},
      {'M', 1000}
    };
    for (int i = 0; i < roman.size(); i++)
    {
        _number.push_back(_romanNumber[roman[i]]);
    }

    for (int i = 0; i < _number.size(); i++)
    {
        if (_number[i]< old)
        {
            sum += old;
            old = _number[i];
        }
        else if(_number[i]> old)
        {
            if (old ==0)
            {
                old = _number[i];
            }
            else
            {
                sum += _number[i] - old;
                old = 0;
            }
        }
        else if(_number[i]== old)
        {
            sum += old + _number[i];
            old = 0;
        }
    }

    return sum+old;
}
map<char, int> nums = { {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1} };

int solution(string roman) {
    vector<int> _number;
    map<char, int> _romanNumber =
    {
      {'I', 1}, {'V', 5},
      {'X', 10}, {'L', 50},
      {'C', 100}, {'D', 500},
      {'M', 1000}
    };
    for (int i = 0; i < roman.size(); i++)
    {
        _number.push_back(_romanNumber[roman[i]]);
    }
    int sum = 0;
    for (int i = _number.size(); i > 0; i--)
    {
        if (_number[i]> _number[i-1])
        {
            sum += _number[i] - _number[i - 1];
        }
        else
        {
                sum += _number[i];
        }
    }
   // for ( auto it : _romanNumber)  { }
    return sum;
}

int solution3(string roman) {
    int res = 0;
    int old = 0;

    for (auto a : roman) {
        int curr = nums[a];
        res += curr;

        if (curr > old) {
            res -= 2 * old;
        }

        old = curr;
    }


    return res;
}
int main()
{

    //cout<<find_short("111 22222 3  22")<<endl;
    //string s = "a";
    //cout << static_cast<int>(s[0]) << endl;
   // cout << sumTwoSmallestNumbers3({ 5, 12, -2, 5, 22 });
 //   Kata3 kata;
 //   vector<string> s = kata.towerBuilder(4);
    //int chislo;
    //int i;
    //do {
    //    cin >> chislo;
    //} while (chislo < 1, chislo>3999);
    //char rim[][3] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    //int arab[] = { 1000, 900,  500,  400, 100, 90,    50,   40, 10,    9,    5,   4,   1 };
    //for (i = 0; i < 13; i++) {
    //    while (chislo - arab[i] >= 0) {
    //        cout << rim[i];
    //        chislo -= arab[i];
    //    }
    //}

    map<string, int> _romanNumber = 
    { 
      {"I", 1}, {"V", 5},
      {"X", 10}, {"L", 50},
      {"C", 100}, {"D", 500},
      {"M", 1000}
    };
    cout<<solution2("XXI")<<endl;
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
