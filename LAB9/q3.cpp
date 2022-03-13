#include <iostream>
#include <string>
using namespace std;

void change(char array[], int r1, int r2)
{
    char temp;

    while(r1 < r2){
        temp = array[r1];
        array[r1] = array[r2];
        array[r2] = temp;

        r1++;
        r2--;
    }
}

void reverse(char *arr){
    int range1,range2;
    int limit;
    char temp;


    cout << "Enter the range:" << endl;
    cin >> range1 >> range2;
    range1--;
    range2--;

    change(arr,range1,range2);

}

/* TEST */
int main(){
    
    char *ch;
    string str;
    int limit;
    int test = 0;

    while(test < 3){ //to test with different strings.
        cout << "\nEnter a string:" << endl;
        cin >> str;
        limit = str.size();
        ch = new char[limit+1];
        for(int t = 0; t < str.size(); t++){
            ch[t] = str[t];
        }
        
        reverse(ch);
        cout << "\nAfter reversed:" << endl;
        cout << ch << endl;
        test++;
        cout << endl;
    }
    return 0;
}


