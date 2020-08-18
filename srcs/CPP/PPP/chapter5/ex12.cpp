#include "std_lib_facilities.h"

int main()
{
    vector<int> in(4);
    vector<int> rn(4);

    rn[0] = randint(10);
    rn[1] = randint(10);
    rn[2] = randint(10);
    rn[3] = randint(10);
    cout << rn[0] << rn[1] << rn[2] << rn[3] << endl;
    while (1)
    {
        cin >> in[0] >> in[1] >> in[2] >> in[3];

        if (!cin)
            error("Please enter a valid number");

        int bulls = 0, cows = 0;

        for (int i = 0; i < in.size(); i++)
        {
            if (i == 0 && in[i] == rn[0])
                bulls++;
            else if (i == 1 && in[i] == rn[1])
                bulls++;
            else if (i == 2 && in[i] == rn[2])
                bulls++;
            else if (i == 3 && in[i] == rn[3])
                bulls++;
            else if (in[i] == rn[0] || in[i] == rn[1] || in[i] == rn[2] || in[i] == rn[3])
                cows++;
        }

        cout << "Bulls: " << bulls << " Cows: " << cows << endl;
    }
}