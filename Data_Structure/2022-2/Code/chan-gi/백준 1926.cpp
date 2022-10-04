#include <bits/stdc++.h>

using namespace std;
#define X first
#define Y second 
int board[502][502];
bool vis[502][502];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; 

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {   // 도화지 입력
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    int an = 0; // 그림의 갯수
    int mx = 0; // 가장 넓은 그림의 넓이

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {   //도화지에서 그림을 찾기 위해 이중 for문 사용
            if (vis[i][j] == 1 || board[i][j] != 1) continue;   //이미 방문했거나 그림 없으면 넘어가기
            an++;
            queue<pair<int, int> > Q;
            vis[i][j] = 1;
            Q.push({ i,j });
            int area = 0; // 이번 그림의 크기
            while (!Q.empty()) {
                area++; // Q가 비어 있지 않다는 것은 그림이 있다는 것이니 그림 크기값을 증가시키기
                pair<int, int> cur = Q.front(); Q.pop();
                for (int dir = 0; dir < 4; dir++) {
                    int nx = cur.X + dx[dir];
                    int ny = cur.Y + dy[dir];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (vis[nx][ny] || board[nx][ny] != 1) continue;
                    vis[nx][ny] = 1;
                    Q.push({ nx,ny });
                }
            }
            if (mx < area) mx = area;
        }
    }
    cout << an << '\n';
    cout << mx;

    return 0;
}