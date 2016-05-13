#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    string A{"type:path:foo"};

    for( auto i = A.begin(); i != A.end(); i++ )
        if( *i ==  ':'  )
            *i = ' ';

    stringstream ss(move(A));
    cout << A << endl;
    A = "";
    vector<string> V;
    while( ss >> A )
        V.push_back(A);

    for( auto& i : V )
        cout << i << endl;

    if( V.size() != 3 )
        cout << "Error" << endl;

    cout << V[0] << endl;

    return 1;

}
