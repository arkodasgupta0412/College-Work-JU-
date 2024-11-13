#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()
#define ABS(x) ((x) >= 0) ? (x) : -(x)

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

int upper_bound_custom(const vector<int> &sorted_array, int key)
{
    return upper_bound(sorted_array.begin(), sorted_array.end(), key) - sorted_array.begin();
}

int lower_bound_custom(const vector<int> &sorted_array, int key)
{
    return lower_bound(sorted_array.begin(), sorted_array.end(), key) - sorted_array.begin();
}

void solve()
{
    int n, d, k;
    cin >> n >> d >> k;

    vector<pair<int, int>> jobs(k);
    vector<int> li(k), ri(k);
    for (int i = 0; i < k; i++)
    {
        cin >> jobs[i].first >> jobs[i].second;
        li[i] = jobs[i].first;
        ri[i] = jobs[i].second;
    }

    sort(li.begin(), li.end());
    sort(ri.begin(), ri.end());

    int max_jobs = -1, min_jobs = k + 1;
    int start_brother = 1, start_mother = 1;

    for (int L = 1; L <= n - d + 1; L++)
    {
        int R = L + d - 1;

        int count_li = upper_bound_custom(li, R);

        int count_ri = lower_bound_custom(ri, L);

        int count = count_li - count_ri;

        if (count > max_jobs)
        {
            max_jobs = count;
            start_brother = L;
        }

        if (count < min_jobs)
        {
            min_jobs = count;
            start_mother = L;
        }
    }

    cout << start_brother << " " << start_mother << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}
