#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector<int> vec;
	int suitor,suitor_numb;
    int count = 0; 
   
    cout << "Enter suitor number(for example< list 123456, enter 6 >):";
    cin >> suitor_numb;
    
    cout << "Enter elements of suitor list one by one:(like ~1 / ~2....)" << endl;
    for(int g=0; g<suitor_numb; ++g){ 
        cout << "~";
        cin >> suitor;
        vec.push_back(suitor);
    }

    while (vec.size() != 1)
    { 
        for (int t = 0; t < vec.size(); t++)
        {
            count++;
            if (count%3 == 0)
            {
                vec.erase(vec.begin() + t);
                
                if ((t-1) == vec.size()-1)
                    continue;
                
                count++;
            }
        }
    }
    cout << "True love is " << vec[0] << endl;
}
