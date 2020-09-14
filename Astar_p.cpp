#include<bits/stdc++.h>
using namespace std;
typedef pair<int,vector<vector<int>>> node;
map <vector<vector<int>>, int> vis;

vector<vector<int>> get_left(vector<vector<int>> &curr, pair<int,int> p){
    vector<vector<int>> temp=curr;
    swap(temp[p.first][p.second],temp[p.first][p.second-1]);
    return temp;
}

vector<vector<int>> get_right(vector<vector<int>> &curr, pair<int,int> p){
    vector<vector<int>> temp=curr;
    swap(temp[p.first][p.second],temp[p.first][p.second+1]);
    return temp;
}

vector<vector<int>> get_up(vector<vector<int>> &curr, pair<int,int> p){
    vector<vector<int>> temp=curr;
    swap(temp[p.first][p.second],temp[p.first-1][p.second]);
    return temp;
}

vector<vector<int>> get_down(vector<vector<int>> &curr, pair<int,int> p){
    vector<vector<int>> temp=curr;
    swap(temp[p.first][p.second],temp[p.first+1][p.second]);
    return temp;
}
int hscore(vector<vector<int>>& curr, vector<vector<int>>& end){
    int score=0;
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            if(curr[i][j]!=0&&curr[i][j]!=end[i][j])
                score++;
        }
    }
    return score;
}
int steps=0;
void astar(vector<vector<int>>& curr, vector<vector<int>>& end,int gscore){
	vis[curr]=1;
    steps++;
	if(vis[end]==1){
        for(int i=0;i<3;++i){
            for(int j=0;j<3;++j){
                cout<<curr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<steps<<endl;
        return;
    }
    pair<int,int> p;
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            cout<<curr[i][j]<<" ";
            if(curr[i][j]==0)
                p={i,j};
        }
        cout<<endl;
    }
    cout<<endl;
    priority_queue<node,vector<node>,greater<node>> pq;    
    if(p.first>0){
        vector<vector<int>> temp=get_up(curr,p);
        if(!vis[temp])
            pq.push({hscore(temp,end)+gscore,temp});    
    }
    if(p.second>0){
        vector<vector<int>> temp=get_left(curr,p);
        if(!vis[temp])    
            pq.push({hscore(temp,end)+gscore,temp});
    }
    if(p.first<2){
        vector<vector<int>> temp=get_down(curr,p);
        if(!vis[temp])
            pq.push({hscore(temp,end)+gscore,temp});
    }
    if(p.second<2){
        vector<vector<int>> temp=get_right(curr,p);
        if(!vis[temp])
            pq.push({hscore(temp,end)+gscore,temp});
    }
    while(pq.size()&&!vis[end]){
        vector<vector<int>> next=pq.top().second;
        pq.pop();
        astar(next,end,gscore+1);    
    }
    
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    vector<vector<int>> start(3);
    vector<vector<int>> end(3);
    cout<<"Enter start matrix:"<<endl;
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            int ele;
            cin>>ele;
            start[i].push_back(ele);
        }
    }
    cout<<"Enter end matrix:"<<endl;
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            int ele;
            cin>>ele;
            end[i].push_back(ele);
        }
    }
    astar(start,end,0);
}
