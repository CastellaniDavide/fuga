/**
 * @file fuga.cpp
 *
 * @version 01.01 2020-11-7
 *
 * @brief https://training.olinfo.it/#/task/fuga/statement
 *
 * @ingroup fuga
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author Castellani Davide
 *
 * Contact: contacts@castellanidavide.it
 *
 */

// Includes
#include <bits/stdc++.h>
using namespace std;

#define DEBUG

// Variabiles
int N, M, temp1, temp2, temp3;
vector < vector <int> > collegamenti;

// Main code
int main()
{
    // Cncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
#ifndef DEBUG
    freopen("output.txt", "w", stdout);
#endif // DEBUG

    // Input
    cin >> N >> M;

    collegamenti.resize(N);

    for (int m = 0; m < M; ++m)
    {
        cin >> temp1 >> temp2 >> temp3;
        if (temp3 == 1)
        {
            collegamenti[temp1 - 1].push_back(temp2 - 1);
            collegamenti[temp2 - 1].push_back(temp1 - 1);
        }
    }

    for (int i = 0; i < N; ++i)
    {
        vector <int> last (N, -1);
        queue <int> next;
        next.push(i);

        while(!next.empty() && last[i] == -1)
        {
#ifdef DEBUG
            cout << " awsfseg" << next.front() <<endl;
#endif // DEBUG
            for(int j = 0; j < collegamenti[next.front()].size(); ++j)
            {

#ifdef DEBUG
                cout << "Try: " << collegamenti[next.front()][j] << endl;
#endif // DEBUG
                if(last[collegamenti[next.front()][j]] < next.front() && collegamenti[next.front()][j] != last[next.front()])
                {
                    next.push(collegamenti[next.front()][j]);
                    last[collegamenti[next.front()][j]] = next.front();
#ifdef DEBUG
                    cout << "inserted: " << next.front() << endl;
#endif // DEBUG
                }
            }
            next.pop();
        }
#ifdef DEBUG
        cout << "Try solution :";
        for (int a = 0; a < last.size(); ++a)
        {
            cout << " " << last[a];
        }
        cout << endl;
#endif // DEBUG

        if (last[i] != -1)
        {
#ifdef DEBUG
            cout << "Solution funded" << endl;
#endif // DEBUG
            vector <int> percorso;
            int actual = last[i];
            do
            {
                percorso.push_back(actual);
                actual = last[actual];
            }
            while(actual != last[i]);

            cout << percorso.size() << endl;
            for (int sol = 0; sol < percorso.size(); ++sol)
            {
                cout << percorso[sol] + 1 << " ";
            }
            cout << endl;
            return 0;
        }
    }

// End
    return 0;
}
