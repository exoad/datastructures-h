/// \author Jack Meng
/// \brief Classwork Number 6

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define nl cout << endl;
#define gl(STR,VAR) int VAR;     \
                    cout << STR; \
                    cin >> VAR;
#define sl(STR,VAR) cout << STR; \
                    cin >> VAR;
#define F0R(I,R,A) for(int i = I; i < R; i += A)

int main(void)
{
    gl("Enter size of arrays: ", n_1)
    nl
    vector<int> a(n_1);
    F0R(0, n_1, 1)
    {
        sl("Enter array #1, element " + to_string(i) + ": ", a[i])
        nl
    }
    nl
    nl
    vector<int> b(n_1);
    F0R(0, n_1, 1)
    {
        sl("Enter array #2, element " + to_string(i) + ": ", b[i])
        nl
    }
    nl
    cout << "Result: ";
    nl
    for(int i = n_1 - 1; i >= 0; i--) cout << (a[i] + b[i]) << " ";
    
}