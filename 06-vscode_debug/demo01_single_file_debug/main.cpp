#include <iostream>
using namespace std;

int main() {
    while (true)
    {
        cout << "Hello World" << endl;
        char ch = getchar();

        cout << ch << endl;

        if(ch == 'q')
        {
            break;
        }
    }
    

    return 0;
}