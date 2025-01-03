class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int oldcolor = image[sr][sc];

        if (oldcolor == color) return image;

        queue<pair<int,int>> q;
        q.push({sr,sc});

        while(!q.empty()){
            auto ele = q.front();
            int x = ele.first;
            int y = ele.second;

            q.pop();

            int row[] = {-1,0, 1,0};
            int col[] = {0,1,0,-1};


            if (image[x][y] == oldcolor) {

                image[x][y] = color;

                for(int i = 0; i < 4; i++){
                    int newrow = x + row[i];
                    int newcol = y + col[i];
                    if( newrow >= 0 && newrow < m && newcol >= 0 && newcol < n && image[newrow][newcol] == oldcolor){
                        q.push({newrow,newcol});
                    }
                }
            }
        }

        return image;
    }
};