#include <string>
using namespace std;


bool visited[11][11][4]; //x 좌표, y 좌표, 방향

// 위로, 오른쪽, 아래, 왼쪽
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};


// 문자열 dir 을 int형으로 변경 ( 반대방향 끼리 규칙이 있는게 좋을듯)
int todir(char dir){
    int ret;
    if(dir == 'U')
        ret = 0;
    else if (dir == 'R')
        ret = 1;
    else if (dir == 'D')
        ret = 2;
    else 
        ret = 3 ;
    return ret;
}

//좌표 평면을 벗어나는지 아닌지
 bool isNotVaild(int x, int y){
     return x<0 || y<0 || x>10 || y>10; 
 }

int opposite_direction(int dir){
    return (dir + 2) % 4; //반대 방향 끼리의 규칙
}


// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(string dirs) {
    int answer = 0;
    
    int x = 5, y =5;
    
    for (auto c : dirs ){
        int dir = todir(c);
        
        int nx = x + dx[dir]; //다음 x 좌표
        int ny = y + dy[dir]; //다음 y 좌표
        
        if(isNotVaild(nx,ny)){
            continue;
        }
        
        if(visited[x][y][dir] == false){
            visited[x][y][dir] = true;
            visited[nx][ny][opposite_direction(dir)] = true;
            
            answer ++;
        }
        
        x = nx;
        y = ny;
    }
    
    
    
    
    return answer;
}