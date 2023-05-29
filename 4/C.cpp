// #Problem C - 

//  # Each lecture hall can satisfy the next 3 lecture halls- 
//      #For each 1 I encounter add a +2 to coffee count. 
//         #Runs in O(n) time
#include <string> 
#include <iostream> 

using namespace std;

int count_coffee(int num_lecs, string coffee_machines){
    int count = 0;
    bool flag = 0; //Keeps track if prev lec hall had a coffee machine
    int active = 0;
    for (int i = 0; i < num_lecs; i++){
        if(coffee_machines.at(i) == '1'){
            // Increment by 1
            count++; 
            active = 2;
        }
        else{
            if(active > 0){
                count++;
                active --;
            }
        }
    }
    return count;
}

int main(void){
    int num_lecs;
    string coffee_machines;
    string s;
    cin >> num_lecs; 
    cin >> coffee_machines;

    int count = count_coffee(num_lecs, coffee_machines);

    if(count > num_lecs){
        cout<<(num_lecs)<<endl;
    }
    else{
        cout<<(count)<<endl;
    }
}