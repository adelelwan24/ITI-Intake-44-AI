#include <iostream>

using namespace std;

int main()
{
    int arrSize;
    cin >> arrSize;
    int* arr = new int[arrSize];

    for (int i=0; i < arrSize; i++)
        cin >> arr[i];

    for (int i=0; i < arrSize; i++)
        cout << arr[i] << endl;
//    cout << "Hello world!" << endl;
    return 0;
}
