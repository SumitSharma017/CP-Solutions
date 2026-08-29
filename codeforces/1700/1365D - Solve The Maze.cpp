#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define forn(i,e) for(ll i=0;i<e;i++)
#define forsn(i,s,e) for(ll i=s;i<e;i++)
#define rforn(i,s) for(ll i=s;i>=0;i--)
#define vll vector<long long>
#define CIGARETTES ios_base::sync_with_stdio(false);
#define AFTER cin.tie(0);
#define SEX cout.tie(0);

const int INF = 1e9;
const ll INFLL = 1e18;
const int MOD = 1e9 + 7;

int N,M;
int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

bool isin(int i,int j){
    return (i>=0 && j>=0 && i<N && j<M);
}

void dfs(int i,int j,vector<vector<bool>>& vis,vector<vector<char>>& grid){
    if(!isin(i,j)) return;
    if(grid[i][j]=='#') return;
    if(vis[i][j]) return;

    vis[i][j]=true;
    forn(k,4) dfs(i+dx[k],j+dy[k],vis,grid);
}


int main() {

    CIGARETTES AFTER SEX

    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin>>n>>m;
        N=n;
        M=m;
        bool ans=true;
        vector<vector<char>>grid(n,vector<char>(m));
        forn(i,n) forn(j,m) cin>>grid[i][j];
            
        forn(i,n){
            forn(j,m){
                if(grid[i][j]=='B'){
                    forn(k,4){
                        if(isin(i+dx[k],j+dy[k]) && grid[i+dx[k]][j+dy[k]]=='G'){
                            ans=false;
                            break;
                        }
                    }
                }
            }
        }
        if(grid[n-1][m-1]=='B') ans=false;
        if(ans==false){
            cout<<"No"<<endl;
            continue;
        }
        forn(i,n){
            forn(j,m){
                if(grid[i][j]=='B'){
                    forn(k,4){
                        if(isin(i+dx[k],j+dy[k]) && grid[i+dx[k]][j+dy[k]]=='.'){
                            grid[i+dx[k]][j+dy[k]]='#';
                        }
                    }
                }
            }
        }
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        dfs(n-1,m-1,vis,grid);
        forn(i,n){
            forn(j,m){
                if(grid[i][j]=='G' && !vis[i][j]) ans=false;
            }
        }
        cout<<(ans?"Yes":"No")<<endl;

    }

    return 0;
}