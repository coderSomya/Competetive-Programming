#include <bits/stdc++.h>
using namespace std;
#define loop(i, l, r) for (int i = l; i < r; i++)
#define int long long
#define pb push_back
#define vi vector<int>
#define mkp make_pair<int, int>
#define umpii unordered_map<int, int>
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vi, greater<int>>
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define in_arr(A, n) loop(i, 0, n) cin >> A[i];
#define p_arr(A, n) loop(i, 0, n) cout << A[i]
;
#define pln_arr(A, n) loop(i, 0, n) cout << A[i] << endl
#define take_n \
    int n;     \
    cin >> n;
#define take_arr \
    int arr[n];  \
    loop(i, 0, n) cin >> arr[i];

const int mod = 1e9 + 7;
const int inf = 1e15;

void solve()
{

    take_n
        vi a(n),
        b(n);

    int ar, aw, br, bw;
    int qs;

    ar=aw=br=bw=qs=0;

    int ans = 0;

    string s, t;
    cin >> s >> t;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '?' && t[i] == '?')
        {
            qs++;
        }
        else if (s[i] == '?' || t[i] == '?')
        {
            ans++;
            if (s[i] != '?')
            {
                if (s[i] == 'R')
                {
                    ar++;
                    bw++;
                }
                else
                {
                    aw++;
                    br++;
                }
            }
            else
            {
                if (t[i] == 'R')
                {
                    br++;
                    aw++;
                }
                else
                {
                    bw++;
                    ar++;
                }
            }
        }

        else if (s[i] == t[i])
        {
            cout << "-1" << endl;
            return;
        }
        else
        {
            ar += s[i] == 'R';
            aw += s[i] == 'W';
            br += t[i] == 'R';
            bw += t[i] == 'W';
        }
    }

    if (ar - aw != bw - br)
    {
        cout << -1 << endl;
        return;
    }
    else if(abs(ar-aw)>qs){cout<<-1<<endl; return;}
    else
        ans += 2 * (abs(ar - aw));

    cout << ans << endl;
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}