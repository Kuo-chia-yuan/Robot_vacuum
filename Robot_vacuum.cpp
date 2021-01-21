#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
using namespace std;

queue<int> x;
queue<int> y;
int temp_x, temp_y, flag1;

struct node{
    int x, y;
    int dis;
    int path_x;
    int path_y;
    int visit;
};

node map1[1005][1005], cur;

void dfs1(int dis_max_x, int dis_max_y)
{
    if(map1[dis_max_x][dis_max_y].path_x == dis_max_x+1 && map1[dis_max_x][dis_max_y].path_y == dis_max_y){
        dfs1(dis_max_x+1, dis_max_y);
    }
    else if(map1[dis_max_x][dis_max_y].path_x == dis_max_x-1 && map1[dis_max_x][dis_max_y].path_y == dis_max_y){
        dfs1(dis_max_x-1, dis_max_y);
    }
    else if(map1[dis_max_x][dis_max_y].path_x == dis_max_x && map1[dis_max_x][dis_max_y].path_y == dis_max_y+1){
        dfs1(dis_max_x, dis_max_y+1);
    }
    else if(map1[dis_max_x][dis_max_y].path_x == dis_max_x && map1[dis_max_x][dis_max_y].path_y == dis_max_y-1){
        dfs1(dis_max_x, dis_max_y-1);
    }
    x.push(dis_max_x);
    y.push(dis_max_y);
    map1[dis_max_x][dis_max_y].visit = 1;
    return;
}

void dfs2(int dis_max_x, int dis_max_y)
{
    if(map1[dis_max_x][dis_max_y].path_x == dis_max_x+1 && map1[dis_max_x][dis_max_y].path_y == dis_max_y){
        if(flag1 == 1){
            flag1 = 0;
        }
        else{
            x.push(dis_max_x);
            y.push(dis_max_y);
        }
        dfs2(dis_max_x+1, dis_max_y);
    }
    else if(map1[dis_max_x][dis_max_y].path_x == dis_max_x-1 && map1[dis_max_x][dis_max_y].path_y == dis_max_y){
        if(flag1 == 1){
            flag1 = 0;
        }
        else{
            x.push(dis_max_x);
            y.push(dis_max_y);
        }
        dfs2(dis_max_x-1, dis_max_y);
    }
    else if(map1[dis_max_x][dis_max_y].path_x == dis_max_x && map1[dis_max_x][dis_max_y].path_y == dis_max_y+1){
        if(flag1 == 1){
            flag1 = 0;
        }
        else{
            x.push(dis_max_x);
            y.push(dis_max_y);
        }
        dfs2(dis_max_x, dis_max_y+1);
    }
    else if(map1[dis_max_x][dis_max_y].path_x == dis_max_x && map1[dis_max_x][dis_max_y].path_y == dis_max_y-1){
        if(flag1 == 1){
            flag1 = 0;
        }
        else{
            x.push(dis_max_x);
            y.push(dis_max_y);
        }
        dfs2(dis_max_x, dis_max_y-1);
    }
    map1[dis_max_x][dis_max_y].visit = 1;
    return;
}

int main(int argc, char *argv[])
{
    ifstream fin;
    ofstream fout;
    fout.open("108062303_proj2.final");
    fin.open(argv[1]);

    int row, column, life, charge_x, charge_y, dis_max=0, dis_max_x, dis_max_y, output_x[1005], output_y[1005], flag=1;

    char map[1005][1005], non;

    queue<node> q;

    fin >> row >> column >> life;

    for(int a=0;a<row;a++){
        scanf("\n");
        for(int b=0;b<column;b++){
            fin >> map[a][b];
            if(map[a][b] == '0'){
                map1[a][b].x = a;
                map1[a][b].y = b;
                map1[a][b].visit = 0;
            }
            else if(map[a][b] == 'R'){
                map1[a][b].x = a;
                map1[a][b].y = b;
                map1[a][b].dis = 0;
                charge_x = a;
                charge_y = b;
            }
        }
    }

    q.push(map1[charge_x][charge_y]);

    while(!q.empty()){
        cur = q.front();
        if(map[cur.x+1][cur.y]=='0' && cur.x+1<row){
            map1[cur.x+1][cur.y].dis = cur.dis + 1;
            map1[cur.x+1][cur.y].path_x = cur.x;
            map1[cur.x+1][cur.y].path_y = cur.y;
            q.push(map1[cur.x+1][cur.y]);
            map[cur.x+1][cur.y] = '2';
        }
        if(map[cur.x-1][cur.y]=='0' && cur.x-1>=0){
            map1[cur.x-1][cur.y].dis = cur.dis + 1;
            map1[cur.x-1][cur.y].path_x = cur.x;
            map1[cur.x-1][cur.y].path_y = cur.y;
            q.push(map1[cur.x-1][cur.y]);
            map[cur.x-1][cur.y] = '2';
        }
        if(map[cur.x][cur.y+1]=='0' && cur.y+1<column){
            map1[cur.x][cur.y+1].dis = cur.dis + 1;
            map1[cur.x][cur.y+1].path_x = cur.x;
            map1[cur.x][cur.y+1].path_y = cur.y;
            q.push(map1[cur.x][cur.y+1]);
            map[cur.x][cur.y+1] = '2';
        }
        if(map[cur.x][cur.y-1]=='0' && cur.y-1>=0){
            map1[cur.x][cur.y-1].dis = cur.dis + 1;
            map1[cur.x][cur.y-1].path_x = cur.x;
            map1[cur.x][cur.y-1].path_y = cur.y;
            q.push(map1[cur.x][cur.y-1]);
            map[cur.x][cur.y-1] = '2';
        }
        q.pop();
    }

    while(flag == 1){
        for(int a=0;a<row;a++){
            for(int b=0;b<column;b++){
                if(map[a][b] == '2'){
                    if(map1[a][b].visit == 0){
                        flag = 0;
                    }
                }
            }
        }
        if(flag == 0){
            for(int a=0;a<row;a++){
                for(int b=0;b<column;b++){
                    if(map[a][b] == '2' && map1[a][b].visit == 0 && map1[a][b].dis > dis_max){
                        dis_max = map1[a][b].dis;
                        dis_max_x = a;
                        dis_max_y = b;
                    }
                }
            }
            dfs1(dis_max_x, dis_max_y);
            flag1 = 1;
            dfs2(dis_max_x, dis_max_y);
            dis_max = 0;

        }
        if(flag == 1)
            break;
        else if(flag == 0)
            flag = 1;
    }

    fout << x.size() + 1 << '\n';
    while(!x.empty()){
        temp_x = x.front();
        temp_y = y.front();
        fout << temp_x << ' ' << temp_y << endl;
        x.pop();
        y.pop();
    }
    fout << charge_x << ' ' << charge_y << endl;

    return 0;
}
