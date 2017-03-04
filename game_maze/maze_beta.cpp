#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
const char MM='A';
using namespace std;
void test_show_maze(vector<vector<char> >&);
void make_maze(vector<vector<char> >& maze);
void play_maze(vector<vector<char> >& maze);
int main(void)
{
    int lines,raws;
    cout << "input lines.\n";
    cin >> lines;
    cout << "input raws.\n";
    cin >> raws;
    vector<vector<char> > maze(lines,vector<char>(raws));
    for(int i=0;i<lines;i++)
    {
        for(int j=0;j<raws;j++)
        {
            maze[i][j]='#';
        }
    }
    if(raws%2==0)
    {
        for(int i=1;i<lines-1;i++)
        {
            for(int j=1;j<raws-1;j+=2)
            maze[i][j]=' ';
        }
        maze[1][0]='S';
        maze[lines-2][raws-1]='E';
        maze[lines-2][raws-2]=' ';
    }
    else if(raws%2==1)
    {
        for(int i=1;i<lines-1;i++)
        {
            for(int j=1;j<raws-1;j+=2)
            maze[i][j]=' ';
        }
        maze[1][0]='S';
        maze[lines-2][raws-1]='E';
        maze[lines-2][raws-2]=' ';
    }
    //the code above initialize the maze
    make_maze(maze);
    play_maze(maze);
    return 0;
}
void make_maze(vector<vector<char> >& maze)
{
    srand(time(NULL));
    for(int i=2;i<maze[1].size()-1;i+=2)
    {
        int temp;
        
        temp=rand()%(maze[1].size()-2)+1;
        maze[temp][i]=' ';
    }
}
void play_maze(vector<vector<char> >& maze)
{
    int temp_l=1;
    int temp_r=1;
    maze[temp_l][temp_r]=MM;
    while(1)
    {
        char n;
        n=cin.get();
        if(n=='a')
        {
            if(temp_r==1 || temp_r==0)
                continue;
            if(maze[temp_l][temp_r-1]=='#')
                continue;
            maze[temp_l][temp_r]=' ';
            temp_r-=1;
            maze[temp_l][temp_r]=MM;
        }
        else if(n=='w')
        {
            if(temp_l==1 || temp_l==0)
                continue;
            if(maze[temp_l-1][temp_r]=='#')
                continue;
            maze[temp_l][temp_r]=' ';
            temp_l-=1;
            maze[temp_l][temp_r]=MM;
        }
        else if(n=='s')
        {
            if(temp_l==maze.size()-1  ||temp_l==maze.size()-2)
                continue;
            if(maze[temp_l+1][temp_r]=='#')
                continue;
            maze[temp_l][temp_r]=' ';
            temp_l+=1;
            maze[temp_l][temp_r]=MM;
        }
        else if(n=='d')
        {
            if(temp_r==maze[1].size()-1 || temp_r==maze[1].size()-2)
                continue;
            if(maze[temp_l][temp_r+1]=='#')
                continue;
            maze[temp_l][temp_r]=' ';
            temp_r+=1;
            maze[temp_l][temp_r]=MM;
        }
        system("cls");
        test_show_maze(maze);
        if(temp_l==maze.size()-2 && temp_r==maze[1].size()-2)
            {
                cout << "you are a motherfucker ginues.";
                break;
            }
    }
    char haha;
    cin >> haha;
}

void test_show_maze(vector<vector<char> >& maze)
{
    for(int i=0;i<maze.size();i++)
    {
        for(int j=0;j<maze[i].size();j++)
            cout << maze[i][j];
        cout << endl;
    }
}
