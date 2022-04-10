#include <bits/stdc++.h>
using namespace std;


const int SZ = 505;
int N;
int prefer[2*SZ][SZ];

bool wPrefersM1OverM(int w, int m, int m1)
{
    for (int i = 0; i < N; i++)
    {
        if (prefer[w][i] == m1)
            return true;
        if (prefer[w][i] == m)
           return false;
    }
}
 
void stableMarriage()
{
    int wPartner[N];
    bool mFree[N];
    memset(wPartner, -1, wPartner.size());
    memset(mFree, false, mfree.size());
    int freeCount = N;
    while (freeCount > 0)
    {
        int m;
        for (m = 0; m < N; m++)
            if (mFree[m] == false)
                break;
        for (int i = 0; i < N && mFree[m] == false; i++)
        {
            int w = prefer[m][i];
            if (wPartner[w-N] == -1)
            {
                wPartner[w-N] = m;
                mFree[m] = true;
                freeCount--;
            }
 
            else 
            {
                int m1 = wPartner[w-N];
                if (wPrefersM1OverM(w, m, m1) == false)
                {
                    wPartner[w-N] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            } 
        } 
    } 
 
    for (int i = 0; i < N; i++)
       cout << i+1 << " " << wPartner[i]+1 << endl;
}


int main() {

	int t;
	cin >> t;
	while(t--) {
		cin >> N;
	    for(int i = 0 ; i < 2*N ; i ++) {
			int id; cin >> id;
			id --;
			if(i >= N) id += N;
			for(int j = 0 ; j < N ; j ++) {
					cin >> prefer[id][j];
					prefer[id][j] --;
					if(i < N) prefer[id][j] += N;
			}
	    }
        stableMarriage();
	}

	return 0;
}