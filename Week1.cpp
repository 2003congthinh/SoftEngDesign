#include <iostream>
using namespace std;
int main()
{
    // ex1

    // double a, b, x;
    // cout << "Enter a: ";
    // cin >> a;
    // cout << "Enter b: ";
    // cin >> b;
    // x = -b / a;
    // cout << "X is: " << x;

    // ex2

    // double a, b, c, d, e, A;
    // cout << "Enter the number: ";
    // cin >> a >> b >> c >> d >> e;
    // // cout << a << b << c << d << e;
    // A = (a + b + c + d + e) / 5;
    // cout << "The avg numb is: " << A;

    // ex3

    string str; //char str[MAX_LEN]; //if you are using array of characters
    int i;
    int total = 0;

    cout << "Please enter a string: ";
    /* getline function extracts characters from cin and 
    stores them into str until '\n' is entered (in this example) */
    getline(cin, str); 
    /* if you are using array of characters, then the correct function is
    cin.getline(str, MAX_LEN); */

    cout << "You have entered " << str << '\n';

    for(i=0; str[i] != '\0'; i++) // '\0' indicates the end of string
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - ('a' - 'A'); // minus 32 (i.e. 'a' - 'A') to convert lowercase to uppercase
        else if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + ('a' - 'A'); // add 32 (i.e. 'a' - 'A') to convert uppercase to lowercase
        else if(isdigit(str[i]))
            total+=(str[i]-'0'); // digit - '0' to obtain the actual integer, instead of ASCII code of digit str[i]
    
    cout << "Converted string: " << str << '\n';
    cout << "Sum of all digits in the string: " << total << '\n';

    return 0;
}